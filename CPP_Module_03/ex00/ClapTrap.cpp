/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfernan3 <dfernan3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 14:43:51 by dfernan3          #+#    #+#             */
/*   Updated: 2025/08/06 15:07:10 by dfernan3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("default"), _hp(10), _energyPoints(10), _attackDamage(0) {
    std::cout<<"ClapTrap constructor called for "<<_name<<std::endl;
}

ClapTrap::ClapTrap(std::string const& name): _name(name), _hp(10), _energyPoints(10), _attackDamage(0) {
    std::cout<<"ClapTrap constructor called for "<<_name<<std::endl;
}

ClapTrap::ClapTrap(ClapTrap const& copy) {
    std::cout<<"ClapTrap copy constructor called for "<<_name<<std::endl;
    *this = copy;
}

ClapTrap& ClapTrap::operator=(ClapTrap const& copy){
    std::cout<<"ClapTrap assignment operator called for "<<_name<<std::endl;
    if (this != &copy) {
        _name = copy._name;
        _hp = copy._hp;
        _energyPoints = copy._energyPoints;
        _attackDamage = copy._attackDamage;
    }
    return *this;
}
ClapTrap::~ClapTrap() {
    std::cout<<"ClapTrap destructor called for "<<_name<<std::endl;
}

void ClapTrap::attack(const std::string& target){
    if (_hp < 1 || _energyPoints < 1)
    {
        std::cout<<"ClapTrap "<<_name<<" cannot attack. No hit points or energy points left!"<<std::endl;
        return;
    }
    _energyPoints--;
    std::cout<<"ClapTrap "<<_name<<" attacks "<<target<<", causing "<<_attackDamage<<" points of damage!"<<std::endl;
}

void ClapTrap::takeDamage(unsigned int amount){
    if (_hp > 0)
	{
		std::cout<<"ClapTrap "<<_name<<" took "<< amount<<" point(s) of damage!";
		_hp -= amount;
        if (_hp >= 0)
            std::cout<<" Remaining HP:  "<<_hp<<std::endl;
	}
	else
		std::cout<<"STOP! ClapTrap "<<_name <<" is already dead XP";
	if (_hp <= 0)
    {
		_hp = 0;
        std::cout<<" Remaining HP:  "<<_hp<<std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount){
    if (_hp < 1){
        std::cout<<"ClapTrap "<<_name<<" is dead!!"<<std::endl;
        return;
    }
    if (_energyPoints < 1){
        std::cout<<"ClapTrap "<<_name<<" has no energy points!"<<std::endl;
        return;
    }
    _hp += amount;
    _energyPoints--;
    std::cout<<"ClapTrap "<<_name<<" repairs itself, regaining "<<amount<<" hit points! HP now: "<<_hp<<std::endl;
}

int ClapTrap::getAttackDamage() const {
    return _attackDamage;
}

void ClapTrap::setAttackDamage(int amount) {
    _attackDamage = amount;
}

std::string ClapTrap::getName() const {
    return _name;
}