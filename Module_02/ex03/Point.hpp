/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiago <tiago@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 09:44:11 by tiago             #+#    #+#             */
/*   Updated: 2024/07/13 11:53:32 by tiago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Fixed.hpp"

class Point
{
private:
    const Fixed _x;
    const Fixed _y;

public:
    Point();
    Point(Fixed x, Fixed y);
    Point(const Point &other);
    Point &operator=(const Point &copy);
    ~Point();

    Fixed getX(void) const;
    Fixed getY(void) const;
};