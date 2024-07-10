/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SedIsForLosers.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:39:47 by tiaferna          #+#    #+#             */
/*   Updated: 2024/07/10 14:38:46 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cerrno>
#include <cstdlib>

// error.cpp
void		perrorExit(std::string errorMsg, std::ifstream &inFile, std::ofstream &outFile);

//  fileUtils.cpp
bool		openInFile( std::ifstream &inFile, const std::string &fileName);
bool		openOutFile( std::ofstream &outFile, const std::string &fileName);

//  replaceText.cpp
void		replaceText(std::ifstream &inFile, std::ofstream &outFile, const std::string &searchStr, const std::string &replaceStr);
