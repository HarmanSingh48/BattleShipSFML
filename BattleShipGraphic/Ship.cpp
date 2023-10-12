#include "Ship.h"

Ship::Ship(char theType, Orientation theOrientation, int theHealthPool)
{
	this->type = theType;
	orientation = theOrientation;
	this->health = theHealthPool;
}

Ship::~Ship()
{
}

char Ship::getType()
{
	return this->type;
}

sf::Vector2i Ship::getPos()
{
	return this->bowPos;
}

void Ship::setPos(const sf::Vector2i thePos)
{
	this->bowPos = thePos;
}

Orientation Ship::getOrientation()
{
	return this->orientation;
}

void Ship::setOrientation(const Orientation theOrientation)
{
	this->orientation = theOrientation;
}

int Ship::getHealth()
{
	return health;
}

