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
//	// ����ͨ��f(NULL)����ָ��汾��f(int*)��������������NULL�������0��������f(int
//	//x)����������ĳ�����㣡�
//	f(NULL);
//	f((int*)NULL);
//	// ���뱨��error C2665: ��f��: 2 ��������û��һ������ת�����в�������
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
//// ʵ��һ��ADD�꺯���ĳ�������
////#define ADD(int a, int b) return a + b;
////#define ADD(a, b) a + b;
////#define ADD(a, b) (a + b)
//// ��ȷ�ĺ�ʵ��
//#define ADD(a, b) ((a) + (b))
//// Ϊʲô���ܼӷֺ�?
//// ΪʲôҪ�����������?
//// ΪʲôҪ�����������?
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
//{// ���Ӵ����޷��������ⲿ���� "void __cdecl f(int)" (?f@@YAXH@Z)
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
//	// ����ͨ�����۲�����Ƿ�չ��
//	// ��call Add������û��չ����û�о���չ����
//	int ret = Add(1, 2);
//	cout << Add(1, 2) * 5 << endl;
//	return 0;
//}
//int main()
//{
//	const int a = 10;
//	// ���뱨��error C2440: ����ʼ����: �޷��ӡ�const int��ת��Ϊ��int &��
//	// ����������Ƕ�a����Ȩ�޵ķŴ�
//	//int& ra = a;
//	// �����ſ���
//	const int& ra = a;
//	// ���뱨��error C3892: ��ra��: ���ܸ�������ֵ
//	//ra++;
//	// ����������Ƕ�b����Ȩ�޵���С
//	int b = 20;
//	const int& rb = b;
//	// ���뱨��error C3892: ��rb��: ���ܸ�������ֵ
//	//rb++;
//	return 0;
//}
//#include<iostream>
//using namespace std;
//int main()
//{
//	int a = 10;
//	const int& ra = 30;
//	// ���뱨��: ����ʼ����: �޷��ӡ�int��ת��Ϊ��int &��
//	// int& rb = a * 3;
//	const int& rb = a * 3;
//	double d = 12.34;
//	// ���뱨������ʼ����: �޷��ӡ�double��ת��Ϊ��int &��
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
//// ջ��
//void STPush(ST& rs, STDataType x)
//{
//	assert(ps);
//	// ���ˣ� ����
//	if (rs.top == rs.capacity)
//	{
//		printf("����\n");
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
//	// ����ȫ�ֵ�
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
//// һЩ��Ҫ��C����ʵ�ְ汾���ݽṹ�̲��У�ʹ��C++�������ָ�봫�Σ�Ŀ���Ǽ򻯳��򣬱ܿ���
//�ӵ�ָ�룬���Ǻܶ�ͬѧûѧ�����ã�����һͷ��ˮ��
//void SeqPushBack(SLT& sl, int x)
//{}
//typedef struct ListNode
//{
//	int val;
//	struct ListNode* next;
//}LTNode, * PNode;
//// ָ�����Ҳ����ȡ����������LTNode*& phead���Ǹ�ָ�����ȡ����
//// �����Ͳ���Ҫ�ö���ָ���ˣ���Զ��Լ��˳���
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
//	// ���뱨����ra��: �����ʼ������
//	//int& ra;
//	int& b = a;
//	int c = 20;
//	// ���ﲢ����b����c����ΪC++���ò��ܸı�ָ��
//	// ������һ����ֵ
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
//	// ���ã�b��c��a�ı���
//	int& b = a;
//	int& c = a;
//	// Ҳ���Ը�����bȡ������d�൱�ڻ���a�ı���
//	int& d = b;
//	++d;
//	// ����ȡ��ַ���ǿ�����һ����
//	cout << &a << endl;
//	cout << &b << endl;
//	cout << &c << endl;
//	cout << &d << endl;
//	return 0;
//}

//#include<iostream>
//using namespace std;
//// 1���������Ͳ�ͬ
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
//// 2������������ͬ
//void f()
//{
//	cout << "f()" << endl;
//}
//void f(int a)
//{
//	cout << "f(int a)" << endl;
//}
//// 3����������˳��ͬ
//void f(int a, char b)
//{
//	cout << "f(int a,char b)" << endl;
//}
//void f(char b, int a)
//{
//	cout << "f(char b, int a)" << endl;
//}
//// ����ֵ��ͬ������Ϊ������������Ϊ����ʱҲ�޷�����
////void fxx()
////{}
////
////int fxx()
////{
//// return 0;
////}
//// ��������������������
//// f()���ǵ���ʱ���ᱨ���������壬��������֪������˭
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
//	Func(); // û�д���ʱ��ʹ�ò�����Ĭ��ֵ
//	Func(10); // ����ʱ��ʹ��ָ����ʵ��
//	return 0;
//}
//#include <iostream>
//using namespace std;
//// ȫȱʡ
//void Func1(int a = 10, int b = 20, int c = 30)
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl << endl;
//}
//// ��ȱʡ
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
//// ȱʡ�������������Ͷ���ͬʱ��
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
//	// ȷ��֪��Ҫ����1000�����ݣ���ʼ��ʱһ�ѿ��ã���������
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
//	// �����Զ�ʶ�����������
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
//	// ��io����Ƚϸߵĵط����粿�ִ�������ľ������У���������3�д���
//	// �������C++IOЧ��
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





