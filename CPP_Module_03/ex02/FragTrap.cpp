/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfernan3 <dfernan3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 14:44:23 by dfernan3          #+#    #+#             */
/*   Updated: 2025/08/06 14:48:06 by dfernan3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("FragTrap") {
    _hp = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout<<"FragTrap "<<_name<<" constructed."<<std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
    _hp = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout<<"FragTrap "<<_name<<" constructed."<<std::endl;
}

FragTrap::FragTrap(FragTrap const& copy) : ClapTrap(copy){
    std::cout<<"FragTrap copy constructor called for "<<_name<<std::endl;
    *this = copy;
}

FragTrap& FragTrap::operator=(const FragTrap& copy) {
    std::cout<<"Copy assignment operator called!\n";
    if (this != &copy) {
        _name = copy._name;
        _hp = copy._hp;
        _energyPoints = copy._energyPoints;
        _attackDamage = copy._attackDamage;
    }
    return *this;
}

FragTrap::~FragTrap() {
    std::cout<<"FragTrap "<<_name<<" destructed."<<std::endl;
}

void FragTrap::highFivesGuys(void) {
    std::cout<<"FragTrap "<<_name<<" requests high fives! ✋😄"<<std::endl;
}