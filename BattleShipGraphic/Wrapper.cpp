#include "Wrapper.h"


/*
* Initializes the fields to their default states at the beginning of execution
*/
void Wrapper::initVars()
{
	this->gameWindow = nullptr;
	this->vMode.width = WINDOW_WIDTH;
	this->vMode.height = WINDOW_HEIGHT;
	this->menu = nullptr;
	this->currScreen = Screen::Main;
	//Grid lines + 1 because a board with x-number of lines makes x + 1 cells
	this->gridSize = BOARD_WIDTH / (NUMBER_OF_RENDERED_GRID_LINES + 1);
	this->maxShipToRender = 0;
	this->selectedShip = this->game.getShipAtIndex(Player::Player_1, maxShipToRender);
}

/*
* Initializes the game window to its default state
*/
void Wrapper::initWindow()
{
	this->gameWindow = new sf::RenderWindow(this->vMode, "Battleship", sf::Style::Titlebar | sf::Style::Close);
	this->gameWindow->setFramerateLimit(60);
	this->menu = new Menu(this->gameWindow->getSize().x, this->gameWindow->getSize().y);
}

void Wrapper::initTextures()
{
	//Load Textures and Sprites
	//Background
	if (!this->gameBackgroundTex.loadFromFile("resources/vecteezy_blue-and-clear-water-texture-swimming-pool-rippled-water-background_.jpg",
		//With these dimensions, the background sprite only covers the area of the game boards and leaves a border open for the info panels
		sf::IntRect(0, 0, (2 * BOARD_WIDTH) + BOARD_OUTLINE_THICKNESS, BOARD_HEIGHT + BOARD_OUTLINE_THICKNESS)))
	{
		std::cout << "Couldn't Load Background Texture" << std::endl;
	}
	this->gameBackgroundSprite.setTexture(this->gameBackgroundTex);

	//Ships
	//Textures
	if (!this->shipTextures[CARR_INDEX].loadFromFile("resources/ShipCarrierHull.png")) {
		std::cout << "Couldn't Load Carrier Texture" << std::endl;
	}
	if (!this->shipTextures[BATT_INDEX].loadFromFile("resources/ShipBattleshipHull.png")) {
		std::cout << "Couldn't Load Battleship Texture" << std::endl;
	}
	if (!this->shipTextures[CRUS_INDEX].loadFromFile("resources/ShipCruiserHull.png")) {
		std::cout << "Couldn't Load Cruiser Texture" << std::endl;
	}
	if (!this->shipTextures[DESTR_INDEX].loadFromFile("resources/ShipDestroyerHull.png")) {
		std::cout << "Couldn't Load Destroyer Texture" << std::endl;
	}
	if (!this->shipTextures[SUB_INDEX].loadFromFile("resources/ShipSubMarineHull.png")) {
		std::cout << "Couldn't Load Submarine Texture" << std::endl;
	}


	//Sprites
	this->shipSprites[CARR_INDEX].setTexture(this->shipTextures[CARR_INDEX]);
	this->shipSprites[CARR_INDEX].setScale(sf::Vector2f(1.4,2.2));
	this->shipSprites[BATT_INDEX].setTexture(this->shipTextures[BATT_INDEX]);
	this->shipSprites[CRUS_INDEX].setTexture(this->shipTextures[CRUS_INDEX]);
	this->shipSprites[DESTR_INDEX].setTexture(this->shipTextures[DESTR_INDEX]);
	this->shipSprites[SUB_INDEX].setTexture(this->shipTextures[SUB_INDEX]);
	
}

void Wrapper::initGridLines()
{
	sf::Vector2f gridLineLengthX(BOARD_WIDTH * 2, 0);
	sf::Vector2f gridLineLengthY(0, BOARD_HEIGHT);

	for (int i = 0; i < NUMBER_OF_RENDERED_GRID_LINES; i++) {
		//Horizontal Lines
		boardGridLinesX[i].setFillColor(sf::Color::Transparent);
		boardGridLinesX[i].setOutlineThickness(BOARD_GRIDLINES_THICKNESS);
		boardGridLinesX[i].setOutlineColor(sf::Color(0, 0, 0, 125));
		boardGridLinesX[i].setSize(gridLineLengthX);
		boardGridLinesX[i].setPosition(sf::Vector2f(BOARD_OUTLINE_THICKNESS, gridSize + (gridSize * i)));

		//Vertical Lines
		boardGridLinesY[i].setFillColor(sf::Color::Transparent);
		boardGridLinesY[i + NUMBER_OF_RENDERED_GRID_LINES].setFillColor(sf::Color::Transparent);
		boardGridLinesY[i].setOutlineThickness(BOARD_GRIDLINES_THICKNESS);
		boardGridLinesY[i + NUMBER_OF_RENDERED_GRID_LINES].setOutlineThickness(BOARD_GRIDLINES_THICKNESS);
		boardGridLinesY[i].setOutlineColor(sf::Color(0, 0, 0, 125));
		boardGridLinesY[i + NUMBER_OF_RENDERED_GRID_LINES].setOutlineColor(sf::Color(0, 0, 0, 125));
		boardGridLinesY[i].setSize(gridLineLengthY);
		boardGridLinesY[i + NUMBER_OF_RENDERED_GRID_LINES].setSize(gridLineLengthY);
		boardGridLinesY[i].setPosition(sf::Vector2f(gridSize + (gridSize * i), BOARD_OUTLINE_THICKNESS));
		boardGridLinesY[i + NUMBER_OF_RENDERED_GRID_LINES].setPosition(sf::Vector2f(BOARD_OUTLINE_THICKNESS + BOARD_WIDTH + (gridSize + (gridSize * i)), BOARD_OUTLINE_THICKNESS));
	}
}

