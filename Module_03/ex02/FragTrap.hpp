/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiago <tiago@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 10:01:10 by tiago             #+#    #+#             */
/*   Updated: 2024/07/16 10:29:40 by tiago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ScavTrap.hpp"

class FragTrap : public ScavTrap
{
public:
	FragTrap();
	FragTrap(const std::string &Name);
	FragTrap(const FragTrap &other);
	~FragTrap();
	FragTrap &operator=(const FragTrap &other);

	void highFivesGuys(void);
	void attack(const std::string &target);

	friend std::ostream &operator<<(std::ostream &out, const FragTrap &scavTrap);
};