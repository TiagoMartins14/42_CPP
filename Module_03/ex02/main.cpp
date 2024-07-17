/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:05:34 by tiago             #+#    #+#             */
/*   Updated: 2024/07/17 14:06:35 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
	FragTrap FragOne("FraggerOne");
	FragTrap FragThree;

	std::cout << "------------ScavOne--------------" << std::endl;
	FragOne.attack("Gambuzino");
	std::cout << FragOne << std::endl;
	std::cout << "------------ScavTwo--------------" << std::endl;
	FragTrap FragTwo(FragOne);
	FragTwo.highFivesGuys();
	std::cout << FragTwo << std::endl;
	FragTwo.attack("Gambas");
	std::cout << FragTwo << std::endl;
	std::cout << "-----------ScavThree-------------" << std::endl;
	FragThree = FragOne;
	std::cout << FragThree << std::endl;
}