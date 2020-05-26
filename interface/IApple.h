#ifndef SNAKE_GAME_OOP_PRACTICE_IAPPLE_H
#define SNAKE_GAME_OOP_PRACTICE_IAPPLE_H

#include "../Position.h"

class IApple{
public:
    //virtual void setPosition(int x, int y, char ='@') =0;
    virtual void setPosition (Position pos) =0;
    virtual Position getPosition() =0;
};

#endif //SNAKE_GAME_OOP_PRACTICE_IAPPLE_H
