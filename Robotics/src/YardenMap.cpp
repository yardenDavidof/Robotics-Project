/*
 * YardenMap.cpp
 *
 *  Created on: Jun 17, 2015
 *      Author: colman
 */

#include "YardenMap.h"

YardenMap::YardenMap() {

	for (int i = 0; i < HEIGHT_IN_CENTIMETERS; i++) {
		for (int j = 0; j < WIDTH_IN_CENTIMETERS; j++) {
			map[i][j] = FREE_CELL;
		}
	}

	map[3][3] = BLOCKED_CELL;
	map[3][4] = BLOCKED_CELL;
	map[5][5]= BLOCKED_CELL;
	map[5][6] = BLOCKED_CELL;
}

vector<Position*> YardenMap::getNeighbours(Position* pos){
	vector<Position*> neighbours;
	for( int i = pos->x - 1; i <= pos->x + 1; ++i ){
	   for( int j = pos->y - 1; j <= pos->y + 1; ++j ){
		   Position* next = new Position(i,j);
		   if (passable(next) && inBounds(next) && *pos != *next)
		   {
			   neighbours.push_back(next);
		   }
	   }
	}
return neighbours;
}

bool YardenMap::inBounds(Position* pos){
    int x, y;
    x = pos->x;
    y = pos->y;
    return 0 <= x && x < WIDTH_IN_CENTIMETERS && 0 <= y && y < HEIGHT_IN_CENTIMETERS;
}

bool YardenMap::passable(Position* pos){

	if (map[(int)pos->x][(int)pos->y] == BLOCKED_CELL)
		return false;
	return true;
}

void YardenMap::drawGrid(vector<Position*> path){
	for (unsigned i =0; i< path.size(); i++){
		Position* current = path[i];
		map[(int)current->x][(int)current->y] = PATH_CELL;
	}

	for (int i = 0; i < HEIGHT_IN_CENTIMETERS; i++){
		for (int j = 0; j < WIDTH_IN_CENTIMETERS; j++){
			if (map[i][j] == FREE_CELL)
				cout << "." << "  ";
			else if(map[i][j] == BLOCKED_CELL)
				cout << "#" << "  ";
			else if (map[i][j] == PATH_CELL)
				cout << "X" << "  ";
		}
		cout << endl;
	}
}

YardenMap::~YardenMap() {
}

