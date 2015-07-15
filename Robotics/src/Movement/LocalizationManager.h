/*
 * LocalizationManager.h
 *
 *  Created on: Jul 15, 2015
 *      Author: colman
 */

#ifndef LOCALIZATIONMANAGER_H_
#define LOCALIZATIONMANAGER_H_

#include "Particle.h"

using namespace std;

class LocalizationManager {
public:
	static const int PARTICLE_NUM = 50;
//	std::vector<Particle*> particles;
	LocalizationManager();
	virtual ~LocalizationManager();
};


#endif /* LOCALIZATIONMANAGER_H_ */
