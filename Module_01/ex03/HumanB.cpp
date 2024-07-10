/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 09:35:07 by tiaferna          #+#    #+#             */
/*   Updated: 2024/07/10 14:57:22 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB( const std::string& name ) : _name(name) {}

void	HumanB::setWeapon( Weapon& weapon )
{
	_weapon = &weapon;
}

void	HumanB::attack( void )
{
	if (_weapon)
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
	else
		std::cout << _name << " attacks with their empty hands!" << std::endl;
}
