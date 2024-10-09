#include "Renderer.h"
#include <iostream>
#include <cstdlib>

void Renderer::clearScreen() {
    system("CLS");  // for Windows
}

void Renderer::render(const std::vector<std::vector<char>>& grid) {
    clearScreen();
    for (const auto& row : grid) {
        for (char cell : row) {
            std::cout << cell << ' ';
        }
        std::cout << std::endl;
    }
}
