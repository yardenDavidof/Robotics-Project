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
#include <unistd.h>
#include <stdlib.h>

using namespace std;

class ConfigurationManager {
private:
	const char* CONF_FILE_LOCATION = "src/Resources/parameters.txt";
	map<string, string> dataMap;

	void readConfFile();
public:
	ConfigurationManager();
	string getMapPath();
	int getRobotWidth();
	int getRobotHeight();
	double getMapResolutionCM();
	double getGridResolutionCM();

	virtual ~ConfigurationManager();
};

#endif /* CONFIGURATIONMANAGER_H_ */
