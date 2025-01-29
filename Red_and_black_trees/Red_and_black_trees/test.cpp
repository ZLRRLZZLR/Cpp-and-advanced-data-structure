


//pair<iterator, bool> insert(const value_type& val);
//size_type erase(const key_type& k);
//iterator find(const key_type& k);
//#include<unordered_set>
//#include<unordered_map>
//#include<set>
//#include<iostream>
//using namespace std;
//int test_set2()
//{
//	const size_t N = 1000000;
//	unordered_set<int> us;
//	set<int> s;
//	vector<int> v;
//	v.reserve(N);
//	srand(time(0));
//	for (size_t i = 0; i < N; ++i)
//	{
//		//v.push_back(rand()); // N比较大时，重复值比较多
//		v.push_back(rand() + i); // 重复值相对少
//		//v.push_back(i); // 没有重复，有序
//	}
//	// 21:15
//	size_t begin1 = clock();
//	for (auto e : v)
//	{
//		s.insert(e);
//	}
//	size_t end1 = clock();
//	cout << "set insert:" << end1 - begin1 << endl;
//	size_t begin2 = clock();
//	us.reserve(N);
//	for (auto e : v)
//	{
//		us.insert(e);
//	}
//	size_t end2 = clock();
//	cout << "unordered_set insert:" << end2 - begin2 << endl;
//	int m1 = 0;
//	size_t begin3 = clock();
//	for (auto e : v)
//	{
//		auto ret = s.find(e);
//		if (ret != s.end())
//		{
//			++m1;
//		}
//	}
//	size_t end3 = clock();
//	cout << "set find:" << end3 - begin3 << "->" << m1 << endl;
//	int m2 = 0;
//	size_t begin4 = clock();
//	for (auto e : v)
//	{
//		auto ret = us.find(e);
//		if (ret != us.end())
//		{
//			++m2;
//		}
//	}
//	size_t end4 = clock();
//	cout << "unorered_set find:" << end4 - begin4 << "->" << m2 << endl;
//	cout << "插入数据个数：" << s.size() << endl;
//	cout << "插入数据个数：" << us.size() << endl << endl;
//	size_t begin5 = clock();
//	for (auto e : v)
//	{
//		s.erase(e);
//	}
//	size_t end5 = clock();
//	cout << "set erase:" << end5 - begin5 << endl;
//	size_t begin6 = clock();
//	for (auto e : v)
//	{
//		us.erase(e);
//	}
//	size_t end6 = clock();
//	cout << "unordered_set erase:" << end6 - begin6 << endl << endl;
//	return 0;
//}
//int main()
//{
//	test_set2();
//	return 0;
//}


//template < class Key, //
//	unordered_set::key_type / value_type
//		class Hash = hash<Key>, // unordered_set::hasher
//		class Pred = equal_to<Key>, // unordered_set::key_equal
//		class Alloc = allocator<Key> // unordered_set::allocator_type
//		> class unordered_set;

