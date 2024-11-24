#ifndef NEEDMANAGER_H
#define NEEDMANAGER_H

#include <unordered_map>
#include <memory>
#include <string>
#include "Need.h"
#include "TimeTickSystem.h"

class NeedManager {
public:
    NeedManager();
    void addNeed(std::unique_ptr<Need> need);
    
    void update();

    void recover(const std::string& type, float amount);
    float scoreNeed(const std::string& type) const;
    float getCurrent(const std::string& type) const;

private:
    std::unordered_map<std::string, std::unique_ptr<Need>> needs;
};

#endif