#include <algorithm>
#include <iostream>
#include "../Position.h"

Position::Position(int x, int y, char c):x_{std::move(x)}, y_{std::move(y)}, symbol_{std::move(c)} {}
void Position::setX(int x) { x_ = x;};
void Position::setY(int y) {y_=y;}
void Position::setSymbol(char c) {symbol_ =c;}
int Position::getX() const {return x_;};
int Position::getY() const { return y_;};
char Position::getSymbol() const {return symbol_;};
void Position::Print() const { std::cout << symbol_ ;}

Position Position::operator+(Position& pos) {
    Position ret (0,0,pos.getSymbol());
    ret.setX(this->x_ + pos.x_);
    ret.setY(this->y_ + pos.y_);
    return ret;
}
bool Position::operator==(Position &pos) const {
    return this->x_ == pos.getX() && this->y_ == pos.getY();
}

bool Position::isEqual(Position& rhs) const {
    return x_ == rhs.getX() && y_ == rhs.getY();
}
