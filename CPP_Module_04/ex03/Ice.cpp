/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfernan3 <dfernan3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 15:45:55 by dfernan3          #+#    #+#             */
/*   Updated: 2025/09/02 16:51:59 by dfernan3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include <iostream>

Ice::Ice() : AMateria("ice") {}

Ice::Ice(const Ice& copy) : AMateria(copy) {}

Ice& Ice::operator=(const Ice& copy) {
    AMateria::operator=(copy);
    return *this;
}
Ice::~Ice() {}

AMateria* Ice::clone() const { return new Ice(*this); }

void Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}