/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfernan3 <dfernan3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 15:33:46 by dfernan3          #+#    #+#             */
/*   Updated: 2025/09/02 15:35:21 by dfernan3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    std::cout << "=== Correct Polymorphism ===" << std::endl;
    const Animal* animal = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    std::cout << dog->getType() << std::endl;
    std::cout << cat->getType() << std::endl;

    cat->makeSound();
    dog->makeSound();
    animal->makeSound();

    delete animal;
    delete dog;
    delete cat;

    std::cout << "\n=== Wrong Polymorphism ===" << std::endl;
    const WrongAnimal* wAnimal = new WrongAnimal();
    const WrongAnimal* wCat = new WrongCat();

    std::cout << wCat->getType() << std::endl;
    wCat->makeSound();
    wAnimal->makeSound();

    delete wAnimal;
    delete wCat;

    return 0;
}