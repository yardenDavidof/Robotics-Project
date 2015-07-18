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
double Particle::probByMov(Position* position){
	double distance = sqrt(pow(position->getX(), 2) + pow(position->getY(), 2));
	double yawProbability = abs(abs(position->getYaw() * (180 / M_PI)) - 180)/180;

	// daniel&guy option
	double distanceProbability = (DISTANCE_THRESHOLD - distance) / DISTANCE_THRESHOLD;;

	return yawProbability * distanceProbability;
//	return distance;
//	return NULL;
}

// predict by laser
double Particle::prodByScan(Position* delta, double laser[], GridMap* grid){
	float distance = sqrt(pow(delta->getX() * ConfigurationManager::getInstance()->getGridResolutionCM(), 2) + pow(delta->getY() * ConfigurationManager::getInstance()->getGridResolutionCM(), 2));
		position->setX(position->getX() + getXDelta(position->getYaw(), distance));
		position->setY(position->getY() + getYDelta(position->getYaw(), distance));

		position->setYaw(position->getYaw() + delta->getYaw());
		int errors = 0;

//		map.updateMap(round(x), round(y), Map::ROBOT_CURRENT_CELL);
			for (int i = 0; i < READINGS_NUM; i++) {
			float laserDistance = laser[i] * ConfigurationManager::getInstance()->getGridResolutionCM();
			double laserInRadians = indexToRadians(i);
			int row = position->getX() + round(getXDelta(position->getYaw() + laserInRadians, laserDistance));
			int col = position->getY() + round(getYDelta(position->getYaw() + laserInRadians, laserDistance));


			if (row < 0 || col < 0 || row > grid->getGridHeight() || col > grid->getGridWidth()) {
				errors++;
				break;
			}

			int currentCellType = grid->gridMap[row][col];
			//int currentCellType = 0;
			bool blocked = laserDistance < LASER_RANGE * ConfigurationManager::getInstance()->getGridResolutionCM();
			int cellType = GridMap::FREE_CELL;
			if (blocked)
				cellType = GridMap::BLOCKED_CELL;
			if (currentCellType != cellType) {
				errors++;
			}

//			if (currentCellType != Map::ROBOT_CURRENT_CELL) {
//				map.updateMap(row, col, cellType);
//				updatePreviousLocationToFree(x, y, row, col);
//			}
		}
		double probability = (double)((double)errors / (double)READINGS_NUM);
		return (double)(1 - probability);
//	return NULL;

}



void Particle::Update(Position* position,double laser[], GridMap* grid){
	float predBel = probByMov(position)*belief;
	belief = NRMALIZATION * prodByScan(position,laser, grid) * predBel;

	//float predMoveVal = calcParticleProbabilty(delta);
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

