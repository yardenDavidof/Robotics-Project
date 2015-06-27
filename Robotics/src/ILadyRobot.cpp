///*
// * ILadyRobot.cpp
// *
// *  Created on: Jun 9, 2015
// *      Author: colman
// */
//
//#include "ILadyRobot.h"
//
//ILadyRobot::ILadyRobot(char* ip, int port) {
//	playerClient = new PlayerClient(ip, port);
//	laser = new LaserProxy(playerClient);
//	position2dProxy = new Position2dProxy(playerClient);
//	position2dProxy->SetMotorEnable(true);
//	cleanCache();
//
//}
//void ILadyRobot::read() {
//	playerClient->Read();
//}
//
//double ILadyRobot::getXPosition() {
//
//	return position2dProxy->GetXPos();
//}
//
//double ILadyRobot::getYPosition() {
//	return position2dProxy->GetYPos();
//}
//
//double ILadyRobot::getYaw() {
//	return position2dProxy->GetYaw();
//}
//
//Position* ILadyRobot::getPosition() {
//	return new Position(this->getXPosition(), this->getYPosition(), this->getYaw());
//}
//
//void ILadyRobot::setSpeed(double speed, double yaw) {
//	position2dProxy->SetSpeed(speed, yaw);
//}
//
//void ILadyRobot::cleanCache() {
//	for(int i = 0; i < 15; i++){
//		playerClient->Read();
//	}
//}
//
//
//double ILadyRobot::getRange(int index) {
//	return laser->GetRange(index);
//}
//
//ILadyRobot::~ILadyRobot() {
//
//}
//
