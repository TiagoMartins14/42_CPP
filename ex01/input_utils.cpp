/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 22:32:53 by tiaferna          #+#    #+#             */
/*   Updated: 2024/06/05 15:16:22 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

static bool is_single_word(std::string input)
{
	int	word_count = 0;
	int i = 0;
	
	while (std::isspace(input[i]))
		i++;
	if (input[i])
		;
	else
		return false; // means it was an empty or white space string
	while (!(std::isspace(input[i])))
		i++;
	if (input[i])
		while (std::isspace(input[i]))
			i++;
	if (input[i])
		return false; // means it has more than one word
	return true;
}

static std::string	input_getter(std::string input)
{
	std::string	ret;
	
	if (!(std::cin >> input))
	{
		if (std::cin.eof())
			exit(0);
	}
	return input;
}

static std::string	input_getter(std::string input)
{
	std::string	ret;
	
	if (!(std::cin >> input))
	{
		if (std::cin.eof())
			exit(0);
	}
	return input;
}

static void	add_contact(PhoneBook &phone_book)
{
	std::string value;
	
	if (phone_book.saved_contacts > 7)
	{
		phone_book.push_contacts_up();
		phone_book.saved_contacts = 7;
	}
	std::cout << "First name: ";
	value = input_getter(value);
	phone_book.add_info(FIRST_NAME ,value, phone_book.saved_contacts);
	std::cout << "Last name: ";
	value = input_getter(value);
	phone_book.add_info(LAST_NAME, value, phone_book.saved_contacts);
	std::cout << "Nickname: ";
	value = input_getter(value);
	phone_book.add_info(NICKNAME, value, phone_book.saved_contacts);
	std::cout << "Phone number: ";
	value = input_getter(value);
	phone_book.add_info(PHONE_NUMBER, value, phone_book.saved_contacts);
	std::cout << "Darkest secret: ";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	if (!(std::getline(std::cin, value)))
	{
		if (std::cin.eof())
			exit(0);
	}
	phone_book.add_info(DARKEST_SECRET, value, phone_book.saved_contacts);
	phone_book.saved_contacts++;
}

static void	search_contact(PhoneBook &phone_book)
{
	std::string	value;

	phone_book.display_phonebook();
	std::cout << "Index of entry: ";
	value = input_getter(value);
	std::cout << std::endl;
	phone_book.display_contact(value);
}

void	parse_input(std::string input, PhoneBook &phone_book)
{
	std::string value;

	if (!input.compare("ADD"))
		add_contact(phone_book);
	else if (!input.compare("SEARCH"))
		search_contact(phone_book);
	else if (!input.compare("EXIT"))
		exit(0);
}
