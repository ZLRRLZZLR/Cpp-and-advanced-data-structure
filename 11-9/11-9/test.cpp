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
//// ����������
//void func2(auto a)
//{}
//
//// ����������ֵ�����ǽ������ʹ��
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
//	auto b = a;//b��a��ֵ�õ��ģ�b������int
//	auto c = 'a';//c������char
//	auto d = func1();
//
//	// ���뱨��:rror C3531: ��e��: ���Ͱ�����auto���ķ��ű�����г�ʼֵ�趨��
//	auto e;
//
//	cout << typeid(b).name() << endl;//�鿴����������
//	cout << typeid(c).name() << endl;
//	cout << typeid(d).name() << endl;
//
//	int x = 10;
//	auto y = &x;//�����Ƶ�ָ������
//	auto* z = &x;
//	auto& m = x;
//
//	cout << typeid(x).name() << endl;//�鿴����������
//	cout << typeid(y).name() << endl;
//	cout << typeid(z).name() << endl;
//
//	auto aa = 1, bb = 2;
//	// ���뱨��error C3538: ���������б��У���auto������ʼ���Ƶ�Ϊͬһ����
//	auto cc = 3, dd = 4.0;
//	// ���뱨��error C3318: ��auto []��: ���鲻�ܾ������а�����auto����Ԫ������
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
//	std::map<std::string, std::string> dict = { { "apple", "ƻ��" },{ "orange",
//	"����" }, {"pear","��"} };
//	// auto������֮��
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
//	// 2��������
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
//	string s1;// ����յ�string�����s1
//	string s2("hello world");// ��C��ʽ�ַ�������string�����s2
//	string s3(s2);// ��������s3
//
//	cout << s1 << endl;
//	cout << s2 << endl;
//	cout << s3 << endl;
//
//	string s4(s2, 6, 15);//��s2��6���ַ���ʼ����5���ַ����й���
//	cout << s4 << endl;
//
//	string s5(s2, 6);//�ӵ�6���ַ�һֱ���������
//	cout << s5 << endl;
//
//	string s6("hello world", 5);//���ַ�����5���ַ���ʼ����
//	cout << s6 << endl;
//
//	string s7(10, 'X');//��10��X����
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
//			return _con.func();//û�б���
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
//	 ��ģ��ʵ����ʱ������ʵ������ʹ����Щ��Ա������ʵ������Щ������ȫʵ����
//	st.push(1);//push�����ʵ����
//	st.push(2);
//	st.push(3);
//	st.push(4);
//
//	cout << st.top() << endl;//�����ˣ����top�ڲ�ϸ�ڣ����򱨴�
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

//template<class X>//���Ʋ���Ҫ���滻ΪXҲ��
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
//	// ��ģ�嶼����ʾʵ����
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



// �ú���ģ�����ɶ�Ӧ�ĺ��� -> ģ���ʵ����
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
//	 �Ƶ�ʵ����
//	cout << Add(a1, (int)d1) << endl;
//	cout << Add((double)a1, d1) << endl;
//
//	 ��ʾʵ����
//	cout << Add<int>(a1, d1) << endl;
//	cout << Add<double>(a1, d1) << endl;
//
//	double* p1 = func1<double>(10);
//
//	return 0;
//}


// //�ú���ģ�����ɶ�Ӧ�ĺ��� -> ģ���ʵ����
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
//	����䲻��ͨ�����룬��Ϊ�ڱ����ڼ䣬��������������ʵ����ʱ����Ҫ������ʵ������
//	ͨ��ʵ��a1��T����Ϊint��ͨ��ʵ��d1��T����Ϊdouble���ͣ���ģ������б���ֻ��
//	һ��T��
//	�������޷�ȷ���˴����׸ý�Tȷ��Ϊint ���� double���Ͷ�����
//	ע�⣺���ڰ�ȫ���ɶ��Եȿ�������ģ���У�������һ�㲻���������ת��������
//*/
//// ��ʱ�����ִ���ʽ��1. �û��Լ���ǿ��ת�� 2. ʹ����ʽʵ����(���Ľ���)
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
//	Add(a1, a2);//�������ģ������֮��,�����ȿ�����ͬһ���͵�Ҳ�����ǲ�ͬ���͵�
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
//// �Ƶ�ʵ����
//cout << Add(a1, (int)d1) << endl;
//cout << Add((double)a1, d1) << endl;
//
//// ��ʾʵ����
//cout << Add<int>(a1, d1) << endl;
//cout << Add<double>(a1, d1) << endl;
//
//cout << Add(a1, d1) << endl;
//
//double* p1 = func1<double>(10);

////ģ������
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
//	//������������
//}
//
//template<class A, class B>
//void func(const A& x, const B& y)
//{
//	//������������
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