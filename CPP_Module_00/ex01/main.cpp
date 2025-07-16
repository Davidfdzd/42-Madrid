/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfernan3 <dfernan3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 12:36:13 by dfernan3          #+#    #+#             */
/*   Updated: 2025/06/24 15:26:22 by dfernan3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(){
    PhoneBook Phonebook;
    std::string str;
    
    while(true)
    {
        std::cout<<"Enter a command: ";
        if(!std::getline(std::cin, str))
        {
            std::cout<<std::endl;
            std::cout<<GREY<<"Exiting program..."<<RESET<<std::endl;
            break;
        }
        if (str == "EXIT")
            break;
        else if(str == "ADD")
            Phonebook.addContact();
        else if(str == "SEARCH")
            Phonebook.searchContact();
        else
            std::cout<<RED<<"Invalid command. Must be ADD, SEARCH or EXIT."<<RESET<<std::endl;
    }
    return 0;
}