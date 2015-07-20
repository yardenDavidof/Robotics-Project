#include "ILadyRobot.h"

ILadyRobot::ILadyRobot(char* ip, int port, int gridHeight, int gridWidth){
	gridHeightCM = gridHeight * 10;
	gridWidthCM = gridWidth * 10;
	playerClient = new PlayerClient(ip, port);
	laser = new LaserProxy(playerClient);
	position2dProxy = new Position2dProxy(playerClient);
	position2dProxy->SetMotorEnable(true);
	Position* startPos = ConfigurationManager::getInstance()->getStartLocation();
	position2dProxy->SetOdometry(startPos->getX()*0.025, startPos->getY()*0.025, dtor(startPos->getYaw()));
	cleanCache();
}

Position2dProxy* ILadyRobot::getPosition2DProxy(){
	read();
	return position2dProxy;
}

Position* ILadyRobot::delegateToMatrix(Position* proxyPosition){
	Position* matrixPosition = new Position( proxyPosition->getX(), - gridHeightCM/10 +  proxyPosition->getY(), proxyPosition->getYaw());
	return matrixPosition;
}

void ILadyRobot::read(){
	playerClient->Read();
}

double ILadyRobot::getYaw(){
	read();
	return position2dProxy->GetYaw();
}

double ILadyRobot::getXPosition(){
	read();
	return position2dProxy->GetXPos();
}

double ILadyRobot::getYPosition(){
	read();
	return position2dProxy->GetYPos();
}

Position* ILadyRobot::getPosition(){
	read();
	Position* positionProxyCM = new Position(getXPosition() * 10, getYPosition() * 10, getYaw() * 10);
	return delegateToMatrix(positionProxyCM);
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
