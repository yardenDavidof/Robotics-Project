#include "ILadyRobot.h"

ILadyRobot::ILadyRobot(char* ip, int port){
	playerClient = new PlayerClient(ip, port);
	laser = new LaserProxy(playerClient);
	position2dProxy = new Position2dProxy(playerClient);
	position2dProxy->SetMotorEnable(true);
	Position* startPos = ConfigurationManager::getInstance()->getStartLocation();
	position2dProxy->SetOdometry(startPos->getX()*0.025, startPos->getY()*0.025, dtor(startPos->getYaw()));
	cleanCache();
}

Position2dProxy* ILadyRobot::getPosition2DProxy(){
	return position2dProxy;
}

void ILadyRobot::read(){
	playerClient->Read();
}

double ILadyRobot::getYaw(){
	return position2dProxy->GetYaw();
}

double ILadyRobot::getXPosition(){
	return position2dProxy->GetXPos();
}

double ILadyRobot::getYPosition(){
	return position2dProxy->GetYPos();
}

Position* ILadyRobot::getPosition(){
	return new Position(getXPosition(), getYPosition(), getYaw());
}

void ILadyRobot::setSpeed(double speed, double yaw){
	position2dProxy->SetSpeed(speed,yaw);
}

void ILadyRobot::cleanCache() {
	for(int i = 0; i < 15; i++){
		playerClient->Read();
	}
}

double ILadyRobot::getRange(int index) {
	return (*laser)[index];

}

ILadyRobot::~ILadyRobot(){

}
