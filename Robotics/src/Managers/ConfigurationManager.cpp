/*
 * ConfigurationManager.cpp
 *
 *  Created on: Jun 9, 2015
 *      Author: colman
 */

#include "ConfigurationManager.h"

ConfigurationManager::ConfigurationManager() {
	readConfFile();
}

ConfigurationManager* ConfigurationManager::getInstance(){
	static ConfigurationManager instance;
	return &instance;
}

string ConfigurationManager::getMapPath(){
	return dataMap["map"];
}

int ConfigurationManager::getRobotHeight(){
	int height = 0;
	string size = dataMap["robotSize"];
	std::size_t index = size.find(" ");
	if (index != std::string::npos){
		height = atoi(size.substr(0,index).c_str());
	}
	return height;
}

int ConfigurationManager::getRobotWidth(){
	int width = 0;
	string size = dataMap["robotSize"];
	std::size_t index = size.find(" ");
	if (index != std::string::npos){
		width = atoi(size.substr(index + 1).c_str());
	}
	return width;
}

double ConfigurationManager::getMapResolutionCM(){
	return atof(dataMap["MapResolutionCM"].c_str());
}

double ConfigurationManager::getGridResolutionCM(){
	return atof(dataMap["GridResolutionCM"].c_str());
}

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


ConfigurationManager::~ConfigurationManager() {
}

