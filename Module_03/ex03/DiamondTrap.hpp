/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiago <tiago@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 10:56:34 by tiago             #+#    #+#             */
/*   Updated: 2024/07/16 11:51:47 by tiago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
public:
	DiamondTrap();
	DiamondTrap(const std::string &Name);
	DiamondTrap(const DiamondTrap &other);
	~DiamondTrap();
	DiamondTrap &operator=(const DiamondTrap &other);

	void whoAmI();
	void attack(const std::string &target);

	friend std::ostream &operator<<(std::ostream &out, const DiamondTrap &scavTrap);
};