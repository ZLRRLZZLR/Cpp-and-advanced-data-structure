#include<iostream>
#include<string>
using namespace std;
		

namespace key_value
{
	template<class K, class V>
	struct BSTNode
	{
		K _key;
		V _value;

		BSTNode<K, V>* _left;
		BSTNode<K, V>* _right;

		BSTNode(const K& key, const V& value)
			:_key(key)
			,_value(value)
			,_left(nullptr)
			,_right(nullptr)
		{}
	};

	// Binary Search Tree
	// Key/value
	template<class K, class V>
	class BSTree
	{
		using Node = BSTNode<K, V>;
	public:
		// 强制生成构造
		BSTree() = default;

		BSTree(const BSTree& t) {
			_root = Copy(t._root);
		}


		BSTree& operator=(BSTree tmp) {
			swap(_root, tmp._root);
			return *this;
		}

		~BSTree() {
			Destroy(_root);
			_root = nullptr;
		}


		bool Insert(const K& key, const V& value) {
			if (_root == nullptr) {
				_root = new Node(key, value);
				return true;
			}

			Node* parent = _root;
			Node* cur = _root;

			while (cur) {
				parent = cur;
				if (cur->_key < key) {
					cur = cur->_right;
				}
				else if (cur->_key > key) {
					cur = cur->_left;
				}
				else {
					return false;
				}
			}

			cur = new Node(key, value);
			if (parent->_key < key) {
				parent->_right = cur;
			}
			else {
				parent->_left = cur;
			}
			return true;
		}

		Node* Find(const K& key) {
			Node* cur = _root;
			while (cur) {
				if (cur->_key < key) {
					cur = cur->_right;
				}
				else if (cur->_key > key) {
					cur = cur->_left;
				}
				else {
					return cur;
				}
			}
			return nullptr;
		}

		bool Erase(const K& key) {
			Node* parent = _root;
			Node* cur = _root;

			while (cur) {
				parent = cur;
				if (cur->_key < key) {
					cur = cur->_right;
				}
				else if (cur->_key > key) {
					cur = cur->_left;
				}
				else {
					if (cur->_left == nullptr)
					{
						if (cur == _root) {
							_root = cur->_right;
						}
						else {
							if (parent->_left == cur) {
								parent->_left = cur->_right;
							}
							else {
								parent->_right = cur->_right;
							}
							delete cur;
						}
					}
					else if (cur->_right == nullptr) {
						if (cur == _root) {
							_root = cur->_left;
						}
						else {
							if (parent->_left == cur) {
								parent->_left = cur->_left;
							}
							else {
								parent->_right = cur->_left;
							}
							delete cur;
						}
					}
					else {
						Node* replaceParent = cur;
						Node* replace = cur->_left;
						while (replace->_right) {
							replaceParent = replace;
							replace = replace->_right;
						}
						cur->_key = replace->_key;
						cur->_value = replace->_value;

						if (replace->_right == replace) {
							replace->_right = replace->_left;
						}
						delete replace;
					}
					return true;
				}
			}
			return false;
		}


		void InOrder() {
			_InOrder(_root);
		}

	private:
		void _InOrder(Node* root) {
			if (root == nullptr)
				return;

			_InOrder(root->_left);
			cout << root->_key << ':' << root->_value << endl;
			_InOrder(root->_right);
		}


		void Destroy(Node* root) {
			if (root == nullptr)
				return;

			Destroy(root->_left);
			Destroy(root->_right);
			delete root;
			root = nullptr;
		}


		Node* Copy(Node* root) {
			if (root == nullptr)
				return nullptr;

			Node* root = new Node(root->_key, root->_value);
			root->left = Copy(root->_left);
			root->right = Copy(root->_right);

			return root;
		}
	private:
		Node* _root = nullptr;
	};
	void TestBSTree()
	{
		BSTree<string, string> dict;
		dict.Insert("insert", "插入");
		dict.Insert("erase", "删除");
		dict.Insert("left", "左边");
		dict.Insert("string", "字符串");

		//string str;
		//while (cin >> str)
		//{
		//	auto ret = dict.Find(str);
		//	if (ret)
		//	{
		//		cout << str << ":" << ret->_value << endl;
		//	}
		//	else
		//	{
		//		cout << "单词拼写错误" << endl;
		//	}
		//}

		string strs[] = { "苹果", "西瓜", "苹果", "樱桃", "苹果", "樱桃", "苹果", "樱桃", "苹果" };
		// 统计水果出现的次
		BSTree<string, int> countTree;
		for (auto str : strs)
		{
			auto ret = countTree.Find(str);
			if (ret == NULL)
			{
				countTree.Insert(str, 1);
			}
			else
			{
				ret->_value++;
			}
		}
		countTree.InOrder();
	}
}

int main()
{
	key_value::TestBSTree();
	return 0;
}