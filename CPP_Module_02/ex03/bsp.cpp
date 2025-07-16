/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfernan3 <dfernan3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:45:26 by dfernan3          #+#    #+#             */
/*   Updated: 2025/07/16 14:45:33 by dfernan3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

float getArea(Point const& a, Point const& b, Point const& c){
    Fixed result;
    Fixed a1 = a.getX() * (b.getY() - c.getY());
    Fixed b1 = b.getX() * (c.getY() - a.getY());
    Fixed c1 = c.getX() * (a.getY() - b.getY());
    
    result = (a1 + b1 + c1);

    if (result < 0)
        result = result * (-1);
    result = result / 2;
    float resultF = result.toFloat();
    return resultF; 
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    float areaABC = getArea(a, b, c);
    float areaAPC = getArea(a, point, c);
    float areaPBC = getArea(point, b, c);
    float areaABP = getArea(a, b, point);
    float total;
    
    total = areaABP + areaPBC + areaAPC;
    if (total > areaABC)
        return false;
    if (roundf(areaABP) == 0 || roundf(areaPBC) == 0 || roundf(areaAPC) == 0)
        return false;
    
    return (true);
}