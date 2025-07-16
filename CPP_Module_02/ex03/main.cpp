/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfernan3 <dfernan3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:36:52 by dfernan3          #+#    #+#             */
/*   Updated: 2025/07/16 14:47:50 by dfernan3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main()
{
    Point a(0, 0);
    Point b(4, 0);
    Point c(0, 3);

    Point inside(1, 1);
    Point outside(5, 5);
    Point inVertex(0, 0);


    std::cout<<"Inside "<<bsp(a, b, c, inside)<<std::endl;
    std::cout<<"Outside: "<<bsp(a, b, c, outside)<<std::endl;
    std::cout<<"In a vertex: "<<bsp(a, b, c, inVertex)<<std::endl;

    return 0;
}