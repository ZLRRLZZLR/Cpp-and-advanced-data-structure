#include <stdio.h>
#include <stdlib.h>

//
//#include<stdio.h>
//namespace N
//{
//	int a = 0;
//	int b = 1;
//}
//// 展开命名空间中全部成员
//using namespace N;
//
//int main()
//{
//	printf("%d\n", a);
//	printf("%d\n", b);
//	return 0;
//}



//#include <stdio.h>
//#include <stdlib.h>
//
//namespace N
//{
//	int a = 0;
//	int b = 1;
//}
//// using将命名空间中某个成员展开
//using N::b;
//int main()
//{
//	printf("%d\n", N::a);
//	printf("%d\n", b);
//	return 0;
//}
//// 域
//namespace zlr
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
//	printf("%d\n", zlr::Add(1, 1));
//
//	//zlr::struct Node p1;
//
//	struct zlr::Node p1;
//
//	return 0;
//}
// //命名冲突
//#include <stdio.h>
//#include <stdlib.h>
//
//// 域
//namespace zlr
//{
//	int rand = 10;
//}
//namespace zlr1
//{
//	int rand = 20;
//}
//
//int a = 0;
//
//int main()
//{
//	printf("%d\n", rand);
//	printf("%d\n", zlr::rand);
//	printf("%d\n", zlr1::rand);
//
//	return 0;
//}
//// 多文件中可以定义同名namespace，他们会默认合并到一起，就像同一个namespace一样
//// Stack.h
//#pragma once
//#include<stdio.h>
//#include<stdlib.h>
//#include<stdbool.h>
//#include<assert.h>
//namespace bit
//{
//	typedef int STDataType;
//	typedef struct Stack
//	{
//		STDataType* a;
//		int top;
//		int capacity;
//	}ST;
//	void STInit(ST* ps, int n);
//	void STDestroy(ST* ps);
//	void STPush(ST* ps, STDataType x);
//	void STPop(ST* ps);
//	STDataType STTop(ST* ps);
//	int STSize(ST* ps);
//	bool STEmpty(ST* ps);
//}
//// Stack.cpp
//#include"Stack.h"
//namespace bit
//{
//	void STInit(ST* ps, int n)
//	{
//		assert(ps);
//		ps->a = (STDataType*)malloc(n * sizeof(STDataType));
//		ps->top = 0;
//		ps->capacity = n;
//	}
//	// 栈顶
//	void STPush(ST* ps, STDataType x)
//	{
//		assert(ps);
//		// 满了， 扩容
//		if (ps->top == ps->capacity)
//		{
//			printf("扩容\n");
//			int newcapacity = ps->capacity == 0 ? 4 : ps->capacity
//				* 2;
//			STDataType* tmp = (STDataType*)realloc(ps->a,
//				newcapacity * sizeof(STDataType));
//			if (tmp == NULL)
//			{
//				perror("realloc fail");
//				return;
//			}ps->a = tmp;
//			ps->capacity = newcapacity;
//		}
//		ps->a[ps->top] = x;
//		ps->top++;
//	}
//	//...
//}
//// Queue.h
//#pragma once
//#include<stdlib.h>
//#include<stdbool.h>
//#include<assert.h>
//namespace bit
//{
//	typedef int QDataType;
//	typedef struct QueueNode
//	{
//		int val;
//		struct QueueNode* next;
//	}QNode;
//	typedef struct Queue
//	{
//		QNode* phead;
//		QNode* ptail;
//		int size;
//	}Queue;
//	void QueueInit(Queue* pq);
//	void QueueDestroy(Queue* pq);
//	// 入队列
//	void QueuePush(Queue* pq, QDataType x);
//	// 出队列
//	void QueuePop(Queue* pq);
//	QDataType QueueFront(Queue* pq);
//	QDataType QueueBack(Queue* pq);
//	bool QueueEmpty(Queue* pq);
//	int QueueSize(Queue* pq);
//}
//// Queue.cpp
//#include"Queue.h"
//namespace bit
//{
//	void QueueInit(Queue* pq)
//	{
//		assert(pq);
//		pq->phead = NULL;
//		pq->ptail = NULL;
//		pq->size = 0;
//	}
//	// ...
//}
//// test.cpp
//#include"Queue.h"
//#include"Stack.h"
//// 全局定义了一份单独的Stack
//typedef struct Stack
//{
//	int a[10];
//	int top;
//}ST;
//void STInit(ST* ps) {}
//void STPush(ST* ps, int x) {}
//int main()
//{
//	// 调用全局的
//	ST st1;
//	STInit(&st1);
//	STPush(&st1, 1);
//	STPush(&st1, 2);
//	printf("%d\n", sizeof(st1));
//	// 调用bit namespace的
//	bit::ST st2;
//	printf("%d\n", sizeof(st2));
//	bit::STInit(&st2);
//	bit::STPush(&st2, 1);
//	bit::STPush(&st2, 2);
//	return 0;
//}
////2. 命名空间可以嵌套
//namespace bit
//{
//	namespace zlr1
//	{
//		int rand = 1;
//		int Add(int left, int right)
//		{
//			return left + right;
//		}
//	}
//	namespace zlr2
//	{
//		int rand = 2;
//		int Add(int left, int right)
//		{
//			return (left + right) * 10;
//		}
//	}
//}
//int main()
//{
//	printf("%d\n", bit::zlr1::rand);
//	printf("%d\n", bit::zlr2::rand);
//	printf("%d\n", bit::zlr1::Add(1, 2));
//	printf("%d\n", bit::zlr2::Add(1, 2));
//	return 0;
//}
//#include <stdio.h>
//#include <stdlib.h>
//// 1. 正常的命名空间定义
//// zlr是命名空间的名字，一般开发中是用项目名字做命名空间名。
//// 自己可以考虑用自己名字缩写，如张三：zs
//namespace zlr
//{
//	// 命名空间中可以定义变量/函数/类型
//	int rand = 10;
//
//}
//int main()
//{
//	// 这里默认是访问的是全局的rand函数指针
//	printf("%p\n", rand);
//
//	return 0;
//}
//#include <stdio.h>
//#include <stdlib.h>
//int rand = 10;
//// C语言没办法解决类似这样的命名冲突问题，所以C++提出了namespace来解决
//int main()
//{
//	printf("%d\n", rand);
//	return 0;
//}
// 编译后后报错：error C2365: “rand”: 重定义；以前的定义是“函数”

