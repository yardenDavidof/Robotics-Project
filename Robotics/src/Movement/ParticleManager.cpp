/*
 * ParticleManager.cpp
 *
 *  Created on: May 30, 2015
 *      Author: colman
 */

#include "ParticleManager.h"

ParticleManager::ParticleManager(GridMap* gridMap, double yawRobot) {
	grid = gridMap;

	Position* startedPos = ConfigurationManager::getInstance()->getStartLocationInGrid();
	Particle* robotParticle = new Particle(startedPos->getX(), startedPos->getY(), startedPos->getYaw());

	for (int particleIndex = 0; particleIndex < PARTICLE_NUM -1; particleIndex++) {
			Particle* newParticle = new Particle(
					(rand() % 10 + 1) + gridMap->getGridWidth() / 2,
					(rand() % 10 + 1) + gridMap->getGridHeight()/ 2, yawRobot);
			particles.push(newParticle);
//			particles.push_back(newParticle);
		}
	particles.push(robotParticle);
}

void ParticleManager::updateAll(Position* delta, double* laserScan, Location* nextLocation){
//	for (vector<Particle*>::iterator particle = particles.begin();
//			particle != particles.end(); particle++) {
//		(*particle)->Update(delta, laserScan, grid);
//	}

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

void ParticleManager::FilterParticles(){

	priority_queue<Particle*> tempList;

	for(int i = 0; i < 10; i++)
	{
		tempList.push(particles.top());
		particles.pop();
	}

	particles = tempList;
	tempList = priority_queue<Particle*>();

//	double minBel = 0.8;
////	while (particles.size() > 10){
//		deleteUnreliableParticles(minBel );
////		minBel += 0.1;
////	}



//	vector<Particle*> temp = copyVector(particles);
//	sort(temp.begin(), temp.end());
//	particles = copyVector(temp);
////	sort(particles.begin(), particles.end());
//	int totalToRemove = particles.size() - 10;
////	int i =0;
//	cout<<"remove belief "<<endl;
////	for (int i=0; i<totalToRemove; i++){
////		cout<< particles[i]->getBelief()<<endl;
////		particles.pop_back();
////	}
//	int i=0;
//	for (vector<Particle*>::iterator particle = particles.begin();
//				particle != particles.end() && i< totalToRemove; particle++) {
//		cout<< (*particle)->getBelief()<<endl;
//
//		particles.erase(particle);
//		i++;
//	}
//
////	cout<<" i "<< i <<endl;
////	cout<< " con "<< (i==totalToRemove)<<endl;
//
//
////	if ((*particle)->getBelief() < BELIEF_THRESHOLD && particles.size() > 1) {
////		particles.erase(particle);
////
////	}
}

//void ParticleManager::deleteUnreliableParticles(double minBelife)
//{
//	for (vector<Particle*>::iterator particle = particles.begin();
//					particle != particles.end() && particles.size() >10 ; particle++) {
//		if((*particle)->getBelief() < minBelife){
//			particles.erase(particle);
//		}
//	}
//}

Position* ParticleManager::GetProbablyPosition(){
//	double max = 0;
//	vector<Particle*>::iterator ProbParticle;
////	for (vector<Particle*>::iterator particle = particles.begin();
////				particle != particles.end(); particle++) {
//	for(int i = 0; i < particles.size(); i++)
//		if(max < (*particle)->getBelief()){
//			max = (*particle)->getBelief();
//			ProbParticle = particle;
//		}
//	}

//	return (*ProbParticle)->getPosition();
return particles.top()->getPosition();

}

void ParticleManager::FillParticlesWithNewMutations(){

//	while (particles.size() < (unsigned)PARTICLE_NUM) {
//			int x = particles[rand() % particles.size()].getPosition()->getX();
//			int y = particles[rand() % particles.size()].getPosition()->getY();
//			int yaw = particles[rand() % particles.size()].getPosition()->getYaw();
//			Particle partical(x, y, yaw);
//			particles.push_back(partical);
//		}


//	vector<Particle*>::iterator finleParticle = particles.end();

//	for (vector<Particle*>::iterator particle = particles.begin();
//					particle != finleParticle; particle++)
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
//			particles.push_back(Particle(pos->getX(), pos->getY(), pos->getYaw()));
		}

		tempList.push(current);
		particles.pop();

	}

	particles = tempList;
	tempList = priority_queue<Particle*>();


}



ParticleManager::~ParticleManager() {
}

