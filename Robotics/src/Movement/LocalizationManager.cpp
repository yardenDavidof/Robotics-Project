///*
// * LocalizationManager.cpp
// *
// *  Created on: Jul 15, 2015
// *      Author: colman
// */
//
//#include "LocalizationManager.h"
//
//LocalizationManager::LocalizationManager(GridMap gridMap, double yawRobot) {
//	for (int particleIndex = 0; particleIndex < PARTICLE_NUM; particleIndex++) {
//		Particle newParticle(
//				(rand() % 10 + 1) + gridMap.getMapWidth() / 2,
//				(rand() % 10 + 1) + gridMap.getMapHeight()/ 2, yawRobot);
//		particles.push_back(newParticle);
//	}
//}
//
////LocalizationManager* LocalizationManager::getInstance(){
////	static LocalizationManager instance;
////	return &instance;
////}
//
//LocalizationManager::~LocalizationManager() {
//	// TODO Auto-generated destructor stub
//}
//
