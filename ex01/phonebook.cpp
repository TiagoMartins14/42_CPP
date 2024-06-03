/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 09:29:21 by tiaferna          #+#    #+#             */
/*   Updated: 2024/06/03 12:34:26 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void	parse_input(std::string input, PhoneBook &phone_book)
{
	std::string value;

	if (!input.compare("ADD"))
	{
		if (phone_book.saved_contacts > 7)
		{
			phone_book.push_contacts_up();
			phone_book.saved_contacts = 7;
		}
		phone_book.display_phonebook();
		std::cout << "First name: ";
		std::cin >> value;
		phone_book.add_info(value, phone_book.saved_contacts, 0);
		std::cout << "Last name: ";
		std::cin >> value;
		phone_book.add_info(value, phone_book.saved_contacts, 1);
		std::cout << "Nickname: ";
		std::cin >> value;
		phone_book.add_info(value, phone_book.saved_contacts, 2);
		std::cout << "Phone number: ";
		std::cin >> value;
		phone_book.add_info(value, phone_book.saved_contacts, 3);
		std::cout << "Darkest secret: ";
		std::cin >> value;
		phone_book.add_info(value, phone_book.saved_contacts, 4);
		phone_book.display_phonebook();
		phone_book.saved_contacts++;	
	}
	else if (!input.compare("SEARCH"))
	{
		phone_book.display_phonebook();
		std::cout << "Index of entry: ";
		std::cin >> value;
		std::cout << std::endl;
		phone_book.display_contact(value);
	}
	else if (!input.compare("EXIT"))
		exit(0) ;
}

int	main()
{
	std::string	input;
	PhoneBook phone_book;
	// TEST
		for (int i = 0; i < 7; i++)
			for (int j = 0; j < 5; j++)
				phone_book.add_info("fill", i, j);
		for (int j = 0; j < 5; j++)
			phone_book.add_info("last", 7, j);
		phone_book.saved_contacts = 8;
	// TEST
	while (1)
	{
		std::cout << std::endl << "* PhoneBook *" << std::endl <<std::endl;
		std::cout << "ADD | SEARCH | EXIT" << std::endl;
		std::cin >> input;
		parse_input(input, phone_book);
	}
}