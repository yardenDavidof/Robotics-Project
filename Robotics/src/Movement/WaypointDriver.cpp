/*
 * WaypointDriver.cpp
 *
 *  Created on: Jul 17, 2015
 *      Author: colman
 */

#include "WaypointDriver.h"

WaypointDriver::WaypointDriver(Behavior * behavior):behavior(behavior) {}

bool WaypointDriver::letsGo(Location* nextLocation){
	//calc angles
	double yaw = 20;

	//do calculation  or switch to speed according to angles?
	// function check if obstacle
	double speed = 20;

	behavior->behave(speed, yaw);
//	behavior->behave()
	return true;
}

double WaypointDriver::angelCalculate(Location* robotLocation, Location* nextLocation){
	double xDistance = nextLocation->x - robotLocation->x;
	double yDistance = nextLocation->y - robotLocation->y;
	double firstCalculate = xDistance/yDistance;

	double angle = atan(firstCalculate) * 180/M_PI;

	return angle;
}


WaypointDriver::~WaypointDriver() {
	// TODO Auto-generated destructor stub
}

