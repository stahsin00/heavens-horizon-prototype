#include "Interaction.h"

Interaction::Interaction() : duration(0.0f) {
    rewards = std::vector<Reward>();
}

const std::string& Interaction::getName() const {
    return name;
}

const std::vector<Reward>& Interaction::getRewards() const {
    return rewards;
}

float Interaction::getDuration() const {
    return duration;
}

void Interaction::addReward(const Reward& reward) {
    rewards.push_back(reward);
}
