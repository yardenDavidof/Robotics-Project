/*
 * Location.h
 *
 *  Created on: Jun 26, 2015
 *      Author: colman
 */

#ifndef LOCATION_H_
#define LOCATION_H_

class Location {
public:
	struct Position{
			double yaw;
			Location* location;
			Position(double x, double y, double yaw) : location(new Location(x,y)), yaw(yaw){}
		};
	double x;
	double y;

	Location(double x, double y);
	Location(Location* loc);
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


	// TODO const ?
	bool operator< (const Location& loc) const{
		if(x + y <= loc.x + loc.y)
			return true;
		return false;
	}
};

#endif /* LOCATION_H_ */
