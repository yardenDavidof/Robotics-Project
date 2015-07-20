#include "ILadyRobot.h"

ILadyRobot::ILadyRobot(char* ip, int port, int gridHeight, int gridWidth){
	this->gridHeight = gridHeight;
	this->gridWidth = gridWidth;
	playerClient = new PlayerClient(ip, port);
	laser = new LaserProxy(playerClient);
	position2dProxy = new Position2dProxy(playerClient);
	position2dProxy->SetMotorEnable(true);
	Position* startPosInGrid = ConfigurationManager::getInstance()->getStartLocationInGrid();
//	position2dProxy->SetOdometry(startPos->getX()*0.025, startPos->getY()*0.025, dtor(startPos->getYaw()));
//	position2dProxy->SetOdometry((-gridHeight + startPos->getY()*0.025) , (gridWidth- startPos->getX()*0.025), dtor(startPos->getYaw()));
	Position* startPosInCartezian =MatrixToCartezianCor(startPosInGrid);
	position2dProxy->SetOdometry(startPosInCartezian->getX() / 10, startPosInCartezian->getY() / 10, dtor(startPosInCartezian->getYaw()));

	cleanCache();
}

Position2dProxy* ILadyRobot::getPosition2DProxy(){
	read();
	return position2dProxy;
}

Position* ILadyRobot::CartezianCorToMatrix(Position* cartezianCor){
	Position* matrixPosition = new Position( (gridHeight-1) - cartezianCor->getY(), cartezianCor->getX() +( gridWidth - 1) , cartezianCor->getYaw());
	return matrixPosition;
}

Position* ILadyRobot::MatrixToCartezianCor(Position* matrixPosition){
	Position* cartizeCorPosition = new Position( -(gridWidth - 1) + matrixPosition->getY(), (gridHeight - 1) -  matrixPosition->getX(), matrixPosition->getYaw());
	return cartizeCorPosition;
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
	Position* positionProxyCM = new Position((getXPosition())*10 , (getYPosition()) * 10 ,  getYaw() );
	return(CartezianCorToMatrix(positionProxyCM));
//	(-gridWidth + startPos->getY())*0.025 , (gridHeight- startPos->getX())*0.025, dtor(startPos->getYaw())
//	Position* positionProxyCM = new Position(getXPosition() * 10, getYPosition() * 10, getYaw() * 10);

//	return delegateToMatrix(positionProxyCM);
//	return positionProxyCM;
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
