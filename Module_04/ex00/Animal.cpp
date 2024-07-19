/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:03:12 by tiaferna          #+#    #+#             */
/*   Updated: 2024/07/19 14:49:49 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Animal")
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal &copy)
{
	*this = copy;
	std::cout << "Animal copy constructor called" << std::endl;
}
Animal &Animal::operator=(const Animal &copy)
{
	std::cout << "Animal = assignment operator called" << std::endl;
	if (this != &copy)
		this->_type = copy._type;
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType()
{
	return _type;
}

void Animal::makeSound()
{
	std::cout << _type << ": [Generic animal sound]" << std::endl;
}
