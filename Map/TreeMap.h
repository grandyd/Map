#pragma once
#include "TNode.h"
#include <stdlib.h>
#include <queue>
using namespace std;

template<class TK, class TV>
class TreeMap
{
	TNode<TK, TV>* root;
public:
	TreeMap()
	{
		this->root = 0;
	}
	TreeMap(const TreeMap& T);
	~TreeMap() {
		while (root)
		{
			this->Delete(root->GetKey());
		}
	}

	void Add(const TK& Key, const TV& Value);
	void Delete(const TK& Key);
	TV& operator[](const TK& Key);
	TV Find(const TK& Key);

};

template<class TK, class TV>
inline TreeMap<TK, TV>::TreeMap(const TreeMap& T)
{
	queue<TNode<TK, TV>*> _s;
	queue<TNode<TK, TV>*> _s1;
	this->root = new TNode<TK, TV>(*(T.root));
	_s.push((this->root));
	_s1.push(T.root);
	while (!_s1.empty())
	{

		if (_s1.top()->left != nullptr)
		{
			_s.front()->left = new TNode<TK, TV>(*(_s1.front()->left));
			_s1.push(_s1.top()->left);
			_s.push(_s.top()->left);
		}
		if (_s1.front()->right != nullptr)
		{
			_s.front()->right = new TNode<TK, TV>(*(_s1.front()->right));
			_s1.push(_s1.top()->right);
			_s.push(_s.top()->right);
		}

		_s.pop();
		_s1.pop();
	}
}

template<class TK, class TV>
inline void TreeMap<TK, TV>::Add(const TK& Key, const TV& Value)
{
	if (root == 0)
	{
		root = new TNode<TK, TV>(Key, Value);
		return;
	}
	TNode <TK,TV>* cur = root;
	
	while (cur)
	{
		if (Key<cur->Data.Key)
		{
			if (cur->left==0)
			{
				cur->left = new TNode<TK, TV>(Key, Value);
				return;
			}
			cur = cur->left;
			continue;
		}
		if (Key>cur->Data.Key)
		{
			if (cur->right == 0)
			{
				cur->right = new TNode<TK, TV>(Key, Value);
				return;
			}
			cur = cur->right;
			continue;
		}
	}
}

template<class TK, class TV>
inline void TreeMap<TK, TV>::Delete(const TK& Key)
{
	TNode<TK, TV>* cur = root;
	TNode<TK, TV>* prev = 0;
	while (cur)
	{
		if (Key < cur->Data.Key)
		{
			prev = cur;
			cur = cur->left;
			continue;
		}
		if (Key > cur->Data.Key)
		{
			prev = cur;
			cur = cur->right;
			continue;
		}
		if (Key == cur->Data.Key)
		{

			if (cur->left==0)
			{
				if (prev->right==cur)
				{
					prev->right = cur->right;
					delete cur;
					return;
				}
				if (prev->left==cur)
				{
					prev->left = cur->right;
					delete cur;
					return;
				}
			}
			if (cur->right == 0)
			{
				if (prev->right == cur)
				{
					prev->right = cur->left;
					delete cur;
					return;
				}
				if (prev->left == cur)
				{
					prev->left = cur->left;
					delete cur;
					return;
				}
			}
			if (cur->left->right==0)
			{
				cur->Data = cur->left->Data;
				prev = cur->left;
				cur->left = cur->left->left;
				delete prev;
				return;
			}
			TNode<TK, TV>* tmp = cur->left;
			prev = cur;
			while (tmp)
			{
				if (tmp->right)
				{
					prev = tmp;
					tmp = tmp->right;
				}
				else
				{
					break;
				}
			}
			prev->right = 0;
			cur->Data = tmp->Data;
			delete tmp;
		}
	}
}

template<class TK, class TV>
inline TV& TreeMap<TK, TV>::operator[](const TK& Key)
{
	TNode<TK, TV>* cur = root;
	while (cur)
	{
		if (Key < cur->Data.Key)
		{
			if (cur->left == 0)
			{
				cur->left = new TNode<TK, TV>(Key, 0);
				return cur->left->GetValue();
			}
			cur = cur->left;
			continue;
		}
		if (Key > cur->Data.Key)
		{
			if (cur->right == 0)
			{
				cur->right = new TNode<TK, TV>(Key, 0);
				return cur->left->GetValue();
			}
			cur = cur->right;
			continue;
		}
		if (Key == cur->Data.Key)
		{
			return cur->Data.Value;
		}
	}
}

template<class TK, class TV>
inline TV TreeMap<TK, TV>::Find(const TK& Key)
{
	TNode<TK, TV>* cur = root;
	while (cur)
	{
		if (Key < cur.Data.Key)
		{
			cur = cur.left;
			continue;
		}
		if (Key > cur.Data.Key)
		{
			cur = cur.right;
			continue;
		}
		if (Key==cur->Data.Key)
		{
			return cur->Data.Value;
		}
	}
	exit(1);
}
