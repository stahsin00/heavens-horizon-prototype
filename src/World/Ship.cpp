#include "Ship.h"

Ship::Ship(int size) : size(size) {
    tiles.resize(size, std::vector<Tile>(size, Tile(0, 0)));

    for (int x = 0; x < size; ++x) {
        for (int y = 0; y < size; ++y) {
            tiles[x][y] = Tile(x, y);
        }
    }
}

int Ship::getSize() const {
    return size;
}

Tile& Ship::getTile(int x, int y) {
    return tiles[x][y];
}

Tile& Ship::operator()(int x, int y) {
    return tiles[x][y];
}
