/*
 * Location.h
 *
 *  Created on: Jun 26, 2015
 *      Author: colman
 */

#ifndef LOCATION_H_
#define LOCATION_H_

class Location {
	struct Position{
		double yaw;
		Location* location;
		Position(double x, double y, double yaw) : location(new Location(x,y)), yaw(yaw){}
	};

public:
	double x;
	double y;

	Location(double x, double y);
	virtual ~Location();

	bool operator!=(const Location& secondLoc) const
    {
		if (x != secondLoc.x || y != secondLoc.y)
			return true;
		return false;
	}

	bool operator==(const Location& secondLoc) const
    {
		if (x == secondLoc.x && y == secondLoc.y)
			return true;
		return false;
	}
};

#endif /* LOCATION_H_ */
