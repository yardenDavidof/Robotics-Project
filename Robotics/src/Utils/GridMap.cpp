#include "GridMap.h"

/**
 * Constructor of gridMap. Initial the grid
 */
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

/**
 * The function return the grid width
 */
int GridMap::getGridWidth(){
	return gridWidth;
}

/**
 * The function return the grid height
 */
int GridMap::getGridHeight(){
	return gridHeight;
}

/**
 * The function  convert the getting map to the grid-> do the calculates according to conf file
 */
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

/**
 * The function return the valid neighbours of the getting location
 */
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

/**
 * The function mark the getting location as visited
 */
void GridMap::setCellVisited(Location* location){
	gridMap[(int)location->x][(int)location->y] = VISITED_CELL;
}

/**
 * The function return if the cell is visited
 */
bool GridMap::isCellVisited(Location* location){
	return gridMap[(int)location->x][(int)location->y] == VISITED_CELL;
}

/**
 * The function return if the getting location is in bound
 */
bool GridMap::inBounds(Location* location){
  return 0 <= location->x && location->x < gridHeight && 0 <= location->y && location->y < gridWidth;
}

/**
 * The function return if the getting location is blocked
 */
bool GridMap::passable(Location* location){
	if (gridMap[(int)location->x][(int)location->y] == BLOCKED_CELL)
			return false;
		return true;
}

/**
 * The function draw the path in the grid
 */
void GridMap::drawGrid(vector<Location> path){
	for (unsigned i =0; i< path.size(); i++){
		Location current = path[i];
		gridMap[(int)current.x][(int)current.y] = PATH_CELL;
	}

	for (int i = 0; i < gridHeight; i++){
		for (int j = 0; j < gridWidth; j++){
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

/**
 * The function return the map width
 */
int GridMap::getMapWidth(){
	return mapWidth;
}

/**
 * The function return the map height
 */
int GridMap::getMapHeight(){
	return mapHeight;
}

GridMap::~GridMap() {}
