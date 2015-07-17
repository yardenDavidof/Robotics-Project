//============================================================================
// Name        : Robotics.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Managers/ConfigurationManager.h"
#include "Utils/Map.h"
#include "Utils/GridMap.h"
#include  "Movement/RoutePlanManager.h"
using namespace std;

int main() {
	Map map;
	map.readPNG();
	GridMap originGrid( map.getMapWidth(), map.getMapHight());
	originGrid.convertMapToGrid(map.getOriginalMap());

	GridMap weightGrid( map.getMapWidth(), map.getMapHight());
	weightGrid.convertMapToGrid(map.getWeightMap());

	Location* start = ConfigurationManager::getInstance()->getStartLocationInGrid();//new Location(1,1);
	Location* goal = ConfigurationManager::getInstance()->getGoalLocationInGrid();//new Location(1,13);

	RoutePlanManager* plan = new RoutePlanManager();
	vector<Location> path = plan->a_star_search(weightGrid,start,goal);
//
//	ILadyRobot ladyRobot("localhost", 6665);
//	WaypointManeger manager(&ladyRobot);
//	manager.run();

	weightGrid.drawGrid(path);
	return 0;
}
