
#include <iostream>
#include "Managers/ConfigurationManager.h"
#include "Utils/Map.h"
#include "Utils/GridMap.h"
#include  "Movement/RoutePlanManager.h"
#include "ILadyRobot.h"
#include "Managers/WaypointManeger.h"
using namespace std;

/**
 * The main for running the robot
 */
int main() {
	Map map;
	map.readPNG();
	GridMap originGrid( map.getMapWidth(), map.getMapHight());
	originGrid.convertMapToGrid(map.getOriginalMap());

	GridMap weightGrid( map.getMapWidth(), map.getMapHight());
	weightGrid.convertMapToGrid(map.getWeightMap());

	cout << "gridHright " << weightGrid.getGridHeight() << " gridWidth " << originGrid.getGridWidth() << endl;

	Location* start = ConfigurationManager::getInstance()->getStartLocationInGrid()->getLocation();
	Location* goal = ConfigurationManager::getInstance()->getGoalLocationInGrid();

	RoutePlanManager* plan = new RoutePlanManager();
	vector<Location> path = plan->a_star_search(weightGrid,start,goal);

	ILadyRobot ladyRobot("localhost", 6665, originGrid.getGridHeight(), originGrid.getGridWidth());
	WaypointManeger manager(path, &ladyRobot, &originGrid);
	manager.run();
	weightGrid.drawGrid(path);

	return 0;
}
