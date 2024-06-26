/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 08:25:05 by tiaferna          #+#    #+#             */
/*   Updated: 2024/06/26 09:30:34 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

class HumanA
{
private:

	std::string	_weapon;

	std::string	_name;
	
public:

	HumanA( const std::string& name, std::string& weapon );

	void	atack( void );
};