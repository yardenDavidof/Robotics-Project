/*
 * Particle.cpp
 *
 *  Created on: May 30, 2015
 *      Author: colman
 */

#include "Particle.h"
#include "../Managers/ConfigurationManager.h"

Particle::Particle(double x, double y, double yaw){
	this->position = new Position(x, y, yaw);
	this->belief = 1.0;
}

// belief
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

// predict by laser
double Particle::prodByScan(Position* delta, double laser[], GridMap* grid){
	float distance = sqrt(pow(delta->getX() * ConfigurationManager::getInstance()->getGridResolutionCM(), 2) + pow(delta->getY() * ConfigurationManager::getInstance()->getGridResolutionCM(), 2));
//		cout << position->getYaw()<< endl;


		int errors = 0;

//		map.updateMap(round(x), round(y), Map::ROBOT_CURRENT_CELL);
			for (int i = 0; i < READINGS_NUM; i++) {
			float laserDistance = laser[i] * ConfigurationManager::getInstance()->getGridResolutionCM();
			double laserInRadians = indexToRadians(i);
			int row = position->getX() + round(getXDelta(position->getYaw() + laserInRadians, laserDistance));
			int col = position->getY() + round(getYDelta(position->getYaw() + laserInRadians, laserDistance));


			if (row < 0 || col < 0 || row >= grid->getGridHeight() || col >= grid->getGridWidth()) {
				errors++;
				break;
			}

//			cout<<"row " << row <<endl;
//			cout<<"col " << col <<endl;
			int currentCellType = grid->gridMap[row][col];
			//int currentCellType = 0;
			bool blocked = laserDistance < LASER_RANGE * ConfigurationManager::getInstance()->getGridResolutionCM();
			int cellType = GridMap::FREE_CELL;
			if (blocked)
				cellType = GridMap::BLOCKED_CELL;
			if (currentCellType != cellType) {
				errors++;
			}

//			if (currentCellType != Map::ROBOT_CURRENT_CELL) {
//				map.updateMap(row, col, cellType);
//				updatePreviousLocationToFree(x, y, row, col);
//			}
		}
		double probability = (double)((double)errors / (double)READINGS_NUM);
		return (double)(1 - probability);
//	return NULL;

}

void Particle::setPositionDelta(Location* nextLocation, Position* delta){
	int quarter = AngleHelper::getQuarter(position->getLocation(), nextLocation);
	double finalDeltaX = delta->getX(), finalDeltaY = delta->getY();

	switch (quarter)
	{
		case QUARTER_TWO:
		{
			finalDeltaX = -finalDeltaX;
			break;
		}
		case QUARTER_THREE:
		{
			finalDeltaX = -finalDeltaX;
			finalDeltaY = -finalDeltaY;
			break;
		}
		case QUARTER_FOUR:
		{
			finalDeltaY = -finalDeltaY;
			break;
		}
	}
	position->setX(position->getX() + finalDeltaX);
	position->setY(position->getY() + finalDeltaY);
	position->setYaw(position->getYaw() + modDouble(delta->getYaw(), 360));

}


void Particle::Update(Position* delta,double laser[], GridMap* grid, Location* nextLocation){
	float predBel = probByMov(delta)*belief;
	belief = NRMALIZATION * prodByScan(delta,laser, grid) * predBel;



//	position->setX(position->getX() + delta->getX());
//	position->setY(position->getY() + delta->getY());
	//	position->setYaw(position->getYaw() + modDouble(delta->getYaw(), 360));

	setPositionDelta(nextLocation, delta);
	cout << "position->getY() : " << position->getY() << " delta->getY() " << delta->getY() << endl;


}

bool Particle::operator<(const Particle& secondParticle) const{
	return (this->belief > secondParticle.belief);
}

double Particle::getBelief(){
	return belief;
}

Position* Particle::getPosition(){
	return position;
}

double Particle::modDouble(double first, double second){
	return first - ((int)first/second)*second;
}

Particle::~Particle() {
	// TODO Auto-generated destructor stub
}

