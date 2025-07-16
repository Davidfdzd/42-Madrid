/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfernan3 <dfernan3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:35:45 by dfernan3          #+#    #+#             */
/*   Updated: 2025/07/16 15:53:29 by dfernan3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed() : _fixedPointValue(0) {}

Fixed::Fixed(const Fixed& copy) {
    *this = copy;
}

Fixed::Fixed(const int n){
    _fixedPointValue = n << _fractionalBits;
}

Fixed::Fixed(const float f){
    _fixedPointValue = roundf(f * (1 <<_fractionalBits));
}

Fixed& Fixed::operator = (const Fixed &copy) {
    if (this != &copy)
        _fixedPointValue = copy.getRawBits();
    return *this;
}

Fixed::~Fixed() {}

bool Fixed::operator>(const Fixed& fixed) const {
    return(_fixedPointValue > fixed._fixedPointValue);
}

bool Fixed::operator<(const Fixed& fixed) const {
    return(_fixedPointValue < fixed._fixedPointValue);
}

bool Fixed::operator>=(const Fixed& fixed) const {
    return(_fixedPointValue >= fixed._fixedPointValue);
}

bool Fixed::operator<=(const Fixed& fixed) const {
    return(_fixedPointValue <= fixed._fixedPointValue);
}

bool Fixed::operator==(const Fixed& fixed) const {
    return(_fixedPointValue == fixed._fixedPointValue);
}

bool Fixed::operator!=(const Fixed& fixed) const {
    return(_fixedPointValue != fixed._fixedPointValue);
}

Fixed Fixed::operator+(const Fixed& fixed) const {
    Fixed result;
    result.setRawBits(_fixedPointValue + fixed._fixedPointValue);
    return result;
}

Fixed Fixed::operator-(const Fixed& fixed) const {
    Fixed result;
    result.setRawBits(_fixedPointValue - fixed._fixedPointValue);
    return result;
}

Fixed Fixed::operator*(const Fixed& fixed) const {
    Fixed result;
    result.setRawBits((_fixedPointValue * fixed._fixedPointValue) >> _fractionalBits);
    return result;
}

Fixed Fixed::operator/(const Fixed& fixed) const {
    Fixed result;
    result.setRawBits((_fixedPointValue << _fractionalBits) / fixed._fixedPointValue);
    return result;
}

Fixed& Fixed::operator++() {
    ++_fixedPointValue;
    return (*this);
}

Fixed& Fixed::operator--()  {
    --_fixedPointValue;
    return (*this);
}

Fixed Fixed::operator++(int)  {
    Fixed tmp(*this);
    _fixedPointValue++;
    return tmp;
}

Fixed Fixed::operator--(int)  {
    Fixed tmp(*this);
    _fixedPointValue--;
    return tmp;
}

int Fixed::toInt(void) const {
    return _fixedPointValue >> _fractionalBits;
}

float Fixed::toFloat(void) const {
    return (float)_fixedPointValue / (1 << _fractionalBits);
}

Fixed& Fixed::min(Fixed &a, Fixed &b) {
    if (a._fixedPointValue < b._fixedPointValue)
        return a;
    else
        return b;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b) {
    if (a._fixedPointValue < b._fixedPointValue)
        return a;
    else
        return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
    if (a._fixedPointValue > b._fixedPointValue)
        return a;
    else
        return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
    if (a._fixedPointValue < b._fixedPointValue)
        return b;
    else
        return a;
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