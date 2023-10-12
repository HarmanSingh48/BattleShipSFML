#pragma once
#include "Constants.h"

class Ship {
	char type;
	sf::Vector2i bowPos;
	Orientation orientation;
	int health;
public:
	Ship(char theType = '~', Orientation theOrientation = Orientation::Vertical, int theHealthPool = 0);
	~Ship();

	//Getters/Setters
	char getType();

	sf::Vector2i getPos();

	void setPos(const sf::Vector2i thePos);

	Orientation getOrientation();

	void setOrientation(const Orientation theOrientation);

	int getHealth();

};

