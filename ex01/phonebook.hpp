/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 08:14:46 by tiaferna          #+#    #+#             */
/*   Updated: 2024/06/03 22:39:28 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <cctype>

typedef enum e_param
{
	FIRST_NAME,
	LAST_NAME,
	NICKNAME,
	PHONE_NUMBER,
	DARKEST_SECRET,
}	t_param;

class Contact
{
public:
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;

	Contact()
	{
		first_name = "";
		last_name = "";
		nickname = "";
		phone_number = "";
		darkest_secret = "";
	}
};

class PhoneBook
{
private:
	Contact contact[8];
public:
	int	saved_contacts;
	PhoneBook()
	{
		saved_contacts = 0;
	}

	void	add_info(t_param parameter , std::string info, int i)
	{
		if (info.size() > 10)
		{
			info.resize(10);
			info[9] = '.';
		}
		if (parameter == FIRST_NAME)
			contact[i].first_name = info;
		else if (parameter == LAST_NAME)
			contact[i].last_name = info;
		else if (parameter == NICKNAME)
			contact[i].nickname = info;
		else if (parameter == PHONE_NUMBER)
			contact[i].phone_number = info;
		else if (parameter == DARKEST_SECRET)
			contact[i].darkest_secret = info;
	}

	void	display_phonebook()
	{
		std::cout << std::setfill (' ') << std::setw (10);
		std::cout << "Index" << "|";
		std::cout << std::setfill (' ') << std::setw (10);
		std::cout << "First Name" << "|";
		std::cout << std::setfill (' ') << std::setw (10);
		std::cout << "Last Name" << "|";
		std::cout << std::setfill (' ') << std::setw (10);
		std::cout << "Nickname" << "|" << std::endl;
		for (int i = 0; i < 8; i++)
		{
			std::cout << std::setfill (' ') << std::setw (10);
			std::cout << i << "|";
			std::cout << std::setfill (' ') << std::setw (10);
			std::cout << contact[i].first_name << "|";
			std::cout << std::setfill (' ') << std::setw (10);
			std::cout << contact[i].last_name << "|";
			std::cout << std::setfill (' ') << std::setw (10);
			std::cout << contact[i].nickname << "|";
			std::cout << std::endl;
		}
	}

	void	display_contact(const std::string index)
	{
		int i = std::atoi(index.c_str());
		if (i >= 0 && i <= 8)
		{
			std::cout << "First Name: ";
			std::cout << contact[i].first_name << std::endl;
			std::cout << "Last Name: ";
			std::cout << contact[i].last_name << std::endl;
			std::cout << "Nickname: ";
			std::cout << contact[i].nickname << std::endl;
			std::cout << "Phone Number: ";
			std::cout << contact[i].phone_number << std::endl;
			std::cout << "Darkest Secret: ";
			std::cout << contact[i].darkest_secret << std::endl;
		}
		else
			std::cout << "Error. Invalid index" << std::endl;
	}

	void	push_contacts_up()
	{
		for (int i = 1; i < 8; i++)
		{
			contact[i - 1].first_name = contact[i].first_name;
			contact[i - 1].last_name = contact[i].last_name;
			contact[i - 1].nickname = contact[i].nickname;
			contact[i - 1].phone_number = contact[i].phone_number;
			contact[i - 1].darkest_secret = contact[i].darkest_secret;
		}
		contact[7].first_name = "";
		contact[7].last_name = "";
		contact[7].nickname = "";
		contact[7].phone_number = "";
		contact[7].darkest_secret = "";
	}
};

/* input_utils.c */
std::string	input_getter(std::string input);
void	parse_input(std::string input, PhoneBook &phone_book);
