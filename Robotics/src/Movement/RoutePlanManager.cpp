/*
 * RoutePlaManager.cpp
 *
 *  Created on: Jun 16, 2015
 *      Author: colman
 */

#include "RoutePlanManager.h"

RoutePlanManager::RoutePlanManager() {
}


int RoutePlanManager::heuristic(Location* first, Location* second){
	return abs(first->x - second->x) + abs(first->y - second->y);
}

vector<Location*> RoutePlanManager::a_star_search(GridMap grid, Location* start, Location* goal){
	map<Location*,Location*> came_from;
	map<Location*, int> cost_so_far;

	PriorityQueue frontier = PriorityQueue();
	frontier.put(start,0);

	cost_so_far.insert(pair<Location*,int>(start,0));
	came_from.insert(pair<Location*,Location*>(start,start));

	  while (!frontier.isEmpty()) {
		  PriorityQueue::Node current = frontier.get();

		if (*current.pos == *goal) {
	      return reconstruct_path(start, goal, came_from);
	    }

	    grid.setCellVisited(current.pos);
	    vector<Location*> neighboors = grid.getNeighbours(current.pos);
	    int new_cost = cost_so_far[current.pos]++;

	    for (unsigned i = 0; i < neighboors.size(); i++){
	    	Location* next = neighboors[i];

	    	if (!grid.isCellVisited(next) || new_cost < cost_so_far[next]){
	    		cost_so_far[next] = new_cost;
	    		grid.setCellVisited(next);
	    		int priority = new_cost + heuristic(next, goal);
	    		frontier.put(next, priority);
	    		came_from[next] = current.pos;
	    	}
	    }
	   }

	  return vector<Location*>();
}

Location* RoutePlanManager::getPointer(Location* pos, map<Location*, Location*>& came_from){
for (map<Location*,Location*>::iterator it = came_from.begin(); it != came_from.end(); ++it){
	if (pos == it->first){
		return it->first;
	}
}
return pos;
}

// TODO - find solution to the pointers
vector<Location*> RoutePlanManager::reconstruct_path(Location* start, Location* goal, map<Location*, Location*>& came_from) {
  vector<Location*> path;
  Location* current = goal;
  path.push_back(current);
  while (*current != *start) {
    current = came_from[getPointer(current,came_from)];
    path.push_back(current);
  }
  return path;
}

RoutePlanManager::~RoutePlanManager() {
}
