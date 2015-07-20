#include "WaypointManeger.h"

/**
 * Constructor of WaypointManeger. Initialize the data members.
 */
WaypointManeger::WaypointManeger(vector<Location> path, ILadyRobot* ladyRobot, GridMap* gridMap) {
	waypoints = path;
	reverse(waypoints.begin(), waypoints.end());
	particleManager = new ParticleManager(gridMap, ConfigurationManager::getInstance()->getStartLocationInGrid()->getYaw());
	behaviorManager = new BehaviorManager(ladyRobot, particleManager);
	driver = new WaypointDriver(behaviorManager);
	selectWaypoints();

	cout << "selected Waypoints size " << filteredWaypoints.size() << endl;
}

/**
 * The function passing the waypoints and target the robot to the naext waypoint
 */
void WaypointManeger::run(){
	int currentWaypoint = 1;
	double readings[READINGS_NUM];

	behaviorManager->read(readings);
	Position* positionStart = ConfigurationManager::getInstance()->getStartLocationInGrid();

	while (currentWaypoint < filteredWaypoints.size()) {
		bool isGetToWaypoint;
		if (currentWaypoint + 1 < filteredWaypoints.size()){
			 isGetToWaypoint = driver->letsGo(&filteredWaypoints[currentWaypoint],&filteredWaypoints[currentWaypoint + 1 ] , positionStart);
		}
		else
		{
			 isGetToWaypoint = driver->letsGo(&filteredWaypoints[currentWaypoint], &filteredWaypoints[currentWaypoint],  positionStart);
		}

		if(isGetToWaypoint){
			cout << "current waypoint " << currentWaypoint << endl;
			currentWaypoint++;
		}

		behaviorManager->read(readings);
		particleManager->updateAll(positionStart->delta(behaviorManager->getLadyRobot()->getPosition()), readings, &filteredWaypoints[currentWaypoint]);
		behaviorManager->getLadyRobot()->read();
		positionStart = behaviorManager->getLadyRobot()->getPosition();
	}
}

/**
 * The function passing the waypoint from AStar and select the most relevant points
 */
void WaypointManeger::selectWaypoints(){
	double previousAngle = 0, nextAngle = 0;

	for (unsigned i =0; i< waypoints.size() - 1; i++){
		Location current = waypoints[i];
		Location nextLocation = waypoints[i + 1];
		nextAngle = AngleHelper::angleToMove(&current, &nextLocation);

		if (nextAngle != previousAngle){
			filteredWaypoints.push_back(current);
		}

		previousAngle = nextAngle;
	}

	filteredWaypoints.push_back(waypoints[waypoints.size() - 1]);
}

WaypointManeger::~WaypointManeger() {}
