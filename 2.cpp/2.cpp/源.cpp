#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<map>
#include<list>
using namespace std;

//for(auto& e : array)
//e*= 2 = 0;
//for (auto e : array)
//cout << e << "" << endl;

//auto func2() {
//	//......
//	return func1();
//}
//int main() {
//	int a = 10;
//	auto b = a;
//	auto c = 'a';
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//	cout << typeid(a).name() << endl;
//
//	//auto array[] = { 4,5,6 };
//	int array[] = { 1,2,3,4,5};
//	for (size_t i = 0; i < sizeof(array) / sizeof(array[0];i++)
//	{
//		array[i] *= 2;
//	}
//	for (size_t i = 0; i < sizeof(array) / sizeof(array[0] ; i++)
//	{
//		cout << array[i] << endl;
//	}
//}



//void test_string4() {
//	string s2("hello worldxxxxxxxxxxxxx");
//	cout << s2.size() << endl;
//	cout << s2.capacity() << endl << endl;
//
//	s2.reserve(20);
//	cout << s2.size() << endl;
//	cout << s2.capacity() << endl;
//
//	s2.clear();
//
//	cout << typeid(string::iterator).name() << endl;
//	cout << typeid(string::reverse_iterator).name() << endl;
//
//
//}


//void TestPushBack() {
//	string s;
//	s.reserve(100);
//	size_t sz = s.capacity();
//	cout << "capacity changed:" << sz << '\n';
//
//	cout << "making s grow:\n";
//	for (size_t i = 0; i < 100; i++)
//	{
//		s.push_back('c');
//		if (sz != s.capacity()) {
//			sz = s.capacity();
//			cout << "capacity changed;" << sz << '\n';
//		}
//	}
//}
//
//void test_string3() {
//	string s2("hellow world");
//	cout << s2.length() << endl;
//	cout << s2.size() << endl;
//
//	cout << s2.max_size() << endl;
//
//	cout << s2.capacity() << endl;
//	TestPushBack();
//	string s3("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
//}


//int main() {
//	TestPushBack();
//	return 0;
//}

//class string {
//private:
//	char _buff[16];
//	char* _str;
//
//	size_t _size;
//	size_t _capacity;
//};

//void test_string1() {
//	string s1;
//	string s2("hellow world");
//
//	cout << s1 << s2 << endl;
//
//	s2[0] = 'x';
//	cout << s1 << s2 << endl;
//
//	for (size_t i = 0; i < s2.size(); i++)
//	{
//		cout << s2[i] << "";
//	}
//
//	cout << endl;
//
//	string::iterator it = s2.begin();
//	auto it = s2.begin();
//	while (it != s2.end()) {
//			*it += 2;
//
//			cout << *it << "";
//			++it;
//
//	}
//	cout << endl;
//
//	cout << s2 << endl;
//
//	map<string, string>dict;
//	//map<string,string>::iterator mit = dict.begin();
//	auto mit = dict.begin();
//	
//	list<int> lt = {1,2,3,4,5,6,7};
//	list<int>::iterator lit = lt.begin();
//	while (lit != lt.end) {
//		cout << *lit << "";
//		++lit;
//	}
//	cout << endl;
//	for (auto& ch : s2) {
//		ch -= 2;
//		cout << ch << "";
//	}
//	cout << endl;
//	cout << s2 << endl;
//
//}
//
//void test_string2() {
//	string s2("hello world");
//	string::iterator it = s2.begin();
//	while (it != s2.end()) {
//		*it += 2;
//		cout << *it << "";
//		++it;
//	}
//	cout << endl;
//	string::reverse_iterator rit = s2.rbegin();
//	while(rit != s2.rend()) {
//		cout << *rit << "";
//		++rit;
//	}
//	cout << endl;
//	const string s3("hellow world");
//	//string::const_iterator cit = s3.begin();
//	auto cit = s3.begin();
//	while (cit != s3.end()) {
//		//*cit += 2;
//		cout << *cit << "";
//		++cit;
//	}
//	cout << endl;
//
//	//string::const_reverse_yterator rcit = s3.begin();
//	auto rcit = s3.rbegin();
//	while(rcit != s3.rend()) {
//		cout << *rcit << "";
//		++rcit;
//	}
//	cout << endl;
//
//}
//
//
//int main() {
//
//	return 0;
//}


