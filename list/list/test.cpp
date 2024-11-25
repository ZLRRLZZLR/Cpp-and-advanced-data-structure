#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <list>
#include <vector>

#include"list.h"


int main()
{
	zlr::Test_01();
	return 0;
}



//////////////////////////////////////////////////////////////
//// list�Ĺ���
//void TestList1()
//{
//	list<int> l1;                         // ����յ�l1
//	list<int> l2(4, 100);                 // l2�з�4��ֵΪ100��Ԫ��
//	list<int> l3(l2.begin(), l2.end());  // ��l2��[begin(), end()������ҿ������乹��l3
//	list<int> l4(l3);                    // ��l3��������l4
//
//	// ������Ϊ���������乹��l5
//	int array[] = { 16,2,77,29 };
//	list<int> l5(array, array + sizeof(array) / sizeof(int));
//
//	// �б��ʽ��ʼ��C++11
//	list<int> l6{ 1,2,3,4,5 };
//
//	// �õ�������ʽ��ӡl5�е�Ԫ��
//	list<int>::iterator it = l5.begin();
//	while (it != l5.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//
//	// C++11��Χfor�ķ�ʽ����
//	for (auto& e : l5)
//		cout << e << " ";
//
//	cout << endl;
//}
//
//////////////////////////////////////////////////////////////
//// list��������ʹ��
//// ע�⣺��������ֻ���õ������ͷ�Χfor
//void PrintList(const list<int>& l)
//{
//	// ע��������õ���list�� begin() const������list��const_iterator����
//	for (list<int>::const_iterator it = l.begin(); it != l.end(); ++it)
//	{
//		cout << *it << " ";
//		// *it = 10; ���벻ͨ��
//	}
//
//	cout << endl;
//}
//
//void TestList2()
//{
//	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
//	list<int> l(array, array + sizeof(array) / sizeof(array[0]));
//	// ʹ���������������list�е�Ԫ��
//	// list<int>::iterator it = l.begin();   // C++98���﷨
//	auto it = l.begin();                     // C++11֮���Ƽ�д��
//	while (it != l.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//
//	// ʹ�÷�������������ӡlist�е�Ԫ��
//	// list<int>::reverse_iterator rit = l.rbegin();
//	auto rit = l.rbegin();
//	while (rit != l.rend())
//	{
//		cout << *rit << " ";
//		++rit;
//	}
//	cout << endl;
//}
//
//////////////////////////////////////////////////////////////
//// list�����ɾ��
//// push_back/pop_back/push_front/pop_front
//void TestList3()
//{
//	int array[] = { 1, 2, 3 };
//	list<int> L(array, array + sizeof(array) / sizeof(array[0]));
//
//	// ��list��β������4��ͷ������0
//	L.push_back(4);
//	L.push_front(0);
//	PrintList(L);
//
//	// ɾ��listβ���ڵ��ͷ���ڵ�
//	L.pop_back();
//	L.pop_front();
//	PrintList(L);
//}
//
//// insert /erase 
//void TestList4()
//{
//	int array1[] = { 1, 2, 3 };
//	list<int> L(array1, array1 + sizeof(array1) / sizeof(array1[0]));
//
//	// ��ȡ�����еڶ����ڵ�
//	auto pos = ++L.begin();
//	cout << *pos << endl;
//
//	// ��posǰ����ֵΪ4��Ԫ��
//	L.insert(pos, 4);
//	PrintList(L);
//
//	// ��posǰ����5��ֵΪ5��Ԫ��
//	L.insert(pos, 5, 5);
//	PrintList(L);
//
//	// ��posǰ����[v.begin(), v.end)�����е�Ԫ��
//	vector<int> v{ 7, 8, 9 };
//	L.insert(pos, v.begin(), v.end());
//	PrintList(L);
//
//	// ɾ��posλ���ϵ�Ԫ��
//	L.erase(pos);
//	PrintList(L);
//
//	// ɾ��list��[begin, end)�����е�Ԫ�أ���ɾ��list�е�����Ԫ��
//	L.erase(L.begin(), L.end());
//	PrintList(L);
//}
//
//// resize/swap/clear
//void TestList5()
//{
//	// ������������list
//	int array1[] = { 1, 2, 3 };
//	list<int> l1(array1, array1 + sizeof(array1) / sizeof(array1[0]));
//	PrintList(l1);
//
//	// ����l1��l2�е�Ԫ��
//	list<int> l2;
//	l1.swap(l2);
//	PrintList(l1);
//	PrintList(l2);
//
//	// ��l2�е�Ԫ�����
//	l2.clear();
//	cout << l2.size() << endl;
//}
//
//#include<iostream>
//#include<algorithm>
//#include<list>
//#include<vector>
//using namespace std;
//
//void test_list1()
//{
//	list<int> lt;
//	lt.push_back(1);
//	lt.push_back(2);
//	lt.push_back(3);
//	lt.push_back(4);
//
//	list<int>::iterator it = lt.begin();
//	while (it != lt.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//
//	for (auto e : lt)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	/*it = lt.begin();
//	lt.erase(it + 3);*/
//
//	// ��֧�֣�Ҫ�����������
//	//sort(lt.begin(), lt.end());
//
//	string s("dadawdfadsa");
//	cout << s << endl;
//	sort(s.begin(), s.end());
//	cout << s << endl;
//}
//
//struct A
//{
//public:
//	A(int a1 = 1, int a2 = 1)
//		:_a1(a1)
//		, _a2(a2)
//	{
//		cout << "A(int a1 = 1, int a2 = 1)" << endl;
//	}
//
//	A(const A& aa)
//		:_a1(aa._a1)
//		, _a2(aa._a2)
//	{
//		cout << "A(const A& aa)" << endl;
//	}
//
//	int _a1;
//	int _a2;
//};
//
//
//void test_list4()
//{
//	list<int> lt;
//	lt.push_back(1);
//	lt.push_back(20);
//	lt.push_back(3);
//	lt.push_back(5);
//	lt.push_back(4);
//	lt.push_back(5);
//	lt.push_back(6);
//
//	for (auto e : lt)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	// ����
//	// lt.sort();
//	// ���� - �º���
//	// less<int> ls;
//	// greater<int> gt;
//	// lt.sort(gt);
//	lt.sort(greater<int>());
//
//	// lt.reverse();
//	//reverse(lt.begin(), lt.end());
//
//	for (auto e : lt)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	std::list<double> first, second;
//
//	first.push_back(3.1);
//	first.push_back(2.2);
//	first.push_back(2.9);
//
//	second.push_back(3.7);
//	second.push_back(7.1);
//	second.push_back(1.4);
//
//	first.sort();
//	second.sort();
//
//	first.merge(second);
//}
//
//void test_list5()
//{
//	list<int> lt;
//	lt.push_back(1);
//	lt.push_back(20);
//	lt.push_back(3);
//	lt.push_back(5);
//	lt.push_back(5);
//	lt.push_back(4);
//	lt.push_back(5);
//	lt.push_back(6);
//
//	lt.sort();
//	for (auto e : lt)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	lt.unique();
//	for (auto e : lt)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//}
//
//void test_list6()
//{
//	// һ������ڵ�ת�Ƹ���һ������
//	std::list<int> mylist1, mylist2;
//	std::list<int>::iterator it;
//
//	// set some initial values:
//	for (int i = 1; i <= 4; ++i)
//		mylist1.push_back(i);      // mylist1: 1 2 3 4
//
//	for (int i = 1; i <= 3; ++i)
//		mylist2.push_back(i * 10);   // mylist2: 10 20 30
//
//	it = mylist1.begin();
//	++it;                         // points to 2
//
//	mylist1.splice(it, mylist2); // mylist1: 1 10 20 30 2 3 4
//	// mylist2 (empty)
//	// "it" still points to 2 (the 5th element
//
//
//// ������ǰ����ڵ��˳��
//	list<int> lt;
//	lt.push_back(1);
//	lt.push_back(2);
//	lt.push_back(3);
//	lt.push_back(4);
//	lt.push_back(5);
//	lt.push_back(6);
//	for (auto e : lt)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	int x = 0;
//	cin >> x;
//	it = find(lt.begin(), lt.end(), x);
//	if (it != lt.end())
//	{
//		//lt.splice(lt.begin(), lt, it);
//		lt.splice(lt.begin(), lt, it, lt.end());
//	}
//
//	for (auto e : lt)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//}
//
//void test_op1()
//{
//	srand(time(0));
//	const int N = 1000000;
//
//	list<int> lt1;
//	vector<int> v;
//
//	for (int i = 0; i < N; ++i)
//	{
//		auto e = rand() + i;
//		lt1.push_back(e);
//		v.push_back(e);
//	}
//
//	int begin1 = clock();
//	// ����
//	sort(v.begin(), v.end());
//	int end1 = clock();
//
//	int begin2 = clock();
//	lt1.sort();
//	int end2 = clock();
//
//	printf("vector sort:%d\n", end1 - begin1);
//	printf("list sort:%d\n", end2 - begin2);
//}
//
//void test_op2()
//{
//	srand(time(0));
//	const int N = 1000000;
//
//	list<int> lt1;
//	list<int> lt2;
//
//	for (int i = 0; i < N; ++i)
//	{
//		auto e = rand() + i;
//		lt1.push_back(e);
//		lt2.push_back(e);
//	}
//
//	int begin1 = clock();
//	// ����vector
//	vector<int> v(lt2.begin(), lt2.end());
//
//	// ����
//	sort(v.begin(), v.end());
//
//	// ������lt2
//	lt2.assign(v.begin(), v.end());
//
//	int end1 = clock();
//
//	int begin2 = clock();
//	lt1.sort();
//	int end2 = clock();
//
//	printf("list copy vector sort copy list sort:%d\n", end1 - begin1);
//	printf("list sort:%d\n", end2 - begin2);
//}
//
//#include"List.h"
//
//// 10:35
//int main()
//{
//	//test_list6();
//	//test_op2();
//
//	bit::test_list1();
//
//	return 0;
//}




