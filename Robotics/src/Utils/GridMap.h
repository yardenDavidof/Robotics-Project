/*
 * GridMap.h
 *
 *  Created on: Jun 16, 2015
 *      Author: colman
 */

#ifndef GRIDMAP_H_
#define GRIDMAP_H_

#include <iostream>

class GridMap {
public:
	static const int FREE_CELL = 0;
	static const int BLOCKED_CELL = 1;

	static const int WIDTH_IN_CENTIMETERS = 4;
	static const int HEIGHT_IN_CENTIMETERS = 4;
	static const int RESOLUTION_IN_CENTIMTERS = 10;
	int gridMap[HEIGHT_IN_CENTIMETERS][WIDTH_IN_CENTIMETERS];
	GridMap();
//	void convertMapToGrid(std::vector<unsigned char> pixelMap );
//	void convertMapToGrid(char& pixelMap);
	void convertMapToGrid(char **pixelMap);
	virtual ~GridMap();
};

#endif /* GRIDMAP_H_ */
