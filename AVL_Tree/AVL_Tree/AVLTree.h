#pragma once

#include<iostream>
#include<assert.h>
using namespace std;


template<class T>
struct AVLTreeNode
{
	AVLTreeNode(const T& data = T())
		: _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _data(data)
		, _bf(0)
	{}

	AVLTreeNode<T>* _left;
	AVLTreeNode<T>* _right;
	AVLTreeNode<T>* _parent;
	T _data;
	int _bf;   // 节点的平衡因子
};


// AVL: 二叉搜索树 + 平衡因子的限制
template<class T>
class AVLTree
{
	typedef AVLTreeNode<T> Node;
public:
	AVLTree()
		: _root(nullptr)
	{}

	// 在AVL树中插入值为data的节点
	bool Insert(const T& data)
	{
		if (_root == nullptr)
		{
			_root = new Node(data);
			return true;
		}

		Node* parent = nullptr;
		Node* cur = _root;
		while(cur) 
		{
			if(cur->_data < data)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if(cur->_data > data)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}

		cur = new Node(data);

		if (parent->_data > data) parent->_left = cur;
		else  parent->_right = cur;

		cur->_parent = parent;

		while(parent)
		{
			if(cur == parent->_left)
				parent->_bf--;
			else
				parent->_bf++;

			if(parent->_bf == 0)
			{
				break;
			}

			else if(parent->_bf == -1 || parent->_bf == 1)
			{
				cur = parent;
				parent = parent->_parent;
			}

			else if(parent->_bf == -2 || parent->_bf == 2)
			{
				if(parent->_bf == -2 && cur->_bf == -1)
				{
					RotateR(parent);
				}
				else if(parent->_bf == 2 && cur->_bf == 1)
				{
					RotateL(parent);
				}
				else if(parent->_bf == -2 && cur->_bf == 1)
				{
					RotateLR(parent);
				}
				else if (parent->_bf == 2 && cur->_bf == -1)
				{
					RotateRL(parent);
				}
				else
				{
					assert("false");
				}

				break;
			}

			else
			{
				assert("false");
			}
		}
		return true;
	}


	// AVL树的验证
	bool IsAVLTree()
	{
		return _IsAVLTree(_root);
	}

	//AVL树的高度
	size_t Height()
	{
		return _Height(_root);
	}

	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}

	int Size()
	{
		return _Size(_root);
	}

	Node* Find(const T& key)
	{
		Node* cur = _root;
		while (cur)
		{
			if (cur->_data < key)
			{
				cur = cur->_right;
			}
			else if (cur->_data > key)
			{
				cur = cur->_left;
			}
			else
			{
				return cur;
			}
		}

		return nullptr;
	}