//template<class Iterator>
//class ReverseListIterator
//{
//	// ע�⣺�˴�typename����������ȷ���߱�������Ref��Iterator���е����ͣ������Ǿ�̬
//	��Ա����
//		// �������������ʱ�Ͳ�֪��Ref��Iterator�е����ͻ��Ǿ�̬��Ա����
//		// ��Ϊ��̬��Ա����Ҳ�ǰ��� ����::��̬��Ա������ �ķ�ʽ���ʵ�
//public:
//	typedef typename Iterator::Ref Ref;
//	typedef typename Iterator::Ptr Ptr;
//	typedef ReverseListIterator<Iterator> Self;
//public:
//	//////////////////////////////////////////////
//	// ����
//	ReverseListIterator(Iterator it) : _it(it) {}
//	//////////////////////////////////////////////
//	// ����ָ��������Ϊ
//	Ref operator*() {
//		Iterator temp(_it);
//		--temp;
//		return *temp;
//	}
//	Ptr operator->() { return &(operator*()); }
//	//////////////////////////////////////////////
//	// ������֧���ƶ�
//	Self& operator++() {
//		--_it;
//		return *this;
//	}
//	Self operator++(int) {
//		Self temp(*this);
//		--_it;
//		return temp;
//	}
//	Self& operator--() {
//		++_it;
//		return *this;
//	}
//	Self operator--(int)
//	{
//		Self temp(*this);
//		++_it;
//		return temp;
//	}
//	//////////////////////////////////////////////
//	// ������֧�ֱȽ�
//	bool operator!=(const Self& l)const { return _it != l._it; }
//	bool operator==(const Self& l)const { return _it != l._it; }
//	Iterator _it;
//};




