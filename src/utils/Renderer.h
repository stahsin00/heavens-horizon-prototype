#ifndef RENDERER_H
#define RENDERER_H

#include <vector>

class Renderer {
public:
    static void clearScreen();
    static void render(const std::vector<std::vector<char>>& grid);
};

#endif
