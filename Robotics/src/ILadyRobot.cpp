#include "ILadyRobot.h"

/**
 * The construction for ladyRobot. initial the relevant parameters
 */
ILadyRobot::ILadyRobot(char* ip, int port, int gridHeight, int gridWidth){
	this->gridHeight = gridHeight;
	this->gridWidth = gridWidth;
	playerClient = new PlayerClient(ip, port);
	laser = new LaserProxy(playerClient);
	position2dProxy = new Position2dProxy(playerClient);
	position2dProxy->SetMotorEnable(true);
	Position* startPosInGrid = ConfigurationManager::getInstance()->getStartLocationInGrid();
	Position* startPosInCartezian =MatrixToCartezianCor(startPosInGrid);
	position2dProxy->SetOdometry(startPosInCartezian->getX() / 10, startPosInCartezian->getY() / 10, dtor(startPosInCartezian->getYaw()));

	cleanCache();
}

/**
 * The function do read and return the position 2d proxy
 */
Position2dProxy* ILadyRobot::getPosition2DProxy(){
	read();
	return position2dProxy;
}

/**
 * The function cartezian current place in map to matrix
 */
Position* ILadyRobot::CartezianCorToMatrix(Position* cartezianCor){
	Position* matrixPosition = new Position( (gridHeight-1) - cartezianCor->getY(), cartezianCor->getX() +( gridWidth - 1) , cartezianCor->getYaw());
	return matrixPosition;
}

/**
 *  The function cartezian current place in matrix to map
 */
Position* ILadyRobot::MatrixToCartezianCor(Position* matrixPosition){
	Position* cartizeCorPosition = new Position( -(gridWidth - 1) + matrixPosition->getY(), (gridHeight - 1) -  matrixPosition->getX(), matrixPosition->getYaw());
	return cartizeCorPosition;
}

/**
 * The function read from playerClient
 */
void ILadyRobot::read(){
	playerClient->Read();
}

/**
 * The function return yaw of proxy
 */
double ILadyRobot::getYaw(){
	read();
	return position2dProxy->GetYaw();
}

/**
 * The function return X of proxy
 */
double ILadyRobot::getXPosition(){
	read();
	return position2dProxy->GetXPos();
}

/**
 * The function return Y of proxy
 */
double ILadyRobot::getYPosition(){
	read();
	return position2dProxy->GetYPos();
}

/**
 * The function return position of proxy after claculate position to matrix
 */
Position* ILadyRobot::getPosition(){
	read();
	Position* positionProxyCM = new Position((getXPosition())*10 , (getYPosition()) * 10 ,  getYaw() );
	return(CartezianCorToMatrix(positionProxyCM));
}

/**
 * The function set the speed of the robot
 */
void ILadyRobot::setSpeed(double speed, double yaw){
	position2dProxy->SetSpeed(speed,yaw);
}

/**
 * The function clean the cache-> reset the laser
 */
void ILadyRobot::cleanCache() {
	for(int i = 0; i < 30; i++){
		playerClient->Read();
		read();
	}
}

/**
 * The function return the laser in wanted index
 */
double ILadyRobot::getRange(int index) {
	return (*laser)[index];

}

ILadyRobot::~ILadyRobot(){}
