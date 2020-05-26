

#ifndef SNAKE_GAME_OOP_PRACTICE_RENDERER_H
#define SNAKE_GAME_OOP_PRACTICE_RENDERER_H


#include <vector>
#include <string>
#include "Position.h"

class Renderer {
    public:
        void RenderBoard(const std::vector<std::vector<Position>>& board);
        void RenderInfoBox( std::vector<std::string>& msg);
};


#endif //SNAKE_GAME_OOP_PRACTICE_RENDERER_H
