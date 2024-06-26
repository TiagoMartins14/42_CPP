/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 09:35:07 by tiaferna          #+#    #+#             */
/*   Updated: 2024/06/26 09:37:44 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB( const std::string& name, std::string *weapon )
{
	_name = name;

	_weapon = *weapon;
}

void	HumanB::atack( void )
{
	std::cout << _name << " attacks with their " << _weapon << std::endl;
}
