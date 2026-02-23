/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wuabdull <wuabdull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 22:51:31 by wuabdull          #+#    #+#             */
/*   Updated: 2026/02/23 22:51:32 by wuabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts(void)
{
	return Account::_nbAccounts;
}

int	Account::getTotalAmount(void)
{
	return Account::_totalAmount;
}

int	Account::getNbDeposits(void)
{
	return Account::_totalNbDeposits;
}

int	Account::getNbWithdrawals(void)
{
	return Account::_totalNbWithdrawals;
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts
			  << ";total:" << _totalAmount
			  << ";deposits:" << _totalNbDeposits
			  << ";withdrawals:" << _totalNbWithdrawals
			  << "\n";
}

Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;

	_nbAccounts = _nbAccounts + 1;
	_totalAmount = _totalAmount + _amount;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";amount:" << _amount
			  << ";created\n";
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";amount:" << _amount
			  << ";closed\n";

	_nbAccounts = _nbAccounts - 1;
	_totalAmount = _totalAmount - _amount;
}

void	Account::makeDeposit(int deposit)
{
	int	p_amount;

	p_amount = _amount;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";p_amount:" << p_amount
			  << ";deposit:" << deposit;

	_amount = _amount + deposit;
	_nbDeposits = _nbDeposits + 1;

	_totalAmount = _totalAmount + deposit;
	_totalNbDeposits = _totalNbDeposits + 1;

	std::cout << ";amount:" << _amount
			  << ";nb_deposits:" << _nbDeposits
			  << "\n";
}

bool	Account::makeWithdrawal(int withdrawal)
{
	int	p_amount;

	p_amount = _amount;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";p_amount:" << p_amount
			  << ";withdrawal:";

	if (withdrawal > _amount)
	{
		std::cout << "refused\n";
		return false;
	}

	_amount = _amount - withdrawal;
	_nbWithdrawals = _nbWithdrawals + 1;

	_totalAmount = _totalAmount - withdrawal;
	_totalNbWithdrawals = _totalNbWithdrawals + 1;

	std::cout << withdrawal
			  << ";amount:" << _amount
			  << ";nb_withdrawals:" << _nbWithdrawals
			  << "\n";
	return true;
}

int	Account::checkAmount(void) const
{
	return _amount;
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";amount:" << _amount
			  << ";deposits:" << _nbDeposits
			  << ";withdrawals:" << _nbWithdrawals
			  << "\n";
}

void	Account::_displayTimestamp(void)
{
	std::time_t	now;
	std::tm		*t;
	char		buf[20];

	now = std::time(NULL);
	t = std::localtime(&now);
	std::strftime(buf, sizeof(buf), "%Y%m%d_%H%M%S", t);

	std::cout << "[" << buf << "] ";
}
