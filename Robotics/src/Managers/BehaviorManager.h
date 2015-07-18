/*
 * BehaviorManager.h
 *
 *  Created on: Jul 16, 2015
 *      Author: colman
 */

#ifndef BEHAVIORMANAGER_H_
#define BEHAVIORMANAGER_H_

#define ROTATE_TURN_SPEED 0.6
#define ROTATE_WALKING_SPEED 0
#define TURN_SPEED 0
#define WALKING_SPEED 0.4

#include "../ILadyRobot.h"

using namespace std;
using namespace PlayerCc;

class BehaviorManager {
private:
ILadyRobot* ladyRobot;
public:
	BehaviorManager(ILadyRobot* ladyRobot);
	void turnRight(double yaw, double startRobotYaw);
	void turnLeft(double yaw, double startRobotYaw);
	void goForward();
	void read(double* readings);
	ILadyRobot* getLadyRobot();
	virtual ~BehaviorManager();
};

#endif /* BEHAVIORMANAGER_H_ */
