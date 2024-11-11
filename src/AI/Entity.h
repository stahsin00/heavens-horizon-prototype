#ifndef ENTITY_H
#define ENTITY_H

#include <vector>
#include "Advertisement.h"

class Entity {
public:
    Entity();

protected:
    std::vector<Advertisement> advertisements;
};

#endif
