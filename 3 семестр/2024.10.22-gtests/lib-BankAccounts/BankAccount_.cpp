#include "BankAccount_.h"

BankAccount::BankAccount()
{
accountNumber = nullptr;
balance = 0;
accountHolder = nullptr;
}

BankAccount::BankAccount(std::string accountNumber_1, double balance_1, std::string accountHolder_1)
{
accountNumber = accountNumber_1;
balance = balance_1;
accountHolder = accountHolder_1;
}

void BankAccount::Deposit(double amount)
{
balance += amount;
}

void BankAccount::Withdraw(double amount)
{
if(amount > balance)
{
std::cout << "not enough money" << std::endl;
}
else
{
balance -= amount;
}
}

int BankAccount::GetBalance()
{
return balance;
}

std::string BankAccount::GetAccountHolder()
{
return accountHolder;
}

std::string BankAccount::GetAccountNumber()
{
return accountNumber;
}

void BankAccount::PrintAccountInfo()
{
std::cout << "_____" << std::endl << "accountNumber " << accountNumber << std::endl;
std::cout << "balance " << balance << std::endl;
std::cout << "accountHolder " << accountHolder << std::endl;
}