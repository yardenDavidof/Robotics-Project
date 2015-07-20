#include "Position.h"

/**
 * Constructor of Position
 */
Position::Position(double x, double y, double yaw):location(new Location(x,y)),yaw(yaw){}

/**
 * The function return the x
 */
int Position::getX()
{
	return location->x;
}

/**
 * The function return the y
 */
int Position::getY()
{
	return location->y;
}

/**
 * The function return the yaw
 */
int Position::getYaw()
{
	return yaw;
}

/**
 * The function return the location part
 */
Location* Position::getLocation(){
	return location;
}

/**
 * The function set x
 */
void Position::setX(double setX)
{
	location->x = setX;
}

/**
 * The function set y
 */
void Position::setY(double setY)
{
	location->y = setY;
}

/**
 * The function set yaw
 */
void Position::setYaw(double setYaw)
{
	yaw = setYaw;
}

/**
 * The function create new position from old and new position
 */
Position* Position::delta(Position* old){
	return new Position(abs(old->getX() - getX()),
						abs(old->getY() - getY()),
						old->getYaw() - getYaw());
}

Position::~Position() {}
