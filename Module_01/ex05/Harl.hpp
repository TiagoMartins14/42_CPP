/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:06:33 by tiaferna          #+#    #+#             */
/*   Updated: 2024/07/01 17:59:27 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>

enum codeLevel
{
	DEBUG,
	INFO,
	WARNING,
	ERROR,
};

class Harl
{
private:

	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);

public:

	void	complain(std::string level);
};
