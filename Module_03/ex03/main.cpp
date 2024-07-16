/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiago <tiago@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:05:34 by tiago             #+#    #+#             */
/*   Updated: 2024/07/16 22:38:55 by tiago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap DiamondOne("DiamondOne");
	DiamondTrap DiamondTwo(DiamondOne);
	DiamondTrap DiamondThree;

	DiamondOne.whoAmI();
	std::cout << "------------DiamondOne--------------" << std::endl;
	DiamondOne.attack("Gambuzino");
	std::cout << DiamondOne << std::endl;
	std::cout << "------------DiamondTwo--------------" << std::endl;
	DiamondTwo.highFivesGuys();
	DiamondTwo.guardGate();
	DiamondTwo.whoAmI();
	std::cout << DiamondTwo << std::endl;
	DiamondTwo.attack("Gambas");
	std::cout << DiamondTwo << std::endl;
	std::cout << "-----------DiamondThree-------------" << std::endl;
	DiamondThree = DiamondOne;
	std::cout << DiamondThree << std::endl;
}