#ifndef SHIP_H
#define SHIP_H

#include <vector>
#include "Tile.h"

class Ship {
public:
    Ship(int size);

    int getSize() const;
    Tile& getTile(int x, int y);
    Tile& operator()(int x, int y);

private:
    int size;
    std::vector<std::vector<Tile>> tiles;
};

#endif
