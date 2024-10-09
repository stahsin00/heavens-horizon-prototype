#include "TimeTickSystem.h"
#include <iostream>

void TimeTickSystem::start() {
    if (isRunning) return;
    isRunning = true;
    tickThread = std::thread(&TimeTickSystem::internalClock, this);  // TODO
}

void TimeTickSystem::stop() {
    if (!isRunning) return;
    isRunning = false;

    if (tickThread.joinable()) {  // TODO
        tickThread.join();
    }
}

void TimeTickSystem::onTick(const std::function<void()>& callback) {
    tickCallbacks.push_back(callback);
}

TimeTickSystem::~TimeTickSystem() {
    stop();
}

void TimeTickSystem::internalClock() {
    while (isRunning) {
        for (const auto& callback : tickCallbacks) {
            if (callback) callback();
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(1000 / speed));
    }
}
