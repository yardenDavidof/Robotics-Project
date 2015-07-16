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

//	for (int i=0; i< originGrid.getGridHeight();i++){
//		for(int j=0; j<originGrid.getGridWidth();j++){
//			if
//			cout<<originGrid.gridMap[i][j];
//		}
//		cout<<endl;
//	}


//GridMap grid= GridMap();
Location* start = ConfigurationManager::getInstance()->getStartLocationInGrid();//new Location(1,1);
Location* goal = ConfigurationManager::getInstance()->getGoalLocationInGrid();//new Location(1,13);

//Location* start = new Location(1,1);
//Location* goal = new Location(1,13);

cout<<weightGrid.gridMap[90][76]<<endl;
cout<<weightGrid.gridMap[42][34];

RoutePlanManager* plan = new RoutePlanManager();
vector<Location> path = plan->a_star_search(weightGrid,start,goal);

for (int i =0; i < path.size(); i++){
	cout << path[i].x << "," << path[i].y << endl;
}

weightGrid.drawGrid(path);
	return 0;
}
