/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfernan3 <dfernan3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:30:59 by dfernan3          #+#    #+#             */
/*   Updated: 2025/07/16 15:51:52 by dfernan3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed(){
    _fixedPointValue = 0;
    std::cout<<"Default constructor called"<<std::endl;
}

Fixed::Fixed(const Fixed &copy) {
    std::cout<<"Copy constructor called"<<std::endl;
    *this = copy;
}

Fixed& Fixed::operator = (const Fixed &copy) {
    std::cout<<"Copy assignment operator called"<<std::endl;
    if (this != &copy)
        _fixedPointValue = copy.getRawBits();
    return *this;
}

Fixed::~Fixed() {
    std::cout<<"Destructor called"<<std::endl;
}

int Fixed::getRawBits(void) const {
    std::cout<<"getRawBits member function called"<<std::endl;
    return _fixedPointValue;
}

void Fixed::setRawBits(int const raw){
    _fixedPointValue = raw;
}