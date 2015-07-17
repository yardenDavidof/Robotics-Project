/*
 * WaypointManeger.cpp
 *
 *  Created on: Jul 17, 2015
 *      Author: colman
 */

#include "WaypointManeger.h"

WaypointManeger::WaypointManeger(vector<Location> path, ILadyRobot* ladyRobot, GridMap* gridMap) {
	waypoints = path;
	behavior = new Behavior(ladyRobot);
	particleManager = new ParticleManager(gridMap, ConfigurationManager::getInstance()->getStartLocationInGrid()->getYaw());
	driver = new WaypointDriver(behavior);
}

void WaypointManeger::run(){

	int currentWaypoint = 0;
	double readings[READINGS_NUM];

	behavior->read(readings);

	particleManager->updateAll(new Position(0,0,0), readings);

	while (currentWaypoint < waypoints.size()) {
		Position* position = behavior->getLadyRobot()->getPosition();

		driver->letsGo(&waypoints[currentWaypoint]);


		behavior->read(readings);

		particleManager->updateAll(position->delta(behavior->getLadyRobot()->getPosition()), readings);
	}
}


WaypointManeger::~WaypointManeger() {
}

