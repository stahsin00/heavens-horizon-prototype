#include "NeedManager.h"
#include <cmath>

NeedManager::NeedManager() {
    TimeTickSystem::getInstance().onTick([this]() {  // TODO: get more comfortable with this syntax ;-;
        update();
    });
}

void NeedManager::addNeed(std::unique_ptr<Need> need) {
    if (need) {
        needs[need->getType()] = std::move(need);
    }
}

void NeedManager::update() {
    for (auto& [type, need] : needs) {
        need->decay();
    }
}

void NeedManager::recover(const std::string& type, float amount) {
    if (auto it = needs.find(type); it != needs.end()) {
        it->second->recover(amount);
    }
}

float NeedManager::scoreNeed(const std::string& type) const {
    if (auto it = needs.find(type); it != needs.end()) {
        return it->second->scoreNeed();
    }
    return 0.0f;
}

float NeedManager::getCurrent(const std::string& type) const {
    if (auto it = needs.find(type); it != needs.end()) {
        return it->second->getCurrent();
    }
    return 1.0f;
}