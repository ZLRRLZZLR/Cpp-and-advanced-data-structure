#include"Stack."
#define _CRT_SECURE_NO_WARNINGS 1


//#include<iostream>
//using namespace std;
//void f(int x)
//{
//	cout << "f(int x)" << endl;
//}
//void f(int* ptr)
//{
//	cout << "f(int* ptr)" << endl;
//}
//int main()
//{
//	f(0);
//	// 本想通过f(NULL)调用指针版本的f(int*)函数，但是由于NULL被定义成0，调用了f(int
//	//x)，因此与程序的初衷相悖。
//	f(NULL);
//	f((int*)NULL);
//	// 编译报错：error C2665: “f”: 2 个重载中没有一个可以转换所有参数类型
//	// f((void*)NULL);
//	f(nullptr);
//	return 0;
//}
//#ifndef NULL
//  #ifdef __cplusplus
//    #define NULL 0
//  #else
//    #define NULL ((void *)0)
//  #endif
//#endif
//#ifndef NULL
//#ifdef __cplusplus
//#define NULL 0
//#else
//#define NULL ((void *)0)
//#endif
//#endif
//#include<iostream>
//using namespace std;
//// 实现一个ADD宏函数的常见问题
////#define ADD(int a, int b) return a + b;
////#define ADD(a, b) a + b;
////#define ADD(a, b) (a + b)
//// 正确的宏实现
//#define ADD(a, b) ((a) + (b))
//// 为什么不能加分号?
//// 为什么要加外面的括号?
//// 为什么要加里面的括号?
//int main()
//{
//	int ret = ADD(1, 2);
//	cout << ADD(1, 2) << endl;
//	cout << ADD(1, 2) * 5 << endl;
//	int x = 1, y = 2;
//	ADD(x & y, x | y); // -> (x&y+x|y)
//	return 0;
//}
//// F.h
//#include <iostream>
//using namespace std;
//inline void f(int i);
//// F.cpp
//#include "F.h"
//void f(int i)
//{
//	cout << i << endl;
//}
//// main.cpp
//#include "F.h"
//int main()
//{// 链接错误：无法解析的外部符号 "void __cdecl f(int)" (?f@@YAXH@Z)
//	f(10);
//	return 0;
//}
//#include<iostream>
//using namespace std;
//inline int Add(int x, int y)
//{
//	int ret = x + y;
//	ret += 1;
//	ret += 1;
//	ret += 1;
//	return ret;
//}
//int main()
//{
//	// 可以通过汇编观察程序是否展开
//	// 有call Add语句就是没有展开，没有就是展开了
//	int ret = Add(1, 2);
//	cout << Add(1, 2) * 5 << endl;
//	return 0;
//}
//int main()
//{
//	const int a = 10;
//	// 编译报错：error C2440: “初始化”: 无法从“const int”转换为“int &”
//	// 这里的引用是对a访问权限的放大
//	//int& ra = a;
//	// 这样才可以
//	const int& ra = a;
//	// 编译报错：error C3892: “ra”: 不能给常量赋值
//	//ra++;
//	// 这里的引用是对b访问权限的缩小
//	int b = 20;
//	const int& rb = b;
//	// 编译报错：error C3892: “rb”: 不能给常量赋值
//	//rb++;
//	return 0;
//}
//#include<iostream>
//using namespace std;
//int main()
//{
//	int a = 10;
//	const int& ra = 30;
//	// 编译报错: “初始化”: 无法从“int”转换为“int &”
//	// int& rb = a * 3;
//	const int& rb = a * 3;
//	double d = 12.34;
//	// 编译报错：“初始化”: 无法从“double”转换为“int &”
//	// int& rd = d;
//	const int& rd = d;
//	return 0;
//}
//void Swap(int& rx, int& ry)
//{
//	int tmp = rx;
//	rx = ry;
//	ry = tmp;
//}
//int main()
//{
//	int x = 0, y = 1;
//	cout << x << " " << y << endl;
//	Swap(x, y);
//	cout << x << " " << y << endl;
//	return 0;
//}
//#include<iostream>
//using namespace std;
//typedef int STDataType;
//typedef struct Stack
//{
//	STDataType* a;
//	int top;
//	int capacity;
//}ST;
//void STInit(ST& rs, int n = 4)
//{
//	rs.a = (STDataType*)malloc(n * sizeof(STDataType));
//	rs.top = 0;
//	rs.capacity = n;
//}
//// 栈顶
//void STPush(ST& rs, STDataType x)
//{
//	assert(ps);
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
//// int STTop(ST& rs)
//int& STTop(ST& rs)
//{
//	assert(rs.top > 0);
//	return rs.a[rs.top];
//}
//int main()
//{
//	// 调用全局的
//	ST st1;
//	STInit(st1);
//	STPush(st1, 1);
//	STPush(st1, 2);
//	cout << STTop(st1) << endl;
//	STTop(st1) += 10;
//	cout << STTop(st1) << endl;
//	return 0;
//}
//#include<iostream>
//using namespace std;
//typedef struct SeqList
//{
//	int a[10];
//	int size;
//}SLT;
//// 一些主要用C代码实现版本数据结构教材中，使用C++引用替代指针传参，目的是简化程序，避开复
//杂的指针，但是很多同学没学过引用，导致一头雾水。
//void SeqPushBack(SLT& sl, int x)
//{}
//typedef struct ListNode
//{
//	int val;
//	struct ListNode* next;
//}LTNode, * PNode;
//// 指针变量也可以取别名，这里LTNode*& phead就是给指针变量取别名
//// 这样就不需要用二级指针了，相对而言简化了程序
////void ListPushBack(LTNode** phead, int x)
////void ListPushBack(LTNode*& phead, int x)
//void ListPushBack(PNode& phead, int x)
//{
//	PNode newnode = (PNode)malloc(sizeof(LTNode));
//	newnode->val = x;
//	newnode->next = NULL;
//	if (phead == NULL)
//	{
//		phead = newnode;
//	}
//	else
//	{
//		//...
//	}
//}
//int main()
//{
//	PNode plist = NULL;
//	ListPushBack(plist, 1);
//	return 0;
//}
//#include<iostream>
//using namespace std;
//int main()
//{
//	int a = 10;
//	// 编译报错：“ra”: 必须初始化引用
//	//int& ra;
//	int& b = a;
//	int c = 20;
//	// 这里并非让b引用c，因为C++引用不能改变指向，
//	// 这里是一个赋值
//	b = c;
//	cout << &a << endl;
//	cout << &b << endl;
//	cout << &c << endl;
//	return 0;
//}

