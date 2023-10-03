#pragma once
#include "Constants.h"

class Menu
{
public:
	/*
	* Initialize the resources and fields for the main menu screen
	*/
	void InitMainMenu(float width, float height);

	/*
	* Initialize the resources and fields for the instruction screen
	*/
	void InitInstructions(float width, float height);

	/*
	* Constructor for the Menu class that takes the desired window size as parameters
	*/
	Menu(float width, float height);
	/*
	* Default Destructor
	*/
	~Menu();

	/*
	* Draw the main menu of the game in its current state.
	*/
	void DrawMainMenu(sf::RenderWindow& window);

	/*
	* Draw the Instructions Screen
	*/
	void DrawInstructions(sf::RenderWindow& window);

	/*
	* Change the selected option in the main menu to the previous option.
	*/
	void MoveUp();
	/*
	* Change the selected option in the main menu to the next option.
	*/
	void MoveDown();
	/*
	* Returns the current selected menu option.
	*/
	int GetSelectedOption() { return this->selectedItemIndex; };



private:
	//Menu Functionality
	int selectedItemIndex;

	//Styling
	sf::Font menuFont;
	sf::Sprite menuBackground;
	sf::Texture menuTex;

	//Texts
	sf::Text mainMenuOptions[MAX_NUMBER_OF_MENU_ITEMS];
	sf::Text instructions[6];
	sf::Text titleText;
	
};

