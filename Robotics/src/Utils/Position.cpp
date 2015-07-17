/*
 * Position.cpp
 *
 *  Created on: Jul 17, 2015
 *      Author: colman
 */

#include "Position.h"

Position::Position(double x, double y, double yaw):location(new Location(x,y)),yaw(yaw)
{}

int Position::getX()
{
	return location->x;
}
int Position::getY()
{
	return location->y;
}

int Position::getYaw()
{
	return yaw;
}

void Position::setX(double setX)
{
	location->x = setX;
}

void Position::setY(double setY)
{
	location->y = setY;
}

void Position::setYaw(double setYaw)
{
	yaw = setYaw;
}

Position::~Position() {
	// TODO Auto-generated destructor stub
}

