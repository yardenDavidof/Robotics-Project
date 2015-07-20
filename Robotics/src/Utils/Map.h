#ifndef MAP_H_
#define MAP_H_

#include <cstring>
#include <iostream>

#include "../Helpers/lodepng.h"
#include "../Managers/ConfigurationManager.h"

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

#endif
