#include <ctime>
#include <iostream>
#include "Account.hpp"

	int	Account::_nbAccounts = 0;
	int	Account::_totalAmount = 0;
	int	Account::_totalNbDeposits = 0;
	int	Account::_totalNbWithdrawals = 0;

    Account::Account( int initial_deposit ) : _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
	{
    	_displayTimestamp();
		std::cout << "index:" << this->_accountIndex
			<< ";amount:" << checkAmount()
			<< ";created" << std::endl;
		_nbAccounts++;
		_totalAmount += initial_deposit;
    }

	Account::Account( void ) : _accountIndex(-1), _amount(0), _nbDeposits(0), _nbWithdrawals(0){}

	Account::~Account( void ){
		_displayTimestamp();
		std::cout << "index:"  << this->_accountIndex
			<< ";amount:"  << checkAmount()
			<< ";closed" << std::endl;
			_nbAccounts--;
			_totalAmount -= checkAmount();
	}

	//getters
    int	    Account::getNbAccounts( void ){ return _nbAccounts; }
	int	    Account::getTotalAmount( void ){ return _totalAmount; }
	int	    Account::getNbDeposits( void ){ return _totalNbDeposits; }
	int	    Account::getNbWithdrawals( void ){ return _totalNbWithdrawals; }
	int		Account::checkAmount( void ) const { return this->_amount; }

	void    Account::displayAccountsInfos( void )
    {
		_displayTimestamp();
		std::cout << "accounts:" << getNbAccounts()
			<< ";total:" << getTotalAmount()
			<< ";deposits:" << getNbDeposits()
			<< ";withdrawals:" << getNbWithdrawals()
			<< std::endl;
    }

	void	Account::makeDeposit( int deposit )
	{
		int	p_amount;

		p_amount = checkAmount();
		_amount += deposit;
		_nbDeposits++;
		_totalNbDeposits++;
		_totalAmount += deposit;
		_displayTimestamp();
		std::cout << "index:" << _accountIndex
			<< ";p_amount:" << p_amount
			<< ";deposit:" << deposit
			<< ";amount:" << checkAmount()
			<< ";nb_deposits:"  << _nbDeposits
			<< std::endl;
	}

	bool	Account::makeWithdrawal( int withdrawal )
	{
		int	p_amount;

		p_amount = checkAmount();
		_displayTimestamp();
		if (withdrawal <= checkAmount())
		{
			_amount -= withdrawal;
			_nbWithdrawals++;
			_totalNbWithdrawals++;
			_totalAmount -= withdrawal;
			std::cout << "index:" << _accountIndex
				<< ";p_amount:" << p_amount
				<< ";withdrawal:" << withdrawal
				<< ";amount:" << checkAmount()
				<< ";nb_withdrawals:"  << _nbWithdrawals
				<< std::endl;
				return true;
		}
		std::cout << "index:" << _accountIndex
			<< ";p_amount:" << p_amount
			<< ";withdrawal:refused"
			<< std::endl;
			return false;
	}

	void	Account::displayStatus( void ) const
	{
		_displayTimestamp();
		std::cout << "index:" << _accountIndex
			<< ";amount:" << checkAmount()
			<< ";deposits:" << _nbDeposits
			<< ";withdrawals:" << _nbWithdrawals
			<< std::endl;
	}

    void	Account::_displayTimestamp( void )
	{
		std::time_t now;
		std::tm* t;
		char buffer[18];

		now = std::time(0);
		t = std::localtime(&now);
		std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S]", t);
		std::cout << buffer << " ";
	}