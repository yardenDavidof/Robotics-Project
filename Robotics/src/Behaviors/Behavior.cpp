/*
 * Behavior.cpp
 *
 *  Created on: Jul 16, 2015
 *      Author: colman
 */

#include "Behavior.h"

Behavior::Behavior(ILadyRobot* ladyRobot):ladyRobot(ladyRobot){}

void Behavior::behave(double speed, double yaw){
	ladyRobot->setSpeed(speed, yaw);
//	turnAngle = 0.0;
}

//get laser reading
void Behavior::read(double* readings) {
	ladyRobot->read();
	for (int i = 0; i < READINGS_NUM; i++){
		readings[i] = ladyRobot->getRange(i);
	}
}

ILadyRobot* Behavior::getLadyRobot(){
	return ladyRobot;
}

Behavior::~Behavior() {
}

