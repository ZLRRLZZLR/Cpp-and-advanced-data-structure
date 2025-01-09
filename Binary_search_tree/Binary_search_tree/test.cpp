#include<iostream>
#include<string>
#define _CRT_SECURE_NO_WARNINGS 1
#include"BinarySearch.h"
using namespace std;

//namespace key_value
//{
//	template<class K, class V>
//	struct BSTNode
//	{
//		K _key;
//		V _value;
//
//		BSTNode<K, V>* _left;
//		BSTNode<K, V>* _right;
//
//		BSTNode(const K& key, const V& value)
//			:_key(key)
//			, _value(value)
//			, _left(nullptr)
//			, _right(nullptr)
//		{}
//	};
//
//	// Binary Search Tree
//	// Key/value
//	template<class K, class V>
//	class BSTree
//	{
//		//typedef BSTNode<K> Node;
//		using Node = BSTNode<K, V>;
//	public:
//		// 强制生成构造
//		BSTree() = default;//有拷贝构造，不再生成默认构造，强制生成
//
//		BSTree(const BSTree& t)//深拷贝、拷贝构造
//		{
//			_root = Copy(t._root);
//		}
//
//		BSTree& operator=(BSTree tmp)
//		{
//			swap(_root, tmp._root);//现代写法，直接交换根节点指向
//			return *this;
//		}
//
//		~BSTree()
//		{
//			Destroy(_root);//后续遍历释放资源
//			_root = nullptr;
//		}
//
//		bool Insert(const K& key, const V& value)
//		{
//			if (_root == nullptr)
//			{
//				_root = new Node(key, value);
//				return true;
//			}
//
//			Node* parent = nullptr;
//			Node* cur = _root;
//
//			while (cur)
//			{
//				if (cur->_key < key)
//				{
//					parent = cur;
//					cur = cur->_right;
//				}
//				else if (cur->_key > key)
//				{
//					parent = cur;
//					cur = cur->_left;
//				}
//				else
//				{
//					return false;
//				}
//			}
//
//			cur = new Node(key, value);
//			if (parent->_key < key)
//			{
//				parent->_right = cur;
//			}
//			else
//			{
//				parent->_left = cur;
//			}
//
//			return true;
//		}
//
//		Node* Find(const K& key)
//		{
//			Node* cur = _root;
//			while (cur)
//			{
//				if (cur->_key < key)
//				{
//					cur = cur->_right;
//				}
//				else if (cur->_key > key)
//				{
//					cur = cur->_left;
//				}
//				else
//				{
//					return cur;
//				}
//			}
//
//			return nullptr;
//		}
//
//		bool Erase(const K& key)
//		{
//			Node* parent = nullptr;
//			Node* cur = _root;
//
//			while (cur)
//			{
//				if (cur->_key < key)
//				{
//					parent = cur;
//					cur = cur->_right;
//				}
//				else if (cur->_key > key)
//				{
//					parent = cur;
//					cur = cur->_left;
//				}
//				else
//				{
//					// 删除
//					// 左为空
//					if (cur->_left == nullptr)
//					{
//						if (cur == _root)
//						{
//							_root = cur->_right;
//						}
//						else
//						{
//							if (parent->_left == cur)
//							{
//								parent->_left = cur->_right;
//							}
//							else
//							{
//								parent->_right = cur->_right;
//							}
//						}
//						delete cur;
//
//					}
//					else if (cur->_right == nullptr)
//					{
//						if (cur == _root)
//						{
//							_root = cur->_left;
//						}
//						else
//						{
//							// 右为空
//							if (parent->_left == cur)
//							{
//								parent->_left = cur->_left;
//							}
//							else
//							{
//								parent->_right = cur->_left;
//							}
//						}
//
//						delete cur;
//
//					}
//					else
//					{
//						// 左右都不为空
//						// 右子树最左节点
//						Node* replaceParent = cur;
//						Node* replace = cur->_right;
//						while (replace->_left)
//						{
//							replaceParent = replace;
//							replace = replace->_left;
//						}
//
//						cur->_key = replace->_key;
//
//						if (replaceParent->_left == replace)
//							replaceParent->_left = replace->_right;
//						else
//							replaceParent->_right = replace->_right;
//
//						delete replace;
//					}
//
//					return true;
//				}
//			}
//
//			return false;
//		}
//
//		void InOrder()
//		{
//			_InOrder(_root);
//			cout << endl;
//		}
//	private:
//		void _InOrder(Node* root)
//		{
//			if (root == nullptr)
//			{
//				return;
//			}
//
//			_InOrder(root->_left);
//			cout << root->_key << ":" << root->_value << endl;
//			_InOrder(root->_right);
//		}
//
//		void Destroy(Node* root)//后序递归释放资源
//		{
//			if (root == nullptr)
//				return;
//
//			Destroy(root->_left);//先释放左子树
//			Destroy(root->_right);//再释放右子树
//			delete root;//释放根节点
//		}
//
//		Node* Copy(Node* root)//前序遍历递归、拷贝构造
//		{
//			if (root == nullptr)
//				return nullptr;
//
//			Node* newRoot = new Node(root->_key, root->_value);
//			newRoot->_left = Copy(root->_left);
//			newRoot->_right = Copy(root->_right);
//			return newRoot;
//		}
//	private:
//		Node* _root = nullptr;
//	};
//}

