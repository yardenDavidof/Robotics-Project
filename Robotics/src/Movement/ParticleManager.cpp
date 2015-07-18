/*
 * ParticleManager.cpp
 *
 *  Created on: May 30, 2015
 *      Author: colman
 */

#include "ParticleManager.h"

ParticleManager::ParticleManager(GridMap* gridMap, double yawRobot) {
	grid = gridMap;
	for (int particleIndex = 0; particleIndex < PARTICLE_NUM; particleIndex++) {
			Particle newParticle(
					(rand() % 10 + 1) + gridMap->getMapWidth() / 2,
					(rand() % 10 + 1) + gridMap->getMapHeight()/ 2, yawRobot);
			particles.push_back(newParticle);
		}
}

void ParticleManager::updateAll(Position* delta, double* laserScan){
	for (vector<Particle>::iterator particle = particles.begin();
			particle != particles.end(); particle++) {
			particle->Update(delta, laserScan, grid);

			// Check if this particle is reliability
			this->FilterParticles(particle);

				}

			FillParticlesWithNewMutations();


}

void ParticleManager::FilterParticles(vector<Particle>::iterator particle){

	if (particle->getBelief() < BELIEF_THRESHOLD && particles.size() > 1) {
		particles.erase(particle);

	}
}

Position* ParticleManager::GetProbablyPosition(){
	double max = 0;
	vector<Particle>::iterator ProbParticle;

	for (vector<Particle>::iterator particle = particles.begin();
				particle != particles.end(); particle++) {
		if(max < particle->getBelief()){
			max = particle->getBelief();
			ProbParticle = particle;
		}
	}

	return ProbParticle->getPosition();
}

void ParticleManager::FillParticlesWithNewMutations(){

	while (particles.size() < (unsigned)PARTICLE_NUM) {
			int x = particles[rand() % particles.size()].getPosition()->getX();
			int y = particles[rand() % particles.size()].getPosition()->getY();
			int yaw = particles[rand() % particles.size()].getPosition()->getYaw();
			Particle partical(x, y, yaw);
			particles.push_back(partical);
		}

}

ParticleManager::~ParticleManager() {
}

