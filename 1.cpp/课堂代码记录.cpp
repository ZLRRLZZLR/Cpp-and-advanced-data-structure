#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

namespace bit
{
	typedef int STDataType;
	typedef struct Stack
	{
		STDataType* a;
		int top;
		int capacity;
	}ST;
	void STInit(ST* ps, int n = 4);
	void STDestroy(ST* ps);
	void STPush(ST* ps, STDataType x);
	void STPop(ST* ps);
	STDataType STTop(ST* ps);
	int STSize(ST* ps);
	bool STEmpty(ST* ps);
}
#include"Stack.h"

namespace bit
{

	void STInit(ST* ps, int n)
	{
		assert(ps);
		ps->a = (STDataType*)malloc(n * sizeof(STDataType));
		ps->top = 0;
		ps->capacity = n;
	}
	// ջ
	void STPush(ST* ps, STDataType x)
	{
		assert(ps);
		// ˣ 
		if (ps->top == ps->capacity)
		{
			printf("\n");
			int newcapacity = ps->capacity == 0 ? 4 : ps->capacity
				* 2;
			STDataType* tmp = (STDataType*)realloc(ps->a,
				newcapacity * sizeof(STDataType));
			if (tmp == NULL)
			{
				perror("realloc fail");
				return;
			}

			ps->a = tmp;
			ps->capacity = newcapacity;
		}

		ps->a[ps->top] = x;
		ps->top++;
	}
	//...
}
#define _CRT_SECURE_NO_WARNINGS 1

//// test.cpp
//#include<stdio.h>
//
//int main()
//{
//	printf("hello world\n");
//	return 0;
//}
// 

// test.cpp
// 这里的std cout等我们都看不懂，没关系，下面我们会依次讲解
//#include<iostream>
//using namespace std;
//
//int main()
//{
//
//	//int i = 1;
//	//i << 10;
//
//	cout << "hello world\n" << endl;
//	return 0;
//}

// 命名冲突
//#include <stdio.h>
//#include <stdlib.h>
//
//// 域
//namespace bit
//{
//	int rand = 10;
//}
//
//int a = 0;
//
//int main()
//{
//	printf("%p\n", rand);
//	printf("%d\n", bit::rand);
//
//	int a = 1;
//	printf("%d\n", a);
//
//	// ::域作用限定符
//	printf("%d\n",::a);
//
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//// 域
//namespace bit
//{
//	int rand = 10;
//
//	int Add(int left, int right)
//	{
//		return left + right;
//	}
//
//	struct Node
//	{
//		struct Node* next;
//		int val;
//	};
//}
//
//int main()
//{
//	printf("%d\n", bit::Add(1, 1));
//
//	struct bit::Node p1;
//
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//// 域
//namespace bit
//{
//	// 鹏哥
//	namespace pg
//	{
//		int rand = 1;
//		int Add(int left, int right)
//		{
//		return left + right;
//		}
//	}
//
//	// 杭哥
//	namespace hg
//	{
//		int rand = 2;
//		int Add(int left, int right)
//		{
//			return (left + right) * 10;
//		}
//	}
//}
//
//int main()
//{
//	printf("%d\n", bit::pg::rand);
//	printf("%d\n", bit::hg::rand);
//
//
//	return 0;
//}

// test.cpp
//#include"Queue.h"
//#include"Stack.h"
//
//// 全局定义了一份单独的Stack
//typedef struct Stack
//{
//	int a[10];
//	int top;
//}ST;
//void STInit(ST* ps) {}
//void STPush(ST* ps, int x) {}
//
//int main()
//{
//	// 调用全局的
//	ST st1;
//	STInit(&st1);
//	STPush(&st1, 1);
//	STPush(&st1, 2);
//	printf("%d\n", sizeof(st1));
//
//	// 调用bit namespace的
//	bit::ST st2;
//	printf("%d\n", sizeof(st2));
//	bit::STInit(&st2, 4);
//	bit::STPush(&st2, 1);
//	bit::STPush(&st2, 2);
//
//	return 0;
//}

// 展开头文件
//#include <stdio.h>
//namespace bit
//{
//	int a = 0;
//	int b = 1;
//}
//
////using namespace bit;
//using bit::a;
//
//int main()
//{
//	printf("%d\n", a);
//	printf("%d\n", a);
//	printf("%d\n", a);
//	printf("%d\n", a);
//	printf("%d\n", a);
//	printf("%d\n", a);
//	printf("%d\n", bit::b);
//
//
//	return 0;
//}

