/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 11:27:04 by tiaferna          #+#    #+#             */
/*   Updated: 2024/06/28 12:27:17 by tiaferna         ###   ########.fr       */
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
	}
}
