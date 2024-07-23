/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiago <tiago@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 14:59:52 by tiaferna          #+#    #+#             */
/*   Updated: 2024/07/23 14:45:06 by tiago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>

#define RESET "\033[0m"
#define BOLD "\033[1m"
#define ITALIC "\033[3m"
#define ULINE "\033[4m"
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define PURPLE "\033[1;35m"
#define CYAN "\033[1;36m"
#define WHITE "\033[1;37m"

class Animal
{
protected:
	std::string _type;

public:
	Animal();
	Animal(const Animal &copy);
	Animal &operator=(const Animal &copy);
	virtual ~Animal();

	std::string getType() const;
	virtual void makeSound() const = 0;
};