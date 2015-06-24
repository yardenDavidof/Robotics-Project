/*
 * ConfigurationManager.cpp
 *
 *  Created on: Jun 9, 2015
 *      Author: colman
 */

#include "ConfigurationManager.h"

ConfigurationManager::ConfigurationManager() {
}

void ConfigurationManager::readConfFile(){
	 string line;
	 ifstream myfile (CONF_FILE_LOCATION);
//	  if (myfile.is_open())
//	  {
	    while ( getline (myfile,line) )
	    {

	   	   std::size_t index = line.find(":");
	   	   if (index != std::string::npos){

	   		   std::string key = line.substr(0, index);
	   		   std::string value = line.substr(index);
	   		   dataMap[key]= value;
	   	   }

	      cout << line << '\n';
	    }
	    myfile.close();
}


ConfigurationManager::~ConfigurationManager() {
}

