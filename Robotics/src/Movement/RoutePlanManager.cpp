/*
 * RoutePlaManager.cpp
 *
 *  Created on: Jun 16, 2015
 *      Author: colman
 */

#include "RoutePlanManager.h"

RoutePlanManager::RoutePlanManager() {
}


int RoutePlanManager::heuristic(Position* first, Position* second){
	return abs(first->x - second->x) + abs(first->y - second->y);
}

bool RoutePlanManager::isExist(vector<Position*> vec, Position* element){
	for (int i=0; i< vec.size(); i++){
		if (vec[i]->x == element->x && vec[i]->y == element->y)
			return true;
	}
	return false;
}

bool RoutePlanManager::a_star_search(YardenMap grid, Position* start, Position* goal, map<Position*,Position*> &came_from, map<Position*, int> &cost_so_far ){
	PriorityQueue frontier = PriorityQueue();
	frontier.put(start,0);

	vector<Position*> visitedCells;

	cost_so_far.insert(pair<Position*,int>(start,0));
	came_from.insert(pair<Position*,Position*>(start,start));

	  while (!frontier.isEmpty()) {
		  PriorityQueue::Node current = frontier.get();

	    if (*current.pos == *goal) {
	      break;
	    }

	    visitedCells.push_back(current.pos);
	    vector<Position*> neighboors = grid.getNeighbours(current.pos);


	    int new_cost = cost_so_far[current.pos] + 1;
	    for (unsigned i = 0; i < neighboors.size(); i++){
	    	Position* next = neighboors[i];

	    	// TODO understand why count is not goosd
	    	// if there is no cost_so_far (meaning we have not visit it) to next or the new cost is lower
	    	if (!isExist(visitedCells, next) || new_cost < cost_so_far[next]){
	    		cost_so_far[next] = new_cost;
	    		visitedCells.push_back(next);
	    		int priority = new_cost + heuristic(next, goal);
	    		frontier.put(next, priority);
	    		came_from[next] = current.pos;
	    	}
	    }

	   }
}

Position* RoutePlanManager::getPointer(Position* pos, map<Position*, Position*>& came_from){
for (map<Position*,Position*>::iterator it = came_from.begin(); it != came_from.end(); ++it){
	if (pos->x == it->first->x && pos->y == it->first->y){
		return it->first;
	}
}
return pos;
}

// TODO - find solution to the pointers
vector<Position*> RoutePlanManager::reconstruct_path(Position* start, Position* goal, map<Position*, Position*>& came_from) {
  vector<Position*> path;
  Position* current = goal;
  path.push_back(current);
  while (*current != *start) {
    current = came_from[getPointer(current,came_from)];
    path.push_back(current);
  }
  return path;
}

RoutePlanManager::~RoutePlanManager() {
}

