#pragma once
#include "BankingCommonDecl.h"
#include "account.h"
#include "normalAccount.h"
#include "highCreditAccount.h"

class AccountHandler
{
private:
	ACCOUNT_PTR accPtrArr[ACC_NUM_OF_MAX];
	int accNum;
	enum{ NORMALACC=1, HIGHCREDITACC };

public:
	AccountHandler();
	int showAndInputMenu() const;
	void makeAccount(void);
	void depositMoney(void);
	void withdrawMoney(void);
	void showAllAccInfo(void);
	ACCOUNT_PTR searchID(int id);
};