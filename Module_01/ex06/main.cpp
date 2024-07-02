/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:19:42 by tiaferna          #+#    #+#             */
/*   Updated: 2024/07/02 14:56:37 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: Usage: ./Harl2.0 [code_level]" << std::endl;
		return 1;
	}

	std::string	level = argv[1];
	Harl		Harl;
	
	Harl.complain(level);
}
