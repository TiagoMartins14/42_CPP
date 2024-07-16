/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiago <tiago@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 10:12:26 by tiago             #+#    #+#             */
/*   Updated: 2024/07/16 10:21:15 by tiago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ScavTrap()
{
	_name = "Default FragTrap";

	std::cout << "FragTrap [" << _name << "] created" << std::endl;

	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap(const std::string &Name) : ScavTrap(Name)
{
	std::cout << "FragTrap [" << _name << "] created" << std::endl;

	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &copy) : ScavTrap(copy)
{
	*this = copy;
	std::cout << "FragTrap [" << _name << "] created" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return *this;
}

void FragTrap::highFivesGuys(void)
{
	if (_energyPoints > 0 && _hitPoints > 0)
	{
		_energyPoints--;
		std::cout << "Scav Trap [" << _name << "] requests a HIGH FIVE!" << std::endl;
	}
	else if (_hitPoints <= 0)
		std::cout << "ScavTrap [" << _name << "] wants to high five but he has no hit points left!"
				  << std::endl;
	else
		std::cout << "ScavTrap [" << _name << "] wants to high five but he has no energy left!"
				  << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap [" << _name << "] destroyed" << std::endl;
}

void FragTrap::attack(const std::string &target)
{
	if (_energyPoints > 0 && _hitPoints > 0)
	{
		_energyPoints--;

		std::cout << "FragTrap [" << _name << "] ATTACKS [" << target
				  << "], causing " << _attackDamage << " points of damage!" << std::endl;
	}
	else if (_hitPoints <= 0)
		std::cout << "FragTrap [" << _name << "] wants to attack but he has no hit points left!"
				  << std::endl;
	else
		std::cout << "FragTrap [" << _name << "] wants to attack but he has no energy left!"
				  << std::endl;
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