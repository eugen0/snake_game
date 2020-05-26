#include "../Apple.h"

Apple::Apple(int x, int y, char c) :apple_(x, y, c){}

void Apple::setPosition(int x, int y, char c) {apple_.setX(x); apple_.setY(y), apple_.setSymbol(c);}

void Apple::setPosition(Position pos) { apple_ = pos;}

Position Apple::getPosition() { return apple_;};

