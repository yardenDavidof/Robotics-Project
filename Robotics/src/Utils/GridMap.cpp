/*
 * MapGrid.cpp
 *
 *  Created on: Jun 16, 2015
 *      Author: colman
 */

#include "GridMap.h"


// TODO - delete (test for yarden);
GridMap::GridMap(){
	mapHeight = 20;
	mapWidth = 20;
	gridMap = new int*[mapHeight]; // num of rows

	for (int i = 0; i < mapHeight; i++)
	    gridMap[i] = new int[mapWidth];

	for (int i = 0 ; i < mapHeight; i++){
		for (int j =0 ; j < mapWidth ; j++){
			gridMap[i][j] = FREE_CELL;
		}
	}

	gridMap[1][2] = BLOCKED_CELL;
	gridMap[2][2] = BLOCKED_CELL;
	gridMap[2][1] = BLOCKED_CELL;
//	gridMap[2][0] = BLOCKED_CELL;

	gridMap[0][2] = BLOCKED_CELL;
	gridMap[0][4] = BLOCKED_CELL;
	gridMap[1][4] = BLOCKED_CELL;
	gridMap[2][4] = BLOCKED_CELL;
	gridMap[4][4] = BLOCKED_CELL;
	gridMap[4][3] = BLOCKED_CELL;
	gridMap[4][2] = BLOCKED_CELL;
	gridMap[4][1] = BLOCKED_CELL;

	gridMap[5][3] = BLOCKED_CELL;
	gridMap[6][3] = BLOCKED_CELL;
	gridMap[7][3] = BLOCKED_CELL;
	gridMap[8][3] = BLOCKED_CELL;
	gridMap[9][3] = BLOCKED_CELL;
	gridMap[3][4] = BLOCKED_CELL;
	gridMap[5][5] = BLOCKED_CELL;
	gridMap[5][6] = BLOCKED_CELL;
}

GridMap::GridMap(int width, int height) {
	mapHeight = height;
	mapWidth = width;

	gridHeight = mapHeight/RESOLUTION;
	gridWidth = mapWidth/RESOLUTION;

	// define rows
	gridMap = new int*[gridHeight];

	// defines columns
	for (int index = 0; index < gridHeight; index++){
		gridMap[index] = new int[gridWidth];
	}
	for (int i=0; i<gridHeight; i++){
		for (int j=0; j<gridWidth; j++){
			gridMap[i][j]=-1;
		}
	}
}

int GridMap::getGridWidth(){
	return gridWidth;
}

int GridMap::getGridHeight(){
	return gridHeight;
}

void GridMap::convertMapToGrid(std::vector<unsigned char> pixelMap){
	// Passing the grid cells
	for (int gridHeightIndex = 0; gridHeightIndex <  gridHeight; gridHeightIndex++){
		for (int gridWidthIndex = 0; gridWidthIndex < gridWidth; gridWidthIndex++){
			bool isCurrentCelIsFree = true;

			// Passing the cells refer to this map (4X4-> 16X16)
			for (int mapHeightIndex = gridHeightIndex*4; mapHeightIndex < (gridHeightIndex*4 + 4 ) && isCurrentCelIsFree; mapHeightIndex++){
				for (int mapWidthIndex = gridWidthIndex*16; mapWidthIndex < (gridWidthIndex *16 + 16) && isCurrentCelIsFree; mapWidthIndex +=  4){
					if(! (pixelMap[mapHeightIndex * mapWidth * 4  + mapWidthIndex + 0]
					    || pixelMap[mapHeightIndex * mapWidth * 4 + mapWidthIndex + 1]
					    || pixelMap[mapHeightIndex * mapWidth * 4 + mapWidthIndex + 2])){
						isCurrentCelIsFree = false;
					}
				}
			}

			if (isCurrentCelIsFree){
				gridMap[gridHeightIndex][gridWidthIndex] = GridMap::FREE_CELL;
			} else {
				gridMap[gridHeightIndex][gridWidthIndex] = GridMap::BLOCKED_CELL;
			}
		}
	}
}

vector<Location*> GridMap::getNeighbours(Location* location){
	vector<Location*> neighbours;
	for( int i = location->x - 1; i <= location->x + 1; ++i ){
	   for( int j = location->y - 1; j <= location->y + 1; ++j ){
		   Location* next = new Location(i,j);
		   if ( inBounds(next) && passable(next) && *location != *next)
		   {
			   neighbours.push_back(next);
		   }
	   }
	}
return neighbours;
}

void GridMap::setCellVisited(Location* location){
	gridMap[(int)location->x][(int)location->y] = VISITED_CELL;
}

bool GridMap::isCellVisited(Location* location){
	return gridMap[(int)location->x][(int)location->y] == VISITED_CELL;
}

bool GridMap::inBounds(Location* location){

	//TODO - check height + width
	  return 0 <= location->x && location->x < gridHeight && 0 <= location->y && location->y < gridWidth;
}

bool GridMap::passable(Location* location){
	if (gridMap[(int)location->x][(int)location->y] == BLOCKED_CELL)
			return false;
		return true;
}

void GridMap::drawGrid(vector<Location> path){
	for (unsigned i =0; i< path.size(); i++){
			Location current = path[i];
			gridMap[(int)current.x][(int)current.y] = PATH_CELL;
		}

	//TODO - check what is the height + width of grid
		for (int i = 0; i < gridHeight; i++){
			for (int j = 0; j < gridWidth; j++){
				// TODO - how to clean the grid from visited cells
				if (gridMap[i][j] == FREE_CELL || gridMap[i][j] == VISITED_CELL)
					cout << "." << "  ";
				else if(gridMap[i][j] == BLOCKED_CELL)
					cout << "#" << "  ";
				else if (gridMap[i][j] == PATH_CELL)
					cout << "X" << "  ";
			}
			cout << endl;
		}
}

GridMap::~GridMap() {
}

