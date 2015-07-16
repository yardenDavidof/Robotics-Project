/*
 * Turn.h
 *
 *  Created on: Jul 16, 2015
 *      Author: colman
 */

#ifndef TURN_H_
#define TURN_H_

class Turn : public Behavior{
public:
	Turn(ILadyRobot ladyRobot);
	virtual ~Turn();
};

#endif /* TURN_H_ */
