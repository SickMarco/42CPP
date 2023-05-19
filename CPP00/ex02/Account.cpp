#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>
#include <sstream>

Account::Account(int initial_deposit)
{
	static int index = 0;

	_accountIndex = index;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	index++;
}

Account::~Account()
{
}

int	Account::getNbAccounts( void ) { return _nbAccounts; }
int	Account::getTotalAmount( void ) { return _totalAmount; }
int	Account::getNbDeposits( void ) { return _totalNbDeposits; }
int	Account::getNbWithdrawals( void ) { return _totalNbWithdrawals; }

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	_amount += deposit;
	_nbDeposits++;
}

void	Account::_displayTimestamp( void )
{
    char timestamp[15];

	std::time_t now = std::time(NULL);
    std::tm* localTime = std::localtime(&now);
	std::strftime(timestamp, sizeof(timestamp), "%Y%m%d_%H%M%S", localTime);
    std::cout << "[" << timestamp << "] ";
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";"\
				<< "total:"	<< getTotalAmount() << ";"\
				<< "deposits:"	<< getNbDeposits() << ";"\
				<< "withdrawals" << getNbDeposits() << std::endl;
}