//// Myset.h
//#include"RBTree.h"
//namespace bit
//{
//	template<class K>
//	class set
//	{
//		struct SetKeyOfT
//		{
//			const K& operator()(const K& key)
//			{
//				return key;
//			}
//		};
//	public:
//		typedef typename RBTree<K, const K, SetKeyOfT>::Iterator iterator;
//		typedef typename RBTree<K, const K, SetKeyOfT>::ConstIterator
//			const_iterator;
//		iterator begin()
//		{
//			return _t.Begin();
//		}
//		iterator end()
//		{
//			return _t.End();
//		}
//		const_iterator begin() const
//		{
//			return _t.Begin();
//		}
//		const_iterator end() const
//		{
//			return _t.End();
//		}
//		pair<iterator, bool> insert(const K& key)
//		{
//			return _t.Insert(key);
//		}
//		iterator find(const K& key)
//		{
//			return _t.Find(key);
//		}
//	private:
//		RBTree<K, const K, SetKeyOfT> _t;
//	};
//	void Print(const set<int>& s)
//	{
//		set<int>::const_iterator it = s.end();
//		while (it != s.begin())
//		{
//			--it;
//			// 不支持修改
//			//*it += 2;
//			cout << *it << " ";
//		}
//		cout << endl;
//	}
//	void test_set()
//	{
//		set<int> s;
//		int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
//		for (auto e : a)
//		{
//			s.insert(e);
//		}
//		for (auto e : s)
//		{
//			cout << e << " ";
//		}
//		cout << endl;
//		Print(s);
//	}
//}
//// Mymap.h
//#include"RBTree.h"
//namespace bit
//{
//	template<class K, class V>
//	class map
//	{
//		struct MapKeyOfT
//		{
//			const K& operator()(const pair<K, V>& kv)
//			{
//				return kv.first;
//			}
//		};
//	public:
//		typedef typename RBTree<K, pair<const K, V>, MapKeyOfT>::Iterator
//			iterator;
//		typedef typename RBTree<K, pair<const K, V>, MapKeyOfT>::ConstIterator
//			const_iterator;
//		iterator begin()
//		{
//			return _t.Begin();
//		}
//		iterator end()
//		{
//			return _t.End();
//		}
//		const_iterator begin() const
//		{
//			return _t.Begin();
//		}
//		const_iterator end() const
//		{
//			return _t.End();
//		}
//		pair<iterator, bool> insert(const pair<K, V>& kv)
//		{
//			return _t.Insert(kv);
//		}
//		iterator find(const K& key)
//		{
//			return _t.Find(key);
//		}
//		V& operator[](const K& key)
//		{
//			pair<iterator, bool> ret = insert(make_pair(key, V()));
//			return ret.first->second;
//		}
//	private:
//		RBTree<K, pair<const K, V>, MapKeyOfT> _t;
//	};
//	void test_map()
//	{
//		map<string, string> dict;
//		dict.insert({ "sort", "排序" });
//		dict.insert({ "left", "左边" });
//		dict.insert({ "right", "右边" });
//		dict["left"] = "左边，剩余";
//		dict["insert"] = "插入";
//		dict["string"];
//		map<string, string>::iterator it = dict.begin();
//		while (it != dict.end())
//		{
//			// 不能修改first，可以修改second
//			//it->first += 'x';
//			it->second += 'x';
//			cout << it->first << ":" << it->second << endl;
//			++it;
//		}
//		cout << endl;
//	}
//}
//// RBtree.h
//enum Colour
//{
//	RED,
//	BLACK
//};
//template<class T>
//struct RBTreeNode
//{
//	T _data;
//	RBTreeNode<T>* _left;
//	RBTreeNode<T>* _right;
//	RBTreeNode<T>* _parent;
//	Colour _col;
//	RBTreeNode(const T& data)
//		: _data(data)
//		, _left(nullptr)
//		, _right(nullptr)
//		, _parent(nullptr)
//	{
//	}
//};
//template<class T, class Ref, class Ptr>
//struct RBTreeIterator
//{
//	typedef RBTreeNode<T> Node;
//	typedef RBTreeIterator<T, Ref, Ptr> Self;
//	Node* _node;
//	Node* _root;
//	RBTreeIterator(Node* node, Node* root)
//		:_node(node)
//		, _root(root)
//	{
//	}
//	Self& operator++()
//	{
//		if (_node->_right)
//		{
//			// 右不为空，右子树最左结点就是中序第一个
//			Node* leftMost = _node->_right;
//			while (leftMost->_left)
//			{
//				leftMost = leftMost->_left;
//			}
//			_node = leftMost;
//		}
//		else
//		{
//			// 孩子是父亲左的那个祖先
//			Node* cur = _node;
//			Node* parent = cur->_parent;
//			while (parent && cur == parent->_right)
//			{
//				cur = parent;
//				parent = cur->_parent;
//			}
//			_node = parent;
//		}
//		return *this;
//	}
//	Self& operator--()
//	{
//		if (_node == nullptr) // end()
//		{
//			// --end()，特殊处理，走到中序最后一个结点，整棵树的最右结点
//			Node* rightMost = _root;
//			while (rightMost && rightMost->_right)
//			{
//				rightMost = rightMost->_right;
//			}
//			_node = rightMost;
//		}
//		else if (_node->_left)
//		{
//			// 左子树不为空，中序左子树最后一个
//			Node* rightMost = _node->_left;
//			while (rightMost->_right)
//			{
//				rightMost = rightMost->_right;
//			}
//			_node = rightMost;
//		}
//		else
//		{
//			// 孩子是父亲右的那个祖先
//			Node* cur = _node;
//			Node* parent = cur->_parent;
//			while (parent && cur == parent->_left)
//			{
//				cur = parent;
//				parent = cur->_parent;
//			}
//			_node = parent;
//		}
//		return *this;
//	}
//	Ref operator*()
//	{
//		return _node->_data;
//	}
//	Ptr operator->()
//	{
//		return &_node->_data;
//	}
//	bool operator!= (const Self& s) const
//	{
//		return _node != s._node;
//	}
//	bool operator== (const Self& s) const
//	{
//		return _node == s._node;
//	}
//};
//template<class K, class T, class KeyOfT>
//class RBTree
//{
//	typedef RBTreeNode<T> Node;
//public:
//	typedef RBTreeIterator<T, T&, T*> Iterator;
//	typedef RBTreeIterator<T, const T&, const T*> ConstIterator;
//	Iterator Begin()
//	{
//		Node* leftMost = _root;
//		while (leftMost && leftMost->_left)
//		{
//			leftMost = leftMost->_left;
//		}
//		return Iterator(leftMost, _root);
//	}
//	Iterator End()
//	{
//		return Iterator(nullptr, _root);
//	}
//	ConstIterator Begin() const
//	{
//		Node* leftMost = _root;
//		while (leftMost && leftMost->_left)
//		{
//			leftMost = leftMost->_left;
//		}
//		return ConstIterator(leftMost, _root);
//	}
//	ConstIterator End() const
//	{
//		return ConstIterator(nullptr, _root);
//	}
//	RBTree() = default;
//	~RBTree()
//	{
//		Destroy(_root);
//		_root = nullptr;
//	}
//	pair<Iterator, bool> Insert(const T & data)
//	{
//		if (_root == nullptr)
//		{
//			_root = new Node(data);
//			_root->_col = BLACK;
//			return make_pair(Iterator(_root, _root), true);
//		}
//		KeyOfT kot;
//		Node* parent = nullptr;
//		Node* cur = _root;
//		while (cur)
//		{
//			if (kot(cur->_data) < kot(data))
//			{
//				parent = cur;
//				cur = cur->_right;
//			}
//			else if (kot(cur->_data) > kot(data))
//			{
//				parent = cur;
//				cur = cur->_left;
//			}
//			else
//			{
//				return make_pair(Iterator(cur, _root), false);
//			}
//		}
//		cur = new Node(data);
//		Node* newnode = cur;
//		// 新增结点。颜色红色给红色
//		cur->_col = RED;
//		if (kot(parent->_data) < kot(data))
//		{
//			parent->_right = cur;
//		}
//		else
//		{
//			parent->_left = cur;
//		}
//		cur->_parent = parent;
//		while (parent && parent->_col == RED)
//		{
//			Node* grandfather = parent->_parent;
//			//		g
//			// p		u
//			if (parent == grandfather->_left)
//			{
//				Node* uncle = grandfather->_right;
//				if (uncle && uncle->_col == RED)
//				{
//					// u存在且为红 -》变色再继续往上处理
//					parent->_col = uncle->_col = BLACK;
//					grandfather->_col = RED;
//					cur = grandfather;
//					parent = cur->_parent;
//				}
//				else
//				{
//					// u存在且为黑或不存在 -》旋转+变色
//					if (cur == parent->_left)
//					{
//						//		g
//						// p		u
//						//c
//						//单旋
//						RotateR(grandfather);
//						parent->_col = BLACK;
//						grandfather->_col = RED;
//					}
//					else
//					{
//						//		g
//						// p		u
//						//		c
//						//双旋
//						RotateL(parent);
//						RotateR(grandfather);
//						cur->_col = BLACK;
//						grandfather->_col = RED;
//					}
//					break;
//				}
//			}
//			else
//			{
//				//		g
//				// u		p
//				Node* uncle = grandfather->_left;
//				// 叔叔存在且为红，-》变色即可
//				if (uncle && uncle->_col == RED)
//				{
//					parent->_col = uncle->_col = BLACK;
//					grandfather->_col = RED;
//					// 继续往上处理
//					cur = grandfather;
//					parent = cur->_parent;
//				}
//				else // 叔叔不存在，或者存在且为黑
//				{
//					// 情况二：叔叔不存在或者存在且为黑
//					// 旋转+变色
//					//		g
//					// u		p
//					//				c
//					if (cur == parent->_right)
//					{
//						RotateL(grandfather);
//						parent->_col = BLACK;
//						grandfather->_col = RED;
//					}
//					else
//					{
//						// g
//						// u p
//						// c
//						RotateR(parent);
//						RotateL(grandfather);
//						cur->_col = BLACK;
//						grandfather->_col = RED;
//					}
//					break;
//				}
//			}
//		}
//		_root->_col = BLACK;
//		return make_pair(Iterator(newnode, _root), true);
//}
//Iterator Find(const K& key)
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
//			return Iterator(cur, _root);
//		}
//	}
//	return End();
//}
//private:
//	void RotateL(Node* parent)
//	{
//		Node* subR = parent->_right;
//		Node* subRL = subR->_left;
//		parent->_right = subRL;
//		if (subRL)
//			subRL->_parent = parent;
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
//	}
//	void RotateR(Node* parent)
//	{
//		Node* subL = parent->_left;
//		Node* subLR = subL->_right;
//		parent->_left = subLR;
//		if (subLR)
//			subLR->_parent = parent;
//		Node* parentParent = parent->_parent;
//		subL->_right = parent;
//		parent->_parent = subL;
//		if (parentParent == nullptr)
//		{
//			_root = subL;
//			subL->_parent = nullptr;
//		}
//		else
//		{
//			if (parent == parentParent->_left)
//			{
//				parentParent->_left = subL;
//			}
//			else
//			{
//				parentParent->_right = subL;
//			}
//			subL->_parent = parentParent;
//		}
//	}
//	void Destroy(Node* root)
//	{
//		if (root == nullptr)
//			return;
//		Destroy(root->_left);
//		Destroy(root->_right);
//		delete root;
//	}
//private:
//	Node* _root = nullptr;
//};


