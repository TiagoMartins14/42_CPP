/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:37:05 by tiaferna          #+#    #+#             */
/*   Updated: 2024/06/25 17:13:26 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie*	newZombie( std::string name )
{
	Zombie* zombie;
	
	zombie = new Zombie(name);
	return zombie;
}

void	randomChump( std::string name )
{
	Zombie chump(name);
}

int	main( void )
{
	Zombie *Patatoss = newZombie("New_Zombie");
	randomChump("Chump");
	delete(Patatoss);
}
