#pragma once
#include "Node.h"

template<class TK, class TV>
class TNode
{
	Node<TK, TV> Data;
	TNode* left;
	TNode* right;
public:
	TNode(const TK& Key=0, const TV& Value=0)
	{
		this->Data = Node<TK, TV>(Key, Value);
		this->left = this->right = 0;
	}
	TNode(const TNode& T)
	{
		this->Data = Node<TK, TV>(T.Data.Key, T.Data.Value);
		this->left = this->right = 0;
	}
	~TNode() {}

	TNode& operator=(const TNode& T)
	{
		this->Data = Node<TK, TV>(T.Data.Key, T.Data.Value);
		this->left = this->right = 0;
		return *this;
	}

	bool operator==(const TNode<TK, TV>& T)
	{
		return this->Data == T.Data;
	}
	bool operator>(const TNode<TK, TV>& T)
	{
		return this->Data > T.Data;
	}
	bool operator<(const TNode<TK, TV>& T)
	{
		return this->Data < T.Data;
	}

	TK GetKey() { return this->Data.Key; }
	TV& GetValue() { return this->Data.Value; }

	void SetKey(const TK& Key) { this->Data.Key = Key; }
	void SetValue(const TV& Value) { this->Data.Value = Value; }

	template<class TK, class TV>
	friend class TreeMap;
};

