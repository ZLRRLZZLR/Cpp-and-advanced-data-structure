#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <list>
#include <vector>
#include<algorithm>
using namespace std;

#include"list.h"


//栈的压入与弹出序列
//class Solution {
//public:
//    /**
//     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//     *
//     *
//     * @param pushV int整型vector
//     * @param popV int整型vector
//     * @return bool布尔型
//     */
//    bool IsPopOrder(vector<int>& pushV, vector<int>& popV) {
//        stack<int> st;
//        size_t pos = 0;
//        for (auto e : pushV)
//        {
//            st.push(e);
//
//            while (!st.empty() && st.top() == popV[pos])
//            {
//                st.pop();
//                pos++;
//            }
//        }
//
//        return pos == popV.size();
//    }
//};


//最小栈
//class MinStack {
//public:
//    MinStack() {
//
//    }
//
//    void push(int val) {
//        if (_minst.empty() || val <= _minst.top())
//        {
//            _minst.push(val);
//        }
//
//        _st.push(val);
//    }
//
//    void pop() {
//        if (_st.top() == _minst.top())
//        {
//            _minst.pop();
//        }
//
//        _st.pop();
//
//    }
//
//    int top() {
//        return _st.top();
//    }
//
//    int getMin() {
//        return _minst.top();
//    }
//
//private:
//    stack<int> _st;
//    stack<int> _minst;
//};
//
///**
// * Your MinStack object will be instantiated and called as such:
// * MinStack* obj = new MinStack();
// * obj->push(val);
// * obj->pop();
// * int param_3 = obj->top();
// * int param_4 = obj->getMin();
// */

//二叉树的层序遍历
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     TreeNode *left;
// *     TreeNode *right;
// *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
// *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// * };
// */
//class Solution {
//public:
//    vector<vector<int>> levelOrder(TreeNode* root) {
//        vector<vector<int>> vv;
//        queue<TreeNode*> q;
//        int levelsize = 0;
//
//        if (root)
//        {
//            q.push(root);
//            levelsize = 1;
//        }
//
//        while (!q.empty())
//        {
//            vector<int> v;
//            while (levelsize--)
//            {
//                TreeNode* front = q.front();
//                q.pop();
//                v.push_back(front->val);
//
//                if (front->left)
//                {
//                    q.push(front->left);
//                }
//
//                if (front->right)
//                {
//                    q.push(front->right);
//                }
//
//            }
//
//            vv.push_back(v);
//            levelsize = q.size();
//
//        }
//
//        return vv;
//    }
//};

//void test_list1()
//{
//	list<int> lt;
//	lt.push_back(1);
//
//	list<int>::iterator it = lt.begin();
//	while(it != lt.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//
//	for(auto e : lt)
//	{
//		cout << e << " ";
//
//	}
//	cout << endl;
//
//	string s("dadawdfadsa");
//	cout << s << endl;
//	sort(s.begin(), s.end());
//	cout << s << endl;
//}
//struct A
//{
//public:
//	A(int a1 = 1,int a2 = 1)
//		:_a1(a1)
//		,_a2(a2)
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
//	int _a1;
//	int _a2;
//};
//
//void test_list2()
//{
//	list<A> lt;
//	A aa1(1, 1);
//	lt.push_back(aa1);
//	lt.push_back(A(2, 2));
//
//	lt.emplace_back(aa1);
//	lt.emplace_back(A(2,2));
//	cout << endl;
//
//	lt.emplace_back(3, 3);
//
//}
//
//void test_list3()
//{
//	list<int> lt;
//	lt.push_back(1);
//	lt.push_back(2);
//	lt.push_back(3);
//	lt.push_back(4);
//	lt.push_back(5);
//	lt.push_back(6);
//
//	for(auto e : lt)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	auto it = lt.begin();
//	int k = 3;
//	while(k--)
//	{
//		++it;
//	}
//
//	lt.insert(it, 30);
//
//	int x = 0;
//	cin >> x;
//	it = find(lt.begin(), lt.end(), x);
//	if(it != lt.end())
//	{
//		lt.erase(it);
//	}
//
//	for(auto e : lt)
//	{
//		cout << e << "";
//	}
//	cout << endl;
//
//}
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
//	for(auto e :lt)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	lt.sort(greater<int>());
//
//	for(auto e : lt)
//	{
//		cout << e << " ";
//	}
//
//	cout << endl;
//
//	std::list<double> first, second;
//
//	first.sort();
//
//	first.merge(second);
//
//}

//void test_list5()
//{
//	list<int> lt;
//	lt.push_back(1);
//	lt.push_back(1);
//	lt.push_back(1);
//	lt.push_back(1);
//	lt.push_back(1);
//
//	lt.sort();
//	for(auto e : lt)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	lt.unique();
//
//	lt.splice(lt.begin(), lt, it, lt.end());
//
//}

//void test_list6()
//{
//	std::list<int> mylist, mylist2;
//
//	mylist1.splice(it, mylist2);
//}





//int main()
//{
//	zlr::Test_01();
//	return 0;
//}



