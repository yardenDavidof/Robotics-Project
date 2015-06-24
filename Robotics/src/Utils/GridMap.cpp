/*
 * MapGrid.cpp
 *
 *  Created on: Jun 16, 2015
 *      Author: colman
 */

#include "GridMap.h"


GridMap::GridMap() {
	for (int i=0; i<GridMap::HEIGHT_IN_CENTIMETERS; i++){
		for (int j=0; j<GridMap::WIDTH_IN_CENTIMETERS; j++){
			gridMap[i][j]=-1;
		}
	}

}
void GridMap::convertMapToGrid(char **pixelMap, int mapWidth, int mapHight){
		char notGood = 'j';
		for (int indexRow = 0; indexRow < mapHight; indexRow+=4){
			for (int indexCol=0; indexCol < mapWidth; indexCol+=4){
				if (pixelMap[indexRow][indexCol] == notGood || pixelMap[indexRow][indexCol+1] == notGood || pixelMap[indexRow][indexCol+2] == notGood || pixelMap[indexRow][indexCol+3] == notGood ||
					pixelMap[indexRow+1][indexCol] == notGood || pixelMap[indexRow+1][indexCol+1] == notGood || pixelMap[indexRow+1][indexCol+2] == notGood || pixelMap[indexRow+1][indexCol+3] == notGood ||
					pixelMap[indexRow+2][indexCol] == notGood || pixelMap[indexRow+2][indexCol+1] == notGood || pixelMap[indexRow+2][indexCol+2] == notGood || pixelMap[indexRow+2][indexCol+3] == notGood ||
					pixelMap[indexRow+3][indexCol] == notGood || pixelMap[indexRow+3][indexCol+1] == notGood || pixelMap[indexRow+3][indexCol+2] == notGood || pixelMap[indexRow+3][indexCol+3] == notGood){
					gridMap[indexRow/4][indexCol/4] = GridMap::BLOCKED_CELL;
				} else {
					gridMap[indexRow/4][indexCol/4] = GridMap::FREE_CELL;
				}
			}
		}

}

GridMap::~GridMap() {
}

