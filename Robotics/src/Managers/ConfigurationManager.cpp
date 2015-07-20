#include "ConfigurationManager.h"

/**
 * private configurationManager constructor. Read the configuration file
 */
ConfigurationManager::ConfigurationManager() {
	readConfFile();
}

/**
 * The function read the data from configuration file to map
 */
void ConfigurationManager::readConfFile(){
	std::string line = "";
	ifstream myfile (CONF_FILE_LOCATION);
	while ( getline (myfile,line) )
	{
	   std::size_t index = line.find(":");
	   if (index != std::string::npos){
		   std::string key = line.substr(0, index);
		   std::string value = line.substr(index + 2);
		   dataMap[key]= value;
	   }
	}
	myfile.close();
}

/**
 * The function return the instance of configuration
 */
ConfigurationManager* ConfigurationManager::getInstance(){
	static ConfigurationManager instance;
	return &instance;
}

/**
 * The function return the map path
 */
string ConfigurationManager::getMapPath(){
	return dataMap["map"];
}

/**
 * The function return the robot height
 */
int ConfigurationManager::getRobotHeight(){
	int height = 0;
	string size = dataMap["robotSize"];
	std::size_t index = size.find(" ");
	if (index != std::string::npos){
		height = atoi(size.substr(0,index).c_str());
	}
	return height;
}

/**
 * The function return the start location in grid after calculation
 */
Position* ConfigurationManager::getStartLocationInGrid(){
	Position* mapLocation = this->getStartLocation();
	return new Position((int)mapLocation->getX()/4, (int)mapLocation->getY()/4, mapLocation->getYaw());
}

/**
 * The function return the goal location in grid after calculation
 */
Location* ConfigurationManager::getGoalLocationInGrid(){
	Location* mapLocation = this->getGoalLocation();
	return new Location((int)mapLocation->x/4, (int)mapLocation->y/4);
}

/**
 * The function return the robot width
 */
int ConfigurationManager::getRobotWidth(){
	int width = 0;
	string size = dataMap["robotSize"];
	std::size_t index = size.find(" ");
	if (index != std::string::npos){
		width = atoi(size.substr(index + 1).c_str());
	}
	return width;
}

/**
 * The function return the map resolution in CM
 */
double ConfigurationManager::getMapResolutionCM(){
	return atof(dataMap["MapResolutionCM"].c_str());
}

/**
 * The function return the grid resolution in CM
 */
double ConfigurationManager::getGridResolutionCM(){
	return atof(dataMap["GridResolutionCM"].c_str());
}

/**
 * The function return the start location in map
 */
Position* ConfigurationManager::getStartLocation(){
	double x,y,yaw;
	string totalLocation = dataMap["startLocation"].c_str();
	std::size_t index = totalLocation.find(" ");
	if (index != std::string::npos){
		y = atof(totalLocation.substr(0, index).c_str());
		std::string continueString = totalLocation.substr(index + 1);
		index = continueString.find(" ");
		x = atof(continueString.substr(0, index).c_str());
		yaw = atof(continueString.substr(index + 1).c_str());
	}

	return new Position(x, y, yaw);
}

/**
 * The function return the goal location in map
 */
Location* ConfigurationManager::getGoalLocation(){
	double x,y,yaw;
	string totalGoal = dataMap["goal"].c_str();
	std::size_t index = totalGoal.find(" ");
	if (index != std::string::npos){
		y = atof(totalGoal.substr(0, index).c_str());
		x = atof(totalGoal.substr(index + 1).c_str());
	}

	return new Location(x, y);
}

ConfigurationManager::~ConfigurationManager() {}
