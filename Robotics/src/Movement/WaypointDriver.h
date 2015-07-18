/*
 * WaypointDriver.h
 *
 *  Created on: Jul 17, 2015
 *      Author: colman
 */

#ifndef WAYPOINTDRIVER_H_
#define WAYPOINTDRIVER_H_
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
	bool letsGo(Location* nextLocation, Position* robotPosition);
	static double angleCalculate(Location* robotLocation, Location* nextLocation);
	static double angleToMove(Position* robotPosition, Location* nextPosition);
	static double degreeToRadian(double degree);
	virtual ~WaypointDriver();
};

#endif /* WAYPOINTDRIVER_H_ */
