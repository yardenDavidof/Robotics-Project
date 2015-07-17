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

#define READINGS_NUM 682

using namespace std;

class WaypointManeger {
	vector<Location> waypoints;
	WaypointDriver driver;
	ParticleManager* particleManager;

public:
	WaypointManeger(vector<Location> path);
	void run();
	virtual ~WaypointManeger();
};

#endif /* WAYPOINTMANEGER_H_ */
