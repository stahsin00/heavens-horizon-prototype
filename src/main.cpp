#include <iostream>
#include <thread>
#include <chrono>
#include <vector>

const int WIDTH = 20;
const int HEIGHT = 10;

void clearScreen() {
    system("CLS");
}

void renderGrid(const std::vector<std::vector<char>>& grid) {
    clearScreen();
    for (const auto& row : grid) {
        for (char cell : row) {
            std::cout << cell << ' ';
        }
        std::cout << std::endl;
    }
}

int main() {
    std::vector<std::vector<char>> grid(HEIGHT, std::vector<char>(WIDTH, '.'));
    
    int npcX = WIDTH / 2;
    int npcY = HEIGHT / 2;
    
    grid[npcY][npcX] = 'N';

    while (true) {
        grid[npcY][npcX] = '.';

        npcX += (rand() % 3) - 1;
        npcY += (rand() % 3) - 1;

        npcX = std::max(0, std::min(WIDTH - 1, npcX));
        npcY = std::max(0, std::min(HEIGHT - 1, npcY));

        grid[npcY][npcX] = 'N';

        renderGrid(grid);

        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }

    return 0;
}
