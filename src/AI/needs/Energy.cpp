#include "Energy.h"
#include <cmath>

Energy::Energy() {
    type = "Energy";
    current = 1.0f;
}

void Energy::decay() {
    current -= current * 0.1f;
}

float Energy::scoreNeed() {
    const float k = 5.0f;
    return 1.0f - (1.0f - std::exp(-k * current));
}