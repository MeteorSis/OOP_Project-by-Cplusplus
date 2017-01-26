#pragma once

#include "BankingCommonDecl.h"
#include "account.h"

template <typename T>
class BoundCheckArray
{
private:
	T * arr;
	int arrlen;
public:
	BoundCheckArray(int len);
	~BoundCheckArray();
	T& operator[](int idx);
	T operator[](int idx) const;
	int getArrLen() const;
};




/*******************************
BoundCheckArray class 정의 부분
********************************/

template <typename T>
BoundCheckArray<T>::BoundCheckArray(int len)
	:arrlen(len)
{
	arr = new T[len];
}

template <typename T>
BoundCheckArray<T>::~BoundCheckArray()
{
	delete[]arr;
}

template <typename T>
T& BoundCheckArray<T>::operator[](int idx)
{
	if (idx < 0 || idx >= arrlen)
	{
		cout << "Array index out of bound exception" << endl;
		exit(1);
	}
	return arr[idx];
}

template <typename T>
T BoundCheckArray<T>::operator[](int idx) const
{
	if (idx < 0 || idx >= arrlen)
	{
		cout << "Array index out of bound exception" << endl;
		exit(1);
	}
	return arr[idx];
}

template <typename T>
int BoundCheckArray<T>::getArrLen() const
{
	return arrlen;
}