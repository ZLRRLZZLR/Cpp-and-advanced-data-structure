#define _CRT_SECURE_NO_WARNINGS 1


//int _Height(Node* root)
//{
//	if (root == nullptr)
//		return 0;
//	int leftHeight = _Height(root->_left);
//	int rightHeight = _Height(root->_right);
//	return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
//}
//bool _IsBalanceTree(Node* root)
//{
//	// 空树也是AVL树
//	if (nullptr == root)
//		return true;
//	// 计算pRoot结点的平衡因子：即pRoot左右子树的高度差
//	int leftHeight = _Height(root->_left);
//	int rightHeight = _Height(root->_right);
//	int diff = rightHeight - leftHeight;
//	// 如果计算出的平衡因子与pRoot的平衡因子不相等，或者
//// pRoot平衡因子的绝对值超过1，则一定不是AVL树
//	if (abs(diff) >= 2)
//	{
//		cout << root->_kv.first << "高度差异常" << endl;
//		return false;
//	}
//	if (root->_bf != diff)
//	{
//		cout << root->_kv.first << "平衡因子异常" << endl;
//		return false;
//	}
//	// pRoot的左和右如果都是AVL树，则该树一定是AVL树
//	return _IsBalanceTree(root->_left) && _IsBalanceTree(root->_right);
//}
//// 测试代码
//void TestAVLTree1()
//{
//	AVLTree<int, int> t;
//	// 常规的测试用例
//	//int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
//	// 特殊的带有双旋场景的测试用例
//	int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
//	for (auto e : a)
//	{
//		t.Insert({ e, e });
//	}
//	t.InOrder();
//	cout << t.IsBalanceTree() << endl;
//}
//// 插入一堆随机值，测试平衡，顺便测试一下高度和性能等
//void TestAVLTree2()
//{
//	const int N = 100000;
//	vector<int> v;
//	v.reserve(N);
//	srand(time(0));
//	for (size_t i = 0; i < N; i++)
//	{
//		v.push_back(rand() + i);
//	}
//	size_t begin2 = clock();
//	AVLTree<int, int> t;
//	for (auto e : v)
//	{
//		t.Insert(make_pair(e, e));
//	}
//	size_t end2 = clock();
//	cout << "Insert:" << end2 - begin2 << endl;
//	cout << t.IsBalanceTree() << endl;
//	cout << "Height:" << t.Height() << endl;
//	cout << "Size:" << t.Size() << endl;
//	size_t begin1 = clock();
//	// 确定在的值
//	/*for (auto e : v)
//	{
//	t.Find(e);
//	}*/
//	// 随机值
//	for (size_t i = 0; i < N; i++)
//	{
//		t.Find((rand() + i));
//	}
//	size_t end1 = clock();
//	cout << "Find:" << end1 - begin1 << endl;
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


//void RotateLR(Node* parent)
//{
//	Node* subL = parent->_left;
//	Node* subLR = subL->_right;
//	int bf = subLR->_bf;
//	RotateL(parent->_left);
//	RotateR(parent);
//	if (bf == 0)
//	{
//		subL->_bf = 0;
//		subLR->_bf = 0;
//		parent->_bf = 0;
//	}
//	else if (bf == -1)
//	{
//		subL->_bf = 0;
//		subLR->_bf = 0;
//		parent->_bf = 1;
//	}
//	else if (bf == 1)
//	{
//		subL->_bf = -1;
//		subLR->_bf = 0;
//		parent->_bf = 0;
//	}
//	else
//	{
//		assert(false);
//	}
//}

//void RotateL(Node* parent)
//{
//	Node* subR = parent->_right;
//	Node* subRL = subR->_left;
//	parent->_right = subRL;
//	if (subRL)
//		subRL->_parent = parent;
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
//	parent->_bf = subR->_bf = 0;
//}

//void RotateR(Node* parent)
//{
//	Node* subL = parent->_left;
//	Node* subLR = subL->_right;
//	// 需要注意除了要修改孩子指针指向，还是修改父亲
//	parent->_left = subLR;
//	if (subLR)
//		subLR->_parent = parent;
//	Node* parentParent = parent->_parent;
//	subL->_right = parent;
//	parent->_parent = subL;
//	// parent有可能是整棵树的根，也可能是局部的子树
//	// 如果是整棵树的根，要修改_root
//	// 如果是局部的指针要跟上一层链接
//	if (parentParent == nullptr)
//	{
//		_root = subL;
//		subL->_parent = nullptr;
//	}
//	else
//	{
//		if (parent == parentParent->_left)
//		{
//			parentParent->_left = subL;
//		}
//		else
//		{
//			parentParent->_right = subL;
//		}
//		subL->_parent = parentParent;
//	}
//	parent->_bf = subL->_bf = 0;
//}

//bool Insert(const pair<K, V>& kv)
//{
//	if (_root == nullptr)
//	{
//		_root = new Node(kv);
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
//	if (parent->_kv.first < kv.first)
//	{
//		parent->_right = cur;
//	}
//	else
//	{
//		parent->_left = cur;
//	}
//	cur->_parent = parent;
//	// 更新平衡因子
//	while (parent)
//	{
//		// 更新平衡因子
//		if (cur == parent->_left)
//			parent->_bf--;
//		else
//			parent->_bf++;
//		if (parent->_bf == 0)
//		{
//			// 更新结束
//			break;
//		}
//		else if (parent->_bf == 1 || parent->_bf == -1)
//		{
//			// 继续往上更新
//			cur = parent;
//			parent = parent->_parent;
//		}
//		else if (parent->_bf == 2 || parent->_bf == -2)
//		{
//			// 不平衡了，旋转处理
//			break;
//		}
//		else
//		{
//			assert(false);
//		}
//	}
//	return true;
//}
//template<class K, class V>
//struct AVLTreeNode
//{
//	// 需要parent指针，后续更新平衡因子可以看到
//	pair<K, V> _kv;
//	AVLTreeNode<K, V>* _left;
//	AVLTreeNode<K, V>* _right;
//	AVLTreeNode<K, V>* _parent;
//	int _bf; // balance factor
//	AVLTreeNode(const pair<K, V>& kv)
//		:_kv(kv)
//		, _left(nullptr)
//		, _right(nullptr)
//		, _parent(nullptr)
//		, _bf(0)
//	{}
//};
//template<class K, class V>
//class AVLTree
//{
//	typedef AVLTreeNode<K, V> Node;
//public:
//	//...
//private:
//	Node* _root = nullptr;
//};