/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 08:14:46 by tiaferna          #+#    #+#             */
/*   Updated: 2024/06/12 22:36:52 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <cctype>
#include <limits>

typedef enum e_param
{
	FIRST_NAME,
	LAST_NAME,
	NICKNAME,
	PHONE_NUMBER,
	DARKEST_SECRET,
}	t_param;

typedef enum e_word_amount
{
	SINGLE_WORD,
	MULTIPLE_WORDS,
}	t_word_amount;

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

	void add_info(t_param parameter, const std::string& info, int i)
	{
		if (i < 0 || i > 7)
			return;
		switch (parameter)
		{
			case FIRST_NAME:
				contact[i].first_name = info;
				break;
			case LAST_NAME:
				contact[i].last_name = info;
				break;
			case NICKNAME:
				contact[i].nickname = info;
				break;
			case PHONE_NUMBER:
				contact[i].phone_number = info;
				break;
			case DARKEST_SECRET:
				contact[i].darkest_secret = info;
				break;
		}
	}

	std::string truncate_string(const std::string& str) const
	{
        if (str.size() > 10) {
            return str.substr(0, 9) + '.';
        }
        return str;
    }

	void display_phonebook()
	{
        std::cout << std::setw(10) << "Index" << "|"
                  << std::setw(10) << "First Name" << "|"
                  << std::setw(10) << "Last Name" << "|"
                  << std::setw(10) << "Nickname" << "|" << std::endl;
        for (int i = 0; i < 8; i++) {
            std::cout << std::setw(10) << i << "|"
                      << std::setw(10) << truncate_string(contact[i].first_name) << "|"
                      << std::setw(10) << truncate_string(contact[i].last_name) << "|"
                      << std::setw(10) << truncate_string(contact[i].nickname) << "|" << std::endl;;
        }
    }

    void display_contact(const std::string& index) const
	{
        int i = std::atoi(index.c_str());
        if (i >= 0 && i < 8) {
            std::cout << "First Name: " << contact[i].first_name << "\n"
                      << "Last Name: " << contact[i].last_name << "\n"
                      << "Nickname: " << contact[i].nickname << "\n"
                      << "Phone Number: " << contact[i].phone_number << "\n"
                      << "Darkest Secret: " << contact[i].darkest_secret << "\n";
        } else {
            std::cout << "Error. Invalid index\n";
        }
    }

	void	push_contacts_up()
	{
		for (int i = 1; i < 8; i++)
			contact[i - 1] = contact[i];
		contact[7] = Contact();
	}
};

/* input_utils.cpp */
void		parse_input(std::string input, PhoneBook &phone_book);

/* utils.cpp */
void		perror_exit(char *str, int error);
