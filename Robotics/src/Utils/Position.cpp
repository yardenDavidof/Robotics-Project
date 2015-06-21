/*
 * Position.cpp
 *
 *  Created on: May 30, 2015
 *      Author: colman
 */

#include "Position.h"

Position::Position(double x, double y, double yaw) {
	this->x = x;
	this->y = y;
	this->yaw = yaw;

}

Position::Position(double x, double y) {
	this->x = x;
	this->y = y;
	this->yaw = 0;

}

void Position::print() const{
	cout << "(" << this->x << "," << this->y << ")";
}

Position::Position() {
	this->x = 0;
	this->y = 0;
	this->yaw = 0;
}

Position::~Position() {
}

