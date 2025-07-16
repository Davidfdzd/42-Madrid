/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfernan3 <dfernan3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 12:35:34 by dfernan3          #+#    #+#             */
/*   Updated: 2025/06/24 15:26:05 by dfernan3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(){
}

Contact::~Contact(){
}

void Contact::setFirst_name(std::string str){
    first_name = str;
}

void Contact::setLast_name(const std::string str){
    last_name = str;
}
void Contact::setNickname(const std::string str){
    nickname = str;
}
void Contact::setPhone_number(const std::string str){
    phone_number = str;
}
void Contact::setDarkest_secret(const std::string str){
    darkest_secret = str;
}

std::string Contact::getFirst_name() const{
    return first_name;
}

std::string Contact::getLast_name() const{
    return last_name;
}

std::string Contact::getNickname() const{
    return nickname;
}

std::string Contact::getPhone_number() const{
    return phone_number;
}

std::string Contact::getDarkest_secret() const{
    return darkest_secret;
}

void Contact::displayContact() const{
    std::cout<<GREY<<"First Name: "<<RESET<<first_name<<std::endl;
    std::cout<<GREY<<"Last Name: "<<RESET<<last_name<<std::endl;
    std::cout<<GREY<<"Nickname: "<<RESET<<nickname<<std::endl;
    std::cout<<GREY<<"Darkest Secret: "<<RESET<<darkest_secret<<std::endl;
}