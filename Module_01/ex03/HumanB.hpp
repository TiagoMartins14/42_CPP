/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 09:19:05 by tiaferna          #+#    #+#             */
/*   Updated: 2024/06/26 09:30:31 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

class HumanB
{
private:

	std::string	_weapon;

	std::string	_name;
	
public:

	HumanB( const std::string& name, std::string *weapon );

	void	atack( void );
};
