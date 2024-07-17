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

	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 30;
}
DiamondTrap::DiamondTrap(const std::string &Name) : ScavTrap(Name), FragTrap(Name)
{
	this->_name = Name;
	this->ClapTrap::_name = Name + "_clap_name";
	std::cout << "DiamondTrap [" << _name << "] created" << std::endl;

	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), ScavTrap(other), FragTrap(other)
{
	*this = other;
	std::cout << "DiamondTrap [" << _name << "] created" << std::endl;
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
