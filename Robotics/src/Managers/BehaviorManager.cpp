/*
 * BehaviorManager.cpp
 *
 *  Created on: Jul 16, 2015
 *      Author: colman
 */

#include "BehaviorManager.h"

BehaviorManager::BehaviorManager(ILadyRobot* ladyRobot):ladyRobot(ladyRobot) {}

void BehaviorManager::turnLeft(double yaw){
	double initialYaw = ladyRobot->getYaw();
	while (ladyRobot->getYaw() < initialYaw +yaw){
		ladyRobot->setSpeed(TURN_SPEED, ROTATE_TURN_SPEED);
	}

	ladyRobot->setSpeed(0,0);
}

void BehaviorManager::turnRight(double yaw){
	double initialYaw = ladyRobot->getYaw();
	while (ladyRobot->getYaw() > initialYaw - yaw){
		ladyRobot->setSpeed(TURN_SPEED, -ROTATE_TURN_SPEED);
	}
	ladyRobot->setSpeed(0,0);
}

void BehaviorManager::goForward(){
	ladyRobot->setSpeed(WALKING_SPEED,ROTATE_WALKING_SPEED);
}

//get laser reading
void BehaviorManager::read(double* readings) {
	ladyRobot->read();
	for (int i = 0; i < READINGS_NUM; i++){
		readings[i] = ladyRobot->getRange(i);
	}
}

ILadyRobot* BehaviorManager::getLadyRobot(){
	return ladyRobot;
}

BehaviorManager::~BehaviorManager() {
	// TODO Auto-generated destructor stub
}

