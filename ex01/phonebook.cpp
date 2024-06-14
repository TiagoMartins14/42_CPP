/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 09:29:21 by tiaferna          #+#    #+#             */
/*   Updated: 2024/06/14 14:42:29 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

static std::string	input_getter(std::string input, bool *prompt)
{
	if (!(std::cin >> input))
	{
		if (std::cin.eof())
			*prompt = false;
	}
	return input;
}

int	main()
{
	PhoneBook	phone_book;
	std::string	input = "";
	bool		prompt = true;

	while (prompt)
	{
		std::cout << std::endl << "* PhoneBook *" << std::endl <<std::endl;
		std::cout << "ADD | SEARCH | EXIT" << std::endl;
		while (!(input.compare("""")))
		{
			input = input_getter(input, &prompt);
			if (prompt == false)
				break ;
			if (!(input.compare("""")))
				continue ;
			if (parse_input(input, phone_book, &prompt) == 0)
				prompt = false;
		}
		input = "";
	}
}
