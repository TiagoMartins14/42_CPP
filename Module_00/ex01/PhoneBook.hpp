/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 14:42:45 by tiaferna          #+#    #+#             */
/*   Updated: 2024/06/25 15:28:44 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "myAwesomePhoneBook.hpp"

class PhoneBook
{
private:
	Contact _contact[8];

	int		_savedContacts;
	
public:
	PhoneBook();

	int			getSavedContacts(void);

	void		setSavedContacts(const int value);

	void		addInfo(t_param parameter, const std::string &info, int i);

	std::string truncateString(const std::string& str) const;

	void		displayPhonebook();

    void		displayContact(const std::string& index);

	void		pushContactsUp();
};
