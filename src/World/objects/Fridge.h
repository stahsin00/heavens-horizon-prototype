#ifndef FRIDGE_H
#define FRIDGE_H

#include "SmartObject.h"

class Fridge : public SmartObject {
public:
    Fridge(int x, int y, bool walkable = false, char symbol = 'F');

private:
};

#endif
