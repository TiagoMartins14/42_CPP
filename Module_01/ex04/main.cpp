/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 11:27:04 by tiaferna          #+#    #+#             */
/*   Updated: 2024/07/01 15:44:58 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SedIsForLosers.hpp"

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
		inFile.close();
		outFile.close();
	}
}
