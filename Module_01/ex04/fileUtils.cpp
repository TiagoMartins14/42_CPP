/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fileUtils.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:42:13 by tiaferna          #+#    #+#             */
/*   Updated: 2024/07/01 15:44:39 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SedIsForLosers.hpp"

bool	openInFile( std::ifstream &inFile, const std::string &fileName)
{
	inFile.open(fileName.c_str());
	if (!inFile.is_open())
		return false;
	return true;
}

bool	openOutFile( std::ofstream &outFile, const std::string &fileName)
{
	outFile.open(fileName.c_str());
	if (!outFile.is_open())
		return false;
	return true;
}

std::string	createOutFileName(std::string inFileName)
{
	std::string	outFileName;
	int			j;

	for (int i = inFileName.size(); i >= 0; i--)
	{
		if (inFileName[i] == '.')
		{
			j = i;
			break ;
		}
	}
	outFileName = inFileName.substr(0, j);
	outFileName.append(".replace");	
	return outFileName;
}