//struct __rb_tree_base_iterator
//{
//	typedef __rb_tree_node_base::base_ptr base_ptr;
//	base_ptr node;
//	void increment()
//	{
//		if (node->right != 0) {
//			node = node->right;
//			while (node->left != 0)
//				node = node->left;
//		}
//		else {
//			base_ptr y = node->parent;
//			while (node == y->right) {
//				node = y;
//				y = y->parent;
//			}
//			if (node->right != y)
//				node = y;
//		}
//	}
//	void decrement()
//	{
//		if (node->color == __rb_tree_red &&
//			node->parent->parent == node)
//			node = node->right;
//		else if (node->left != 0) {
//			base_ptr y = node->left;
//			while (y->right != 0)
//				y = y->right;
//			node = y;
//		}
//		else {
//			base_ptr y = node->parent;
//			while (node == y->left) {
//				node = y;
//				y = y->parent;
//			}
//			node = y;
//		}
//	}
//};
//template <class Value, class Ref, class Ptr>
//struct __rb_tree_iterator : public __rb_tree_base_iterator
//{
//	typedef Value value_type;
//	typedef Ref reference;
//	typedef Ptr pointer;
//	typedef __rb_tree_iterator<Value, Value&, Value*> iterator;
//	__rb_tree_iterator() {}
//	__rb_tree_iterator(link_type x) { node = x; }
//	__rb_tree_iterator(const iterator& it) { node = it.node; }
//	reference operator*() const { return link_type(node)->value_field; }
//#ifndef __SGI_STL_NO_ARROW_OPERATOR
//	pointer operator->() const { return &(operator*()); }
//#endif /* __SGI_STL_NO_ARROW_OPERATOR */
//	self& operator++() { increment(); return *this; }
//	self& operator--() { decrement(); return *this; }
//	inline bool operator==(const __rb_tree_base_iterator& x,
//		const __rb_tree_base_iterator& y) {
//		return x.node == y.node;
//	}
//	inline bool operator!=(const __rb_tree_base_iterator& x,
//		const __rb_tree_base_iterator& y) {
//		return x.node != y.node;
//	}

