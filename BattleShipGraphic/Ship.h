#pragma once
#include "Constants.h"

using std::string;

class Ship {
protected:
	string type;
	sf::Vector2i bowPos;
	Orientation orientation;
	int health;
	sf::Texture shipTexture;
	sf::Sprite shipSprite;

public:
	Ship();
	~Ship();

	//Getters/Setters
	string getType();

	sf::Vector2i getPos();

	void setPos(const sf::Vector2i thePos);

	Orientation getOrientation();

	void setOrientation(const Orientation theOrientation);

	int getHealth();

	sf::Sprite& getSprite();

};

class Carrier : public Ship {
public:
	Carrier();
	~Carrier();
};

class Battleship : public Ship {
public:
	Battleship();
	~Battleship();
};

class Submarine : public Ship {
public:
	Submarine();
	~Submarine();
};

class Cruiser : public Ship {
public:
	Cruiser();
	~Cruiser();
};

class Destroyer : public Ship {
public:
	Destroyer();
	~Destroyer();
};