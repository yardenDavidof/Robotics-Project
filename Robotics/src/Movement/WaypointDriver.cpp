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
		behaviorManager->turnRight(yaw, dtor(probRobotPos->getYaw()));
		behaviorManager->goForward();
				Position* deltaPosition = behaviorManager->getLadyRobot()->getPosition()->delta(new Position(nextLocation->x, nextLocation->y, 0));
				cout << "x " << deltaPosition->getX() << " y " << deltaPosition->getY() << endl;
				if( deltaPosition->getX() <0.3 && deltaPosition->getY() < 0.3){
					isArriveToPoint = true;
					behaviorManager->getLadyRobot()->setSpeed(0,0);
				}
	}
	else {
		behaviorManager->turnLeft(yaw, dtor(probRobotPos->getYaw()));
		behaviorManager->goForward();
				Position* deltaPosition = behaviorManager->getLadyRobot()->getPosition()->delta(new Position(nextLocation->x, nextLocation->y, 0));
				if( deltaPosition->getX() <0.3 && deltaPosition->getY() < 0.3){
					isArriveToPoint = true;
					behaviorManager->getLadyRobot()->setSpeed(0,0);
				}
	}

	return isArriveToPoint;
}
double WaypointDriver::angleToMove(Position* robotPosition, Location* nextLocation){

//	double angleCalcRad = dtor(modDoubles(angleCalculate(robotPosition->getLocation(),nextLocation),360.0));
//	cout<<modDoubles(angleCalculate(robotPosition->getLocation(),nextLocation),360.0)<<endl;
//	double robotYawRad = dtor(robotPosition->getYaw());
//	double angleToMove = robotYawRad - angleCalcRad;
//
//
//
//	if (angleToMove <= M_PI ){
//		return -1*angleToMove;
//	}
//	else
//	{
//		return 2*M_PI - angleToMove;
//	}

	float yDeltaToPoint = abs(nextLocation->y - robotPosition->getY());
		float distanceToPoint = distance(robotPosition->getLocation(), nextLocation);
		float neededYaw = acos(yDeltaToPoint / distanceToPoint);

		double radYaw;
		int quarter = getQuarter(robotPosition->getLocation(), nextLocation);
		if (quarter == QUARTER_ONE){
			radYaw = M_PI_2 - neededYaw;
		}
		else if(quarter == QUARTER_TWO)
		{
			radYaw = M_PI - neededYaw;
		}
		else if (quarter == QUARTER_THREE){
			radYaw = M_PI + M_PI_2 - neededYaw;
		}
		else{
			radYaw = M_PI * 2 - neededYaw;
		}

		return radYaw;
}

int WaypointDriver::getQuarter(Location* initialLoc, Location* nextLoc) {
	if (initialLoc->y > nextLoc->y) {
		if (initialLoc->x > nextLoc->x)
			return QUARTER_TWO;
		else
			return QUARTER_ONE;
	}
	else {
		if (initialLoc->x > nextLoc->x)
			return QUARTER_THREE;
		else
			return QUARTER_FOUR;
	}
}

double WaypointDriver::distance(Location* robotLocation, Location* nextLocation){
	return sqrt(pow(robotLocation->x - nextLocation->x, 2) + pow(robotLocation->y - nextLocation->y, 2));
}

 double WaypointDriver::modDoubles(double first, double second){
	 int mana = round(first/second);
	 return first - second * mana;
 }

WaypointDriver::~WaypointDriver() {
	// TODO Auto-generated destructor stub
}

