/*
 * YardenMap.h
 *
 *  Created on: Jun 17, 2015
 *      Author: colman
 */

#ifndef YARDENMAP_H_
#define YARDENMAP_H_

#include <set>
#include "Utils/PriorityQueue.h"
#include <iostream>

using namespace std;

class YardenMap {

	public:
	static const int WIDTH_IN_CENTIMETERS = 10;
	static const int HEIGHT_IN_CENTIMETERS = 10;

	static const int FREE_CELL = 0;
	static const int BLOCKED_CELL = 1;
	static const int UNKOWNN_CELL = 2;
	static const int ROBOT_CURRENT_CELL = 3;
	static const int PATH_CELL = 4;

private:
	int map[HEIGHT_IN_CENTIMETERS][WIDTH_IN_CENTIMETERS];

public:
	YardenMap();
	vector<Position*> getNeighbours(Position* pos);
	bool inBounds(Position* pos);
	bool passable(Position* pos);
	void drawGrid(vector<Position*> path);

	virtual ~YardenMap();
};

#endif /* YARDENMAP_H_ */
