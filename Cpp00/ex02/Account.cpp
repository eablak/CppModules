#include "Account.hpp"
#include <iomanip>
// #include <ctime>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts()
{
	return (_nbAccounts); // this ?
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

int Account::checkAmount() const /*
Burada, checkAmount() fonksiyonunun const olarak işaretlenmesi,
	fonksiyonun sınıfın durumunu değiştirmeyeceği ve nesnenin veri üyelerini değiştirmeyeceği anlamına gelir. Yani,
	checkAmount() fonksiyonu nesne durumunu okumaya yönelik bir işlem yapacak,
	ancak nesneyi değiştirmeyecek. Bu,
	fonksiyonun const-correctness prensibine uygun olarak tanımlandığını gösterir.*/
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
	_displayTimestamp();
	std::cout << "index: " << this->_accountIndex 
			<< ";" << "amount: " << this->checkAmount()
			<< ";" << "created" << std::endl;
	this->_totalAmount += _amount;
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << "index: " << this->_accountIndex
			<< ";" << "amount: " << this->_amount
			<< ";" << "closed" << std::endl ;
	return ;
}

void Account::_displayTimestamp()
{
	std::time_t t = std::time(NULL);
	std::tm now = *localtime(&t);
	std::cout
		<< "["
		<< (now.tm_year + 1900)
		<< std::setfill('0')
		<< std::setw(2) << now.tm_mon + 1
		<< std::setw(2) << now.tm_mday << "_"
		<< std::setw(2) << now.tm_hour
		<< std::setw(2) << now.tm_min
		<< std::setw(2) << now.tm_sec
		<< "] ";
}

void Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "accounts: " << getNbAccounts()
				<< ";" << "total: " << getTotalAmount()
				<< ";" << "deposits: " << getNbDeposits()
				<< ";" << "withdrawals: " << getNbWithdrawals() << std::endl;
}

void Account::displayStatus() const
{
	_displayTimestamp();
	std::cout << "index: " << this->_accountIndex
				<< ";" << "amount: " << this->_amount
				<< ";" << "deposits: " << this->_nbDeposits
				<< ";" << "withdrawals: " << this->_nbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index: " << this->_accountIndex
			<< ";" << "p_amount: " << this->_amount
			<< ";" << "deposit: " << deposit;
	this->_amount += deposit;
	_totalAmount += deposit;
	_totalNbDeposits++;
	std::cout << ";" << "amount: " << this->_amount
			<< ";" << "nb_deposits: " << ++this->_nbDeposits
			<< std::endl;
	
}

bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index: " << _accountIndex << ";"
			<< "p_amount: " << _amount << ";"
			<< "withdrawal: ";

	if (this->_amount < withdrawal){
		std::cout << "refused" << std::endl;
		return false;
	}
	else{
		std::cout << withdrawal << ";";
		this->_amount -= withdrawal;
		_totalAmount -= withdrawal;
		this->_nbWithdrawals++;
		_totalNbWithdrawals++;
		std::cout << "amount: " << this->_amount
				<< "nb_withdrawals: " << this->_nbWithdrawals
				<< std::endl;
				return true;
	}
}
