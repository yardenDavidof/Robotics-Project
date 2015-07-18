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
double Particle::probByMov(double deltaX, double deltaY, double deltaYaw){
	double distance = sqrt(pow(deltaX, 2) + pow(deltaY, 2));
	double yawProbability = abs(abs(deltaYaw * (180 / M_PI)) - 180)/180;




	//	double distanceProbability = (LocalizationManager::DISTANCE_THRESHOLD - distance) / LocalizationManager::DISTANCE_THRESHOLD;;

//	return yawProbability * distanceProbability;
	return distance;
}

// predict by laser
double Particle::prodByScan(Position* delta, double laser[], GridMap grid){
//	float distance = sqrt(pow(delta->getX() * ConfigurationManager::getInstance()->getGridResolutionCM(), 2) + pow(delta->getY() * ConfigurationManager::getInstance()->getGridResolutionCM(), 2));
//		position->setX(position->getX() + getXDelta(position->getYaw(), distance));
//		position->setY(position->getY() + getYDelta(position->getYaw(), distance));
//
//		position->setYaw(position->getYaw() + delta->getYaw());
//		int errors = 0;
//
////		map.updateMap(round(x), round(y), Map::ROBOT_CURRENT_CELL);
//
//		for (int i = 0; i < READINGS_NUM; i++) {
//			float laserDistance = laser[i] * ConfigurationManager::getInstance()->getGridResolutionCM();
//			double laserInRadians = indexToRadians(i);
//			int row = position->getX() + round(getXDelta(position->yaw + laserInRadians, laserDistance));
//			int col = position->getY() + round(getYDelta(position->yaw + laserInRadians, laserDistance));
//
//			if (row < 0 || col < 0 || row > grid.mapHeight || col > grid.mapWidth) {
//				errors++;
//				break;
//			}
//
//			int currentCellType = map.getCellType(row, col);
//			bool blocked = laserDistance < LASER_RANGE * ConfigurationManager::getInstance()->getGridResolutionCM();
//			int cellType = Map::FREE_CELL;
//			if (blocked)
//				cellType = Map::BLOCKED_CELL;
//			if (currentCellType != cellType && currentCellType != Map::UNKOWNN_CELL) {
//				errors++;
//			}
//
//			if (currentCellType != Map::ROBOT_CURRENT_CELL) {
//				map.updateMap(row, col, cellType);
//				updatePreviousLocationToFree(x, y, row, col);
//			}
//		}
//		double probability = (double)((double)errors / (double)READINGS_NUM);
//		return (double)(1 - probability);
	return NULL;

}



void Particle::Update(double deltaX,double deltaY,double deltaYaw,double laser[], GridMap grid){
	float predBel = probByMov(deltaX, deltaY, deltaYaw)*belief;
//	belief = NRMALIZATION * prodByScan(laser) * predBel;

//	float predMoveVal = calcParticleProbabilty(delta);
//	float probUpdate = updateMap(delta, laserScan);
//	belief *= (double)predMoveVal * (double)probUpdate * NORMALIZE_FACTOR;
}

double Particle::getBelief(){
	return belief;
}

Position* Particle::getPosition(){
	return position;
}

Particle::~Particle() {
	// TODO Auto-generated destructor stub
}

