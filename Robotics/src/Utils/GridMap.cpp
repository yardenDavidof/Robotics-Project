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
	for (int i=0; i<mapHeight/RESOLUTION/4; i++){
		for (int j=0; j<mapWidth/RESOLUTION/4; j++){
			gridMap[i][j]=-1;
		}
	}
}

void GridMap::convertMapToGrid(std::vector<unsigned char> pixelMap){
	for (int indexHeight = 0; indexHeight < mapHeight/RESOLUTION; indexHeight++){
		for(int indexWidth = 0; indexWidth < mapWidth/RESOLUTION; indexWidth++)
		{
			if (!(pixelMap[indexHeight * mapWidth * 4 + mapHeight * 4 + 0]
				|| pixelMap[indexHeight * mapWidth * 4 + mapHeight * 4 + 1]
				|| pixelMap[indexHeight * mapWidth * 4 + mapHeight * 4 + 2]))
			{
			}



		char notGood = 0;
		for (int indexRow = 0; indexRow < mapHeight; indexRow= indexRow +RESOLUTION){
			for (int indexCol=0; indexCol < mapWidth; indexCol= indexCol + RESOLUTION){
				if (pixelMap[indexRow + indexCol] == notGood || pixelMap[indexRow + indexCol+1] == notGood || pixelMap[indexRow + indexCol+2] == notGood || pixelMap[indexRow + indexCol+3] == notGood ||
					pixelMap[indexRow+1 + indexCol] == notGood || pixelMap[indexRow+1 + indexCol+1] == notGood || pixelMap[indexRow+1 + indexCol+2] == notGood || pixelMap[indexRow+1 + indexCol+3] == notGood ||
					pixelMap[indexRow+2 + indexCol] == notGood || pixelMap[indexRow+2 + indexCol+1] == notGood || pixelMap[indexRow+2 + indexCol+2] == notGood || pixelMap[indexRow+2 + indexCol+3] == notGood ||
					pixelMap[indexRow+3 + indexCol] == notGood || pixelMap[indexRow+3 + indexCol+1] == notGood || pixelMap[indexRow+3 + indexCol+2] == notGood || pixelMap[indexRow+3 + indexCol+3] == notGood){
					gridMap[indexRow/RESOLUTION][indexCol/RESOLUTION] = GridMap::BLOCKED_CELL;
				} else {
					gridMap[indexRow/RESOLUTION][indexCol/RESOLUTION] = GridMap::FREE_CELL;
				}
			}
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
	  return 0 <= location->x && location->x < mapWidth && 0 <= location->y && location->y < mapHeight;
}

bool GridMap::passable(Location* location){
	if (gridMap[(int)location->x][(int)location->y] == BLOCKED_CELL)
			return false;
		return true;
}

void GridMap::drawGrid(vector<Location*> path){
	for (unsigned i =0; i< path.size(); i++){
			Location* current = path[i];
			gridMap[(int)current->x][(int)current->y] = PATH_CELL;
		}

	//TODO - check what is the height + width of grid
		for (int i = 0; i < mapHeight; i++){
			for (int j = 0; j < mapWidth; j++){
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

