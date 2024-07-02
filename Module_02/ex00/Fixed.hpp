/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:56:28 by tiaferna          #+#    #+#             */
/*   Updated: 2024/07/02 17:31:00 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Fixed
{
private:

	int					_fpValue;
	static const int	_numOfFractionalBits = 8;

public:

	Fixed ();

	Fixed(const Fixed& other);

	Fixed& operator=(const Fixed& other);
		
	~Fixed();

	int	getRawBits(void);

	void setRawBits(int const raw);
};
