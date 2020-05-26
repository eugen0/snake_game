#include "../Snake.h"
#include <iostream>
#include <algorithm>

Snake::Snake():snake_{{3,20,'*'},{2,20,'*'}}{};

Snake::Snake(std::vector<Position> snake) : snake_(snake){};

void Snake::SetHead(Position &pos) {snake_.front() = pos;};
void Snake::SetTail(Position &pos) { snake_.back() = pos;}
void Snake::AddPos(Position pos) {
    auto s_size = snake_.size();
    snake_.emplace_back(pos);
    if( s_size == snake_.size()){std::cout << "ERROR: Snake size " << std::endl;}
}
Position Snake::GetHead() const {return snake_.front();};
Position Snake:: GetTail() const {return snake_.back();}
std::vector<Position> Snake::GetSnakePositions() const {return snake_;}

bool Snake::Update(Position &pos, int& free_snake) {
    // check if head hits any other nodes of snake;
    auto temp_head = snake_.front() + pos;
    auto hit = std::any_of(snake_.begin()+1, snake_.end(),[&temp_head](auto it){return it.isEqual(temp_head);} );
    if(hit){
        free_snake = 0;
    return false;}
    //player.GameOver();info.SetInfo("Game Over");} set palyer in controller to active = false;

    // update body
    for( int i = snake_.size()-1; i > 0; --i){
            snake_.at(i) = snake_.at(i - 1);
    }
    // update head
    snake_.at(0) = snake_.at(0) + pos;
    return  true;
}
