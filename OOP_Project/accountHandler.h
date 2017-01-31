#pragma once

#include "BankingCommonDecl.h"
#include "account.h"
#include "normalAccount.h"
#include "highCreditAccount.h"
#include "BoundCheckArray.h"
#include "invalid_variable.h"
#include "invalid_menu.h"
#include "minusException.h"

class AccountHandler
{
private:
	BoundCheckArray<ACCOUNT_PTR> accPtrArr;
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