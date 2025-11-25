/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfernan3 <dfernan3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 15:44:13 by dfernan3          #+#    #+#             */
/*   Updated: 2025/09/02 15:46:47 by dfernan3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria(std::string const & t) : type(t) {}

AMateria::~AMateria() {}

std::string const & AMateria::getType() const { return type; }

void AMateria::use(ICharacter& target) {
    (void)target;
}