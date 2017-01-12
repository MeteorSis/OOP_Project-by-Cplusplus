#pragma once
#include "account.h"
#include "main.h"

class AccountHandler	//this is handler class
{
private:
	Account* accPtrArr[ACC_NUM_OF_MAX];
	int accNum;

public:
	AccountHandler();
	int showAndInputMenu() const;
	void makeAccount(void);
	void depositMoney(void);
	void withdrawMoney(void);
	void showAllAccInfo(void);
	Account* searchID(int id);
};