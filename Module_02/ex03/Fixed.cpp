/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiago <tiago@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 14:25:12 by tiaferna          #+#    #+#             */
/*   Updated: 2024/07/11 22:09:33 by tiago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	// std::cout << "Default constructor called" << std::endl;
	this->_fpValue = 0;
}

Fixed::Fixed(const Fixed &other)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::Fixed(const int integer)
{
	// std::cout << "Int constructor called" << std::endl;
	this->_fpValue = integer * (1 << this->_numOfFractionalBits);
}
Fixed::Fixed(const float floatingPoint)
{
	// std::cout << "Float constructor called" << std::endl;
	this->_fpValue = roundf(floatingPoint * (1 << this->_numOfFractionalBits));
}

Fixed &Fixed::operator=(const Fixed &other)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		_fpValue = other.getRawBits();
	return *this;
}

Fixed &Fixed::operator+(const Fixed &other)
{
	// std::cout << "Adition assignment operator called" << std::endl;
	this->_fpValue += other.getRawBits();
	return *this;
}

Fixed &Fixed::operator-(const Fixed &other)
{
	// std::cout << "Subtraction assignment operator called" << std::endl;
	this->_fpValue -= other.getRawBits();

	return *this;
}
Fixed &Fixed::operator*(const Fixed &other)
{
	// std::cout << "Multiplication assignment operator called" << std::endl;
	long long result = static_cast<long long>(this->getRawBits()) * other.getRawBits();
	result >>= _numOfFractionalBits;
	this->_fpValue = static_cast<int>(result);
	return *this;
}

Fixed &Fixed::operator/(const Fixed &other)
{
	// std::cout << "Division assignment operator called" << std::endl;
	long long numerator = static_cast<long long>(_fpValue) << _numOfFractionalBits;
	_fpValue = static_cast<int>(numerator / other.getRawBits());
	return *this;
}

Fixed &Fixed::operator++()
{
	++_fpValue;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	++_fpValue;
	return temp;
}

Fixed &Fixed::operator--()
{
	--_fpValue;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	--_fpValue;
	return temp;
}

bool Fixed::operator>(const Fixed &other)
{
	// std::cout << "Bigger than assignment operator called" << std::endl;
	if (this != &other)
	{
		if (this->_fpValue > other._fpValue)
			return true;
	}
	return false;
}

bool Fixed::operator<(const Fixed &other)
{
	// std::cout << "Smaller than assignment operator called" << std::endl;
	if (this != &other)
	{
		if (this->_fpValue < other._fpValue)
			return true;
	}
	return false;
}

bool Fixed::operator>=(const Fixed &other)
{
	// std::cout << "Bigger or equal than assignment operator called" << std::endl;
	if (this != &other)
	{
		if (this->_fpValue >= other._fpValue)
			return true;
	}
	return false;
}

bool Fixed::operator<=(const Fixed &other)
{
	// std::cout << "Smaller or equal than assignment operator called" << std::endl;
	if (this != &other)
	{
		if (this->_fpValue <= other._fpValue)
			return true;
	}
	return false;
}

bool Fixed::operator==(const Fixed &other)
{
	// std::cout << "Sames as assignment operator called" << std::endl;
	if (this != &other)
	{
		if (this->_fpValue == other._fpValue)
			return true;
	}
	return false;
}
bool Fixed::operator!=(const Fixed &other)
{
	// std::cout << "Different than assignment operator called" << std::endl;
	if (this != &other)
	{
		if (this->_fpValue != other._fpValue)
			return true;
	}
	return false;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}

std::istream &operator>>(std::istream &in, Fixed &fixed)
{
	float tempValue;

	in >> tempValue;
	fixed = Fixed(tempValue);
	return in;
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	return _fpValue;
}

void Fixed::setRawBits(int const raw)
{
	_fpValue = raw;
}

float Fixed::toFloat(void) const
{
	return static_cast<float>(this->_fpValue) / (1 << _numOfFractionalBits);
}

int Fixed::toInt(void) const
{
	return static_cast<int>(this->_fpValue) >> _numOfFractionalBits;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return (a.getRawBits() < b.getRawBits()) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a.getRawBits() < b.getRawBits()) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return (a.getRawBits() > b.getRawBits()) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a.getRawBits() > b.getRawBits()) ? a : b;
}
