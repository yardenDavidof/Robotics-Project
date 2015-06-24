/*
 * Position.h
 *
 *  Created on: May 30, 2015
 *      Author: colman
 */

#ifndef POSITION_H_
#define POSITION_H_

#include <iostream>

using namespace std;

class Position {
public:
	double x;
	double y;
	double yaw;
	Position(double x, double y, double yaw);
	Position(double x, double y);
	Position();
	void print() const;
	virtual ~Position();

	bool operator<(const Position& secondPos) const
    {
		if (x < secondPos.x && y < secondPos.y)
			return true;
		return false;
	}


	bool operator==(const Position& secondPos) const
    {
		if (x == secondPos.x && y == secondPos.y)
			return true;
		return false;
	}

	bool operator!=(const Position& secondPos) const
    {
		if (x != secondPos.x || y != secondPos.y)
			return true;
		return false;
	}
};

#endif /* POSITION_H_ */
