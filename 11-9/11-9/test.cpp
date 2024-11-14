#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;


void test_string3()
{
	string s2("hello world");
	cout << s2.length() << endl;
	cout << s2.size() << endl;

	cout << s2.max_size() << endl;

	cout << s2.capacity() << endl;


	string s3("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
	//cout << sizeof(s2) << endl;
	//cout << sizeof(s3) << endl;
}

//class string
//{
//private:
//	char _buff[16];
//	char*  _str;
//
//	size_t _size;
//	size_t _capacity;
//};


//void test_string2()
//{
//	string s2("hello world");
//	string::iterator it = s2.begin();
//	while (it != s2.end())
//	{
//		*it += 2;
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//
//	string s3("hello world");
//	string::reverse_iterator rit = s3.rbegin();
//	while (rit != s3.rend())
//	{
//		cout << *rit << " ";
//		++rit;
//	}
//	cout << endl;
//
//	const string s4("hello world");
//	//string::const_iterator cit = s3.begin();
//	auto cit = s4.begin();
//	while (cit != s4.end())
//	{
//		//*cit += 2;
//		cout << *cit << " ";
//		++cit;
//	}
//	cout << endl;
//
//	const string s5("hello world");
//	//string::const_reverse_iterator rcit = s3.rbegin();
//	auto rcit = s5.rbegin();
//	while (rcit != s5.rend())
//	{
//		// *rcit += 2;
//		cout << *rcit << " ";
//		++rcit;
//	}
//	cout << endl;
//}
//int main() {
//	test_string2();
//	return 0;
//}

//#include<iostream>
//using namespace std;
//int func1()
//{
//	return 10;
//}
//
//// 不能做参数
//void func2(auto a)
//{}
//
//// 可以做返回值，但是建议谨慎使用
//auto func3()
//{
//	return 3;
//}
//
//
//
//int main()
//{
//	int a = 10;
//	auto b = a;//b是a赋值得到的，b类型是int
//	auto c = 'a';//c类型是char
//	auto d = func1();
//
//	// 编译报错:rror C3531: “e”: 类型包含“auto”的符号必须具有初始值设定项
//	auto e;
//
//	cout << typeid(b).name() << endl;//查看变量的类型
//	cout << typeid(c).name() << endl;
//	cout << typeid(d).name() << endl;
//
//	int x = 10;
//	auto y = &x;//可以推导指针类型
//	auto* z = &x;
//	auto& m = x;
//
//	cout << typeid(x).name() << endl;//查看变量的类型
//	cout << typeid(y).name() << endl;
//	cout << typeid(z).name() << endl;
//
//	auto aa = 1, bb = 2;
//	// 编译报错：error C3538: 在声明符列表中，“auto”必须始终推导为同一类型
//	auto cc = 3, dd = 4.0;
//	// 编译报错：error C3318: “auto []”: 数组不能具有其中包含“auto”的元素类型
//	auto array[] = { 4, 5, 6 };
//
//	return 0;
//}
//
//#include<iostream>
//#include <string>
//#include <map>
//using namespace std;
//int main()
//{
//	std::map<std::string, std::string> dict = { { "apple", "苹果" },{ "orange",
//	"橙子" }, {"pear","梨"} };
//	// auto的用武之地
//	//std::map<std::string, std::string>::iterator it = dict.begin();
//	auto it = dict.begin();
//	while (it != dict.end())
//	{
//		cout << it->first << ":" << it->second << endl;
//		++it;
//	}
//	return 0;
//}



//void Teststring3()
//{
//	// 2、迭代器
//	//string::iterator it = s2.begin();
//	auto it = s2.begin();
//	while (it != s2.end())
//	{
//		*it += 2;
//
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//
//	cout << s2 << endl;
//
//	map<string, string> dict;
//	//map<string, string>::iterator mit = dict.begin();
//	auto mit = dict.begin();
//
//	/*list<int> lt = { 1,2,3,4,5,6,7 };
//	list<int>::iterator lit = lt.begin();
//	while (lit != lt.end())
//	{
//		cout << *lit << " ";
//		++lit;
//	}
//	cout << endl;*/
//}

//int main()
//{
//	string s1;// 构造空的string类对象s1
//	string s2("hello world");// 用C格式字符串构造string类对象s2
//	string s3(s2);// 拷贝构造s3
//
//	cout << s1 << endl;
//	cout << s2 << endl;
//	cout << s3 << endl;
//
//	string s4(s2, 6, 15);//从s2第6个字符开始拷贝5个字符进行构造
//	cout << s4 << endl;
//
//	string s5(s2, 6);//从第6个字符一直拷贝到最后
//	cout << s5 << endl;
//
//	string s6("hello world", 5);//从字符串第5个字符开始拷贝
//	cout << s6 << endl;
//
//	string s7(10, 'X');//用10个X构造
//	cout << s7 << endl;
//
//	return 0;
//}
//namespace zlr
//{
//	template<class T, class Container = vector<T>>
//	class stack
//	{
//	public:
//		void push(const T& x)
//		{
//			_con.push_back(x);
//		}
//
//		void pop()
//		{
//			_con.pop_back();
//		}
//
//		const T& top() const
//		{
//			X++;
//			return _con.func();//没有报错
//		}
//
//		size_t size() const
//		{
//			return _con.size();
//		}
//
//		bool empty() const
//		{
//			return _con.empty();
//		}
//
//	private:
//		Container _con;
//	};
//
//}
//
//int main()
//{
//	bit::stack<int, vector<int>> st;
//	bit::stack<int, list<int>> st;
//	zlr::stack<int, vector<int>> st;
//
//	 类模板实例化时，按需实例化，使用哪些成员函数就实例化哪些，不会全实例化
//	st.push(1);//push会进行实例化
//	st.push(2);
//	st.push(3);
//	st.push(4);
//
//	cout << st.top() << endl;//调用了，检查top内部细节，程序报错
//	st.pop();
//
//	return 0;
//}

//template<typename T>
//class Stack
//{
//public:
//	Stack(int n = 4)
//		:_array(new T[n])
//		,_size(0)
//		,_capacity(n)
//	{}
//
//	~Stack()
//	{
//		delete[] _array;
//		_array = nullptr;
//		_size = _capacity = 0;
//	}
//
//	void Push(const T& x);
//
//private:
//	T* _array;
//	size_t _capacity;
//	size_t _size;
//};

//template<class X>//名称不重要，替换为X也行
//void Stack<X>::Push(const X& x)
//{
//	if (_size == _capacity)
//	{
//		X* tmp = new X[_capacity * 2];
//		memcpy(tmp, _array, sizeof(X) * _size);
//		delete[] _array;
//
//		_array = tmp;
//		_capacity *= 2;
//	}
//
//	_array[_size++] = x;
//}



//int main()
//{
//	// 类模板都是显示实例化
//	Stack<int> st1; // int
//	st1.Push(1);
//	st1.Push(2);
//	st1.Push(3);
//
//	Stack<double> st2; // double
//	st2.Push(1.1);
//	st2.Push(1.1);
//	st2.Push(1.1);
//
//	Stack<double>* pst = new Stack<double>;
//	//...
//	delete pst;
//
//	return 0;
//}



// 用函数模版生成对应的函数 -> 模版的实例化
//template<class t>
//t Add(const t& left, const t& right)
//{
//	return left + right;
//}
//
//template<class T>
//T* func1(int n)
//{
//	return new T[n];
//}
//
//int main()
//{
//	int a1 = 10, a2 = 20;
//	double d1 = 10.1, d2 = 20.2;
//
//	 推导实例化
//	cout << Add(a1, (int)d1) << endl;
//	cout << Add((double)a1, d1) << endl;
//
//	 显示实例化
//	cout << Add<int>(a1, d1) << endl;
//	cout << Add<double>(a1, d1) << endl;
//
//	double* p1 = func1<double>(10);
//
//	return 0;
//}


// //用函数模版生成对应的函数 -> 模版的实例化
//template<class T>
//T Add(const T& left, const T& right)
//{
//	return left + right;
//}
//
//
//
//
//int main()
//{
//	int a1 = 10, a2 = 20;
//	double d1 = 10.1, d2 = 20.2;
//	Add(a1, a2);
//	Add(d1, d2);
//
//
//
//	return 0;
//}
//
//
//
//template<class T>
//T Add(const T& left, const T& right)
//{
//	return left + right;
//}
//int main()
//{
//	int a1 = 10, a2 = 20;
//	double d1 = 10.0, d2 = 20.0;
//	Add(a1, a2);
//	Add(d1, d2);
//	/*
//	该语句不能通过编译，因为在编译期间，当编译器看到该实例化时，需要推演其实参类型
//	通过实参a1将T推演为int，通过实参d1将T推演为double类型，但模板参数列表中只有
//	一个T，
//	编译器无法确定此处到底该将T确定为int 或者 double类型而报错
//	注意：处于安全、可读性等考量，在模板中，编译器一般不会进行类型转换操作，
//*/
//// 此时有两种处理方式：1. 用户自己来强制转化 2. 使用显式实例化(下文介绍)
//	Add(a1, (int)d2);
//	return 0;
//}
//
//template<class T1, class T2>
//T1 Add(const T1& left, const T2& right)
//{
//	return left + right;
//}
//
//int main()
//{
//	int a1 = 10, a2 = 20;
//	double d1 = 10.1, d2 = 20.2;
//	Add(a1, a2);//定义多种模板类型之后,参数既可以是同一类型的也可以是不同类型的
//	Add(d1, d2);
//
//	return 0;
//}
//
//
//
//
//template<class T>
//T* func1(int n)
//{
//	return new T[n];
//}
//
//// 推导实例化
//cout << Add(a1, (int)d1) << endl;
//cout << Add((double)a1, d1) << endl;
//
//// 显示实例化
//cout << Add<int>(a1, d1) << endl;
//cout << Add<double>(a1, d1) << endl;
//
//cout << Add(a1, d1) << endl;
//
//double* p1 = func1<double>(10);

////模版类型
//template<class T>
//void Swap(T& x, T& y)
//{
//	T tmp = x;
//	x = y;
//	y = tmp;
//}
//
//template<typename T>
//void Swap(T& x, T& y)
//{
//	T tmp = x;
//	x = y;
//	y = tmp;
//}
//
//template<class T1, typename T2>
//void func(const T1& x, const T2& y)
//{
//	//………………
//}
//
//template<class A, class B>
//void func(const A& x, const B& y)
//{
//	//………………
//}

//#define _CRT_SECURE_NO_WARNINGS 1
//#pragma once
//
//#include<iostream>
//#include<string>
//#include<assert.h>
//using namespace std;
//
//namespace bit {
//	class string {
//	public:
//		typedef char* iterator;
//		typedef const char* const_iterator;
//
//		iterator begin() {
//			return _str;
//		}
//
//		iterator end() {
//			return _str + _size;
//		}
//
//		const_iterator beign() const {
//			return _str;
//		}
//
//		const_iterator end() cosnt {
//			return _str + _size;
//		}
//
//		string(const char* str = "") {
//			_size = strlen(str);
//
//			_capacity = _size;
//			_str = new char[_capacity + 1];
//			strcpy(_str, str);
//		}
//
//		void swap(string& s) {
//			std::swap(_str, s._str);
//			std::swap(_size, s._size);
//			std::swap(_str, s._capacity);
//		}
//
//		string(const string& s) {
//			string tmp(s._str);
//			swap(tmp);
//		}
//
//		string& operator=(const string& s) {
//			if (this != &s) {
//				delete[] _str;
//
//				_str = new char[s.capacity + 1];
//				strcpy(_str, s._str);
//				_size = s.size;
//				_capacity = s._capacity;
//			}
//
//			return *this;
//		}
//
//		string& operator=(string tmp) {
//			swap(tmp);
//
//			return *this;
//		}
//
//		~string() {
//			if (_str) {
//				delete[] _str;
//				_str = nullptr;
//				_size = _capcity = 0;
//
//			}
//		}
//
//		const char* c_str() const {
//			return _str;
//		}
//
//		void clear() {
//			_str[0] = '\0';
//			_size = 0;
//		}
//
//		size_t size() const {
//			return _size;
//		}
//
//		size_t capacity() const {
//			return _capacity;
//		}
//
//		char& operator[](size_t pos) {
//			assert(pos < _size);
//
//			return _str[pos];
//		}
//
//		const char& operator[])(size_t pos) const{
//			assert(pos < _size);
//
//			return _str[pos];
//		}
//
//
//
//	};
//}