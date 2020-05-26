
#ifndef SNAKE_GAME_OOP_PRACTICE_APPLE_H
#define SNAKE_GAME_OOP_PRACTICE_APPLE_H

#include "interface/IApple.h"

class Apple: public IApple{
    Position apple_;
public:
    Apple() = delete;
    Apple(int x, int y , char c = '@');

    void setPosition(int x, int y, char c ='@');
    void setPosition (Position pos) override;
    Position getPosition() override;

};

#endif //SNAKE_GAME_OOP_PRACTICE_APPLE_H
