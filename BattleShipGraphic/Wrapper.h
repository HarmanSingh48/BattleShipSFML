#pragma once

#include "Menu.h"
#include "BattleShip.h"


class Wrapper
{
private:
	//Window
	sf::RenderWindow* gameWindow;
	sf::VideoMode vMode;
	
	//User Input
	sf::Event e;

	//GUI
	Menu* menu;
	Screen currScreen;
	int gridSize;

	//Game
	Player currPlayer;
	BattleShip game;//Make game pointer to be able to instantiate new games without restarting?

	//Game Resources
	sf::Sprite gameBackgroundSprite;
	sf::Texture gameBackgroundTex;

	//Visual Stuff
	sf::RectangleShape P1Board;
	sf::Vector2f P1BoardPosition;

	sf::RectangleShape P2Board;
	sf::Vector2f P2BoardPosition;

	sf::Font infoFont;
	sf::Text P1ScoreText;
	sf::Text P2ScoreText;

	//X grid lines are * 2 because they need to be repeated for the second board
	sf::RectangleShape boardGridLinesX[NUMBER_OF_RENDERED_GRID_LINES];
	sf::RectangleShape boardGridLinesY[NUMBER_OF_RENDERED_GRID_LINES * 2];

	//Player Choice for setup
	//int setupSelectionIndex;
	//sf::RectangleShape setupSelectBackground;
	//sf::Text setupSelectOptions[2];

	//Logic
	GameState currState;
	int maxShipToRender;
	Ship* selectedShip;



	//Private Methods
	void initVars();
	void initWindow();

	void initTextures();
	void initGridLines();
	void DrawGridLines();
	void initText();
	void initGameBoardVisuals();
	void DrawGame();
		//Ship Movement
	void MoveUp();
	void MoveDown();
	void MoveLeft();
	void MoveRight();

	void HandleSetupInput(sf::Event& keyEvent);


public:
	//Constructor/ Destructor
	Wrapper();
	~Wrapper();

	//Functions
	void pollEvents();
	void update();
	void render();

	//Getters/ Setters
	bool getWindowStatus();


};