//#include <iostream>
//using namespace std;
//
//class Date
//
//{
//
//public:
//
//    // ��ȡĳ��ĳ�µ�����
//
//    int GetMonthDay(int year, int month)
//
//    {
//
//        static int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//
//        int day = days[month];
//
//        if (month == 2
//
//            && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
//
//        {
//
//            day += 1;
//
//        }
//
//        return day;
//
//    }
//
//
//
//    // ȫȱʡ�Ĺ��캯��
//
//    Date(int year = 1900, int month = 1, int day = 1)
//
//    {
//
//        if (year < 1900
//
//            || month < 1 || month > 12
//
//            || day < 1 || day > GetMonthDay(year, month))
//
//        {
//
//            cout << "�Ƿ�����" << endl;
//
//        }
//
//
//
//        _year = year;
//
//        _month = month;
//
//        _day = day;
//
//    }
//
//
//
//    // �������캯��
//
//  // d2(d1)
//
//    Date(const Date& d)
//
//    {
//
//        this->_year = d._year;
//
//        _month = d._month;
//
//        _day = d._day;
//
//    }
//
//
//
//    // ��ֵ���������
//
//  // d2 = d3 -> d2.operator=(&d2, d3)
//
//    Date& operator=(const Date& d)
//
//    {
//
//        if (this != &d)
//
//        {
//
//            this->_year = d._year;
//
//            this->_month = d._month;
//
//            this->_day = d._day;
//
//        }
//
//
//
//        return *this;
//
//    }
//
//
//    Date& operator+=(int day)
//
//    {
//
//
//        _day += day;
//
//        while (_day > GetMonthDay(_year, _month))
//
//        {
//
//            _day -= GetMonthDay(_year, _month);
//
//            _month++;
//
//            if (_month == 13)
//
//            {
//
//                _year++;
//
//                _month = 1;
//
//            }
//
//        }
//
//
//
//        return *this;
//
//    }
//
//
//    int _year;
//
//    int _month;
//
//    int _day;
//
//};
//
//int main() {
//    int m;
//    while (scanf("%d", &m) != EOF) { // ע�� while ������ case
//        int year = 0, month = 0, day = 0, num = 0;
//        Date d1;
//        for (int i = 0; i < m; i++) {
//            cin >> year >> month >> day >> num;
//            Date d2(year, month, day);
//            d2 += num;
//            d1 = d2;
//        }
//        cout << d1._year << "-";
//        if (d1._month < 10) {
//            cout << 0 << d1._month << "-";
//        }
//        else {
//            cout << d1._month << "-";
//        }
//        if (d1._day < 10) {
//            cout << 0 << d1._day << endl;;
//        }
//        else {
//            cout << d1._day << endl;
//        }
//    }
//}
// 64 λ������� printf("%lld")

//int main() {
//	string s1;
//	string s2("hello world");
//	string s3(s2);
//
//	cout << s1 << endl;
//
//
//	return 0;
//}


//int main() {
//	Stack<int> st1;
//	st1.Push(1);
//	st1.Push(2);
//	st1.Push(3);
//
//
//}


//template<class T>
//T Add(const T& left, const T& right) {
//	return left + right;
//}
//int Add(const int& x, const int& y) {
//	return (x + y) * 10;
//}
//
//int main() {
//	int a1 = 10, int a2 = 20;
//	cout << Add(a1, a2) << endl;
//
//	return 0;
//}
//template<typename T>
//class Stack {
//public:
//	Stack(int n = 4)
//		:_array(new T[n])
//		,_size(0)
//		,_capacity(n)
//	{}
//
//	~Stack() {
//		delete[] _array;
//		_array = nullptr;
//		_size = _capacity = 0;
//	}
//
//	void Push(const T& x);
//Private:
//	T* _array;
//	size_t _capacity;
//	size_t _size;
//};
//
//template<class T>
//void Stack<T>::Push(const T& x) {
//	if (_size == _capacity) {
//		T* tmp = new T[_capacity * 2]��
//			memcpy(tmp, _array, sizeof(T) * _size);
//		delete[] _array;
//
//		_array = tmp;
//		_capacity *= 2;
//	}
//
//	_array[_size++] = x;
//}




//template<class T>
//T Add(const T& left, const T& right) {
//	return left + right;
//}
//
//template<class T1, class T2 >
//T1 Add(const T1& left, const T2& right) {
//	return left + right��
//}
//
//template<class T>
//T* func(int n) {
//	return new T[n];
//}
//
//int main() {
//	int a1 = 10, a2 = 20;
//	double d1 = 10, d2 = 20.2;
//	Add(a1, a2);
//	Add(d1, d2);
//
//	cout << Add(a1, (int)d1) << endl;
//	cout << Add((double)a1, d1) << endl;
//
//	cout << Add<int>(a1, d1) << endl;
//	cout << Add<double>(a1, d1) << endl;
//
//	cout << Add(a1, d1) << endl;
//
//	double* p1 = func<double>(10);
//
//	return 0;  
//}




