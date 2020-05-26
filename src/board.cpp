#include <algorithm>
#include "../Board.h"


void changeBorder(std::vector<Position>& pos){
    auto change =[]( Position& p){ p.setSymbol('%');};
    std::for_each(pos.begin(), pos.end(),change);
}

std::vector<pos>& getBoard(std::vector<pos>& board, int height = 20, int length = 100){
    for( int i =0; i<height; ++i){// rows
        pos temp;
        for(int j = 0; j<length; ++j) {   // columns
            temp.push_back(Position(i,j,' '));          // populated with empty string;
        }
        board.push_back(temp);
    }

    // placing boarder around
    for(auto& i: board){
        if(i.front().getX() == 0) changeBorder(i);              // top border;
        i.front().setSymbol('%');                               // border right;
        i.back().setSymbol('%');                                // border left;
        if(i.front().getX() == board.size() -1) changeBorder(i);  // bottom border;
    }

    return board;
}

// building the board with margins;
Board::Board(int height, int length) {
    getBoard(board_, height, length);
}

bool Board::IsEmptyPosition( const Position& pos) {
    if(board_[pos.getX()][pos.getY()].getSymbol() == ' ') return true;
    return false;
}
void Board::OccupyPosition( Position pos) {
    board_[pos.getX()][pos.getY()].setSymbol(pos.getSymbol());
}

std::vector<pos> Board::GetState() const {
    return board_;
}

void Board::ClearBoard() {
    board_.clear();
    getBoard(board_);
}

bool Board::isBorder(Position pos) {
    if(board_[pos.getX()][pos.getY()].getSymbol() == '%') return true;
    return false;
}


