/*
 * Map.h
 *
 *  Created on: Jun 2, 2015
 *      Author: colman
 */

#ifndef MAP_H_
#define MAP_H_

#include "../Helpers/lodepng.h"
#include "../Managers/ConfigurationManager.h"
#include <cstring>
#include <iostream>
using namespace std;

class Map {
private:
	std::vector<unsigned char> originalImage;
	std::vector<unsigned char> imageWeight;
public:
	Map();
	int* getGrid();


	void readPNG();

	virtual ~Map();
};

#endif /* MAP_H_ */
