cmake_minimum_required(VERSION 3.16)
project(Snake_Game_OOP_Practice)

set(CMAKE_CXX_STANDARD 17)

add_executable(Snake_Game_OOP_Practice interface/IApple.h Position.h  Apple.h Board.h Player.h InfoBox.h test/test.cpp main.cpp src/apple.cpp src/position.cpp src/player.cpp Snake.h src/snake.cpp src/board.cpp Controller.h Renderer.h src/renderer.cpp src/controller.cpp src/infoBox.cpp)