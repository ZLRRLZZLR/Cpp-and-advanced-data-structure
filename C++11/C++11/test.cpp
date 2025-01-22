#include<iostream>

using namespace std;

template <class T>
const T& GetArg(const T& x)
{
	cout << x << " ";
	return x;
}
template <class ...Args>
void Arguments(Args... args)
{
}
template <class ...Args>
void Print(Args... args)
{
	// 注意GetArg必须返回或者到的对象，这样才能组成参数包给Arguments
	GetArg(args)...;
}

// 本质可以理解为编译器编译时，包的扩展模式
// 将上面的函数模板扩展实例化为下面的函数
// 是不是很抽象，C++11以后，只能说委员会的大佬设计语法思维跳跃得太厉害
//void Print(int x, string y, double z)
//{
// Arguments(GetArg(x), GetArg(y), GetArg(z));
//}
int main()
{
	Print(1, string("xxxxx"), 2.2);
	return 0;
}

//namespace bit
//{
//	string addStrings(string num1, string num2)
//	{
//		string str;
//		int end1 = num1.size() - 1, end2 = num2.size() - 1;
//		int next = 0;
//		while (end1 >= 0 || end2 >= 0)
//		{
//			int val1 = end1 >= 0 ? num1[end1--] - '0' : 0;
//			int val2 = end2 >= 0 ? num2[end2--] - '0' : 0;
//			int ret = val1 + val2 + next;
//			next = ret / 10;
//			ret = ret % 10;
//			str += ('0' + ret);
//		}
//		if (next == 1)
//			str += '1';
//		reverse(str.begin(), str.end());
//		cout << "******************************" << endl;
//		return str;
//	}
//}
//// 场景1
//int main()
//{
//	bit::string ret = bit::addStrings("11111", "2222");
//	cout << ret.c_str() << endl;
//	return 0;
//}
//// 场景2
//int main()
//{
//	bit::string ret;
//	ret = bit::addStrings("11111", "2222");
//	cout << ret.c_str() << endl;
//	return 0;
//}

//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<assert.h>
//#include<string.h>
//#include<algorithm>
//using namespace std;
//namespace bit
//{
//	class string
//	{
//	public:
//		typedef char* iterator;
//		typedef const char* const_iterator;
//		iterator begin()
//		{
//			return _str;
//		}
//		iterator end()
//		{
//			return _str + _size;
//		}
//		const_iterator begin() const
//		{
//			return _str;
//		}
//		const_iterator end() const
//		{
//			return _str + _size;
//		}
//		string(const char* str = "")
//			:_size(strlen(str))
//			, _capacity(_size)
//		{
//			cout << "string(char* str)-构造" << endl;
//			_str = new char[_capacity + 1];
//			strcpy(_str, str);
//		}
//		void swap(string& s)
//		{
//			::swap(_str, s._str);
//			::swap(_size, s._size);
//			::swap(_capacity, s._capacity);
//		}
//		string(const string& s)
//			:_str(nullptr)
//		{
//			cout << "string(const string& s) -- 拷贝构造" << endl;
//			reserve(s._capacity);
//			for (auto ch : s)
//			{
//				push_back(ch);
//			}
//		}
//		// 移动构造
//		string(string&& s)
//		{
//			cout << "string(string&& s) -- 移动构造" << endl;
//			swap(s);
//		}
//		string& operator=(const string& s)
//		{
//			cout << "string& operator=(const string& s) -- 拷贝赋值" <<
//				endl;
//			if (this != &s)
//			{
//				_str[0] = '\0';
//				_size = 0;
//				reserve(s._capacity);
//				for (auto ch : s)
//				{
//					push_back(ch);
//				}
//			}
//			return *this;
//		}
//		// 移动赋值
//		string& operator=(string&& s)
//		{
//			cout << "string& operator=(string&& s) -- 移动赋值" << endl;
//			swap(s);
//			return *this;
//		}
//		~string()
//		{
//			cout << "~string() -- 析构" << endl;
//			delete[] _str;
//			_str = nullptr;
//		}
//		char& operator[](size_t pos)
//		{
//			assert(pos < _size);
//			return _str[pos];
//		}
//		void reserve(size_t n)
//		{
//			if (n > _capacity)
//			{
//				char* tmp = new char[n + 1];
//				if (_str)
//				{
//					strcpy(tmp, _str);
//					delete[] _str;
//				}
//				_str = tmp;
//				_capacity = n;
//			}
//		}
//		void push_back(char ch)
//		{
//			if (_size >= _capacity)
//			{
//				size_t newcapacity = _capacity == 0 ? 4 : _capacity *
//					2;
//				reserve(newcapacity);
//			}
//			_str[_size] = ch;
//			++_size;
//			_str[_size] = '\0';
//		}
//		string& operator+=(char ch)
//		{
//			push_back(ch);
//			return *this;
//		}
//		const char* c_str() const
//		{
//			return _str;
//		}
//		size_t size() const
//		{
//			return _size;
//		}
//private:
//	char* _str = nullptr;
//	size_t _size = 0;
//	size_t _capacity = 0;
//};
//}
//int main()
//{
//	bit::string s1("xxxxx");
//	// 拷贝构造
//	bit::string s2 = s1;
//	// 构造+移动构造，优化后直接构造
//	bit::string s3 = bit::string("yyyyy");
//	// 移动构造
//	bit::string s4 = move(s1);
//	cout << "******************************" << endl;
//	return 0;
//}

