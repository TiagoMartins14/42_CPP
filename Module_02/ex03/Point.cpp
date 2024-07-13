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

Fixed Point::getX(void) { return _x; }
Fixed Point::getY(void) { return _y; }

void Point::setX(const Fixed x) { _x = x; }
void Point::setY(const Fixed y) { _y = y; }
