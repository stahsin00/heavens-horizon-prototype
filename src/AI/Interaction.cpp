#include "Interaction.h"

Interaction::Interaction() : x(0), y(0), duration(0.0f) {
    rewards = std::vector<Reward>();
}

const std::string& Interaction::getName() const {
    return name;
}

int Interaction::getX() const {
    return x;
}

int Interaction::getY() const {
    return y;
}

const std::vector<Reward>& Interaction::getRewards() const {
    return rewards;
}

float Interaction::getDuration() const {
    return duration;
}

void Interaction::setName(const std::string& name) {
    this->name = name;
}

void Interaction::addReward(const Reward& reward) {
    rewards.push_back(reward);
}
