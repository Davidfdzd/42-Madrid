/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfernan3 <dfernan3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 15:30:49 by dfernan3          #+#    #+#             */
/*   Updated: 2025/09/02 15:31:11 by dfernan3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
    type = "Cat";
    std::cout << "Cat created" << std::endl;
}

Cat::Cat(const Cat& copy) : Animal(copy) {
    std::cout << "Cat copied" << std::endl;
}

Cat& Cat::operator=(const Cat& copy) {
    Animal::operator=(copy);
    std::cout << "Cat assigned" << std::endl;
    return *this;
}

Cat::~Cat() {
    std::cout << "Cat destroyed" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "Meow! Meow!" << std::endl;
}