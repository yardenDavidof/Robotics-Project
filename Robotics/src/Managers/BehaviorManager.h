#ifndef BEHAVIORMANAGER_H_
#define BEHAVIORMANAGER_H_

#define ROTATE_TURN_SPEED 0.4
#define ROTATE_WALKING_SPEED 0
#define TURN_SPEED 0
#define WALKING_SPEED 0.2
#define UP_NORMALIZE 1.1
#define DOWN_NORMALIZE 0.9825

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
	void turnRight(double yaw, double startRobotYaw, double nextYaw);
	void turnLeft(double yaw, double startRobotYaw, double nextYaw);
	void goForward(Position* probRobotPos, Location* nextLocation);
	void read(double* readings);
	double normalizeYaw(double currentYaw, double nextYaw);
	ILadyRobot* getLadyRobot();
	virtual ~BehaviorManager();
};

#endif
