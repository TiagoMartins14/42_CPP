/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiago <tiago@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:05:34 by tiago             #+#    #+#             */
/*   Updated: 2024/07/15 19:29:18 by tiago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	ScavTrap ScavOne("Scavenger One");
	ScavTrap ScavTwo(ScavOne);
	ScavTrap ScavThree;

	std::cout << "------------ScavOne--------------" << std::endl;
	ScavOne.attack("Gambuzino");
	std::cout << ScavOne << std::endl;
	std::cout << "------------ScavTwo--------------" << std::endl;
	ScavTwo.guardGate();
	std::cout << ScavTwo << std::endl;
	ScavTwo.attack("Gambas");
	std::cout << ScavTwo << std::endl;
	std::cout << "-----------ScavThree-------------" << std::endl;
	ScavThree = ScavOne;
	std::cout << ScavThree << std::endl;
}