//// 源码中pair支持的<重载实现
//template <class T1, class T2>
//bool operator< (const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
//{
//	return lhs.first < rhs.first || (!(rhs.first < lhs.first) &&
//		lhs.second < rhs.second);
//}
//// Mymap.h
//namespace bit
//{
//	template<class K, class V>
//	class map
//	{
//		struct MapKeyOfT
//		{
//			const K& operator()(const pair<K, V>& kv)
//			{
//				return kv.first;
//			}
//		};
//	public:
//		bool insert(const pair<K, V>& kv)
//		{
//			return _t.Insert(kv);
//		}
//	private:
//		RBTree<K, pair<K, V>, MapKeyOfT> _t;
//	};
//}
//// Myset.h
//namespace bit
//{
//	template<class K>
//	class set
//	{
//		struct SetKeyOfT
//		{
//			const K& operator()(const K& key)
//			{
//				return key;
//			}
//		};
//	public:
//		bool insert(const K& key)
//		{
//			return _t.Insert(key);
//		}
//	private:
//		RBTree<K, K, SetKeyOfT> _t;
//	};
//}
//// RBTree.h
//enum Colour
//{
//	RED,
//	BLACK
//};
//template<class T>
//struct RBTreeNode
//{
//	T _data;
//	RBTreeNode<T>* _left;
//	RBTreeNode<T>* _right;
//	RBTreeNode<T>* _parent;
//	Colour _col;
//	RBTreeNode(const T& data)
//		: _data(data)
//		, _left(nullptr)
//		, _right(nullptr)
//		, _parent(nullptr)
//	{
//	}
//};
//// 实现步骤：
//// 1、实现红黑树
//// 2、封装map和set框架，解决KeyOfT
//// 3、iterator
//// 4、const_iterator
//// 5、key不支持修改的问题
//// 6、operator[]
//template<class K, class T, class KeyOfT>
//class RBTree
//{
//private:
//	typedef RBTreeNode<T> Node;
//	Node* _root = nullptr;
//public:
//	bool Insert(const T& data)
//	{
//		if (_root == nullptr)
//		{
//			_root = new Node(data);
//			_root->_col = BLACK;
//			return true;
//		}
//		KeyOfT kot;
//		Node* parent = nullptr;
//		Node* cur = _root;
//		while (cur)
//		{
//			if (kot(cur->_data) < kot(data))
//			{
//				parent = cur;
//				cur = cur->_right;
//			}
//			else if (kot(cur->_data) > kot(data))
//			{
//				parent = cur;
//				cur = cur->_left;
//			}
//			else
//			{
//				return false;
//			}
//		}
//		cur = new Node(data);
//		Node* newnode = cur;
//		// 新增结点。颜色给红色
//		cur->_col = RED;
//		if (kot(parent->_data) < kot(data))
//		{
//			parent->_right = cur;
//		}
//		else
//		{
//			parent->_left = cur;
//		}
//		cur->_parent = parent;
//		//...
//		return true;
//	}
//}

