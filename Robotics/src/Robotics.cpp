//============================================================================
// Name        : Robotics.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Managers/ConfigurationManager.h"
#include "YardenMap.h"
#include <map>
#include "Movement/RoutePlanManager.h"
#include <vector>

using namespace std;

int main() {
//	ConfigurationManager co = ConfigurationManager();
//	co.readConfFile();





	YardenMap grid;
Position* start = new Position(4,5);
Position* goal = new Position(9,6);

//path.push_back(start);
//path.push_back(goal);

map <Position*, Position*> came_from;
map <Position*, int> cost_so_far;


RoutePlanManager* manager = new RoutePlanManager();
manager->a_star_search(grid, start, goal,came_from,cost_so_far );



for (map<Position*,Position*>::const_iterator it = came_from.begin() ; it != came_from.end() ; ++it){
	cout << it->first->x << " " << it->first->y;
	cout << " <- ";
	cout << it->second->x << " " << it->second->y;
	cout << endl;
}

vector<Position*> path = manager->reconstruct_path(start, goal, came_from);


grid.drawGrid(path);

	return 0;
}
