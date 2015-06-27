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
	unsigned width;
	unsigned height;
public:
	Map();
	std::vector<unsigned char> getOriginalMap();
	std::vector<unsigned char> getWeightMap();
	unsigned getMapWidth();
	unsigned getMapHight();

	void readPNG();

	virtual ~Map();
};

#endif /* MAP_H_ */
