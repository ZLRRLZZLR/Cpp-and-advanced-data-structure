
//#include<iostream>
//#include<string>
//#include<vector>
//#include<list>
//using namespace std;
//int main()
//{
//	int a[10];
//	int* ptr = nullptr;
//	cout << typeid(10).name() << endl;
//	cout << typeid(a).name() << endl;
//	cout << typeid(ptr).name() << endl;
//	cout << typeid(string).name() << endl;
//	cout << typeid(string::iterator).name() << endl;
//	cout << typeid(vector<int>).name() << endl;
//	cout << typeid(vector<int>::iterator).name() << endl;
//	return 0;
//}
//// vs2019下的运行结果
//int
//int[10]
//int*
//class std::basic_string<char, struct std::char_traits<char>, class
//	std::allocator<char> >
//	class std::_String_iterator<class std::_String_val<struct
//	std::_Simple_types<char> > >
//	class std::vector<int, class std::allocator<int> >
//	class std::_Vector_iterator<class std::_Vector_val<struct
//	std::_Simple_types<int> > >
//	// gcc 9.4下运行结果
//	i
//	A10_i
//	Pi
//	NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
//	N9__gnu_cxx17__normal_iteratorIPcNSt7__cxx1112basic_stringIcSt11char_traitsIcES
//	aIcEEEEE
//	St6vectorIiSaIiEE
//	N9__gnu_cxx17__normal_iteratorIPiSt6vectorIiSaIiEEEE


//class A
//{
//public:
//	virtual void f() {}
//	int _a = 1;
//};
//class B : public A
//{
//public:
//	int _b = 2;
//};
//void fun1(A* pa)
//{
//	// 指向父类转换时有风险的，后续访问存在越界访问的风险
//	// 指向子类转换时安全
//	B* pb1 = (B*)pa;
//	cout << "pb1:" << pb1 << endl;
//	cout << pb1->_a << endl;
//	cout << pb1->_b << endl;
//	pb1->_a++;
//	pb1->_b++;
//	cout << pb1->_a << endl;
//	cout << pb1->_b << endl;
//}
//void fun2(A* pa)
//{
//	// dynamic_cast会先检查是否能转换成功(指向子类对象)，能成功则转换，
//	// (指向父类对象)转换失败则返回nullptr
//	B* pb1 = dynamic_cast<B*>(pa);
//	if (pb1)
//	{
//		cout << "pb1:" << pb1 << endl;
//		cout << pb1->_a << endl;
//		cout << pb1->_b << endl;
//		pb1->_a++;
//		pb1->_b++;
//		cout << pb1->_a << endl;
//		cout << pb1->_b << endl;
//	}
//	else
//	{
//		cout << "转换失败" << endl;
//	}
//}
//void fun3(A& pa)
//{
//	// 转换失败，则抛出bad_cast异常
//	try {
//		B& pb1 = dynamic_cast<B&>(pa);
//		cout << "转换成功" << endl;
//	}
//	catch (const exception& e)
//	{
//		cout << e.what() << endl;
//	}
//}
//int main()
//{
//	A a;
//	B b;
//	//fun1(&a);
//	//fun1(&b);
//	fun2(&a);
//	fun2(&b);
//	fun3(a);
//	fun3(b);
//	return 0;
//}

//int main()
//{
//	// 对应隐式类型转换 -- 数据的解释意义没有改变
//	double d = 12.34;
//	int a = static_cast<int>(d);
//	cout << a << endl;
//	int&& ref = static_cast<int&&>(a);
//	// 对应强制类型转换 -- 数据的解释意义已经发生改变
//	int* p1 = reinterpret_cast<int*>(a);
//	// 对应强制类型转换中有风险的去掉const属性
//	// 所以要注意加volatile
//	volatile const int b = 0;
//	int* p2 = const_cast<int*>(&b);
//	*p2 = 1;
//	cout << b << endl;
//	cout << *p2 << endl;
//	return 0;
//}


