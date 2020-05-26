
#ifndef SNAKE_GAME_OOP_PRACTICE_INFOBOX_H
#define SNAKE_GAME_OOP_PRACTICE_INFOBOX_H


#include <string>
#include <vector>

class InfoBox {
    std::vector<std::string> msg_;

public:
    InfoBox();
    //InfoBox(std::string msg);
    void SetInfo( std::string msg);
    void ClearInfo();
    std::vector<std::string>& GetInfo();

};



#endif //SNAKE_GAME_OOP_PRACTICE_INFOBOX_H
