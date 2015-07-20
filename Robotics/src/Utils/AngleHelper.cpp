/*
 * AngleHElper.cpp
 *
 *  Created on: Jul 19, 2015
 *      Author: colman
 */

#include "AngleHelper.h"

AngleHelper::AngleHelper() {
	// TODO Auto-generated constructor stub

}

double AngleHelper::angleToMove(Location* robotLocation, Location* nextLocation){

	float yDeltaToPoint = abs(nextLocation->y - robotLocation->y);

		float distanceToPoint = distance(robotLocation, nextLocation);
		float neededYaw = acos(yDeltaToPoint / distanceToPoint);

		double radYaw;
		int quarter = getQuarter(robotLocation, nextLocation);
		if (quarter == QUARTER_ONE){
//			radYaw = M_PI_2 - neededYaw;
			radYaw = neededYaw;
		}
		else if(quarter == QUARTER_TWO)
		{
			radYaw = M_PI - neededYaw;
		}
		else if (quarter == QUARTER_THREE){
//			radYaw = M_PI + M_PI_2 - neededYaw;
			radYaw = M_PI + neededYaw;
		}
		else{
			radYaw = M_PI * 2 - neededYaw;
		}

		return radYaw;
}

double AngleHelper::distance(Location* robotLocation, Location* nextLocation){
	return sqrt(pow(robotLocation->x - nextLocation->x, 2) + pow(robotLocation->y - nextLocation->y, 2));
}

int AngleHelper::getQuarter(Location* initialLoc, Location* nextLoc) {
//	if (initialLoc->y > nextLoc->y) {
//		if (initialLoc->x > nextLoc->x)
//			return QUARTER_TWO;
//		else
//			return QUARTER_ONE;
//	}
//	else {
//		if (initialLoc->x > nextLoc->x)
//			return QUARTER_THREE;
//		else
//			return QUARTER_FOUR;

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

AngleHelper::~AngleHelper() {
	// TODO Auto-generated destructor stub
}