//void insert(size_t pos, char ch)
//{
//	// 这里当pos==0时，就会引发由于隐式类型转换
//	// end跟pos比较时，提升为size_t导致判断结束逻辑出现问题
//	// 在数组中访问挪动数据就会出现越界，经典的类型安全问题
//	int end = 10;
//	while (end >= pos)
//	{
//		// ...
//		cout << end << endl;
//		--end;
//	}
//}
//int main()
//{
//	insert(5, 'x');
//	//insert(0, 'x');
//	// 这里会本质已经出现了越界访问，只是越界不一定能被检查出来
//	int x = 100;
//	double* p1 = (double*)&x;
//	cout << *p1 << endl;
//	const int y = 0;
//	int* p2 = (int*)&y;
//	(*p2) = 1;
//	// 这里打印的结果是1和0，也是因为我们类型转换去掉了const属性
//	// 但是编译器认为y是const的，不会被改变，所以会优化编译时放到
//	// 寄存器或者直接替换y为0导致的
//	cout << *p2 << endl;
//	cout << y << endl;
//	return 0;
//}

//// 自定义类型之间转换的实践样例
//// Test.cpp
//#include"List.h"
//int main()
//{
//	bit::list<int> lt = { 1,2,3,4 };
//	// 权限缩小？权限缩小和放大，仅限于const的指针和引用
//	// 这里不是权限缩小，这里是自定义类型=自定义类型之间的类型转换
//	// 具体实现看下面ListIterator中对应的构造函数的实现
//	bit::list<int>::const_iterator cit = lt.begin();
//	while (cit != lt.end())
//	{
//		cout << *cit << " ";
//		++cit;
//	}
//	cout << endl;
//	return 0;
//}
//// List.h
//#pragma once
//#include<assert.h>
//namespace bit
//{
//	template<class T>
//	struct ListNode
//	{
//		ListNode<T>* _next;
//		ListNode<T>* _prev;
//		T _data;
//		ListNode(const T& data = T())
//			:_next(nullptr)
//			, _prev(nullptr)
//			, _data(data)
//		{
//		}
//	};
//	template<class T, class Ref, class Ptr>
//	struct ListIterator
//	{
//		typedef ListNode<T> Node;
//		typedef ListIterator<T, Ref, Ptr> Self;
//		Node* _node;
//		ListIterator(Node* node)
//			:_node(node)
//		{
//		}
//		// typedef ListIterator<T, T&, T*> iterator;
//		// typedef ListIterator<T, const T&, const T*> const_iterator;
//		// ListIterator实例化为iterator时，这个函数是拷贝构造
//		// ListIterator实例化为const_iterator时，这个函数支持iterator转换为
//		const_iterator构造函数
//			ListIterator(const ListIterator<T, T&, T*>& it)
//			:_node(it._node)
//		{
//		}
//		// ++it;
//		Self& operator++()
//		{
//			_node = _node->_next;
//			return *this;
//		}
//		Self& operator--()
//		{
//			_node = _node->_prev;
//			return *this;
//		}
//		Self operator++(int)
//		{
//			Self tmp(*this);
//			_node = _node->_next;
//			return tmp;
//		}
//		Self& operator--(int)
//		{
//			Self tmp(*this);
//			_node = _node->_prev;
//			return tmp;
//		}
//		Ref operator*()
//		{
//			return _node->_data;
//		}
//		Ptr operator->()
//		{
//			return &_node->_data;
//		}
//		bool operator!=(const Self& it)
//		{
//			return _node != it._node;
//		}
//		bool operator==(const Self& it)
//		{
//			return _node == it._node;
//		}
//	};
//	template<class T>
//	class list
//	{
//		typedef ListNode<T> Node;
//	public:
//		// 同一个类模板给不同参数会实例化出不同的类型
//		typedef ListIterator<T, T&, T*> iterator;
//		typedef ListIterator<T, const T&, const T*> const_iterator;
//		iterator begin()
//		{
//			return iterator(_head->_next);
//		}
//		const_iterator begin() const
//		{
//			return const_iterator(_head->_next);
//		}
//		iterator end()
//		{
//			return iterator(_head);
//		}
//		const_iterator end() const
//		{
//			return const_iterator(_head);
//		}
//		void empty_init()
//		{
//			_head = new Node();
//			_head->_next = _head;
//			_head->_prev = _head;
//		}
//		list()
//		{
//			empty_init();
//		}
//		list(initializer_list<T> il)
//		{
//			empty_init();
//			for (const auto& e : il)
//			{
//				push_back(e);
//			}
//		}
//		void push_back(const T& x)
//		{
//			insert(end(), x);
//		}
//		// 没有iterator失效
//		iterator insert(iterator pos, const T& x)
//		{
//			Node* cur = pos._node;
//			Node* newnode = new Node(x);
//			Node* prev = cur->_prev;
//			// prev newnode cur
//			prev->_next = newnode;
//			newnode->_prev = prev;
//			newnode->_next = cur;
//			cur->_prev = newnode;
//			return iterator(newnode);
//		}
//	private:
//		Node* _head;
//	};
//}

