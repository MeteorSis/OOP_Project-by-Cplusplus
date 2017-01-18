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
	~Account();
	Account* getAccPtrFromID(const int &accID);
	virtual void deposit(const int &money) = 0;
	bool withdraw(const int &money);
	virtual void showAccInfo(void) const = 0;
};