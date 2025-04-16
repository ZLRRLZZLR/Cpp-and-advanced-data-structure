#pragma once
#include<assert.h>

enum Colour
{
	RED,
	BLACK
};


template<class T>
struct RBTreeNode
{
	RBTreeNode(T& data)
		:_data(data),
		_left(nullptr),
		_right(nullptr)
		_parent(nullptr)
	{ }

	T _data;
	RBTreeNode<T>* _parent;
	RBTreeNode<T>* _left;
	RBTreeNode<T>* right;
	Colour _col = RED;
};


// 说明：
// 1. 在完善迭代器前，请先确保红黑树实现成功
// 2. 迭代器实现好后，与红黑树结合起来，能够通过红黑树的迭代器遍历红黑树
// 3. 此处给的迭代器实现并不完整，缺少--操作，大家只需要将++实现即可，此处主要了解红黑树迭代器原理即可
//    要实现完整的迭代器需要对红黑树进行改造，有兴趣可参考侯捷《STL源码剖析》

﻿template<class T,class Ptr,class Ref>
struct RBTreeIterator
{
	typedef RBTreeNode<T> Node;
	typedef RBTreeIterator<T,Ptr,Ref> Self;

	Node* _node;
	Node* _root;

	RBTreeIterator(Node* node,Node* root)
		:_node(node)
		,_root(root)
	{}

	// 请完善迭代器的++操作，让迭代器可以移动
	Self operator++()
	{
		Node* child = _node;

		if(child->right)
		{
			Node* cur = child->right;
			while(cur->_left)
			{
				cur = cur->_left;
			}
			_node = cur;
		}
		else
		{
			Node* parent = _node->_parent;
			Node* cur = child;
			while(parent && cur == parent->right)
			{
				cur = parent;
				parent = cur->_parent;
			}
			_node = parent;
		}
		return *this;
	}

	Self operator--()
	{
		if(_node == nullptr)
		{
			if(_root == nullptr)
			{
				assert("nullptr");
			}
			Node* cur = _root;
			while(cur->right)
			{
				cur = cur->right;
			}
			_node = cur;
		}
		else
		{
			Node* child = _node;

			if (child->_left)
			{
				Node* cur = child->_left;
				while (cur->right)
				{
					cur = cur->right;
				}
				_node = cur;
			}
			else
			{
				Node* parent = _node->_parent;
				Node* cur = child;
				while (parent && cur == parent->_left)
				{
					cur = parent;
					parent = cur->_parent;
				}
				_node = parent;
			}
		}
		return *this;
	}

	// 请完善下面两个操作，让迭代器可以像指针一样操作
	Ptr operator*()
	{
		return _node->_data;
	}
	Ref operator->()
	{
		return &_node->_data;
	}

	// 请完善下面两个操作，让迭代器能够支持比较
	bool operator!=(const Self& s)const
	{
		return _node != s._node;
	}
	bool operator==(const Self& s)const
	{
		return _node == s._node;
	}
};



// 注意：红黑树完整操作参考课堂代码
// 此处给红黑树添加迭代器，其他用不到的操作暂被拿掉，只留下红黑树构建的核心操作
template<class K, class T, class KeyOfT>
class RBTree
{
	typedef RBTreeNode<T> Node;
public:
	// 请给红黑树的迭代器取别名，方便后序使用
	typedef RBTreeIterator<T, T&, T*> iterator;
	typedef RBTreeIterator<T, const T&, const T*> const_iterator;


	// 请完善Begin() 和 End()方法
	iterator Begin()
	{
		Node* cur = _root;
		if(cur)
		{
			while(cur->_left)
			{
				cur = cur->_left;
			}
			return iterator{ cur,_root };
		}
		else
		{
			return iterator{ nullptr,_root };
		}
	}
	iterator End()
	{
		return iterator{ nullptr,_root };
	}

