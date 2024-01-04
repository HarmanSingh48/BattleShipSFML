#include "BattleShip.h"


void BattleShip::initShips()
{
	P1_Ships = new Ship*[5];
	//Initialize each ship type for both players
	cout << "Creating Carrier" << std::endl;
	P1_Ships[CARR_INDEX] = new Carrier();
	P1_Ships[BATT_INDEX] = new Battleship();
	P1_Ships[CRUS_INDEX] = new Cruiser();
	P1_Ships[SUB_INDEX] = new Submarine();
	P1_Ships[DESTR_INDEX] = new Destroyer();

	P2_Ships = new Ship * [5];
	//Initialize each ship type for both players
	cout << "Creating Carrier" << std::endl;
	P2_Ships[CARR_INDEX] = new Carrier();
	P2_Ships[BATT_INDEX] = new Battleship();
	P2_Ships[CRUS_INDEX] = new Cruiser();
	P2_Ships[SUB_INDEX] = new Submarine();
	P2_Ships[DESTR_INDEX] = new Destroyer();
}



BattleShip::BattleShip()
{
	//Initializing Ships
	this->initShips();
	//this->initShips(this->P2_Ships);

	currShip = nullptr;
	this->P1Board = new Board((int)GRID_SIZE);
	this->P2Board = new Board((int)GRID_SIZE);

}

BattleShip::~BattleShip()
{
	delete this->P1Board;
	delete this->P2Board;
	for (int i = 0; i < NUMBER_OF_SHIPS_PER_PLAYER; i++) {
		cout << "deleteing" << i << std::endl;
		delete this->P1_Ships[i];
		//delete this->P2_Ships[i];
	}
	delete[] this->P1_Ships;
	delete[] this->P2_Ships;
}


void BattleShip::HandleKeyEvent(sf::Event& keyPressedEvent, GameState currState)
{
	if (currState == GameState::Setup) {
		
	}
	else if (currState == GameState::Playing) {

	}
	else {

	}
}

void BattleShip::UpdateScoreBoard(sf::Text* P1ScoreBoard, sf::Text* P2ScoreBoard)
{
	//sf::String P1_Scores("Player 1:\nHits: " + P1_Stats.getHits());
	//sf::String P2_Scores("Player 2:\nHits: " + P2_Stats.getHits());
	//P1_Scores.operator+=("\nMisses: " + P1_Stats.getMisses());
	//P2_Scores.operator+=("\nMisses: " + P2_Stats.getMisses());
	
	//P1_Scores.operator+=("\nTotal Shots: " + P1_Stats.getTotal());
	//P2_Scores.operator+=("\nTotal Shots: " + P2_Stats.getTotal());


	//P1ScoreBoard->setString(P1_Scores);
	//P2ScoreBoard->setString(P2_Scores);
	P1ScoreBoard->setString("Windows");
}

Ship* BattleShip::getShipAtIndex(const Player player, const int index)
{
	if (index >= 0 && index < NUMBER_OF_SHIPS_PER_PLAYER) {
		if (player == Player::Player_1) {
			return P1_Ships[index];
		}
		return P2_Ships[index];
	}
	return nullptr;
}

bool BattleShip::VerifyAndPlaceShipOnBoard(const Player player, Ship& shipToPlace)
{

	return false;
}

void BattleShip::MoveDown(Ship* shipToMove)
{
	shipToMove->setPos(sf::Vector2i(shipToMove->getPos().x - GRID_SIZE, shipToMove->getPos().y));
}

void BattleShip::MoveUp(Ship* shipToMove)
{
	shipToMove->setPos(sf::Vector2i(shipToMove->getPos().x + GRID_SIZE, shipToMove->getPos().y));
}

void BattleShip::MoveLeft(Ship* shipToMove)
{
	shipToMove->setPos(sf::Vector2i(shipToMove->getPos().x, shipToMove->getPos().y - GRID_SIZE));
}

void BattleShip::MoveRight(Ship* shipToMove)
{
	shipToMove->setPos(sf::Vector2i(shipToMove->getPos().x, shipToMove->getPos().y + GRID_SIZE));
}
