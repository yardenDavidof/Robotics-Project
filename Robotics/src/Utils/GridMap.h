/*
 * GridMap.h
 *
 *  Created on: Jun 16, 2015
 *      Author: colman
 */

#ifndef GRIDMAP_H_
#define GRIDMAP_H_

#include <iostream>
#include "Location.h"
#include <vector>
#include "../Managers/ConfigurationManager.h"

using namespace std;

class GridMap {
private:
	int mapWidth;
	int mapHeight;
	int gridHeight;
	int gridWidth;
public:
	static const int FREE_CELL = 0;
	static const int BLOCKED_CELL = 1;
	static const int PATH_CELL = 2;
	static const int VISITED_CELL = 3;

	const  int RESOLUTION = ConfigurationManager::getInstance()->getGridResolutionCM()/ ConfigurationManager::getInstance()->getMapResolutionCM();
	int** gridMap;
	GridMap(int mapWidth, int mapHight);
	GridMap();
	int getGridWidth();
	int getGridHeight();
	int getMapWidth();
	int getMapHeight();
	void convertMapToGrid(std::vector<unsigned char> pixelMap);
	vector<Location*> getNeighbours(Location* pos);
	bool inBounds(Location* pos);
	bool passable(Location* pos);
	void drawGrid(vector<Location> path);
	void setCellVisited(Location* location);
	bool isCellVisited(Location* location);

	virtual ~GridMap();
};

#endif /* GRIDMAP_H_ */
