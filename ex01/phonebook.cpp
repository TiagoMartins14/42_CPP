/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 09:29:21 by tiaferna          #+#    #+#             */
/*   Updated: 2024/06/03 22:37:18 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int	main()
{
	std::string	input;
	PhoneBook phone_book;
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
		input_getter(input);
		parse_input(input, phone_book);
	}
}
