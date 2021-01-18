///
/// @file    MyString.cc
/// @author  frank(frankrxd@gmail.com)
/// @date    2020-01-09 17:13:49
///
#include "MyString.h"

String::String(const char* pstr)
	:_pstr(new char[strlen(pstr) + 1]())
{
	strcpy(_pstr, pstr);
	//cout << "String(const char* pstr)" << endl;
}

String::String(const String& rhs)
	: _pstr(new char[strlen(rhs._pstr) + 1]())
{
	strcpy(_pstr, rhs._pstr);
	//cout << "String(const String& rhs)" << endl;
}

String& String::operator=(const String rhs)
{
	if (this != &rhs)
	{
		delete[] _pstr;
		_pstr = new char[strlen(rhs._pstr) + 1]();
		strcpy(_pstr, rhs._pstr);
	}
	//cout << "String::operator=(const String rhs)" << endl;
	return *this;
}

String& String::operator=(const char* rhs)
{
	if (_pstr != rhs)
	{
		delete[] _pstr;
		_pstr = new char[strlen(rhs) + 1]();
		strcpy(_pstr, rhs);
	}
	//cout << "String::operator=(const String rhs)" << endl;
	return *this;
}

String& String::operator+=(const String& rhs)
{
	String temp = *this;
	delete[] _pstr;
	_pstr = new char[strlen(rhs._pstr) + strlen(temp._pstr) + 1]();
	strcpy(_pstr, temp._pstr);
	strcat(_pstr, rhs._pstr);
	//cout << "String::operator=(const String rhs)" << endl;
	return *this;
}

String& String::operator+=(const char* rhs)
{
	String temp = *this;
	delete[] _pstr;
	_pstr = new char[strlen(rhs) + strlen(temp._pstr) + 1]();
	strcpy(_pstr, temp._pstr);
	strcat(_pstr, rhs);
	//cout << "String::operator=(const String rhs)" << endl;
	return *this;
}

String& String::operator+(const String& rhs)
{
	return ((*this) += rhs);
}

String& String::operator+(const char* rhs)
{
	return ((*this) += rhs);
}

String::~String()
{
	if (_pstr != nullptr)
		delete[] _pstr;
	//cout << "~String()" << endl;
}

char& String::operator[](size_t idx)
{
	if (idx >= 0 && idx < strlen(_pstr))
		return _pstr[idx];
	else
	{
		static char nullchar = '\0';
		cerr << "Expression: array subscrip out of range ! \n";
		return nullchar;
	}
}
const char& String::operator[](std::size_t idx) const
{
	return _pstr[idx];
}

size_t String::size() const
{
	return strlen(_pstr);
}
const char* String::c_str() const
{
	return _pstr;
}

bool operator==(const String& str1, const String& str2)
{
	if (strcmp(str1._pstr, str2._pstr) == 0)
		return true;
	else return false;
}

bool operator!=(const String&str1, const String&str2)
{
	if (strcmp(str1._pstr, str2._pstr) != 0)
		return true;
	else return false;
}
bool operator<(const String&str1, const String&str2)
{
	if (strcmp(str1._pstr, str2._pstr) < 0)
		return true;
	else return false;
}
bool operator>(const String&str1, const String&str2)
{
	if (strcmp(str1._pstr, str2._pstr) > 0)
		return true;
	else return false;
}
bool operator<=(const String&str1, const String&str2)
{
	if (strcmp(str1._pstr, str2._pstr) <= 0)
		return true;
	else return false;
}
bool operator>=(const String&str1, const String&str2)
{
	if (strcmp(str1._pstr, str2._pstr) >= 0)
		return true;
	else return false;
}
ostream& operator<<(ostream& os, const String& s)
{
	return os << s._pstr;
}
istream& operator>>(istream& is, String& s)
{
	s._pstr=new char[is.gcount()+1];
	return is >> s._pstr;
}

String operator+(const String& str1, const String& str2)
{
	return str1 + str2;
}
String operator+(const String& str1, const char*str2)
{
	return str1 + str2;
}
String operator+(const char*str1, const String&str2)
{
	String temp = str1;
	return temp + str2;
}
