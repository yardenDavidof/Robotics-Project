/*
 * WaypointDriver.h
 *
 *  Created on: Jul 17, 2015
 *      Author: colman
 */

#ifndef WAYPOINTDRIVER_H_
#define WAYPOINTDRIVER_H_

#define QUARTER_ONE 1
#define QUARTER_TWO 2
#define QUARTER_THREE 3
#define QUARTER_FOUR 4

#include "../Managers/BehaviorManager.h"
#include "../Utils/Location.h"
#include "../Utils/Position.h"
#include <math.h>
#include <stdio.h>

using namespace std;

class WaypointDriver {
private:
	BehaviorManager* behaviorManager;

public:
	WaypointDriver(BehaviorManager* manager);
	static int getQuarter(Location* initialLoc, Location* nextLoc);
	bool letsGo(Location* nextLocation, Position* robotPosition);
	static double modDoubles(double first, double second);
	static double distance(Location* robotLocation, Location* nextLocation);
	static double angleToMove(Position* robotPosition, Location* nextPosition);
	virtual ~WaypointDriver();
};

#endif /* WAYPOINTDRIVER_H_ */
