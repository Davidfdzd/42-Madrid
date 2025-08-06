/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfernan3 <dfernan3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 14:43:58 by dfernan3          #+#    #+#             */
/*   Updated: 2025/08/06 14:51:27 by dfernan3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap clap1("Luffy");
    ClapTrap clap2("Kaido");

    clap1.setAttackDamage(5);
    clap1.attack(clap2.getName());

    clap2.takeDamage(clap1.getAttackDamage());

    clap2.beRepaired(3);

    clap1.attack(clap2.getName());
    clap2.takeDamage(clap1.getAttackDamage());
    clap1.attack(clap2.getName());
    clap2.takeDamage(clap1.getAttackDamage());
    clap1.attack(clap2.getName());
    clap2.takeDamage(clap1.getAttackDamage());
    clap2.beRepaired(2);

    clap1.beRepaired(5);
    clap2.beRepaired(5);

    return 0;
}