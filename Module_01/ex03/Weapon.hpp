/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 08:21:08 by tiaferna          #+#    #+#             */
/*   Updated: 2024/06/26 10:55:27 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

class Weapon
{
private:

	std::string	_type;

public:

	Weapon( void );
	
	Weapon( std::string type );
	
	std::string	getType( void );

	void		setType( const std::string& type );
};
