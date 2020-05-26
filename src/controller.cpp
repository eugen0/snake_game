#include "../Controller.h"
#include <stdlib.h>
#include <iostream>
#include <unistd.h>

// user valid moves;
Position up(-1, 0, '*');
Position lf(0, -1, '*');
Position rght(0, 1, '*');
Position dwn(1, 0, '*');

// random generator for apple
int RandomX(){return 1+ rand() % 18;};
int RandomY(){return 1+ rand() % 90;}

//set random apple position;
void SetAppleRandomPos(Apple& apple){
    apple.setPosition(RandomX(), RandomY());
}

// put Apple on board
void PlaceAppleOnBoard(Apple& apple, Board& board){
    if(board.IsEmptyPosition(apple.getPosition())){

        //if empty as occupied pos on board;
        board.OccupyPosition(apple.getPosition());
    }else{
        std::cout << "Was an error with random" << std::endl;
        SetAppleRandomPos(apple);
        PlaceAppleOnBoard(apple, board);
    }
}

// put snake on boards
void PlaceSnakeOnBord(std::vector<Position> snake, Board& board){
    //not empty
    if(snake.empty()) std::cout<<"ERROR empty snake"<<std::endl;
    for(auto& i: snake){
        if(board.IsEmptyPosition(i)) board.OccupyPosition(i);
    }
}

bool placeUserMove( int move, Snake& snake, Player& player, InfoBox& info, int& free_snake){
         switch (move) {
             case 97: //a
                 return snake.Update(lf, free_snake);
                 //break;
             case 119: //w
                 return snake.Update(up, free_snake);
                // break;
             case 100: //d
                 return snake.Update(rght, free_snake);
                // break;
             case 115: //s
                 return snake.Update(dwn, free_snake);
                // break;
             case 32:
                 player.GameOver();
                 info.SetInfo("Presses space");
                 break;
             default:
                 info.ClearInfo();
                 info.SetInfo(" Please, use only A, S, D, W");
                 return false;
         }
   return false;
 }

bool BorderHit(Board& board, Snake& snake){
    return board.isBorder(snake.GetHead());
}


 Controller::Controller(Player &x) : player(x), apple(RandomX(), RandomY()) {}

 void Controller::PlayGame() {
     //// main game loop
     while( player.isActive()){
         std::cout << "In teh main game loop" << std::endl;

         ////  load infoBord
         info.SetInfo("Eat the apple but dont't hit the walls and yourself.Use the keyboard W,S,A,D to move towards the apple or press space to quit");

         /// place snake on board
         PlaceSnakeOnBord(snake.GetSnakePositions(), board);

         /// place apple on board
         PlaceAppleOnBoard(apple, board);

         ///Rendere Board and InfoBox;
     render.RenderBoard(board.GetState());
     render.RenderInfoBox(info.GetInfo());
     std::cout <<player.getName() <<" score : " << player.getScore()<< std::endl;

     // clear info, leave space for error messages;
     info.ClearInfo();

     /// player move
     bool valid_move;
     int free_snake = 1;
     do {
         int user_key = player.Move();
         valid_move = placeUserMove(user_key, snake, player, info, free_snake);
         if(valid_move) {
             auto borderHit = BorderHit(board, snake);
             if (borderHit) {
                player.GameOver();
                info.SetInfo(" You hit the border");
             };
         };

         // check if head of snake hit any other nodes
         if(!valid_move){
             // check for sure not mistyping
             if(free_snake == 0){
                 player.GameOver();
                 info.SetInfo("Game over you hit yourself !!!");
                 return;
             }
         }


     }while(!valid_move);


     /// eat the apple
     // snake find apple, new apple
     auto apple_pos = apple.getPosition();
     auto snake_head_pos = snake.GetHead();
     if (apple_pos.isEqual(snake_head_pos)) {
         snake.AddPos(apple_pos);

         // set new apple;
         SetAppleRandomPos(apple);

         // update player score;
         player.setScore(player.getScore()+1);

         //place score in Info box
         //info.SetInfo(static_cast<std::string>(player.getScore()));
        }

         /// render score and problems
       //  render.RenderInfoBox(info.GetInfo());

     ///clear //
     // clear screen
     system("cls");

     // clear board;
     board.ClearBoard();
    // clear info
    //info.ClearInfo();

     }
    render.RenderBoard(board.GetState());
    std::cout << "Outside main loop" <<std::endl;
     //info.ClearInfo();
     info.SetInfo(" Thank you for playing snake. Your score is: ");
     std::cout <<player.getName() <<" score : " << player.getScore()<< std::endl;
     render.RenderInfoBox(info.GetInfo());
};


