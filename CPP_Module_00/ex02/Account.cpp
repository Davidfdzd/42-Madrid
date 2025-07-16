/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfernan3 <dfernan3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:28:55 by dfernan3          #+#    #+#             */
/*   Updated: 2025/06/24 16:51:53 by dfernan3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>

int Account::_nbAccounts = 0;

int Account::_totalAmount = 0;

int Account::_totalNbDeposits = 0;

int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit){
    _accountIndex = _nbAccounts;
    _amount = initial_deposit;
    _totalAmount += initial_deposit;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _nbAccounts++;
    Account::_displayTimestamp();
    std::cout<<"index:"<<_accountIndex<<";amount:"<<_amount<<";created"<<std::endl;
}
	
Account::~Account(void){
    _displayTimestamp();
    std::cout<<"index:"<<_accountIndex << ";amount:"<<_amount<<";closed"<<std::endl;
}

int Account::getNbAccounts(void)
{
    return(Account::_nbAccounts);
}

int Account::getTotalAmount(void)
{
    return(Account::_totalAmount);
}

int Account::getNbDeposits(void)
{
    return(Account::_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
    return(Account::_totalNbWithdrawals);
}

void Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout<<"accounts:"<<_nbAccounts<<";total:"<<_totalAmount<<";deposits:"<<_totalNbDeposits<<";withdrawals:"<<_totalNbWithdrawals<<std::endl;
}

void Account::makeDeposit(int deposit)
{
    _displayTimestamp();
    std::cout<<"index:"<<_accountIndex<<";p_amount:"<<_amount<<";deposit:"<<deposit;
    _nbDeposits++;
    _totalNbDeposits++;
    _amount += deposit;
    _totalAmount += deposit;
    std::cout<<";amount:"<<_amount<<";nb_deposits:"<<_nbDeposits<<std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp();
    std::cout<<"index:"<<_accountIndex<<";p_amount:"<<_amount;
    if (withdrawal > checkAmount())
    {
        std::cout<<";withdrawal:refused"<<std::endl;
        return(false);
    }
    _nbWithdrawals++;
    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;
    _amount -= withdrawal;
    std::cout<<";withdrawal:"<<withdrawal<<";amount:"<<_amount<<";nb_withdrawals:"<<_nbWithdrawals<<std::endl;
    return(true);
}

int	 Account::checkAmount(void) const
{
    return(_amount);
}

void Account::displayStatus( void ) const
{
    _displayTimestamp();
    std::cout<<"index:"<<_accountIndex<<";amount:"<<_amount<<";deposits:"<<_nbDeposits<<";withdrawals:"<<_nbWithdrawals<<std::endl;
}

void Account::_displayTimestamp(void)
{
    time_t now;

    now = time(NULL);
    struct tm *lt = localtime(&now);

	std::cout << '['
		<< (lt->tm_year + 1900)
		<< std::setfill('0') << std::setw(2) << lt->tm_mon + 1
		<< std::setfill('0') << std::setw(2) << lt->tm_mday << '_'
		<< std::setfill('0') << std::setw(2) << lt->tm_hour
		<< std::setfill('0') << std::setw(2) << lt->tm_min
		<< std::setfill('0') << std::setw(2) << lt->tm_sec
		<< "] ";
}