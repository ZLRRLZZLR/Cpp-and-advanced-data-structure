#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<map>
#include<list>
using namespace std;


//class string {
//private:
//	char _buff[16];
//	char* _str;
//
//	size_t _size;
//	size_t _capacity;
//};
void test_string1() {
	string s1;
	string s2("hello world");

	cout << s1 << s2 << endl;

	s2[0] = 'x';
	cout << s1 << s2 << endl;

	for (size_t i = 0; i < s2.size(); i++) {
		cout << s2[i] << " ";
	}
	cout << endl;
	auto it = s2.begin();
	while (it != s2.end()) {
		*it += 2;

		cout << *it << " ";
		++it;
	}
	cout << endl;

	cout << s2 << endl;

	map<string, string>dict;

	auto mit = dict.begin();
	for (auto& ch : s2) {
		ch -= 2;
		cout << ch << " ";
	}
	cout << endl;

	cout << s2 << endl;

}



////NC21 链表内指定区间反转
///**
// * struct ListNode {
// *	int val;
// *	struct ListNode *next;
// * };
// */
// /**
//  * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//  *
//  *
//  * @param head ListNode类
//  * @param m int整型
//  * @param n int整型
//  * @return ListNode类
//  */
//typedef struct ListNode ListNode;
//
//struct ListNode* reverseBetween(struct ListNode* head, int m, int n) {
//    if (NULL == head || m == n)
//        return head;
//
//    ListNode* new_head = (ListNode*)malloc(sizeof(ListNode));
//    new_head->next = head;
//
//    ListNode* prev = new_head;
//    for (int i = 1; i < m; i++) {
//        prev = prev->next;
//    }
//
//    head = prev->next;
//    for (int i = m; i < n; i++) {
//        ListNode* p = head->next;
//        head->next = p->next;
//        p->next = prev->next;
//        prev->next = p;
//    }
//
//    head = new_head->next;
//    free(new_head);
//    return head;
//}
///**
// * struct ListNode {
// *	int val;
// *	struct ListNode *next;
// * };
// */
// /**
//  * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//  *
//  *
//  * @param head ListNode类
//  * @param m int整型
//  * @param n int整型
//  * @return ListNode类
//  */
//typedef struct ListNode ListNode;
//
//struct ListNode* reverseBetween(struct ListNode* head, int m, int n) {
//    if (NULL == head || m == n)
//        return head;
//
//    ListNode* new_head = (ListNode*)malloc(sizeof(ListNode));
//    new_head->next = head;
//    ListNode* prev = new_head;
//    for (int i = 1; i < m; i++) {
//        prev = prev->next;
//    }
//
//    head = prev->next;
//    while (head->next != NULL) {
//        ListNode* p = head->next;
//        head->next = p->next;
//        prev->next = p;
//        p->next = head;
//    }
//    head = new_head->next;
//    free(new_head);
//    return head;
//}
//#include <iostream>
//using namespace std;
//
//int main() {
//    int year, day;
//    while (cin >> year >> day) {
//        static int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
//        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
//            days[1] = 29;
//        }
//        else {
//            days[1] = 28;
//        }
//        int month = 1;
//        while (day > days[month - 1]) {
//            day -= days[month - 1];
//            month++;
//        }
//        printf("%4d-%02d-%02d", year, month, day);
//    }
//}
//// 64 位输出请用 printf("%lld")
//#include <iostream>
//using namespace std;
//
//int main() {
//    int n;
//    while (cin >> n) {
//        for (int i = 0; i < n; i++) {
//            int year, month, day, num;
//            cin >> year >> month >> day >> num;
//            static int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
//            day += num;
//            while (day > days[month - 1]) {
//                if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
//                    days[1] = 29;
//                }
//                else {
//                    days[1] = 28;
//                }
//                day -= days[month - 1];
//                month++;
//                if (month > 12) {
//                    month = 1;
//                    year++;
//                }
//            }
//            printf("%02d-%02d-%02d\n", year, month, day);
//        }
//    }
//    return 0;
//}
//// 64 位输出请用 printf("%lld")


//KY222 打印日期
//#include <iostream>
//using namespace std;
//int GetNum(int year, int day, int* psum) {
//    int arr[13] = { 0 , 31 , 28 , 31 , 30 , 31 ,
//    30 , 31 , 31 , 30 , 31 , 30 , 31 };
//    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
//        arr[2] = 29;
//    int i = 1;
//    while (i < 13) {
//        if (*psum + arr[i] > day) {
//            if (*psum + arr[i] == day) {
//                i++;
//            }
//            return i;
//        }
//        else {
//            if (*psum + arr[i] >= day) {
//                return ++i;
//            }
//            *psum += arr[i];
//            i++;
//        }
//    }
//    return i;
//}
//
//int main() {
//    int y, n;
//    while (cin >> y >> n) {
//        int sum = 0;
//        int month = GetNum(y, n, &sum);
//        int day = n - sum;
//        cout << y << "-";
//        if (month < 10) {
//            cout << 0 << month << "-";
//        }
//        else {
//            cout << month << "-";
//        }
//        if (day < 10) {
//            cout << 0 << day << endl;;
//        }
//        else {
//            cout << day << endl;
//        }
//    }
//}
// 64 位输出请用 printf("%lld")


//char& operator[](size_t pos)
//{
//	assert(pos < _size);
//
//	return _str[pos];
//}
//
//const char& operator[](const size_t pos) const
//{
//	assert(pos < _size);
//
//	return _str[pos];
//}

