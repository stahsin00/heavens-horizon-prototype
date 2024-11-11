#ifndef INTERACTION_H
#define INTERACTION_H

#include <string>
#include <vector>
#include "Reward.h"

class Interaction {
public:
    Interaction();

    const std::string& getName() const;
    const std::vector<Reward>& getRewards() const;
    float getDuration() const;

protected:
    void addReward(const Reward& reward);

public:
    virtual void execute() = 0;

protected:
    std::string name;
    std::vector<Reward> rewards;
    float duration;
};

#endif
