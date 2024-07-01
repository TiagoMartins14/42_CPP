/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replaceText.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:42:36 by tiaferna          #+#    #+#             */
/*   Updated: 2024/07/01 15:45:03 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SedIsForLosers.hpp"

void	replaceText(std::ifstream &inFile, std::ofstream &outFile, const std::string &searchStr, const std::string &replaceStr)
{
	std::string	textLine;
	std::string	output;
	std::size_t	startPos;
	std::size_t	foundPos;

	while (std::getline(inFile, textLine)) {
		startPos = 0;
		output.clear();
		while (true)
		{
			foundPos = textLine.find(searchStr, startPos);
			if (foundPos == std::string::npos)
			{
				output += textLine.substr(startPos);
				break;
			}
			output += textLine.substr(startPos, foundPos - startPos);
			output += replaceStr;
			startPos = foundPos + searchStr.size();
		}
		outFile << output << std::endl;
	}
}
