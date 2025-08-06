/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfernan3 <dfernan3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 14:43:58 by dfernan3          #+#    #+#             */
/*   Updated: 2025/08/06 15:19:53 by dfernan3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
    std::cout << "=== ClapTrap Fight ===\n";
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

    std::cout << "\n=== ScavTrap Enters the Battle ===\n";
    ScavTrap scav1("Serena");
    ClapTrap bigMom("Big Mom");

    scav1.attack(bigMom.getName());
    bigMom.takeDamage(scav1.getAttackDamage());
    bigMom.beRepaired(0);

    scav1.takeDamage(30);
    scav1.beRepaired(10);

    std::cout << "\n=== ScavTrap Special Ability ===\n";
    scav1.guardGate();

    std::cout << "\n=== FragTrap Joins the Fight ===\n";
    FragTrap frag1("Franky");

    frag1.attack(scav1.getName());
    scav1.takeDamage(frag1.getAttackDamage());
    frag1.takeDamage(20);
    frag1.beRepaired(15);

    std::cout << "\n=== FragTrap Special Ability ===\n";
    frag1.highFivesGuys();

    std::cout << "\n=== DiamondTrap Appears ===\n";
    DiamondTrap diamond1("Zoro");

    diamond1.attack(clap1.getName());
    clap1.takeDamage(diamond1.getAttackDamage());
    diamond1.takeDamage(40);
    diamond1.beRepaired(20);

    std::cout << "\n=== DiamondTrap Special Identity ===\n";
    diamond1.whoAmI();

    std::cout << "\n=== End of Simulation ===\n";
    return 0;
}