private:
	// 根据AVL树的概念验证pRoot是否为有效的AVL树
	bool _IsAVLTree(Node* root)
	{
		if (root == nullptr) 
		{
			return true;
		}

		int LeftHeights = _Height(root->_left);
		int RightsHeights = _Height(root->_right);

		int heights = RightsHeights - LeftHeights;
		if(abs(heights) >= 2)
		{
			cout << "AVL树异常" << endl;
			return false;
		}
		if (heights != root->_bf)
		{
			cout << "平衡因子异常" << endl;
			return false;
		}

		return _IsAVLTree(root->_left) && _IsAVLTree(root->_right);
	}

	int _Height(Node* root)
	{
		if (root == nullptr)
		{
			return 0;
		}
		int LeftHeights = _Height(root->_left);
		int RightsHeights = _Height(root->_right);

		return LeftHeights > RightsHeights ? LeftHeights + 1 : RightsHeights + 1;
	}

	void _InOrder(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}

		_InOrder(root->_left);
		cout << root->_data << endl;
		_InOrder(root->_right);
	}

	int _Size(Node* root)
	{
		if (root == nullptr)
			return 0;

		return _Size(root->_left) + _Size(root->_right) + 1;
	}

	// 右单旋
	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		subL->_parent = parent->_parent;

		parent->_left = subLR;

		if (subLR)
			subLR->_parent = parent;

		parent->_parent = subL;
		subL->_right = parent;

		if(parent == _root)
		{
			_root = subL;
			subL->_parent = nullptr;
		}
		else
		{
			Node* pparent = subL->_parent;
			if(pparent->_left == parent)
			{
				pparent->_left = subL;
			}
			else
			{
				pparent->_right = subL;
			}
		}

		subL->_bf = 0;
		parent->_bf = 0;
	}
	// 左单旋
	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		subR->_parent = parent->_parent;

		parent->_right = subRL;
		if (subRL)
			subRL->_parent = parent;

		parent->_parent = subR;
		subR->_left = parent;

		if (parent == _root)
		{
			_root = subR;
		}
		else
		{
			Node* pparent = subR->_parent;
			if (pparent->_left == parent)
			{
				pparent->_left = subR;
			}
			else
			{
				pparent->_right = subR;
			}
		}

		subR->_bf = 0;
		parent->_bf = 0;
	}
	// 右左双旋
	void RotateRL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		int bf = subRL->_bf;
		RotateR(subR);
		RotateL(parent);

		if (bf == -1)
		{
			subR->_bf = 1;
			subRL->_bf = 0;
			parent->_bf = 0;
		}
		else if (bf == 1)
		{
			subR->_bf = 0;
			subRL->_bf = 0;
			parent->_bf = -1;
		}
		else if (bf == 0)
		{
			subR->_bf = 0;
			subRL->_bf = 0;
			parent->_bf = 0;
		}
		else
		{
			assert("false");
		}

	}
	// 左右双旋
	void RotateLR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		int bf = subLR->_bf;
		RotateL(subL);
		RotateR(parent);

		if(bf == -1)
		{
			subL->_bf = 0;
			subLR->_bf = 0;
			parent->_bf = 1;
		}
		else if(bf == 1)
		{
			subL->_bf = -1;
			subLR->_bf = 0;
			parent->_bf = 0;
		}
		else if(bf == 0)
		{
			subL->_bf = 0;
			subLR->_bf = 0;
			parent->_bf = 0;
		}
		else
		{
			assert("false");
		}
	}

private:
	Node* _root = nullptr;
};