//template<class T>
//void Swap(T & a, T & y) {
//	T tmp = x;
//	x = y;
//	y = tmp;
//}
//
////template<typename T1, typename T2 >
////void func(const T1& x, const T2& y) {
////
////}
//int main() {
//	int i = 1, j = 2;
//	double m = 1.1, n = 2.2;
//	Swap(i, j);
//	Swap(m, n);
//
//	swap(i,j);
//	swap(m, n);
//
//	func(i, m);
//	return 0;
//}



//class A {
//public:
//	A(int a = 0)
//		: _a(a);
//	{
//		cout << "A():" << this << endl;
//	}
//
//	~A() {
//		cout << "~A():" << this << endl;
//	}
//private:
//	int _a;
//};
//
//int main() {
//	A* p1 = new A(1);
//	delete p1;
//
//	A* p2 = (A*)operator new(sizeof(A));
//	new(p2)A(1);
//	
//	p2->~A();
//	operator delete(p2);
//
//	return 0;
//}

//class B {
//public:
//	~B() {
//		cout << "~B()" << endl;
//	}
//private:
//	int _b1 = 2;
//	int _b2 = 2;
//};
//
//int main() {
//	int* p1 = new int[10];
//	delete p1;
//	free(p1);
//
//	B* p2 = new B[10];
//	delete p2;
//
//	A* p2 = new A[10];
//	delete[] p3;
//
//	return 0;
//}


//int mian() {
//	int* p1 = new int;
//	free(p1);
//
//	A* p2 = new A;
//	delete p2;
//
//	return 0;
//}




//int main() {
//	A* p1 = new A(1);
//	delete p1;
//	A* p2 = new A[5];
//	delete[] p2;
//
//	return 0;
//}





//void func() {
//	int n = 1;
//	while (1) {
//		void* p1 = new char[1024 * 1024];
//		cout << p1 << "->"<< n << endl;
//		++n;
//	}
//}
//
//
//int main() {
//	try {
//		func();
//	}
//
//	catch (const exception& e) {
//		cout << e.what() << endl;
//	}
//
//	return 0;
//
//}









//int main() {
//	try {
//		void* p1 = new char[1024 * 1024 * 1024];
//		cout << p1 << endl;
//	}
//	catch (const exception& e) {
//		cout << e.what() << endl;
//	}
//
//	return 0;
//}





//int main() {
//	A* p1 = new A(1);
//	A* p2 = new A(2, 2);
//
//	A aa1(1, 1);
//	A aa2(2, 2);
//	A aa3(3, 3);
//	A* p3 = new A[3]{ aa1,aa2,aa3 };
//
//	A* p4 = new A[3]{ A(1,1),A(2,2),A(3,3) };
//	A* p5 = new A[3]{ {1,1},{ 2,2 },{3,3} };
//
//	return 0;
//}



//int main() {
//	int* p1 = new int;
//	int* p2 = new int[10];
//
//	delete p1;
//	delete[] p2;
//
//	int* p3 = new int(0);
//	int* p4 = new int[10] {0};
//	int* p5 = new int[10] {1, 2, 3, 4, 5};
//
//	delete p3;
//	delete[] p4;
//	delete[] p5;
//
//	return 0;
//}
//struct ListNode {
//	int val;
//	ListNode* next;
//
//	ListNode(int x)
//		:val(x)
//		,next(nullptr)
//	{}
//};
//
//int main() {
//	A* p1 = new A;
//	A* p2 = new A(1);
//	delete p1;
//	delete p2;
//
//	ListNode* n1 = new ListNode(1);
//	ListNode* n2 = new ListNode(1);
//	ListNode* n3 = new ListNode(1);
//	ListNode* n4 = new ListNode(1);
//	n1->next = n2;
//	n2->next = n3;
//	n3->next = n4;
//	return 0;
//
//}



