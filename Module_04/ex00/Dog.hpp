/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:34:47 by tiaferna          #+#    #+#             */
/*   Updated: 2024/07/17 16:10:32 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

class Dog : virtual public Animal
{
public:
	Dog();
	Dog(const Animal &copy);
	Dog &operator=(const Dog &copy);
	~Dog();

	void makeSound();
};