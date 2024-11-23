#include "Hunger.h"
#include <cmath>

Hunger::Hunger() {
    type = "Hunger";
    current = 1.0f;
}

void Hunger::decay() {
    current -= DECAY_RATE;
}

float Hunger::scoreNeed() {
    const float k = 5.0f;
    return 1.0f - (1.0f - std::exp(-k * current));
}