//#include <iostream>
//using namespace std;
//// 内置类型和自定义类型之间
//// 1、自定义类型 = 内置类型 ->构造函数支持
//// 2、内置类型 = 自定义类型 ->operator 内置类型 支持
//class A
//{
//public:
//	// 构造函数加上explicit就不支持隐式类型转换了
//	//explicit A(int a)
//	A(int a)
//		:_a1(a)
//		, _a2(a)
//	{
//	}
//	A(int a1, int a2)
//		:_a1(a1)
//		, _a2(a2)
//	{
//	}
//	// 加上explicit就不支持隐式类型转换了
//	// explicit operator int()
//	operator int() const
//	{
//		return _a1 + _a2;
//	}
//private:
//	int _a1 = 1;
//	int _a2 = 1;
//};
//class B
//{
//public:
//	B(int b)
//		:_b1(b)
//	{}
//	// 支持A类型对象转换为B类型对象
//	B(const A& aa)
//		:_b1(aa)
//	{
//	}
//private:
//	int _b1 = 1;
//};
//int main()
//{
//	// 单参数的转换
//	string s1 = "1111111";
//	A aa1 = 1;
//	A aa2 = (A)1;
//	// 多参数的转换
//	A aa3 = { 2,2 };
//	const A& aa4 = { 2,2 };
//	int z = aa1.operator int();
//	int x = aa1;
//	int y = (int)aa2;
//	cout << x << endl;
//	cout << y << endl;
//	cout << z << endl;
//	std::shared_ptr<int> foo;
//	std::shared_ptr<int> bar(new int(34));
//	//if (foo.operator bool())
//	if (foo)
//		std::cout << "foo points to " << *foo << '\n';
//	else
//		std::cout << "foo is null\n";
//	if (bar)
//		std::cout << "bar points to " << *bar << '\n';
//	else
//		std::cout << "bar is null\n";
//	// A类型对象隐式转换为B类型
//	B bb1 = aa1;
//	B bb2(2);
//	bb2 = aa1;
//	const B& ref1 = aa1;
//	return 0;
//}


//int main()
//{
//	int i = 1;
//	// 隐式类型转换
//	// 隐式类型转换主要发生在整形和整形之间，整形和浮点数之间，浮点数和浮点数之间
//	double d = i;
//	printf("%d, %.2f\n", i, d);
//	int* p = &i;
//	// 显示的强制类型转换
//	// 强制类型转换主要发生在指针和整形之间，指针和指针之间
//	int address = (int)p;
//	printf("%p, %d\n", p, address);
//	// malloc返回值是void*，被强转成int*
//	int* ptr = (int*)malloc(8);
//	// 编译报错：类型强制转换: 无法从“int *”转换为“double”
//	// 指针是地址的编号，也是一种整数，所以可以和整形互相转换
//	// 但是指针和浮点数毫无关联，强转也是不支持的
//	// d = (double)p;
//	return 0;
//}

