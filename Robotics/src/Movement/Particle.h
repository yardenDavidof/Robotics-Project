/*
 * Particle.h
 *
 *  Created on: May 30, 2015
 *      Author: colman
 */

#ifndef PARTICLE_H_
#define PARTICLE_H_
//#include "../Utils/Position.h"
#include "../ILadyRobot.h"
#include "../Utils/GridMap.h"
//#include "../Movement/WaypointDriver.h"

#include <cmath>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include "../Utils/Location.h"
#include "../Utils/AngleHelper.h"

using namespace std;

class Particle {
	static const double NRMALIZATION = 1.5;
	Position* position;
	double belief;

private:
	double probByMov(Position* position);
	double prodByScan(Position* delta, double laser[],GridMap* grid);
	static const float MAX_DISTANCE = 100;
	static const float MAX_YAW = 8;
public:
	Particle();
	Particle(double x, double y, double yaw);
	void setPositionDelta(Location* nextLocation, Position* delta);
	void Update(Position* position,double laser[], GridMap* grid, Location* nextLocation);
	double getBelief();
	Position* getPosition();
	double modDouble(double first, double second);
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

	virtual bool operator<(const Particle& secondParticle) const;
};

#endif /* PARTICLE_H_ */
