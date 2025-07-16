#pragma once

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanB{
private:
    std::string _name;
    Weapon *_weapon;
public:
    HumanB(const std::string& name);
    ~HumanB(void);
    void setWeapon(Weapon& weapon);
    void attack() const;
};