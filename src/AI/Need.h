#ifndef NEED_H
#define NEED_H

#include <string>

class Need {
public:
    Need(const std::string& type);

    const std::string& getType() const;
    float getCurrent() const;

    void recover(float amount);
    void decay();
    float scoreNeed();

protected:
    std::string type;
    float current;
};

#endif
