/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:41:35 by tiaferna          #+#    #+#             */
/*   Updated: 2024/07/01 15:43:03 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SedIsForLosers.hpp"

static void perror_cpp(const std::string &message)
{
    std::cerr << message << ": " << std::strerror(errno) << std::endl;
}

void	perrorExit(std::string errorMsg, std::ifstream &inFile, std::ofstream &outFile)
{
	if (inFile.is_open())
		inFile.close();
	if (outFile.is_open())
		outFile.close();
	perror_cpp(errorMsg);
	exit(2);
}
