/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:56:28 by tiaferna          #+#    #+#             */
/*   Updated: 2024/07/03 14:40:49 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Fixed
{
private:

	int					_fpValue;
	static const int	_numOfFractionalBits = 8;

public:

	Fixed ();

	Fixed(Fixed& other);

	Fixed& operator=(Fixed& other);
		
	~Fixed();

	int	getRawBits(void) const;

	void setRawBits(int const raw);
};
