#ifndef HUNGER_H
#define HUNGER_H

#include "Need.h"

class Hunger : public Need {
public:
    Hunger();
    void decay() override;
    float scoreNeed() override;

private:
    static constexpr float DECAY_RATE = 0.01f;
};

#endif