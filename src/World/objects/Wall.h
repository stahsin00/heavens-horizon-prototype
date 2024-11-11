#ifndef WALL_H
#define WALL_H

#include "SmartObject.h"

class Wall : public SmartObject {
public:
    Wall(int x, int y, bool walkable = false, char symbol = '#');

private:
};

#endif