//template<class K, class V>
//struct AVLTreeNode 
//{
//	pair<K, V> _kv;
//	AVLTreeNode<K, V>* _left;
//	AVLTreeNode<K, V>* _right;
//	AVLTreeNode<K, V>* _parent;
//
//	int _bf;
//
//	AVLTreeNode(const pair<k, V>& kv) {
//		:_kv(kv)
//		,_left(nullptr)
//		,_right(nullptr)
//		,_parent(nullptr)
//		,_bf(0)
//		{}
//	}
//};
//
//template<class K,class V>
//class AVLTree
//{
//	typedef AVLTreeNode<K, V> Node;
//public:
//	bool Insert(const pair<K, V>& kv) 
//	{
//		if(_root = nullptr)
//		{
//			_root = new Node(kv);
//			return true;
//		}
//
//		Node* parent = nullptr;
//		Node* cur = _root;
//		while(cur)
//		{
//			if (cur->_kv.first < kv.first) 
//			{
//				parent = cur;
//				cur = cur->_right;
//			}
//			else if (cur->_kv.first < kv.first) 
//			{
//				parent = cur;
//				cur = cur->_left;
//			}
//			else
//			{
//				return false;
//			}
//
//			cur = new Node(kv);
//			if(parent->_kv.first < kv.first)
//			{
//				parent->_right = cur;
//			}
//			else
//			{
//				parent->_left = cur;
//			}
//
//			cur->_parent = parent;
//
//			while(parent)
//			{
//				if (cur == parent->_left)
//					parent->_bf--;
//				else
//					parent->_bf++;
//
//				if (parent->_bf == 0)
//				{
//					break;
//				}
//
//				else if(parent->_bf == 1 || parent->_bf == -1)
//				{
//					cur = parent;
//					parent = parent->_parent;
//				}
//
//				else if(parent->_bf == 2 || parent->_bf == -2)
//				{
//					if(parent->_bf == -2 && cur->_bf == -1)
//					{
//						RotateR(parent);
//					}
//					else if(parent->_bf == 2 && cur->_bf == 1)
//					{
//						RotateL(parent);
//					}
//					else if(parent->_bf == -2 && cur->_bf == 1)
//					{
//						RotateLR(parent);
//					}
//					else if (parent->_bf == 2 && cur->_bf == -1)
//					{
//						RotateRL(parent);
//					}
//					else
//					{
//						assert(false);
//					}
//					break;
//				}
//				else
//				{
//					assert(false);
//				}
//			}
//
//
//			return true;
//		}
//
//
//	}
//
//	void RotateR(Node* parent)
//	{
//		Node* subL = parent->_left;
//		Node* subLR = subL->_right;
//
//		parent->_left = subLR;
//
//		if (subLR)
//			subLR->_parent = parent;
//
//		Node* pParent = parent->_parent;
//
//		subL->_right = parent;
//		parent->_parent = subL;
//
//		if (parent == _root)
//		{
//			_root = subL;
//			subL->_parent = nullptr;
//		}
//		else
//		{
//			if (pParent->_left = parent)
//			{
//				pParent->_left = subL;
//			}
//			else
//			{
//				pParent->_right = subL;
//			}
//
//			subL->_parent = pParent;
//		}
//
//		subL->_bf = 0;
//		parent->_bf = 0;
//	}
//
//	void RotateL(Node* parent)
//	{
//		Node* subR = parent->_right;
//		Node* subRL = subR->_left;
//		parent->_right = subRL;
//		if (subRL)
//			subRL->_parent = parent;
//
//		Node* parentParent = parent->_parent;
//		subR->_left = parent;
//		parent->_parent = subR;
//		if (parentParent == nullptr)
//		{
//			_root = subR;
//			subR->_parent = nullptr;
//		}
//		else
//		{
//			if (parent == parentParent->_left)
//			{
//				parentParent->_left = subR;
//			}
//			else
//			{
//				parentParent->_right = subR;
//			}
//			subR->_parent = parentParent;
//		}
//
//		parent->_bf = subR->_bf = 0;
//	}
//
//	RotateLR(Node* parent)
//	{
//		Node* subL = parent->_left;
//		Node* subLR = subL->_right;
//		int bf = subLR->_bf;
//
//		RotateL(Parent->_left);
//		RotateR(parent);
//
//		if (bd == -1)
//		{
//			subLR->_bf = 0;
//			subL->_bf = 1;
//			parent->_bf = 1;
//		}
//		else if (bf == 1)
//		{
//			subLR->_bf = 0;
//			subL->_bf = -1;
//			parent->_bf = 0;
//		}
//		else if (bf == 0)
//		{
//			subLR->_bf = 0;
//			subL->_bf = 0;
//			parent->_bf = 0;
//		}
//		else
//		{
//			assert(false);
//		}
//	}
//
//	void RotateRL(Node* parent)
//	{
//		Node* subR = parent->_right;
//		Node* subRL = subR->_left;
//		int bf = subRL->_bf;
//		RotateR(parent->_right);
//		RotateL(parent);
//		if (bf == 0)
//		{
//			subR->_bf = 0;
//			subRL->_bf = 0;
//			parent->_bf = 0;
//		}
//		else if (bf == 1)
//		{
//			subR->_bf = 0;
//			subRL->_bf = 0;
//			parent->_bf = -1;
//		}
//		else if (bf == -1)
//		{
//			subR->_bf = 1;
//			subRL->_bf = 0;
//			parent->_bf = 0;
//		}
//		else
//		{
//			assert(false);
//		}
//	}
//
//	void InOrder()
//	{
//		_InOrder(_root);
//		cout << endl;
//	}
//
//	int Height()
//	{
//		return _Height(_root);
//	}
//
//	int Size()
//	{
//		return _Size(_root);
//	}
//
//	bool IsBalanceTree()
//	{
//		return _IsBalanceTree(_root);
//	}
//
//	Node* Find(const K& key)
//	{
//		Node* cur = _root;
//		while (cur)
//		{
//			if (cur->_kv.first < key)
//			{
//				cur = cur->_right;
//			}
//			else if (cur->_kv.first > key)
//			{
//				cur = cur->_left;
//			}
//			else
//			{
//				return cur;
//			}
//		}
//
//		return nullptr;
//	}
//
//private:
//	void _InOrder(Node* root)
//	{
//		if (root == nullptr)
//		{
//			return;
//		}
//
//		_InOrder(root->_left);
//		cout << root->_kv.first << ":" << root->_kv.second << endl;
//		_InOrder(root->_right);
//	}
//
//	int _Height(Node* root)
//	{
//		if (root == nullptr)
//			return 0;
//		int leftHeight = _Height(root->_left);
//		int rightHeight = _Height(root->_right);
//		return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
//	}
//
//	int _Size(Node* root)
//	{
//		if (root == nullptr)
//			return 0;
//
//		return _Size(root->_left) + _Size(root->_right) + 1;
//	}
//
//	bool _IsBalanceTree(Node* root)
//	{
//		// 空树也是AVL树
//		if (nullptr == root)
//			return true;
//		// 计算pRoot结点的平衡因子：即pRoot左右子树的高度差
//		int leftHeight = _Height(root->_left);
//		int rightHeight = _Height(root->_right);
//		int diff = rightHeight - leftHeight;
//
//		// 如果计算出的平衡因子与pRoot的平衡因子不相等，或者
//		// pRoot平衡因子的绝对值超过1，则一定不是AVL树
//		if (abs(diff) >= 2)
//		{
//			cout << root->_kv.first << "高度差异常" << endl;
//			return false;
//		}
//
//		if (root->_bf != diff)
//		{
//			cout << root->_kv.first << "平衡因子异常" << endl;
//			return false;
//		}
//
//		// pRoot的左和右如果都是AVL树，则该树一定是AVL树
//		return _IsBalanceTree(root->_left) && _IsBalanceTree(root->_right);
//	}
//private:
//	Node* _root = nullptr;
//};


