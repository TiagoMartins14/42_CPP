/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiago <tiago@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 10:56:36 by tiago             #+#    #+#             */
/*   Updated: 2024/07/16 11:53:12 by tiago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ScavTrap(), FragTrap()
{
	_name = "Default DiamondTrap";
	ClapTrap::_name = _name + "_clap_name";

	std::cout << "FragTrap [" << _name << "] created" << std::endl;

	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 30;
}
DiamondTrap::DiamondTrap(const std::string &Name) : ScavTrap(Name), FragTrap(Name)
{
	std::cout << "DiamondTrap [" << _name << "] created" << std::endl;

	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap(copy)
{
	*this = copy;
	std::cout << "DiamondTrap [" << _name << "] created" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
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

void DiamondTrap::whoAmI(void)
{
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap [" << _name << "] destroyed" << std::endl;
}

void DiamondTrap::attack(const std::string &target)
{
	if (_energyPoints > 0 && _hitPoints > 0)
	{
		_energyPoints--;

		std::cout << "DiamondTrap [" << _name << "] ATTACKS [" << target
				  << "], causing " << _attackDamage << " points of damage!" << std::endl;
	}
	else if (_hitPoints <= 0)
		std::cout << "DiamondTrap [" << _name << "] wants to attack but he has no hit points left!"
				  << std::endl;
	else
		std::cout << "DiamondTrap [" << _name << "] wants to attack but he has no energy left!"
				  << std::endl;
}

std::ostream &operator<<(std::ostream &out, const DiamondTrap &DiamondTrap)
{
	out << "[" << DiamondTrap._name << "] "
		<< "Hit Points: " << DiamondTrap._hitPoints
		<< "| Energy Points: " << DiamondTrap._energyPoints
		<< "| Attack Damage: " << DiamondTrap._attackDamage
		<< std::endl;

	return out;
}