//// set
//#ifndef __SGI_STL_INTERNAL_TREE_H
//#include <stl_tree.h>
//#endif
//#include <stl_set.h>
//#include <stl_multiset.h>
//// map
//#ifndef __SGI_STL_INTERNAL_TREE_H
//#include <stl_tree.h>
//#endif
//#include <stl_map.h>
//#include <stl_multimap.h>
//// stl_set.h
//template <class Key, class Compare = less<Key>, class Alloc = alloc>
//class set {
//public:
//	// typedefs:
//	typedef Key key_type;
//	typedef Key value_type;
//private:
//	typedef rb_tree<key_type, value_type,
//		identity<value_type>, key_compare, Alloc> rep_type;
//	rep_type t; // red-black tree representing set
//};
//// stl_map.h
//template <class Key, class T, class Compare = less<Key>, class Alloc = alloc>
//class map {
//public:
//	// typedefs:
//	typedef Key key_type;
//	typedef T mapped_type;
//	typedef pair<const Key, T> value_type;
//private:
//	typedef rb_tree<key_type, value_type,
//		select1st<value_type>, key_compare, Alloc> rep_type;
//	rep_type t; // red-black tree representing map
//};
//// stl_tree.h
//struct __rb_tree_node_base
//{
//	typedef __rb_tree_color_type color_type;
//	typedef __rb_tree_node_base* base_ptr;
//	color_type color;
//	base_ptr parent;
//	base_ptr left;
//	base_ptr right;
//};
//// stl_tree.h
//template <class Key, class Value, class KeyOfValue, class Compare, class Alloc
//	= alloc>
//class rb_tree {
//protected:
//	typedef void* void_pointer;
//	typedef __rb_tree_node_base* base_ptr;
//	typedef __rb_tree_node<Value> rb_tree_node;
//	typedef rb_tree_node* link_type;
//	typedef Key key_type;
//	typedef Value value_type;
//public:
//	// insert用的是第二个模板参数左形参
//	pair<iterator, bool> insert_unique(const value_type& x);
//	// erase和find用第一个模板参数做形参
//	size_type erase(const key_type& x);
//	iterator find(const key_type& x);
//protected:
//	size_type node_count; // keeps track of size of tree
//	link_type header;
//};
//template <class Value>
//struct __rb_tree_node : public __rb_tree_node_base
//{
//	typedef __rb_tree_node<Value>* link_type;
//	Value value_field;
//};

