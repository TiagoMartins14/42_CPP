/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 14:40:44 by tiaferna          #+#    #+#             */
/*   Updated: 2024/06/25 15:35:39 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "myAwesomePhoneBook.hpp"

class Contact
{
private:
	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickname;
	std::string	_phoneNumber;
	std::string	_darkestSecret;

public:
	Contact();

	std::string	getFirstName() const;
	std::string	getLastName() const;
	std::string	getNickname() const;
	std::string	getPhoneNumber() const;
	std::string	getDarkestSecret() const;
	
	void		setFirstName(const std::string &firstName);
	void		setLastName(const std::string &lastName);
	void		setNickname(const std::string &nickname);
	void		setPhoneNumber(const std::string &phoneNumber);
	void		setDarkestSecret(const std::string &darkestSecret);
};
