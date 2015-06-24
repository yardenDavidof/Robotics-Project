/*
 * Particle.cpp
 *
 *  Created on: May 30, 2015
 *      Author: colman
 */

#include "Particle.h"

Particle::Particle(double x, double y, double yaw) {
	this->position = new Position(x, y, yaw);
}

Particle::~Particle() {
}

