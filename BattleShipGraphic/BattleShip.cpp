#include "BattleShip.h"

void BattleShip::initGameBoardArray(char game_board[][MAX_COLS])
{
	int row_index = 0, col_index = 0;
	for (; row_index < MAX_ROWS; row_index++) {
		for (col_index = 0; col_index < MAX_COLS; col_index++) {
			game_board[row_index][col_index] = '~';
		}
	}
}



void BattleShip::initShips(Ship theShipArr[])
{
	//Initialize each ship type for both players
	theShipArr[CARR_INDEX] = Ship(CARRIER, Cardinal::North, CARRIER_LEN);
	theShipArr[BATT_INDEX] = Ship(BATTLE, Cardinal::North, BATTLE_LEN);
	theShipArr[CRUS_INDEX] = Ship(CRUISER, Cardinal::North, CRUISER_LEN);
	theShipArr[SUB_INDEX] = Ship(SUB, Cardinal::North, SUB_LEN);
	theShipArr[DESTR_INDEX] = Ship(DESTR, Cardinal::North, DESTR_LEN);
}



BattleShip::BattleShip()
{
	//Initializing Game Boards
	this->initGameBoardArray(this->P1_Board);
	this->initGameBoardArray(this->P2_Board);
	//Initializing Ships
	this->initShips(this->P1_Ships);
	this->initShips(this->P2_Ships);

	currShip = nullptr;

}

BattleShip::~BattleShip()
{
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
	if (shipToPlace.getOrientation() == Cardinal::North || shipToPlace.getOrientation() == Cardinal::South) {
		shipToPlace.getPos().
	}
	else {

	}
	return false;
}
