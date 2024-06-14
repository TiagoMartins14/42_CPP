/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 08:14:46 by tiaferna          #+#    #+#             */
/*   Updated: 2024/06/14 14:54:32 by tiaferna         ###   ########.fr       */
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
private:
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;

public:
	Contact()
	{
		first_name = "";
		last_name = "";
		nickname = "";
		phone_number = "";
		darkest_secret = "";
	}

	std::string	get_first_name() const { return first_name; }
	std::string	get_last_name() const { return last_name; }
	std::string	get_nickname() const { return nickname; }
	std::string	get_phone_number() const { return phone_number; }
	std::string	get_darkest_secret() const { return darkest_secret; }
	
	void		set_first_name(const std::string &value) { first_name = value; }
	void		set_last_name(const std::string &value) { last_name = value; }
	void		set_nickname(const std::string &value) { nickname = value; }
	void		set_phone_number(const std::string &value) { phone_number = value; }
	void		set_darkest_secret(const std::string &value) { darkest_secret = value; }
	
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

	void add_info(t_param parameter, const std::string &info, int i)
	{
		if (i < 0 || i > 7)
			return;
		switch (parameter)
		{
			case FIRST_NAME:
				contact[i].set_first_name(info);
				break;
			case LAST_NAME:
				contact[i].set_last_name(info);
				break;
			case NICKNAME:
				contact[i].set_nickname(info);
				break;
			case PHONE_NUMBER:
				contact[i].set_phone_number(info);
				break;
			case DARKEST_SECRET:
				contact[i].set_darkest_secret(info);
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
                      << std::setw(10) << truncate_string(contact[i].get_first_name()) << "|"
                      << std::setw(10) << truncate_string(contact[i].get_last_name()) << "|"
                      << std::setw(10) << truncate_string(contact[i].get_nickname()) << "|" << std::endl;;
        }
    }

    void display_contact(const std::string& index)
	{
        int i = std::atoi(index.c_str());
        if (i >= 0 && i < 8) {
            std::cout << "First Name: " << contact[i].get_first_name() << std::endl
                      << "Last Name: " << contact[i].get_last_name() << std::endl
                      << "Nickname: " << contact[i].get_nickname() << std::endl
                      << "Phone Number: " << contact[i].get_phone_number() << std::endl
                      << "Darkest Secret: " << contact[i].get_darkest_secret() << std::endl;
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
int		parse_input(std::string input, PhoneBook &phone_book, bool *prompt);
