
#ifndef SNAKE_GAME_OOP_PRACTICE_SNAKE_H
#define SNAKE_GAME_OOP_PRACTICE_SNAKE_H

#include <vector>
#include "Position.h"

class Snake{
    std::vector <Position> snake_;
public:

    //ctr
    Snake();
    explicit Snake( std::vector<Position> snake);

    //setter, getter
    void SetHead(Position& pos);
    void SetTail(Position& pos );
    void AddPos(Position pos);
    Position GetHead() const ;
    Position GetTail() const ;

    std::vector<Position> GetSnakePositions() const;

    bool Update(Position& pos, int& free_snake);
};

#endif //SNAKE_GAME_OOP_PRACTICE_SNAKE_H
