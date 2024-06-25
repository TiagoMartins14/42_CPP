/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 18:12:47 by tiaferna          #+#    #+#             */
/*   Updated: 2024/06/25 18:26:46 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main( void )
{
	std::string	string = "HI THIS IS BRAIN";
	
	std::string* stringPTR = &string;

	std::string& stringREF = string;

	std::cout << "Memory address of the string variable: " << &string << std::endl;
	std::cout << "The memory address held by stringPTR:  " << stringPTR << std::endl;
	std::cout << "The memory address held by stringREF:  " << &stringREF << std::endl;
	std::cout << std::endl;
	std::cout << "The value of the string variable:  " << string << std::endl;
	std::cout << "The value pointed to by stringPTR: " << *stringPTR << std::endl;
	std::cout << "The value pointed to by stringPTR: " << stringREF << std::endl;
}