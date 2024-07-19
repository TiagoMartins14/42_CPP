/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:23:11 by tiaferna          #+#    #+#             */
/*   Updated: 2024/07/17 17:23:12 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
	Zombie *horde;
	try
	{
		horde = new Zombie[N];
	}
	catch (std::bad_alloc &e)
	{
		std::cerr << "ERROR: " << e.what() << std::endl;
		return (NULL);
	}

	for (int i = 0; i < N; i++)
		new (&horde[i]) Zombie(name);

	return horde;
}
