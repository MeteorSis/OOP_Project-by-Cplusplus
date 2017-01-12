#pragma once

#include <iostream>
#include "account.h"

using namespace std;

#define NAME_LEN 20
#define ACC_NUM_OF_MAX 100

enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

extern Account* accPtrArr[ACC_NUM_OF_MAX];
extern int accNum;