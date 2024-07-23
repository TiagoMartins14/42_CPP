/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiago <tiago@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:34:49 by tiaferna          #+#    #+#             */
/*   Updated: 2024/07/23 14:06:29 by tiago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Dog default constructor called" << std::endl;
	_type = "Default Dog";
	_brain = new Brain();
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
	std::cout << "Dog copy constructor called" << std::endl;
	_brain = new Brain();
}

Dog &Dog::operator=(const Dog &copy)
{
	std::cout << "Dog = assignment operator called" << std::endl;

	if (this != &copy)
		this->_type = copy._type;
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete _brain;
}

void Dog::makeSound() const
{
	std::cout << BLUE << _type << ": Woof Woof!" << RESET << std::endl;
}