void Wrapper::DrawGridLines()
{
	for (int i = 0; i < NUMBER_OF_RENDERED_GRID_LINES; i++) {
		this->gameWindow->draw(boardGridLinesX[i]);
		this->gameWindow->draw(boardGridLinesY[i]);
		this->gameWindow->draw(boardGridLinesY[i + NUMBER_OF_RENDERED_GRID_LINES]);
	}
}

void Wrapper::initText()
{
	if (!this->infoFont.loadFromFile("resources/BurbankBigCondensed-Bold.otf")) {
		std::cout << "Font: Burbank could not be loaded" << std::endl;
	}

	P1ScoreText.setFont(infoFont);
	P2ScoreText.setFont(infoFont);

	P1ScoreText.setString("Player 1:\nHits:\nMisses:\nTotal Shots:");
	P2ScoreText.setString("Player 2:\nHits:\nMisses:\nTotal Shots:");



	P1ScoreText.setPosition(sf::Vector2f(20, BOARD_HEIGHT + BOARD_OUTLINE_THICKNESS + 20));//X-Value and added-value in Y is an arbritary number used for styling
	P2ScoreText.setPosition(sf::Vector2f(BOARD_WIDTH + (2 * BOARD_OUTLINE_THICKNESS) + 20, BOARD_HEIGHT + BOARD_OUTLINE_THICKNESS + 20));

	
}

void Wrapper::initGameBoardVisuals()
{
	//Setting up visual representation of the game boards
	this->P1BoardPosition.x = this->P1BoardPosition.y = BOARD_OUTLINE_THICKNESS;//Position is set to outline thickness because the outline is otherwise
	//cutoff by the window edge

	this->P2BoardPosition.x = BOARD_WIDTH + BOARD_OUTLINE_THICKNESS;
	this->P2BoardPosition.y = BOARD_OUTLINE_THICKNESS;


	this->P1Board.setPosition(this->P1BoardPosition);
	this->P2Board.setPosition(this->P2BoardPosition);

	this->P1Board.setSize(sf::Vector2f(BOARD_WIDTH, BOARD_HEIGHT));
	this->P2Board.setSize(sf::Vector2f(BOARD_WIDTH, BOARD_HEIGHT));

	this->P1Board.setOutlineColor(sf::Color::Black);
	this->P2Board.setOutlineColor(sf::Color::Black);

	this->P1Board.setOutlineThickness(BOARD_OUTLINE_THICKNESS);
	this->P2Board.setOutlineThickness(BOARD_OUTLINE_THICKNESS);

	this->P1Board.setFillColor(sf::Color::Transparent);
	this->P2Board.setFillColor(sf::Color::Transparent);

	this->initGridLines();
}

void Wrapper::DrawGame()
{
	//General Render for game window
	this->gameWindow->clear(sf::Color(96, 175, 206, 255));
	this->gameWindow->draw(this->gameBackgroundSprite);
	this->gameWindow->draw(this->P1Board);
	this->gameWindow->draw(this->P2Board);
	this->gameWindow->draw(this->P1ScoreText);
	this->gameWindow->draw(this->P2ScoreText);
	if (this->currState == GameState::Setup) {
		for (int i = 0; i <= this->maxShipToRender; i++) {
			this->gameWindow->draw(this->shipSprites[i]);
		}
	}
	this->DrawGridLines();
}

