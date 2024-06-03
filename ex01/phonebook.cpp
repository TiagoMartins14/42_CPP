/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 09:29:21 by tiaferna          #+#    #+#             */
/*   Updated: 2024/06/03 11:44:34 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void	parse_input(std::string input, PhoneBook &phone_book)
{
	std::string value;

	if (!input.compare("ADD"))
	{
		// if (phone_book.saved_contacts == 8) ** TO DO!! **
		// 	phone_book.push_contacts_up();
		if (phone_book.saved_contacts < 8)
			phone_book.saved_contacts++;
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
	// t_action action;
	PhoneBook phone_book;
	while (1)
	{
		std::cout << std::endl << "* PhoneBook *" << std::endl <<std::endl;
		std::cout << "ADD | SEARCH | EXIT" << std::endl;
		std::cin >> input;
		parse_input(input, phone_book);
		
	}
	// phone_book.display_phonebook();
	// std::cout << std::endl << "Contact number 1" << std::endl << std::endl;
	// phone_book.display_contact(0);
}