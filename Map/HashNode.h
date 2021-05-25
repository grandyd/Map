#pragma once
template<class TK, class TV>
class HashNode
{
	TK Key;
	TV Value;
	HashNode* next;
public:
	HashNode(const TK& Key = TK(), const TV& Value = 0, HashNode<TK, TV>* next = 0);
	HashNode(HashNode& N);
	~HashNode() {}

	TK GetKey();
	TV& GetValue();

	void SetKey(const TK& Key);
	void SetValue(const TV& Value);

	HashNode<TK, TV>& operator=(HashNode<TK, TV>& N);

	bool operator==(const HashNode<TK, TV>& N);
	bool operator>(const HashNode<TK, TV>& N);
	bool operator<(const HashNode<TK, TV>& N);

	template<class TK, class TV>
	friend class HashMap;
};

template<class TK, class TV>
inline HashNode<TK, TV>::HashNode(const TK& Key, const TV& Value, HashNode<TK, TV>* next)
{
	this->Key = Key;
	this->Value = Value;
	this->next = next;
}

template<class TK, class TV>
inline HashNode<TK, TV>::HashNode(HashNode<TK, TV>& N)
{
	this->Key = N.Key;
	this->Value = N.Value;
	HashNode<TK, TV>* tmp = &N;
	HashNode<TK, TV>* cur = this;
	while (tmp->next)
	{
		cur->next = new HashNode<TK,TV>(tmp->next->Key,tmp->next->Value);
		tmp = tmp->next;
		cur = cur->next;
	}
	cur->next = 0;
}

template<class TK, class TV>
inline TK HashNode<TK, TV>::GetKey()
{
	return this->Key;
}

template<class TK, class TV>
inline TV& HashNode<TK, TV>::GetValue()
{
	return this->Value;
}

template<class TK, class TV>
inline void HashNode<TK, TV>::SetKey(const TK& Key)
{
	this->Key = Key;
}

template<class TK, class TV>
inline void HashNode<TK, TV>::SetValue(const TV& Value)
{
	this->Value = Value;
}

template<class TK, class TV>
inline HashNode<TK, TV>& HashNode<TK, TV>::operator=(HashNode<TK, TV>& N)
{
	this->Key = N.Key;
	this->Value = N.Value;
	HashNode<TK, TV>* tmp = &N;
	HashNode<TK, TV>* cur = this;
	while (tmp->next)
	{
		cur->next = new HashNode<TK, TV>(tmp->next->Key, tmp->next->Value);
		tmp = tmp->next;
		cur = cur->next;
	}
	cur->next = 0;

	return *this;
}

template<class TK, class TV>
inline bool HashNode<TK, TV>::operator==(const HashNode<TK, TV>& N)
{
	return (this->Value == N.Value && this->Key == N.Key) ? 1 : 0;
}

template<class TK, class TV>
inline bool HashNode<TK, TV>::operator>(const HashNode<TK, TV>& N)
{
	return (this->Key > N.Key ? 1 : 0);
}

template<class TK, class TV>
inline bool HashNode<TK, TV>::operator<(const HashNode<TK, TV>& N)
{
	return (this->Key < N.Key ? 1 : 0);
}