void Wrapper::MoveUp()
{
	if (this->game.getShipAtIndex(Player::Player_1, maxShipToRender)->getOrientation() == Cardinal::North) {
		if ((this->selectedShip->getPos().y - 1) >= 0) {
			//Set new position
			this->selectedShip->setPos(sf::Vector2i(this->selectedShip->getPos().x,this->selectedShip->getPos().y - 1));
			std::cout << "(" << this->selectedShip->getPos().x << ", " << this->selectedShip->getPos().y << ")" << std::endl;
		}
	}
	//else if (this->game.getShipAtIndex(Player::Player_1, maxShipToRender)->getOrientation() == Cardinal::South) {
	//	if ((this->selectedShip->getPos().y - 1) >= 0) {
	//		this->selectedShip->setPos(sf::Vector2i(this->selectedShip->getPos().x, this->selectedShip->getPos().y - 1));
	//		std::cout << "(" << this->selectedShip->getPos().x << ", " << this->selectedShip->getPos().y << ")" << std::endl;
	//	}
	//}
	/*
	else if (this->game.getShipAtIndex(Player::Player_1, maxShipToRender)->getOrientation() == Cardinal::East) {
		if ((this->selectedShip->getPos().y - 1) >= 0) {
			currShipPos.y -= 1;
			std::cout << "(" << currShipPos.x << ", " << currShipPos.y << ")" << std::endl;
		}
	}
	else if (this->game.getShipAtIndex(Player::Player_1, maxShipToRender)->getOrientation() == Cardinal::West) {
		if ((this->selectedShip->getPos().y - 1) >= 0) {
			currShipPos.y -= 1;
			std::cout << "(" << currShipPos.x << ", " << currShipPos.y << ")" << std::endl;
		}
	}
	*/
	this->shipSprites[maxShipToRender].setPosition((this->selectedShip->getPos().x * gridSize) + BOARD_OUTLINE_THICKNESS, (this->selectedShip->getPos().y * gridSize) + BOARD_OUTLINE_THICKNESS);
}

void Wrapper::MoveDown()
{
	if (this->game.getShipAtIndex(Player::Player_1, maxShipToRender)->getOrientation() == Cardinal::North) {
		if ((this->selectedShip->getPos().y + 1) <= (MAX_ROWS - this->game.getShipAtIndex(Player::Player_1, maxShipToRender)->getHealth())) {
			this->selectedShip->setPos(sf::Vector2i(this->selectedShip->getPos().x, this->selectedShip->getPos().y + 1));
			std::cout << "(" << this->selectedShip->getPos().x << ", " << this->selectedShip->getPos().y << ")" << std::endl;
		}
	}
	/*else if (this->game.getShipAtIndex(Player::Player_1, maxShipToRender)->getOrientation() == Cardinal::South) {
		if ((this->currShipPos.y + 1) <= (MAX_ROWS - this->game.getShipAtIndex(Player::Player_1, maxShipToRender)->getHealth())) {
			currShipPos.y += 1;
			std::cout << "(" << currShipPos.x << ", " << currShipPos.y << ")" << std::endl;
		}
	}*/
	/*else if (this->game.getShipAtIndex(Player::Player_1, maxShipToRender)->getOrientation() == Cardinal::East) {
		if ((this->currShipPos.y + 1) < MAX_ROWS) {
			currShipPos.y += 1;
			std::cout << "(" << currShipPos.x << ", " << currShipPos.y << ")" << std::endl;
		}
	}
	else if (this->game.getShipAtIndex(Player::Player_1, maxShipToRender)->getOrientation() == Cardinal::West) {
		if ((this->currShipPos.y + 1) < MAX_ROWS) {
			currShipPos.y += 1;
			std::cout << "(" << currShipPos.x << ", " << currShipPos.y << ")" << std::endl;
		}
	}*/
	this->shipSprites[maxShipToRender].setPosition((this->selectedShip->getPos().x * gridSize) + BOARD_OUTLINE_THICKNESS, (this->selectedShip->getPos().y * gridSize) + BOARD_OUTLINE_THICKNESS);
}

void Wrapper::MoveLeft()
{
}

void Wrapper::MoveRight()
{
}

