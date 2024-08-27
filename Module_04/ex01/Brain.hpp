/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiago <tiago@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 17:09:36 by tiaferna          #+#    #+#             */
/*   Updated: 2024/07/23 11:15:30 by tiago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>

class Brain
{
private:
	std::string *_ideas;

public:
	Brain();
	Brain(const Brain &other);
	Brain &operator=(const Brain &copy);
	~Brain();
};
