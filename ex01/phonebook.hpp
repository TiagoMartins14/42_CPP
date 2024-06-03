/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 08:14:46 by tiaferna          #+#    #+#             */
/*   Updated: 2024/06/03 13:27:36 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>

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
	Contact contacts[8];
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
			contacts[i].first_name = info;
		else if (parameter == LAST_NAME)
			contacts[i].last_name = info;
		else if (parameter == NICKNAME)
			contacts[i].nickname = info;
		else if (parameter == PHONE_NUMBER)
			contacts[i].phone_number = info;
		else if (parameter == DARKEST_SECRET)
			contacts[i].darkest_secret = info;
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
			for (int j = 0; j < 3; j++)
			{
				std::cout << std::setfill (' ') << std::setw (10);
				std::cout << contacts[i][j] << "|";
			}
			std::cout << std::endl;
		}
	}


	void	display_contact(const std::string index)
	{
		int i = std::atoi(index.c_str());
		int j = 0;
		if (i >= 0 && i <= 8)
		{
			std::cout << "First Name: ";
			std::cout << contacts[i][j++] << std::endl;
			std::cout << "Last Name: ";
			std::cout << contacts[i][j++] << std::endl;
			std::cout << "Nickname: ";
			std::cout << contacts[i][j++] << std::endl;
			std::cout << "Phone Number: ";
			std::cout << contacts[i][j++] << std::endl;
			std::cout << "Darkest Secret: ";
			std::cout << contacts[i][j++] << std::endl;
		}
		else
			std::cout << "Invalid index" << std::endl;
	}

	void	push_contacts_up()
	{
		for (int i = 1; i < 8; i++)
		{
			for (int j = 0; j < 5; j++)
				contacts[i - 1][j] = contacts[i][j];
		}
		for (int j = 0; j < 5; j++)
			contacts[7][j] = "";
	}
};
