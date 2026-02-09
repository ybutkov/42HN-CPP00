/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybutkov <ybutkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 23:15:58 by ybutkov           #+#    #+#             */
/*   Updated: 2026/02/09 15:34:17 by ybutkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>
#include <chrono>

namespace
{
	std::tm get_test_date()
	{
		std::tm datetime = {};
		datetime.tm_year = 1992 - 1900;
		datetime.tm_mon  = 0;
		datetime.tm_mday = 4;
		datetime.tm_hour = 9;
		datetime.tm_min  = 15;
		datetime.tm_sec  = 32;

		return datetime;
	}
} // end namespace

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(void): _accountIndex(0), _amount(0), _nbDeposits(0), _nbWithdrawals(0)
{
}

Account::Account(int initial_deposit)
	: _amount(initial_deposit)
{
	_accountIndex = Account::getNbAccounts();
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex
				<< ";amount:" << _amount
				<< ";created" << std::endl;
	Account::_nbAccounts += 1;
	Account::_totalAmount += initial_deposit;
}

Account::~Account(void)
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex
				<< ";amount:" << _amount
				<< ";closed" << std::endl;
}

void Account::makeDeposit(int deposit)
{
	int	p_amount;

	p_amount = _amount;
	_amount += deposit;
	Account::_totalAmount += deposit;
	_nbDeposits += 1;
	Account::_totalNbDeposits += 1;
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex
				<< ";p_amount:" << p_amount
				<< ";deposit:" << deposit
				<< ";amount:" << _amount
				<< ";nb_deposits:" << _nbDeposits
				<< std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	int	p_amount;

	p_amount = _amount;
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex
				<< ";p_amount:" << p_amount;
	if (_amount < withdrawal)
	{
		std::cout << ";withdrawal:"
					<< "refused"
					<< std::endl;
		return (false);
	}
	_amount -= withdrawal;
	Account::_totalAmount -= withdrawal;
	_nbWithdrawals += 1;
	Account::_totalNbWithdrawals += 1;
	std::cout << ";withdrawal:" << withdrawal
				<< ";amount:" << _amount
				<< ";nb_withdrawals:" << _nbWithdrawals
				<< std::endl;
	return (true);
}

int Account::checkAmount(void) const
{
	return (_amount);
}

void Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex
				<< ";amount:" << _amount
				<< ";deposits:" << _nbDeposits
				<< ";withdrawals:" << _nbWithdrawals
				<< std::endl;
}

// Static
int Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

void Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts()
				<< ";total:" << Account::getTotalAmount()
				<< ";deposits:" << Account::getNbDeposits()
				<< ";withdrawals:" << Account::getNbWithdrawals()
				<< std::endl;
}

void Account::_displayTimestamp(void)
{
	std::tm datetime;
	std::time_t t = std::time(nullptr);

	// datetime = get_test_date(); (void)t;
	localtime_r(&t, &datetime); (void)get_test_date;

	std::cout << "[" << std::put_time(&datetime, "%Y%m%d_%H%M%S") << "] ";
}
