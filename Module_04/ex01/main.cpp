/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiago <tiago@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:24:51 by tiaferna          #+#    #+#             */
/*   Updated: 2024/07/23 11:20:57 by tiago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	const int SIZE = 6;
	Animal *animals[SIZE];

	std::cout << "------ Creating cats and dogs with brains classes -----" << std::endl
			  << std::endl;
	for (size_t i = 0; i < SIZE / 2; i++)
		animals[i] = new Dog;
	for (size_t i = SIZE / 2; i < SIZE; i++)
		animals[i] = new Cat;

	std::cout << std::endl
			  << "------ Destroying created classes -----" << std::endl
			  << std::endl;
	for (int i = 0; i < SIZE; i++)
		delete animals[i];
}