//bool Check(Node* root, int blackNum, const int refNum)
//{
//	if (root == nullptr)
//	{
//		// 前序遍历走到空时，意味着一条路径走完了
//		//cout << blackNum << endl;
//		if (refNum != blackNum)
//		{
//			cout << "存在黑色结点的数量不相等的路径" << endl;
//			return false;
//		}
//		return true;
//	}
//	// 检查孩子不太方便，因为孩子有两个，且不一定存在，反过来检查父亲就方便多了
//	if (root->_col == RED && root->_parent->_col == RED)
//	{
//		cout << root->_kv.first << "存在连续的红色结点" << endl;
//		return false;
//	}
//	if (root->_col == BLACK)
//	{
//		blackNum++;
//	}
//	return Check(root->_left, blackNum, refNum)
//		&& Check(root->_right, blackNum, refNum);
//}
//bool IsBalance()
//{
//	if (_root == nullptr)
//		return true;
//	if (_root->_col == RED)
//		return false;
//	// 参考值
//	int refNum = 0;
//	Node* cur = _root;
//	while (cur)
//	{
//		if (cur->_col == BLACK)
//		{
//			++refNum;
//		}
//		cur = cur->_left;
//	}
//	return Check(_root, 0, refNum);
//}

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
//	return nullptr;
//}

