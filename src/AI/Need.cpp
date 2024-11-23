#include "Need.h"
#include <string>
#include <algorithm>

Need::Need() : current(1.0f) {}

const std::string& Need::getType() const {
    return type;
}

float Need::getCurrent() const {
    return current;
}

void Need::recover(float value) {
    current = std::clamp(current + value, 0.0f, 1.0f);
}