//void TestListIterator1()
//{
//	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
//	list<int> l(array, array + sizeof(array) / sizeof(array[0]));
//	auto it = l.begin();
//	while (it != l.end())
//	{
//		// erase()����ִ�к�it��ָ��Ľڵ��ѱ�ɾ�������it��Ч������һ��ʹ��itʱ�������ȸ�
//		�丳ֵ
//			l.erase(it);
//		++it;
//	}
//}
//// ����
//void TestListIterator()
//{
//	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
//	list<int> l(array, array + sizeof(array) / sizeof(array[0]));
//	auto it = l.begin();
//	while (it != l.end())
//	{
//		l.erase(it++); // it = l.erase(it);
//	}
//}




//// ������֧�ֱȽ�
//bool operator!=(const Self& l)const { return _it != l._it; }
//bool operator==(const Self& l)const { return _it != l._it; }
//Iterator _it;
//};
//template<class Iterator>
//class ReverseListIterator
//{
//	// ע�⣺�˴�typename����������ȷ���߱�������Ref��Iterator���е����ͣ������Ǿ�̬
//	��Ա����
//		// �������������ʱ�Ͳ�֪��Ref��Iterator�е����ͻ��Ǿ�̬��Ա����
//		// ��Ϊ��̬��Ա����Ҳ�ǰ��� ����::��̬��Ա������ �ķ�ʽ���ʵ�
//public:
//	typedef typename Iterator::Ref Ref;
//	typedef typename Iterator::Ptr Ptr;
//	typedef ReverseListIterator<Iterator> Self;
//public:
//	//////////////////////////////////////////////
//	// ����
//	ReverseListIterator(Iterator it) : _it(it) {}
//	//////////////////////////////////////////////
//	// ����ָ��������Ϊ
//	Ref operator*() {
//		Iterator temp(_it);
//		--temp;
//		return *temp;
//	}
//	Ptr operator->() { return &(operator*()); }
//	//////////////////////////////////////////////
//	// ������֧���ƶ�
//	Self& operator++() {
//		--_it;
//		return *this;
//	}
//	Self operator++(int) {
//		Self temp(*this);
//		--_it;
//		return temp;
//	}
//	Self& operator--() {
//		++_it;
//		return *this;
//	}
//	Self operator--(int)
//	{
//		Self temp(*this);
//		++_it;
//		return temp;
//	}
//	//////////////////////////////////////////////

//void TestListIterator1()
//{
//	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
//	list<int> l(array, array + sizeof(array) / sizeof(array[0]));
//	auto it = l.begin();
//	while (it != l.end())
//	{
//		// erase()����ִ�к�it��ָ��Ľڵ��ѱ�ɾ�������it��Ч������һ��ʹ��itʱ�������ȸ�
//		�丳ֵ
//			l.erase(it);
//		++it;
//	}
//}
//// ����
//void TestListIterator()
//{
//	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
//	list<int> l(array, array + sizeof(array) / sizeof(array[0]));
//	auto it = l.begin();
//	while (it != l.end())
//	{
//		l.erase(it++); // it = l.erase(it);
//	}
//}