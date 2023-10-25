#include "Menu.h"

void Menu::InitMainMenu(float width, float height) {
	if (!menuFont.loadFromFile("resources/FortunerHeavy-jEMyR.otf")) {
		//handle error
	}
	this->selectedItemIndex = 0;

	titleText.setFont(menuFont);
	titleText.setFillColor(sf::Color::White);
	titleText.setCharacterSize(50);
	titleText.setString("Battleship");
	titleText.setPosition(width / 2 - (width / 32), height / (MAX_NUMBER_OF_MENU_ITEMS + 3));//Why is this +3? IDK, it just looks decent visually

	mainMenuOptions[0].setFont(menuFont);
	mainMenuOptions[0].setFillColor(sf::Color::Blue);
	mainMenuOptions[0].setString("Play");
	mainMenuOptions[0].setPosition(sf::Vector2f(width / 2 - (width / 32), (height  - titleText.getPosition().y) / (MAX_NUMBER_OF_MENU_ITEMS) * 1));

	//std::cout << mainMenuOptions[0].getString().toAnsiString() << " Button Height: " << mainMenuOptions[0].getPosition().y << std::endl;

	mainMenuOptions[1].setFont(menuFont);
	mainMenuOptions[1].setFillColor(sf::Color::White);
	mainMenuOptions[1].setString("Instructions");
	mainMenuOptions[1].setPosition(sf::Vector2f(width / 2 - (width / 32), (height - titleText.getPosition().y) / (MAX_NUMBER_OF_MENU_ITEMS) * 2));


	mainMenuOptions[2].setFont(menuFont);
	mainMenuOptions[2].setFillColor(sf::Color::White);
	mainMenuOptions[2].setString("Exit");
	mainMenuOptions[2].setPosition(sf::Vector2f((width / 2) - (width / 32), (height - titleText.getPosition().y) / (MAX_NUMBER_OF_MENU_ITEMS) * 3));
	//mainMenuOptions[2].setPosition(sf::Vector2f((width / 2) - (width / 32), (height - titleText.getPosition().y) / (MAX_NUMBER_OF_MENU_ITEMS + 1) * 3));

	//TODO: Add about section
}

void Menu::InitInstructions(float width, float height) {//Idea: Use a pre rendered image with text for instruction page
	if (!menuFont.loadFromFile("resources/FortunerHeavy-jEMyR.otf")) {
		//handle error
	}
	instructions[0].setString("1. There are two players: You(Player 1) and the computer(Player 2).");
	instructions[1].setString("2. You will decide whether you want to place the ships manually or \nhave them be placed automatically.");
	instructions[2].setString("3. When it is your turn, you will enter where you want to hit. It will be indicated whether you hit something or you missed.");
	instructions[3].setString("4. You and the other player will alternate guessing the places to hit. You cannot guess the same coordinates twice.");
	instructions[4].setString("5. The game will continue until one player has sunk all the other player's ships.");
	instructions[5].setString("press escape to go back");

	for (int i = 0; i < 6; i++) {
		instructions[i].setFillColor(sf::Color::White);
		instructions[i].setFont(menuFont);
		instructions[i].setPosition(sf::Vector2f(width / 32, height / (6 + 1) * (i + 1)));
		instructions[i].setCharacterSize(30);
		instructions[i].setLetterSpacing((float)0.85);
	}
	instructions[5].setFillColor(sf::Color::Blue);
}

Menu::Menu(float width, float height)
{
	this->InitMainMenu(width, height);
	this->InitInstructions(width, height);
	if (!this->menuTex.loadFromFile("resources/BB61_USS_Iowa_BB61_broadside_USN.jpg", sf::IntRect(220,800,width,height))) {
		//error handling
	}
	this->menuBackground.setTexture(this->menuTex);
	this->menuBackground.setColor(sf::Color(255, 255, 255, 150));
}

Menu::~Menu()
{
}

void Menu::DrawMainMenu(sf::RenderWindow& window)
{
	window.draw(this->menuBackground);
	window.draw(this->titleText);
	for (int i = 0; i < MAX_NUMBER_OF_MENU_ITEMS; i++) {
		window.draw(mainMenuOptions[i]);
	}
}

void Menu::DrawInstructions(sf::RenderWindow& window) 
{
	window.draw(this->menuBackground);
	for (int i = 0; i < 6; i++) {
		window.draw(instructions[i]);
	}
}

void Menu::MoveUp()
{
	//If the current option is NOT the first option (index 0), move the selection upwards by one option
	if (selectedItemIndex - 1 >= 0) {
		//Visually deselect the current option by changing its color to white and decrement the index
		mainMenuOptions[selectedItemIndex--].setFillColor(sf::Color::White);
		//Select the new option by changing its drawn color to blue
		mainMenuOptions[selectedItemIndex].setFillColor(sf::Color::Blue);

		std::cout << selectedItemIndex << std::endl;
	}
	//If the current option is the first option, wrap around the menu and select the last option
	else {
		//Visually deselect the current option by changing its color to white
		mainMenuOptions[selectedItemIndex].setFillColor(sf::Color::White);
		//Select the last menu option
		selectedItemIndex = MAX_NUMBER_OF_MENU_ITEMS - 1;
		//Select the new option by changing its drawn color to blue
		mainMenuOptions[selectedItemIndex].setFillColor(sf::Color::Blue);

		std::cout << selectedItemIndex << std::endl;
	}
}

void Menu::MoveDown()
{
	//If the current option is NOT the last option (index 2), move the selection down by one option
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_MENU_ITEMS) {
		//Visually deselect the current option by changing its color to white and increment the index
		mainMenuOptions[selectedItemIndex++].setFillColor(sf::Color::White);
		//Select the new option by changing its drawn color to blue
		mainMenuOptions[selectedItemIndex].setFillColor(sf::Color::Blue);

		std::cout << selectedItemIndex << std::endl;
	}
	//If the current option is the first option, wrap around the menu and select the last option
	else {
		//Visually deselect the current option by changing its color to white
		mainMenuOptions[selectedItemIndex].setFillColor(sf::Color::White);
		//Select the first menu option
		selectedItemIndex = 0;
		//Select the new option by changing its drawn color to blue
		mainMenuOptions[selectedItemIndex].setFillColor(sf::Color::Blue);

		std::cout << selectedItemIndex << std::endl;

	}
}