#include<iostream>
using namespace std;

//int main()
//{
//	//int i = 1234;
//	//int j = -1234;
//	////std::cout << i << endl;
//	//cout << i << endl;
//
//	int a = 0;
//	double b = 0.1;
//	char c = 'x';
//
//	cout << a << "             " << b << " " << c << "\n" << '\n' << endl;
//	std::cout << a << " " << b << " " << c << std::endl;
//
//	scanf("%d%lf", &a, &b);
//	printf("%d %lf\n", a, b);
//
//	// 可以自动识别变量的类型
//	//cin >> a;
//	//cin >> b >> c;
//	cin >>a>> b >> c;
//	cout << a << endl;
//	cout << b << " " << c << endl;
//
//	return 0;
//}

//int main()
//{
//	double d = 2.22222222;
//	printf("%.2lf\n", d);
//	cout << d << endl;
//	cout << &d << endl;
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//int main()
//{
//	// 在io需求比较高的地方，如部分大量输入的竞赛题中，加上以下3行代码
//	// 可以提高C++IO效率
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//void Func(int a = 0)
//{
//	cout << a << endl;
//}
//
//// 全缺省
//void Func1(int a = 10, int b = 20, int c = 30)
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl << endl;
//}
//
//// 半缺省
//void Func2(int a, int b = 10, int c = 20)
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl << endl;
//}
//
//int main()
//{
//	Func(); // 没有传参时，使用参数的默认值
//	Func(10); // 传参时，使用指定的实参
//
//	Func1();
//	Func1(1);
//	Func1(1, 2);
//	Func1(1, 2, 3);
//
//	//Func2();
//	Func2(100);
//	Func2(100, 200);
//	Func2(100, 200, 300);
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//#include"Stack.h"
//
//int main()
//{
//	bit::ST s1;
//	bit::STInit(&s1);
//
//	// 确定知道要插入1000个数据，初始化时一把开好，避免扩容
//	bit::ST s2;
//	bit::STInit(&s2, 1000);
//
//	for (size_t i = 0; i < 1000; i++)
//	{
//		bit::STPush(&s2, i);
//	}
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//// 1、参数类型不同
//int Add(int left, int right)
//{
//	cout << "int Add(int left, int right)" << endl;
//	return left + right;
//}
//
//double Add(double left, double right)
//{
//	cout << "double Add(double left, double right)" << endl;
//	return left + right;
//}
//
//void Swap(int* px, int* py)
//{}
//
//void Swap(double* px, double* py)
//{}
//
//// 2、参数个数不同
//void f()
//{
//	cout << "f()" << endl;
//}
//void f(int a)
//{
//	cout << "f(int a)" << endl;
//}
//
//// 3、参数类型顺序不同
//void f(int a, char b)
//{
//	cout << "f(int a,char b)" << endl;
//}
//
//void f(char b, int a)
//{
//	cout << "f(char b, int a)" << endl;
//}

// 下面两个函数构成重载
// f()但是调用时，会报错，存在歧义，编译器不知道调用谁

//namespace bit1
//{
//	void f1()
//	{
//		cout << "f()" << endl;
//	}
//}


//void f1()
//{
//	cout << "f()" << endl;
//}
//
//void f1(int a = 10)
//{
//	cout << "f(int a)" << endl;
//}

// 返回值不同不能作为重载条件，因为调用时也无法区分
//void fxx()
//{}
//
//int fxx()
//{
//	return 0;
//}

// 12:03继续
//int main()
//{
//	Add(1, 2);
//	Add(1.1, 2.2);
//
//	f();
//	f(1);
//
//	f(1, 'x');
//	f('x', 1);
//
//	//bit1::f1();
//	//f1();
//
//	f1(1);
//
//	fxx();
//
//	return 0;
//}
//

//////////////////////////////////////////////////////////////////////


#include<iostream>
#include<assert.h>
using namespace std;

//int main()
//{
//	int a = 0;
//	// 引用：b和c是a的别名
//	int& b = a;
//	int& c = a;
//
//	// 也可以给别名b取别名，d相当于还是a的别名
//	int& d = b;
//	++d;
//
//	// 这里取地址我们看到是一样的
//	cout << &a << endl;
//	cout << &b << endl;
//	cout << &c << endl;
//	cout << &d << endl;
//	return 0;
//}

void Swap(int& rx, int& ry)
{
	int tmp = rx;
	rx = ry;
	ry = tmp;
}

