/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfernan3 <dfernan3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 15:40:05 by dfernan3          #+#    #+#             */
/*   Updated: 2025/09/02 15:42:26 by dfernan3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Brain created" << std::endl;
}

Brain::Brain(const Brain& copy) {
    std::cout << "Brain copied" << std::endl;
    for (int i = 0; i < 100; i++)
        this->ideas[i] = copy.ideas[i];
}

Brain& Brain::operator=(const Brain& copy) {
    std::cout << "Brain assigned" << std::endl;
    if (this != &copy) {
        for (int i = 0; i < 100; i++)
            this->ideas[i] = copy.ideas[i];
    }
    return *this;
}

Brain::~Brain() {
    std::cout << "Brain destroyed" << std::endl;
}

void Brain::setIdea(int index, const std::string& idea) {
    if (index >= 0 && index < 100)
        ideas[index] = idea;
}

std::string Brain::getIdea(int index) const {
    if (index >= 0 && index < 100)
        return ideas[index];
    return "";
}