#include<iostream>


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
//	{
//	}
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

//int main()
//{
//	// 对应隐式类型转换 -- 数据的解释意义没有改变
//	double d = 12.34;
//	int a = static_cast<int>(d);
//	std::cout << a << std::endl;
//	int&& ref = static_cast<int&&>(a);
//	// 对应强制类型转换 -- 数据的解释意义已经发生改变
//	int* p1 = reinterpret_cast<int*>(a);
//
//	// 对应强制类型转换中有风险的去掉const属性
//	// 所以要注意加volatile
//	//const修饰的变量可能会优化到寄存器中或者直接替换
//	//需要volatile修饰从内存中获取数据
//	volatile const int b = 0;
//	int* p2 = const_cast<int*>(&b);
//	*p2 = 1;
//	std::cout << b << std::endl;
//	std::cout << *p2 << std::endl;
//
//	return 0;
//}

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

//#include<iostream>
//#include<string>
//#include<vector>
//#include<list>
//using namespace std;
//
//int main() {
//	int a[10];
//	int* ptr = nullptr;
//	cout << typeid(10).name() << endl;
//	cout << typeid(a).name() << endl;
//	cout << typeid(ptr).name() << endl;
//	cout << typeid(string).name() << endl;
//	cout << typeid(string::iterator).name() << endl;
//
//	cout << typeid(vector<int>).name() << endl;
//	cout << typeid(vector<int>::iterator).name() << endl;
//
//	return 0;
//}
//
//#include<iostream>
//using namespace std;
//class A
//{
//public:
//	virtual void func()
//	{
//	}
//protected:
//	int _a1 = 1;
//};
//class B : public A
//{
//protected:
//	int _b1 = 2;
//};
//int main()
//{
//	try
//	{
//		B* pb = new B;
//		A* pa = (A*)pb;
//		if (typeid(*pb) == typeid(B))
//		{
//			cout << "typeid(*pb) == typeid(B)" << endl;
//		}
//		// 如果A和B不是继承关系，则会抛bad_typeid异常
//		if (typeid(*pa) == typeid(B))
//		{
//			cout << "typeid(*pa) == typeid(B)" << endl;
//		}
//		// 这里pa和pb是A*和B*，不是类类型对象，他会被当做编译是求值的静态类型运
//		//算
//			// 所以这里始终是不相等的
//			if (typeid(pa) == typeid(pb))
//			{
//				cout << "typeid(pa) == typeid(B)" << endl;
//			}
//	}
//	catch (const std::exception& e)
//	{
//		cout << e.what() << endl;
//	}
//	return 0;
//}
