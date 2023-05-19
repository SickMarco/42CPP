#include "Account.hpp"
#include <iostream>

Account::Account(int initial_deposit)
{
}

Account::~Account()
{
}

void	Account::makeDeposit( int deposit )
{ 
	_amount += deposit;
	_nbDeposits++;
}

int	Account::getNbAccounts( void ) { return _nbAccounts; }
int	Account::getTotalAmount( void ) { return _totalAmount; }
int	Account::getNbDeposits( void ) { return _totalNbDeposits; }
int	Account::getNbWithdrawals( void ) { return _totalNbWithdrawals; }

void	Account::displayAccountsInfos( void )
{
	std::cout << "accounts:" << Account::getNbAccounts() << ";"\
				<< "total:"	<< Account::getTotalAmount() << ";"\
				<< "deposits:"	<< Account::getNbDeposits() << ";"\
				<< "withdrawals" << Account::getNbDeposits() << std::endl;
}