/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 22:58:27 by tiaferna          #+#    #+#             */
/*   Updated: 2024/07/08 14:48:07 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <cmath>

class Fixed
{
private:

	int					_fpValue;
	static const int	_numOfFractionalBits = 8;

public:

	Fixed ();
	Fixed(const Fixed& other);
	Fixed(const int integer);
	Fixed(const float floatingPoint);
	
	Fixed&	operator=(const Fixed& other);
	Fixed&	operator+(const Fixed& other);
	Fixed&	operator-(const Fixed& other);
	Fixed&	operator*(const Fixed& other);
	Fixed&	operator/(const Fixed& other);
	Fixed&	operator++();
	Fixed	operator++(int);
	Fixed&	operator--();
	Fixed	operator--(int);
	bool	operator>(const Fixed& other);
	bool	operator<(const Fixed& other);
	bool	operator>=(const Fixed& other);
	bool	operator<=(const Fixed& other);
	bool	operator==(const Fixed& other);
	bool	operator!=(const Fixed& other);
	friend std::ostream &operator<<(std::ostream& out, const Fixed &fixed);
	
	~Fixed();
	
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;
	static Fixed& min(Fixed& a, Fixed& b);
	static const Fixed& min(const Fixed& a, const Fixed& b);
	static Fixed& max(Fixed& a, Fixed& b);
	static const Fixed& max(const Fixed& a, const Fixed& b);
};
