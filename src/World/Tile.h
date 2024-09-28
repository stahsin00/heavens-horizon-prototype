#ifndef TILE_H
#define TILE_H

class Tile {
public:
    Tile(int x, int y);

    int getX() const;
    int getY() const;

private:
    int x;
    int y;
};

#endif
