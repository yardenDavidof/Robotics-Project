/*
 * Position.h
 *
 *  Created on: Jul 17, 2015
 *      Author: colman
 */

#ifndef POSITION_H_
#define POSITION_H_

#include "Location.h"

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
	void setX(double setX);
	void setY(double setY);
	void setYaw(double setY);
};

#endif /* POSITION_H_ */
