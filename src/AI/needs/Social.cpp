#include "Social.h"
#include <cmath>

Social::Social() {
    type = "Social";
    current = 1.0f;
}

void Social::decay() {
    current -= DECAY_RATE;
}

float Social::scoreNeed() {
    if (current > 0.5f) {
        const float k = 5.0f;
        return -(1.0f - std::exp(-k * current)) + 1.0f;
    } else {
        return 0.9f;
    }
}