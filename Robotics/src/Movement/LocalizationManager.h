/*
 * LocalizationManager.h
 *
 *  Created on: Jul 15, 2015
 *      Author: colman
 */

#ifndef LOCALIZATIONMANAGER_H_
#define LOCALIZATIONMANAGER_H_

#include "Particle.h"
#include "../Utils/GridMap.h"
#include <vector>

using namespace std;

class LocalizationManager {
	GridMap grid;
	LocalizationManager(GridMap gridMap, double yawRobot);
	LocalizationManager(LocalizationManager const&);   // Don't Implement.
		        void operator=(LocalizationManager const&); // Don't implement
public:
    static LocalizationManager* getInstance();
	static const int PARTICLE_NUM = 50;
	std::vector<Particle> particles;

	virtual ~LocalizationManager();
};


#endif /* LOCALIZATIONMANAGER_H_ */
