/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfernan3 <dfernan3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 15:25:51 by dfernan3          #+#    #+#             */
/*   Updated: 2025/07/09 15:30:36 by dfernan3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    Zombie *horde;
    int N = 5;

    horde = zombieHorde(N, "Foo");
    if (!horde)
    {
        std::cout<<"Error creating the horde"<<std::endl;
        return 1;
    }
    for (int i = 0; i < N; i++)
        horde[i].announce();
    
    delete[] horde;
    return 0;
}