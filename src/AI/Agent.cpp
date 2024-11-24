#include "Agent.h"

Agent::Agent() : Entity() {
    needManager.addNeed(std::make_unique<Energy>());
    needManager.addNeed(std::make_unique<Hunger>());
    needManager.addNeed(std::make_unique<Social>());
}

void Agent::receiveReward(const std::string& type, float amount) {
    needManager.recover(type, amount);
}