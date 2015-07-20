#ifndef LOCATION_H_
#define LOCATION_H_

class Location {
public:
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

	bool operator< (const Location& loc) const{
		if(x + y <= loc.x + loc.y)
			return true;
		return false;
	}
};

#endif
