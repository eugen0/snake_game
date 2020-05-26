#include "../Renderer.h"
#include <algorithm>
#include <iostream>

auto print = [](const auto c){ c.Print();};

void Renderer::RenderBoard(const std::vector<std::vector<Position>> & board) {
    for(const auto& i:board){
        std::for_each(i.begin(), i.end(),print);
        std::cout<< "\n";
    }
}

void Renderer::RenderInfoBox(std::vector<std::string>&msgs) {
    for(auto& i: msgs){
        std::cout << i << std::endl;
    }
}
