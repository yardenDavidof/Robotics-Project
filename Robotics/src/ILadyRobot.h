/*
 * ILadyRobot.h
 *
 *  Created on: Jun 9, 2015
 *      Author: colman
 */

#ifndef ILADYROBOT_H_
#define ILADYROBOT_H_

#include <libplayerc++/playerc++.h>
#include "Utils/Position.h"

using namespace std;
using namespace PlayerCc;


class ILadyRobot {
private:

	PlayerClient* playerClient;
	Position2dProxy* position2dProxy;
	LaserProxy* laser;
	void cleanCache();
public:
	ILadyRobot(char* ip, int port);
	void read();
	double getYaw();
	double getXPosition();
	double getYPosition();
	Position* getPosition();
	void setSpeed(double speed, double yaw);
	double getRange(int index);

	virtual ~ILadyRobot();
};

#endif /* ILADYROBOT_H_ */