//////////////////////////////////////////////////////////////
//// list的构造
//void TestList1()
//{
//	list<int> l1;                         // 构造空的l1
//	list<int> l2(4, 100);                 // l2中放4个值为100的元素
//	list<int> l3(l2.begin(), l2.end());  // 用l2的[begin(), end()）左闭右开的区间构造l3
//	list<int> l4(l3);                    // 用l3拷贝构造l4
//
//	// 以数组为迭代器区间构造l5
//	int array[] = { 16,2,77,29 };
//	list<int> l5(array, array + sizeof(array) / sizeof(int));
//
//	// 列表格式初始化C++11
//	list<int> l6{ 1,2,3,4,5 };
//
//	// 用迭代器方式打印l5中的元素
//	list<int>::iterator it = l5.begin();
//	while (it != l5.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//
//	// C++11范围for的方式遍历
//	for (auto& e : l5)
//		cout << e << " ";
//
//	cout << endl;
//}
//
//////////////////////////////////////////////////////////////
//// list迭代器的使用
//// 注意：遍历链表只能用迭代器和范围for
//void PrintList(const list<int>& l)
//{
//	// 注意这里调用的是list的 begin() const，返回list的const_iterator对象
//	for (list<int>::const_iterator it = l.begin(); it != l.end(); ++it)
//	{
//		cout << *it << " ";
//		// *it = 10; 编译不通过
//	}
//
//	cout << endl;
//}
//
//void TestList2()
//{
//	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
//	list<int> l(array, array + sizeof(array) / sizeof(array[0]));
//	// 使用正向迭代器正向list中的元素
//	// list<int>::iterator it = l.begin();   // C++98中语法
//	auto it = l.begin();                     // C++11之后推荐写法
//	while (it != l.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//
//	// 使用反向迭代器逆向打印list中的元素
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
//// list插入和删除
//// push_back/pop_back/push_front/pop_front
//void TestList3()
//{
//	int array[] = { 1, 2, 3 };
//	list<int> L(array, array + sizeof(array) / sizeof(array[0]));
//
//	// 在list的尾部插入4，头部插入0
//	L.push_back(4);
//	L.push_front(0);
//	PrintList(L);
//
//	// 删除list尾部节点和头部节点
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
//	// 获取链表中第二个节点
//	auto pos = ++L.begin();
//	cout << *pos << endl;
//
//	// 在pos前插入值为4的元素
//	L.insert(pos, 4);
//	PrintList(L);
//
//	// 在pos前插入5个值为5的元素
//	L.insert(pos, 5, 5);
//	PrintList(L);
//
//	// 在pos前插入[v.begin(), v.end)区间中的元素
//	vector<int> v{ 7, 8, 9 };
//	L.insert(pos, v.begin(), v.end());
//	PrintList(L);
//
//	// 删除pos位置上的元素
//	L.erase(pos);
//	PrintList(L);
//
//	// 删除list中[begin, end)区间中的元素，即删除list中的所有元素
//	L.erase(L.begin(), L.end());
//	PrintList(L);
//}
//
//// resize/swap/clear
//void TestList5()
//{
//	// 用数组来构造list
//	int array1[] = { 1, 2, 3 };
//	list<int> l1(array1, array1 + sizeof(array1) / sizeof(array1[0]));
//	PrintList(l1);
//
//	// 交换l1和l2中的元素
//	list<int> l2;
//	l1.swap(l2);
//	PrintList(l1);
//	PrintList(l2);
//
//	// 将l2中的元素清空
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
//	// 不支持，要求随机迭代器
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
//	// 升序
//	// lt.sort();
//	// 降序 - 仿函数
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
//	// 一个链表节点转移给另一个链表
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
//// 调整当前链表节点的顺序
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
//	// 排序
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
//	// 拷贝vector
//	vector<int> v(lt2.begin(), lt2.end());
//
//	// 排序
//	sort(v.begin(), v.end());
//
//	// 拷贝回lt2
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
//	// 注意：此处typename的作用是明确告诉编译器，Ref是Iterator类中的类型，而不是静态
//	成员变量
//		// 否则编译器编译时就不知道Ref是Iterator中的类型还是静态成员变量
//		// 因为静态成员变量也是按照 类名::静态成员变量名 的方式访问的
//public:
//	typedef typename Iterator::Ref Ref;
//	typedef typename Iterator::Ptr Ptr;
//	typedef ReverseListIterator<Iterator> Self;
//public:
//	//////////////////////////////////////////////
//	// 构造
//	ReverseListIterator(Iterator it) : _it(it) {}
//	//////////////////////////////////////////////
//	// 具有指针类似行为
//	Ref operator*() {
//		Iterator temp(_it);
//		--temp;
//		return *temp;
//	}
//	Ptr operator->() { return &(operator*()); }
//	//////////////////////////////////////////////
//	// 迭代器支持移动
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
//	// 迭代器支持比较
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
//		// erase()函数执行后，it所指向的节点已被删除，因此it无效，在下一次使用it时，必须先给
//		其赋值
//			l.erase(it);
//		++it;
//	}
//}
//// 改正
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




//// 迭代器支持比较
//bool operator!=(const Self& l)const { return _it != l._it; }
//bool operator==(const Self& l)const { return _it != l._it; }
//Iterator _it;
//};
//template<class Iterator>
//class ReverseListIterator
//{
//	// 注意：此处typename的作用是明确告诉编译器，Ref是Iterator类中的类型，而不是静态
//	成员变量
//		// 否则编译器编译时就不知道Ref是Iterator中的类型还是静态成员变量
//		// 因为静态成员变量也是按照 类名::静态成员变量名 的方式访问的
//public:
//	typedef typename Iterator::Ref Ref;
//	typedef typename Iterator::Ptr Ptr;
//	typedef ReverseListIterator<Iterator> Self;
//public:
//	//////////////////////////////////////////////
//	// 构造
//	ReverseListIterator(Iterator it) : _it(it) {}
//	//////////////////////////////////////////////
//	// 具有指针类似行为
//	Ref operator*() {
//		Iterator temp(_it);
//		--temp;
//		return *temp;
//	}
//	Ptr operator->() { return &(operator*()); }
//	//////////////////////////////////////////////
//	// 迭代器支持移动
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
//		// erase()函数执行后，it所指向的节点已被删除，因此it无效，在下一次使用it时，必须先给
//		其赋值
//			l.erase(it);
//		++it;
//	}
//}
//// 改正
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