void Swap(int* px, int* py)
{}

typedef int STDataType;
typedef struct Stack
{
	STDataType* a;
	int top;
	int capacity;
}ST;

void STInit(ST& rs, int n = 4)
{
	rs.a = (STDataType*)malloc(n * sizeof(STDataType));
	rs.top = 0;
	rs.capacity = n;
}

// 栈顶
void STPush(ST& rs, STDataType x)
{
	//assert(ps);

	// 满了， 扩容
	if (rs.top == rs.capacity)
	{
		printf("扩容\n");
		int newcapacity = rs.capacity == 0 ? 4 : rs.capacity * 2;
		STDataType* tmp = (STDataType*)realloc(rs.a, newcapacity *
			sizeof(STDataType));
		if (tmp == NULL)
		{
			perror("realloc fail");
			return;
		}
		rs.a = tmp;
		rs.capacity = newcapacity;
	}
	rs.a[rs.top] = x;
	rs.top++;
}
// int STTop(ST& rs)
int& STTop(ST& rs)
{
	assert(rs.top > 0);
	return rs.a[rs.top];
}

//int main()
//{
//	int x = 0, y = 1;
//	cout << x << " " << y << endl;
//	//Swap(&x, &y);
//
//	Swap(x, y);
//	cout << x << " " << y << endl;
//
//
//	// 调用全局的
//	ST st1;
//	STInit(st1);
//	STPush(st1, 1);
//	STPush(st1, 2);
//
//	cout << STTop(st1) << endl;
//
//	return 0;
//}


typedef struct ListNode
{
	int val;
	struct ListNode* next;
}LTNode, *PNode;

// typedef struct ListNode* PNode;

//void ListPushBack(LTNode** phead, int x)
void ListPushBack(LTNode*& phead, int x)
//void ListPushBack(PNode& phead, int x)
{
	PNode newnode = (PNode)malloc(sizeof(LTNode));
	newnode->val = x;
	newnode->next = NULL;
	if (phead == NULL)
	{
		phead = newnode;
	}
	else
	{
		//...
	}
}

int main()
{
	//PNode plist = NULL;
	LTNode* plist = NULL;
	ListPushBack(plist, 1);

	return 0;
}
#pragma once

//#include "F.h"
//void f(int i)
//{
//	cout << i << endl;
//}
#include<iostream>
using namespace std;

//void func1(int& x)
//{
//	x++;
//}
//
////int& func2()
////{}
//
//int main()
//{
//	int a = 10;
//	// 编译报错：“ra”: 必须初始化引用
//	//int& ra;
//
//	func1(a);
//
//	int& b = a;
//	int& c = b;
//
//	int d = 20;
//	b = d;
//
//	cout << &a << endl;
//	cout << &b << endl;
//	cout << &d << endl;
//
//	return 0;
//}

//#include<iostream>
//#include<assert.h>
//
//using namespace std;
//typedef int STDataType;
//typedef struct Stack
//{
//	STDataType* a;
//	int top;
//	int capacity;
//}ST;
//
//void STInit(ST& rs, int n = 4)
//{
//	rs.a = (STDataType*)malloc(n * sizeof(STDataType));
//	rs.top = 0;
//	rs.capacity = n;
//}
//
//// 栈顶
//void STPush(ST& rs, STDataType x)
//{
//	// 满了， 扩容
//	if (rs.top == rs.capacity)
//	{
//		printf("扩容\n");
//		int newcapacity = rs.capacity == 0 ? 4 : rs.capacity * 2;
//		STDataType* tmp = (STDataType*)realloc(rs.a, newcapacity *
//			sizeof(STDataType));
//		if (tmp == NULL)
//		{
//			perror("realloc fail");
//			return;
//		}
//		rs.a = tmp;
//		rs.capacity = newcapacity;
//	}
//	rs.a[rs.top] = x;
//	rs.top++;
//}
//
//void STModityTop(ST& rs, int x)
//{
//	rs.a[rs.top-1] = x;
//}
//
//// int STTop(ST& rs)
//int& STTop(ST& rs)
//{
//	assert(rs.top > 0);
//	return rs.a[rs.top-1];
//}
//
//int& func()
//{
//	int a = 0;
//	return a;
//}
//
//int main()
//{
//	// 调用全局的
//	ST st1;
//	STInit(st1);
//	STPush(st1, 1);
//	STPush(st1, 2);
//
//	STModityTop(st1, 3);
//
//	STTop(st1) = 4;
//
//	/*vector<int> v;
//	for (size_t i = 0; i < v.size(); i++)
//	{
//		v[i] = i;
//	}*/
//	//operator[]
//	
//
//	return 0;
//}

