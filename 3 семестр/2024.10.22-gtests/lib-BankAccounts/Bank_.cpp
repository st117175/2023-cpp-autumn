#include "Bank_.h"

Bank::Bank()
{
std::vector<BankAccount*> accounts;
}

Bank::~Bank()
{
accounts.clear();
}

void Bank::AddAccount(BankAccount* account)
{
accounts.push_back(account);
}

double Bank::GetTotalBalance()
{
double TotalBalance = 0;
for(int i = 0; i < accounts.size(); ++i)
{
TotalBalance += accounts[i]->GetBalance();
}
return TotalBalance;
}

void Bank::PrintAllAccounts()
{
for(int i = 0; i < accounts.size(); ++i)
{
accounts[i]->PrintAccountInfo();
}
}