//struct HashFuncBKDR
//{
//	/// @detail 本 算法由于在Brian Kernighan与Dennis Ritchie的《The C
//	Programming Language》
//		// 一书被展示而得 名，是一种简单快捷的hash算法，也是Java目前采用的字符串的Hash
//		算法累乘因子为31。
//		size_t operator()(const string& s)
//	{
//		size_t hash = 0;
//		for (auto ch : s)
//		{
//			hash *= 31;
//			hash += ch;
//		}
//		return hash;
//	}
//};
//struct HashFuncAP
//{
//	// 由Arash Partow发明的一种hash算法。
//	size_t operator()(const string& s)
//	{
//		size_t hash = 0;
//		for (size_t i = 0; i < s.size(); i++)
//		{
//			if ((i & 1) == 0) // 偶数位字符
//			{
//				hash ^= ((hash << 7) ^ (s[i]) ^ (hash >> 3));
//			}
//			else // 奇数位字符
//			{
//				hash ^= (~((hash << 11) ^ (s[i]) ^ (hash >>
//					5)));
//			}
//		}
//		return hash;
//	}
//};
//struct HashFuncDJB
//{
//	// 由Daniel J. Bernstein教授发明的一种hash算法。
//	size_t operator()(const string& s)
//	{
//		size_t hash = 5381;
//		for (auto ch : s)
//		{
//			hash = hash * 33 ^ ch;
//		}
//		return hash;
//	}
//};
//template<size_t N,
//	size_t X = 6,
//	class K = string,
//	class Hash1 = HashFuncBKDR,
//	class Hash2 = HashFuncAP,
//	class Hash3 = HashFuncDJB>
//class BloomFilter
//{
//public:
//	void Set(const K& key)
//	{
//		size_t hash1 = Hash1()(key) % M;
//		size_t hash2 = Hash2()(key) % M;
//		size_t hash3 = Hash3()(key) % M;
//		_bs.set(hash1);
//		_bs.set(hash2);
//		_bs.set(hash3);
//	}
//	bool Test(const K& key)
//	{
//		size_t hash1 = Hash1()(key) % M;
//		if (_bs.test(hash1) == false)
//			return false;
//		size_t hash2 = Hash2()(key) % M;
//		if (_bs.test(hash2) == false)
//			return false;
//		size_t hash3 = Hash3()(key) % M;
//		if (_bs.test(hash3) == false)
//			return false;
//		return true; // 存在误判(有可能3个位都是跟别人冲突的，所以误判)
//	}
//	// 获取公式计算出的误判率
//	double getFalseProbability()
//	{
//		double p = pow((1.0 - pow(2.71, -3.0 / X)), 3.0);
//		return p;
//	}
//private:
//	static const size_t M = X * N;
//	// 我们实现位图是用vector，也就是堆上开的空间
//	bit::bitset<M> _bs;
//	//std::bitset<M> _bs;
//	// vs下std的位图是开的静态数组，M太大会存在崩的问题
//	// 解决方案就是bitset对象整体new一下，空间就开到堆上了
//	//std::bitset<M>* _bs = new std::bitset<M>;
//};
//void TestBloomFilter1()
//{
//	string strs[] = { "百度","字节","腾讯" };
//	BloomFilter<10> bf;
//	for (auto& s : strs)
//	{
//		bf.Set(s);
//	}
//	for (auto& s : strs)
//	{
//		cout << bf.Test(s) << endl;
//	}
//	for (auto& s : strs)
//	{
//		cout << bf.Test(s + 'a') << endl;
//	}
//	cout << bf.Test("摆渡") << endl;
//	cout << bf.Test("百渡") << endl;
//}
//void TestBloomFilter2()
//{
//	srand(time(0));
//	const size_t N = 10000000;
//	BloomFilter<N> bf;
//	//BloomFilter<N, 3> bf;
//	//BloomFilter<N, 10> bf;
//	std::vector<std::string> v1;
//	std::string url = "https://www.cnblogs.com/-
//		clq / archive / 2012 / 05 / 31 / 2528153.html";
//		//std::string url = "https://www.baidu.com/s?ie=utf-
//		8 & f = 8 & rsv_bp = 1 & rsv_idx = 1 & tn = 65081411_1_oem_dg & wd = ln2 & fenlei = 256 & rsv_pq = 0x8d9962
//		630072789f & rsv_t = ceda1rulSdBxDLjBdX4484KaopD % 2BzBFgV1uZn4271RV0PonRFJm0i5xAJ % 2F
//		Do & rqlang = en & rsv_enter = 1 & rsv_dl = ib & rsv_sug3 = 3 & rsv_sug1 = 2 & rsv_sug7 = 100 & rsv_sug2 =
//		0 & rsv_btype = i & inputT = 330 & rsv_sug4 = 2535";
//		//std::string url = "猪八戒";
//		for (size_t i = 0; i < N; ++i)
//		{
//			v1.push_back(url + std::to_string(i));
//		}
//	for (auto& str : v1)
//	{
//		bf.Set(str);
//	}
//	// v2跟v1是相似字符串集（前缀一样），但是后缀不一样
//	v1.clear();
//	for (size_t i = 0; i < N; ++i)
//	{
//		std::string urlstr = url;
//		urlstr += std::to_string(9999999 + i);
//		v1.push_back(urlstr);
//	}
//	size_t n2 = 0;
//	for (auto& str : v1)
//	{
//		if (bf.Test(str)) // 误判
//		{
//			++n2;
//		}
//	}
//	cout << "相似字符串误判率:" << (double)n2 / (double)N << endl;
//	// 不相似字符串集 前缀后缀都不一样
//	v1.clear();
//	for (size_t i = 0; i < N; ++i)
//	{
//		//string url = "zhihu.com";
//		string url = "孙悟空";
//		url += std::to_string(i + rand());
//		v1.push_back(url);
//	}
//	size_t n3 = 0;
//	for (auto& str : v1)
//	{
//		if (bf.Test(str))
//		{
//			++n3;
//		}
//	}
//	cout << "不相似字符串误判率:" << (double)n3 / (double)N << endl;
//	cout << "公式计算出的误判率:" << bf.getFalseProbability() << endl;
//}
//int main()
//{
//	TestBloomFilter2();
//	return 0;
//}

