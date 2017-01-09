#pragma once

#include <iostream>
using namespace std;

#define NAME_LEN 20
#define ACC_NUM_OF_MAX 100

enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

typedef struct
{
	int accID;
	int balance;
	char cusName[NAME_LEN];
} Account;

extern Account accArr[ACC_NUM_OF_MAX];
extern int accNum;