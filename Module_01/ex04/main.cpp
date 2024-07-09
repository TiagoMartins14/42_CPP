/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 11:27:04 by tiaferna          #+#    #+#             */
/*   Updated: 2024/07/09 16:50:30 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SedIsForLosers.hpp"

int	main(int argc, char **argv)
{
	if ( argc == 4)
	{
		const std::string o_string = argv[2];
		const std::string r_string = argv[3];
		std::ifstream	inFile;
		std::ofstream	outFile;
		std::string		outFileName = createOutFileName(argv[1]);

		if (openInFile(inFile, argv[1]) == false)
			perrorExit("Error", inFile, outFile);
		if (openOutFile(outFile, outFileName) == false)
			perrorExit("Error", inFile, outFile);
		if (!o_string.size())
			return 0;
		replaceText(inFile, outFile, o_string, r_string);
		inFile.close();
		outFile.close();
	}
}
