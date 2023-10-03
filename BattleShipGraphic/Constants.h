#pragma once

#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/System/Vector2.hpp"

#define MAX_ROWS 10
#define MAX_COLS 10

#define CARRIER 'c'
#define CARRIER_LEN 5
#define CARR_INDEX 0

#define BATTLE 'b'
#define BATTLE_LEN 4
#define BATT_INDEX 1 

#define CRUISER 'r'
#define CRUISER_LEN 3
#define CRUS_INDEX 2

#define SUB 's'
#define SUB_LEN	3
#define SUB_INDEX 3

#define DESTR 'd'
#define DESTR_LEN 2
#define DESTR_INDEX 4

#define HIT '*'
#define MISS 'm'

#define MAX_NUMBER_OF_MENU_ITEMS 3

#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080

#define BOARD_WIDTH 860
#define BOARD_HEIGHT 860

#define NUMBER_OF_SHIPS_PER_PLAYER 5
#define NUMBER_OF_RENDERED_GRID_LINES 9

#define BOARD_OUTLINE_THICKNESS 5
#define BOARD_GRIDLINES_THICKNESS 2

//Used for tracking whose turn it currently is
enum class Player {
	Player_1 = 1,
	Player_2 = 2
};

//Used for tracking which direction the ships are facing
enum class Cardinal
{
	North, South, East, West
};

//Used for tracking which screen is to be rendered: the Main Menu, the Instructions, or the game
enum class Screen {
	Main,
	Instructions,
	Play
};

//Differentiates current game state between the setup phase (players are placing ships),
//when the game is on-going, and when the game is over (one player has lost)
enum class GameState
{
	Menu,
	Setup,
	Playing,
	GameOver
};