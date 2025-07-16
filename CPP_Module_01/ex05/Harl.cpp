/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfernan3 <dfernan3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 15:53:19 by dfernan3          #+#    #+#             */
/*   Updated: 2025/07/09 16:03:10 by dfernan3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void Harl::debug(void) {
    std::cout<<"[ DEBUG ]\nI love having extra bacon for my\n7XL-double-cheese-triple-pickle-special-ketchup burger.\nI really do!"<<std::endl;
}

void Harl::info(void) {
    std::cout<<"[ INFO ]\nI cannot believe adding extra bacon costs more money.\nYou didn’t put enough bacon in my burger!\nIf you did, I wouldn’t be asking for more!"<<std::endl;
}

void Harl::warning(void) {
    std::cout<<"[ WARNING ]\nI think I deserve to have some extra bacon for free.\nI’ve been coming for years, whereas you started working\nhere just last month."<<std::endl;
}

void Harl::error(void) {
    std::cout<<"[ ERROR ]\nThis is unacceptable! I want to speak to the manager now."<<std::endl;
}

void Harl::complain(std::string level)
{
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*actions[])( void ) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

    for (int i = 0; i < 4; ++i)
        if (level == levels[i])
        {
            (this->*actions[i])();
            return;
        }
    std::cout<<"Level not recognized"<<std::endl;
}