#pragma once

#include "BankingCommonDecl.h"
#include "account.h"

class AccountArray
{
private:
	ACCOUNT_PTR * arr;
	int arrlen;
public:
	AccountArray(int len);
	~AccountArray();
	ACCOUNT_PTR& operator[](int idx);
	ACCOUNT_PTR operator[](int idx) const;
	int getArrLen() const;
};