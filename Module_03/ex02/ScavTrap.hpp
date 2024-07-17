/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 13:30:22 by tiago             #+#    #+#             */
/*   Updated: 2024/07/17 13:52:24 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
	ScavTrap();
	ScavTrap(const std::string &Name);
	ScavTrap(const ScavTrap &other);
	~ScavTrap();

	void guardGate();
	void attack(const std::string &target);

	friend std::ostream &operator<<(std::ostream &out, const ScavTrap &scavTrap);
};