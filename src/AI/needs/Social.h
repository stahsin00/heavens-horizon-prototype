#ifndef SOCIAL_H
#define SOCIAL_H

#include "Need.h"

class Social : public Need {
public:
    Social();
    void decay() override;
    float scoreNeed() override;

private:
    static constexpr float DECAY_RATE = 0.01f;
};

#endif