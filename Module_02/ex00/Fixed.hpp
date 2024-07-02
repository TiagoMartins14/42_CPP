/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:56:28 by tiaferna          #+#    #+#             */
/*   Updated: 2024/07/02 17:11:36 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Fixed
{
private:

	int					_fpValue;
	static const int	_numOfFractionalBits = 8;

public:

	Fixed ();

	Fixed(Fixed& other);
		
	~Fixed();
};
