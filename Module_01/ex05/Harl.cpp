/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:28:09 by tiaferna          #+#    #+#             */
/*   Updated: 2024/07/01 18:31:16 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::debug(void)
{
	std::cout << "DEBUG: I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "INFO: I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "WARNING: I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "ERROR: This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level)
{
	int	code = DEBUG;
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	while (code <= ERROR && levels[code] != level)
		code++;
	if (code > ERROR)
	{
		std::cout << "UNKNOWN: I hate it when you put a level that doesn't exist!" << std::endl;
		return ;
	}

	void	(Harl::*func[4]) () = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	(this->*func[code]) ();
}
