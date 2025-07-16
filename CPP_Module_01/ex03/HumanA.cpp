/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfernan3 <dfernan3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 15:38:02 by dfernan3          #+#    #+#             */
/*   Updated: 2025/07/09 15:39:24 by dfernan3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(const std::string& name, Weapon& weapon) : _name(name), _weapon(weapon) {}

HumanA::~HumanA(void) {}

void HumanA::attack() const{
    std::cout<<_name<<" attacks with their "<<_weapon.getType()<<std::endl;
}