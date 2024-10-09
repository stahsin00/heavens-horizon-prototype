#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include "Renderer.h"
#include "TimeTickSystem.h"

const int WIDTH = 20;
const int HEIGHT = 10;

void update(std::vector<std::vector<char>>& grid, int& npcX, int& npcY) {
    grid[npcY][npcX] = '.';

    npcX += (rand() % 3) - 1;
    npcY += (rand() % 3) - 1;

    npcX = std::max(0, std::min(WIDTH - 1, npcX));
    npcY = std::max(0, std::min(HEIGHT - 1, npcY));

    grid[npcY][npcX] = 'N';

    Renderer::render(grid);
}

int main() {
    std::vector<std::vector<char>> grid(HEIGHT, std::vector<char>(WIDTH, '.'));
    
    int npcX = WIDTH / 2;
    int npcY = HEIGHT / 2;
    
    grid[npcY][npcX] = 'N';

    TimeTickSystem& timeTickSystem = TimeTickSystem::getInstance();

    timeTickSystem.onTick([&grid, &npcX, &npcY]() {
        update(grid, npcX, npcY);
    });

    timeTickSystem.start();

    while (true) {  // TODO
        std::this_thread::sleep_for(std::chrono::minutes(10));
    }

    return 0;
}
