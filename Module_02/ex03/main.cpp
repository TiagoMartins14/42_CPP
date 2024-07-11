/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiago <tiago@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 17:21:48 by tiaferna          #+#    #+#             */
/*   Updated: 2024/07/11 23:14:16 by tiago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

static Fixed get_coordinate_x(Fixed &point)
{
    std::cout << "x coordinate: ";
    std::cin >> point;
    return point;
}

static Fixed get_coordinate_y(Fixed &point)
{
    std::cout << "y coordinate: ";
    std::cin >> point;
    return point;
}

void BSP(void)
{
    std::cout << "vertice A ";
    Fixed a_x = get_coordinate_x(a_x);
    std::cout << "vertice A ";
    Fixed a_y = get_coordinate_y(a_y);
    std::cout << "vertice B ";
    Fixed b_x = get_coordinate_x(b_x);
    std::cout << "vertice B ";
    Fixed b_y = get_coordinate_y(b_y);
    std::cout << "vertice C ";
    Fixed c_x = get_coordinate_x(c_x);
    std::cout << "vertice C ";
    Fixed c_y = get_coordinate_y(c_y);
    std::cout << "Fixed point ";
    Fixed fp_x = get_coordinate_x(fp_x);
    std::cout << "Fixed point ";
    Fixed fp_y = get_coordinate_y(fp_y);
    Point a(a_x, a_y);
    Point b(b_x, b_y);
    Point c(c_x, c_y);
    Point fixedPoint(fp_x, fp_y);
    Fixed A = (a_x * (b_y - c_y) + b_x * (c_y - a_y) + c_x * (a_y - b_y)) / 2;
    Fixed PAB = (a_x * (b_y - fp_y) + b_x * (fp_y - a_y) + fp_x * (a_y - b_y)) / 2;
    Fixed PBC = (fp_x * (b_y - c_y) + b_x * (c_y - fp_y) + c_x * (fp_y - b_y)) / 2;
    Fixed PAC = (a_x * (fp_y - c_y) + fp_x * (c_y - a_y) + c_x * (a_y - fp_y)) / 2;
    std::cout << A << std::endl;
    std::cout << PAB << std::endl;
    std::cout << PBC << std::endl;
    std::cout << PAC << std::endl;
    if (A == 0.0f || PAB == 0.0f || PBC == 0.0f || PAC == 0.0f)
        std::cout << "The fixed point is outside of the triagle" << std::endl;
    else if (A == PAB + PBC + PAC)
        std::cout << "The fixed point is inside the triangle!" << std::endl;
    else
        std::cout << "The fixed point is outside of the triagle" << std::endl;
}

int main(int argc, char **argv)
{
    (void)argv;
    if (argc == 1)
    {
        BSP();
    }
    else
    {
        std::cout << "Error: Input: ./BSP" << std::endl;
    }
}
