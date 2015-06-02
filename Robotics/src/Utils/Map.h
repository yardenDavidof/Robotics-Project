/*
 * Map.h
 *
 *  Created on: Jun 2, 2015
 *      Author: colman
 */

#ifndef MAP_H_
#define MAP_H_

class Map {
private:
	int mapSize;
	int* Grid;
	double resolution;
public:
	Map();
	int* getGrid();


	void readPNG();

	virtual ~Map();
};

#endif /* MAP_H_ */
