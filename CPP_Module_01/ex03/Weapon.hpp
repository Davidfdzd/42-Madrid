#pragma once

#include <string>

class Weapon{
private:
    std::string _type;

public:
    explicit Weapon(const std::string& type);
    const std::string& getType() const;
    void setType(const std::string& newType);
};