/*
 * ConfigurationManager.h
 *
 *  Created on: Jun 9, 2015
 *      Author: colman
 */

#ifndef CONFIGURATIONMANAGER_H_
#define CONFIGURATIONMANAGER_H_

#include <fstream>
#include <iostream>
#include <cstring>
#include <map>

using namespace std;

class ConfigurationManager {
private:

	const char* CONF_FILE_LOCATION = "../Resources/parameters.txt";//"/home/colman/git/Robotics-Project/Robotics/src/Resources/parameters.txt";//Resources/parameter.txt";
	map<string, string> dataMap;
public:
	ConfigurationManager();
	void readConfFile();
	virtual ~ConfigurationManager();
};

#endif /* CONFIGURATIONMANAGER_H_ */
