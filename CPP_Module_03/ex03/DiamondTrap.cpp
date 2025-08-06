/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfernan3 <dfernan3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 14:44:35 by dfernan3          #+#    #+#             */
/*   Updated: 2025/08/06 14:45:54 by dfernan3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap(), _Name(name) {
    _hp = FragTrap::_hp;
    _energyPoints = ScavTrap::_energyPoints;
    _attackDamage = FragTrap::_attackDamage;
    std::cout<<"DiamondTrap "<<_Name<<" constructed."<<std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const& copy) : ClapTrap(copy), ScavTrap(copy), FragTrap(copy), _Name(copy._Name){
    std::cout<<"DiamondTrap copy constructor called for "<<_Name<<std::endl;
    *this = copy;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& copy) {
    std::cout<<"Copy assignment operator called!\n";
    if (this != &copy) {
        _Name = copy._Name;
        _name = copy._name;
        _hp = copy._hp;
        _energyPoints = copy._energyPoints;
        _attackDamage = copy._attackDamage;
    }
    return *this;
}

DiamondTrap::~DiamondTrap() {
    std::cout<<"DiamondTrap "<<_Name<<" destructed."<<std::endl;
}

void DiamondTrap::whoAmI(void){
    std::cout<<_Name<<" exclaims: I am "<<_name + "!"<<std::endl;
}
    
void DiamondTrap::attack(const std::string& target){
    ScavTrap::attack(target);
}