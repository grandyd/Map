#pragma once
#include <iostream>
class MyString
{
	char* str;
public:
	MyString();
	MyString(const MyString&);
	MyString(const char*);
	MyString(const char);
	~MyString();


	operator char* ()
	{
		return str;
	}



	MyString Slice(int n1, int n2) const;

	void Copy(const MyString&);
	void Copy(const char*);
	void Copy(const char);

	void SetStr(const char*);
	void SetStr(const MyString&);
	void SetStr(const char);
	char* GetStr();

	friend int StrCmp(const MyString&, const MyString&);
	friend int StrCmp(const MyString&, const char*);
	friend int StrCmp(const char*, const MyString&);
	friend int StrCmp(const MyString&, const char);
	friend int StrCmp(const char, const MyString&);

	int Len() const;
	void Clear();
	bool Empty();
	void PushBack(const char);
	void PopBack();
	void Append(const char*);
	void Append(const char);
	void Replace(const char, const char);
	void Replace(const char*, const char);

	MyString& operator=(const MyString&);
	MyString& operator=(const char*);
	MyString& operator=(const char);

	friend bool EqualStr(const MyString& str1, const MyString& str2);
	friend bool EqualStr(const MyString& str1, const char*);
	friend bool EqualStr(const MyString& str1, const char);

	MyString operator+(const MyString&);
	MyString operator+(const char*);
	MyString operator+(const char);

	MyString operator*(const int);

	bool In_String(const MyString& str) const;

	friend MyString& operator+=(MyString&, const MyString&);
	friend MyString& operator+=(MyString&, const char*);
	friend MyString& operator+=(MyString&, const char);

	friend bool operator>(const MyString&, const MyString&);
	friend bool operator>(const MyString&, const char*);
	friend bool operator>(const char*, const MyString&);
	friend bool operator>(const MyString&, const char);
	friend bool operator>(const char, const MyString&);

	friend bool operator>=(const MyString&, const MyString&);
	friend bool operator>=(const MyString&, const char*);
	friend bool operator>=(const char*, const MyString&);
	friend bool operator>=(const MyString&, const char);
	friend bool operator>=(const char, const MyString&);

	friend bool operator<(const MyString&, const MyString&);
	friend bool operator<(const MyString&, const char*);
	friend bool operator<(const char*, const MyString&);
	friend bool operator<(const MyString&, const char);
	friend bool operator<(const char, const MyString&);

	friend bool operator<=(const MyString&, const MyString&);
	friend bool operator<=(const MyString&, const char*);
	friend bool operator<=(const char*, const MyString&);
	friend bool operator<=(const MyString&, const char);
	friend bool operator<=(const char, const MyString&);

	friend bool operator==(const MyString&, const MyString&);
	friend bool operator==(const MyString&, const char*);
	friend bool operator==(const MyString&, const char);
	friend bool operator==(const char*, const MyString&);
	friend bool operator==(const char, const MyString&);

	friend bool operator!=(const MyString&, const MyString&);
	friend bool operator!=(const MyString&, const char*);
	friend bool operator!=(const MyString&, const char);
	friend bool operator!=(const char*, const MyString&);
	friend bool operator!=(const char, const MyString&);

	friend std::ostream& operator<<(std::ostream& out, const MyString& str);
	friend std::istream& operator>>(std::istream& in, MyString& str);

	char operator[](int index) const;
};