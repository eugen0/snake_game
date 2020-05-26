#include "../Player.h"
#include <conio.h>
#include <iostream>

Player::Player(std::string name):name_(name) {}
void Player::setScore(int num) {score_ = num;};
int Player::getScore() {return score_;};
std::string Player::getName() const {return name_;}
bool Player::isActive() {return active;};
void Player::GameOver() { active = false;}

int Player::Move() {
    int user_key;
    while (_kbhit()) {
        user_key = _getch();
    }
    return user_key;
}
