/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiago <tiago@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 08:48:24 by tiago             #+#    #+#             */
/*   Updated: 2024/07/13 10:46:07 by tiago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : _x(0), _y(0) {}

Point::Point(Fixed x, Fixed y) : _x(x), _y(y) {}

Point::Point(const Point &other) : _x(other._x), _y(other._y)
{
    *this = other;
}

Point &Point::operator=(const Point &copy)
{
    if (this != &copy)
        ;
    return *this;
}

Point::~Point() {}

Fixed Point::getX(void) const { return _x; }
Fixed Point::getY(void) const { return _y; }
