/*
 * ParticleManager.cpp
 *
 *  Created on: May 30, 2015
 *      Author: colman
 */

#include "ParticleManager.h"

ParticleManager::ParticleManager(GridMap* gridMap, double yawRobot) {
	for (int particleIndex = 0; particleIndex < PARTICLE_NUM; particleIndex++) {
			Particle newParticle(
					(rand() % 10 + 1) + gridMap->getMapWidth() / 2,
					(rand() % 10 + 1) + gridMap->getMapHeight()/ 2, yawRobot);
			particles.push_back(newParticle);
		}
}

void ParticleManager::updateAll(Position* delta, double* laserScan){

}

ParticleManager::~ParticleManager() {
	// TODO Auto-generated destructor stub
}

