/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 08:25:05 by tiaferna          #+#    #+#             */
/*   Updated: 2024/06/26 11:21:27 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanA
{
private:

	std::string	_name;
	Weapon&		_weapon;
	
public:

	HumanA( std::string name, Weapon& weapon );
	void	attack( void );
};
