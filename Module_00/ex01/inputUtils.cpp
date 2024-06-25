/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputUtils.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 22:32:53 by tiaferna          #+#    #+#             */
/*   Updated: 2024/06/25 15:39:14 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myAwesomePhoneBook.hpp"

static bool isSingleWord(std::string str)
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

static bool	isAlphabetic(std::string str)
{
	if (str.empty()) 
		return false;
	for (size_t i = 0; i < str.size(); i++)
		if (!std::isalpha(str[i]))
			return false;
	return true;
}

static bool	isNumeric(std::string str)
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

static bool	isAlphanumeric(std::string str)
{
	if (str.empty()) 
		return false;
	for (size_t i = 0; i < str.size(); i++)
		if (!std::isalpha(str[i]) && !std::isdigit(str[i]) && !std::isspace(str[i]))
			return false;
	return true;
}

static std::string	inputGetterAlphanumeric(std::string input, t_word_amount amount, bool *prompt)
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
		if (amount == SINGLE_WORD && isSingleWord(input) == false)
		{
			std::cout << "Invalid input. Please enter only one word" << std::endl;
			continue ;
		}
		if (!isAlphanumeric(input))
		{
			std::cout << "Invalid input. Please enter only alphanumeric characters" << std::endl;
			continue ;
		}
		flag = true;
	}
	return input;
}

static std::string	inputGetterAlphabetic(std::string input, bool *prompt)
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
		if (!isSingleWord(input))
		{
			std::cout << "Invalid input. Please enter only one word" << std::endl;
			continue ;
		}
		if (!isAlphabetic(input))
		{
			std::cout << "Invalid input. Please enter only alphabetic characters" << std::endl;
			continue ;
		}
		flag = true;
	}
	return input;
}

static std::string	inputGetterNumeric(std::string input, bool *prompt)
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
		if (!isSingleWord(input))
		{
			std::cout << "Invalid input. Please enter only one word" << std::endl;
			continue ;
		}
		if (!isNumeric(input))
		{
			std::cout << "Invalid input. Please enter only numeric characters" << std::endl;
			continue ;
		}
		flag = true;
	}
	return input;
}

static void	addContact(PhoneBook &phoneBook, bool *prompt)
{
	std::string value;
	
	if (phoneBook.getSavedContacts() > 7)
	{
		phoneBook.pushContactsUp();
		phoneBook.setSavedContacts(7);
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout << "First name: ";
	value = inputGetterAlphabetic(value, prompt);
	if (*prompt == false)
		return ;
	phoneBook.addInfo(FIRST_NAME ,value, phoneBook.getSavedContacts());
	std::cout << "Last name: ";
	value = inputGetterAlphabetic(value, prompt);
	if (*prompt == false)
		return ;
	phoneBook.addInfo(LAST_NAME, value, phoneBook.getSavedContacts());
	std::cout << "Nickname: ";
	value = inputGetterAlphanumeric(value, SINGLE_WORD, prompt);
	if (*prompt == false)
		return ;
	phoneBook.addInfo(NICKNAME, value, phoneBook.getSavedContacts());
	std::cout << "Phone number: ";
	value = inputGetterNumeric(value, prompt);
	if (*prompt == false)
		return ;
	phoneBook.addInfo(PHONE_NUMBER, value, phoneBook.getSavedContacts());
	std::cout << "Darkest secret: ";
	value = inputGetterAlphanumeric(value, MULTIPLE_WORDS, prompt);
	if (*prompt == false)
		return ;
	phoneBook.addInfo(DARKEST_SECRET, value, phoneBook.getSavedContacts());
	phoneBook.setSavedContacts(phoneBook.getSavedContacts() + 1);
}

static void	searchContact(PhoneBook &phoneBook, bool *prompt)
{
	std::string	value;

	phoneBook.displayPhonebook();
	std::cout << "Index of entry: ";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	value = inputGetterNumeric(value, prompt);
	std::cout << std::endl;
	phoneBook.displayContact(value);
}

int	parseInput(std::string input, PhoneBook &phoneBook, bool *prompt)
{
	std::string value;

	if (!input.compare("ADD"))
		addContact(phoneBook, prompt);
	else if (!input.compare("SEARCH"))
		searchContact(phoneBook, prompt);
	else if (!input.compare("EXIT"))
		return 0;
	return 1;
}
