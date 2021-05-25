#pragma once
#include <stdlib.h>
#include "Node.h"
#include <iostream>

using namespace std;

template<class TK, class TV>
class Map
{
	Node<TK, TV>* arr;
	int count;
	int size;


	void Resize();
public:
	Map();
	Map(const TK& Key, const TV& Value);
	Map(const Map<TK,TV>& M);
	~Map();

	void Add(const TK& Key, const TV& Value);
	TV& Find(const TK& Key);
	void Delete(const TK& Key);
	int GetCount();
	int GetSize();
	void ShrinkToFit();

	template<class TK, class TV>
	friend ostream& operator<<(ostream& out, const Map<TK, TV>& M);
	TV& operator[](const TK& Key);

	template<class TK, class TV>
	friend class MapIter;
};

template<class TK, class TV>
inline void Map<TK, TV>::Resize()
{
	if (this->size==0)
	{
		this->size+=2;
		this->arr = new Node<TK, TV>[2];
		return;
	}
	this->size *= 2;
	Node<TK, TV>* tmp = new Node<TK, TV>[this->size];
	int i = 0;
	while (i!=this->count)
	{
		tmp[i] = this->arr[i];
		i++;
	}
	delete[]arr;
	arr = tmp;
}

template<class TK, class TV>
inline Map<TK, TV>::Map()
{
	this->arr = 0;
	this->count = this->size = 0;
}

template<class TK, class TV>
inline Map<TK, TV>::Map(const TK& Key, const TV& Value)
{
	this->arr = new Node<TK, TV>[2];
	this->arr[0] = Node<TK, TV>(Key, Value);
	this->count = 1;
	this->size = 2;
}

template<class TK, class TV>
inline Map<TK, TV>::Map(const Map<TK, TV>& M)
{
	this->size = M.size;
	this->count = 0;
	this->arr = new Node<TK, TV>[this->size];
	while (this->count!=M.count)
	{
		this->arr[this->count] = M.arr[this->count];
		this->count++;
	}
}

template<class TK, class TV>
inline Map<TK, TV>::~Map()
{
	delete[]this->arr;
	this->size = 0;
	this->count = 0;
}

template<class TK, class TV>
inline void Map<TK, TV>::Add(const TK& Key, const TV& Value)
{
	if (this->count==this->size)
	{
		this->Resize();
	}
	this->arr[this->count++] = Node<TK, TV>(Key, Value);
}

template<class TK, class TV>
inline TV& Map<TK, TV>::Find(const TK& Key)
{
	int i = 0;
	while (i!=this->count)
	{
		if (this->arr[i].Key==Key)
		{
			return this->arr[i]->Value;
		}
	}
	exit(-1);
}

template<class TK, class TV>
inline void Map<TK, TV>::Delete(const TK& Key)
{
	int i = 0;
	while (i != this->count)
	{
		if (this->arr[i].Key == Key)
		{
			while (i+1!=this->count)
			{
				this->arr[i].Key = this->arr[i + 1].Key;
				this->arr[i].Value = this->arr[i + 1].Value;
				i++;
			}
			this->count -= 1;
			return;
		}
		i++;
	}
}

template<class TK, class TV>
inline int Map<TK, TV>::GetCount()
{
	return this->count;
}

template<class TK, class TV>
inline int Map<TK, TV>::GetSize()
{
	return this->size;
}

template<class TK, class TV>
inline void Map<TK, TV>::ShrinkToFit()
{
	if (this->count==this->size)
	{
		return;
	}
	Node<TK, TV>* tmp = new Node<TK, TV>[this->count];
	int i = 0;
	while (i!=this->count)
	{
		tmp[i] = this->arr[i];
		i++;
	}
	delete[]this->arr;
	this->arr = tmp;
	this->size = this->count;
}

template<class TK, class TV>
inline TV& Map<TK, TV>::operator[](const TK& Key)
{
	int i = 0;
	while (i!=this->count)
	{
		if (this->arr[i].Key==Key)
		{
			return this->arr[i].Value;
		}
		i++;
	}
	this->Add(Key, TV());
	return this->arr[count].Value;
}


template<class TK, class TV>
inline ostream& operator<<(ostream& out, const Map<TK, TV>& M)
{
	int i = 0;
	while (i != M.count)
	{
		out << M.arr[i].GetValue() << " ";
		i++;
	}
	return out;
}



template<class TK, class TV>
class MapIter
{
	Node<TK, TV>* first;
public:
	friend ostream& operator<<(ostream& out, const MapIter<TK,TV>& Iter);
	MapIter(const Map<TK,TV>& M);

	template<class TK, class TV>
	friend void operator++(const MapIter<TK, TV> I);
	~MapIter();

private:

};

template<class TK, class TV>
inline void operator++(const MapIter<TK, TV> I)
{
	this->first++;
}

template<class TK, class TV>
ostream& operator<<(ostream& out, const MapIter<TK,TV>& Iter)
{
	out <<Iter.first->GetKey()<<":"<< Iter.first->GetValue();
}


template<class TK, class TV>
inline MapIter<TK, TV>::MapIter(const Map<TK, TV>& M)
{
	this->first = M.arr;
}

template<class TK, class TV>
MapIter<TK,TV>::~MapIter()
{ 

}