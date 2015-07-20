#include "BehaviorManager.h"

/**
 * Constructor of BehaviorManager. Initialize ILadyRobot and ParticleManager
 */
BehaviorManager::BehaviorManager(ILadyRobot* ladyRobot, ParticleManager* particleManager):ladyRobot(ladyRobot), particleManager(particleManager) {}

/*
 * The function make the robot turn left, until it arrive to wanted yaw.
 * Normalize the angle according the next waypoint yaw.
 */
void BehaviorManager::turnLeft(double yaw, double startRobotYaw, double nextYaw){
	ladyRobot->read();
	cout << "yaw to go " << yaw << " last yaw " << startRobotYaw << endl;
	double normalizedAngle = normalizeYaw(yaw, nextYaw);
	ladyRobot->setSpeed(TURN_SPEED, ROTATE_TURN_SPEED);
	while (ladyRobot->getYaw() < normalizedAngle){
		ladyRobot->read();
	}

	ladyRobot->setSpeed(0,0);
	ladyRobot->read();
	cout << "the yaw! "<< ladyRobot->getYaw() << endl;
	cout << "finish turn left" << endl;
}

/*
 * The function make the robot turn right, until it arrive to wanted yaw.
 * Normalize the angle according the next waypoint yaw.
 */
void BehaviorManager::turnRight(double yaw, double startRobotYaw, double nextYaw){
	ladyRobot->read();
	double normalizedAngle = normalizeYaw(yaw, nextYaw);
	ladyRobot->setSpeed(TURN_SPEED, -ROTATE_TURN_SPEED);
	while (ladyRobot->getYaw() > normalizedAngle){
		ladyRobot->read();
	}
	ladyRobot->setSpeed(0,0);

	cout << "the yaw! " << ladyRobot->getYaw() << endl;
	cout << "finish turn right" << endl;
}

/**
 * The function calculate the normalize number for yaw according to currentWantedYaw and the next waypoint
 */
double BehaviorManager::normalizeYaw(double currentYaw, double nextYaw){
	if (nextYaw < currentYaw ){
		return UP_NORMALIZE * currentYaw;
	}
	return DOWN_NORMALIZE * currentYaw;
}

/*
 * The function make the robot go forward, until it arrive to wanted place, according the minimum delta.
 */
void BehaviorManager::goForward(Position* probRobotPos, Location* nextLocation){
	double readings[READINGS_NUM];
	ladyRobot->read();
	Position* deltaPosition = ladyRobot->getPosition()->delta(new Position(nextLocation->x, nextLocation->y, 0));
	ladyRobot->setSpeed(WALKING_SPEED,ROTATE_WALKING_SPEED);

	while( deltaPosition->getX() > 10 || deltaPosition->getY() > 10){
		Position* prevPos = particleManager->GetProbablyPosition();
		cout << "x Proxy " << ladyRobot->getPosition()->getX() << " y Proxy " << ladyRobot->getPosition()->getY() << endl;
		cout << "x Particle " << probRobotPos->getX() << " y Particle " << probRobotPos->getY() << endl;
		cout << "x  delta " << deltaPosition->getX() << " y delta " << deltaPosition->getY() << endl << endl;
		read(readings);
		particleManager->updateAll(prevPos->delta(ladyRobot->getPosition()), readings , nextLocation);
		ladyRobot->read();
		probRobotPos = particleManager->GetProbablyPosition();
		deltaPosition = probRobotPos->delta(new Position(nextLocation->x, nextLocation->y, 0));
	}

	cout << "x  finish while" << deltaPosition->getX() << " y finish while" << deltaPosition->getY() << endl;
	ladyRobot->setSpeed(0, 0);
}

/**
 * The function get the laser reading
 */
void BehaviorManager::read(double* readings) {
	ladyRobot->read();
	for (int i = 0; i < READINGS_NUM; i++){
		readings[i] = ladyRobot->getRange(i);
	}
}

/**
 * The function return ILadyRobot
 */
ILadyRobot* BehaviorManager::getLadyRobot(){
	return ladyRobot;
}

BehaviorManager::~BehaviorManager() {}
