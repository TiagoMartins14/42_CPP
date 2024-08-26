/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 10:56:36 by tiago             #+#    #+#             */
/*   Updated: 2024/07/17 14:39:11 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ScavTrap(), FragTrap()
{
	this->_name = "Default DiamondTrap";
	this->ClapTrap::_name = _name + "_clap_name";

	std::cout << "DiamondTrap [" << _name << "] created" << std::endl;

	this->_hitPoints = this->FragTrap::_hitPoints;
	this->_energyPoints = this->ScavTrap::_energyPoints;
	this->_attackDamage = this->FragTrap::_attackDamage;
}
DiamondTrap::DiamondTrap(const std::string &Name) : ScavTrap(Name), FragTrap(Name)
{
	this->_name = Name;
	this->ClapTrap::_name = Name + "_clap_name";
	std::cout << "DiamondTrap [" << _name << "] created" << std::endl;

	this->_hitPoints = this->FragTrap::_hitPoints;
	this->_energyPoints = this->ScavTrap::_energyPoints;
	this->_attackDamage = this->FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), ScavTrap(other), FragTrap(other)
{
	*this = other;
	std::cout << "DiamondTrap [" << _name << "] created" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &copy)
{
	if (this != &copy)
	{
		this->_name = copy._name;
		this->_hitPoints = copy._hitPoints;
		this -> _energyPoints = copy._energyPoints;
		this->_attackDamage = copy._attackDamage;
		this->ClapTrap::_name = copy.ClapTrap::_name;
	}
	return *this;
}

void DiamondTrap::whoAmI()
{
	std::cout << "Name: " << _name << std::endl;
	std::cout << "ClapTrap name: " << this->ClapTrap::_name << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap [" << _name << "] destroyed" << std::endl;
}
