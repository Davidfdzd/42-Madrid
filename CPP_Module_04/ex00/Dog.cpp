/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfernan3 <dfernan3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 15:31:34 by dfernan3          #+#    #+#             */
/*   Updated: 2025/09/02 15:31:40 by dfernan3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
    type = "Dog";
    std::cout << "Dog created" << std::endl;
}

Dog::Dog(const Dog& copy) : Animal(copy) {
    std::cout << "Dog copied" << std::endl;
}

Dog& Dog::operator=(const Dog& copy) {
    Animal::operator=(copy);
    std::cout << "Dog assigned" << std::endl;
    return *this;
}

Dog::~Dog() {
    std::cout << "Dog destroyed" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Woof! Woof!" << std::endl;
}