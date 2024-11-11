#ifndef REWARD_H
#define REWARD_H

#include <string>

class Reward {
public:
    Reward(const std::string& type, float amount);

    const std::string& getType() const;
    float getAmount() const;

private:
    std::string type;
    float amount;
};

#endif