//int main()
//{
//	// 申请一个1G未释放，这个程序多次运行也没啥危害
//	// 因为程序马上就结束，进程结束各种资源也就回收了
//	char* ptr = new char[1024 * 1024 * 1024];
//	cout << (void*)ptr << endl;
//	return 0;
//}

//struct AA
//{
//	int _a1 = 0;
//	int _a2 = 0;
//	~AA()
//	{
//		cout << "~AA()" << endl;
//	}
//};
//int main()
//{
//	bit::shared_ptr<AA> p(new AA);
//	const size_t n = 100000;
//	mutex mtx;
//	auto func = [&]()
//		{
//			for (size_t i = 0; i < n; ++i)
//			{
//				// 这里智能指针拷贝会++计数
//				bit::shared_ptr<AA> copy(p);
//				{
//					unique_lock<mutex> lk(mtx);
//					copy->_a1++;
//					copy->_a2++;
//				}
//			}
//		};
//	thread t1(func);
//	thread t2(func);
//	t1.join();
//	t2.join();
//	cout << p->_a1 << endl;
//	cout << p->_a2 << endl;
//	cout << p.use_count() << endl;
//	return 0;
//}

//int main()
//{
//	std::shared_ptr<string> sp1(new string("111111"));
//	std::shared_ptr<string> sp2(sp1);
//	std::weak_ptr<string> wp = sp1;
//	cout << wp.expired() << endl;
//	cout << wp.use_count() << endl;
//	// sp1和sp2都指向了其他资源，则weak_ptr就过期了
//	sp1 = make_shared<string>("222222");
//	cout << wp.expired() << endl;
//	cout << wp.use_count() << endl;
//	sp2 = make_shared<string>("333333");
//	cout << wp.expired() << endl;
//	cout << wp.use_count() << endl;
//	wp = sp1;
//	//std::shared_ptr<string> sp3 = wp.lock();
//	auto sp3 = wp.lock();
//	cout << wp.expired() << endl;
//	cout << wp.use_count() << endl;
//	*sp3 += "###";
//	cout << *sp1 << endl;
//	return 0;
//}

