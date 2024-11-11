#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>
#include <vector>
#include "Renderer.h"
#include "TimeTickSystem.h"
#include "Ship.h"
#include "SmartObject.h"
#include "Wall.h"
#include "Fridge.h"

const int WIDTH = 20;
const int HEIGHT = 20;

std::unique_ptr<SmartObject> createObject(char symbol, int x, int y) {
    switch (symbol) {
        case '.':
            return nullptr;
        case '#':
            return std::make_unique<Wall>(x, y);  // TODO

        case 'F':
            return std::make_unique<Fridge>(x, y);

        default:
            return nullptr;
    }
}

Ship initializeShip(const std::string& configFilePath, int width, int height) {
    Ship ship(width);
    
    std::ifstream configFile(configFilePath);
    std::string line;
    int y = 0;

    while (std::getline(configFile, line) && y < height) {

        for (int x = 0; x < width && x < line.size(); ++x) {

            char symbol = line[x];

            auto object = createObject(symbol, x, y);
            if (object) {
                ship.getTile(x, y).setObject(std::move(object));
            }
        }

        y++;
    }

    return ship;
}

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
    Ship ship = initializeShip("ship.txt", 20, 20);
    
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
