#include "BattleShip.h"


void BattleShip::initShips(Ship theShipArr[])
{
	//Initialize each ship type for both players
	theShipArr[CARR_INDEX] = Carrier();
	theShipArr[BATT_INDEX] = Battleship();
	theShipArr[CRUS_INDEX] = Cruiser();
	theShipArr[SUB_INDEX] = Submarine();
	theShipArr[DESTR_INDEX] = Destroyer();
}



BattleShip::BattleShip()
{
	//Initializing Ships
	this->initShips(this->P1_Ships);
	this->initShips(this->P2_Ships);

	currShip = nullptr;
	this->P1Board = new Board((int)GRID_SIZE);
	this->P2Board = new Board((int)GRID_SIZE);

}

BattleShip::~BattleShip()
{
	delete this->P1Board;
	delete this->P2Board;
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
	if (index >= 0 || index < NUMBER_OF_SHIPS_PER_PLAYER) {
		if (player == Player::Player_1) {
			return &P1_Ships[index];
		}
		return &P2_Ships[index];
	}
	return nullptr;
}

bool BattleShip::VerifyAndPlaceShipOnBoard(const Player player, Ship& shipToPlace)
{
	return false;
}
