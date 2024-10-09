#ifndef REWARD_H
#define REWARD_H

#include <string>

class Reward {
public:
    Reward(const std::string& needType, float amount);

    const std::string& getNeedType() const;
    float getAmount() const;

private:
    std::string needType;
    float amount;
};

#endif
