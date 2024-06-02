/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 16:43:48 by tiaferna          #+#    #+#             */
/*   Updated: 2024/06/02 21:33:04 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Megaphone
{
public:
	void	Scream(const std::string &str)
	{
		for (size_t i = 0; i < str.size(); i++)
			std::cout << (char)toupper((unsigned char)str[i]);
	}
};

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		Megaphone speaker;
		for (int i = 1; i < argc; i++)
			speaker.Scream(argv[i]);
		std::cout << std::endl;
	}
}
