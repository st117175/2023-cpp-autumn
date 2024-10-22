#include "Bank.h"

int main()
{
	BankAccount Num1("0001", 5000, "Sanya");
	BankAccount Num2("0002", 50, "Sanya Bedni");
	BankAccount Num3("0003", 500000, "Major");

	Bank Krisis;
	Krisis.AddAccount(&Num1);
	Krisis.AddAccount(&Num2);
	Krisis.AddAccount(&Num3);

	Num1.Deposit(432);
	Num2.Withdraw(50);

	Krisis.PrintAllAccounts();
}