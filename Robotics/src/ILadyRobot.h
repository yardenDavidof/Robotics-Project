#ifndef ILADYROBOT_H_
#define ILADYROBOT_H_

#define READINGS_NUM 682
#define LASER_RANGE 4

#include <libplayerc++/playerc++.h>
#include <cmath>
#include <math.h>

#include "Utils/Position.h"
#include  "Managers/ConfigurationManager.h"

using namespace std;
using namespace PlayerCc;

class ILadyRobot {
private:
	PlayerClient* playerClient;
	Position2dProxy* position2dProxy;
	LaserProxy* laser;
	int gridHeight;
	int gridWidth;
	void cleanCache();
	Position* CartezianCorToMatrix(Position* cartezianCor);
	Position* MatrixToCartezianCor(Position* matrixPosition);
public:
	ILadyRobot(char* ip, int port, int gridHeight, int gridWidth);
	Position* delegateToMatrix(Position* proxyPosition);
	void read();
	double getYaw();
	double getXPosition();
	double getYPosition();
	Position2dProxy* getPosition2DProxy();
	Position* getPosition();
	void setPosition();
	void setSpeed(double speed, double yaw);
	double getRange(int index);
	virtual ~ILadyRobot();
};

#endif
