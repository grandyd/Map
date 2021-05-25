//#pragma once
//#include <cassert>
//#include <iostream>
//using namespace std;
//template <typename T>
//class list
//{
//	template <typename T>
//	class Help
//	{
//	public:
//		T field;
//		Help* next;
//		Help* prev;
//		Help<T>(T field = T(), Help* next = nullptr, Help* prev = nullptr)
//		{
//			this->field = field;
//			this->next = next;
//			this->prev = prev;
//		}
//	};
//	Help<T>* first;
//	Help<T>* tail;
//	int size;
//public:
//
//	list();
//	list(const T);
//	list(const list<T>&);
//	~list();
//	T GetValue(int) const;
//	bool Empty() const;
//	int GetSize() const { return this->size; }
//	void clear();
//	void pop_front();
//	void pop_back();
//	void pop(int);
//	void push_front(T field);
//	void push_back(T field);
//	void insert(T, int);
//	void revers();
//	T& operator[](int index);
//	T operator[](int index) const;
//	int find(T field);
//	list<T> unique();
//	void print(const char separator[] = "");
//
//	void swap(int index1, int index2);
//
//	list& operator=(const list&);
//	friend ostream& operator<< <T> (ostream& out, const list<T>& lst);
//	friend istream& operator>> <T> (istream& in, list<T>& lst);
//};
//
//template <typename T>
//list<T>::list()
//{
//	this->size = 0;
//	this->first = nullptr;
//	this->tail = nullptr;
//}
//
//template <typename T>
//list<T>::list(const T field)
//{
//	this->size = 1;
//	this->first = new Help<T>(field);
//	this->tail = new Help<T>(field);
//}
//
//template <typename T>
//list<T>::list(const list<T>& lst)
//{
//	//*this = lst;
//	this->size = 0;
//	this->first = nullptr;
//	this->tail = nullptr;
//	for (int i = 0; i < lst.size; i++)
//	{
//		this->push_back(lst.GetValue(i));
//	}
//	//return *this;
//}
//
//template <typename T>
//list<T>::~list()
//{
//	while (this->size != 0)
//	{
//		pop_front();
//	}
//}
//
//template<typename T>
//inline void list<T>::clear()
//{
//	while (this->size != 0)
//	{
//		pop_front();
//	}
//}
//
//template <typename T>
//void list<T>::pop_front()
//{
//	if (size != 0)
//	{
//
//
//		Help<T>* tmp = this->first->next;
//		delete first;
//		this->size -= 1;
//		first = tmp;
//		if (first != nullptr)
//		{
//			first->prev = nullptr;
//		}
//	}
//}
//
//template <typename T>
//void list<T>::insert(T field, int index)
//{
//	if (index == size)
//	{
//		push_back(field);
//		return;
//	}
//	if (index == 0)
//	{
//		push_front(field);
//		return;
//	}
//	try
//	{
//		if (index<0 || index>this->size)
//		{
//			throw "Index out of range";
//		}
//
//	}
//	catch (const char* exception)
//	{
//		std::cout << "Error: " << exception << std::endl;
//	}
//	Help<T>* cur = first;
//	for (int i = 0; i < index; i++)
//	{
//		cur = cur->next;
//	}
//	Help<T>* help = cur;
//	cur = new Help<T>(field);
//
//	cur->prev = help->prev;
//	help->prev->next = cur;
//	help->prev = cur;
//	cur->next = help;
//	size++;
//}
//
//template<typename T>
//inline void list<T>::revers()
//{
//	for (int i = 0; i < this->size / 2; i++)
//	{
//		swap(i, this->size - 1 - i);
//	}
//}
//
//template <typename T>
//T& list<T>::operator[](int index)
//{
//	Help<T>* tmp;
//	if (index < size / 2)
//	{
//		tmp = first;
//		for (int i = 0; i < index; i++)
//		{
//			tmp = tmp->next;
//		}
//	}
//	else
//	{
//		tmp = tail;
//		for (int i = size - 1; i > index; i--)
//		{
//			tmp = tmp->prev;
//		}
//	}
//	return tmp->field;
//}
//
//template <typename T>
//T list<T>::operator[](int index) const
//{
//	Help<T>* tmp;
//	if (index < size / 2)
//	{
//		tmp = first;
//		for (int i = 0; i < index; i++)
//		{
//			tmp = tmp->next;
//		}
//	}
//	else
//	{
//		tmp = tail;
//		for (int i = size - 1; i > index; i--)
//		{
//			tmp = tmp->prev;
//		}
//	}
//	return tmp->field;
//}
//
//template <typename T>
//int list<T>::find(T field)
//{
//	for (int i = 0; i < size; i++)
//	{
//		if (this->GetValue(i) == field)
//		{
//			return i;
//		}
//	}
//	return -1;
//}
//
//template <typename T>
//list<T> list<T>::unique()
//{
//	list<T> nl;
//	for (int i = 0; i < this->size; i++)
//	{
//		if (nl.find(this->GetValue(i)) > -1)
//		{
//			continue;
//		}
//		nl.push_back(this->GetValue(i));
//	}
//	*this = nl;
//	return *this;
//}
//
//template <typename T>
//list<T>& list<T>::operator=(const list<T>& lst)
//{
//	while (this->size > 0)
//	{
//		pop_front();
//	}
//	for (int i = 0; i < lst.size; i++)
//	{
//		this->push_back(lst.GetValue(i));
//	}
//	return *this;
//}
//
//template <typename T>
//void list<T>::pop_back()
//{
//	Help<T>* tmp = this->tail;
//	tmp->prev->next = nullptr;
//	this->tail = tmp;
//	delete tmp;
//	this->size -= 1;
//}
//
//template <typename T>
//void list<T>::pop(int index)
//{
//	if (index == 0)
//	{
//		pop_front();
//		return;
//	}
//	if (index == size - 1)
//	{
//		pop_back();
//		return;
//	}
//	try
//	{
//		if (index < 0 || index >= this->size)
//		{
//			throw "Index out of range";
//		}
//
//	}
//	catch (const char* exception)
//	{
//		std::cout << "Error: " << exception << std::endl;
//	}
//
//	Help<T>* tmp;
//	if (index > size / 2)
//	{
//		tmp = this->first;
//		for (int i = 0; i < index; i++)
//		{
//			tmp = tmp->next;
//		}
//	}
//	else
//	{
//		tmp = this->tail;
//		for (int i = size - 1; i > index; i--)
//		{
//			tmp = tmp->prev;
//		}
//	}
//	tmp->next->prev = tmp->prev;
//	tmp->prev->next = tmp->next;
//	delete tmp;
//	size--;
//}
//
//template <typename T>
//void list<T>::push_front(T field)
//{
//	Help<T>* tmp = new Help<T>(field);
//	tmp->prev = nullptr;
//	tmp->next = this->first;
//	this->first->prev = tmp;
//	this->first = tmp;
//	size++;
//}
//
//
//template <typename T>
//void list<T>::push_back(T field)
//{
//	if (first == nullptr)
//	{
//		Help<T> cur(field);
//		first = &cur;
//		tail = first;
//		size++;
//		return;
//	}
//	Help<T>* tmp = this->tail;
//	tmp->next = new Help<T>(field);
//	tmp->next->prev = tmp;
//	this->tail = tmp->next;
//	size++;
//}
//
//template <typename T>
//T list<T>::GetValue(int index) const
//{
//	Help<T>* tmp;
//	if (index < size / 2)
//	{
//		tmp = first;
//		for (int i = 0; i < index; i++)
//		{
//			tmp = tmp->next;
//		}
//	}
//	else
//	{
//		tmp = tail;
//		for (int i = size - 1; i > index; i--)
//		{
//			tmp = tmp->prev;
//		}
//	}
//
//	return tmp->field;
//}
//
//template<typename T>
//inline bool list<T>::Empty() const
//{
//	return this->size == 0 ? true : false;
//}
//
//template <typename T>
//ostream& operator<<(ostream& out, const list<T>& lst)
//{
//	list<T> nl = lst;
//	for (int i = 0; i < lst.size; i++)
//	{
//		out << nl.first->field;
//		if (nl.first->next != nullptr)
//		{
//			out << " ";
//		}
//		if (i + 1 < lst.size)
//		{
//			nl.first = nl.first->next;
//		}
//	}
//	for (int i = 1; i < lst.size; i++)
//	{
//		nl.first = nl.first->prev;
//	}
//
//	return out;
//}
//
//template <typename T>
//istream& operator>>(istream& in, list<T>& lst)
//{
//	if (lst.first != nullptr)
//	{
//		while (lst.size > 0)
//		{
//			lst.pop_front();
//		}
//	}
//
//	int size;
//	T tmp;
//	cout << "Введите размер списка\n";
//	in >> size;
//	cout << "Задайте значения элементов\n";
//	for (int i = 0; i < size; i++)
//	{
//		in >> tmp;
//		lst.push_back(tmp);
//	}
//	return in;
//}
//
//template<typename T>
//inline void list<T>::print(const char separator[])
//{
//	Help<T>* tmp = this->first;
//	for (int i = 0; i < this->size; i++)
//	{
//		cout << tmp->field;
//		if (tmp->next != nullptr)
//		{
//			cout << separator;
//		}
//		if (i + 1 < this->size)
//		{
//			tmp = tmp->next;
//		}
//	}
//}
//
//template<typename T>
//inline void list<T>::swap(int index1, int index2)
//{
//	try
//	{
//		if (index1 > this->size || index1<0 || index2>this->size || index2 < 0)
//			throw "Index out of range";
//	}
//	catch (const char* exception)
//	{
//		cout << "Error: " << exception << '\n';
//		exit(1);
//	}
//	T tmp;
//	tmp = this->GetValue(index1);
//	this->operator[](index1) = this->operator[](index2);
//	this->operator[](index2) = tmp;
//}