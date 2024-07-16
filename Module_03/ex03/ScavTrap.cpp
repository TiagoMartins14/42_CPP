/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiago <tiago@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 13:44:19 by tiago             #+#    #+#             */
/*   Updated: 2024/07/16 10:22:34 by tiago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	_name = "Default ScavTrap";

	std::cout << "ScavTrap [" << _name << "] created" << std::endl;

	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap(const std::string &Name) : ClapTrap(Name)
{
	std::cout << "ScavTrap [" << _name << "] created" << std::endl;

	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
	*this = copy;
	std::cout << "ScavTrap [" << _name << "] created" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
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

void ScavTrap::guardGate(void)
{
	if (_energyPoints > 0 && _hitPoints > 0)
	{
		_energyPoints--;
		std::cout << "Scav Trap [" << _name << "] is now in GATE KEEPER MODE!" << std::endl;
	}
	else if (_hitPoints <= 0)
		std::cout << "ScavTrap [" << _name << "] wants to enter gate keeper mode but he has no hit points left!"
				  << std::endl;
	else
		std::cout << "ScavTrap [" << _name << "] wants to gate keeper mode but he has no energy left!"
				  << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap [" << _name << "] destroyed" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (_energyPoints > 0 && _hitPoints > 0)
	{
		_energyPoints--;

		std::cout << "ScavTrap [" << _name << "] ATTACKS [" << target
				  << "], causing " << _attackDamage << " points of damage!" << std::endl;
	}
	else if (_hitPoints <= 0)
		std::cout << "ScavTrap [" << _name << "] wants to attack but he has no hit points left!"
				  << std::endl;
	else
		std::cout << "ScavTrap [" << _name << "] wants to attack but he has no energy left!"
				  << std::endl;
}

std::ostream &operator<<(std::ostream &out, const ScavTrap &ScavTrap)
{
	out << "[" << ScavTrap._name << "] "
		<< "Hit Points: " << ScavTrap._hitPoints
		<< "| Energy Points: " << ScavTrap._energyPoints
		<< "| Attack Damage: " << ScavTrap._attackDamage
		<< std::endl;

	return out;
}