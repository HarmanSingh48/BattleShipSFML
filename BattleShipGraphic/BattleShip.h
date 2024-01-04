#pragma once
#include "PlayerStats.h"

class BattleShip
{
		//Player 1
	Board* P1Board;
	PlayerStats P1_Stats;
	Ship** P1_Ships;

		//Player 2
	Board* P2Board;
	PlayerStats P2_Stats;
	Ship** P2_Ships;

	Ship* currShip;




	void initShips();





public:
	BattleShip();
	~BattleShip();


	void HandleKeyEvent(sf::Event& keyPressedEvent, GameState currState);
	void UpdateScoreBoard(sf::Text* P1ScoreBoard, sf::Text* P2ScoreBoard);
	Ship* getShipAtIndex(const Player player, const int index);
	bool VerifyAndPlaceShipOnBoard(const Player player, Ship& shipToPlay);
	void MoveDown(Ship* shipToMove);
	void MoveUp(Ship* shipToMove);
	void MoveLeft(Ship* shipToMove);
	void MoveRight(Ship* shipToMove);
};

