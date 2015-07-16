/*
 * BehaviorManager.h
 *
 *  Created on: Jul 16, 2015
 *      Author: colman
 */

#ifndef BEHAVIORMANAGER_H_
#define BEHAVIORMANAGER_H_

#define BEHAVIORS_SIZE 8
#define FORWARD 0
#define BACKWARD  1
#define RIGHT 2
#define LEFT 3
#define DIAGONAL_UP_RIGHT 4
#define DIAGONAL_UP_LEFT 5
#define DIAGONAL_DOWN_RIGHT 6
#define DIAGONAL_DOWN_LEFT 7


class BehaviorManager {
private:
	ILadyRobot* ladyRobot;
	Behavior* behaviors[BEHAVIORS_SIZE];
public:
	BehaviorManager(ILadyRobot* ladyRobot);
	void run();
	virtual ~BehaviorManager();
};

#endif /* BEHAVIORMANAGER_H_ */