//struct ListNode
//{
//	int _data;
//	std::shared_ptr<ListNode> _next;
//	std::shared_ptr<ListNode> _prev;
//	// 这里改成weak_ptr，当n1->_next = n2;绑定shared_ptr时
//	// 不增加n2的引用计数，不参与资源释放的管理，就不会形成循环引用了
//	/*std::weak_ptr<ListNode> _next;
//	std::weak_ptr<ListNode> _prev;*/
//	~ListNode()
//	{
//		cout << "~ListNode()" << endl;
//	}
//};
//int main()
//{
//	// 循环引用 -- 内存泄露
//	std::shared_ptr<ListNode> n1(new ListNode);
//	std::shared_ptr<ListNode> n2(new ListNode);
//	cout << n1.use_count() << endl;
//	cout << n2.use_count() << endl;
//	n1->_next = n2;
//	n2->_prev = n1;
//	cout << n1.use_count() << endl;
//	cout << n2.use_count() << endl;
//	// weak_ptr不支持管理资源，不支持RAII
//	// weak_ptr是专门绑定shared_ptr，不增加他的引用计数，作为一些场景的辅助管理
//	//std::weak_ptr<ListNode> wp(new ListNode);
//	return 0;
//}
//namespace bit
//{
//	template<class T>
//	class auto_ptr
//	{
//	public:
//		auto_ptr(T* ptr)
//			:_ptr(ptr)
//		{
//		}
//		auto_ptr(auto_ptr<T>& sp)
//			:_ptr(sp._ptr)
//		{
//			// 管理权转移
//			sp._ptr = nullptr;
//		}
//		auto_ptr<T>& operator=(auto_ptr<T>& ap)
//		{
//			// 检测是否为自己给自己赋值
//			if (this != &ap)
//			{
//				// 释放当前对象中资源
//				if (_ptr)
//					delete _ptr;
//				// 转移ap中资源到当前对象中
//				_ptr = ap._ptr;
//				ap._ptr = NULL;
//			}
//			return *this;
//		}
//		~auto_ptr()
//		{
//			if (_ptr)
//			{
//				cout << "delete:" << _ptr << endl;
//				delete _ptr;
//			}
//		}
//		// 像指针一样使用
//		T& operator*()
//		{
//			return *_ptr;
//		}
//		T* operator->()
//		{
//			return _ptr;
//		}
//	private:
//		T* _ptr;
//	};
//	template<class T>
//	class unique_ptr
//	{
//	public:
//		explicit unique_ptr(T* ptr)
//			:_ptr(ptr)
//		{
//		}
//		~unique_ptr()
//		{
//			if (_ptr)
//			{
//				cout << "delete:" << _ptr << endl;
//				delete _ptr;
//			}
//		}
//		// 像指针一样使用
//		T& operator*()
//		{
//			return *_ptr;
//		}
//		T* operator->()
//		{
//			return _ptr;
//		}
//		unique_ptr(const unique_ptr<T>&sp) = delete;
//		unique_ptr<T>& operator=(const unique_ptr<T>&sp) = delete;
//		unique_ptr(unique_ptr<T> && sp)
//			:_ptr(sp._ptr)
//		{
//			sp._ptr = nullptr;
//		}
//		unique_ptr<T>& operator=(unique_ptr<T> && sp)
//		{
//			delete _ptr;
//			_ptr = sp._ptr;
//			sp._ptr = nullptr;
//		}
//	private:
//		T* _ptr;
//	};
//	template<class T>
//	class shared_ptr
//	{
//	public:
//		explicit shared_ptr(T* ptr = nullptr)
//			: _ptr(ptr)
//			, _pcount(new int(1))
//		{
//		}
//		template<class D>
//		shared_ptr(T* ptr, D del)
//			: _ptr(ptr)
//			, _pcount(new int(1))
//			, _del(del)
//		{
//		}
//		shared_ptr(const shared_ptr<T>& sp)
//			:_ptr(sp._ptr)
//			, _pcount(sp._pcount)
//			, _del(sp._del)
//		{
//			++(*_pcount);
//		}
//		void release()
//		{
//			if (--(*_pcount) == 0)
//			{
//				// 最后一个管理的对象，释放资源
//				_del(_ptr);
//				delete _pcount;
//				_ptr = nullptr;
//				_pcount = nullptr;
//			}
//		}
//		shared_ptr<T>& operator=(const shared_ptr<T>& sp)
//		{
//			if (_ptr != sp._ptr)
//			{
//				release();
//				_ptr = sp._ptr;
//				_pcount = sp._pcount;
//				++(*_pcount);
//				_del = sp._del;
//			}
//			return *this;
//		}
//		~shared_ptr()
//		{
//			release();
//		}
//		T* get() const
//		{
//			return _ptr;
//		}
//		int use_count() const
//		{
//			return *_pcount;
//		}
//		T& operator*()
//		{
//			return *_ptr;
//		}
//		T* operator->()
//		{
//			return _ptr;
//		}
//	private:
//		T* _ptr;
//		int* _pcount;
//		//atomic<int>* _pcount;
//		function<void(T*)> _del = [](T* ptr) {delete ptr; };
//	};
//	// 需要注意的是我们这里实现的shared_ptr和weak_ptr都是以最简洁的方式实现的，
//	// 只能满足基本的功能，这里的weak_ptr lock等功能是无法实现的，想要实现就要
//	// 把shared_ptr和weak_ptr一起改了，把引用计数拿出来放到一个单独类型，shared_ptr
//	// 和weak_ptr都要存储指向这个类的对象才能实现，有兴趣可以去翻翻源代码
//	template<class T>
//	class weak_ptr
//	{
//	public:
//		weak_ptr()
//		{
//		}
//		weak_ptr(const shared_ptr<T>& sp)
//			:_ptr(sp.get())
//		{
//		}
//		weak_ptr<T>& operator=(const shared_ptr<T>& sp)
//		{
//			_ptr = sp.get();
//			return *this;
//		}
//	private:
//		T* _ptr = nullptr;
//	};
//}
//int main()
//{
//	bit::auto_ptr<Date> ap1(new Date);
//	// 拷贝时，管理权限转移，被拷贝对象ap1悬空
//	bit::auto_ptr<Date> ap2(ap1);
//	// 空指针访问，ap1对象已经悬空
//	//ap1->_year++;
//	bit::unique_ptr<Date> up1(new Date);
//	// 不支持拷贝
//	//unique_ptr<Date> up2(up1);
//	// 支持移动，但是移动后up1也悬空，所以使用移动要谨慎
//	bit::unique_ptr<Date> up3(move(up1));
//	bit::shared_ptr<Date> sp1(new Date);
//	// 支持拷贝
//	bit::shared_ptr<Date> sp2(sp1);
//	bit::shared_ptr<Date> sp3(sp2);
//	cout << sp1.use_count() << endl;
//	sp1->_year++;
//	cout << sp1->_year << endl;
//	cout << sp2->_year << endl;
//	cout << sp3->_year << endl;
//	return 0;
//}

