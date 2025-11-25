/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfernan3 <dfernan3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 15:30:08 by dfernan3          #+#    #+#             */
/*   Updated: 2025/09/02 15:30:20 by dfernan3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal") {
    std::cout << "Animal created" << std::endl;
}

Animal::Animal(const Animal& copy) : type(copy.type) {
    std::cout << "Animal copied" << std::endl;
}

Animal& Animal::operator=(const Animal& copy) {
    if (this != &copy)
        type = copy.type;
    std::cout << "Animal assigned" << std::endl;
    return *this;
}

Animal::~Animal() {
    std::cout << "Animal destroyed" << std::endl;
}

std::string Animal::getType() const {
    return type;
}

void Animal::makeSound() const {
    std::cout << "Some generic animal sound..." << std::endl;
}