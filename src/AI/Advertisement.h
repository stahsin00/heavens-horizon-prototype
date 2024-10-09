#ifndef ADVERTISEMENT_H
#define ADVERTISEMENT_H

#include <vector>
#include "Interaction.h"
#include "Reward.h"

class Advertisement {
public:
    Advertisement(const Interaction& task);

    const Interaction& getTask() const;

    const std::vector<Reward>& getRewards() const;

    void addReward(const Reward& reward);

private:
    const Interaction& task;
    std::vector<Reward> rewards;
};

#endif
