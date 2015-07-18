/*
 * BehaviorManager.cpp
 *
 *  Created on: Jul 16, 2015
 *      Author: colman
 */

#include "BehaviorManager.h"

BehaviorManager::BehaviorManager(ILadyRobot* ladyRobot, ParticleManager* particleManager):ladyRobot(ladyRobot), particleManager(particleManager) {}

void BehaviorManager::turnLeft(double yaw, double startRobotYaw){
	ladyRobot->read();
//	while (ladyRobot->getYaw() < startRobotYaw +yaw){
	//todo: think how to combine the kaka
	while (ladyRobot->getYaw() < (yaw - startRobotYaw)*2/1.75){
//		cout<<ladyRobot->getYaw()<<endl;
		ladyRobot->setSpeed(TURN_SPEED, ROTATE_TURN_SPEED);
		ladyRobot->read();

	}
	ladyRobot->setSpeed(0,0);
}

void BehaviorManager::turnRight(double yaw, double startRobotYaw){
	ladyRobot->read();
//	while (ladyRobot->getYaw() > startRobotYaw - yaw){
	while (ladyRobot->getYaw() > yaw - startRobotYaw ){
		ladyRobot->setSpeed(TURN_SPEED, -ROTATE_TURN_SPEED);
		ladyRobot->read();
	}
	ladyRobot->setSpeed(0,0);
}

void BehaviorManager::goForward(Position* probRobotPos, Location* nextLocation){
	double readings[READINGS_NUM];
	ladyRobot->read();
	Position* deltaPosition = probRobotPos->delta(new Position(nextLocation->x, nextLocation->y, 0));
	while( deltaPosition->getX()/10 >0.4 || deltaPosition->getY()/10 > 0.4){
		cout << "x  finish" << deltaPosition->getX() << " y finish" << deltaPosition->getY() << endl;
		ladyRobot->setSpeed(WALKING_SPEED,ROTATE_WALKING_SPEED);
		ladyRobot->read();
		read(readings);
		particleManager->updateAll(deltaPosition, readings);
		probRobotPos = particleManager->GetProbablyPosition();
		//todo: yaw= location calc yaw-> calc beforev changes
		deltaPosition = probRobotPos->delta(new Position(nextLocation->x, nextLocation->y, ladyRobot->getYaw()));
	}

	cout << "x  finish" << deltaPosition->getX() << " y finish" << deltaPosition->getY() << endl;


	ladyRobot->setSpeed(0, 0);
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

