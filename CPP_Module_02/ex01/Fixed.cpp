/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfernan3 <dfernan3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:32:47 by dfernan3          #+#    #+#             */
/*   Updated: 2025/07/16 15:46:38 by dfernan3         ###   ########.fr       */
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

Fixed::Fixed(const int n){
    std::cout<<"Int constructor called"<<std::endl;
    _fixedPointValue = n << _fractionalBits;
}

Fixed::Fixed(const float f){
    std::cout<<"Float constructor called"<<std::endl;
    _fixedPointValue = roundf(f * (1 <<_fractionalBits));
}

Fixed& Fixed::operator=(const Fixed& copy) {
    std::cout<<"Copy assignment operator called"<<std::endl;
    if (this != &copy)
        _fixedPointValue = copy.getRawBits();
    return *this;
}

Fixed::~Fixed() {
    std::cout<<"Destructor called"<<std::endl;
}

int Fixed::toInt(void) const {
    return _fixedPointValue >> _fractionalBits;
}

float Fixed::toFloat(void) const {
    return (float)_fixedPointValue / (1 << _fractionalBits);
}

int Fixed::getRawBits(void) const {
    return _fixedPointValue;
}

void Fixed::setRawBits(int const raw){
    _fixedPointValue = raw;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
    out << fixed.toFloat();
    return out;
}
