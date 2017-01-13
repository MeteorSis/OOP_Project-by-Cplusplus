#include "normalAccount.h"

NormalAccount::NormalAccount(const int &accID, const int &balance, char * const &cusName, const int &interRate)
	:Account(accID, balance, cusName), interRate(interRate){}