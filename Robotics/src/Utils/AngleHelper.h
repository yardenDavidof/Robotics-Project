#ifndef ANGLEHELPER_H_
#define ANGLEHELPER_H_

#include "Location.h"
#include <cmath>
#include <math.h>

#define QUARTER_ONE 1
#define QUARTER_TWO 2
#define QUARTER_THREE 3
#define QUARTER_FOUR 4

using namespace std;

class AngleHelper {
public:
	AngleHelper();
	static double distance(Location* robotLocation, Location* nextLocation);
	static double angleToMove(Location* robotLocation, Location* nextLocation);
	static int getQuarter(Location* initialLoc, Location* nextLoc);
	virtual ~AngleHelper();
};

#endif
