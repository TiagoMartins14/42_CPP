/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:25:26 by tiaferna          #+#    #+#             */
/*   Updated: 2024/07/10 14:20:54 by tiaferna         ###   ########.fr       */
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
	std::cout << "<" << this->getName() << ">: BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie( std::string name )
{
	setName( name );
	announce();
}

Zombie::~Zombie( void )
{
	std::cout << _name << " destroyed" << std::endl;
}
