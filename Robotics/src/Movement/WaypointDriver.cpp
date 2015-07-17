/*
 * WaypointDriver.cpp
 *
 *  Created on: Jul 17, 2015
 *      Author: colman
 */

#include "WaypointDriver.h"

WaypointDriver::WaypointDriver(Behavior * behavior):behavior(behavior) {
	// TODO Auto-generated constructor stub

}

 double WaypointDriver::angelCalculate(Location* robotLocation, Location* nextLocation){
	double xDistance = nextLocation->x - robotLocation->x;
	double yDistance = nextLocation->y - robotLocation->y;
	double firstCalculate = xDistance/yDistance;

	double angle = atan(firstCalculate) * 180/PI;

	return angle;
}

WaypointDriver::~WaypointDriver() {
	// TODO Auto-generated destructor stub
}

