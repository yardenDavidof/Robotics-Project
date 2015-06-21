/*
 * RoutePlaManager.h
 *
 *  Created on: Jun 16, 2015
 *      Author: colman
 */

#ifndef ROUTEPLAMANAGER_H_
#define ROUTEPLAMANAGER_H_

#include <vector>
#include "../Utils/PriorityQueue.h"
#include "../YardenMap.h"
#include <cmath>
#include <map>

using namespace std;

class RoutePlaManager {



private:

public:
	RoutePlaManager();
	Position* getPointer(Position* pos, map<Position*, Position*>& came_from);
	int heuristic(Position* first, Position* second);
	void a_star_search(YardenMap grid, Position* start, Position* goal, map<Position*,Position*> &came_from, map<Position*, int> &cost_so_far );
	bool isExist(vector<Position*> vec, Position* element);
	vector<Position*> reconstruct_path(Position* start, Position* goal, map<Position*, Position*>& came_from);
	virtual ~RoutePlaManager();
};

#endif /* ROUTEPLAMANAGER_H_ */
