/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 10:12:26 by tiago             #+#    #+#             */
/*   Updated: 2024/07/17 14:04:42 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	_name = "Default FragTrap";

	std::cout << "FragTrap [" << _name << "] created" << std::endl;

	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap(const std::string &Name) : ClapTrap(Name)
{
	std::cout << "FragTrap [" << _name << "] created" << std::endl;

	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy)
{
	*this = copy;
	std::cout << "FragTrap [" << _name << "] created" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	if (_energyPoints > 0 && _hitPoints > 0)
	{
		_energyPoints--;
		std::cout << "FragTrap [" << _name << "] requests a HIGH FIVE!" << std::endl;
	}
	else if (_hitPoints <= 0)
		std::cout << "FragTrap [" << _name << "] wants to high five but he has no hit points left!"
				  << std::endl;
	else
		std::cout << "FragTrap [" << _name << "] wants to high five but he has no energy left!"
				  << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap [" << _name << "] destroyed" << std::endl;
}

std::ostream &operator<<(std::ostream &out, const FragTrap &FragTrap)
{
	out << "[" << FragTrap._name << "] "
		<< "Hit Points: " << FragTrap._hitPoints
		<< "| Energy Points: " << FragTrap._energyPoints
		<< "| Attack Damage: " << FragTrap._attackDamage
		<< std::endl;

	return out;
}