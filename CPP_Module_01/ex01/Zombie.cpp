/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfernan3 <dfernan3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 15:25:36 by dfernan3          #+#    #+#             */
/*   Updated: 2025/07/09 15:31:38 by dfernan3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
}

Zombie::~Zombie()
{
    std::cout<<_name<<": Aaaargh... I am dying... again..."<<std::endl;
}

void Zombie::announce(void)const
{
    std::cout<<_name<<": BraiiiiiiinnnzzzZ..."<<std::endl;
}

void Zombie::setName(std::string name)
{
    _name = name;
}