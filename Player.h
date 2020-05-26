
#ifndef SNAKE_GAME_OOP_PRACTICE_PLAYER_H
#define SNAKE_GAME_OOP_PRACTICE_PLAYER_H


#include <string>

#include "InfoBox.h"


class Player {
    std::string name_;
    int score_ = 0;
    bool active = true;
public:
    explicit Player(std::string name = "Default name");

    // setter, getter
    std::string getName() const;
    void setScore(int num);
    int getScore();

    int Move();
    bool isActive();
    void GameOver();
};

#endif //SNAKE_GAME_OOP_PRACTICE_PLAYER_H
