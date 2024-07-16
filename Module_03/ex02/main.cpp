/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiago <tiago@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:05:34 by tiago             #+#    #+#             */
/*   Updated: 2024/07/16 10:32:31 by tiago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
	FragTrap FragOne("Scavenger One");
	FragTrap FragTwo(FragOne);
	FragTrap FragThree;

	std::cout << "------------ScavOne--------------" << std::endl;
	FragOne.attack("Gambuzino");
	std::cout << FragOne << std::endl;
	std::cout << "------------ScavTwo--------------" << std::endl;
	FragTwo.guardGate();
	FragTwo.highFivesGuys();
	std::cout << FragTwo << std::endl;
	FragTwo.attack("Gambas");
	std::cout << FragTwo << std::endl;
	std::cout << "-----------ScavThree-------------" << std::endl;
	FragThree = FragOne;
	std::cout << FragThree << std::endl;
}