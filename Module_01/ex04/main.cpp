/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 11:27:04 by tiaferna          #+#    #+#             */
/*   Updated: 2024/06/30 15:04:46 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cerrno>
#include <cstdlib>

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

int	main(int argc, char **argv)
{
	if ( argc == 4)
	{
		std::ifstream	inFile;
		std::ofstream	outFile;
		std::string		outFileName = createOutFileName(argv[1]);

		if (openInFile(inFile, argv[1]) == false)
			perrorExit("Error", inFile, outFile);
		if (openOutFile(outFile, outFileName) == false)
			perrorExit("Error", inFile, outFile);
		replaceText(inFile, outFile, argv[2], argv[3]);
	}
}
