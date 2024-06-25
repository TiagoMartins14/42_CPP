/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:25:26 by tiaferna          #+#    #+#             */
/*   Updated: 2024/06/25 17:13:41 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

std::string	Zombie::getName( void )
{
	return _name;
}

void		Zombie::setName( std::string name)
{
	_name = name;
}

void		Zombie::announce( void )
{
	std::cout << "<" << _name << ">: BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie( std::string name )
{
	setName( name );
	announce();
}
