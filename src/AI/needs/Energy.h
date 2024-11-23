#ifndef ENERGY_H
#define ENERGY_H

#include "Need.h"

class Energy : public Need {
public:
    Energy();
    void decay() override;
    float scoreNeed() override;
};

#endif