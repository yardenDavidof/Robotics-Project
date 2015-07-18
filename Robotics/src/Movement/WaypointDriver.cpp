/*
 * WaypointDriver.cpp
 *
 *  Created on: Jul 17, 2015
 *      Author: colman
 */

#include "WaypointDriver.h"

WaypointDriver::WaypointDriver(BehaviorManager * manager):behaviorManager(manager) {}

bool WaypointDriver::letsGo(Location* nextLocation, Position* probRobotPos){

	cout<< "robotloc " << probRobotPos->getX() << " " << probRobotPos->getY()<<endl;
	//calc angles
	double yaw = angleToMove(probRobotPos->getLocation(), nextLocation);
	cout<<"yaww " << yaw<<endl;
	bool isArriveToPoint = false;

	// TODO put in function && remove yaw =0
	 if(yaw <= 0)
	{
		behaviorManager->turnRight(yaw, dtor(probRobotPos->getYaw()));
		behaviorManager->goForward(probRobotPos, nextLocation);
//				Position* deltaPosition = probRobotPos->delta(new Position(nextLocation->x, nextLocation->y, 0));
//				cout << "x " << deltaPosition->getX() << " y " << deltaPosition->getY() << endl;
//				if( deltaPosition->getX()/10 <=0.4 && deltaPosition->getY()/10 <= 0.4){
//					isArriveToPoint = true;
//					behaviorManager->getLadyRobot()->setSpeed(0,0);
//				}
	}
	else {
		behaviorManager->turnLeft(yaw, dtor(probRobotPos->getYaw()));
		behaviorManager->goForward(probRobotPos, nextLocation);
//				Position* deltaPosition = probRobotPos->delta(new Position(nextLocation->x, nextLocation->y, 0));
//				cout << "x " << deltaPosition->getX() << " y " << deltaPosition->getY() << endl;
//				if( deltaPosition->getX()/10 <=0.4 && deltaPosition->getY()/10 <= 0.4){
//					isArriveToPoint = true;
//					behaviorManager->getLadyRobot()->setSpeed(0,0);
//				}
	}

	return true;
}
double WaypointDriver::angleToMove(Location* robotLocation, Location* nextLocation){
	float yDeltaToPoint = abs(nextLocation->y - robotLocation->y);
		float distanceToPoint = distance(robotLocation, nextLocation);
		float neededYaw = acos(yDeltaToPoint / distanceToPoint);

		double radYaw;
		int quarter = getQuarter(robotLocation, nextLocation);
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

