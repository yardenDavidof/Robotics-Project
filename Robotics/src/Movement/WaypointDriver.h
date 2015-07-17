/*
 * WaypointDriver.h
 *
 *  Created on: Jul 17, 2015
 *      Author: colman
 */

#ifndef WAYPOINTDRIVER_H_
#define WAYPOINTDRIVER_H_
#include "../Behaviors/Behavior.h"
#include "../Utils/Location.h"
#include "../Utils/Position.h"
#include <math.h>
#include <stdio.h>

using namespace std;

class WaypointDriver {
private:
	Behavior* behavior;

public:
	WaypointDriver(Behavior* behavior);
	bool letsGo(Location* nextLocation);
	static double angleCalculate(Position* robotLocation, Position* nextLocation);
	static double degreeToRadian(double degree);
	virtual ~WaypointDriver();
};

#endif /* WAYPOINTDRIVER_H_ */
