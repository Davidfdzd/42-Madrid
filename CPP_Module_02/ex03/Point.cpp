/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfernan3 <dfernan3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:37:13 by dfernan3          #+#    #+#             */
/*   Updated: 2025/07/16 15:57:08 by dfernan3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point(const float x, const float y) : _x(x), _y(y) {}

Point::Point(const Point& copy) : _x(copy._x), _y(copy._y) {}

Point& Point::operator = (const Point& copy) {
    if (this != &copy)
    {
        (Fixed)this->_x = copy._x;
        (Fixed)this->_y = copy._y;
    }
    return *this;
}

Point::~Point() {}

Fixed Point::getX() const {
    return _x;
}

Fixed Point::getY() const {
    return _y;
}