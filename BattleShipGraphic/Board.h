#pragma once
#include "Ship.h"

/*
* This class represents the game board and holds its current state for both the player and the AI.
* It is hard coded to be a 10x10 grid and the origin (0,0) represents the top-left corner of the game board visually.
* Each grid square (Tile Class) holds what game piece is currently stored as a pointer (empty square will have a null pointer to the piece.
*/
class Board {
private:
	Tile gameBoard[MAX_ROWS][MAX_COLS];

public:
	Board(const int GridSize);
	~Board();

};

class Tile {
private:
	Ship const * currentPiece;
	sf::Vector2i pxBoundUpper;
	sf::Vector2i pxBoundLower;

public:
	Tile();
	Tile(Ship &storedPiece, sf::Vector2i UpperBoundOfPixels, sf::Vector2i LowerBoundOfPixels);
	Tile(const Tile& copy);
	~Tile();

	void setCurrPiece(Ship& newPiece);
	void setUpperBound(const sf::Vector2i& UpperBoundOfPixels);
	void setLowerBound(const sf::Vector2i& UpperBoundOfPixels);
};