//void test_string5()
//{
//	string s("hello world");
//	s.push_back(' ');
//	s.push_back('x');
//	s.append("yyyyyy");
//
//	cout << s << endl;
//
//	s += ' ';
//	s += "33333333333";
//	cout << s << endl;
//
//	s.insert(0, "hello bit ");
//	cout << s << endl;
//
//	s.insert(10, "zzzz");
//	cout << s << endl;
//
//	s.insert(0, "p");
//	cout << s << endl;
//
//	char ch = 't';
//	s.insert(0, 1, ch);
//	s.insert(s.begin(), ch);
//
//	cout << s << endl;
//}
//
//void test_string6()
//{
//	string s("hello world");
//	s.erase(6, 1);
//	cout << s << endl;
//
//	// 头删
//	s.erase(0, 1);
//	cout << s << endl;
//
//	s.erase(s.begin());
//	cout << s << endl;
//
//	// 尾删
//	s.erase(--s.end());
//	cout << s << endl;
//
//	s.erase(s.size() - 1, 1);
//	cout << s << endl;
//
//	string ss("hello world");
//	ss.erase(6);
//	cout << ss << endl;
//
//	string sss("hello                 world hello bit");
//	/*size_t pos = sss.find(' ');
//	while (pos != string::npos)
//	{
//		sss.replace(pos, 1, "%%");
//		cout << sss << endl;
//
//		pos = sss.find(' ', pos+2);
//	}
//	cout << sss << endl;*/
//
//	//sss.replace(5, 1, "%%");
//	//cout << sss << endl;
//
//	string tmp;
//	tmp.reserve(sss.size());
//	for (auto ch : sss)
//	{
//		if (ch == ' ')
//			tmp += "%%";
//		else
//			tmp += ch;
//	}
//	cout << tmp << endl;
//	//sss = tmp;
//	sss.swap(tmp);
//	cout << sss << endl;
//
//	string file;
//	cin >> file;
//	FILE* fout = fopen(file.c_str(), "r");
//	char ch = fgetc(fout);
//	while (ch != EOF)
//	{
//		cout << ch;
//		ch = fgetc(fout);
//	}
//	fclose(fout);
//}
//
//void SplitFilename(const std::string& str)
//{
//	std::cout << "Splitting: " << str << '\n';
//	std::size_t found = str.find_last_of("/\\");
//
//	std::cout << " path: " << str.substr(0, found) << '\n';
//	std::cout << " file: " << str.substr(found + 1) << '\n';
//}
//// 16：10
//void test_string7()
//{
//	string s("test.cpp.zip");
//	size_t pos = s.rfind('.');
//	string suffix = s.substr(pos);
//	cout << suffix << endl;
//
//	std::string str("Please, replace the vowels in this sentence by asterisks.");
//	std::cout << str << '\n';
//
//	std::size_t found = str.find_first_not_of("abcdef");
//	while (found != std::string::npos)
//	{
//		str[found] = '*';
//		found = str.find_first_not_of("abcdef", found + 1);
//	}
//
//	std::cout << str << '\n';
//
//	std::string str1("/usr/bin/man");
//	std::string str2("D:\\1-教学服务团队\\1-比特课件\\4.C++课件\\C++课件V6-2022年修订\\C++课件--2022修订\\C++进阶课件");
//
//	SplitFilename(str1);
//	SplitFilename(str2);
//}
//
//void test_string8()
//{
//	string s1("hello");
//
//	string s2 = s1 + "world";
//	cout << s2 << endl;
//
//	string s3 = "world" + s1;
//	cout << s3 << endl;
//}

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
//    // 获取某年某月的天数
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
//    // 全缺省的构造函数
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
//            cout << "非法日期" << endl;
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
//    // 拷贝构造函数
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
//    // 赋值运算符重载
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
//    while (scanf("%d", &m) != EOF) { // 注意 while 处理多个 case
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
// 64 位输出请用 printf("%lld")

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
//		T* tmp = new T[_capacity * 2]；
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
//	return left + right；
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
//	// 获取某年某月的天数
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
//	// 拷贝构造函数
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
//	// 赋值运算符重载
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
//	// 日期+=天数
//
//
//	Date& operator+=(int day);
//
//	// 日期+天数
//
//
//	Date operator+(int day);
//
//
//	// 日期-=天数
//
//
//	Date& operator-=(int day);
//
//
//	// 日期-天数
//
//
//	Date operator-(int day);
//
//
//	// 前置++
//
//
//	Date& operator++();
//
//
//	// 后置++
//
//
//	Date operator++(int);
//
//	// 前置--
//
//
//	Date& operator--();
//
//
//	// 后置--
//
//
//	Date operator--(int);
//
//
//	// >运算符重载
//
//
//	bool operator>(const Date& d)const;
//
//	// ==运算符重载
//
//
//	bool operator==(const Date& d)const;
//
//
//	// >=运算符重载
//
//
//	bool operator >= (const Date& d)const;
//
//
//	// <运算符重载
//
//
//	bool operator < (const Date& d)const;
//
//
//	// <=运算符重载
//
//
//	bool operator <= (const Date& d)const;
//
//
//	// !=运算符重载
//
//
//	bool operator != (const Date& d)const;
//
//	// 日期-日期 返回天数
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
//// 日期+=天数
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
//// 日期+天数
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
//// 前置++
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
//// 后置++
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
//// 日期-=天数
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
//// 日期-天数
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
//// 前置--
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
//// 后置--
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
//// >运算符重载
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
//// ==运算符重载
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
//// >=运算符重载
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
//// <运算符重载
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
//// <=运算符重载
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
//// !=运算符重载
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
//// 日期-日期 返回天数
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
//	// 注意 while 处理多个 case
//	Date n1(year1, month1, day1);
//	Date n2(year2, month2, day2);
//	cout << (n2 - n1) + 1 << endl;
//}
//// 64 位输出请用 printf("%lld")