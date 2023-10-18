#include "Ship.h"

Ship::Ship()
{
	this->type = "default";
	orientation = Orientation::Vertical;
	this->health = 0;
}

Ship::~Ship()
{
}

string Ship::getType()
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

void Ship::setOrientation(const Orientation theOrientation) {
	this->orientation = theOrientation;
}

int Ship::getHealth()
{
	return health;
}

sf::Sprite& Ship::getSprite()
{
	return this->shipSprite;
}

Carrier::Carrier()
{
	this->health = 5;
	this->type = "Carrier";
	if (!this->shipTexture.loadFromFile("resources/ShipCarrierHull.png")) {
		std::cout << "Couldn't Load Carrier Texture" << std::endl;
	}

	this->shipSprite.setTexture(this->shipTexture);
	this->shipSprite.setScale(sf::Vector2f(1.4, 2.2));
}

Carrier::~Carrier()
{
}

Battleship::Battleship()
{
	this->health = 4;
	this->type = "Battleship";

	if (!this->shipTexture.loadFromFile("resources/ShipBattleshipHull.png")) {
		std::cout << "Couldn't Load Battleship Texture" << std::endl;
	}

	this->shipSprite.setTexture(this->shipTexture);
}

Battleship::~Battleship()
{

}

Submarine::Submarine()
{
	this->health = 3;
	this->type = "Submarine";

	if (!this->shipTexture.loadFromFile("resources/ShipSubMarineHull.png")) {
		std::cout << "Couldn't Load Submarine Texture" << std::endl;
	}
	this->shipSprite.setTexture(this->shipTexture);
}

Submarine::~Submarine()
{
}

Cruiser::Cruiser()
{
	this->health = 3;
	this->type = "Cruiser";

	if (!this->shipTexture.loadFromFile("resources/ShipCruiserHull.png")) {
		std::cout << "Couldn't Load Cruiser Texture" << std::endl;
	}

	this->shipSprite.setTexture(this->shipTexture);
}

Cruiser::~Cruiser()
{

}

Destroyer::Destroyer()
{
	this->health = 2;
	this->type = "Destroyer";

	if (!this->shipTexture.loadFromFile("resources/ShipDestroyerHull.png")) {
		std::cout << "Couldn't Load Destroyer Texture" << std::endl;
	}

	this->shipSprite.setTexture(this->shipTexture);
}

Destroyer::~Destroyer()
{
}