//
//
//class Date
//{
//
//
//public:
//
//
//	// ��ȡĳ��ĳ�µ�����
//
//
//	int GetMonthDay(int year, int month) {
//		static int arr[13] = { -1,31,28,31,30,31,
//			30,31,31,30,31,30,31 };
//
//
//		if (month == 2 &&
//			year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
//			return 29;
//		}
//		return arr[month];
//
//
//	}
//
//	Date(int year, int month, int day) {
//		_year = year;
//		_day = day;
//		_month = month;
//	}
//	// �������캯��
//	// d2(d1)
//
//
//	Date(const Date& d) {
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//
//
//	}
//
//
//	// ��ֵ���������
//
//	Date& operator=(const Date& d) {
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//
//
//		return *this;
//	}
//
//
//	// ����+=����
//
//
//	Date& operator+=(int day);
//
//	// ����+����
//
//
//	Date operator+(int day);
//
//
//	// ����-=����
//
//
//	Date& operator-=(int day);
//
//
//	// ����-����
//
//
//	Date operator-(int day);
//
//
//	// ǰ��++
//
//
//	Date& operator++();
//
//
//	// ����++
//
//
//	Date operator++(int);
//
//	// ǰ��--
//
//
//	Date& operator--();
//
//
//	// ����--
//
//
//	Date operator--(int);
//
//
//	// >���������
//
//
//	bool operator>(const Date& d)const;
//
//	// ==���������
//
//
//	bool operator==(const Date& d)const;
//
//
//	// >=���������
//
//
//	bool operator >= (const Date& d)const;
//
//
//	// <���������
//
//
//	bool operator < (const Date& d)const;
//
//
//	// <=���������
//
//
//	bool operator <= (const Date& d)const;
//
//
//	// !=���������
//
//
//	bool operator != (const Date& d)const;
//
//	// ����-���� ��������
//
//
//	int operator-(const Date& d);
//
//
//private:
//
//
//	int _year;
//
//
//	int _month;
//
//
//	int _day;
//
//
//};
//
//
//// ����+=����
//Date& Date::operator+=(int day) {
//	if (day < 0) {
//		return *this -= (-day);
//	}
//	_day += day;
//	while (_day > GetMonthDay(_year, _month)) {
//		_day -= GetMonthDay(_year, _month);
//		_month++;
//		if (13 == _month) {
//			_year++;
//			_month = 1;
//		}
//
//
//	}
//	return *this;
//}
//
//
//// ����+����
//
//
//Date Date::operator+(int day) {
//	Date tmp = *this;
//	tmp += day;
//
//
//	return tmp;
//}
//
//
//// ǰ��++
//
//
//Date& Date::operator++() {
//	*this = *this + 1;
//
//
//	return *this;
//}
//
//
//
//
//// ����++
//
//
//Date Date::operator++(int) {
//	Date tmp = *this;
//	++(*this);
//	return tmp;
//}
//
//
//
//
//// ����-=����
//
//
//Date& Date::operator-=(int day) {
//	if (day < 0) {
//		return *this += (-day);
//	}
//	_day -= day;
//	while (_day <= 0) {
//		if (1 == _month) {
//			_year--;
//			_month = 12;
//			_day += GetMonthDay(_year, _month);
//		}
//		else {
//			_month--;
//			_day += GetMonthDay(_year, _month);
//		}
//	}
//
//
//	return *this;
//}
//
//
//// ����-����
//
//
//Date Date::operator-(int day) {
//	Date tmp = *this;
//	tmp -= day;
//
//
//	return tmp;
//}
//
//
//
//
//// ǰ��--
//
//
//Date& Date::operator--() {
//	*this = *this - 1;
//
//
//	return *this;
//}
//
//
//// ����--
//
//
//Date Date::operator--(int) {
//	Date tmp = *this;
//	--(*this);
//	return tmp;
//}
//
//
//
//
//
//
//// >���������
//
//
//bool Date::operator>(const Date& d) const {
//	if (_year > d._year) {
//		return true;
//	}
//	else if (_year == d._year) {
//		if (_month > d._month) {
//			return true;
//		}
//		else if (_month == d._month) {
//			if (_day > d._day) {
//				return true;
//			}
//			else {
//				return false;
//			}
//		}
//		else {
//			return false;
//		}
//	}
//	else {
//		return false;
//	}
//}
//
//
//
//
//
//
//// ==���������
//
//
//bool Date::operator==(const Date& d) const {
//	return _year == d._year && _month == d._month && _day == d._day;
//}
//
//
//
//
//
//
//// >=���������
//
//
//bool Date::operator >= (const Date& d) const {
//	return *this > d || *this == d;
//}
//
//
//
//
//
//
//// <���������
//
//
//bool Date::operator < (const Date& d) const {
//	return !(*this >= d);
//}
//
//
//
//
//
//
//// <=���������
//
//
//bool Date::operator <= (const Date& d) const {
//	return !(*this > d);
//}
//
//
//
//
//
//
//// !=���������
//
//
//bool Date::operator != (const Date& d) const {
//	return !(*this == d);
//}
//
//
//
//
//
//
//// ����-���� ��������
//
//
//int Date::operator-(const Date& d) {
//	int flag = 1;
//	int day = 0;
//	Date max = *this;
//	Date min = d;
//	if (*this < d) {
//		flag = -1;
//		min = *this;
//		max = d;
//	}
//	while (min < max) {
//		++min;
//		++day;
//	}
//
//
//	return day * flag;
//}
//
//
//int main() {
//	int year1, month1, day1;
//	int year2, month2, day2;
//	scanf("%4d%2d%2d", &year1, &month1, &day1);
//	scanf("%4d%2d%2d", &year2, &month2, &day2);
//	// ע�� while ������ case
//	Date n1(year1, month1, day1);
//	Date n2(year2, month2, day2);
//	cout << (n2 - n1) + 1 << endl;
//}
//// 64 λ������� printf("%lld")