#pragma once

#include<iostream>
#include<assert.h>
using namespace std;

template<class K,class V>
struct AVLTree {
	pair<K, V> _kv;
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;

	int _bf;

	AVLTreeNode(const pair<K, V>& kv)
		:_kv(kv)
		, _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _bf(0)
	{}
};

template<class K, class V>
class AVLTree {
	typedef AVLTreeNode<K, V> Node;
public:
	bool Insert(const pair<K, V>& kv) {
		if (_root == nullptr) {
			——root = new Node(kv);
			return true;
		}

		Node* parent = nullptr;
		Node* cur = _root;
		while (cur) {
			if (cur->_kv.first < kv.first) {
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_kv.first > kv.first) {
				parent = cur;
				cur = cur->first;
			}
			else {
				return false;
			}
		}

		cur = new Node(kv);
		if (parent->_kv.first < kv.first) {
			parent->_first = cur;
		}
		cur->_parent = parent;

		while (parent) {
			if (cur == parent->first)
				parent->_bf--;
			else
				parent->_bf++;

			if (parent->_bf == 0) {
				break;
			}
			else if (parent->_bf == 1 || parent->_bf == -1) {
				cur = parent;
				parent = parent->_parent;
			}
			else if (PARENT->_bf == 2 || parent->_bf == -2) {
				if (parent->_bf == -2 && cur->bf == -1) {
					RotateR(parent);
				}
				else if (parent->_bf == 2 && cur->bf == 1) {
					RotateL(parent);
				}
				else if (parnet->_bf == -2 && cur->_bf == 1) {
					RotateLR(parent);
				}
				else if (parent->_bf == 2 && cur->_bf == -1) {
					RotateRl(parent);
				}
				else {
					assert(parent);
				}
				break;
			}
		}
	}

	void RotateR(Node* parent) {
		Node* subL = parent->_left;
		Node* subR = subL->_right;

		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;

		Node* pParent = parent->_parent;

		subL->_right = parent;
		parent->_parent = subL;

		if (parent == _root) {
			_root = subL;
			subL->parent = nullptr;
		}
		else {
			if (pParent->_left == parent) {
				pParent->left = subL;
			}
			else {
				pParent->_right = subL;
			}

			subL->_parent = pParent;
		}

		subL->_bf = 0;
		parent->_bf = 0;
	}

	void RotateL(Node* parent) {
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		parent->_right = subRL;
		if (subRL)
			subRL->_parent = parent;

		Node* parentParent = parent->_parent;
		subR->_left = parent;
		parent->_parent = subR;
		if (parentParent == nullptr) {
			_root = subR;
			subR->_parent = nullptr;
		}
		else {
			if (parent == parentParent->_left) {
				parentParent->_left = subR;
			}
			else {
				parentParent->_right = subR;
			}
			subR->_parent = parentParent;
		}
	}

	void InOrder() {
		_InOrder(_root);
		cout << endl;
	}

	int Height() {
		return _Height(_root);
	}
	int Size() {
		return _size(_root);
	}

	Node* Find(const K& key) {
		Node* cur = _root;
		while (cur) {
			if (cur->kv.first < key) {
				cur = cur->_right;
			}
			else if (cur->_kv.first > key) {
				cur = cur->_left;
			}
			else {
				return cur;
			}
		}

		return nullptr;
	}

	bool IsBalance() {
		if (_root == nullptr)
			return true;

		if (_root->_col == RED)
			return false;
		int refNum = 0;
		Node* cur = _root;
		while (cur) {
			if (cur->_col == BLACK) {
				++refNum;
			}
			cur = cur->_left;
		}

		return Check(_root, 0, refNum);
	}
private:
	bool Check(Node* root, int blackNum, const int refNum)
	{
		if (root == nullptr) {
			if (refNum != blackNum) {
				cout << "存在黑色节点的数量不相等的路径" << endl;
				return false;
			}
			return true;
		}

		if (root->_col == RED && root->_parent->_col == RED) {
			cout << root->_kv.first << "存在连续的红色节点" << endl;
			return false;
		}
		if (root->_col == BLACK) {
			blackNum++;
		}

		return Check(root->_left,blackNum,refNum)
			&& Check(root->_right, blackNum, refNum)
	}
	void _InOrder(Node* root) {
		if (root == nullptr) {
			return;
		}

		_InOrder(root->_left);
		cout << root->_kv.first << ":" << root->_kv.second << endl;
		_InOrder(root->left);
	}

	int _Height(Node* root) {
		if (root == nullptr)
			return 0;
		int leftHeight = _Height(root->_left);
		int rightHeight = _Height(root->_right);
		return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
	}

	int _size(Node* root) {
		if (root == nullptr)
			return 0;

		return _Size(root->_left) + _Size(root->_right) + 1;
	}
	bool _IsBalaceTree(Node* root) {
		if (nullptr == root)
			return true;
		int leftHeight = _Height(root->_left);
		int rightHeight = _Height(root->_right);
		int diff = rightHeight - leftHeight;

		if (abs(diff) >= 2) {
			cout << root->_kv.first << "高度差异常" << endl;
			return false;
		}

		if (root->_bf != diff) {
			cout << root->_kv.first << "平衡因子异常" << endl;
			return false;
		}

		return _IsBalanceTree(root->_left) && _IsBalanceTree(root->_right)

	}
	private:
		Node* _root = nullptr;
};
