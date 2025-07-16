/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfernan3 <dfernan3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 12:21:19 by dfernan3          #+#    #+#             */
/*   Updated: 2025/06/24 16:55:59 by dfernan3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av)
{
    int i;
    int j;

    if (ac < 2)
        std::cout<<"* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    i = 0;
    while(ac > 1 && av && av[++i])
    {
        j = -1;
        while(av[i][++j])
            std::cout<<(char)std::toupper(av[i][j]);
    }
    std::cout<<std::endl;
    return (0);
}