//int main()
//{
//	shared_ptr<Date> sp1(new Date(2024, 9, 11));
//	shared_ptr<Date> sp2 = make_shared<Date>(2024, 9, 11);
//	auto sp3 = make_shared<Date>(2024, 9, 11);
//	shared_ptr<Date> sp4;
//	// if (sp1.operator bool())
//	if (sp1)
//		cout << "sp1 is not nullptr" << endl;
//	if (!sp4)
//		cout << "sp1 is nullptr" << endl;
//	// 报错
//	shared_ptr<Date> sp5 = new Date(2024, 9, 11);
//	unique_ptr<Date> sp6 = new Date(2024, 9, 11);
//	return 0;
//}

//template<class T>
//void DeleteArrayFunc(T* ptr)
//{
//	delete[] ptr;
//}
//template<class T>
//class DeleteArray
//{
//public:
//	void operator()(T* ptr)
//	{
//		delete[] ptr;
//	}
//};
//class Fclose
//{
//public:
//	void operator()(FILE* ptr)
//	{
//		cout << "fclose:" << ptr << endl;
//		fclose(ptr);
//	}
//};
//int main()
//{
//	// 这样实现程序会崩溃
//	// unique_ptr<Date> up1(new Date[10]);
//	// shared_ptr<Date> sp1(new Date[10]);
//	// 解决方案1
//	// 因为new[]经常使用，所以unique_ptr和shared_ptr
//	// 实现了一个特化版本，这个特化版本析构时用的delete[]
//	unique_ptr<Date[]> up1(new Date[5]);
//	shared_ptr<Date[]> sp1(new Date[5]);
//	// 解决方案2
//	// 仿函数对象做删除器
//	//unique_ptr<Date, DeleteArray<Date>> up2(new Date[5], DeleteArray<Date>
//	());
//	// unique_ptr和shared_ptr支持删除器的方式有所不同
//	// unique_ptr是在类模板参数支持的，shared_ptr是构造函数参数支持的
//	// 这里没有使用相同的方式还是挺坑的
//	// 使用仿函数unique_ptr可以不在构造函数传递，因为仿函数类型构造的对象直接就可以调用
//	// 但是下面的函数指针和lambda的类型不可以
//	unique_ptr<Date, DeleteArray<Date>> up2(new Date[5]);
//	shared_ptr<Date> sp2(new Date[5], DeleteArray<Date>());
//	// 函数指针做删除器
//	unique_ptr<Date, void(*)(Date*)> up3(new Date[5], DeleteArrayFunc<Date>);
//	shared_ptr<Date> sp3(new Date[5], DeleteArrayFunc<Date>);
//	// lambda表达式做删除器
//	auto delArrOBJ = [](Date* ptr) {delete[] ptr; };
//	unique_ptr<Date, decltype(delArrOBJ)> up4(new Date[5], delArrOBJ);
//	shared_ptr<Date> sp4(new Date[5], delArrOBJ);
//	// 实现其他资源管理的删除器
//	shared_ptr<FILE> sp5(fopen("Test.cpp", "r"), Fclose());
//	shared_ptr<FILE> sp6(fopen("Test.cpp", "r"), [](FILE* ptr) {
//		cout << "fclose:" << ptr << endl;
//		fclose(ptr);
//		});
//	return 0;
//}

