/*
 * Position.h
 *
 *  Created on: May 30, 2015
 *      Author: colman
 */

#ifndef POSITION_H_
#define POSITION_H_

class Position {
public:
	double x;
	double y;
	double yaw;
	Position(double x, double y, double yaw);
	virtual ~Position();
};

#endif /* POSITION_H_ */
