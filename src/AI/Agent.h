#ifndef AGENT_H
#define AGENT_H

#include "Entity.h"
#include "NeedManager.h"
#include "Energy.h"
#include "Hunger.h"
#include "Social.h"

class Agent : public Entity {
public:
    Agent();

    void receiveReward(const std::string& type, float amount);
    // TODO

private:
    NeedManager needManager;
};

#endif
