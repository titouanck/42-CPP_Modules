/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 17:57:15 by tchevrie          #+#    #+#             */
/*   Updated: 2023/05/24 20:45:32 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <functional>
#include <ctime>
#include <locale>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout \
	<< "accounts:" << _nbAccounts \
	<< ";total:" << _totalAmount \
	<< ";deposits:" << _totalNbDeposits \
	<< ";withdrawals:" << _totalNbWithdrawals << std::endl;
}


void	Account::makeDeposit(int deposit)
{
	Account::_displayTimestamp();
	std::cout \
	<< "index:" << _accountIndex \
	<< ";p_amount:" << _amount \
	<< ";deposit:" << deposit \
	<< ";amount:" << _amount + deposit \
	<< ";nb_deposits:" << _nbDeposits + 1 << std::endl;
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits += 1;
	_totalNbDeposits += 1;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	Account::_displayTimestamp();
	if (_amount < withdrawal)
	{
		std::cout \
		<< "index:" << _accountIndex \
		<< ";p_amount:" << _amount \
		<< ";withdrawal:" << "refused" << std::endl;
		return (false);
	}
	std::cout \
	<< "index:" << _accountIndex \
	<< ";p_amount:" << _amount \
	<< ";withdrawal:" << withdrawal \
	<< ";amount:" << _amount - withdrawal \
	<< ";nb_withdrawals:" << _nbWithdrawals + 1 << std::endl;
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_nbWithdrawals += 1;
	_totalNbWithdrawals += 1;
	return (true);
}

int		Account::checkAmount(void) const
{
	return (_amount);
}

void	Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout \
	<< "index:" << _accountIndex \
	<< ";amount:" << _amount \
	<< ";deposits:" << _nbDeposits \
	<< ";withdrawals:" << _nbWithdrawals << std::endl;
	return ;
}

void	Account::_displayTimestamp(void)
{
	time_t		rawTime;
	struct tm	t_rawTime;
	char		str[42];
	
	rawTime = time(&rawTime);
	if (rawTime <= 0)
		return ;
	t_rawTime = *localtime(&rawTime);
	strftime(str, sizeof(str), "%Y%m%d_%H%M%S", &t_rawTime);
	std::cout << '[' << str << "] ";
}

Account::Account(int initial_deposit) : _amount(initial_deposit), _accountIndex(_nbAccounts)
{
	_totalAmount += _amount;
	_nbAccounts += 1;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	Account::_displayTimestamp();
	std::cout \
	<< "index:" << _accountIndex \
	<< ";amount:" << _amount \
	<< ";created" << std::endl;
}

Account::~Account(void)
{
	_totalAmount -= _amount;
	_nbAccounts -= 1;
	Account::_displayTimestamp();
	std::cout \
	<< "index:" << _accountIndex \
	<< ";amount:" << _amount \
	<< ";closed" << std::endl;
}
