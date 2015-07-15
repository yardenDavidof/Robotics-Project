/*
 * Particle.cpp
 *
 *  Created on: May 30, 2015
 *      Author: colman
 */

#include "Particle.h"

Particle::Particle(double x, double y, double yaw){
	this->position = new Location::Position(x, y, yaw);
	this->belief = 1.0;
}

double Particle::probByMov(double deltaX, double deltaY, double deltaYaw){
	double distance = sqrt(pow(deltaX, 2) + pow(deltaY, 2));
//	double yawProbability = abs(abs(deltaYaw * (180 / M_PI)) - 180)/180;




	//	double distanceProbability = (LocalizationManager::DISTANCE_THRESHOLD - distance) / LocalizationManager::DISTANCE_THRESHOLD;;

//	return yawProbability * distanceProbability;
	return distance;
}

double Particle::prodByScan(double laser[]){

}



void Particle::Update(double deltaX,double deltaY,double deltaYaw,double laser[]){
	float predBel = probByMov(deltaX, deltaY, deltaYaw)*belief;
	belief = NRMALIZATION * prodByScan(laser) * predBel;

//	float predMoveVal = calcParticleProbabilty(delta);
//	float probUpdate = updateMap(delta, laserScan);
//	belief *= (double)predMoveVal * (double)probUpdate * NORMALIZE_FACTOR;
}

double Particle::getBelief(){
	return belief;
}

Particle::~Particle() {
	// TODO Auto-generated destructor stub
}

