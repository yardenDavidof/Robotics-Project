/*
 * WaypointManeger.cpp
 *
 *  Created on: Jul 17, 2015
 *      Author: colman
 */

#include "WaypointManeger.h"

WaypointManeger::WaypointManeger(vector<Location> path, ILadyRobot* ladyRobot, GridMap* gridMap) {
	waypoints = path;
	reverse(waypoints.begin(), waypoints.end());
	particleManager = new ParticleManager(gridMap, ConfigurationManager::getInstance()->getStartLocationInGrid()->getYaw());
	behaviorManager = new BehaviorManager(ladyRobot, particleManager);
	driver = new WaypointDriver(behaviorManager);
	selectWaypoints();

	cout << "selected Waypoints " << filteredWaypoints.size() << endl;
}

void WaypointManeger::run(){

	int currentWaypoint = 1;
	double readings[READINGS_NUM];

	behaviorManager->read(readings);


	Position* positionStart = ConfigurationManager::getInstance()->getStartLocationInGrid();
	while (currentWaypoint < filteredWaypoints.size()) {

//		cout<< "x: " << positionStart->getX() << " y: " << positionStart->getY()<<endl;
		if(driver->letsGo(&filteredWaypoints[currentWaypoint], positionStart)){
			cout<<"curent wp " << currentWaypoint<<endl;
			currentWaypoint++;
		}

		behaviorManager->read(readings);

		particleManager->updateAll(positionStart->delta(behaviorManager->getLadyRobot()->getPosition()), readings);

		positionStart = particleManager->GetProbablyPosition();
	}
}

void WaypointManeger::selectWaypoints(){
	double previousAngle = 0, nextAngle = 0;

	cout << "Waypoints full: "<< endl;
	for (unsigned i =0; i< waypoints.size() - 1; i++){
		cout << "x " << waypoints[i].x << " y " << waypoints[i].y << endl;
	}

	cout << "filtered: "  << endl;
	for (unsigned i =0; i< waypoints.size() - 1; i++){
		Location current = waypoints[i];
		Location nextLocation = waypoints[i + 1];
		nextAngle = WaypointDriver::angleToMove(&current, &nextLocation);

		if (nextAngle != previousAngle){
			filteredWaypoints.push_back(current);
			cout << "x " << current.x << " y " << current.y << endl;
		}

		previousAngle = nextAngle;
	}
	filteredWaypoints.push_back(waypoints[waypoints.size() - 1]);
}

WaypointManeger::~WaypointManeger() {
}

