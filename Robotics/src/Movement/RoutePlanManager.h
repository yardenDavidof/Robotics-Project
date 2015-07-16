/*
 * RoutePlaManager.h
 *
 *  Created on: Jun 16, 2015
 *      Author: colman
 */

#ifndef ROUTEPLANMANAGER_H_
#define ROUTEPLANMANAGER_H_

#include <vector>
#include "../Utils/PriorityQueue.h"
#include "../Utils/GridMap.h"
#include <cmath>
#include <map>

using namespace std;

class RoutePlanManager {

public:
	RoutePlanManager();
	int heuristic(Location* first, Location* second);
	void printCameFrom(map<Location,Location*>&came_from);
	vector<Location> a_star_search(GridMap grid, Location* start, Location* goal);
	vector<Location> reconstruct_path(Location* start, Location* goal, map<Location, Location*>& came_from);
	Location* getValue(map<Location,Location*>& came_from, Location key);
	virtual ~RoutePlanManager();
};

#endif /* ROUTEPLAMANAGER_H_ */
