/*
 * WaypointDriver.cpp
 *
 *  Created on: Jul 17, 2015
 *      Author: colman
 */

#include "WaypointDriver.h"

WaypointDriver::WaypointDriver(Behavior * behavior):behavior(behavior) {}

bool WaypointDriver::letsGo(Location* nextLocation){

//	//calc angles
//	double yaw = angleCalculate(behavior->getLadyRobot()->getPosition()->);
//
//	//do calculation  or switch to speed according to angles?
//	// function check if obstacle
//	double speed = 20;
//
//	behavior->behave(speed, yaw);
////	behavior->behave()
//	return true;
}

double WaypointDriver::angleCalculate(Position* robotLocation, Position* nextLocation){
	double xDistance = nextLocation->getX() - robotLocation->getX();
	double yDistance = nextLocation->getY() - robotLocation->getY();
	double firstCalculate = xDistance/yDistance;

	double angle = atan(firstCalculate) * 180/M_PI;

	return angle;
}

 double WaypointDriver::degreeToRadian(double degree){
	 return (M_PI * degree)/180;
 }

WaypointDriver::~WaypointDriver() {
	// TODO Auto-generated destructor stub
}

