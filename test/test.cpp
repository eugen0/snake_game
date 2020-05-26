/*
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "../Player.h"
#include "../Apple.h"
#include "../Position.h"
#include "../Snake.h"


TEST_CASE ("Testing Init Game"){
    SECTION("Player Init") {
        Player x("Eugen");
        x.setScore(12);
        CHECK (x.getName() == "Eugen");
        CHECK(x.getScore() == 12);
        CHECK (x.isActive() == true);
    };

    SECTION("Position init"){
        Position pos(1,1,'@');
        CHECK( pos.getX() == 1);
        CHECK(pos.getY() == 1);

        Position pos2(1,1,'@');
        CHECK( pos.isEqual(pos2));
        //CHECK(pos == pos2);
    }

    SECTION("Apple init"){
       Apple apple(1,2,'@');
       Apple apple2(1, 2,'@');
       auto app1_pos = apple.getPosition();
       auto app2_pos = apple.getPosition();
       CHECK (app1_pos.isEqual(app2_pos));
       apple.setPosition(2,3);
       CHECK_FALSE(!app1_pos.isEqual(app2_pos));

    }

    SECTION ("Snake, Apple, InfoBox Init"){

        int x =1+rand()%20, y = 1+rand()%30;
        Apple t_apple( x, y );

        InfoBox t_info_b;
        t_info_b.SetInfo("Test new info box");
        CHECK (t_info_b.GetInfo().front() == "Test new info box");

        Snake t_snake;
        //add pos
        t_snake.AddPos(t_apple.getPosition());
        CHECK (t_snake.GetSnakePositions().size() == 3);

        // check that is same pos
        t_snake.AddPos(t_apple.getPosition());

        auto apple_pos = t_apple.getPosition();
        auto snake_head_pos = t_snake.GetHead() + apple_pos;
        auto snake_back_pos = t_snake.GetTail() + apple_pos;

        CHECK_FALSE(snake_head_pos.isEqual(apple_pos));
        CHECK_FALSE(snake_back_pos.isEqual(apple_pos));
    }

}
*/