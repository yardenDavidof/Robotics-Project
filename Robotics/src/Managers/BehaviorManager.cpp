/*
 * BehaviorManager.cpp
 *
 *  Created on: Jul 16, 2015
 *      Author: colman
 */

#include "BehaviorManager.h"

BehaviorManager::BehaviorManager(ILadyRobot* ladyRobot, ParticleManager* particleManager):ladyRobot(ladyRobot), particleManager(particleManager) {}

void BehaviorManager::turnLeft(double yaw, double startRobotYaw, double nextYaw){
	ladyRobot->read();
	cout<< "yaw to go " << yaw<<" last yaw "<< startRobotYaw<< endl;
//	while (ladyRobot->getYaw() < startRobotYaw +yaw){
	//todo: think how to combine the kaka
//	while (ladyRobot->getYaw() < (yaw - startRobotYaw)){//*2/1.75){
	double normalizedAngle = normalizeYaw(yaw, nextYaw);
	ladyRobot->setSpeed(TURN_SPEED, ROTATE_TURN_SPEED);
	while (ladyRobot->getYaw() < normalizedAngle){
//		cout<<ladyRobot->getYaw`()<<endl;
		ladyRobot->read();
	}

	ladyRobot->setSpeed(0,0);
	ladyRobot->read();
	cout << "the yaw!!! "<< ladyRobot->getYaw() << endl;
	cout<<"finish turn left"<<endl;
}

void BehaviorManager::turnRight(double yaw, double startRobotYaw, double nextYaw){
	ladyRobot->read();
//	while (ladyRobot->getYaw() > startRobotYaw - yaw){
	double normalizedAngle = normalizeYaw(yaw, nextYaw);
	ladyRobot->setSpeed(TURN_SPEED, -ROTATE_TURN_SPEED);
	while (ladyRobot->getYaw() > normalizedAngle){

		ladyRobot->read();
	}
	ladyRobot->setSpeed(0,0);

	cout << "the yaw!!! "<< ladyRobot->getYaw() << endl;
		cout<<"finish turn right"<<endl;
}

double BehaviorManager::normalizeYaw(double currentYaw, double nextYaw){
		if (nextYaw < currentYaw ){
			return UP_NORMALIZE * currentYaw;
		}
		return DOWN_NORMALIZE * currentYaw;
}

double BehaviorManager::normalizeYawRight(double currentYaw, double nextYaw){
		if (nextYaw > currentYaw ){
			return UP_NORMALIZE * currentYaw;
		}
		return DOWN_NORMALIZE * currentYaw;
}

void BehaviorManager::goForward(Position* probRobotPos, Location* nextLocation){
	double readings[READINGS_NUM];
	ladyRobot->read();
//	Position* deltaPosition = probRobotPos->delta(new Position(nextLocation->x, nextLocation->y, 0));
	Position* deltaPosition = ladyRobot->getPosition()->delta(new Position(nextLocation->x, nextLocation->y, 0));

	ladyRobot->setSpeed(WALKING_SPEED,ROTATE_WALKING_SPEED);

	while( deltaPosition->getX() >10 || deltaPosition->getY() > 10){

//		Position* prevPos = ladyRobot->getPosition();
		Position* prevPos = particleManager->GetProbablyPosition();
		cout << "x Proxy " << ladyRobot->getPosition()->getX() << " y Proxy " << ladyRobot->getPosition()->getY() << endl;
		cout << "x Particle " << probRobotPos->getX() << " y Particle " << probRobotPos->getY() << endl;// << " yaw robotP " << probRobotPos->getYaw() << endl;
		cout << "x  delta " << deltaPosition->getX() << " y delta " << deltaPosition->getY() << endl << endl;
//		ladyRobot->read();//57.2957795
		read(readings);
//		Position* po = ladyRobot->getPosition();
//		particleManager->updateAll(po->delta(probRobotPos), readings , nextLocation);
		particleManager->updateAll(prevPos->delta(ladyRobot->getPosition()), readings , nextLocation);

//		cout << "x  ladyProxy" << ladyRobot->getPosition()->getX() << " y ladyProxy" << ladyRobot->getPosition()->getY() << " yaw ladyProxy" << ladyRobot->getYaw() <<endl;
//		cout << "x  Proxy " << po->getX() << " y proxy " << po->getY() << " yaw in deg" << po->getYaw() <<endl << endl;
//		cout << "x  realProxy " << ladyRobot->getPosition2DProxy()->GetXPos() << " y realproxy " << ladyRobot->getPosition2DProxy()->GetYPos() <<endl << endl;

		ladyRobot->read();

		probRobotPos = particleManager->GetProbablyPosition();

		//todo: yaw= location calc yaw-> calc beforev changes
		deltaPosition = probRobotPos->delta(new Position(nextLocation->x, nextLocation->y, 0));
	}

	cout << "x  finish while" << deltaPosition->getX() << " y finish while" << deltaPosition->getY() << endl;


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

