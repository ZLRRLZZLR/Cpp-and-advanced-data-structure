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

		BSTree(const BSTree& t)


		BSTree& operator=(BSTree tmp)


		~BSTree()


		bool Insert(const K& key, const V& value)

		Node* Find(const K& key)


		bool Erase(const K& key)


		void InOrder()

	private:
		void _InOrder(Node* root)


		void Destroy(Node* root)


		Node* Copy(Node* root)
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

		string str;
		while (cin >> str)
		{
			auto ret = dict.Find(str);
			if (ret)
			{
				cout << str << ":" << ret->_value << endl;
			}
			else
			{
				cout << "单词拼写错误" << endl;
			}
		}

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
	//BSTree<string, string>().TestBSTree();
	return 0;
}