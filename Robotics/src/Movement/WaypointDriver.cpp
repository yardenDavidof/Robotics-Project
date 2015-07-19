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
	double yaw = AngleHelper::angleToMove(probRobotPos->getLocation(), nextLocation);
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


double WaypointDriver::modDoubles(double first, double second){
	 int mana = round(first/second);
	 return first - second * mana;
 }

WaypointDriver::~WaypointDriver() {
	// TODO Auto-generated destructor stub
}