//class Solution {
//public:
//	// 传值返回需要拷贝
//	string addStrings(string num1, string num2) {
//		string str;
//		int end1 = num1.size() - 1, end2 = num2.size() - 1;
//		// 进位
//		int next = 0;
//		while (end1 >= 0 || end2 >= 0)
//		{
//			int val1 = end1 >= 0 ? num1[end1--] - '0' : 0;
//			int val2 = end2 >= 0 ? num2[end2--] - '0' : 0;
//			int ret = val1 + val2 + next;
//			next = ret / 10;
//			ret = ret % 10;
//			str += ('0' + ret);
//		}
//		if (next == 1)
//			str += '1';
//		reverse(str.begin(), str.end());
//		return str;
//	}
//};
//class Solution {
//public:
//	// 这里的传值返回拷贝代价就太大了
//	vector<vector<int>> generate(int numRows) {
//		vector<vector<int>> vv(numRows);
//		for (int i = 0; i < numRows; ++i)
//		{
//			vv[i].resize(i + 1, 1);
//		}
//		for (int i = 2; i < numRows; ++i)
//		{
//			for (int j = 1; j < i; ++j)
//			{
//				vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1];
//			}
//		}
//		return vv;
//	}
//};


//#include<iostream>
//using namespace std;
//void f(int& x)
//{
//	std::cout << "左值引用重载 f(" << x << ")\n";
//}
//void f(const int& x)
//{
//	std::cout << "到 const 的左值引用重载 f(" << x << ")\n";
//}
//void f(int&& x)
//{
//	std::cout << "右值引用重载 f(" << x << ")\n";
//}
//int main()
//{
//	int i = 1;
//	const int ci = 2;
//	f(i); // 调用 f(int&)
//	f(ci); // 调用 f(const int&)
//	f(3); // 调用 f(int&&)，如果没有 f(int&&) 重载则会调用 f(const int&)
//	f(std::move(i)); // 调用 f(int&&)
//	// 右值引用变量在用于表达式时是左值
//	int&& x = 1;
//	f(x); // 调用 f(int& x)
//	f(std::move(x)); // 调用 f(int&& x)
//	return 0;
//}

//int main()
//{
//	std::string s1 = "Test";
//	// std::string&& r1 = s1; // 错误：不能绑定到左值
//	const std::string& r2 = s1 + s1; // OK：到 const 的左值引用延长生存期
//	// r2 += "Test"; // 错误：不能通过到 const 的引用修改
//	std::string&& r3 = s1 + s1; // OK：右值引用延长生存期
//	r3 += "Test"; // OK：能通过到非 const 的引用修改
//	std::cout << r3 << '\n';
//	return 0;
//}

//template <class _Ty>
//remove_reference_t<_Ty>&& move(_Ty&& _Arg)
//{ // forward _Arg as movable
//	return static_cast<remove_reference_t<_Ty>&&>(_Arg);
//}
//#include<iostream>
//using namespace std;
//int main()
//{
//	// 左值：可以取地址
//	// 以下的p、b、c、*p、s、s[0]就是常见的左值
//	int* p = new int(0);
//	int b = 1;
//	const int c = b;
//	*p = 10;
//	string s("111111");
//	s[0] = 'x';
//	double x = 1.1, y = 2.2;
//	// 左值引用给左值取别名
//	int& r1 = b;
//	int*& r2 = p;
//	int& r3 = *p;
//	string& r4 = s;
//	char& r5 = s[0];
//	// 右值引用给右值取别名
//	int&& rr1 = 10;
//	double&& rr2 = x + y;
//	double&& rr3 = fmin(x, y);
//	string&& rr4 = string("11111");
//	// 左值引用不能直接引用右值，但是const左值引用可以引用右值
//	const int& rx1 = 10;
//	const double& rx2 = x + y;
//	const double& rx3 = fmin(x, y);
//	const string& rx4 = string("11111");
//	// 右值引用不能直接引用左值，但是右值引用可以引用move(左值)
//	int&& rrx1 = move(b);
//	int*&& rrx2 = move(p);
//	int&& rrx3 = move(*p);
//	string&& rrx4 = move(s);
//	string&& rrx5 = (string&&)s;
//	// b、r1、rr1都是变量表达式，都是左值
//	cout << &b << endl;
//	cout << &r1 << endl;
//	cout << &rr1 << endl;
//	// 这里要注意的是，rr1的属性是左值，所以不能再被右值引用绑定，除非move一下
//	int& r6 = r1;
//	// int&& rrx6 = rr1;
//	int&& rrx6 = move(rr1);
//	return 0;
//}


