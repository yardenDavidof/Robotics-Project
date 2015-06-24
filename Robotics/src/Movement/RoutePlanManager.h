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
#include "../YardenMap.h"
#include <cmath>
#include <map>

using namespace std;

class RoutePlanManager {



private:

public:
	RoutePlanManager();
	Position* getPointer(Position* pos, map<Position*, Position*>& came_from);
	int heuristic(Position* first, Position* second);
	bool a_star_search(YardenMap grid, Position* start, Position* goal, map<Position*,Position*> &came_from, map<Position*, int> &cost_so_far );
	bool isExist(vector<Position*> vec, Position* element);
	vector<Position*> reconstruct_path(Position* start, Position* goal, map<Position*, Position*>& came_from);
	virtual ~RoutePlanManager();
};

#endif /* ROUTEPLAMANAGER_H_ */
