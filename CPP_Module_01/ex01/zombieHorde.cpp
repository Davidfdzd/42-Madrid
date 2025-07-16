/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfernan3 <dfernan3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 15:25:03 by dfernan3          #+#    #+#             */
/*   Updated: 2025/07/09 15:27:32 by dfernan3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
    if (N < 1)
    {
        std::cout<<"A Horde can not contain less than 1 Zombie"<<std::endl;
		return (NULL);
    }
    Zombie *horde = new Zombie[N];
    
    for (int i = 0; i < N; i++)
        horde[i].setName(name);
    
    return horde;
}