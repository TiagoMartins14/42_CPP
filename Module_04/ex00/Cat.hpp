/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:34:32 by tiaferna          #+#    #+#             */
/*   Updated: 2024/07/17 15:58:00 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

class Cat : virtual public Animal
{
public:
	Cat();
	Cat(const Animal &copy);
	Cat &operator=(const Cat &copy);
	~Cat();

	void makeSound();
};