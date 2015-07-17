/*
 * WaypointDriver.h
 *
 *  Created on: Jul 17, 2015
 *      Author: colman
 */

#ifndef WAYPOINTDRIVER_H_
#define WAYPOINTDRIVER_H_
#include "../Behaviors/Behavior.h"

using namespace std;

class WaypointDriver {
private:
	Behavior* behavior;

public:
	WaypointDriver(Behavior* behavior);
	virtual ~WaypointDriver();
};

#endif /* WAYPOINTDRIVER_H_ */
