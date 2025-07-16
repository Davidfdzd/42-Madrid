/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfernan3 <dfernan3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 15:32:23 by dfernan3          #+#    #+#             */
/*   Updated: 2025/07/09 15:35:38 by dfernan3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    std::cout<<"Dirección de str       : "<<&str<<std::endl;
    std::cout<<"Dirección en stringPTR : "<<stringPTR<<std::endl;
    std::cout<<"Dirección en stringREF : "<<&stringREF<<std::endl;
    
    std::cout<<"Valor de str     : "<<str<<std::endl;
    std::cout<<"Valor *stringPTR : "<<*stringPTR<<std::endl;
    std::cout<<"Valor stringREF  : "<<stringREF<<std::endl;

    return (0);
}