/*
 * WaypointManeger.h
 *
 *  Created on: Jul 17, 2015
 *      Author: colman
 */

#ifndef WAYPOINTMANEGER_H_
#define WAYPOINTMANEGER_H_

#include <vector>
#include "../Utils/Location.h"
#include "../Movement/WaypointDriver.h"
#include "../Movement/ParticleManager.h"
#include "../Behaviors/Behavior.h"

#define READINGS_NUM 682

using namespace std;

class WaypointManeger {
	vector<Location> waypoints;
	WaypointDriver driver;
	ParticleManager* particleManager;
	Behavior* behavior;

public:
	WaypointManeger(vector<Location> path);
	void run();
	virtual ~WaypointManeger();
};

#endif /* WAYPOINTMANEGER_H_ */
