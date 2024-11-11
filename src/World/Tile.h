#ifndef TILE_H
#define TILE_H

#include <memory>
#include "SmartObject.h"

class Tile {
public:
    Tile(int x, int y);

    int getX() const;
    int getY() const;

    bool isEmpty() const;

    void setObject(std::unique_ptr<SmartObject> obj);  // TODO
    SmartObject* getObject() const;

private:
    int x;
    int y;

    bool isEmpty;
    
    std::unique_ptr<SmartObject> object;  // TODO
};

#endif
