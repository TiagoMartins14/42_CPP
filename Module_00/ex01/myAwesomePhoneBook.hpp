/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myAwesomePhoneBook.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 08:14:46 by tiaferna          #+#    #+#             */
/*   Updated: 2024/06/25 15:39:24 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <cctype>
#include <limits>

typedef enum e_param
{
	FIRST_NAME,
	LAST_NAME,
	NICKNAME,
	PHONE_NUMBER,
	DARKEST_SECRET,
}	t_param;

typedef enum e_word_amount
{
	SINGLE_WORD,
	MULTIPLE_WORDS,
}	t_word_amount;

#include "Contact.hpp"
#include "PhoneBook.hpp"

/* input_utils.cpp */
int			parseInput(std::string input, PhoneBook &phone_book, bool *prompt);

/* utils.cpp */
std::string	inputGetter(std::string input, bool *prompt);