//namespace key
//{
//	template<class K>
//	struct BSTNode
//	{
//		K _key;
//		BSTNode<K>* _left;
//		BSTNode<K>* _right;
//
//		BSTNode(const K& key)
//			:_key(key)
//			, _left(nullptr)
//			, _right(nullptr)
//		{}
//	};
//
//	// Binary Search Tree
//	// Key
//	template<class K>
//	class BSTree
//	{
//		//typedef BSTNode<K> Node;
//		using Node = BSTNode<K>;
//	public:
//
//		bool Insert(const K& key)
//		{
//			if (_root == nullptr)
//			{
//				_root = new Node(key);
//				return true;
//			}
//
//			Node* parent = nullptr;
//			Node* cur = _root;
//
//			while (cur)//遍历到要插入的位置
//			{
//				if (cur->_key < key)//要插入值比当前位置大，插入位置在右边
//				{
//					parent = cur;
//					cur = cur->_right;
//				}
//				else if (cur->_key > key)//要插入值比当前位置小，插入位置在左边
//				{
//					parent = cur;
//					cur = cur->_left;
//				}
//				else//要树中已存在要插入值，插入失败
//				{
//					return false;
//				}
//			}
//
//			cur = new Node(key);
//			if (parent->_key < key)//判断要插入值是插在左子树还是右子树上
//			{
//				parent->_right = cur;
//			}
//			else
//			{
//				parent->_left = cur;
//			}
//
//			return true;
//		}
//
//		bool Find(const K& key)
//		{
//			Node* cur = _root;
//			while (cur)
//			{
//				if (cur->_key < key)//要查找的值比根值大，往右子树查找
//				{
//					cur = cur->_right;
//				}
//				else if (cur->_key > key)//要查找的值比根值小，往左子树查找
//				{
//					cur = cur->_left;
//				}
//				else//相等，找到值
//				{
//					return true;
//				}
//			}
//
//			return false;//遍历到空节点，找不到该值。
//		}
//
//		bool Erase(const K& key)
//		{
//			Node* parent = nullptr;
//			Node* cur = _root;
//
//			while (cur)
//			{
//				if (cur->_key < key)
//				{
//					parent = cur;
//					cur = cur->_right;
//				}
//				else if (cur->_key > key)
//				{
//					parent = cur;
//					cur = cur->_left;
//				}
//				else
//				{
//				// 删除
//				// 左为空
//				// 0-1个孩子的情况
//				// 删除情况1 2 3均可以直接删除，改变父亲对应孩子指针
//				//指向即可
//					if (cur->_left == nullptr)//左为空
//					{
//						if (cur == _root)//如果删除节点是根节点，特殊处理一下
//						{
//							_root = cur->_right;
//						}
//						else
//						{
//							if (parent->_left == cur)
//							{
//								parent->_left = cur->_right;
//							}
//							else
//							{
//								parent->_right = cur->_right;
//							}
//						}
//						delete cur;
//
//					}
//					else if (cur->_right == nullptr)
//					{
//						if (cur == _root)
//						{
//							_root = cur->_left;
//						}
//						else
//						{
//							// 右为空
//							if (parent->_left == cur)
//							{
//								parent->_left = cur->_left;
//							}
//							else
//							{
//								parent->_right = cur->_left;
//							}
//						}
//
//						delete cur;
//
//					}
//					else
//					{
//					// 左右都不为空
//					// 2个孩子的情况
//					// 删除情况4，替换法删除
//					// 假设这里我们取右子树的最小结点作为替代结点
//					//去删除
//					// 这里尤其要注意右子树的根就是最小情况的情况
//					//的处理，对应图中删除8的情况
//					// 一定要把cur给replaceParent，否会报错。
//						Node* replaceParent = cur;
//						Node* replace = cur->_right;
//						while (replace->_left)
//						{
//							replaceParent = replace;
//							replace = replace->_left;
//						}
//
//						cur->_key = replace->_key;
//
//						if (replaceParent->_left == replace)
//							replaceParent->_left = replace->_right;
//						else
//							replaceParent->_right = replace->_right;
//
//						delete replace;
//					}
//
//					return true;
//				}
//			}
//
//			return false;
//		}
//
//		void InOrder()//中序遍历，遍历出来的一组数据是有序的
//		{
//			_InOrder(_root);//_root是私有的，在外部无法获取，因此这里我们可以套一层
//			cout << endl;
//		}
//	private:
//
//		void _InOrder(Node* root)//递归方式进行中序遍历
//		{
//			if (root == nullptr)
//			{
//				return;
//			}
//
//			_InOrder(root->_left);
//			cout << root->_key << " ";
//			_InOrder(root->_right);
//		}
//
//	private:
//		Node* _root = nullptr;
//	};
//}