// 
// 
//int main()
//{
//	const int a = 10;
//	int rd = a;
//	const int& ra = a;
//
//	//const int& rc = 30;
//	//const int& rd = (a + b);
//
//	int* ptr = NULL;
//	int& rb = *ptr;
//
//	rd++;
//	const int& rc = a + 2;
//
//}

//void func1(int& x)
//{
//	x++;
//}
//
////int& func2()
////{
////
////}
//
//int main()
//{
//	int a = 10;
//	int& ra = a;
//	func1(a);
//
//	int& b = a;
//	int& c = b;
//	cout << &a << endl;
//	cout << &b << endl;
//	cout << &c << endl;
//
//	return 0;
//
//
//}

/*#include<iostream>
using namespace std*/;
//namespace bit
//{
//	int a = 0;
//	int b = 1;
//
//}
//
//using namespace bit;
//using bit::a;
//
//#include<iostream>
//using namespace std;

//void Func(int a = 0)
//{
//	cout << a << endl;
//}
//
////全缺省
//void Func1(int a = 10,int b = 20, int c = 30)
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl << endl;
//}
//
////半缺省
//void Func2(int a ,int b = 10,int c = 20)
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl << endl;
//}
//
//int main()
//{
//	////cout << a << endl;
//	//int i = 1234;
//	//std::cout << i << endl;
//	//cout << i << endl;
//
//	//int a = 0;
//	//double b = 0.1;
//	//char c = 'x';
//
//	//cin >> a >> b >> c;
//	//cout << a << endl;
//
//
//	//cout << a << "" << b << "" << "\n" << endl;
//	//std::cout << a << "" << b << "" << "\n" << std::endl;
//
//	
//	Func(); // 没有传参时，使用参数的默认值
//	Func(10); // 传参时，使用指定的实参
//
//	Func1();
//	Func1(1);
//	Func1(1, 2);
//	Func1(1, 2, 3);
//
//	//Func2();
//	Func2(10);
//	Func2(100, 200);
//	Func2(100, 200, 300);
//
//	return 0;
//
//	return 0;
//}
//#include<stdio.h>
//#include<stdlib.h>
//
//#include<iostream>
//using namespace std;
//
//namespace bit
//{
//	int rand = 10;
//
//	int Add(int left,int right)
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
//	//printf("%d\n",bit::Add(1,1));
//
//	cout << bit::Add(1, 1) << endl;
//
//	struct bit::Node p1;
//
//	return 0;
//}


//namespace bit
//{
//	int rand = 10;
//}
//int a = 0;
//
//int main() {
//	printf("%p\n",rand);
//	printf("%d\n", bit::rand);
//
//	int a = 1;
//	printf("%d\n",a);
//
//	// ::域作用限定符
//	printf("%d\n",::a);
//
//	return 0;
//
//}

//int rand = 10;
//
//int main()
//{
//	printf("%d",rand);
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//int main()
//{
//
//	return 0;
//}

//BC7 牛牛的字符矩形
//#include <iostream>
//using namespace std;
//
//int main() {
//    char a;
//    cin >> a;
//    for (int i = 0; i < 3; i++)
//    {
//        for (int j = 0; j < 3; j++)
//        {
//            cout << a;
//        }
//        cout << endl;
//    }
//
//    return 0;
//}
// 64 位输出请用 printf("%lld")
// BC6 牛牛的第二个整数
//#include <iostream>
//using namespace std;
//
//int main() {
//    int a, b, c;
//    while (cin >> a >> b >> c) { // 注意 while 处理多个 case
//        cout << b << endl;
//    }
//}
// 64 位输出请用 printf("%lld")
// BC5 牛牛学说话之-字符
//#include <iostream>
//using namespace std;
//
//int main() {
//    char a;
//    while (cin >> a) { // 注意 while 处理多个 case
//        cout << a << endl;
//    }
//}
// 64 位输出请用 printf("%lld")
//BC4 牛牛学说话之-浮点数
//#include <iostream>
//using namespace std;
//
//int main() {
//    double a;
//    while (cin >> a) { // 注意 while 处理多个 case
//        printf("%0.3lf\n", a);
//    }
//}
// 64 位输出请用 printf("%lld")
// BC3 牛牛学说话之-整数
//#include <iostream>
//using namespace std;
//
//int main() {
//    int a;
//    while (cin >> a) { // 注意 while 处理多个 case
//        cout << a << endl;
//    }
//}
// 64 位输出请用 printf("%lld")
//#include <iostream>
//using namespace std;
//BC2 小飞机
//int main() {
//    cout << "     **     " << endl;
//    cout << "     **     " << endl;
//    cout << "************" << endl;
//    cout << "************" << endl;
//    cout << "    *  *    " << endl;
//    cout << "    *  *    " << endl;
//
//}
// 64 位输出请用 printf("%lld")
// BC1 Hello Nowcoder
//#include <iostream>
//using namespace std;
//
//int main() {
//    cout << "Hello Nowcoder!" << endl;
//}
//// 64 位输出请用 printf("%lld")
