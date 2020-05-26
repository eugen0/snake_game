
#ifndef SNAKE_GAME_OOP_PRACTICE_CONTROLLER_H
#define SNAKE_GAME_OOP_PRACTICE_CONTROLLER_H

#include "Snake.h"
#include "Apple.h"
#include "Board.h"
#include "InfoBox.h"
#include "Player.h"
#include "Renderer.h"

class Controller{
    Apple apple;                // apple is init at def
    Snake snake;                // init at def
    Board board;                // init at def
    InfoBox info;               // init at def
    Player player;              // user defined
    Renderer render;            // free funct
public:
    Controller(Player& x);
    void PlayGame();





};


#endif //SNAKE_GAME_OOP_PRACTICE_CONTROLLER_H
