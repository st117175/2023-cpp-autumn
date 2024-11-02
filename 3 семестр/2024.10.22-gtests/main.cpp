#include <gtest/gtest.h>
#include "lib-TextEditor/Editor_1.h"
#include "lib-BankAccounts/Bank_.h"

//Tests for TextEditor hw1

TEST(TextEditor, Subtest_operator_assignment) 
{
	TextEditor TextEditor1;
	TextEditor1.addText("Hello");
	TextEditor TextEditor2 = TextEditor1;
    ASSERT_EQ(TextEditor2.GettextBefore(), "Hello");
}

TEST(TextEditor, Subtest_addText_length) 
{
	std::string str1 = "Hello";
	TextEditor TextEditor1;
	TextEditor1.addText(str1);
	ASSERT_EQ(TextEditor1.GettextBefore().length(), str1.length());
}

//Checking returned value
TEST(TextEditor, Subtest_deleteText) 
{
	TextEditor TextEditor1;
	TextEditor1.addText("Linking Park");
	int k = TextEditor1.deleteText(TextEditor1.GettextBefore().length() + 2);
	ASSERT_EQ(k, TextEditor1.GettextBefore().length());
}

TEST(TextEditor, Subtest_cursorLeft) 
{
	TextEditor TextEditor1;
	TextEditor1.addText("Linking Park");
	ASSERT_EQ("Linking ", TextEditor1.cursorLeft(4));
}

TEST(TextEditor, Subtest_cursorRight) 
{
	TextEditor TextEditor1;
	TextEditor1.addText("Linking Park");
	TextEditor1.cursorLeft(4);
	ASSERT_EQ("rk", TextEditor1.cursorLeft(2));
}


//Tests for class Bank from hw 2

TEST(Bank, Subtest_constructor)
{
	BankAccount example;
	ASSERT_TRUE(example.GetBalance() == 0 && example.GetAccountHolder() == "" && example.GetAccountNumber() == "0");
}

TEST(Bank, Subtest_Deposit)
{
	BankAccount example("1", 766, "G");
	example.Deposit(1234);
	ASSERT_EQ(example.GetBalance(), 2000);
}

TEST(Bank, Subtest_get)
{
	BankAccount example("1", 766, "Vova");
	example.Deposit(1234);
	ASSERT_TRUE(example.GetBalance() == 2000 && example.GetAccountHolder() == "Vova" && example.GetAccountNumber() == "1");
}

TEST(Bank, Subtest_Withdraw)
{
	BankAccount account1("LOLO", 543, "Valerian");
	account1.Withdraw(43);
	ASSERT_TRUE(account1.GetBalance() == 500);
}

TEST(Bank, Subtest_GetTotalBalance)
{
	Bank bank;
	BankAccount Acc1("1", 400, "G");
	BankAccount Acc2("2", 500, "V");
	BankAccount Acc3("3", 600, "C");
	bank.AddAccount(&Acc1);
	bank.AddAccount(&Acc2);
	bank.AddAccount(&Acc3);
	ASSERT_EQ(bank.GetTotalBalance(), 1500);
}