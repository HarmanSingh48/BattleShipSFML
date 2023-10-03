#include "Ship.h"

Ship::Ship(char theType, Cardinal theOrientation, int theHealthPool)
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

Cardinal Ship::getOrientation()
{
	return this->orientation;
}

void Ship::setOrientation(const Cardinal theOrientation)
{
	this->orientation = theOrientation;
}

int Ship::getHealth()
{
	return health;
}

