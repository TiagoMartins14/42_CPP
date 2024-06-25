/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 14:38:14 by tiaferna          #+#    #+#             */
/*   Updated: 2024/06/25 15:31:51 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myAwesomePhoneBook.hpp"

PhoneBook::PhoneBook() { _savedContacts = 0; }

int		PhoneBook::getSavedContacts(void) { return _savedContacts; }

void	PhoneBook::setSavedContacts(const int savedContacts) { _savedContacts = savedContacts; }

void	PhoneBook::addInfo(t_param parameter, const std::string &info, int i)
{
	if (i < 0 || i > 7)
		return;
	switch (parameter)
	{
		case FIRST_NAME:
			_contact[i].setFirstName(info);
			break;
		case LAST_NAME:
			_contact[i].setLastName(info);
			break;
		case NICKNAME:
			_contact[i].setNickname(info);
			break;
		case PHONE_NUMBER:
			_contact[i].setPhoneNumber(info);
			break;
		case DARKEST_SECRET:
			_contact[i].setDarkestSecret(info);
			break;
	}
}

std::string truncate_string(const std::string& str)
{
	if (str.size() > 10) {
		return str.substr(0, 9) + '.';
	}
	return str;
}
	
void 		PhoneBook::displayPhonebook()
{
	std::cout << std::setw(10) << "Index" << "|"
				<< std::setw(10) << "First Name" << "|"
				<< std::setw(10) << "Last Name" << "|"
				<< std::setw(10) << "Nickname" << "|" << std::endl;
	for (int i = 0; i < 8; i++) {
		std::cout << std::setw(10) << i << "|"
					<< std::setw(10) << truncate_string(_contact[i].getFirstName()) << "|"
					<< std::setw(10) << truncate_string(_contact[i].getLastName()) << "|"
					<< std::setw(10) << truncate_string(_contact[i].getNickname()) << "|" << std::endl;;
	}
}

void 		PhoneBook::displayContact(const std::string& index)
{
	int i = std::atoi(index.c_str());
	if (i >= 0 && i < 8) {
		std::cout << "First Name: " << _contact[i].getFirstName() << std::endl
					<< "Last Name: " << _contact[i].getLastName() << std::endl
					<< "Nickname: " << _contact[i].getNickname() << std::endl
					<< "Phone Number: " << _contact[i].getPhoneNumber() << std::endl
					<< "Darkest Secret: " << _contact[i].getDarkestSecret() << std::endl;
	} else {
		std::cout << "Error. Invalid index\n";
	}
}

void		PhoneBook::pushContactsUp()
{
	for (int i = 1; i < 8; i++)
		_contact[i - 1] = _contact[i];
	_contact[7] = Contact();
}
