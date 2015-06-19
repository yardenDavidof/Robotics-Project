/*
 * MapGrid.cpp
 *
 *  Created on: Jun 16, 2015
 *      Author: colman
 */

#include "GridMap.h"


GridMap::GridMap() {

}
void GridMap::convertMapToGrid(){
	for (int i=0; i<GridMap::HEIGHT_IN_CENTIMETERS; i++){
		for (int j=0; j<GridMap::WIDTH_IN_CENTIMETERS; j++){
			gridMap[i][j]=0;
		}
	}

}
//void GridMap::convertMapToGrid(char* pixelMap){
//	int widthOfMap = 12;
//	int hightOfMap = 8;
//	char notGood = 'j';
////void GridMap::convertMapToGrid(std::vector<unsigned char>& pixelMap ){
//	for (int indexRow = 0; indexRow < hightOfMap/4; indexRow+=4){
//		for (int indexCol=0; indexCol < widthOfMap/4; indexCol+=4){
//			if (pixelMap[indexRow][indexCol] == notGood || pixelMap[indexRow][indexCol+1] == notGood || pixelMap[indexRow][indexCol+2] == notGood || pixelMap[indexRow][indexCol+3] == notGood ||
//				pixelMap[indexRow+1][indexCol] == notGood || pixelMap[indexRow+1][indexCol+1] == notGood || pixelMap[indexRow+1][indexCol+2] == notGood || pixelMap[indexRow+1][indexCol+3] == notGood ||
//				pixelMap[indexRow+2][indexCol] == notGood || pixelMap[indexRow+2][indexCol+1] == notGood || pixelMap[indexRow+2][indexCol+2] == notGood || pixelMap[indexRow+2][indexCol+3] == notGood ||
//				pixelMap[indexRow+3][indexCol] == notGood || pixelMap[indexRow+3][indexCol+1] == notGood || pixelMap[indexRow+3][indexCol+2] == notGood || pixelMap[indexRow+3][indexCol+3] == notGood){
//				gridMap[indexRow/4][indexCol/4] = GridMap::BLOCKED_CELL;
//			} else {
//				gridMap[indexRow/4][indexCol/4] = GridMap::FREE_CELL;
//			}
//		}
//	}
////	for(int i=0; i<GridMap::HEIGHT_IN_CENTIMETERS; i++){
////		for(int j=0; j<GridMap::WIDTH_IN_CENTIMETERS; j++){
////			if (pixelMap[i*4][j*4] == 'j' || pixelMap[i*4][j*4] == 'j' || pixelMap[i*4][j*4] == 'j'){
////				gridMap[i][j] = GridMap::BLOCKED_CELL;
////			} else {
////				gridMap[i][j] = GridMap::FREE_CELL;
////			}
////		}
////	}
////	std::vector<std::vector<int>> myGrid = std::vector<std::vector<int>>() ;
////	for (int i=0; i< pixelMap.size()-4; i+=4){
////		if (pixelMap[i] == 'a' || pixelMap[i+1] == 'g'||
////				pixelMap[i+2] == 'a' || pixelMap[i+3] == 'g'){
////			myGrid[1] = 1;
////
////		} else{
////			myGrid[1] = 2;
////		}
////	}
//
//}

GridMap::~GridMap() {
}

