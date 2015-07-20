#include "Location.h"

/**
 * Constructor of Location by x and y
 */
Location::Location(double xPos, double yPos) {
	x= xPos;
	y = yPos;
}

/**
 * Constructor of Location by another location
 */
Location::Location(Location* loc){
	x = loc->x;
	y = loc->y;
}

Location::~Location() {}
