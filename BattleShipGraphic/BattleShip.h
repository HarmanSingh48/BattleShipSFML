#pragma once
#include "PlayerStats.h"

class BattleShip
{
		//Player 1
	Board* P1Board;
	PlayerStats P1_Stats;
	Ship* P1_Ships;

		//Player 2
	Board* P2Board;
	PlayerStats P2_Stats;
	Ship P2_Ships[NUMBER_OF_SHIPS_PER_PLAYER];

	Ship* currShip;




	void initShips(Ship* theShipArr);





public:
	BattleShip();
	~BattleShip();


	void HandleKeyEvent(sf::Event& keyPressedEvent, GameState currState);
	void UpdateScoreBoard(sf::Text* P1ScoreBoard, sf::Text* P2ScoreBoard);
	Ship* getShipAtIndex(const Player player, const int index);
	bool VerifyAndPlaceShipOnBoard(const Player player, Ship& shipToPlay);
};

