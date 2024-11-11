#ifndef SMARTOBJECT_H
#define SMARTOBJECT_H

#include "Entity.h"

class SmartObject : public Entity {
public:
    SmartObject(int x, int y, bool walkable = true, char symbol = '.');

    int getX() const;
    int getY() const;

    char getSymbol() const;

private:
    int x;
    int y;

    char symbol;

    bool isWalkable;
};

#endif
