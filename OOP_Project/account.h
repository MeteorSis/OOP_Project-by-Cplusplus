#pragma once

#include "BankingCommonDecl.h"
#include "minusException.h"
#include "insuffException.h"

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
	virtual void deposit(const int &money) throw (minusException) = 0 ;
	void withdraw(const int &money) throw (minusException, insuffException);
	virtual void showAccInfo(void) const = 0;
};