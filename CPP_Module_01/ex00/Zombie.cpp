/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfernan3 <dfernan3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 15:18:15 by dfernan3          #+#    #+#             */
/*   Updated: 2025/07/09 15:24:01 by dfernan3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
    _name = name;
}

Zombie::~Zombie()
{
    std::cout<<"Zombie "<<_name<<" has been destroyed"<<std::endl;
}

void Zombie::announce(void) 
{
    std::cout<<_name<<": BraiiiiiiinnnzzzZ..."<<std::endl;
}