	const_iterator Begin() const
	{
		Node* cur = _root;
		if (cur)
		{
			while (cur->_left)
			{
				cur = cur->_left;
			}
			return const_iterator{ cur,_root };
		}
		else
		{
			return const_iterator{ nullptr,_root };
		}
	}
	const_iterator End() const
	{
		return const_iterator{ nullptr,_root };
	}


	~RBTree()
	{
		Destroy(_root);
		_root = nullptr;
	}


	pair<iterator,bool> Insert(const T& data)
	{
		if (_root == nullptr)
		{
			_root = new Node(data);
			_root->_col = BLACK;
			return {iterator(_root,_root),true};
		}


		KeyOfT kot;
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (kot(cur->_data) < kot(data))
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (kot(cur->_data) > kot(data))
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return {iterator(cur,_root),false};
			}
		}


		cur = new Node(data);
		// 新增节点。颜色红色给红色
		cur->_col = RED;
		if (kot(parent->_data) < kot(data))
		{
			parent->_right = cur;
		}
		else
		{
			parent->_left = cur;
		}
		cur->_parent = parent;

		while (parent && parent->_col == RED)
		{
			Node* grandfather = parent->_parent;
			//    g
			//  p   u
			if (parent == grandfather->_left)
			{
				Node* uncle = grandfather->_right;
				if (uncle && uncle->_col == RED)
				{
					// u存在且为红 -》变色再继续往上处理
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;


					cur = grandfather;
					parent = cur->_parent;
				}
				else
				{
					// u存在且为黑或不存在 -》旋转+变色
					if (cur == parent->_left)
					{
						//    g
						//  p   u
						//c
						//单旋
						RotateR(grandfather);
						parent->_col = BLACK;
						grandfather->_col = RED;
					}
					else
					{
						//    g
						//  p   u
						//    c
						//双旋
						RotateL(parent);
						RotateR(grandfather);


						cur->_col = BLACK;
						grandfather->_col = RED;
					}
					break;
				}
			}
			else
			{
				//    g
				//  u   p
				Node* uncle = grandfather->_left;
				// 叔叔存在且为红，-》变色即可
				if (uncle && uncle->_col == RED)
				{
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;

					// 继续往上处理
					cur = grandfather;
					parent = cur->_parent;
				}
				else // 叔叔不存在，或者存在且为黑
				{
					// 情况二：叔叔不存在或者存在且为黑
					// 旋转+变色
					//      g
					//   u     p
					//            c
					if (cur == parent->_right)
					{
						RotateL(grandfather);
						parent->_col = BLACK;
						grandfather->_col = RED;
					}
					else
					{
						//		g
						//   u     p
						//      c
						RotateR(parent);
						RotateL(grandfather);
						cur->_col = BLACK;
						grandfather->_col = RED;
					}
					break;
				}
			}
		}

		_root->_col = BLACK;
		return {iterator(cur,_root),true};
	}
private:
	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		if (subRL)
			subRL->_parent = parent;

		Node* parentParent = parent->_parent;

		subR->_left = parent;
		parent->_parent = subR;


		if (parentParent == nullptr)
		{
			_root = subR;
			subR->_parent = nullptr;
		}
		else
		{
			if (parent == parentParent->_left)
			{
				parentParent->_left = subR;
			}
			else
			{
				parentParent->_right = subR;
			}

			subR->_parent = parentParent;
		}
	}


	void  RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;

		Node* parentParent = parent->_parent;

		subL->_right = parent;
		parent->_parent = subL;

		if (parentParent == nullptr)
		{
			_root = subL;
			subL->_parent = nullptr;
		}
		else
		{
			if (parent == parentParent->_left)
			{
				parentParent->_left = subL;
			}
			else
			{
				parentParent->_right = subL;
			}
			subL->_parent = parentParent;
		}
	}

	void Destroy(Node* root)
	{
		if (root == nullptr)
			return;

		Destroy(root->_left);
		Destroy(root->_right);
		delete root;
	}

private:
	Node* _root = nullptr;
};