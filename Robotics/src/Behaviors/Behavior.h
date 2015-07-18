/*
 * Behavior.h
 *
 *  Created on: Jul 16, 2015
 *      Author: colman
 */

#ifndef BEHAVIOR_H_
#define BEHAVIOR_H_
#include "../ILadyRobot.h"
using namespace std;

class Behavior {
private:
	ILadyRobot* ladyRobot;
public:
	Behavior(ILadyRobot* ladyRobot);
	void read(double* readings);
//	virtual boGol startCondition();
//	virtual bool stopCondition();
	ILadyRobot* getLadyRobot();
	void behave(double speed, double yaw);

//	Behavior* addNext(Behavior* behavior);
//	virtual Behavior* getNext();

	virtual ~Behavior();
};

#endif /* BEHAVIOR_H_ */
