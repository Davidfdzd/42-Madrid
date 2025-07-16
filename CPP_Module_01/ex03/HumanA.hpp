#pragma once

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanA{
private:
    std::string _name;
    Weapon &_weapon;
public:
    HumanA(const std::string& name, Weapon &weapon);
    ~HumanA(void);
    void attack() const;
};