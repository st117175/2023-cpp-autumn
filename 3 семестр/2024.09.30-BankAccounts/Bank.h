#ifndef BANK_H
#define BANK_H

#include <iostream>
#include <string>
#include <vector>

class BankAccount
{
	private:
	std::string accountNumber;
	double balance;
	std::string accountHolder;
	
	public:
	BankAccount()
	{
	accountNumber = nullptr;
	balance = 0;
	accountHolder = nullptr;
	}

	BankAccount(std::string accountNumber_1, double balance_1, std::string accountHolder_1)
	{
	accountNumber = accountNumber_1;
	balance = balance_1;
	accountHolder = accountHolder_1;
	}

	void Deposit(double amount)
	{
	balance += amount;
	}

	void Withdraw(double amount)
	{
	if(amount < balance)
	{
	std::cout << "not enough money" << std::endl;
	}
	else
	{
	balance -= amount;
	}
	}

	int GetBalance()
	{
	return balance;
	}

	std::string GetAccountHolder()
	{
	return accountHolder;
	}

	std::string GetAccountNumber()
	{
	return accountNumber;
	}

	void PrintAccountInfo()
	{
	std::cout << "_____" << std::endl << "accountNumber " << accountNumber << std::endl;
	std::cout << "balance " << balance << std::endl;
	std::cout << "accountHolder " << accountHolder << std::endl;
	}
};

class Bank
{
	private:
	std::vector<BankAccount*> accounts;
	

	public:
	Bank()
	{
	std::vector<BankAccount*> accounts;
	}

	~Bank()
	{
	accounts.clear();
	}

	void AddAccount(BankAccount* account)
	{
	accounts.push_back(account);
	}

	double GetTotalBalance()
	{
	double TotalBalance = 0;
	for(int i = 0; i < accounts.size(); ++i)
	{
	TotalBalance += accounts[i]->GetBalance();
	}
	return TotalBalance;
	}

	void PrintAllAccounts()
	{
	for(int i = 0; i < accounts.size(); ++i)
	{
	accounts[i]->PrintAccountInfo();
	}
	}
};

#endif
