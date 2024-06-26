/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 09:35:07 by tiaferna          #+#    #+#             */
/*   Updated: 2024/06/26 11:06:08 by tiaferna         ###   ########.fr       */
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
	std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}
