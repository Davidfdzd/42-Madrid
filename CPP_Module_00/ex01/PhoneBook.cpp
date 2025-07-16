/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfernan3 <dfernan3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 12:37:58 by dfernan3          #+#    #+#             */
/*   Updated: 2025/06/24 17:27:16 by dfernan3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"


PhoneBook::PhoneBook(){
    number_contacts = 0;
    std::cout<<GREEN<<"Welcome! Your phonebook is ready to store up to 8 contacts."<<RESET<<std::endl;
}

PhoneBook::~PhoneBook(){
    std::cout<<GREEN<<"Goodbye!!"<<RESET<<std::endl;
}

std::string formatField(const std::string& str) {
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    else
        return std::string(10 - str.length(), ' ') + str;
}

bool isOnlyDigits(const std::string& str) {
    int i = 0;
    while (i < static_cast<int>(str.length())) {
        if (!std::isdigit(static_cast<unsigned char>(str[i])))
            return false;
        i++;
    }
    return true;
}

void PhoneBook::addContact(){
    std::string str;

    if (number_contacts > 7)
    {
        std::cout<<RED<<"Phonebook is full!!"<<RESET<<std::endl;
        std::cout<<BLUE<<"Warning: overwriting info about "<<RESET<<contacts[number_contacts % 8].getFirst_name()<<std::endl;
    }      
    while(str == "")
    {
        std::cout << "Enter a first name: ";
        if (!std::getline(std::cin, str))
        {
            std::cout<<std::endl;
            std::cout<<GREY<<"Exiting program..."<<RESET<<std::endl;
            exit(0);
        }
        else
            contacts[number_contacts % 8].setFirst_name(str);
    }
    str = "";
    while(str == "")
    {
        std::cout << "Enter a last name: ";
        if (!std::getline(std::cin, str))
        {
            std::cout<<std::endl;
            std::cout<<GREY<<"Exiting program..."<<RESET<<std::endl;
            exit(0);
        }
        else
            contacts[number_contacts % 8].setLast_name(str);
    }
    str = "";
    while(str == "")
    {
        std::cout << "Enter a nickname: ";
        if (!std::getline(std::cin, str))
        {
            std::cout<<std::endl;
            std::cout<<GREY<<"Exiting program..."<<RESET<<std::endl;
            exit(0);
        }
        else
            contacts[number_contacts % 8].setNickname(str);
    }
    str = "";
    while(str == "")
    {
        std::cout << "Enter a phone number: ";
        if (!std::getline(std::cin, str))
        {
            std::cout<<std::endl;
            std::cout<<GREY<<"Exiting program..."<<RESET<<std::endl;
            exit(0);
        }
        if (!isOnlyDigits(str)) {
            std::cout<<RED<<"Invalid input. Please enter only digits."<<RESET<<std::endl;
            str = "";
        }
        else
            contacts[number_contacts % 8].setPhone_number(str);
    }
    str = "";
    while (str == "")
    {
        std::cout << "Enter a darkest secret: ";
        if (!std::getline(std::cin, str))
        {
            std::cout << std::endl;
            std::cout << GREY << "Exiting program..." << RESET << std::endl;
            exit(0);
        }
    }
    contacts[number_contacts % 8].setDarkest_secret(str);
    std::cout << GREEN << "New contact successfully added to phonebook!!" << RESET << std::endl;
    number_contacts++;
}

void PhoneBook::searchContact() const{
    int i;
    std::string index;

    std::cout<<" ------------------------------------------- "<<std::endl;
    std::cout<<"|     Index|First Name| Last Name|  Nickname|"<<std::endl;
    std::cout<<"|----------|----------|----------|----------|" << std::endl;
    i = 0;
    while (i < 8)
    {
        std::cout << "|" << std::setw(10) << i + 1 << "|"
          << formatField(contacts[i].getFirst_name()) << "|"
          << formatField(contacts[i].getLast_name()) << "|"
          << formatField(contacts[i].getNickname()) << "|"
          << std::endl;
        i++;
    }
    std::cout<<" ------------------------------------------- "<<std::endl;
    while (true)
    {
        std::cout<<BLUE<< "Enter the index of the contact you want to see: " << RESET;
        if (!std::getline(std::cin, index))
        {
            std::cout << std::endl;
            std::cout << GREY << "Exiting program..." << RESET << std::endl;
            exit(0);
        }
        if (index.size() == 1 && index[0] >= '1' && index[0] <= '8')
        {
            i = index[0] - '0' - 1;
            if (!contacts[i].getFirst_name().empty())
            {
                contacts[i].displayContact();
                break;
            }
            else
            {
                std::cout<<GREY<<"This contact is empty."<<RESET<<std::endl;
                break;
            }
        }
        else if (!index.empty())
            std::cout<<RED<<"Invalid index!! Must be between 1 and 8"<<RESET<<std::endl;
    }
}