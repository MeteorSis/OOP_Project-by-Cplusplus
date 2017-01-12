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
	void deposit(const int &money);
	bool withdraw(const int &money);
	void showAccInfo(void) const;
};