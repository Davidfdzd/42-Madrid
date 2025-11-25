/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfernan3 <dfernan3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 15:44:42 by dfernan3          #+#    #+#             */
/*   Updated: 2025/09/02 16:57:24 by dfernan3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>

Character::Character(std::string const & n) : name(n) {
    for (int i = 0; i < 4; i++)
        inventory[i] = NULL;
}

Character::Character(const Character& copy) : name(copy.name) {
    for (int i = 0; i < 4; i++) {
        if (copy.inventory[i] != NULL)
            inventory[i] = copy.inventory[i]->clone();
        else
            inventory[i] = NULL;
    }
}

Character& Character::operator=(const Character& copy) {
    if (this != &copy) {
        name = copy.name;
        for (int i = 0; i < 4; i++) {
            if (inventory[i]) {
                delete inventory[i];
                inventory[i] = NULL;
            }
            if (copy.inventory[i])
                inventory[i] = copy.inventory[i]->clone();
        }
    }
    return *this;
}

Character::~Character() {
    for (int i = 0; i < 4; i++)
        if (inventory[i])
            delete inventory[i];
}

std::string const & Character::getName() const {
    return name;
}

void Character::equip(AMateria* m) {
    if (!m) 
        return;
    for (int i = 0; i < 4; i++) {
        if (!inventory[i]) {
            inventory[i] = m;
            return;
        }
    }
}

void Character::unequip(int idx) {
    if (idx < 0 || idx >= 4) return;
    inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
    if (idx < 0 || idx >= 4 || !inventory[idx]) return;
    inventory[idx]->use(target);
}