void Wrapper::HandleSetupInput(sf::Event& keyEvent)
{
	if (keyEvent.key.code == sf::Keyboard::W) {
		this->MoveUp();
	}
	else if (keyEvent.key.code == sf::Keyboard::A) {
		this->selectedShip->setPos(sf::Vector2i(this->selectedShip->getPos().x - 1, this->selectedShip->getPos().y));
		std::cout << "(" << this->selectedShip->getPos().x << ", " << this->selectedShip->getPos().y << ")" << std::endl;
		this->shipSprites[maxShipToRender].setPosition((this->selectedShip->getPos().x * gridSize) + BOARD_OUTLINE_THICKNESS, (this->selectedShip->getPos().y * gridSize) + BOARD_OUTLINE_THICKNESS);
	}
	else if (keyEvent.key.code == sf::Keyboard::S) {
		this->MoveDown();
	}
	else if (keyEvent.key.code == sf::Keyboard::D) {
		this->selectedShip->setPos(sf::Vector2i(this->selectedShip->getPos().x + 1, this->selectedShip->getPos().y));
		std::cout << "(" << this->selectedShip->getPos().x << ", " << this->selectedShip->getPos().y << ")" << std::endl;
		this->shipSprites[maxShipToRender].setPosition((this->selectedShip->getPos().x * gridSize) + BOARD_OUTLINE_THICKNESS, (this->selectedShip->getPos().y * gridSize) + BOARD_OUTLINE_THICKNESS);
	}
	//else if (keyEvent.key.code == sf::Keyboard::E) {
	//	//Set the origin of the sprite to its center
	//	this->shipSprites[maxShipToRender].setOrigin(this->shipSprites[maxShipToRender].getLocalBounds().getSize().x / 2, this->shipSprites[maxShipToRender].getLocalBounds().getSize().y / 2);
	//	//Rotate sprite around its center
	//	this->shipSprites[maxShipToRender].rotate(90);
	//	//Reset origin to top left corner
	//	this->shipSprites[maxShipToRender].setOrigin(0, 0);
	//}
	//else if (keyEvent.key.code == sf::Keyboard::Q) {
	//	//Set the origin of the sprite to its center
	//	this->shipSprites[maxShipToRender].setOrigin(this->shipSprites[maxShipToRender].getLocalBounds().getSize().x / 2, this->shipSprites[maxShipToRender].getLocalBounds().getSize().y / 2);
	//	//Rotate sprite around its center
	//	this->shipSprites[maxShipToRender].rotate(-90);
	//	//Reset origin to top left corner
	//	this->shipSprites[maxShipToRender].setOrigin(0, 0);
	//	
	//}
	else if (keyEvent.key.code == sf::Keyboard::Enter) {//Place ship on board
		//place ship into battleship board[][]
		
		//increment max ships
		
		if (this->maxShipToRender + 1 < 5) {
			maxShipToRender++;
		}
		else {
			this->currState = GameState::Playing;
		}
		
		//load next ship pointer
		this->selectedShip = game.getShipAtIndex(Player::Player_1, maxShipToRender);
	}
}



/*
* Default constructor for the wrapper class
*/
Wrapper::Wrapper()
{

	//The order of initializing methods is important! Do not switch,
	//Or the game window will be a nullpointer!
	this->initVars();
	this->initWindow();

	//Textures/Visuals
	this->initTextures();
	this->initGameBoardVisuals();
	this->initText();

	currState = GameState::Menu;

}

Wrapper::~Wrapper()
{
	delete this->gameWindow;
}



void Wrapper::pollEvents()
{
	while (this->gameWindow->pollEvent(this->e)) {
		switch (this->e.type)
		{
			case sf::Event::Closed:
				this->gameWindow->close();
				break;
			case sf::Event::KeyPressed:
				if (this->currScreen == Screen::Play) {
					if (this->currState == GameState::Setup) {
						this->HandleSetupInput(this->e);
					}
				}
				else if (this->currScreen == Screen::Main) {//Keyboard behavior for main menu
						if (this->e.key.code == sf::Keyboard::Escape) this->gameWindow->close();

						if (this->e.key.code == sf::Keyboard::Up) this->menu->MoveUp();

						if (this->e.key.code == sf::Keyboard::Down) this->menu->MoveDown();

						if (this->e.key.code == sf::Keyboard::Enter) {
							int option = this->menu->GetSelectedOption();
							if (option == 0) {
								//std::cout << "Play Selected" << std::endl;
								this->currScreen = Screen::Play;
								this->currState = GameState::Setup;
							}

							else if (option == 1) {
								//std::cout << "Instructions Selected" << std::endl;
								this->currScreen = Screen::Instructions;
							}

							else if (option == 2) {
							this->gameWindow->close();
							}
						}
				}
				else if (this->currScreen == Screen::Instructions) {//Keyboard behavior for instruction screen
					if (this->e.key.code == sf::Keyboard::Escape) this->currScreen = Screen::Main;
				}
				break;
		}
	}
}

void Wrapper::update()
{
	this->pollEvents();
	//this->game.UpdateScoreBoard(&P1ScoreText, &P2ScoreText);
	//std::cout << P1ScoreText.getString().toUtf32().c_str() << std::endl;
	//std::cout << P2ScoreText.getString().toUtf32().c_str() << std::endl;
}

void Wrapper::render()
{
	this->gameWindow->clear();
	//Drawing game stuff happens here
	switch (this->currScreen)
	{
		case Screen::Play:
			this->DrawGame();
			break;
		case Screen::Main:
			this->menu->DrawMainMenu(*gameWindow);
			break;
		case Screen::Instructions:
			this->menu->DrawInstructions(*gameWindow);
			break;
	}


	this->gameWindow->display();
}

/*
* Used when determining whether the program window is open or closed.
* Allows the use of sf::RenderWindow::isOpen() while encapsulating the window-object as private.
* @return TRUE if window is open, FALSE if closed.
*/
bool Wrapper::getWindowStatus()
{
	return this->gameWindow->isOpen();
}