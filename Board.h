
#ifndef SNAKE_GAME_OOP_PRACTICE_BOARD_H
#define SNAKE_GAME_OOP_PRACTICE_BOARD_H


#include <vector>
#include "Position.h"

using pos = std::vector<Position>;

class Board{
    std::vector<pos> board_;
public:
    //Board() = delete ;                                   // can not have an empty board;
    explicit Board (int height = 20, int length = 100);   // make board suitable hight and lenght; populate it with empty characters;
    void OccupyPosition (Position pos);
    bool IsEmptyPosition(const Position& pos);
    std::vector<pos> GetState() const;                     // get board pos with the all pos;
    void ClearBoard();
    bool isBorder(Position pos);
};


#endif //SNAKE_GAME_OOP_PRACTICE_BOARD_H
