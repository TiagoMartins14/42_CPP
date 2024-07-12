/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiago <tiago@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 17:21:48 by tiaferna          #+#    #+#             */
/*   Updated: 2024/07/12 23:04:14 by tiago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "Fixed.hpp"
#include "Point.hpp"

// static Fixed get_coordinate_x(Fixed &point)
// {
//     std::cout << "x coordinate: ";
//     std::cin >> point;
//     return point;
// }

// static Fixed get_coordinate_y(Fixed &point)
// {
//     std::cout << "y coordinate: ";
//     std::cin >> point;
//     return point;
// }

static Fixed triangleArea(Fixed x1, Fixed y1, Fixed x2, Fixed y2, Fixed x3, Fixed y3)
{
    Fixed Area = (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0f;
    if (Area.getRawBits() < 0)
        Area.setRawBits(std::abs(Area.getRawBits()));
    return Area;
}

void BSP(void)
{
    // std::cout << "vertice A ";
    // Fixed a_x = get_coordinate_x(a_x);
    // std::cout << "vertice A ";
    // Fixed a_y = get_coordinate_y(a_y);
    // std::cout << "vertice B ";
    // Fixed b_x = get_coordinate_x(b_x);
    // std::cout << "vertice B ";
    // Fixed b_y = get_coordinate_y(b_y);
    // std::cout << "vertice C ";
    // Fixed c_x = get_coordinate_x(c_x);
    // std::cout << "vertice C ";
    // Fixed c_y = get_coordinate_y(c_y);
    // std::cout << "Fixed point ";
    // Fixed fp_x = get_coordinate_x(fp_x);
    // std::cout << "Fixed point ";
    // Fixed fp_y = get_coordinate_y(fp_y);
    Fixed a_x = 0.0f;
    Fixed a_y = 0.0f;
    Fixed b_x = 10.0f;
    Fixed b_y = 30.0f;
    Fixed c_x = 20.0f;
    Fixed c_y = 0.0f;
    Fixed fp_x = 10.0f;
    Fixed fp_y = 13.0f;
    // Point a(a_x, a_y);
    // Point b(b_x, b_y);
    // Point c(c_x, c_y);
    // Point fixedPoint(fp_x, fp_y);
    // Point a(0, 0);
    // Point b(10, 30);
    // Point c(20, 0);
    // Point fixedPoint(10, 15);
    // Fixed A = triangleArea(a_x, a_y, b_x, b_y, c_x, c_y);
    // Fixed PAB = triangleArea(fp_x, fp_y, a_x, a_y, c_x, c_y);
    // Fixed PBC = triangleArea(fp_x, fp_y, b_x, b_y, c_x, c_y);
    // Fixed PAC = triangleArea(fp_x, fp_y, a_x, a_y, c_x, c_y);
    Fixed A = triangleArea(a_x, a_y, b_x, b_y, c_x, c_y);
    Fixed PAB = triangleArea(a_x, a_y, b_x, b_y, fp_x, fp_y);
    Fixed PBC = triangleArea(fp_x, fp_y, b_x, b_y, c_x, c_y);
    Fixed PAC = triangleArea(a_x, a_y, fp_x, fp_y, c_x, c_y);
    std::cout << A << std::endl;
    std::cout << PAB << std::endl;
    std::cout << PBC << std::endl;
    std::cout << PAC << std::endl;
    // if (A == 0.0f || PAB == 0.0f || PBC == 0.0f || PAC == 0.0f)
    //     std::cout << "The fixed point is outside of the triagle" << std::endl;
    /* else  */ if (A == PAB + PBC + PAC)
        std::cout << "The fixed point is inside the triangle!" << std::endl;
    else
        std::cout << "The fixed point is outside of the triagle" << std::endl;
}

int main(int argc, char **argv)
{
    (void)argv;
    if (argc == 1)
        BSP();
    else
        std::cout << "Error: Input: ./BSP" << std::endl;
}
