#include "Board.h"

Tile::Tile()
{
	this->currentPiece = nullptr;
	this->pxBoundUpper.x = 0;
	this->pxBoundLower.y = 0;
}

Tile::Tile(Ship &storedPiece, sf::Vector2i UpperBoundOfPixels, sf::Vector2i LowerBoundOfPixels)
{
	this->currentPiece = &storedPiece;
	this->pxBoundUpper = UpperBoundOfPixels;
	this->pxBoundLower = LowerBoundOfPixels;
}

Tile::Tile(const Tile& copy)
{
	this->currentPiece = copy.currentPiece;
	this->pxBoundUpper = copy.pxBoundUpper;
	this->pxBoundLower = copy.pxBoundLower;
}

Tile::~Tile()
{
}

void Tile::setCurrPiece(Ship& newPiece)
{
	this->currentPiece = &newPiece;
}

void Tile::setUpperBound(const sf::Vector2i& UpperBoundOfPixels)
{
	this->pxBoundUpper.x = UpperBoundOfPixels.x;
	this->pxBoundUpper.y = UpperBoundOfPixels.y;
}

void Tile::setLowerBound(const sf::Vector2i& LowerBoundOfPixels)
{
	this->pxBoundUpper.x = LowerBoundOfPixels.x;
	this->pxBoundUpper.y = LowerBoundOfPixels.y;
}

Board::Board(const int GridSize)
{
	for (int i = 0; i < BOARD_WIDTH; i++) {//Arr[i][j]
		for (int j = 0; j < BOARD_HEIGHT; j++) {
			gameBoard[i][j].setUpperBound(sf::Vector2i((j + 1) * GRID_SIZE, (i + 1) * GRID_SIZE));
			gameBoard[i][j].setLowerBound(sf::Vector2i((j * GRID_SIZE) + 1, (i * GRID_SIZE) + 1));
		}
	}
}

Board::~Board()
{
}
