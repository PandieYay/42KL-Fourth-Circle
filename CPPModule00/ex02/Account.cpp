#include "Account.hpp"
#include <iostream>
#include <ctime>

using std::cout;

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp(void)
{
	// Uncomment line below and comment everything else to do diff test
	// cout << "[19920104_091532] ";
	std::time_t now = time(0);
	std::tm	*ltime = std::localtime(&now);
	cout << "[" << ltime->tm_year + 1900;
	if (ltime->tm_mon + 1 < 10)
		cout << "0";
	cout <<	ltime->tm_mon + 1;
	if (ltime->tm_mday + 1 < 10)
		cout << "0";
	cout << ltime->tm_mday << "_";
	if (ltime->tm_hour + 1 < 10)
		cout << "0";
	cout << ltime->tm_hour;
	if (ltime->tm_min + 1 < 10)
		cout << "0";
	cout << ltime->tm_min;
	if (ltime->tm_sec + 1 < 10)
		cout << "0";
	cout << ltime->tm_sec << "] ";
}

int	Account::getNbAccounts(void)
{
	return (0);
}

int	Account::getTotalAmount(void)
{
	return (0);
}

int	Account::getNbDeposits(void)
{
	return (0);
}

int	Account::getNbWithdrawals(void)
{
	return (0);
}

void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:" << 
	_totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << "\n";
}

Account::Account(int initial_deposit)
{
	_displayTimestamp();
	++_nbAccounts;
	_totalAmount += initial_deposit;
	_accountIndex = _nbAccounts - 1;
	cout << "index:" << _accountIndex << ";amount:" << initial_deposit << ";created\n";
	_amount = initial_deposit;
}

Account::~Account()
{
	_displayTimestamp();
	cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed\n";
}

void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:" << deposit << ";amount:";
	_amount += deposit;
	_totalAmount += deposit;
	++_nbDeposits;
	++_totalNbDeposits;
	cout << _amount << ";nb_deposits:" << _nbDeposits << "\n";
}

bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:";
	if (withdrawal > _amount)
	{
		cout << "refused\n";
		return (false);
	}
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	++_nbWithdrawals;
	++_totalNbWithdrawals;
	cout << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << "\n";
	return (true);
}

int Account::checkAmount(void) const
{
	cout << "Checked amount\n";
	return (0);
}


void Account::displayStatus(void) const
{
	_displayTimestamp();
	cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << "\n";
}
