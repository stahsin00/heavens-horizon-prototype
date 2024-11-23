#ifndef NEED_H
#define NEED_H

#include <string>

class Need {
public:
    Need();

    const std::string& getType() const;
    float getCurrent() const;
    void recover(float amount);

    virtual void decay();
    virtual float scoreNeed();

protected:
    std::string type;
    float current;
};

#endif
