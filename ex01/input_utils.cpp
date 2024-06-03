/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 22:32:53 by tiaferna          #+#    #+#             */
/*   Updated: 2024/06/03 22:37:10 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

std::string	input_getter(std::string input)
{
	if (!(std::cin >> input))
	{
		if (std::cin.eof())
			exit(0);
	}
	return input;
}

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
		std::cout << "First name: ";
		input_getter(value);
		phone_book.add_info(FIRST_NAME ,value, phone_book.saved_contacts);
		std::cout << "Last name: ";
		input_getter(value);
		phone_book.add_info(LAST_NAME, value, phone_book.saved_contacts);
		std::cout << "Nickname: ";
		input_getter(value);
		phone_book.add_info(NICKNAME, value, phone_book.saved_contacts);
		std::cout << "Phone number: ";
		input_getter(value);
		phone_book.add_info(PHONE_NUMBER, value, phone_book.saved_contacts);
		std::cout << "Darkest secret: ";
		input_getter(value);
		phone_book.add_info(DARKEST_SECRET, value, phone_book.saved_contacts);
		phone_book.saved_contacts++;	
	}
	else if (!input.compare("SEARCH"))
	{
		phone_book.display_phonebook();
		std::cout << "Index of entry: ";
		input_getter(value);
		std::cout << std::endl;
		phone_book.display_contact(value);
	}
	else if (!input.compare("EXIT"))
		exit(0);
}