//bool Insert(const K& key, const V& value)
//{
//	if (_root == nullptr)
//	{
//		_root = new Node(key, value);
//		return true;
//	}
//
//	Node* parent = nullptr;
//	Node* cur = _root;
//
//	while (cur)
//	{
//		if (cur->_key < key)
//		{
//			parent = cur;
//			cur = cur->_right;
//		}
//		else if (cur->_key > key)
//		{
//			parent = cur;
//			cur = cur->_left;
//		}
//		else
//		{
//			return false;
//		}
//	}
//
//	cur = new Node(key, value);
//	if (parent->_key < key)
//	{
//		parent->_right = cur;
//	}
//	else
//	{
//		parent->_left = cur;
//	}
//
//	return true;
//}
//
//
//template<class K>
//struct BSTNode
//{
//	K _key;
//	BSTNode<K>* _left;
//	BSTNode<K>* _right;
//	BSTNode(const K& key)
//		:_key(key)
//		, _left(nullptr)
//		, _right(nullptr)
//	{}
//};
//// Binary Search Tree
//template<class K>
//class BSTree
//{
//	typedef BSTNode<K> Node;
//public:
//	bool Insert(const K& key)
//	{
//		if (_root == nullptr)
//		{
//			_root = new Node(key);
//			return true;
//		}
//		Node* parent = nullptr;
//		Node* cur = _root;
//		while (cur)
//		{
//			if (cur->_key < key)
//			{
//				parent = cur;
//				cur = cur->_right;
//			}
//			else if (cur->_key > key)
//			{
//				parent = cur;
//				cur = cur->_left;
//			}
//			else
//			{
//				return false;
//			}
//		}
//		cur = new Node(key);
//		if (parent->_key < key)
//		{
//			parent->_right = cur;
//		}
//		else
//		{
//			parent->_left = cur;
//		}
//		return true;
//	}
//	bool Find(const K& key)
//	{
//		Node* cur = _root;
//		while (cur)
//		{
//			if (cur->_key < key)
//			{
//				cur = cur->_right;
//			}
//			else if (cur->_key > key)
//			{
//				cur = cur->_left;
//			}
//			else
//			{
//				return true;
//			}
//		}
//		return false;
//	}
//	bool Erase(const K& key)
//	{
//		Node* parent = nullptr;
//		Node* cur = _root;
//		while (cur)
//		{
//			if (cur->_key < key)
//			{
//				parent = cur;
//				cur = cur->_right;
//			}
//			else if (cur->_key > key)
//			{
//				parent = cur;
//				cur = cur->_left;
//			}
//			else
//			{
//				// 0-1个孩子的情况
//				// 删除情况1 2 3均可以直接删除，改变父亲对应孩子指针
//				//指向即可
//				if (cur->_left == nullptr)
//				{
//					if (parent == nullptr)
//					{
//						_root = cur->_right;
//					}
//					else
//					{
//						if (parent->_left == cur)
//							parent->_left = cur->_right;
//						else
//							parent->_right = cur->_right;
//					}
//					delete cur;
//					return true;
//				}
//				else if (cur->_right == nullptr)
//				{
//					if (parent == nullptr)
//					{
//						_root = cur->_left;
//					}
//					else
//					{
//						if (parent->_left == cur)
//							parent->_left = cur->_left;
//						else
//							parent->_right = cur->_left;
//					}
//					delete cur;
//					return true;
//				}
//				else
//				{
//					// 2个孩子的情况
//					// 删除情况4，替换法删除
//					// 假设这里我们取右子树的最小结点作为替代结点
//					//去删除
//						// 这里尤其要注意右子树的根就是最小情况的情况
//						//的处理，对应课件图中删除8的情况
//						// 一定要把cur给rightMinP，否会报错。
//					Node* rightMinP = cur;
//					Node* rightMin = cur->_right;
//					while (rightMin->_left)
//					{
//						rightMinP = rightMin;
//						rightMin = rightMin->_left;
//					}
//					cur->_key = rightMin->_key;
//					if (rightMinP->_left == rightMin)
//						rightMinP->_left = rightMin->_right;
//					else
//						rightMinP->_right = rightMin->_right;
//					delete rightMin;
//					return true;
//				}
//			}
//		}
//		return false;
//	}
//	void InOrder()
//	{
//		_InOrder(_root);
//		cout << endl;
//	}
//private:
//	void _InOrder(Node* root)
//	{
//		if (root == nullptr)
//		{
//			return;
//		}
//		_InOrder(root->_left);
//		cout << root->_key << " ";
//		_InOrder(root->_right);
//	}
//private:
//	Node* _root = nullptr;
//};
//int main()
//{
//	key::BSTree<int> t;
//	int a[] = { 8,3,1,10,1,6,4,7,14,13 };
//	for (auto e : a) {
//		t.Insert(e);
//	}
//	t.InOrder();
//	t.Insert(16);
//	t.Insert(3);
//
//	t.Erase(3);
//	t.InOrder();
//
//	for (auto e : a) {
//		t.Erase(e);
//		t.InOrder();
//	}
//	return 0;
//}
//
//int main() {
//	key_valude::BSTree<string, string> dict;
//	BSTree<string, string> copy = dict;
//	dict.Insert("left", "左边");
//	dict.Insert("right", "右边");
//	dict.Insert("insert", "插入");
//	dict.Insert("string", "字符串");
//
//	string str;
//	while (cin >> str) {
//		auto ret = dict.Find(str);
//		if (ret) {
//			cout << "->" << ret->_value << endl;
//		}
//		else {
//			cout << "无此单词，请重新输入" << endl;
//		}
//	}
//		return 0;
//}

//int main() {
//	string arr[] = { "苹果", "西瓜", "苹果", "西瓜", "苹果", "苹果", "西瓜",
//	"苹果", "香蕉", "苹果", "香蕉" };
//	key_valude::BSTree<string, int> countTree;
//
//	for (const auto& str : arr) {
//		auto ret = countTree.Find(str);
//		if (ret = nullptr)
//		{
//			conTree.Insert(str, 1);
//		}
//		else {
//			ret->_value++;
//		}
//		countTree.InOrder();
//	}
//
//	key_valude::BSTree<string, int>  copy = countTree;
//	copy.InOrder();
//
//	return 0;
//}