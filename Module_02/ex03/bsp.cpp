/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiago <tiago@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 11:48:42 by tiago             #+#    #+#             */
/*   Updated: 2024/07/13 12:17:53 by tiago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

bool BSP(Point A, Point B, Point C, Point Point)
{
    Fixed pointOne = 1.0f;

    Fixed denominator = ((B.getY() - C.getY()) * (A.getX() - C.getX()) + (C.getX() - B.getX()) * (A.getY() - C.getY()));
    if (denominator == 0.0f)
        return false;

    Fixed lambda1 = ((B.getY() - C.getY()) * (Point.getX() - C.getX()) + (C.getX() - B.getX()) * (Point.getY() - C.getY())) / denominator;
    Fixed lambda2 = ((C.getY() - A.getY()) * (Point.getX() - C.getX()) + (A.getX() - C.getX()) * (Point.getY() - C.getY())) / denominator;
    Fixed lambda3 = pointOne - lambda1 - lambda2;

    return lambda1 > 0 && lambda2 > 0 && lambda3 > 0;
}

void bspMessage(bool BSP, Point A, Point B, Point C, Point Point)
{
    std::cout << "A: " << A.getX() << ", " << A.getY() << std::endl;
    std::cout << "B: " << B.getX() << ", " << B.getY() << std::endl;
    std::cout << "C: " << C.getX() << ", " << C.getY() << std::endl;
    std::cout << "POINT: " << Point.getX() << ", " << Point.getY() << std::endl;
    if (BSP)
        std::cout << "The point is INSIDE the triangle!" << std::endl;
    else
        std::cout << "The point is OUTSIDE the triangle!" << std::endl;
}
