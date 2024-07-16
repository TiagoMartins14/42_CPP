/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiago <tiago@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 13:30:22 by tiago             #+#    #+#             */
/*   Updated: 2024/07/16 11:45:08 by tiago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
public:
	ScavTrap();
	ScavTrap(const std::string &Name);
	ScavTrap(const ScavTrap &other);
	~ScavTrap();
	ScavTrap &operator=(const ScavTrap &other);

	void guardGate();
	void attack(const std::string &target);

	friend std::ostream &operator<<(std::ostream &out, const ScavTrap &scavTrap);
};