//// 旋转代码的实现跟AVL树是一样的，只是不需要更新平衡因子
//bool Insert(const pair<K, V>& kv)
//{
//	if (_root == nullptr)
//	{
//		_root = new Node(kv);
//		_root->_col = BLACK;
//		return true;
//	}
//	Node* parent = nullptr;
//	Node* cur = _root;
//	while (cur)
//	{
//		if (cur->_kv.first < kv.first)
//		{
//			parent = cur;
//			cur = cur->_right;
//		}
//		else if (cur->_kv.first > kv.first)
//		{
//			parent = cur;
//			cur = cur->_left;
//		}
//		else
//		{
//			return false;
//		}
//	}
//	cur = new Node(kv);
//	// 新增结点。颜色红色给红色
//	cur->_col = RED;
//	if (parent->_kv.first < kv.first)
//	{
//		parent->_right = cur;
//	}
//	else
//	{
//		parent->_left = cur;
//	}
//	cur->_parent = parent;
//	while (parent && parent->_col == RED)
//	{
//		Node* grandfather = parent->_parent;
//		// g
//		// p u
//		if (parent == grandfather->_left)
//		{
//			Node* uncle = grandfather->_right;
//			if (uncle && uncle->_col == RED)
//			{
//				// u存在且为红 -》变色再继续往上处理
//				parent->_col = uncle->_col = BLACK;
//				grandfather->_col = RED;
//				cur = grandfather;
//				parent = cur->_parent;
//			}
//			else
//			{
//				// u存在且为黑或不存在 -》旋转+变色
//				if (cur == parent->_left)
//				{
//					// g
//					// p u
//					//c
//					//单旋
//					RotateR(grandfather);
//					parent->_col = BLACK;
//					grandfather->_col = RED;
//				}
//				else
//				{
//					// g
//					// p u
//					// c
//					//双旋
//					RotateL(parent);
//					RotateR(grandfather);
//					cur->_col = BLACK;
//					grandfather->_col = RED;
//				}
//				break;
//			}
//		}
//		else
//		{
//			// g
//			// u p
//			Node* uncle = grandfather->_left;
//			// 叔叔存在且为红，-》变色即可
//			if (uncle && uncle->_col == RED)
//			{
//				parent->_col = uncle->_col = BLACK;
//				grandfather->_col = RED;
//				// 继续往上处理
//				cur = grandfather;
//				parent = cur->_parent;
//			}
//			else // 叔叔不存在，或者存在且为黑
//			{
//				// 情况二：叔叔不存在或者存在且为黑
//				// 旋转+变色
//				// g
//				// u p
//				// c
//				if (cur == parent->_right)
//				{
//					RotateL(grandfather);
//					parent->_col = BLACK;
//					grandfather->_col = RED;
//				}
//				else
//				{
//					// g
//					// u p
//					// c
//					RotateR(parent);
//					RotateL(grandfather);
//					cur->_col = BLACK;
//					grandfather->_col = RED;
//				}
//				break;
//			}
//		}
//	}
//	_root->_col = BLACK;
//	return true;
//}


//// 枚举值表示颜色
//enum Colour
//{
//	RED,
//	BLACK
//};
//// 这里我们默认按key/value结构实现
//template<class K, class V>
//struct RBTreeNode
//{
//	// 这里更新控制平衡也要加入parent指针
//	pair<K, V> _kv;
//	RBTreeNode<K, V>* _left;
//	RBTreeNode<K, V>* _right;
//	RBTreeNode<K, V>* _parent;
//	Colour _col;
//	RBTreeNode(const pair<K, V>& kv)
//		:_kv(kv)
//		, _left(nullptr)
//		, _right(nullptr)
//		, _parent(nullptr)
//	{
//	}
//};
//template<class K, class V>
//class RBTree
//{
//	typedef RBTreeNode<K, V> Node;
//public:
//private:
//	Node* _root = nullptr;
//};


