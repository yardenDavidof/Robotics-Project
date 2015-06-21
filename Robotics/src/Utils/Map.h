#ifndef MAP_H_
#define MAP_H_

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "RGB.h"
#include "Position.h"

using namespace std;

class Map {
public:
	static const int WIDTH_IN_CENTIMETERS = 1000;
	static const int HEIGHT_IN_CENTIMETERS = 1000;
	static const int RESOLUTION_IN_CENTIMTERS = 10;

	static const int FREE_CELL = 0;
	static const int BLOCKED_CELL = 1;
	static const int UNKOWNN_CELL = 2;
	static const int ROBOT_CURRENT_CELL = 3;

private:
	int map[HEIGHT_IN_CENTIMETERS][WIDTH_IN_CENTIMETERS];
    RGB* getCellColor(int i, int j);

public:
    Map();
    void getPosition(float x, float y, int &x1, int &y1);
    void updateMap(int i, int j, int value);
    int getCellType(int i, int j);
    void printMap();

    ~Map();
};

#endif
