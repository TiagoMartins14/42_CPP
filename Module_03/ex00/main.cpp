/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiago <tiago@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 14:52:01 by tiago             #+#    #+#             */
/*   Updated: 2024/07/14 16:21:56 by tiago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap Old_Biden("Old Biden");
	ClapTrap CrazyTrump("Crazy Trump");
	ClapTrap BidenClone(Old_Biden);

	std::cout << Old_Biden << std::endl;
	std::cout << CrazyTrump << std::endl;

	Old_Biden.attack(CrazyTrump.getName());
	std::cout << Old_Biden << std::endl;

	Old_Biden.takeDamage(10);
	std::cout << Old_Biden << std::endl;

	Old_Biden.beRepaired(5);
	std::cout << Old_Biden << std::endl;

	std::cout << "Old_Biden = Crazy_trump" << std::endl;
	Old_Biden = CrazyTrump;
	std::cout << Old_Biden << std::endl;

	BidenClone.beRepaired(90);
	std::cout << BidenClone << std::endl;

	for (int i = 0; i < 9; i++)
		BidenClone.beRepaired(1);

	std::cout << BidenClone << std::endl;
	
	BidenClone.attack("CrazyTrump");
}