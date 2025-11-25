/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfernan3 <dfernan3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 15:40:44 by dfernan3          #+#    #+#             */
/*   Updated: 2025/09/02 15:42:53 by dfernan3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    std::cout << "======== Basic test ========" << std::endl;
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    delete j;
    delete i;

    std::cout << "\n======== Array of Animals ========" << std::endl;
    const int size = 4;
    Animal* animals[size];

    for (int k = 0; k < size; ++k) {
        if (k < size / 2)
            animals[k] = new Dog();
        else
            animals[k] = new Cat();
    }

    std::cout << "\n--- Deleting array ---" << std::endl;
    for (int k = 0; k < size; ++k)
        delete animals[k];

    std::cout << "\n======== Deep Copy test ========" << std::endl;
    Dog dog1;
    dog1.getBrain()->setIdea(0, "Chase the cat");
    dog1.getBrain()->setIdea(1, "Eat food");

    Dog dog2 = dog1;

    std::cout << "Dog1 idea[0]: " << dog1.getBrain()->getIdea(0) << std::endl;
    std::cout << "Dog2 idea[0]: " << dog2.getBrain()->getIdea(0) << std::endl;

    std::cout << "\n--- Modifying Dog2's brain ---" << std::endl;
    dog2.getBrain()->setIdea(0, "Sleep all day");

    std::cout << "Dog1 idea[0]: " << dog1.getBrain()->getIdea(0) << std::endl;
    std::cout << "Dog2 idea[0]: " << dog2.getBrain()->getIdea(0) << std::endl;

    std::cout << "\n======== Assignment Operator test ========" << std::endl;
    Cat cat1;
    cat1.getBrain()->setIdea(0, "Climb the tree");

    Cat cat2;
    cat2 = cat1;

    std::cout << "Cat1 idea[0]: " << cat1.getBrain()->getIdea(0) << std::endl;
    std::cout << "Cat2 idea[0]: " << cat2.getBrain()->getIdea(0) << std::endl;

    return 0;
}