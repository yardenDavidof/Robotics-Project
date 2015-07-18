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
#include "../Managers/BehaviorManager.h"
#include "../ILadyRobot.h"
#include "../Utils/GridMap.h"
#include "ConfigurationManager.h"

#define READINGS_NUM 682
#define REGULAR_SPEED 0.6
#define OBSTACLE_SPEED 0.2

using namespace std;

class WaypointManeger {
	vector<Location> waypoints;
	WaypointDriver* driver;
	ParticleManager* particleManager;
	BehaviorManager* behaviorManager;

public:
	WaypointManeger(vector<Location> path, ILadyRobot* ladyRobot, GridMap* gridMap);
	void run();
	virtual ~WaypointManeger();
};

#endif /* WAYPOINTMANEGER_H_ */
