/*
 * Particle.h
 *
 *  Created on: May 30, 2015
 *      Author: colman
 */

#ifndef PARTICLE_H_
#define PARTICLE_H_

class Particle {
	double deltaX;
	double deltaY;
	double deltaYaw;
	double belief;

private:
	double probByMov(double deltaX, double deltaY, double deltaYaw);
	double prodByScan(double laser[]);
public:
	Particle();
	void Update(double deltaX,double deltaY,double deltaYaw,double laser[]);
	virtual ~Particle();
};

#endif /* PARTICLE_H_ */
