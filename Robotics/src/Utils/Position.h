/*
 * Position.h
 *
 *  Created on: Jul 17, 2015
 *      Author: colman
 */

#ifndef POSITION_H_
#define POSITION_H_

#include "Location.h"
#include <cmath>

using namespace std;

class Position {
private:
	double yaw;
	Location* location;
public:
	Position();
	virtual ~Position();
	Position(double x, double y, double yaw);
	int getX();
	int getY();
	int getYaw();
	Location* getLocation();
	void setX(double setX);
	void setY(double setY);
	void setYaw(double setY);
	Position* delta(Position* old);
};

#endif /* POSITION_H_ */
