/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfernan3 <dfernan3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 14:43:47 by dfernan3          #+#    #+#             */
/*   Updated: 2025/08/06 14:47:52 by dfernan3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("ScavTrap"){
    _hp = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout<<"ScavTrap "<<_name<<" constructor called!\n";
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name){
    _hp = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout<<"ScavTrap "<<_name<<" constructor called!\n";
}

ScavTrap::ScavTrap(const ScavTrap& copy) : ClapTrap(copy){
    std::cout<<"ScavTrap copy constructor called for "<<_name<<std::endl;
    *this = copy;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& copy) {
    std::cout<<"Copy assignment operator called!\n";
    if (this != &copy) {
        _name = copy._name;
        _hp = copy._hp;
        _energyPoints = copy._energyPoints;
        _attackDamage = copy._attackDamage;
    }
    return *this;
}

ScavTrap::~ScavTrap(){
    std::cout<<"ScavTrap "<<_name<<" destructor called!\n";
}

void ScavTrap::attack(const std::string& target){
    std::cout<<"ScavTrap "<<_name<<" attacks "<<target<<", causing "<<_attackDamage<<" points of damage!\n";
}

void ScavTrap::guardGate(){
    std::cout<<"ScavTrap "<<_name<<" is now in Gate keeper mode!\n";
}