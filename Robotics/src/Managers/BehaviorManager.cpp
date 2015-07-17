///*
// * BehaviorManager.cpp
// *
// *  Created on: Jul 16, 2015
// *      Author: colman
// */
//
//#include "BehaviorManager.h"
//
//BehaviorManager::BehaviorManager(ILadyRobot* ladyRobot, ParticleManager* particleManager):ladyRobot(ladyRobot), particleManager(particleManager) {
//
//	behaviors[FORWARD] = new GoForward(ladyRobot);
//	behaviors[BACKWARD] = new GoBackward(ladyRobot);
//	behaviors[RIGHT] = new TurnRight(ladyRobot);
//	behaviors[LEFT] = new TurnLeft(ladyRobot);
//	behaviors[DIAGONAL_UP_RIGHT] = new TurnDiagonalUpRight(ladyRobot);
//	behaviors[DIAGONAL_UP_LEFT] = new TurnDiagonalUpLeft(ladyRobot);
//	behaviors[DIAGONAL_DOWN_RIGHT] = new TurnDiagonalUpRight(ladyRobot);
//	behaviors[DIAGONAL_DOWN_LEFT] = new TurnDiagonalDownLeft(ladyRobot);
//
//
//}
//
//void BehaviorManager::run(){
//	Behavior* behavior = behaviors[FORWARD];
//
//	double readings[READINGS_NUM];
//
//	read(readings);
//
//	particleManager->updateAll(new Position(), readings);
//
//	while ((behavior = getNextBehavior(behavior))) {
//		Position* position = ladyRobot->getPosition();
//
//		behavior->behave();
//
//		read(readings);
//
//		slamManager->update(position->delta(robot->getPosition()), readings);
//
//
//}
//
//BehaviorManager::~BehaviorManager() {
//	// TODO Auto-generated destructor stub
//}
//
