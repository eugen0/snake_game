#ifndef SNAKE_GAME_OOP_PRACTICE_POSITION_H
#define SNAKE_GAME_OOP_PRACTICE_POSITION_H
class Position{
        int x_;
        int y_;
        char symbol_;
public:

        Position() = delete ;
        Position(int x, int y, char c);

        // setter, getter
        void setX(int x);
        void setY(int y);
        void setSymbol(char c);
        int getX() const;
        int getY() const;
        char getSymbol() const;

        //print
        void Print() const;

        // overload
        Position operator+(Position& pos);
        bool operator==(Position& rhs) const ;
        bool isEqual(Position& rhs) const ;
        //void operator=(Position& rhs);
};


#endif //SNAKE_GAME_OOP_PRACTICE_POSITION_H