//template<class K, class V>
//struct AVLTreeNode {
//	pair<k, V> _kv;
//	AVLTreeNode<K, V>* _left;
//	AVLTreeNode<K, V>* _right;
//	AVLTreeNode<K, V>* _parent;
//
//	int _bf;
//
//	AVLTreeNode(const pair<K, V>& kv) {
//		:_kv(kv)
//			, _left(nullptr)
//			, _left(nullptr)
//			, _right(nullptr)
//			, _parent(nullptr)
//			, _bf(0)
//		{}
//	}
//};
//
//template<class K, class V>{
//	typedef AVLTreeNode<K, V> Node;
//public:
//	bool Insert(const pair<K, V>& kv) {
//		if (_root == nullptr) {
//			+root = new Node(kv);
//			return true;
//		}
//
//		Node* parent = nullptr;
//		Node* cur = _root;
//		while (cur) {
//			if (cur->_kv.first < kv.first) {
//				parent = cur;
//				cur = cur->_right;
//			}
//			else if (cur->_kv.first > kv.first) {
//				parent = cur;
//				cur = cur->_left;
//			}
//			else {
//				return false;
//			}
//		}
//
//		cur = new Node(kv);
//		if (parent->_kv.first < kv.first) {
//			parent->_right = cur;
//		}
//		else {
//			parent->_left = cur;
//		}
//		cur->_parent = parent;
//	}
//
//	while (parent) {
//		if (cur == parent->_left) {
//			parent->_bf--;
//		}
//		else {
//			paren->_bf++;
//		}
//		if (parent->_bf == 0) {
//			break;
//		}
//		else if (parent->_bf == 1 || parent->_bf == -1)
//		{
//			cur = parent;
//			parent = parent->_parent;
//		}
//		else if (parent->_bf == 2 || parent->_bf == -2) {
//			if (parent->_bf == -2 && cur->_bf == -1)
//			{
//				RotateR(parent);
//			}
//			else if (parent->_bf == 2 && cur->_bf == 1)
//			{
//				RotateL(parent);
//			}
//			else if (parent->_bf == -2 && cur->_bf == 1)
//			{
//				RotateLR(parent);
//			}
//			else if (parent->_bf == 2 && cur->_bf == -1)
//			{
//				RotateRL(parent);
//			}
//			else
//			{
//				assert(false);
//			}
//
//			break;
//		}
//		else {
//			assert(false);
//		}
//	}
//	return true;
//}
//
//void RoteteR(Node* parent) {
//	Node* subL = parent->_left;
//	Node* subL = parent->_right;
//
//	parent->_left = subLR;
//	if (subLR)
//		subLR->_parent = parent;
//	Node* pParent = parent->_parnet;
//
//	subL->_right = parent;
//	parent->_parent = subL;
//	if (paren == _root) {
//		_root = subL;
//		subL->_parent = nullptr;
//	}
//	else {
//		if (pParent->_left == parent) {
//			pParent->_left = subL;
//		}
//		else {
//			pPraent->_right = subL;
//		}
//		subL->_parent = pParent;
//	}
//
//	subL_ > bf = 0;
//	parent->_bf = 0;
//}
//
//void RotateL(Node* parent)
//{
//	Node* subR = parent->_right;
//	Node* subRL = subR->_left;
//	parent->_right = subRL;
//	if (subRL)
//		subRL->_parent = parent;
//
//	Node* parentParent = parent->_parent;
//	subR->_left = parent;
//	parent->_parent = subR;
//	if (parentParent == nullptr)
//	{
//		_root = subR;
//		subR->_parent = nullptr;
//	}
//	else
//	{
//		if (parent == parentParent->_left)
//		{
//			parentParent->_left = subR;
//		}
//		else
//		{
//			parentParent->_right = subR;
//		}
//		subR->_parent = parentParent;
//	}
//
//	parent->_bf = subR->_bf = 0;
//}
//
//void RotateLR(Node* parent)
//{
//	Node* subL = parent->_left;
//	Node* subLR = subL->_right;
//	int bf = subLR->_bf;
//
//	RotateL(parent->_left);
//	RotateR(parent);
//
//	if (bf == -1)
//	{
//		subLR->_bf = 0;
//		subL->_bf = 0;
//		parent->_bf = 1;
//	}
//	else if (bf == 1)
//	{
//		subLR->_bf = 0;
//		subL->_bf = -1;
//		parent->_bf = 0;
//	}
//	else if (bf == 0)
//	{
//		subLR->_bf = 0;
//		subL->_bf = 0;
//		parent->_bf = 0;
//	}
//	else
//	{
//		assert(false);
//	}
//}
//
//void RotateRL(Node* parent)
//{
//	Node* subR = parent->_right;
//	Node* subRL = subR->_left;
//	int bf = subRL->_bf;
//	RotateR(parent->_right);
//	RotateL(parent);
//	if (bf == 0)
//	{
//		subR->_bf = 0;
//		subRL->_bf = 0;
//		parent->_bf = 0;
//	}
//	else if (bf == 1)
//	{
//		subR->_bf = 0;
//		subRL->_bf = 0;
//		parent->_bf = -1;
//	}
//	else if (bf == -1)
//	{
//		subR->_bf = 1;
//		subRL->_bf = 0;
//		parent->_bf = 0;
//	}
//	else
//	{
//		assert(false);
//	}
//}
//
//void InOrder()
//{
//	_InOrder(_root);
//	cout << endl;
//}
//int Height()
//{
//	return _Height(_root);
//}
//
//int Size()
//{
//	return _Size(_root);
//}
//
//bool IsBalanceTree()
//{
//	return _IsBalanceTree(_root);
//}
//
//Node* Find(const K& key)
//{
//	Node* cur = _root;
//	while (cur)
//	{
//		if (cur->_kv.first < key)
//		{
//			cur = cur->_right;
//		}
//		else if (cur->_kv.first > key)
//		{
//			cur = cur->_left;
//		}
//		else
//		{
//			return cur;
//		}
//	}
//
//	return nullptr;
//}
//
//private:
//	void _InOrder(Node* root)
//	{
//		if (root == nullptr)
//		{
//			return;
//		}
//
//		_InOrder(root->_left);
//		cout << root->_kv.first << ":" << root->_kv.second << endl;
//		_InOrder(root->_right);
//	}
//	int _Height(Node* root)
//	{
//		if (root == nullptr)
//			return 0;
//		int leftHeight = _Height(root->_left);
//		int rightHeight = _Height(root->_right);
//		return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
//	}
//	int _Size(Node* root)
//	{
//		if (root == nullptr)
//			return 0;
//
//		return _Size(root->_left) + _Size(root->_right) + 1;
//	}
//
//	bool _IsBalanceTree(Node* root) {
//		if (nullptr == root)
//			return true;
//
//		int leftHeight = _Height(root->_left);
//		int rightHeight = _Height(root->_right);
//		int diff = rightHeight - leftHeight;
//
//		if (abs(diff) >= 2)
//		{
//			cout << root->_kv.first << "高度差异常" << endl;
//			return false;
//		}
//
//		if (root->_bf != diff)
//		{
//			cout << root->_kv.first << "平衡因子异常" << endl;
//			return false;
//		}
//
//		return _IsBalanceTree(root->_left) && _IsBalanceTree(root->_right);
//
//	}
//	private:
//		Node* _root = nullptr;
//};

