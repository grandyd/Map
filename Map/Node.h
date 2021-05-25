#pragma once
template<class TK, class TV>
class Node
{
	TK Key;
	TV Value;
public:
	Node(const TK& Key = 0, const TV& Value = 0);
	Node(const Node& N);
	~Node() {}

	TK GetKey();
	TV& GetValue();

	void SetKey(const TK& Key);
	void SetValue(const TV& Value);

	Node<TK, TV>& operator=(const Node<TK,TV>& N);

	bool operator==(const Node<TK,TV>& N);
	bool operator>(const Node<TK,TV>& N);
	bool operator<(const Node<TK,TV>& N);

	template<class TK, class TV>
	friend class Map;

	template<class TK, class TV>
	friend class SortMap;

	template<class TK, class TV>
	friend class TNode;

	template<class TK, class TV>
	friend class TreeMap;
};

template<class TK, class TV>
inline Node<TK, TV>::Node(const TK& Key, const TV& Value)
{
	this->Key = Key;
	this->Value = Value;
}

template<class TK, class TV>
inline Node<TK, TV>::Node(const Node<TK, TV>& N)
{
	this->Key = N.Key;
	this->Value = N.Value;
}

template<class TK, class TV>
inline TK Node<TK, TV>::GetKey()
{
	return this->Key;
}

template<class TK, class TV>
inline TV& Node<TK, TV>::GetValue()
{
	return this->Value;
}

template<class TK, class TV>
inline void Node<TK, TV>::SetKey(const TK& Key)
{
	this->Key = Key;
}

template<class TK, class TV>
inline void Node<TK, TV>::SetValue(const TV& Value)
{
	this->Value = Value;
}

template<class TK, class TV>
inline Node<TK, TV>& Node<TK, TV>::operator=(const Node<TK,TV>& N)
{
	this->Key = N.Key;
	this->Value = N.Value;

	return *this;
}

template<class TK, class TV>
inline bool Node<TK, TV>::operator==(const Node<TK, TV>& N)
{
	return (this->Value == N.Value && this->Key == N.Key) ? 1 : 0;
}

template<class TK, class TV>
inline bool Node<TK, TV>::operator>(const Node<TK, TV>& N)
{
	return (this->Key > N.Key ? 1 : 0);
}

template<class TK, class TV>
inline bool Node<TK, TV>::operator<(const Node<TK, TV>& N)
{
	return (this->Key < N.Key ? 1 : 0);
}
