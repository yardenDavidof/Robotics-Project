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
//	Map map;
//	map.readPNG();
//	GridMap originGrid( map.getMapWidth(), map.getMapHight());
//	originGrid.convertMapToGrid(map.getOriginalMap());
//	GridMap weightGrid( map.getMapWidth(), map.getMapHight());
//	weightGrid.convertMapToGrid(map.getWeightMap());

GridMap grid= GridMap();
Location* start = new Location(1,1);
Location* goal = new Location(1,13);

RoutePlanManager* plan = new RoutePlanManager();
vector<Location*> path = plan->a_star_search(grid,start,goal);

grid.drawGrid(path);
	return 0;
}
