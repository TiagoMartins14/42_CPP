/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 09:09:04 by tiaferna          #+#    #+#             */
/*   Updated: 2024/06/26 09:18:31 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA( const std::string& name, std::string &weapon )
{
	_name = name;

	_weapon = weapon;
}

void	HumanA::atack( void )
{
	std::cout << _name << " attacks with their " << _weapon << std::endl;
}
