#pragma once

#include "BankingCommonDecl.h"

class Account;
typedef Account* ACCOUNT_PTR;

class Account
{
private:
	int accID;
	int balance;
	String cusName;

public:
	Account(const int &accID, const int &balance, const String &cusName);
	ACCOUNT_PTR getAccPtrFromID(const int &accID);
	virtual void deposit(const int &money) = 0;
	bool withdraw(const int &money);
	virtual void showAccInfo(void) const = 0;
};