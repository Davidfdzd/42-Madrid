/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfernan3 <dfernan3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 15:37:25 by dfernan3          #+#    #+#             */
/*   Updated: 2025/09/02 15:38:34 by dfernan3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal() {
    type = "Cat";
    brain = new Brain();
    std::cout << "Cat created" << std::endl;
}

Cat::Cat(const Cat& copy) : Animal(copy) {
    type = copy.type;
    brain = new Brain(*copy.brain);
    std::cout << "Cat copied" << std::endl;
}

Cat& Cat::operator=(const Cat& copy) {
    std::cout << "Cat assigned" << std::endl;
    if (this != &copy) {
        Animal::operator=(copy);
        type = copy.type;
        if (brain)
            delete brain;
        brain = new Brain(*copy.brain);
    }
    return *this;
}

Cat::~Cat() {
    delete brain;
    std::cout << "Cat destroyed" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "Meow! Meow!" << std::endl;
}

Brain* Cat::getBrain() const {
    return brain;
}