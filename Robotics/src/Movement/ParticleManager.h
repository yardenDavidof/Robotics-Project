/*
 * ParticleManager.h
 *
 *  Created on: May 30, 2015
 *      Author: colman
 */

#ifndef PARTICLEMANAGER_H_
#define PARTICLEMANAGER_H_

#include "../Utils/Position.h"
#include <vector>
#include "../Movement/Particle.h"
#include "../Utils/GridMap.h"

using namespace std;

// TODO: Maybe singleton
class ParticleManager {
private:
	static const int PARTICLE_NUM = 50;
	static const float BELIEF_THRESHOLD = 0.4;
	std::vector<Particle> particles;
	GridMap grid;
	void FilterParticles(vector<Particle>::iterator particle);

public:
	ParticleManager(GridMap* gridMap, double yawRobot);
	void updateAll(Position* delta, double* laserScan);
	void FillParticlesWithNewMutations();
	virtual ~ParticleManager();
};

#endif /* PARTICLEMANAGER_H_ */
