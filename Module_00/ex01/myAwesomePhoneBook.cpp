/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myAwesomePhoneBook.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 09:29:21 by tiaferna          #+#    #+#             */
/*   Updated: 2024/06/25 15:39:45 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myAwesomePhoneBook.hpp"

int	main()
{
	PhoneBook	phoneBook;
	std::string	input = "";
	bool		prompt = true;

	while (prompt)
	{
		std::cout << std::endl << "* PhoneBook *" << std::endl <<std::endl;
		std::cout << "ADD | SEARCH | EXIT" << std::endl;
		while (!(input.compare("""")))
		{
			input = inputGetter(input, &prompt);
			if (prompt == false)
				break ;
			if (!(input.compare("""")))
				continue ;
			if (parseInput(input, phoneBook, &prompt) == 0)
				prompt = false;
		}
		input = "";
	}
}