//template<class K,class V>
//struct AVLTree {
//	pair<K, V> _kv;
//	AVLTreeNode<K, V>* _left;
//	AVLTreeNode<K, V>* _right;
//	AVLTreeNode<K, V>* _parent;
//
//	int _bf;
//
//	AVLTreeNode(const pair<K, V>& kv)
//		:_kv(kv)
//		, _left(nullptr)
//		, _right(nullptr)
//		, _parent(nullptr)
//		, _bf(0)
//	{}
//};
//
//template<class K, class V>
//class AVLTree {
//	typedef AVLTreeNode<K, V> Node;
//public:
//	bool Insert(const pair<K, V>& kv) {
//		if (_root == nullptr) {
//			——root = new Node(kv);
//			return true;
//		}
//
//		Node* parent = nullptr;
//		Node* cur = _root;
//		while (cur) {
//			if (cur->_kv.first < kv.first) {
//				parent = cur;
//				cur = cur->_right;
//			}
//			else if (cur->_kv.first > kv.first) {
//				parent = cur;
//				cur = cur->first;
//			}
//			else {
//				return false;
//			}
//		}
//
//		cur = new Node(kv);
//		if (parent->_kv.first < kv.first) {
//			parent->_first = cur;
//		}
//		cur->_parent = parent;
//
//		while (parent) {
//			if (cur == parent->first)
//				parent->_bf--;
//			else
//				parent->_bf++;
//
//			if (parent->_bf == 0) {
//				break;
//			}
//			else if (parent->_bf == 1 || parent->_bf == -1) {
//				cur = parent;
//				parent = parent->_parent;
//			}
//			else if (PARENT->_bf == 2 || parent->_bf == -2) {
//				if (parent->_bf == -2 && cur->bf == -1) {
//					RotateR(parent);
//				}
//				else if (parent->_bf == 2 && cur->bf == 1) {
//					RotateL(parent);
//				}
//				else if (parnet->_bf == -2 && cur->_bf == 1) {
//					RotateLR(parent);
//				}
//				else if (parent->_bf == 2 && cur->_bf == -1) {
//					RotateRl(parent);
//				}
//				else {
//					assert(parent);
//				}
//				break;
//			}
//		}
//	}
//
//	void RotateR(Node* parent) {
//		Node* subL = parent->_left;
//		Node* subR = subL->_right;
//
//		parent->_left = subLR;
//		if (subLR)
//			subLR->_parent = parent;
//
//		Node* pParent = parent->_parent;
//
//		subL->_right = parent;
//		parent->_parent = subL;
//
//		if (parent == _root) {
//			_root = subL;
//			subL->parent = nullptr;
//		}
//		else {
//			if (pParent->_left == parent) {
//				pParent->left = subL;
//			}
//			else {
//				pParent->_right = subL;
//			}
//
//			subL->_parent = pParent;
//		}
//
//		subL->_bf = 0;
//		parent->_bf = 0;
//	}
//
//	void RotateL(Node* parent) {
//		Node* subR = parent->_right;
//		Node* subRL = subR->_left;
//		parent->_right = subRL;
//		if (subRL)
//			subRL->_parent = parent;
//
//		Node* parentParent = parent->_parent;
//		subR->_left = parent;
//		parent->_parent = subR;
//		if (parentParent == nullptr) {
//			_root = subR;
//			subR->_parent = nullptr;
//		}
//		else {
//			if (parent == parentParent->_left) {
//				parentParent->_left = subR;
//			}
//			else {
//				parentParent->_right = subR;
//			}
//			subR->_parent = parentParent;
//		}
//	}
//
//	void InOrder() {
//		_InOrder(_root);
//		cout << endl;
//	}
//
//	int Height() {
//		return _Height(_root);
//	}
//	int Size() {
//		return _size(_root);
//	}
//
//	Node* Find(const K& key) {
//		Node* cur = _root;
//		while (cur) {
//			if (cur->kv.first < key) {
//				cur = cur->_right;
//			}
//			else if (cur->_kv.first > key) {
//				cur = cur->_left;
//			}
//			else {
//				return cur;
//			}
//		}
//
//		return nullptr;
//	}
//
//	bool IsBalance() {
//		if (_root == nullptr)
//			return true;
//
//		if (_root->_col == RED)
//			return false;
//		int refNum = 0;
//		Node* cur = _root;
//		while (cur) {
//			if (cur->_col == BLACK) {
//				++refNum;
//			}
//			cur = cur->_left;
//		}
//
//		return Check(_root, 0, refNum);
//	}
//private:
//	bool Check(Node* root, int blackNum, const int refNum)
//	{
//		if (root == nullptr) {
//			if (refNum != blackNum) {
//				cout << "存在黑色节点的数量不相等的路径" << endl;
//				return false;
//			}
//			return true;
//		}
//
//		if (root->_col == RED && root->_parent->_col == RED) {
//			cout << root->_kv.first << "存在连续的红色节点" << endl;
//			return false;
//		}
//		if (root->_col == BLACK) {
//			blackNum++;
//		}
//
//		return Check(root->_left,blackNum,refNum)
//			&& Check(root->_right, blackNum, refNum)
//	}
//	void _InOrder(Node* root) {
//		if (root == nullptr) {
//			return;
//		}
//
//		_InOrder(root->_left);
//		cout << root->_kv.first << ":" << root->_kv.second << endl;
//		_InOrder(root->left);
//	}
//
//	int _Height(Node* root) {
//		if (root == nullptr)
//			return 0;
//		int leftHeight = _Height(root->_left);
//		int rightHeight = _Height(root->_right);
//		return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
//	}
//
//	int _size(Node* root) {
//		if (root == nullptr)
//			return 0;
//
//		return _Size(root->_left) + _Size(root->_right) + 1;
//	}
//	bool _IsBalaceTree(Node* root) {
//		if (nullptr == root)
//			return true;
//		int leftHeight = _Height(root->_left);
//		int rightHeight = _Height(root->_right);
//		int diff = rightHeight - leftHeight;
//
//		if (abs(diff) >= 2) {
//			cout << root->_kv.first << "高度差异常" << endl;
//			return false;
//		}
//
//		if (root->_bf != diff) {
//			cout << root->_kv.first << "平衡因子异常" << endl;
//			return false;
//		}
//
//		return _IsBalanceTree(root->_left) && _IsBalanceTree(root->_right)
//
//	}
//	private:
//		Node* _root = nullptr;
//};
