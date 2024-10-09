#include "Advertisement.h"

Advertisement::Advertisement(const Interaction& task) : task(task) {}

const Interaction& Advertisement::getTask() const {
    return task;
}

const std::vector<Reward>& Advertisement::getRewards() const {
    return rewards;
}

void Advertisement::addReward(const Reward& reward) {
    rewards.push_back(reward);
}
