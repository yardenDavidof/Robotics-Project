/*
 * WaypointManeger.cpp
 *
 *  Created on: Jul 17, 2015
 *      Author: colman
 */

#include "WaypointManeger.h"

WaypointManeger::WaypointManeger(vector<Location> path, ILadyRobot* ladyRobot, GridMap* gridMap) {
	waypoints = path;
	behaviorManager = new BehaviorManager(ladyRobot);
	particleManager = new ParticleManager(gridMap, ConfigurationManager::getInstance()->getStartLocationInGrid()->getYaw());
	driver = new WaypointDriver(behaviorManager);
}

void WaypointManeger::run(){

	int currentWaypoint = 0;
	double readings[READINGS_NUM];

	behaviorManager->read(readings);

	particleManager->updateAll(new Position(0,0,0), readings);

	while (currentWaypoint < waypoints.size()) {
		Position* positionStart = particleManager->GetProbablyPosition();
		if(driver->letsGo(&waypoints[currentWaypoint], positionStart)){
			currentWaypoint++;
		}

		behaviorManager->read(readings);

		particleManager->updateAll(positionStart->delta(behaviorManager->getLadyRobot()->getPosition()), readings);
	}
}


WaypointManeger::~WaypointManeger() {
}

