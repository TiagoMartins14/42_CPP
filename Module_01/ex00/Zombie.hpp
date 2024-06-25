/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 14:01:20 by tiaferna          #+#    #+#             */
/*   Updated: 2024/06/25 17:13:53 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

class Zombie
{
private:

	std::string	_name;
	
public:

	Zombie( std::string name );

	std::string	getName( void );

	void		setName( std::string name);
	
	void		announce( void );
};