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

Ship const* Tile::getCurrPiece()
{
	return this->currentPiece;
}

sf::Vector2i& Tile::getUpperBound()
{
	return this->pxBoundUpper;
}

sf::Vector2i& Tile::getLowerBound()
{
	return this->pxBoundUpper;
}



Board::Board(const int GridSize)
{
	for (int i = 0; i < MAX_ROWS; i++) {//Arr[i][j]
		for (int j = 0; j < MAX_COLS; j++) {
			gameBoard[i][j].setUpperBound(sf::Vector2i((j + 1) * GRID_SIZE, (i + 1) * GRID_SIZE));
			gameBoard[i][j].setLowerBound(sf::Vector2i((j * GRID_SIZE) + 1, (i * GRID_SIZE) + 1));
		}
	}

}

Board::~Board()
{
}



bool Board::placeShipOnBoard(Ship& shipToPlace, sf::Vector2i shipHeadPosition)
{
	//if the specified tile is already occupies
	if (gameBoard[shipHeadPosition.y][shipHeadPosition.x].getCurrPiece() != nullptr) return false;
	
	if (shipToPlace.getOrientation() == Orientation::Vertical) {
		for (int i = 0; i < shipToPlace.getHealth(); i++) {
			gameBoard[shipHeadPosition.y + i][shipHeadPosition.x].setCurrPiece(shipToPlace);
		}
	}
	else {
		for (int i = 0; i < shipToPlace.getHealth(); i++) {
			gameBoard[shipHeadPosition.y][shipHeadPosition.x + i].setCurrPiece(shipToPlace);
		}
	}


	return false;
}
