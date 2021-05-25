#pragma once
#include <stdlib.h>
#include <iostream>
#include "Node.h"

using namespace std;

template<class TK, class TV>
class SortMap
{
	Node<TK, TV>* arr;
	int size;
	int count;

	void Resize();
public:
	SortMap(int size_ = 1000);
	SortMap(const SortMap& M);
	~SortMap();

	TV& operator[](const TK& Key);

	template<class TK, class TV>
	friend ostream& operator<<(ostream& out, const SortMap<TK, TV>& M);

	int GetCount();
	int GetSize();
	void ShrinkToFit();

	TV Find(const TK& Key);
	void Delete(const TK& Key);
	void Add(const TK& Key,const TV& Value);

};


template<class TK, class TV>
inline int SortMap<TK, TV>::GetCount()
{
	return this->count;
}

template<class TK, class TV>
inline int SortMap<TK, TV>::GetSize()
{
	return this->size;
}

template<class TK, class TV>
inline void SortMap<TK, TV>::ShrinkToFit()
{
	if (this->count == this->size)
	{
		return;
	}
	Node<TK, TV>* tmp = new Node<TK, TV>[this->count];
	int i = 0;
	while (i != this->count)
	{
		tmp[i] = this->arr[i];
		i++;
	}
	delete[]this->arr;
	this->arr = tmp;
	this->size = this->count;
}

template<class TK, class TV>
inline void SortMap<TK, TV>::Resize()
{
	if (this->size == 0)
	{
		this->size += 2;
		this->arr = new Node<TK, TV>[2];
		return;
	}
	this->size *= 2;
	Node<TK, TV>* tmp = new Node<TK, TV>[this->size];
	int i = 0;
	while (i != this->count)
	{
		tmp[i] = this->arr[i];
		i++;
	}
	delete[]arr;
	arr = tmp;
}

template<class TK, class TV>
inline SortMap<TK, TV>::SortMap(int size_)
{
	this->size = size_;
	this->count = 0;
	this->arr = new Node<TK, TV>[this->size];
}

template<class TK, class TV>
inline SortMap<TK, TV>::SortMap(const SortMap& M)
{
	this->size = M.size;
	this->count = 0;
	this->arr = new Node<TK, TV>[this->size];
	while (this->count != M.count)
	{
		this->arr[this->count] = M.arr[this->count];
		this->count++;
	}
}

template<class TK, class TV>
inline SortMap<TK, TV>::~SortMap()
{
	delete[]this->arr;
	this->size = 0;
	this->count = 0;
}

template<class TK, class TV>
inline TV& SortMap<TK, TV>::operator[](const TK& Key)
{
	int bot = 0;
	int top = this->count;
	int i = this->count / 2;
	while (this->arr[i].Key!=Key)
	{
		if (Key>this->arr[i].Key)
		{
			bot = i;
			i = (bot + top) / 2;
			continue;
		}
		if (Key<this->arr[i].Key)
		{
			top = i;
			i = (bot + top) / 2;
			continue;
		}
		if (bot==top)
		{
			Add(Key, 0);
			return operator[](Key);
		}
	}
	return this->arr[i].Value;
}

template<class TK, class TV>
inline TV SortMap<TK, TV>::Find(const TK& Key)
{
	int bot = 0;
	int top = this->count;
	int i = this->count / 2;
	while (this->arr[i].Key != Key)
	{
		if (Key > this->arr[i].Key)
		{
			bot = i;
			i = (bot + top) / 2;
			continue;
		}
		if (Key < this->arr[i].key)
		{
			top = i;
			i = (bot + top) / 2;
			continue;
		}
		if (bot == top)
		{
			exit(1);
		}
	}
	return this->arr[i].Value;
}

template<class TK, class TV>
inline void SortMap<TK, TV>::Delete(const TK& Key)
{
	int i = 0;
	while (i!=this->count+1)
	{
		if (this->arr[i].Key==Key)
		{
			this->count--;
			while (i!=this->count)
			{
				this->arr[i] = this->arr[i + 1];
				i++;
			}
			return;
		}
		i++;
	}
}

template<class TK, class TV>
inline void SortMap<TK, TV>::Add(const TK& Key, const TV& Value)
{
	if (this->size==this->count)
	{
		Resize();
	}
	int i = 0;
	if (this->count != 0)
	{
		while (this->arr[i].Key < Key && i<count)
		{
			i++;
		}
	}
	this->count++;
	int j = this->count-1;
	while (j!=i)
	{
		this->arr[j] = this->arr[j - 1];
		j--;
	}
	this->arr[j] = Node<TK, TV>(Key, Value);
}

template<class TK, class TV>
inline ostream& operator<<(ostream& out, const SortMap<TK, TV>& M)
{
	int i = 0;
	while (i != M.count)
	{
		out << M.arr[i].GetValue() << " ";
		i++;
	}
	return out;
}