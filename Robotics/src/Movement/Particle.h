/*
 * Particle.h
 *
 *  Created on: May 30, 2015
 *      Author: colman
 */

#ifndef PARTICLE_H_
#define PARTICLE_H_
#include "../Utils/Position.h"


class Particle {
	const double NRMALIZATION = 0.5;
	Position* position;
	double belief;

private:
	double probByMov(double deltaX, double deltaY, double deltaYaw);
	double prodByScan(double laser[]);
public:
	Particle(double x, double y, double yaw);
	void Update(double deltaX,double deltaY,double deltaYaw,double laser[]);
	virtual ~Particle();
};

#endif /* PARTICLE_H_ */
