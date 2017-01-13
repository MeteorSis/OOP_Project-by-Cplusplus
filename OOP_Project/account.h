#pragma once
class Account
{
private:
	int accID;
	int balance;
	char* cusName;

public:
	Account(const int &accID, const int &balance, char * const &cusName);
	Account(const Account &ref);
	virtual ~Account();
	Account* getAccPtrFromID(const int &accID);
	void deposit(const int &money);
	bool withdraw(const int &money);
	virtual void showAccInfo(void) const;
};