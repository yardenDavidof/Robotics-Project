#include "AngleHelper.h"

/**
 * Empty constructor of AngleHelper
 */
AngleHelper::AngleHelper() {}

/**
 * The function calculate the angle to move according to getting location
 */
double AngleHelper::angleToMove(Location* robotLocation, Location* nextLocation){
	float yDeltaToPoint = abs(nextLocation->y - robotLocation->y);
	float distanceToPoint = distance(robotLocation, nextLocation);
	float neededYaw = acos(yDeltaToPoint / distanceToPoint);

	double radYaw;
	int quarter = getQuarter(robotLocation, nextLocation);
	if (quarter == QUARTER_ONE){
		radYaw = neededYaw;
	}
	else if(quarter == QUARTER_TWO)
	{
		radYaw = M_PI - neededYaw;
	}
	else if (quarter == QUARTER_THREE){
		radYaw = M_PI + neededYaw;
	}
	else{
		radYaw = M_PI * 2 - neededYaw;
	}

	return radYaw;
}

/**
 * The function return the distance between the getting locations
 */
double AngleHelper::distance(Location* robotLocation, Location* nextLocation){
	return sqrt(pow(robotLocation->x - nextLocation->x, 2) + pow(robotLocation->y - nextLocation->y, 2));
}

/**
 * The function return the quarter of the angle to go from initial to next location
 */
int AngleHelper::getQuarter(Location* initialLoc, Location* nextLoc) {
	if (initialLoc->x > nextLoc->x) {
			if (initialLoc->y > nextLoc->y)
				return QUARTER_TWO;
			else
				return QUARTER_ONE;
	}
	else {
		if (initialLoc->y > nextLoc->y)
			return QUARTER_THREE;
		else
			return QUARTER_FOUR;
	}
}

AngleHelper::~AngleHelper() {}