//enum Colour {
//	RED,
//	BLACK
//};
//
//template<class K, class V>
//struct RBTree {
//	pair<k, V> _kv;
//	RBTree<k, V>* _left;
//	RBTree<k, V>* _right;
//	RBTree<k, V>* _parent;
//	Colour _col;
//
//	RBTreeNode(const pair<k,V>&kv)
//		:_kv(kv)
//		,_left(nullptr)
//		,_right(nullptr)
//		,_parent(nullptr)
//	{}
//};
//
//template<class k,class V>
//class RBTree {
//	typedef RBTreeNode<K, V> Node;
//public:
//	bool Insert(const pair<k, V>& kv) {
//		if (_root == nullptr) {
//			_root = new Node(kv);
//			_root->_col = BLACK;
//
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
//		cur->_col = RED;
//		if (parent->kv._first < kv.first) {
//			parent->_right = cur;
//		}
//		else {
//			parent->left = cur;
//		}
//
//		cur->_parent = parnet;
//
//		while (parnet && parnet->_col == RED) {
//			Node* grandfather = parent->_parent;
//			if (parent == grandfather->_left) {
//				Node* uncle = grandfather->_right;
//				if (uncle && uncle->_col == RED) {
//					parent->_col = uncle->_col = BLACK;
//					grandfather->_col = RED;
//
//					cur = grandfather;
//					parent = cur->_parent;
//				}
//				else {
//					if (cur == parent->_left) {
//						RotateR(grandfather);
//						parent->_col = BLACK;
//						grandfather->_col = RED;
//					}
//
//					else {
//						RotateL(parent);
//						RotateR(grandfather);
//						cur->_col = BLACK;
//						grandfather->_col = RED;
//					}
//
//					break;
//				}
//			}
//			else{
//				Node * uncle = grandfather->_left;
//
//				if (uncle && uncle->_col == RED) {
//					parent->_col = uncle->_col = BLACK;
//					grandfather->_col = RED;
//
//					cur = grandfather;
//					parent = cur->_parent;
//				}
//				else {
//					if (cur == parent->_right)
//					{
//						RotateL(grandfather);
//						parent->_col = BLACK;
//						grandfather->_col = RED;
//					}
//					else
//					{
//						RotateR(parent);
//						RotateL(grandfather);
//						cur->_col = BLACK;
//						grandfather->_col = RED;
//					}
//
//					braek;
//				}
//			}
//		}
//		_root->_col = BLACK;
//		return true;
//	}
//	void RotateR(Node* parent)
//	{
//		Node* subL = parent->_left;
//		Node* subLR = subL->_right;
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
//		if (parent == _root)
//		{
//			_root = subL;
//			subL->_parent = nullptr;
//		}
//		else
//		{
//			if (pParent->_left == parent)
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
//	bool IsBalance()
//	{
//		if (_root == nullptr)
//			return true;
//
//		if (_root->_col == RED)
//			return false;
//
//		// 参考值
//		int refNum = 0;
//		Node* cur = _root;
//		while (cur)
//		{
//			if (cur->_col == BLACK)
//			{
//				++refNum;
//			}
//			cur = cur->_left;
//		}
//
//		return Check(_root, 0, refNum);
//	}
//
//private:
//	bool Check(NOde* root, int blackNum, const int refNum) {
//		if (root == nullptr) {
//			if (refNum != blackNum) {
//				cout << "存在黑色结点的数量不相等的路径" << endl;
//				return false;
//			}
//			return true;
//		}
//
//		if (root->_col == RED && root->_parent->_col == RED) {
//			cout << root->_kv.first << "存在连续的红色节点" << endl;
//			return false;
//		}
//
//		if (root->_col == BLACK) {
//			blackNum++;
//		}
//		return Check(root->_left, blackNum, refNum)
//			&& Check(root->_right, blackNum, refNum);
//	}
//
//	void _InOrder(Node* root) {
//		if (root == nullptr) {
//			return;
//		}
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
//
//	int _Size(Node* root)
//	{
//		if (root == nullptr)
//			return 0;
//
//		return _Size(root->_left) + _Size(root->_right) + 1;
//	}
//
//private:
//	Node* _root = nullptr;
//};