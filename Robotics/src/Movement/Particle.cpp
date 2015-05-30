/*
 * Particle.cpp
 *
 *  Created on: May 30, 2015
 *      Author: colman
 */

#include "Particle.h"

Particle::Particle(double x, double y, double yaw) {
	this->position = new Position(x, y, yaw);
	this->belief = MAX_BELIEF;
}

double Particle::probByMov(double deltaX, double deltaY, double deltaYaw){


}
double Particle::prodByScan(double laser[])
{

}

void Particle::Update(double deltaX,double deltaY,double deltaYaw,double laser[]){
	this->position->x = deltaX;
	this->position->y = deltaY;
	this->position->yaw = deltaYaw;
	double predictBelief = probByMov(deltaX,deltaY,deltaYaw) * belief;
	this->belief = prodByScan(laser) * predictBelief * NRMALIZATION;
}


Particle::~Particle() {
	// TODO Auto-generated destructor stub
}

