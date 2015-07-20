#ifndef POSITION_H_
#define POSITION_H_

#include <cmath>

#include "Location.h"

using namespace std;

class Position {
private:
	double yaw;
	Location* location;
public:
	Position();
	virtual ~Position();
	Position(double x, double y, double yaw);
	int getX();
	int getY();
	int getYaw();
	Location* getLocation();
	void setX(double setX);
	void setY(double setY);
	void setYaw(double setY);
	Position* delta(Position* old);
};

#endif
