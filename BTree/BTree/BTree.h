#pragma once
#include<functional>
using namespace std;

template<class K, size_t M>
struct BTreeNode
{
	//K _keys[M - 1];
	//BTreeNode<K, M>* _subs[M];

	// 为了方便插入以后再分裂，多给一个空间
	K _keys[M];
	BTreeNode<K, M>* _subs[M + 1];
	BTreeNode<K, M>* _parent;
	// 记录实际存储多个关键字 
	size_t _n;

	BTreeNode()
	{
		int i = 0;
		for (; i < M; i++) {
			_keys[i] = K();
			_subs[i] = nullptr;
		}

		_subs[i] = nullptr;
		_parent = nullptr;

		_n = 0;
	}

};



// 数据是存在磁盘，K是磁盘地址
template<class K, size_t M>
class BTree
{
	typedef BTreeNode<K, M> Node;
public:

	pair<Node*, int> Find(const K& key)
	{
		Node* parent = nullptr;
		Node* cur = _root;

		while (cur)
		{
			int i = 0;
			//先在一个分支上找
			while (i < cur->_n)
			{
				if (key < cur->_keys[i]) {
					break;
				}
				else if (key > cur->_keys[i]) {
					i++;
				}
				else {
					return make_pair(cur, i);
				}

			}

			//跳转到孩子继续找
			//如果是因为小于break出来的，i未++；如果是>不满足循环的，i已经++了直接可以到右子树
			parent = cur;
			cur = cur->_subs[i];
		}

		return make_pair(parent, -1);
	}

	//插入数据
	void InsertKey(Node* node, const K& key, Node* child)
	{
		int end = node->_n - 1;

		while (end >= 0) {
			if (node->_keys[end] > key) {
				node->_keys[end + 1] = node->_keys[end];
				node->_subs[end + 2] = node->_subs[end + 1];
				end--;
			}
			else {
				break;
			}
		}

		node->_keys[end + 1] = key;
		node->_subs[end + 2] = child;
		node->_n++;

		if (child) {
			child->_parent = node;
		}

	}

	bool Insert(const K& key)
	{
		//空树的情况
		if (_root == nullptr) {
			_root = new Node;
			_root->_keys[0] = key;
			_root->_n++;
			return true;
		}

		pair<Node*, int> ret = Find(key);
		if (ret.second >= 0) {
			return false;
		}

		Node* parent = ret.first;
		Node* child = nullptr;

		InsertKey(parent, key, child);

		//插入后判断是否分裂

		while (parent->_n >= M) {
			size_t mid = M / 2;
			Node* brother = new Node;
			//如果当前需要分裂节点是根

			int i = mid + 1;
			int j = 0;
			//分裂一半节点给兄弟
			for (; i <= M - 1; i++) {
				brother->_keys[j] = parent->_keys[i];
				brother->_subs[j++] = parent->_subs[i];
				parent->_n--;
				brother->_n++;

				if (parent->_subs[i]) {
					parent->_subs[i]->_parent = brother;
				}

				parent->_keys[i] = K();
				parent->_subs[i] = nullptr;
			}

			brother->_subs[j] = parent->_subs[i];
			parent->_subs[i];
			if (parent->_subs[i]) {
				parent->_subs[i]->_parent = brother;
			}


			if (parent->_parent == nullptr) {
				_root = new Node;
				_root->_subs[0] = parent;
				_root->_subs[1] = brother;
				parent->_parent = _root;
				brother->_parent = _root;
			}

			InsertKey(parent->_parent, parent->_keys[mid], brother);

			parent->_keys[mid] = K();
			parent->_n--;
			parent = parent->_parent;
		}
		return true;
	}

void _InOrder(Node* cur)
{
	if (cur == nullptr)
		return;

	// 左 根  左 根  ...  右
	size_t i = 0;
	for (; i < cur->_n; ++i)
	{
		_InOrder(cur->_subs[i]); // 左子树
		cout << cur->_keys[i] << " "; // 根
	}

	_InOrder(cur->_subs[i]); // 最后的那个右子树

}

void InOrder()
{
	_InOrder(root);
}



private:
	Node* _root = nullptr;
};


void TestBtree()
{
	int a[] = { 53, 139, 75, 49, 145, 36, 101 };
	BTree<int, 3> t;
	for (auto e : a)
	{
		t.Insert(e);
	}
	t.InOrder();
}