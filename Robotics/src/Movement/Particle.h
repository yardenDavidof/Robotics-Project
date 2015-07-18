/*
 * Particle.h
 *
 *  Created on: May 30, 2015
 *      Author: colman
 */

#ifndef PARTICLE_H_
#define PARTICLE_H_
#include "../Utils/Position.h"
#include "../ILadyRobot.h"
#include "../Utils/GridMap.h"

#include <cmath>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>


class Particle {
	static const double NRMALIZATION = 0.5;
	Position* position;
	double belief;


private:
	double probByMov(double deltaX, double deltaY, double deltaYaw);
	double prodByScan(Position* delta, double laser[],GridMap grid);
public:
	Particle(double x, double y, double yaw);
	void Update(double deltaX,double deltaY,double deltaYaw,double laser[], GridMap grid);
	double getBelief();
	Position* getPosition();
	virtual ~Particle();

	static double getXDelta(double degree, double distance) {
		return cos(degree) * distance;
	}

	static double getYDelta(double degree, double distance) {
		return sin(degree) * distance;
	}

	static double indexToRadians(int index) {
			return ((index * 0.36 - 120) * M_PI) / 180;
		}

};

#endif /* PARTICLE_H_ */
