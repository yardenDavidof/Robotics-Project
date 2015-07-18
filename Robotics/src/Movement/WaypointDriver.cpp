/*
 * WaypointDriver.cpp
 *
 *  Created on: Jul 17, 2015
 *      Author: colman
 */

#include "WaypointDriver.h"

WaypointDriver::WaypointDriver(BehaviorManager * manager):behaviorManager(manager) {}

bool WaypointDriver::letsGo(Location* nextLocation, Position* probRobotPos){

	//calc angles
	double yaw = angleToMove(probRobotPos, nextLocation);

	bool isArriveToPoint = false;
	//do calculation  or switch to speed according to angles?
	// function check if obstacle
	if(yaw == 0){
		behaviorManager->goForward();
		Position* deltaPosition = behaviorManager->getLadyRobot()->getPosition()->delta(new Position(nextLocation->x, nextLocation->y, 0));
		if( deltaPosition->getX() <0.1 && deltaPosition->getY() < 0.1){
			isArriveToPoint = true;
		}
	}
	else if(yaw < 0)
	{
		behaviorManager->turnRight(yaw);
	}
	else {
		behaviorManager->turnLeft(yaw);
	}

	return isArriveToPoint;
}
double WaypointDriver::angleToMove(Position* robotPosition, Location* nextLocation){

	double angleCalcRad = dtor(fmod(angleCalculate(robotPosition->getLocation(),nextLocation),360.0));
	double robotYawRad = robotPosition->getYaw();
	double angleToMove = robotYawRad - angleCalcRad;

	if (angleToMove <= M_PI ){
		return -1*angleToMove;
	}
	else
	{
		return 2*M_PI - angleToMove;
	}
}

double WaypointDriver::angleCalculate(Location* robotLocation, Location* nextLocation){
	double xDistance = nextLocation->x - robotLocation->x;
	double yDistance = nextLocation->y - robotLocation->y;
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

