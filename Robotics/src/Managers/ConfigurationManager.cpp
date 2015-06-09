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
	      cout << line << '\n';
	    }
	    myfile.close();
//	  }

}


ConfigurationManager::~ConfigurationManager() {
}

