/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 08:14:46 by tiaferna          #+#    #+#             */
/*   Updated: 2024/06/03 12:42:05 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>

typedef enum e_action
{
	ADD,
	SEARCH,
	EXIT,
}	t_action;

class PhoneBook
{
private:
	std::string contacts[8][5];
public:
	int	saved_contacts;
	PhoneBook()
	{
		saved_contacts = 0;
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 5; j++)
				contacts[i][j] = "";
		}

	}

	void	add_info(std::string info, int i, int j)
	{
		contacts[i][j] = info;	
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

class Contact
{
public:
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;
};