/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 18:34:59 by tiaferna          #+#    #+#             */
/*   Updated: 2024/06/24 16:06:45 by tiaferna         ###   ########.fr       */
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
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbAccounts++;
	_totalAmount += _amount;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex 
			  << ";amount:" << initial_deposit
			  << ";created" << std::endl;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex 
			  << ";amount:" << _amount
			  << ";closed" << std::endl;
}

void	Account::makeDeposit(int deposit)
{	
	_nbDeposits++;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex 
			  << ";p_amount:" << _amount
			  << ";deposit:" << deposit
			  << ";amount:" << (_amount + deposit)
			  << ";nb_deposits:" << _nbDeposits << std::endl;
	
	_amount += deposit;
	_totalNbDeposits++;
	_totalAmount += deposit;
}

bool	Account::makeWithdrawal(int withdrawal)
{	
	_displayTimestamp();
	if (_amount - withdrawal < 0)
	{
		std::cout << "index:" << _accountIndex
				  << ";p_amount:" << _amount
				  << ";withdrawal:refused" << std::endl;
		return false;
	}
	
	_nbWithdrawals++;

	std::cout << "index:" << _accountIndex 
			  << ";p_amount:" << _amount
			  << ";withdrawal:" << withdrawal
			  << ";amount:" << (_amount - withdrawal)
			  << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
			  
	_amount -= withdrawal;
	_totalNbWithdrawals++;
	_totalAmount -= withdrawal;
	return true;
}

int		Account::checkAmount( void ) const
{
	return	_amount;
}

void	Account::displayStatus(void) const
{	
	_displayTimestamp();
	std::cout << "index:" << _accountIndex 
			  << ";amount:" << _amount
			  << ";deposits:" << _nbDeposits
			  << ";withdrawals:" << _nbWithdrawals << std::endl;
}
