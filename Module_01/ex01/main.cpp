/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:37:05 by tiaferna          #+#    #+#             */
/*   Updated: 2024/06/25 18:01:44 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main( void )
{
	int	numOfZombies = 14;
	
	Zombie *Patatoss = zombieHorde(numOfZombies, "New_Zombie");
	
	delete[] Patatoss;
}
