//============================================================================
// Name        : Robotics.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Managers/ConfigurationManager.h"
using namespace std;

int main() {
	ConfigurationManager co = ConfigurationManager();
	co.readConfFile();


	return 0;
}
