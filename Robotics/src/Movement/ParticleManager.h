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

using namespace std;

class ParticleManager {
private:
	vector<Particle> particles;

public:


	ParticleManager();
	void updateAll(Position* delta, double laserScan[]);
	virtual ~ParticleManager();
};

#endif /* PARTICLEMANAGER_H_ */
