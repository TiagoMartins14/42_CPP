/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiago <tiago@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 17:21:48 by tiaferna          #+#    #+#             */
/*   Updated: 2024/07/13 12:19:52 by tiago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "Fixed.hpp"
#include "Point.hpp"
#include "bsp.hpp"

// Regular triangle, point is inside
void test_case_1()
{
    const Point A(5.0f, 0.0f);
    const Point B(2.5f, 5.0f);
    const Point C(0.0f, 0.0f);
    const Point Point(2.5f, 2.5f);

    bspMessage(BSP(A, B, C, Point), A, B, C, Point);
}

// Triangle with negative coordinates, point is inside
void test_case_2()
{
    const Point A(-4.0f, -2.0f);
    const Point B(-1.5f, 15.0f);
    const Point C(4.0f, -1);
    const Point Point(0.0f, 0.0f);

    bspMessage(BSP(A, B, C, Point), A, B, C, Point);
}

// Point super position, point is on top of vertex (thus, outside)
void test_case_3()
{
    const Point A(5.0f, 0.0f);
    const Point B(2.5f, 5.0f);
    const Point C(0.0f, 0.0f);
    const Point Point(2.5f, 5.0f);

    bspMessage(BSP(A, B, C, Point), A, B, C, Point);
}

// Point is on-line (thus, outside)
void test_case_4()
{
    const Point A(-4.0f, 0.0f);
    const Point B(0.0f, 4.0f);
    const Point C(4.0f, 0.0f);
    const Point Point(2.0f, 2.0f);

    bspMessage(BSP(A, B, C, Point), A, B, C, Point);
}

// Degenerated triangle and point is on-line (thus, outside)
void test_case_5()
{
    const Point A(-5.0f, -5.0f);
    const Point B(0.0f, 0.0f);
    const Point C(5.0f, 5.0f);
    const Point Point(0.0f, 0.0f);

    bspMessage(BSP(A, B, C, Point), A, B, C, Point);
}

int main(int argc, char **argv)
{
    (void)argv;
    if (argc == 1)
    {
        test_case_1();
        test_case_2();
        test_case_3();
        test_case_4();
        test_case_5();
    }
    else
        std::cout << "Error: Input: ./BSP" << std::endl;
}
