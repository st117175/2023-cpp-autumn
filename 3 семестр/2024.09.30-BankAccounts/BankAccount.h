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
	BankAccount();
	BankAccount(std::string accountNumber_1, double balance_1, std::string accountHolder_1);
	void Deposit(double amount);
	void Withdraw(double amount);
	int GetBalance();
	std::string GetAccountHolder();
	std::string GetAccountNumber();
	void PrintAccountInfo();
};

