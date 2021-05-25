#pragma once
#include "Node.h"
#include "HashNode.h"
#include <stdlib.h>
#include "MyList.h"
//
//template<class TK, class TV>
//class HashMap
//{
//	list<HashNode<TK, TV>>* arr;
//	int Hash(const TK& Key);
//public:
//	HashMap();
//	HashMap(const HashMap* M);
//	~HashMap() {}
//	
//	void Add(const TK& Key, const TV& Value);
//	TV Find(const TK& Key);
//	TV& operator[](const TK& Key);
//	void Delete(const TK& Key);
//};
//	
//
//template<class TK, class TV>
//inline int HashMap<TK, TV>::Hash(const TK& Key)
//{
//	return Key[0] - 'a';
//}
//
//template<class TK, class TV>
//inline HashMap<TK, TV>::HashMap()
//{
//	this->arr = new list<HashNode<TK, TV>>[26];
//}
//
//template<class TK, class TV>
//inline HashMap<TK, TV>::HashMap(const HashMap* M)
//{
//	for (int i = 0; i < 26; i++)
//	{
//		arr[i] = M->arr[i];
//	}
//}
//
//template<class TK, class TV>
//inline void HashMap<TK, TV>::Add(const TK& Key, const TV& Value)
//{
//	int i = Hash(Key);
//	HashNode<TK, TV> N(Key, Value);
//	arr[i].push_back(N);
//}
//
//template<class TK, class TV>
//inline TV HashMap<TK, TV>::Find(const TK& Key)
//{
//	int i = Hash(Key);
//	int j = 0;
//	while (&arr[i][j]!=0)
//	{
//		if (arr[i][j].Key==Key)
//		{
//			return arr[i][j].Value;
//		}
//		j++;
//	}
//	exit(1);
//}
//
//template<class TK, class TV>
//inline TV& HashMap<TK, TV>::operator[](const TK& Key)
//{
//	int i = Hash(Key);
//	int j = 0;
//	while (arr[i][j])
//	{
//		if (arr[i][j].Key == Key)
//		{
//			return arr[i][j].Value;
//		}
//		j++;
//	}
//	Add(Key);
//	return arr[i][j].Value;
//}
//
//template<class TK, class TV>
//inline void HashMap<TK, TV>::Delete(const TK& Key)
//{
//	int i = Hash(Key);
//	int j = 0;
//	while (arr[i][j])
//	{
//		if (arr[i][j].Key == Key)
//		{
//			arr[i].pop(j);
//			return;
//		}
//		j++;
//	}
//}
//
//
//









template<class TK, class TV>
class HashMap
{
	HashNode<TK, TV>* arr;
	int Hash(const TK& Key);
public:
	HashMap();
	HashMap(const HashMap* M);
	~HashMap();

	void Add(const TK& Key, const TV& Value);
	TV Find(const TK& Key);
	TV& operator[](const TK& Key);
	void Delete(const TK& Key);
};

template<class TK, class TV>
inline int HashMap<TK, TV>::Hash(const TK& Key)
{
	return Key[0]-'a';
}

template<class TK, class TV>
inline HashMap<TK, TV>::HashMap()
{
	this->arr = new HashNode<TK, TV>[26];
	for (int i = 0; i < 26; i++)
	{
		this->arr[i].Key = "dont use this key";
	}
}

template<class TK, class TV>
inline HashMap<TK, TV>::HashMap(const HashMap* M)
{

}

template<class TK, class TV>
inline HashMap<TK, TV>::~HashMap()
{
	Node<TK, TV>* cur;
	for (int i = 0; i < 26; i++)
	{
		while (arr[i].Key!="dont use this key")
		{
			this->Delete(arr[i].Key);
		}
	}
	delete[]arr;
}

template<class TK, class TV>
inline void HashMap<TK, TV>::Add(const TK& Key, const TV& Value)
{
	int i = Hash(Key);
	if (arr[i].Key == "dont use this key")
	{
		HashNode<TK, TV> tmp(Key, Value);
		arr[i] = tmp;
	}
	else
	{

		HashNode<TK, TV>* tmp = &arr[i];
		while (tmp->next)
		{
			tmp = tmp->next;
		}
		tmp->next = new HashNode<TK, TV>(Key, Value);
	}
}

template<class TK, class TV>
inline TV HashMap<TK, TV>::Find(const TK& Key)
{
	int i = Hash(Key);
	HashNode<TK, TV>* tmp = &arr[i];
	while (tmp)
	{
		if (tmp->Key==Key)
		{
			return tmp->Value;
		}
		tmp = tmp->next;
	}
	exit(1);
}

template<class TK, class TV>
inline TV& HashMap<TK, TV>::operator[](const TK& Key)
{
	int i = Hash(Key);
	HashNode<TK, TV>* tmp = &arr[i];
	if (tmp->Key=="dont use this key")
	{
		tmp = new HashNode<TK, TV>(Key);
		return tmp->Value;
	}
	while (tmp->next)
	{
		if (tmp->Key == Key)
		{
			return tmp->Value;
		}
		tmp = tmp->next;
	}
	tmp->next = new HashNode<TK, TV>(Key);
	return tmp->next->Value;
}

template<class TK, class TV>
inline void HashMap<TK, TV>::Delete(const TK& Key)
{
	int i = Hash(Key);
	HashNode<TK, TV>* cur = &arr[i];
	HashNode<TK, TV>* prev=0;
	if (arr[i].Key==Key)
	{
		if (arr[i].next)
		{
			arr[i].Key = arr[i].next->Key;
			arr[i].Value = arr[i].next->Value;
			arr[i].next = arr[i].next->next;
		}
		else
		{
			cur->Key = "dont use this key";
			cur->Value = 0;
			return;
		}
	}
	while (cur)
	{
		if (cur->Key==Key)
		{
			if (prev)
			{
				prev->next = cur->next;
				return;
			}
			else
			{
				cur->Key = "dont use this key";
				cur->Value = 0;
				return;
			}
		}
		
		prev = cur;
		cur = cur->next;
	}
}
