/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 09:29:21 by tiaferna          #+#    #+#             */
/*   Updated: 2024/06/13 12:27:31 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

static std::string	input_getter(std::string input)
{
	if (!(std::cin >> input))
	{
		if (std::cin.eof())
			exit(1);
	}
	return input;
}

int	main()
{
	std::string	input = "";
	// TEST
		// for (int i = 0; i < 7; i++)
		// 	for (int j = 0; j < 5; j++)
		// 		phone_book.add_info("fill", i, j);
		// for (int j = 0; j < 5; j++)
		// 	phone_book.add_info("last", 7, j);
		// phone_book.saved_contacts = 8;
	// TEST
	while (1)
	{
		std::cout << std::endl << "* PhoneBook *" << std::endl <<std::endl;
		std::cout << "ADD | SEARCH | EXIT" << std::endl;
		while (!(input.compare("""")))
		{
			input = input_getter(input);
			if (!(input.compare("""")))
				continue ;
			parse_input(input);
		}
		input = "";
	}
}
