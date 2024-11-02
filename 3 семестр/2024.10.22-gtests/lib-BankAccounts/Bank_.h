#include "BankAccount_.h"

class Bank
{
	private:
	std::vector<BankAccount*> accounts;
	

	public:
	Bank();
	~Bank();
	void AddAccount(BankAccount* account);
	double GetTotalBalance();
	void PrintAllAccounts();
};