//#include<iostream>
//using namespace std;
//int main()
//{
//	int a = 0;
//	// 引用：b和c是a的别名
//	int& b = a;
//	int& c = a;
//	// 也可以给别名b取别名，d相当于还是a的别名
//	int& d = b;
//	++d;
//	// 这里取地址我们看到是一样的
//	cout << &a << endl;
//	cout << &b << endl;
//	cout << &c << endl;
//	cout << &d << endl;
//	return 0;
//}

//#include<iostream>
//using namespace std;
//// 1、参数类型不同
//int Add(int left, int right)
//{
//	cout << "int Add(int left, int right)" << endl;
//	return left + right;
//}
//double Add(double left, double right)
//{
//	cout << "double Add(double left, double right)" << endl;
//	return left + right;
//}
//// 2、参数个数不同
//void f()
//{
//	cout << "f()" << endl;
//}
//void f(int a)
//{
//	cout << "f(int a)" << endl;
//}
//// 3、参数类型顺序不同
//void f(int a, char b)
//{
//	cout << "f(int a,char b)" << endl;
//}
//void f(char b, int a)
//{
//	cout << "f(char b, int a)" << endl;
//}
//// 返回值不同不能作为重载条件，因为调用时也无法区分
////void fxx()
////{}
////
////int fxx()
////{
//// return 0;
////}
//// 下面两个函数构成重载
//// f()但是调用时，会报错，存在歧义，编译器不知道调用谁
//void f1()
//{
//	cout << "f()" << endl;
//}
//void f1(int a = 10)
//{
//	cout << "f(int a)" << endl;
//}
//int main() 
//{
//	Add(10, 20);
//	Add(10.1, 20.2);
//	f();
//	f(10);
//	f(10, 'a');
//	f('a', 10);
//	return 0;
//}
//#include <iostream>
//#include <assert.h>
//using namespace std;
//void Func(int a = 0)
//{
//	cout << a << endl;
//}
//int main()
//{
//	Func(); // 没有传参时，使用参数的默认值
//	Func(10); // 传参时，使用指定的实参
//	return 0;
//}
//#include <iostream>
//using namespace std;
//// 全缺省
//void Func1(int a = 10, int b = 20, int c = 30)
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl << endl;
//}
//// 半缺省
//void Func2(int a, int b = 10, int c = 20)
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl << endl;
//}
//int main()
//{
//	Func1();
//	Func1(1);
//	Func1(1, 2);
//	Func1(1, 2, 3);
//	Func2(100);
//	Func2(100, 200);
//	Func2(100, 200, 300);
//	return 0;
//}
//// Stack.h
//#include <iostream>
//#include <assert.h>
//using namespace std;
//typedef int STDataType;
//typedef struct Stack
//{
//	STDataType* a;
//	int top;
//	int capacity;
//}ST;
//void STInit(ST* ps, int n = 4);
//// Stack.cpp
//#include"Stack.h"
//// 缺省参数不能声明和定义同时给
//void STInit(ST* ps, int n)
//{
//	assert(ps && n > 0);
//	ps->a = (STDataType*)malloc(n * sizeof(STDataType));
//	ps->top = 0;
//	ps->capacity = n;
//}
//// test.cpp
//#include"Stack.h"
//int main()
//{
//	ST s1;
//	STInit(&s1);
//	// 确定知道要插入1000个数据，初始化时一把开好，避免扩容
//	ST s2;
//	STInit(&s2, 1000);
//	return 0;
//}
//#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//using namespace std;
//int main()
//{
//	int a = 0;
//	double b = 0.1;
//	char c = 'x';
//	cout << a << " " << b << " " << c << endl;
//	std::cout << a << " " << b << " " << c << std::endl;
//	scanf("%d%lf", &a, &b);
//	printf("%d %lf\n", a, b);
//	// 可以自动识别变量的类型
//	cin >> a;
//	cin >> b >> c;
//	cout << a << endl;
//	cout << b << " " << c << endl;
//	return 0;
//}
//#include<iostream>
//using namespace std;
//int main()
//{
//	// 在io需求比较高的地方，如部分大量输入的竞赛题中，加上以下3行代码
//	// 可以提高C++IO效率
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//	return 0;
//}
////test.cpp
//#include<stdio.h>
//
//int main() {
//	printf("hello world\n");
//	return 0;
//}

//test.cpp
//#include<iostream>
//using namespace std;

//int main() {
//	//int i = 1;
//	//i << 10;
//
//	cout << "hello world\n" << endl;
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//namespace blog {
//	int rand = 10;
//}
//
//int a = 0;
//int main() {
//	printf("%p\n",rand);
//	printf("%d\n",blog::rand);
//
//	int a = 1;
//	printf("%d\n",a);
//
//	printf("%d\n",::a);
//
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//
//namespace blog
//{
//	int rand = 20;
//
//	int Add(int left, int right) {
//		return left + right;
//	}
//
//	struct Node {
//		struct Node* next;
//		int val;
//	};
//}
//
//int main() {
//	printf("%d\n",blog::Add(1,1));
//
//	struct blog::Node p1;
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//
//namespace blog {
//
//	namespace b1 {
//		int rand = 1;
//		int Add(int left, int right) {
//			return left + right;
//		}
//	}
//
//	namespace b2 {
//		int rand = 2;
//		int Add(int left, int right) {
//			return (left + right) * 10;
//		}
//	}
//}
//
//int main() {
//	printf("%d\n",blog::b1::rand);
//	printf("%d\n", blog::b2::rand);
//
//}





