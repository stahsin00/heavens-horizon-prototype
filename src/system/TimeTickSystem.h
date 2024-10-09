#ifndef TIMETICKSYSTEM_H
#define TIMETICKSYSTEM_H

#include <functional>
#include <vector>
#include <thread>
#include <chrono>
#include <atomic>

class TimeTickSystem {
public:
    static TimeTickSystem& getInstance() {
        static TimeTickSystem instance;
        return instance;
    }

    // TODO: look more into c++ singleton pattern
    TimeTickSystem(const TimeTickSystem&) = delete;
    TimeTickSystem& operator=(const TimeTickSystem&) = delete;

    void start();

    void stop();

    void onTick(const std::function<void()>& callback);  // TODO: c++ callbacks

    ~TimeTickSystem();

private:
    TimeTickSystem() : isRunning(false), speed(1) {}

    void internalClock();

    std::vector<std::function<void()>> tickCallbacks;
    std::atomic<bool> isRunning;
    int speed;
    std::thread tickThread;  // TODO: learn more about threads
};

#endif
