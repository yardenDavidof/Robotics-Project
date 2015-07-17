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
#include <math.h>
#include <stdio.h>

#define PI 3.14159265

using namespace std;

class WaypointDriver {
private:
	Behavior* behavior;

public:
	WaypointDriver(Behavior* behavior);
	static double angelCalculate(Location* robotLocation, Location* nextLocation);
	virtual ~WaypointDriver();
};

#endif /* WAYPOINTDRIVER_H_ */
