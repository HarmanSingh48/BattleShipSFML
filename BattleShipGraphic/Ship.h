#pragma once
#include "Constants.h"

class Ship {
	char type;
	sf::Vector2i bowPos;
	Cardinal orientation;
	int health;
public:
	Ship(char theType = '~', Cardinal theOrientation = Cardinal::North, int theHealthPool = 0);
	~Ship();

	//Getters/Setters
	char getType();

	sf::Vector2i getPos();

	void setPos(const sf::Vector2i thePos);

	Cardinal getOrientation();

	void setOrientation(const Cardinal theOrientation);

	int getHealth();

};

