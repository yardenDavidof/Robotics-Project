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
	cout<< "yaw to go " << yaw<<"last yaw "<< startRobotYaw<< endl;
		cout << "the yaw!!! "<< (yaw - startRobotYaw)*2/1.75 << endl;
//	while (ladyRobot->getYaw() < startRobotYaw +yaw){
	//todo: think how to combine the kaka
	while (ladyRobot->getYaw() < (yaw - startRobotYaw)*2/1.75){
//		cout<<ladyRobot->getYaw()<<endl;
		ladyRobot->setSpeed(TURN_SPEED, ROTATE_TURN_SPEED);
		ladyRobot->read();

	}
	ladyRobot->setSpeed(0,0);
	cout<<"finish turn left"<<endl;
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
//	Position* deltaPosition = probRobotPos->delta(new Position(nextLocation->x, nextLocation->y, 0));
	Position* deltaPosition = ladyRobot->getPosition()->delta(new Position(nextLocation->x, nextLocation->y, 0));


	while( deltaPosition->getX() >25 || deltaPosition->getY() > 25){
		Position* prevPos = ladyRobot->getPosition();
		cout << "x Particle " << probRobotPos->getX() << " y Particle " << probRobotPos->getY() << endl;// << " yaw robotP " << probRobotPos->getYaw() << endl;
		cout << "x  delta " << deltaPosition->getX() << " y delta " << deltaPosition->getY() << endl;
		ladyRobot->setSpeed(WALKING_SPEED,ROTATE_WALKING_SPEED);
		ladyRobot->read();//57.2957795
		read(readings);
		Position* po = ladyRobot->getPosition();
//		particleManager->updateAll(po->delta(probRobotPos), readings , nextLocation);
		particleManager->updateAll(prevPos->delta(ladyRobot->getPosition()), readings , nextLocation);

//		cout << "x  ladyProxy" << ladyRobot->getPosition()->getX() << " y ladyProxy" << ladyRobot->getPosition()->getY() << " yaw ladyProxy" << ladyRobot->getYaw() <<endl;
		cout << "x  Proxy " << po->getX() << " y proxy " << po->getY() << " yaw in deg" << po->getYaw() <<endl << endl;
		cout << "x  realProxy " << ladyRobot->getPosition2DProxy()->GetXPos() << " y realproxy " << ladyRobot->getPosition2DProxy()->GetYPos() <<endl << endl;

		ladyRobot->read();

//		probRobotPos = particleManager->GetProbablyPosition();
		probRobotPos = ladyRobot->getPosition();

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

