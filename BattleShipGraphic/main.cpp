// BattleShipGraphic.cpp : This file contains the 'main' function. The game window is created here and the game-loop is started here.
//
#include "Wrapper.h"

int main()
{
    //Init Game Window
    Wrapper game;

    //Game loop
    while (game.getWindowStatus()) {

        game.update();
        
        game.render();
    }
    return 0;
}