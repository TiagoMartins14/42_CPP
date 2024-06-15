/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 08:14:46 by tiaferna          #+#    #+#             */
/*   Updated: 2024/06/15 14:41:01 by tiaferna         ###   ########.fr       */
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
	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickname;
	std::string	_phoneNumber;
	std::string	_darkestSecret;

public:
	Contact()
	{
		_firstName = "";
		_lastName = "";
		_nickname = "";
		_phoneNumber = "";
		_darkestSecret = "";
	}

	std::string	getFirstName() const { return _firstName; }
	std::string	getLastName() const { return _lastName; }
	std::string	getNickname() const { return _nickname; }
	std::string	getPhoneNumber() const { return _phoneNumber; }
	std::string	getDarkestSecret() const { return _darkestSecret; }
	
	void		setFirstName(const std::string &firstName) { _firstName = firstName; }
	void		setLastName(const std::string &lastName) { _lastName = lastName; }
	void		setNickname(const std::string &nickname) { _nickname = nickname; }
	void		setPhoneNumber(const std::string &phoneNumber) { _phoneNumber = phoneNumber; }
	void		setDarkestSecret(const std::string &darkestSecret) { _darkestSecret = darkestSecret; }
	
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
				contact[i].setFirstName(info);
				break;
			case LAST_NAME:
				contact[i].setLastName(info);
				break;
			case NICKNAME:
				contact[i].setNickname(info);
				break;
			case PHONE_NUMBER:
				contact[i].setPhoneNumber(info);
				break;
			case DARKEST_SECRET:
				contact[i].setDarkestSecret(info);
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
                      << std::setw(10) << truncate_string(contact[i].getFirstName()) << "|"
                      << std::setw(10) << truncate_string(contact[i].getLastName()) << "|"
                      << std::setw(10) << truncate_string(contact[i].getNickname()) << "|" << std::endl;;
        }
    }

    void display_contact(const std::string& index)
	{
        int i = std::atoi(index.c_str());
        if (i >= 0 && i < 8) {
            std::cout << "First Name: " << contact[i].getFirstName() << std::endl
                      << "Last Name: " << contact[i].getLastName() << std::endl
                      << "Nickname: " << contact[i].getNickname() << std::endl
                      << "Phone Number: " << contact[i].getPhoneNumber() << std::endl
                      << "Darkest Secret: " << contact[i].getDarkestSecret() << std::endl;
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