// 函数模版，T可以任意类型
//template<class T>
//void func(const T& val)
//{
//
//}

//void func(const int& val)
//{
//
//}
//
//int main()
//{
//	const int a = 10;
//	//int rd = a;
//	//int& ra = a;
//
//	const int& ra = a;
//
//	// 引用的时候权限可以缩小，但是不能放大
//	int b = 20;
//	const int& rb = b;
//	b++;
//	//rb++;
//
//	const int& rc = 30;
//	const int& rd = (a + b);
//
//	double d = 12.34;
//	int i = d;
//	const int& ri = d;
//	//double& rd = d;
//
//	func(a);
//	func(b);
//	func(30);
//	func(a+b);
//	func(d);
//
//	return 0;
//}

//int main()
//{
//	int a = 0;
//	int* p = &a;
//	*p = 1;
//
//	int& ra = a;
//	ra = 2;
//
//	// 空引用
//	int* ptr = NULL;
//	int& rb = *ptr;
//	rb++;
//
//	const int& rc = a + 2;
//
//	return 0;
//}

////////////////////////////////////////////////////////////////////////
// inline

// 实现一个ADD宏函数的常见问题
//#define ADD(int a, int b) return a + b;
//#define ADD(a, b) a + b;
//#define ADD(a, b) (a + b)

// 正确的宏实现
//#define ADD(a, b) ((a) + (b))
//// 为什么不能加分号?
//// 为什么要加外面的括号?
//// 为什么要加里面的括号?
//
//int main()
//{
//	int ret = ADD(1, 2); // int ret = ((1)+(2));
//	cout << ADD(1, 2) << endl;
//
//	cout << ADD(1, 2) * 5 << endl;
//
//	int x = 1, y = 2;
//	ADD(x & y, x | y); // -> (x&y+x|y)
//
//	return 0;
//}

//inline int Add(int x, int y)
//{
//	int ret = x + y;
//	ret += 1;
//	ret += 1;
//	ret += 1;
//	ret += 1;
//	ret += 1;
//	ret += 1;
//	ret += 1;
//	ret += 1;
//	ret += 1;
//
//	return ret;
//}
//
//#include"F.h"
//
//int main()
//{
//	int ret = Add(1, 2);
//	cout << Add(1, 2) * 5 << endl;
//	cout << ret << endl;
//
//	f(10);
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//void f(int x)
//{
//	cout << "f(int x)" << endl;
//}
//
//void f(int* ptr)
//{
//	cout << "f(int* ptr)" << endl;
//}
//
//int main()
//{
//	f(0);
//	f(NULL);
//	//f((void*)0);
//
//	f(nullptr);
//
//	// C++
//	void* p1 = NULL;
//	int* p2 = (int*)p1;
//
//	int* p2 = nullptr;
//	//int i = nullptr;
//
//	return 0;
//}

#include<iostream>
using namespace std;

//class Queue
//{
//public:
//	void Push(int x)
//	{}
//};

//class Stack
//{
//public:
//	void Push(int x)
//	{}
////public:
//	void Pop()
//	{}
//
//	int Top()
//	{
//		return 0;
//	}
//private:
//	int* a;
//	int top;
//	int capacity;
//};
//
//int main()
//{
//	Stack st;
//	st.Pop();
//	st.Push(1);
//	//st.a;
//
//	return 0;
//}

// class Date
struct Date
{
public:
	void Init(int year, int month, int day);

//private:
	// 为了区分成员变量，一般习惯上成员变量
	// 会加一个特殊标识，如_ 或者 m开头
	// 声明
	int _year; // year_ m_year
	int _month;
	int _day;
};

void Date::Init(int year, int month, int day)
{
	_year = year;
	_month = month;
	_day = day;
}

// 兼容C的struct用法
typedef struct ListNodeC
{
	int val;
	struct ListNodeC* next;
}LTNodeC;

// CPP
struct ListNodeCPP
{
	int val;
	ListNodeCPP* next;
};

int main()
{
	Date d2;
	Date d3;

	d2.Init(2024, 7, 9);

	struct Date d1;

	ListNodeCPP node;

	//Date::_year = 2024;

	return 0;
}