//#include<iostream>
//using namespace std;
//int main()
//{
//	// 左值：可以取地址
//	// 以下的p、b、c、*p、s、s[0]就是常见的左值
//	int* p = new int(0);
//	int b = 1;
//	const int c = b;
//	*p = 10;
//	string s("111111");
//	s[0] = 'x';
//	cout << &c << endl;
//	cout << (void*)&s[0] << endl;
//	// 右值：不能取地址
//	double x = 1.1, y = 2.2;
//	// 以下几个10、x + y、fmin(x, y)、string("11111")都是常见的右值
//	10;
//	x + y;
//	fmin(x, y);
//	string("11111");
//	//cout << &10 << endl;
//	//cout << &(x+y) << endl;
//	//cout << &(fmin(x, y)) << endl;
//	//cout << &string("11111") << endl;
//	return 0;
//}

//#include<vector>
//#include<string>
//#include<map>
//using namespace std;
//int main()
//{
//	std::initializer_list<int> mylist;
//	mylist = { 10, 20, 30 };
//	cout << sizeof(mylist) << endl;
//	// 这里begin和end返回的值initializer_list对象中存的两个指针
//	// 这两个指针的值跟i的地址跟接近，说明数组存在栈上
//	int i = 0;
//	cout << mylist.begin() << endl;
//	cout << mylist.end() << endl;
//	cout << &i << endl;
//	// {}列表中可以有任意多个值
//	// 这两个写法语义上还是有差别的，第一个v1是直接构造，
//	// 第二个v2是构造临时对象+临时对象拷贝v2+优化为直接构造
//	vector<int> v1({ 1,2,3,4,5 });
//	vector<int> v2 = { 1,2,3,4,5 };
//	const vector<int>& v3 = { 1,2,3,4,5 };
//	// 这里是pair对象的{}初始化和map的initializer_list构造结合到一起用了
//	map<string, string> dict = { {"sort", "排序"}, {"string", "字符串"} };
//	// initializer_list版本的赋值支持
//	v1 = { 10,20,30,40,50 };
//	return 0;
//}

//// STL中的容器都增加了一个initializer_list的构造
//vector(initializer_list<value_type> il, const allocator_type& alloc =
//	allocator_type());
//list(initializer_list<value_type> il, const allocator_type& alloc =
//	allocator_type());
//map(initializer_list<value_type> il, const key_compare& comp =
//	key_compare(), const allocator_type& alloc = allocator_type());
//// ...
//template<class T>
//class vector {
//public:
//	typedef T* iterator;
//	vector(initializer_list<T> l)
//	{
//		for (auto e : l)
//			push_back(e)
//	}
//private:
//	iterator _start = nullptr;
//	iterator _finish = nullptr;
//	iterator _endofstorage = nullptr;
//};
//// 另外，容器的赋值也支持initializer_list的版本
//vector& operator= (initializer_list<value_type> il);
//map& operator= (initializer_list<value_type> il);



//#include<iostream>
//#include<vector>
//using namespace std;
//struct Point
//{
//	int _x;
//	int _y;
//};
//class Date
//{
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//	{
//		cout << "Date(int year, int month, int day)" << endl;
//	}
//	Date(const Date& d)
//		:_year(d._year)
//		, _month(d._month)
//		, _day(d._day)
//	{
//		cout << "Date(const Date& d)" << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//// 一切皆可用列表初始化，且可以不加=
//int main()
//{
//	// C++98支持的
//	int a1[] = { 1, 2, 3, 4, 5 };
//	int a2[5] = { 0 };
//	Point p = { 1, 2 };
//	// C++11支持的
//	// 内置类型支持
//	int x1 = { 2 };
//	// 自定义类型支持
//	// 这里本质是用{ 2025, 1, 1}构造一个Date临时对象
//	// 临时对象再去拷贝构造d1，编译器优化后合二为一变成{ 2025, 1, 1}直接构造初始化
//	d1
//		// 运行一下，我们可以验证上面的理论，发现是没调用拷贝构造的
//		Date d1 = { 2025, 1, 1 };
//	// 这里d2引用的是{ 2024, 7, 25 }构造的临时对象
//	const Date& d2 = { 2024, 7, 25 };
//	// 需要注意的是C++98支持单参数时类型转换，也可以不用{}
//	Date d3 = { 2025 };
//	Date d4 = 2025;
//	// 可以省略掉=
//	Point p1{ 1, 2 };
//	int x2{ 2 };
//	Date d6{ 2024, 7, 25 };
//	const Date& d7{ 2024, 7, 25 };
//	// 不支持，只有{}初始化，才能省略=
//	// Date d8 2025;
//	vector<Date> v;
//	v.push_back(d1);
//	v.push_back(Date(2025, 1, 1));
//	// 比起有名对象和匿名对象传参，这里{}更有性价比
//	v.push_back({ 2025, 1, 1 });
//	return 0;
//}

//struct Point
//{
//	int _x;
//	int _y;
//};
//int main()
//{
//	int array1[] = { 1, 2, 3, 4, 5 };
//	int array2[5] = { 0 };
//	Point p = { 1, 2 };
//	return 0;
//}