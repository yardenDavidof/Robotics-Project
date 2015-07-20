#include "WaypointDriver.h"

/**
 * Constructor of WaypointDriver
 */
WaypointDriver::WaypointDriver(BehaviorManager * manager):behaviorManager(manager) {}

/**
 * The function do the going of the robot to the next waypoint
 */
bool WaypointDriver::letsGo(Location* nextLocation, Location* nextNextLocation,  Position* probRobotPos){
	cout << "robot location " << probRobotPos->getX() << " " << probRobotPos->getY()<<endl;
	//calc angles
	double currentYaw = behaviorManager->getLadyRobot()->getYaw();
	double yaw = AngleHelper::angleToMove(probRobotPos->getLocation(), nextLocation);
	double nextYaw = AngleHelper::angleToMove(nextLocation, nextNextLocation);
	cout << "yaw " << yaw << endl;

	if(yaw-currentYaw < 0)
	{
		behaviorManager->turnRight(yaw, dtor(probRobotPos->getYaw()), nextYaw);
		behaviorManager->goForward(probRobotPos, nextLocation);
	}
	else {
		behaviorManager->turnLeft(yaw, dtor(probRobotPos->getYaw()), nextYaw);
		behaviorManager->goForward(probRobotPos, nextLocation);
	}

	return true;
}


WaypointDriver::~WaypointDriver() {}
