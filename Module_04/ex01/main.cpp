/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:24:51 by tiaferna          #+#    #+#             */
/*   Updated: 2024/07/19 16:57:42 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"

int main()
{
	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); // will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete meta;
	delete j;
	delete i;

	std::cout << std::endl;
	std::cout << "-------------- Wrong Animal -------------" << std::endl;
	std::cout << std::endl;

	const WrongAnimal *meta2 = new WrongAnimal();
	const WrongAnimal *l = new WrongCat();
	std::cout << l->getType() << " " << std::endl;
	l->makeSound(); // will output the animal sound!
	meta2->makeSound();
	delete meta2;
	delete l;
	return 0;
}