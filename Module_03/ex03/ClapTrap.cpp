/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 13:44:19 by tiago             #+#    #+#             */
/*   Updated: 2024/07/17 14:35:40 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Default ClapTrap"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap [" << _name << "] created" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap [" << _name << "] created" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	*this = copy;
	std::cout << "ClapTrap [" << _name << "] created" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
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

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap [" << _name << "] destroyed" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (_energyPoints > 0 && _hitPoints > 0)
	{
		_energyPoints--;

		std::cout << "ClapTrap [" << _name << "] ATTACKS [" << target
				  << "], causing " << _attackDamage << " points of damage!" << std::endl;
	}
	else if (_hitPoints <= 0)
		std::cout << "ClapTrap [" << _name << "] wants to attack but he has no hit points left!"
				  << std::endl;
	else
		std::cout << "ClapTrap [" << _name << "] wants to attack but he has no energy left!"
				  << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	_hitPoints -= amount;

	std::cout << "ClapTrap [" << _name << "] GETS ATTACKED and receives "
			  << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_energyPoints > 0 && _hitPoints > 0)
	{
		_energyPoints--;
		_hitPoints += amount;

		std::cout << "ClapTrap [" << _name << "] GETS REPAIRED and receives "
				  << amount << " hit points!" << std::endl;
	}
	else if (_hitPoints <= 0)
		std::cout << "ClapTrap [" << _name << "] wants to repair but he has no hit points left!"
				  << std::endl;
	else
		std::cout << "ClapTrap [" << _name << "] wants to repair but he has no energy left!"
				  << std::endl;
}

std::string ClapTrap::getName(void) const
{
	return _name;
}

int ClapTrap::getAttackDamage(void) const
{
	return _attackDamage;
}

int ClapTrap::getHitPoints(void) const
{
	return _hitPoints;
}

int ClapTrap::getEnergyPoints(void) const
{
	return _energyPoints;
}

std::ostream &operator<<(std::ostream &out, const ClapTrap &clapTrap)
{
	out << "[" << clapTrap.getName() << "] "
		<< "Hit Points: " << clapTrap.getHitPoints()
		<< "| Energy Points: " << clapTrap.getEnergyPoints()
		<< "| Attack Damage: " << clapTrap.getAttackDamage()
		<< std::endl;

	return out;
}