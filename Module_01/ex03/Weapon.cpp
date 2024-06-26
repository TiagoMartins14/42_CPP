/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 08:25:23 by tiaferna          #+#    #+#             */
/*   Updated: 2024/06/26 10:55:23 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( void )
{
	_type = "empty hand!";
}

Weapon::Weapon( std::string type )
{
	_type = type;
}

std::string	Weapon::getType( void )
{
	return _type;
}

void		Weapon::setType(const std::string& type)
{
	_type = type;
}
