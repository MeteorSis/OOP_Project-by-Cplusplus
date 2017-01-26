#include "String.h"

String::String()
	:str(nullptr), len(0){}

String::String(const char* s)
{
	len = strlen(s) + 1;
	str = new char[len];
	strcpy(str, s);
}

String::String(const String& s)
{
	len = s.len;
	str = new char[len];
	strcpy(str, s.str);
}

String::~String()
{
	if(str!=nullptr)
		delete[] str;
}

String& String::operator=(const String& s)
{
	if (str != nullptr)
		delete[] str;
	len = s.len;
	str = new char[len];
	strcpy(str, s.str);
	return *this;
}

String& String::operator+=(const String& s)
{
	/*len += (s.len - 1);
	char * tmpStr = new char[len];
	strcpy(tmpStr, str);
	strcpy(tmpStr, s.str);

	if (str != nullptr)
		delete[] str;
	str = tmpStr;*/
	*this = *this + s;
	return *this;
}

bool String::operator==(const String& s)
{
	return strcmp(str, s.str) ? false : true;
}

String String::operator+(const String& s)
{
	char* tmpStr = new char[len + s.len - 1];
	strcpy(tmpStr, str);
	strcpy(tmpStr, s.str);

	String tmp(tmpStr);
	delete[] tmpStr;
	return tmp;
}

ostream& operator<<(ostream& os, const String& s)
{
	os << s.str;
	return os;
}

istream& operator >> (istream& is, String& s)
{
	char str[100];
	is >> str;
	s = String(str);
	return is;
}