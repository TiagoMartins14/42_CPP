/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 10:01:10 by tiago             #+#    #+#             */
/*   Updated: 2024/07/17 14:00:52 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
	FragTrap();
	FragTrap(const std::string &Name);
	FragTrap(const FragTrap &other);
	~FragTrap();

	void highFivesGuys(void);

	friend std::ostream &operator<<(std::ostream &out, const FragTrap &scavTrap);
};