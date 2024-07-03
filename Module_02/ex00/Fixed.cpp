/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 17:11:23 by tiaferna          #+#    #+#             */
/*   Updated: 2024/07/03 14:40:42 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	operator=(other);
}

Fixed& Fixed::operator=(Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		_fpValue = other.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return _fpValue;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	_fpValue = raw;
}
