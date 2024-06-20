/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 18:34:59 by tiaferna          #+#    #+#             */
/*   Updated: 2024/06/20 22:58:45 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void) { return Account::_nbAccounts; }

int Account::getTotalAmount(void) { return Account::_totalAmount; }

int Account::getNbDeposits(void) { return Account::_totalNbDeposits; }

int Account::getNbWithdrawals(void) { return Account::_totalNbWithdrawals; }

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();

	std::cout << "accounts:" << Account::getNbAccounts()
			  << ";total:" << Account::getTotalAmount()
			  << ";deposits:" << Account::getNbDeposits()
			  << ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

Account::Account(int initial_deposit)
{
	_displayTimestamp();
	
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbAccounts++;
	_totalAmount += _amount;
}

void	Account::_displayTimestamp()
{
	std::time_t now = std::time(0);

	std::tm* localTime = std::localtime(&now);
	
	std::cout << "[" << (localTime->tm_year + 1900)
			  << std::setw(2) << std::setfill('0') << (localTime->tm_mon + 1)
			  << std::setw(2) << std::setfill('0') << localTime->tm_mday << "_"
			  << std::setw(2) << std::setfill('0') << localTime->tm_hour
			  << std::setw(2) << std::setfill('0') << localTime->tm_min
			  << std::setw(2) << std::setfill('0') << localTime->tm_sec << "] ";
}