//struct Date
//{
//	int _year;
//	int _month;
//	int _day;
//	Date(int year = 1, int month = 1, int day = 1)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//	{
//	}
//	~Date()
//	{
//		cout << "~Date()" << endl;
//	}
//};
//int main()
//{
//	auto_ptr<Date> ap1(new Date);
//	// 拷贝时，管理权限转移，被拷贝对象ap1悬空
//	auto_ptr<Date> ap2(ap1);
//	// 空指针访问，ap1对象已经悬空
//	//ap1->_year++;
//	unique_ptr<Date> up1(new Date);
//	// 不支持拷贝
//	//unique_ptr<Date> up2(up1);
//	// 支持移动，但是移动后up1也悬空，所以使用移动要谨慎
//	unique_ptr<Date> up3(move(up1));
//	shared_ptr<Date> sp1(new Date);
//	// 支持拷贝
//	shared_ptr<Date> sp2(sp1);
//	shared_ptr<Date> sp3(sp2);
//	cout << sp1.use_count() << endl;
//	sp1->_year++;
//	cout << sp1->_year << endl;
//	cout << sp2->_year << endl;
//	cout << sp3->_year << endl;
//	// 支持移动，但是移动后sp1也悬空，所以使用移动要谨慎
//	shared_ptr<Date> sp4(move(sp1));
//	return 0;
//}

//template<class T>
//class SmartPtr
//{
//public:
//	// RAII
//	SmartPtr(T* ptr)
//		:_ptr(ptr)
//	{
//	}
//	~SmartPtr()
//	{
//		cout << "delete[] " << _ptr << endl;
//		delete[] _ptr;
//	}
//	// 重载运算符，模拟指针的行为，方便访问资源
//	T& operator*()
//	{
//		return *_ptr;
//	}
//	T* operator->()
//	{
//		return _ptr;
//	}
//	T& operator[](size_t i)
//	{
//		return _ptr[i];
//	}
//private:
//	T* _ptr;
//};
//double Divide(int a, int b)
//{
//	// 当b == 0时抛出异常
//	if (b == 0)
//	{
//		throw "Divide by zero condition!";
//	}
//	else
//	{
//		return (double)a / (double)b;
//	}
//}
//void Func()
//{
//	// 这里使用RAII的智能指针类管理new出来的数组以后，程序简单多了
//	SmartPtr<int> sp1 = new int[10];
//	SmartPtr<int> sp2 = new int[10];
//	for (size_t i = 0; i < 10; i++)
//	{
//		sp1[i] = sp2[i] = i;
//	}
//	int len, time;
//	cin >> len >> time;
//	cout << Divide(len, time) << endl;
//}
//int main()
//{
//	try
//	{
//		Func();
//	}
//	catch (const char* errmsg)
//	{
//		cout << errmsg << endl;
//	}
//	catch (const exception& e)
//	{
//		cout << e.what() << endl;
//	}
//	catch (...)
//	{
//		cout << "未知异常" << endl;
//	}
//	return 0;
//}


//double Divide(int a, int b)
//{
//	// 当b == 0时抛出异常
//	if (b == 0)
//	{
//		throw "Divide by zero condition!";
//	}
//	else
//	{
//		return (double)a / (double)b;
//	}
//}
//void Func()
//{
//	// 这里可以看到如果发生除0错误抛出异常，另外下面的array和array2没有得到释放。
//	// 所以这里捕获异常后并不处理异常，异常还是交给外面处理，这里捕获了再重新抛出去。
//	// 但是如果array2new的时候抛异常呢，就还需要套一层捕获释放逻辑，这里更好解决方案
//	// 是智能指针，否则代码太戳了
//	int* array1 = new int[10];
//	int* array2 = new int[10]; // 抛异常呢
//	try
//	{
//		int len, time;
//		cin >> len >> time;
//		cout << Divide(len, time) << endl;
//	}
//	catch (...)
//	{
//		cout << "delete []" << array1 << endl;
//		cout << "delete []" << array2 << endl;
//		delete[] array1;
//		delete[] array2;
//		throw; // 异常重新抛出，捕获到什么抛出什么
//	}
//	// ...
//	cout << "delete []" << array1 << endl;
//	delete[] array1;
//	cout << "delete []" << array2 << endl;
//	delete[] array2;
//}
//int main()
//{
//	try
//	{
//		Func();
//	}
//	catch (const char* errmsg)
//	{
//		cout << errmsg << endl;
//	}
//	catch (const exception& e)
//	{
//		cout << e.what() << endl;
//	}
//	catch (...)
//	{
//		cout << "未知异常" << endl;
//	}
//	return 0;
//}

//shared_ptr<T>& operator=(const shared_ptr<T>& sp) {
//	if (_ptr != sp._ptr) {
//		if (--(*pcount) == 0) {
//			delete _ptr;
//			_ptr = nullptr;
//		}
//		_ptr = sp._ptr;
//		_pcount = sp.pcount;
//		++(*pcount);
//	}
//		return *this; and_eq`q12e
//}