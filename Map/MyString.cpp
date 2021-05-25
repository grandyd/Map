
#include "MyString.h"
#include <string.h>
#include <iostream>


MyString::MyString()
{
	this->str = new char[1];
	this->str[0] = '\0';
}
MyString::MyString(const char c)
{
	this->str = new char[2];
	this->str[0] = c;
	this->str[1] = '\0';
}
MyString::MyString(const MyString& str1)
{
	this->str = new char[strlen(str1.str) + 1];
	int i = 0;
	for (i; i < strlen(str1.str); i++)
	{
		this->str[i] = str1.str[i];
	}
	this->str[i] = '\0';
}
MyString::MyString(const char* str)
{
	this->str = new char[strlen(str) + 1];
	int i = 0;
	for (; i < strlen(str); i++)
	{
		this->str[i] = str[i];
	}
	this->str[i] = '\0';
}

MyString::~MyString()
{
	if (!Empty())
	{
		delete[]this->str;
	}
}

void MyString::Copy(const MyString& str)
{
	*this = str;
}
void MyString::Copy(const char* str)
{
	*this = str;
}
void MyString::Copy(const char c)
{
	*this = c;
}

int StrCmp(const MyString& str1, const MyString& str2)
{
	if (strcmp(str1.str, str2.str) == -1)
	{
		return -1;
	}
	else if (strcmp(str1.str, str2.str) == 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
int StrCmp(const MyString& str1, const char* str2)
{
	if (strcmp(str1.str, str2) == -1)
	{
		return -1;
	}
	else if (strcmp(str1.str, str2) == 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
int StrCmp(const char* str1, const MyString& str2)
{
	if (strcmp(str1, str2.str) == -1)
	{
		return -1;
	}
	else if (strcmp(str1, str2.str) == 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
int StrCmp(const MyString& str1, const char c)
{
	char* str2 = new char[2];
	str2[0] = c;
	str2[1] = '\0';
	if (strcmp(str1.str, str2) == -1)
	{
		return -1;
	}
	else if (strcmp(str1.str, str2) == 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
int StrCmp(const char c, const MyString& str1)
{
	char* str2 = new char[2];
	str2[0] = c;
	str2[1] = '\0';
	if (strcmp(str1.str, str2) == -1)
	{
		return -1;
	}
	else if (strcmp(str1.str, str2) == 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

int MyString::Len() const
{
	int i = 0;
	while (true)
	{
		if (this->str[i] == '\0')
		{
			return i;
		}
		i++;
	}
}

void MyString::Clear()
{
	delete[]this->str;
	*this = "\0";
}

bool MyString::Empty()
{
	if (this->str[0] == '\0')
	{
		return true;
	}
	return false;
}

void MyString::PushBack(const char c)
{
	*this += c;
}

void MyString::Append(const char* str)
{
	*this += str;
}
void MyString::Append(const char c)
{
	*this += c;
}

void MyString::Replace(const char c1, const char c2)
{
	for (int i = 0; i < strlen(this->str); i++)
	{
		if (this->str[i] == c1)
		{
			this->str[i] = c2;
		}
	}
}

void MyString::PopBack()
{
	char* buf = new char[strlen(this->str)];
	int i = 0;
	for (i; i < strlen(this->str) - 1; i++)
	{
		buf[i] = this->str[i];
	}
	buf[i] = '\0';
	delete[]this->str;
	this->str = new char[strlen(buf) + 1];
	strcpy(this->str, buf);
	delete[]buf;
}

void MyString::SetStr(const char* str)
{
	*this = str;
}
void MyString::SetStr(const MyString& str)
{
	*this = str;
}
void MyString::SetStr(const char c)
{
	*this = c;
}

char* MyString::GetStr()
{
	return this->str;
}

bool EqualStr(const MyString& str1, const MyString& str2)
{
	if (strcmp(str1.str, str2.str) == 0)
	{
		return true;
	}
	return false;
}
bool EqualStr(const MyString& str1, const char* str2)
{
	if (strcmp(str1.str, str2) == 0)
	{
		return true;
	}
	return false;
}
bool EqualStr(const MyString& str1, const char c)
{
	if (strlen(str1.str) == 1 && str1.str[0] == c)
	{
		return true;
	}
	return false;
}



MyString& operator+=(MyString& str1, const MyString& str2)
{
	char* buf = new char[strlen(str1.str) + strlen(str2.str) + 1];
	int i = 0, j = 0;
	for (i; i < str1.Len(); i++)
	{
		buf[i] = str1.str[i];
	}
	for (j; j < strlen(str2.str); j++)
	{
		buf[i + j] = str2.str[j];
	}
	delete[]str1.str;
	buf[i + j] = '\0';
	str1.str = new char[strlen(buf) + 1];
	strcpy(str1.str, buf);
	str1.str[i + j] = '\0';
	delete[]buf;
	return str1;
}
MyString& operator+=(MyString& str1, const char* str2)
{
	char* buf = new char[strlen(str1.str) + strlen(str2) + 1];
	int i = 0, j = 0;
	for (i; i < str1.Len(); i++)
	{
		buf[i] = str1.str[i];
	}
	for (j; j < strlen(str2); j++)
	{
		buf[i + j] = str2[j];
	}
	delete[]str1.str;
	buf[i + j] = '\0';
	str1.str = new char[strlen(buf) + 1];
	strcpy(str1.str, buf);
	str1.str[i + j] = '\0';
	delete[]buf;
	return str1;
}
MyString& operator+=(MyString& str1, const char c)
{
	char* buf = new char[strlen(str1.str) + 2];
	int i = 0;
	for (i; i < str1.Len(); i++)
	{
		buf[i] = str1.str[i];
	}
	buf[i] = c;
	delete[]str1.str;
	buf[i + 1] = '\0';
	str1.str = new char[strlen(buf) + 1];
	strcpy(str1.str, buf);
	str1.str[i + 1] = '\0';
	delete[]buf;
	return str1;
}

MyString MyString::operator+(const MyString& str1)
{
	char* buf = new char[strlen(str1.str) + strlen(this->str) + 1];
	int i = 0, j = 0;
	for (i; i < strlen(this->str); i++)
	{
		buf[i] = this->str[i];
	}
	for (j; j < strlen(str1.str); j++)
	{
		buf[i + j] = str1.str[j];
	}
	buf[i + j] = '\0';
	MyString str2(buf);
	delete[]buf;
	return str2;
}
MyString MyString::operator+(const char* str1)
{
	char* buf = new char[strlen(this->str) + strlen(str1) + 1];
	int i = 0; int j = 0;
	for (i; i < strlen(this->str); i++)
	{
		buf[i] = this->str[i];
	}
	for (j; j < strlen(str1); j++)
	{
		buf[i + j] = str1[j];
	}
	buf[i + j] = '\0';
	MyString str2(buf);
	delete[]buf;
	return str2;
}
MyString MyString::operator+(const char c)
{
	char* buf = new char[strlen(this->str) + 2];
	int i = 0; int j = 0;
	for (i; i < strlen(this->str); i++)
	{
		buf[i] = this->str[i];
	}
	buf[i++] = c;
	buf[i] = '\0';
	MyString str2(buf);
	delete[]buf;
	return str2;
}

bool operator==(const MyString& str1, const MyString& str2)
{
	return EqualStr(str1, str2);
}
bool operator==(const MyString& str1, const char* str2)
{
	return EqualStr(str1, str2);
}
bool operator==(const MyString& str1, const char c)
{
	return EqualStr(str1, c);
}
bool operator==(const char* str2, const MyString& str1)
{
	return (str1 == str2);
}
bool operator==(const char c, const MyString& str1)
{
	return (str1 == c);
}

bool operator!=(const MyString& str1, const MyString& str2)
{
	return !(str1 == str2);
}
bool operator!=(const MyString& str1, const char* str2)
{
	return !(str1 == str2);
}
bool operator!=(const MyString& str1, const char str2)
{
	return !(str1 == str2);
}
bool operator!=(const char* str1, const MyString& str2)
{
	return !(str1 == str2);
}
bool operator!=(const char str1, const MyString& str2)
{
	return !(str1 == str2);
}


MyString& MyString::operator=(const MyString& str)
{
	if (this == &str)
	{
		return *this;
	}
	delete[]this->str;
	this->str = new char[strlen(str.str) + 1];
	strcpy(this->str, str.str);
	return *this;
}
MyString& MyString::operator=(const char* str)
{

	if (strcmp(this->str, str) == 0)
	{
		return *this;
	}
	this->str = new char[strlen(str) + 1];
	strcpy(this->str, str);
	return *this;
}
MyString& MyString::operator=(const char c)
{
	delete[]this->str;
	this->str = new char[2];
	this->str[0] = c;
	this->str[1] = '\0';
	return *this;
}

std::ostream& operator<< (std::ostream& out, const MyString& str)
{
	out << str.str;
	return out;
}

bool operator>(const MyString& str1, const MyString& str2)
{
	return StrCmp(str1, str2) == 1 ? true : false;
}
bool operator>(const MyString& str1, const char* str2)
{
	return StrCmp(str1, str2) == 1 ? true : false;
}
bool operator>(const char* str1, const MyString& str2)
{
	return StrCmp(str1, str2) == 1 ? true : false;
}
bool operator>(const MyString& str1, const char c)
{
	return StrCmp(str1, c) == 1 ? true : false;
}
bool operator>(const char c, const MyString& str2)
{
	return StrCmp(c, str2) == 1 ? true : false;
}

bool operator>=(const MyString& str1, const MyString& str2)
{
	return StrCmp(str1, str2) == (0 || 1) ? true : false;
}
bool operator>=(const MyString& str1, const char* str2)
{
	return StrCmp(str1, str2) == (0 || 1) ? true : false;
}
bool operator>=(const char* str1, const MyString& str2)
{
	return StrCmp(str1, str2) == (0 || 1) ? true : false;
}
bool operator>=(const MyString& str1, const char c)
{
	return StrCmp(str1, c) == (0 || 1) ? true : false;
}
bool operator>=(const char c, const MyString& str2)
{
	return StrCmp(c, str2) == (0 || 1) ? true : false;
}

bool operator<(const MyString& str1, const MyString& str2)
{
	return StrCmp(str1, str2) == -1 ? true : false;
}
bool operator<(const MyString& str1, const char* str2)
{
	return StrCmp(str1, str2) == -1 ? true : false;
}
bool operator<(const char* str1, const MyString& str2)
{
	return StrCmp(str1, str2) == -1 ? true : false;
}
bool operator<(const MyString& str1, const char c)
{
	return StrCmp(str1, c) == -1 ? true : false;
}
bool operator<(const char c, const MyString& str2)
{
	return StrCmp(c, str2) == -1 ? true : false;
}

bool operator<=(const MyString& str1, const MyString& str2)
{
	return StrCmp(str1, str2) == (-1 || 0) ? true : false;
}
bool operator<=(const MyString& str1, const char* str2)
{
	return StrCmp(str1, str2) == (-1 || 0) ? true : false;
}
bool operator<=(const char* str1, const MyString& str2)
{
	return StrCmp(str1, str2) == (-1 || 0) ? true : false;
}
bool operator<=(const MyString& str1, const char c)
{
	return StrCmp(str1, c) == (-1 || 0) ? true : false;
}
bool operator<=(const char c, const MyString& str2)
{
	return StrCmp(c, str2) == (-1 || 0) ? true : false;
}

MyString MyString::operator*(const int n)
{
	MyString buf;
	if (n != 0) for (int i = 0; i < n; i++) buf += *this;
	return buf;
}

bool MyString::In_String(const MyString& str) const
{
	for (int i = 0; i <= str.Len() - this->Len(); i++)
	{
		if (*this == str.Slice(i, i + this->Len() - 1))
		{
			return true;
		}
	}
	return false;
}

char MyString::operator[](int index) const
{
	return this->str[index];
}

std::istream& operator>>(std::istream& in, MyString& str)
{
	char buf[256] = { 0 };
	while (buf[0] == '\0' && !in.eof())
	{
		in.getline(buf, 255);
	}

	str = buf;
	return in;
}

MyString MyString::Slice(const int n1 = 0, const int n2 = 10) const
{
	if (n1 < n2 && n2 < strlen(this->str))
	{
		char* buf = new char[n2 - n1 + 2];
		int i = n1, j = 0;
		for (i, j; i < n2 + 1; i++, j++)
		{
			buf[j] = this->str[i];
		}
		buf[j] = '\0';
		MyString str(buf);
		delete[]buf;
		return str;
	}
	std::cout << "Ошибка, второе значения переданное функции выходит за пределы строки\n";
	return *this;
}