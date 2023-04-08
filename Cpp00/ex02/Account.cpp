#include "Account.hpp"
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts()
{
	return (_nbAccounts); //static olduğu için böyle ulaşbiliyosun!!
							//yukarıda Account yine tanımlı olmak zorunda tekrarb ak
}

int Account::getTotalAmount()
{
	return (_totalAmount);
}

int Account::getNbDeposits()
{
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals()
{
	return (_totalNbWithdrawals);
}

int Account::checkAmount() const
{
	return (this->_amount);
}

Account::Account(int initial_deposit)
{
	this->_accountIndex = _nbAccounts;
	_nbAccounts++;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	//this->_displayTimestamp();
	std::cout << "index: " << this->_accountIndex
			<< ";"	<< "amount: " << this->checkAmount()
			<< ";"	<< "created" << std::endl;
	this->_totalAmount += initial_deposit;
}