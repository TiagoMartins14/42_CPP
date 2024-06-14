/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 22:32:53 by tiaferna          #+#    #+#             */
/*   Updated: 2024/06/14 14:44:47 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

static bool is_single_word(std::string str)
{
    int i = 0;
    int len = str.length();

    while (i < len && std::isspace(str[i]))
        i++;
    if (i == len)
        return false;
    while (i < len && !std::isspace(str[i]))
        i++;
    while (i < len && std::isspace(str[i]))
        i++;
    return i == len;
}

static bool	is_alphabetic(std::string str)
{
	if (str.empty()) 
		return false;
	for (size_t i = 0; i < str.size(); i++)
		if (!std::isalpha(str[i]))
			return false;
	return true;
}

static bool	is_numeric(std::string str)
{
	size_t	i = 0;
	
	if (str.empty() || (str.size() == 1 && str[0] == '+')) 
		return false;
	if (str[0] == '+')
		i++;
	for (; i < str.size(); i++)
		if (!std::isdigit(str[i]))
			return false;
	return true;
}

static bool	is_alphanumeric(std::string str)
{
	if (str.empty()) 
		return false;
	for (size_t i = 0; i < str.size(); i++)
		if (!std::isalpha(str[i]) && !std::isdigit(str[i]) && !std::isspace(str[i]))
			return false;
	return true;
}

static std::string	input_getter_alphanumeric(std::string input, t_word_amount amount, bool *prompt)
{
	bool flag = false;

	while (flag == false)
	{
		if (!(std::getline(std::cin, input)))
		{
			if (std::cin.eof())
			{
				*prompt = false;
				return "";
			}
		}
		if (amount == SINGLE_WORD && is_single_word(input) == false)
		{
			std::cout << "Invalid input. Please enter only one word" << std::endl;
			continue ;
		}
		if (!is_alphanumeric(input))
		{
			std::cout << "Invalid input. Please enter only alphanumeric characters" << std::endl;
			continue ;
		}
		flag = true;
	}
	return input;
}

static std::string	input_getter_alphabetic(std::string input, bool *prompt)
{
	bool flag = false;

	while (flag == false)
	{
		if (!(std::getline(std::cin, input)))
		{
			if (std::cin.eof())
			{
				*prompt = false;
				return "";
			}
		}
		if (!is_single_word(input))
		{
			std::cout << "Invalid input. Please enter only one word" << std::endl;
			continue ;
		}
		if (!is_alphabetic(input))
		{
			std::cout << "Invalid input. Please enter only alphabetic characters" << std::endl;
			continue ;
		}
		flag = true;
	}
	return input;
}

static std::string	input_getter_numeric(std::string input, bool *prompt)
{
	bool flag = false;

	while (flag == false)
	{
		if (!(std::getline(std::cin, input)))
		{
			if (std::cin.eof())
			{
				*prompt = false;
				return "";
			}
		}
		if (!is_single_word(input))
		{
			std::cout << "Invalid input. Please enter only one word" << std::endl;
			continue ;
		}
		if (!is_numeric(input))
		{
			std::cout << "Invalid input. Please enter only numeric characters" << std::endl;
			continue ;
		}
		flag = true;
	}
	return input;
}

static void	add_contact(PhoneBook &phone_book, bool *prompt)
{
	std::string value;
	
	if (phone_book.saved_contacts > 7)
	{
		phone_book.push_contacts_up();
		phone_book.saved_contacts = 7;
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout << "First name: ";
	value = input_getter_alphabetic(value, prompt);
	if (*prompt == false)
		return ;
	phone_book.add_info(FIRST_NAME ,value, phone_book.saved_contacts);
	std::cout << "Last name: ";
	value = input_getter_alphabetic(value, prompt);
	if (*prompt == false)
		return ;
	phone_book.add_info(LAST_NAME, value, phone_book.saved_contacts);
	std::cout << "Nickname: ";
	value = input_getter_alphanumeric(value, SINGLE_WORD, prompt);
	if (*prompt == false)
		return ;
	phone_book.add_info(NICKNAME, value, phone_book.saved_contacts);
	std::cout << "Phone number: ";
	value = input_getter_numeric(value, prompt);
	if (*prompt == false)
		return ;
	phone_book.add_info(PHONE_NUMBER, value, phone_book.saved_contacts);
	std::cout << "Darkest secret: ";
	value = input_getter_alphanumeric(value, MULTIPLE_WORDS, prompt);
	if (*prompt == false)
		return ;
	phone_book.add_info(DARKEST_SECRET, value, phone_book.saved_contacts);
	phone_book.saved_contacts++;
}

static void	search_contact(PhoneBook &phone_book, bool *prompt)
{
	std::string	value;

	phone_book.display_phonebook();
	std::cout << "Index of entry: ";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	value = input_getter_numeric(value, prompt);
	std::cout << std::endl;
	phone_book.display_contact(value);
}

int	parse_input(std::string input, PhoneBook &phone_book, bool *prompt)
{
	std::string value;

	if (!input.compare("ADD"))
		add_contact(phone_book, prompt);
	else if (!input.compare("SEARCH"))
		search_contact(phone_book, prompt);
	else if (!input.compare("EXIT"))
		return 0;
	return 1;
}
