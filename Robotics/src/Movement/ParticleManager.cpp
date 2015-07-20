#include "ParticleManager.h"

/**
 * Constructor of ParticleManager. Create firsts particles
 */
ParticleManager::ParticleManager(GridMap* gridMap, double yawRobot) {
	grid = gridMap;

	Position* startedPos = ConfigurationManager::getInstance()->getStartLocationInGrid();
	Particle* robotParticle = new Particle(startedPos->getX(), startedPos->getY(), startedPos->getYaw());

	for (int particleIndex = 0; particleIndex < PARTICLE_NUM -1; particleIndex++) {
		Particle* newParticle = new Particle(
				(rand() % 10 + 1) + gridMap->getGridWidth() / 2,
				(rand() % 10 + 1) + gridMap->getGridHeight()/ 2, yawRobot);
		particles.push(newParticle);
	}

	particles.push(robotParticle);
}

/**
 * The function passing the all particles, update them, filtered and fill with childrens
 */
void ParticleManager::updateAll(Position* delta, double* laserScan, Location* nextLocation){
	Particle* tempParticle;
	priority_queue<Particle*> tempList;
	int particlesSize = particles.size();

	for(int i = 0; i<particlesSize; i++)
	{
		tempParticle = particles.top();
		tempParticle->Update(delta, laserScan, grid, nextLocation);
		tempList.push(tempParticle);
		particles.pop();
	}

	particles = tempList;
	tempList = priority_queue<Particle*>();

	// Check if this particle is reliability
	this->FilterParticles();

	FillParticlesWithNewMutations();
}

/**
 * The function filtered the particles to be the top ten
 */
void ParticleManager::FilterParticles(){
	priority_queue<Particle*> tempList;

	for(int i = 0; i < 10; i++)
	{
		tempList.push(particles.top());
		particles.pop();
	}

	particles = tempList;
	tempList = priority_queue<Particle*>();
}

/**
 * The function return the Position from the particles with the highest belief
 */
Position* ParticleManager::GetProbablyPosition(){
	return particles.top()->getPosition();
}

/**
 * The function fill the particles with the "children" of the filtered
 */
void ParticleManager::FillParticlesWithNewMutations(){
	int initialSize = particles.size();
	priority_queue<Particle*> tempList;

	for(int i = 0; i< initialSize; i++ )
	{
		Particle* current = particles.top();
		vector<Location*> neighbours =  grid->getNeighbours(current->getPosition()->getLocation());

		for(int i =0; i<neighbours.size(); i++)
		{
			Position* pos = new Position(neighbours[i]->x, neighbours[i]->y, current->getPosition()->getYaw());
			Particle* newParticle = new Particle(pos->getX(), pos->getY(), pos->getYaw());
			tempList.push(newParticle);
		}

		tempList.push(current);
		particles.pop();

	}

	particles = tempList;
	tempList = priority_queue<Particle*>();
}

bool ParticleManager::isGoodNeighbour(Location* neighbourLoc){
	int neighbourUpXIndex = neighbourLoc->x -1;
	int neighbourDownXIndex = neighbourLoc->x +1;
	int neighbourRightYIndex = neighbourLoc->y +1;
	int neighbourLeftYIndex = neighbourLoc->x -1;

	if(neighbourUpXIndex >= 0){
		if(grid->gridMap[neighbourUpXIndex][(int)neighbourLoc->y] == grid->BLOCKED_CELL)
			return false;
	}
	if(neighbourDownXIndex < grid->getGridHeight()){
		if(grid->gridMap[neighbourDownXIndex][(int)neighbourLoc->y] == grid->BLOCKED_CELL)
			return false;
	}
	if(neighbourLeftYIndex >=0){
		if(grid->gridMap[(int)neighbourLoc->x][neighbourLeftYIndex] == grid->BLOCKED_CELL)
			return false;
	}
	if(neighbourRightYIndex < grid->getGridWidth()){
		if(grid->gridMap[(int)neighbourLoc->x][neighbourRightYIndex] == grid->BLOCKED_CELL)
			return false;
	}

	return true;
}

ParticleManager::~ParticleManager() {}
