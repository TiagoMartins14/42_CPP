/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 11:27:04 by tiaferna          #+#    #+#             */
/*   Updated: 2024/07/20 15:43:58 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SedIsForLosers.hpp"

int main(int argc, char **argv)
{
	if (argc == 4)
	{
		std::string o_string = argv[2];
		std::string r_string = argv[3];
		std::ifstream inFile;
		std::ofstream outFile;
		std::string inFileName = argv[1];
		std::string outFileName = inFileName.append(".replace");

		if (openInFile(inFile, argv[1]) == false)
			perrorExit("Error", inFile, outFile);
		if (openOutFile(outFile, outFileName) == false)
			perrorExit("Error", inFile, outFile);
		if (!o_string.size())
			copyFile(inFile, outFile);
		replaceText(inFile, outFile, o_string, r_string);
		inFile.close();
		outFile.close();
	}
	else
		std::cout << "Error: Usage: ./SedIsForLosers [infile name] [word] [word replacer]" << std::endl;
}
