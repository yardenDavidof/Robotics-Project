/*
 * BehaviorManager.h
 *
 *  Created on: Jul 16, 2015
 *      Author: colman
 */

#ifndef BEHAVIORMANAGER_H_
#define BEHAVIORMANAGER_H_

#define ROTATE_TURN_SPEED 0.4
#define ROTATE_WALKING_SPEED 0
#define TURN_SPEED 0
#define WALKING_SPEED 0.2

#include "../ILadyRobot.h"
#include "../Movement/ParticleManager.h"

using namespace std;
using namespace PlayerCc;

class BehaviorManager {
private:
ILadyRobot* ladyRobot;
ParticleManager* particleManager;
public:
	BehaviorManager(ILadyRobot* ladyRobot, ParticleManager* particleManager);
	void turnRight(double yaw, double startRobotYaw);
	void turnLeft(double yaw, double startRobotYaw);
	void goForward(Position* probRobotPos, Location* nextLocation);
	void read(double* readings);
	ILadyRobot* getLadyRobot();
	virtual ~BehaviorManager();
};

#endif /* BEHAVIORMANAGER_H_ */
