#include "Reward.h"

Reward::Reward(const std::string& needType, float amount)
    : needType(needType), amount(amount) {}

const std::string& Reward::getNeedType() const {
    return needType;
}

float Reward::getAmount() const {
    return amount;
}
