/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 17:09:32 by tiaferna          #+#    #+#             */
/*   Updated: 2024/07/19 17:09:34 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

#define ARRAY_SIZE 100

Brain::Brain()
{
	std::cout << "Brain constructor called" << std::endl;

	this->_ideas = new std::string[ARRAY_SIZE];
}

Brain::Brain(const Brain &other) 
{
	std::cout << "Copy Brain constructor called" << std::endl;

	this->_ideas = new std::string[ARRAY_SIZE];
	for (int i = 0; i < ARRAY_SIZE; i++)
		this->_ideas[i] = other._ideas[i];
}

Brain &Brain::operator=(const Brain &copy)
{
	if (this != &copy)
	{
		delete[] this->_ideas;
		this->_ideas = new std::string[ARRAY_SIZE];
		for (int i = 0; i < ARRAY_SIZE; i++)
			this->_ideas[i] = copy._ideas[i];
	}
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;

	delete[] this->_ideas;
}

