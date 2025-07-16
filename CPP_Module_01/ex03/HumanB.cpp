/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfernan3 <dfernan3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 15:38:15 by dfernan3          #+#    #+#             */
/*   Updated: 2025/07/09 15:40:50 by dfernan3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string& name) : _name(name), _weapon(NULL) {}

HumanB::~HumanB(void){}

void HumanB::setWeapon(Weapon& weapon){
    _weapon = &weapon;
}

void HumanB::attack() const{
    if (_weapon)
        std::cout<<_name<<" attacks with their "<<_weapon->getType()<<std::endl;
    else
        std::cout<<_name<<" has no weapon to attack with "<<std::endl;
}