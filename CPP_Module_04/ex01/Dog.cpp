/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfernan3 <dfernan3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 15:37:22 by dfernan3          #+#    #+#             */
/*   Updated: 2025/09/02 15:38:57 by dfernan3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal() {
    type = "Dog";
    brain = new Brain();
    std::cout << "Dog created" << std::endl;
}

Dog::Dog(const Dog& copy) : Animal(copy) {
    type = copy.type;
    brain = new Brain(*copy.brain);
    std::cout << "Dog copied" << std::endl;
}

Dog& Dog::operator=(const Dog& copy) {
    std::cout << "Dog assigned" << std::endl;
    if (this != &copy) {
        Animal::operator=(copy);
        type = copy.type;
        if (brain)
            delete brain;
        brain = new Brain(*copy.brain);
    }
    return *this;
}

Dog::~Dog() {
    delete brain;
    std::cout << "Dog destroyed" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Woof! Woof!" << std::endl;
}

Brain* Dog::getBrain() const {
    return brain;
}