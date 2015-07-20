#include "Particle.h"
#include "../Managers/ConfigurationManager.h"

/**
 * Constructor of Particle. Get the x, y and yaw. set start belief to 1
 */
Particle::Particle(double x, double y, double yaw){
	this->position = new Position(x, y, yaw);
	this->belief = 1.0;
}

/**
 * The function calculate the probability according to delta
 */
double Particle::probByMov(Position* delta){
	double distance = sqrt(pow(delta->getX(), 2) + pow(delta->getY(), 2));
	float yawProbability = abs(delta->getYaw()) ;

	float propability = 0.25;

	if (distance <= MAX_DISTANCE)
		propability += 0.25;
	if (yawProbability <= MAX_YAW)
		propability += 0.25;
	if (yawProbability == 0)
		propability += 0.25;

	return propability;
}

/*
 *  The function calculate the probability according to laser scans
 */
double Particle::prodByScan(Position* delta, double laser[], GridMap* grid){
	float distance = sqrt(pow(delta->getX() * ConfigurationManager::getInstance()->getGridResolutionCM(), 2) + pow(delta->getY() * ConfigurationManager::getInstance()->getGridResolutionCM(), 2));
	int errors = 0;

	for (int i = 0; i < READINGS_NUM; i++) {
		float laserDistance = laser[i] * ConfigurationManager::getInstance()->getGridResolutionCM();
		double laserInRadians = indexToRadians(i);
		int row = position->getX() + round(getXDelta(position->getYaw() + laserInRadians, laserDistance));
		int col = position->getY() + round(getYDelta(position->getYaw() + laserInRadians, laserDistance));

		if (row < 0 || col < 0 || row >= grid->getGridHeight() || col >= grid->getGridWidth()) {
			errors++;
			break;
		}

		int currentCellType = grid->gridMap[row][col];
		bool blocked = laserDistance < LASER_RANGE * ConfigurationManager::getInstance()->getGridResolutionCM();
		int cellType = GridMap::FREE_CELL;
		if (blocked)
			cellType = GridMap::BLOCKED_CELL;
		if (currentCellType != cellType) {
			errors++;
		}
	}

	double probability = (double)((double)errors / (double)READINGS_NUM);
	return (double)(1 - probability);
}

/**
 * The function calculate the the delta according the quarter of next location and set the position of the particle
 */
void Particle::setPositionDelta(Location* nextLocation, Position* delta){
	int quarter = AngleHelper::getQuarter(position->getLocation(), nextLocation);
	double finalDeltaX = delta->getX(), finalDeltaY = delta->getY();

	switch (quarter)
	{
		case QUARTER_TWO:
		{
			finalDeltaX = -finalDeltaX;
			finalDeltaY = -finalDeltaY;
			break;
		}
		case QUARTER_THREE:
		{
			finalDeltaY = -finalDeltaY;
			break;
		}
		case QUARTER_ONE:
		{
			finalDeltaX = -finalDeltaX;
			break;
		}
	}

	position->setX(position->getX() + finalDeltaX);
	position->setY(position->getY() + finalDeltaY);
	position->setYaw(position->getYaw() + modDouble(delta->getYaw(), 360));
}

/**
 * The function update the current particle. set the belief and positionDelta
 */
void Particle::Update(Position* delta, double laser[], GridMap* grid, Location* nextLocation){
	float predBel = probByMov(delta)*belief;
	belief = NRMALIZATION * prodByScan(delta,laser, grid) * predBel;
	setPositionDelta(nextLocation, delta);
}

/**
 * Operator < for compare between particles. Do according to belief
 */
bool Particle::operator<(const Particle& secondParticle) const{
	return (this->belief > secondParticle.belief);
}

/**
 * The function return the particle belief
 */
double Particle::getBelief(){
	return belief;
}

/**
 * The function return the position of particle
 */
Position* Particle::getPosition(){
	return position;
}

/**
 * The function do mod between doubles
 */
double Particle::modDouble(double first, double second){
	return first - ((int)first/second)*second;
}

Particle::~Particle() {}
