/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:28:09 by tiaferna          #+#    #+#             */
/*   Updated: 2024/07/09 15:35:25 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::debug(void)
{
	std::cout << "[DEBUG]" <<std:: endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "[INFO]" <<std:: endl;
	std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
	std::cout << "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "[WARNING]" <<std:: endl;
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << "I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "[ERROR]" <<std:: endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level)
{
	int	codeLevel = DEBUG;
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	while (codeLevel <= ERROR && levels[codeLevel] != level)
		codeLevel++;

	void	(Harl::*func[4]) () = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	switch (codeLevel)
	{
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break ;
		case DEBUG:
			(this->*func[codeLevel++]) ();
			// fall through
		case INFO:
			(this->*func[codeLevel++]) ();
			// fall through
		case WARNING:
			(this->*func[codeLevel++]) ();
			// fall through
		case ERROR:
			(this->*func[codeLevel]) ();
	}
}
