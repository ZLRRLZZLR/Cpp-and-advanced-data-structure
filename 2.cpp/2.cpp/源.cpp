#define _CRT_SECURE_NO_WARNINGS 1

#include<string>
#include<map>
#include<list>








//class String
//{
//public:
//	String(const char* str = "")
//	{
//		if (nullptr == str)
//		{
//			assert(false);
//			return;
//		}
//		_str = new char[strlen(str) + 1];
//		strcpy(_str, str);
//	}
//	String(const String& s)
//		: _str(nullptr)
//	{
//		String strTmp(s._str);
//		swap(_str, strTmp._str);
//	}
//	// 对比下和上面的赋值那个实现比较好？
//	String& operator=(String s)
//	{
//		swap(_str, s._str);
//		return *this;
//	}
//	/*
//	String& operator=(const String& s)
//	{
//	if(this != &s)
//	{
//	String strTmp(s);
//	swap(_str, strTmp._str);
//	}
//	return *this;
//	}
//	*/
//	~String()
//	{
//		if (_str)
//		{
//			delete[] _str;
//			_str = nullptr;
//		}
//	}
//private:
//	char* _str;
//};



//class String
//{
//public:
//	String(const char* str = "")
//	{
//		// 构造String类对象时，如果传递nullptr指针，可以认为程序非
//		if (nullptr == str)
//		{
//			assert(false);
//			return;
//		}
//		_str = new char[strlen(str) + 1];
//		strcpy(_str, str);
//	}
//	String(const String& s)
//		: _str(new char[strlen(s._str) + 1])
//	{
//		strcpy(_str, s._str);
//	}
//	String& operator=(const String& s)
//	{
//		if (this != &s)
//		{
//			char* pStr = new char[strlen(s._str) + 1];
//			strcpy(pStr, s._str);
//			delete[] _str;
//			_str = pStr;
//		}
//		return *this;
//	}
//	~String()
//	{
//		if (_str)
//		{
//			delete[] _str;
//			_str = nullptr;
//		}
//	}
//private:
//	char* _str;
//};



//// 为了和标准库区分，此处使用String
//class String
//{
//public:
//	/*String()
//	:_str(new char[1])
//	{*_str = '\0';}
//	*/
//	//String(const char* str = "\0") 错误示范
//	//String(const char* str = nullptr) 错误示范
//	String(const char* str = "")
//	{
//		// 构造String类对象时，如果传递nullptr指针，可以认为程序非
//		if (nullptr == str)
//		{
//			assert(false);
//			return;
//		}
//		_str = new char[strlen(str) + 1];
//		strcpy(_str, str);
//	}
//	~String()
//	{
//		if (_str)
//		{
//			delete[] _str;
//			_str = nullptr;
//		}
//	}
//private:
//	char* _str;
//};
//// 测试
//void TestString()
//{
//	String s1("hello bit!!!");
//	String s2(s1);
//}



//class Solution {
//public:
//	string addstrings(string num1, string num2)
//	{
//		// 从后往前相加，相加的结果到字符串可以使用insert头插
//		// 或者+=尾插以后再reverse过来
//		int end1 = num1.size() - 1;
//		int end2 = num2.size() - 1;
//		int value1 = 0, value2 = 0, next = 0;
//		string addret;
//		while (end1 >= 0 || end2 >= 0)
//		{
//			if (end1 >= 0)
//				value1 = num1[end1--] - '0';
//			else
//				value1 = 0;
//			if (end2 >= 0)
//				value2 = num2[end2--] - '0';
//			else
//				value2 = 0;
//			int valueret = value1 + value2 + next;
//			if (valueret > 9)
//			{
//				next = 1;
//				valueret -= 10;
//			}
//			else
//			{
//				next = 0;
//			}
//			//addret.insert(addret.begin(), valueret+'0');
//			addret += (valueret + '0');
//		}
//		if (next == 1)
//		{
//			//addret.insert(addret.begin(), '1');
//			addret += '1';
//		}
//		reverse(addret.begin(), addret.end());
//		return addret;
//	}
//};



//class Solution {
//public:
//	bool isLetterOrNumber(char ch)
//	{
//		return (ch >= '0' && ch <= '9')
//			|| (ch >= 'a' && ch <= 'z')
//			|| (ch >= 'A' && ch <= 'Z');
//	}
//	bool isPalindrome(string s) {
//		// 先小写字母转换成大写，再进行判断
//		for (auto& ch : s)
//		{
//			if (ch >= 'a' && ch <= 'z')
//				ch -= 32;
//		}
//		int begin = 0, end = s.size() - 1;
//		while (begin < end)
//		{
//			while (begin < end && !isLetterOrNumber(s[begin]))
//				++begin;
//			while (begin < end && !isLetterOrNumber(s[end]))
//				--end;
//			if (s[begin] != s[end])
//			{
//				return false;
//			}
//			else
//			{
//				++begin;
//				--end;
//			}
//		}
//		return true;
//	}
//};

//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//	string line;
//	// 不要使用cin>>line,因为会它遇到空格就结束了
//	// while(cin>>line)
//	while (getline(cin, line))
//	{
//		size_t pos = line.rfind(' ');
//		cout << line.size() - pos - 1 << endl;
//	}
//	return 0;
//}


//class Solution {
//public:
//	int firstUniqChar(string s) {
//		// 统计每个字符出现的次数
//		int count[256] = { 0 };
//		int size = s.size();
//		for (int i = 0; i < size; ++i)
//			count[s[i]] += 1;
//		// 按照字符次序从前往后找只出现一次的字符
//		for (int i = 0; i < size; ++i)
//			if (1 == count[s[i]])
//				return i;
//		return -1;
//	}
//};



//class Solution {
//public:
//	bool isLetter(char ch)
//	{
//		if (ch >= 'a' && ch <= 'z')
//			return true;
//		if (ch >= 'A' && ch <= 'Z')
//			return true;
//		return false;
//	}
//	string reverseOnlyLetters(string S) {
//		if (S.empty())
//			return S;
//		size_t begin = 0, end = S.size() - 1;
//		while (begin < end)
//		{
//			while (begin < end && !isLetter(S[begin]))
//				++begin;
//			while (begin < end && !isLetter(S[end]))
//				--end;
//			swap(S[begin], S[end]);
//			++begin;
//			--end;
//		}
//		return S;
//	}
//};


//struct _Rep_base
//{
//	size_type _M_length;
//	size_type _M_capacity;
//	_Atomic_word _M_refcount;
//};



//union _Bxty
//{ // storage for small buffer or pointer to larger one
//	value_type _Buf[_BUF_SIZE];
//	pointer _Ptr;
//	char _Alias[_BUF_SIZE]; // to permit aliasing
//} _Bx;

//#define _CRT_SECURE_NO_WARNINGS
//
//#include <iostream>
//using namespace std;
//
//#include <string>
//
//////////////////////////////////////////////////////////////////////////
//// 测试string容量相关的接口
//// size/clear/resize
//void Teststring1()
//{
//	// 注意：string类对象支持直接用cin和cout进行输入和输出
//	string s("hello, bit!!!");
//	cout << s.size() << endl;
//	cout << s.length() << endl;
//	cout << s.capacity() << endl;
//	cout << s << endl;
//
//	// 将s中的字符串清空，注意清空时只是将size清0，不改变底层空间的大小
//	s.clear();
//	cout << s.size() << endl;
//	cout << s.capacity() << endl;
//
//	// 将s中有效字符个数增加到10个，多出位置用'a'进行填充
//	// “aaaaaaaaaa”
//	s.resize(10, 'a');
//	cout << s.size() << endl;
//	cout << s.capacity() << endl;
//
//	// 将s中有效字符个数增加到15个，多出位置用缺省值'\0'进行填充
//	// "aaaaaaaaaa\0\0\0\0\0"
//	// 注意此时s中有效字符个数已经增加到15个
//	s.resize(15);
//	cout << s.size() << endl;
//	cout << s.capacity() << endl;
//	cout << s << endl;
//
//	// 将s中有效字符个数缩小到5个
//	s.resize(5);
//	cout << s.size() << endl;
//	cout << s.capacity() << endl;
//	cout << s << endl;
//}
//
////====================================================================================
//void Teststring2()
//{
//	string s;
//	// 测试reserve是否会改变string中有效元素个数
//	s.reserve(100);
//	cout << s.size() << endl;
//	cout << s.capacity() << endl;
//
//	// 测试reserve参数小于string的底层空间大小时，是否会将空间缩小
//	s.reserve(50);
//	cout << s.size() << endl;
//	cout << s.capacity() << endl;
//}
//
//// 利用reserve提高插入数据的效率，避免增容带来的开销
////====================================================================================
//void TestPushBack()
//{
//	string s;
//	size_t sz = s.capacity();
//	cout << "making s grow:\n";
//	for (int i = 0; i < 100; ++i)
//	{
//		s.push_back('c');
//		if (sz != s.capacity())
//		{
//			sz = s.capacity();
//			cout << "capacity changed: " << sz << '\n';
//		}
//	}
//}
//
//// 构建vector时，如果提前已经知道string中大概要放多少个元素，可以提前将string中空间设置好
//void TestPushBackReserve()
//{
//	string s;
//	s.reserve(100);
//	size_t sz = s.capacity();
//
//	cout << "making s grow:\n";
//	for (int i = 0; i < 100; ++i)
//	{
//		s.push_back('c');
//		if (sz != s.capacity())
//		{
//			sz = s.capacity();
//			cout << "capacity changed: " << sz << '\n';
//		}
//	}
//}
//
//
//////////////////////////////////////////////////////////////////
//// string的遍历
//// begin()+end()   for+[]  范围for
//// 注意：string遍历时使用最多的还是for+下标 或者 范围for(C++11后才支持)
//// begin()+end()大多数使用在需要使用STL提供的算法操作string时，比如：采用reverse逆置string
//void Teststring3()
//{
//	string s1("hello Bit");
//	const string s2("Hello Bit");
//	cout << s1 << " " << s2 << endl;
//	cout << s1[0] << " " << s2[0] << endl;
//
//	s1[0] = 'H';
//	cout << s1 << endl;
//
//	// s2[0] = 'h';   代码编译失败，因为const类型对象不能修改
//}
//
//void Teststring4()
//{
//	string s("hello Bit");
//	// 3种遍历方式：
//	// 需要注意的以下三种方式除了遍历string对象，还可以遍历是修改string中的字符，
//	// 另外以下三种方式对于string而言，第一种使用最多
//	// 1. for+operator[]
//	for (size_t i = 0; i < s.size(); ++i)
//		cout << s[i] << endl;
//
//	// 2.迭代器
//	string::iterator it = s.begin();
//	while (it != s.end())
//	{
//		cout << *it << endl;
//		++it;
//	}
//
//	// string::reverse_iterator rit = s.rbegin();
//	// C++11之后，直接使用auto定义迭代器，让编译器推到迭代器的类型
//	auto rit = s.rbegin();
//	while (rit != s.rend())
//		cout << *rit << endl;
//
//	// 3.范围for
//	for (auto ch : s)
//		cout << ch << endl;
//}
//
//
////////////////////////////////////////////////////////////////
//// 测试string：
//// 1. 插入(拼接)方式：push_back  append  operator+= 
//// 2. 正向和反向查找：find() + rfind()
//// 3. 截取子串：substr()
//// 4. 删除：erase
//void Teststring5()
//{
//	string str;
//	str.push_back(' ');   // 在str后插入空格
//	str.append("hello");  // 在str后追加一个字符"hello"
//	str += 'b';           // 在str后追加一个字符'b'   
//	str += "it";          // 在str后追加一个字符串"it"
//	cout << str << endl;
//	cout << str.c_str() << endl;   // 以C语言的方式打印字符串
//
//	// 获取file的后缀
//	string file("string.cpp");
//	size_t pos = file.rfind('.');
//	string suffix(file.substr(pos, file.size() - pos));
//	cout << suffix << endl;
//
//	// npos是string里面的一个静态成员变量
//	// static const size_t npos = -1;
//
//	// 取出url中的域名
//	string url("http://www.cplusplus.com/reference/string/string/find/");
//	cout << url << endl;
//	size_t start = url.find("://");
//	if (start == string::npos)
//	{
//		cout << "invalid url" << endl;
//		return;
//	}
//	start += 3;
//	size_t finish = url.find('/', start);
//	string address = url.substr(start, finish - start);
//	cout << address << endl;
//
//	// 删除url的协议前缀
//	pos = url.find("://");
//	url.erase(0, pos + 3);
//	cout << url << endl;
//}
//
//int main()
//{
//	return 0;
//}



//#define _CRT_SECURE_NO_WARNINGS
//
//#include <iostream>
//using namespace std;
//
//#include <string>
//
//////////////////////////////////////////////////////////////////////////
//// 测试string容量相关的接口
//// size/clear/resize
//void Teststring1()
//{
//	// 注意：string类对象支持直接用cin和cout进行输入和输出
//	string s("hello, bit!!!");
//	cout << s.size() << endl;
//	cout << s.length() << endl;
//	cout << s.capacity() << endl;
//	cout << s << endl;
//
//	// 将s中的字符串清空，注意清空时只是将size清0，不改变底层空间的大小
//	s.clear();
//	cout << s.size() << endl;
//	cout << s.capacity() << endl;
//
//	// 将s中有效字符个数增加到10个，多出位置用'a'进行填充
//	// “aaaaaaaaaa”
//	s.resize(10, 'a');
//	cout << s.size() << endl;
//	cout << s.capacity() << endl;
//
//	// 将s中有效字符个数增加到15个，多出位置用缺省值'\0'进行填充
//	// "aaaaaaaaaa\0\0\0\0\0"
//	// 注意此时s中有效字符个数已经增加到15个
//	s.resize(15);
//	cout << s.size() << endl;
//	cout << s.capacity() << endl;
//	cout << s << endl;
//
//	// 将s中有效字符个数缩小到5个
//	s.resize(5);
//	cout << s.size() << endl;
//	cout << s.capacity() << endl;
//	cout << s << endl;
//}
//
////====================================================================================
//void Teststring2()
//{
//	string s;
//	// 测试reserve是否会改变string中有效元素个数
//	s.reserve(100);
//	cout << s.size() << endl;
//	cout << s.capacity() << endl;
//
//	// 测试reserve参数小于string的底层空间大小时，是否会将空间缩小
//	s.reserve(50);
//	cout << s.size() << endl;
//	cout << s.capacity() << endl;
//}
//
//// 利用reserve提高插入数据的效率，避免增容带来的开销
////====================================================================================
//void TestPushBack()
//{
//	string s;
//	size_t sz = s.capacity();
//	cout << "making s grow:\n";
//	for (int i = 0; i < 100; ++i)
//	{
//		s.push_back('c');
//		if (sz != s.capacity())
//		{
//			sz = s.capacity();
//			cout << "capacity changed: " << sz << '\n';
//		}
//	}
//}
//
//// 构建vector时，如果提前已经知道string中大概要放多少个元素，可以提前将string中空间设置好
//void TestPushBackReserve()
//{
//	string s;
//	s.reserve(100);
//	size_t sz = s.capacity();
//
//	cout << "making s grow:\n";
//	for (int i = 0; i < 100; ++i)
//	{
//		s.push_back('c');
//		if (sz != s.capacity())
//		{
//			sz = s.capacity();
//			cout << "capacity changed: " << sz << '\n';
//		}
//	}
//}
//
//
//////////////////////////////////////////////////////////////////
//// string的遍历
//// begin()+end()   for+[]  范围for
//// 注意：string遍历时使用最多的还是for+下标 或者 范围for(C++11后才支持)
//// begin()+end()大多数使用在需要使用STL提供的算法操作string时，比如：采用reverse逆置string
//void Teststring3()
//{
//	string s1("hello Bit");
//	const string s2("Hello Bit");
//	cout << s1 << " " << s2 << endl;
//	cout << s1[0] << " " << s2[0] << endl;
//
//	s1[0] = 'H';
//	cout << s1 << endl;
//
//	// s2[0] = 'h';   代码编译失败，因为const类型对象不能修改
//}
//
//void Teststring4()
//{
//	string s("hello Bit");
//	// 3种遍历方式：
//	// 需要注意的以下三种方式除了遍历string对象，还可以遍历是修改string中的字符，
//	// 另外以下三种方式对于string而言，第一种使用最多
//	// 1. for+operator[]
//	for (size_t i = 0; i < s.size(); ++i)
//		cout << s[i] << endl;
//
//	// 2.迭代器
//	string::iterator it = s.begin();
//	while (it != s.end())
//	{
//		cout << *it << endl;
//		++it;
//	}
//
//	// string::reverse_iterator rit = s.rbegin();
//	// C++11之后，直接使用auto定义迭代器，让编译器推到迭代器的类型
//	auto rit = s.rbegin();
//	while (rit != s.rend())
//		cout << *rit << endl;
//
//	// 3.范围for
//	for (auto ch : s)
//		cout << ch << endl;
//}
//
//
////////////////////////////////////////////////////////////////
//// 测试string：
//// 1. 插入(拼接)方式：push_back  append  operator+= 
//// 2. 正向和反向查找：find() + rfind()
//// 3. 截取子串：substr()
//// 4. 删除：erase
//void Teststring5()
//{
//	string str;
//	str.push_back(' ');   // 在str后插入空格
//	str.append("hello");  // 在str后追加一个字符"hello"
//	str += 'b';           // 在str后追加一个字符'b'   
//	str += "it";          // 在str后追加一个字符串"it"
//	cout << str << endl;
//	cout << str.c_str() << endl;   // 以C语言的方式打印字符串
//
//	// 获取file的后缀
//	string file("string.cpp");
//	size_t pos = file.rfind('.');
//	string suffix(file.substr(pos, file.size() - pos));
//	cout << suffix << endl;
//
//	// npos是string里面的一个静态成员变量
//	// static const size_t npos = -1;
//
//	// 取出url中的域名
//	string url("http://www.cplusplus.com/reference/string/string/find/");
//	cout << url << endl;
//	size_t start = url.find("://");
//	if (start == string::npos)
//	{
//		cout << "invalid url" << endl;
//		return;
//	}
//	start += 3;
//	size_t finish = url.find('/', start);
//	string address = url.substr(start, finish - start);
//	cout << address << endl;
//
//	// 删除url的协议前缀
//	pos = url.find("://");
//	url.erase(0, pos + 3);
//	cout << url << endl;
//}
//
//int main()
//{
//	return 0;
//}


//void Teststring()
//{
//	string s1; // 构造空的string类对象s1
//	string s2("hello bit"); // 用C格式字符串构造string类对象s2
//	string s3(s2); // 拷贝构造s3
//}

//#include<iostream>
//#include <string>
//#include <map>
//using namespace std;
//int main()
//{
//	int array[] = { 1, 2, 3, 4, 5 };
//	// C++98的遍历
//	for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i)
//	{
//		array[i] *= 2;
//	}
//	for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i)
//	{
//		cout << array[i] << endl;
//	}
//	// C++11的遍历
//	for (auto& e : array)
//		e *= 2;
//	for (auto e : array)
//		cout << e << " " << endl;
//	string str("hello world");
//	for (auto ch : str)
//	{
//		cout << ch << " ";
//	}
//	cout << endl;
//	return 0;
//}



//#include<iostream>
//#include <string>
//#include <map>
//using namespace std;
//int main()
//{
//	int array[] = { 1, 2, 3, 4, 5 };
//	// C++98的遍历
//	for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i)
//	{
//		array[i] *= 2;
//	}
//	for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i)
//	{
//		cout << array[i] << endl;
//	}
//	// C++11的遍历
//	for (auto& e : array)
//		e *= 2;
//	for (auto e : array)
//		cout << e << " " << endl;
//	string str("hello world");
//	for (auto ch : str)
//	{
//		cout << ch << " ";
//	}
//	cout << endl;
//	return 0;
//}


//#include<iostream>
//using namespace std;
//int func1()
//{
//	return 10;
//}
//// 不能做参数
//void func2(auto a)
//{}
//// 可以做返回值，但是建议谨慎使用
//auto func3()
//{
//	return 3;
//}
//int main()
//{
//	int a = 10;
//	auto b = a;
//	auto c = 'a';
//	auto d = func1();
//	// 编译报错:rror C3531: “e”: 类型包含“auto”的符号必须具有初始值设定项
//	auto e;
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//	cout << typeid(d).name() << endl;
//	int x = 10;
//	auto y = &x;
//	auto* z = &x;
//	auto& m = x;
//	cout << typeid(x).name() << endl;
//	cout << typeid(y).name() << endl;
//	cout << typeid(z).name() << endl;
//	auto aa = 1, bb = 2;
//	// 编译报错：error C3538: 在声明符列表中，“auto”必须始终推导为同一类型
//	auto cc = 3, dd = 4.0;
//	// 编译报错：error C3318: “auto []”: 数组不能具有其中包含“auto”的元素类型
//	auto array[] = { 4, 5, 6 };
//	return 0;
//}
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


//template<class T1, class T2, ..., class Tn>
//class 类模板名
//{
//	// 类内成员定义
//};
//#include<iostream>
//using namespace std;
//// 类模版
//template<typename T>
//class Stack
//{
//public:
//	Stack(size_t capacity = 4)
//	{
//		_array = new T[capacity];
//		_capacity = capacity;
//		_size = 0;
//	}
//	void Push(const T& data);
//private:
//	T* _array;
//	size_t _capacity;
//	size_t _size;
//};
//// 模版不建议声明和定义分离到两个文件.h 和.cpp会出现链接错误，具体原因后面会讲
//template<class T>
//void Stack<T>::Push(const T& data)
//{
//	// 扩容
//	_array[_size] = data;
//	++_size;
//}
//int main()
//{
//	Stack<int> st1; // int
//	Stack<double> st2; // double
//	return 0;
//}




//// 专门处理int的加法函数
//int Add(int left, int right)
//{
//	return left + right;
//}
//// 通用加法函数
//template<class T1, class T2>
//T1 Add(T1 left, T2 right)
//{
//	return left + right;
//}
//void Test()
//{
//	Add(1, 2); // 与非函数模板类型完全匹配，不需要函数模板实例化
//	Add(1, 2.0); // 模板函数可以生成更加匹配的版本，编译器根据实参生成更加匹配的
//	Add函数
//}


//// 专门处理int的加法函数
//int Add(int left, int right)
//{
//	return left + right;
//}
//// 通用加法函数
//template<class T>
//T Add(T left, T right)
//{
//	return left + right;
//}
//void Test()
//{
//	Add(1, 2); // 与非模板函数匹配，编译器不需要特化
//	Add<int>(1, 2); // 调用编译器特化的Add版本
//}

//int main(void)
//{
//	int a = 10;
//	double b = 20.0;
//	// 显式实例化
//	Add<int>(a, b);
//	return 0;
//}





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
//	注意：在模板中，编译器一般不会进行类型转换操作，因为一旦转化出问题，编译器就需要
//背黑锅
//Add(a1, d1);
//*/
//// 此时有两种处理方式：1. 用户自己来强制转化 2. 使用显式实例化
//	Add(a, (int)d);
//	return 0;
//}



//template<typename T>
//void Swap(T& left, T& right)
//{
//	T temp = left;
//	left = right;
//	right = temp;
//}

//void Swap(int& left, int& right)
//{
//	int temp = left;
//	left = right;
//	right = temp;
//}
//void Swap(double& left, double& right)
//{
//	double temp = left;
//	left = right;
//	right = temp;
//}
//void Swap(char& left, char& right)
//{
//	char temp = left;
//	left = right;
//	right = temp;
//}
//......

//class A
//{
//public:
//	A(int a = 0)
//		: _a(a)
//	{
//		cout << "A():" << this << endl;
//	}
//	~A()
//	{
//		cout << "~A():" << this << endl;
//	}
//private:
//	int _a;
//};
//// 定位new/replacement new
//int main()
//{
//	// p1现在指向的只不过是与A对象相同大小的一段空间，还不能算是一个对象，因为构造函数没
//	有执行
//		A* p1 = (A*)malloc(sizeof(A));
//	new(p1)A; // 注意：如果A类的构造函数有参数时，此处需要传参
//	p1->~A();
//	free(p1);
//	A* p2 = (A*)operator new(sizeof(A));
//	new(p2)A(10);
//	p2->~A();
//	operator delete(p2);
//	return 0;
//}

///*
//operator new：该函数实际通过malloc来申请空间，当malloc申请空间成功时直接返回；申请空间
//失败，尝试执行空 间不足应对措施，如果改应对措施用户设置了，则继续申请，否
//则抛异常。
//*/
//void* __CRTDECL operator new(size_t size) _THROW1(_STD bad_alloc)
//{
//	// try to allocate size bytes
//	void* p;
//	while ((p = malloc(size)) == 0)
//		if (_callnewh(size) == 0)
//		{
//			// report no memory
//			// 如果申请内存失败了，这里会抛出bad_alloc 类型异常
//			static const std::bad_alloc nomem;
//			_RAISE(nomem);
//		}
//	return (p);
//}
///*
//operator delete: 该函数最终是通过free来释放空间的
//*/
//void operator delete(void* pUserData)
//{
//	_CrtMemBlockHeader* pHead;
//	RTCCALLBACK(_RTC_Free_hook, (pUserData, 0));
//	if (pUserData == NULL)
//		return;
//	_mlock(_HEAP_LOCK); /* block other threads */
//	__TRY
//		/* get a pointer to memory block header */
//		pHead = pHdr(pUserData);
//	/* verify block type */
//	_ASSERTE(_BLOCK_TYPE_IS_VALID(pHead->nBlockUse));
//	_free_dbg(pUserData, pHead->nBlockUse);
//	__FINALLY
//		_munlock(_HEAP_LOCK); /* release other threads */
//	__END_TRY_FINALLY
//		return;
//}
///*
//free的实现
//*/
//#define free(p) _free_dbg(p, _NORMAL_BLOCK)


//class A
//{
//public:
//	A(int a = 0)
//		: _a(a)
//	{
//		cout << "A():" << this << endl;
//	}
//	~A()
//	{
//		cout << "~A():" << this << endl;
//	}
//private:
//	int _a;
//};
//int main()
//{
//	// new/delete 和 malloc/free最大区别是 new/delete对于【自定义类型】除了开空间
//	还会调用构造函数和析构函数
//		A* p1 = (A*)malloc(sizeof(A));
//	A* p2 = new A(1);
//	free(p1);
//	delete p2;
//	// 内置类型是几乎是一样的
//	int* p3 = (int*)malloc(sizeof(int)); // C
//	int* p4 = new int;
//	free(p3);
//	delete p4;
//	A* p5 = (A*)malloc(sizeof(A) * 10);
//	A* p6 = new A[10];
//	free(p5);
//	delete[] p6;
//	return 0;
//}


//void Test()
//{
//	// 动态申请一个int类型的空间
//	int* ptr4 = new int;
//	// 动态申请一个int类型的空间并初始化为10
//	int* ptr5 = new int(10);
//	// 动态申请10个int类型的空间
//	int* ptr6 = new int[3];
//	delete ptr4;
//	delete ptr5;
//	delete[] ptr6;
//}

//void Test()
//{
//	// 1.malloc/calloc/realloc的区别是什么？
//	int* p2 = (int*)calloc(4, sizeof(int));
//	int* p3 = (int*)realloc(p2, sizeof(int) * 10);
//	// 这里需要free(p2)吗？
//	free(p3);
//}

//#include<iostream>
//using namespace std;
//
//
//int globalVar = 1;
//static int staticGlobalVar = 1;
//void Test()
//{
//	static int staticVar = 1;
//	int localVar = 1;
//	int num1[10] = { 1, 2, 3, 4 };
//	char char2[] = "abcd";
//	const char* pChar3 = "abcd";
//	int* ptr1 = (int*)malloc(sizeof(int) * 4);
//	int* ptr2 = (int*)calloc(4, sizeof(int));
//	int* ptr3 = (int*)realloc(ptr2, sizeof(int) * 4);
//	free(ptr1);
//	free(ptr3);
//}
//1. 选择题：
//选项 : A.栈 B.堆 C.数据段(静态区) D.代码段(常量区)
//globalVar在哪里？____
//staticGlobalVar在哪里？____
//staticVar在哪里？____
//localVar在哪里？____
//num1 在哪里？____
//char2在哪里？____
//* char2在哪里？___
//pChar3在哪里？____
//* pChar3在哪里？____
//ptr1在哪里？____
//* ptr1在哪里？____

//class A
//{
//public:
//	A(int a1 = 0, int a2 = 0)
//		:_a1(a1)
//		, _a2(a2)
//	{
//		cout << "A(int a1 = 0, int a2 = 0)" << endl;
//	}
//
//	A(const A& aa)
//		:_a1(aa._a1)
//	{
//		cout << "A(const A& aa)" << endl;
//	}
//
//	A& operator=(const A& aa)
//	{
//		cout << "A& operator=(const A& aa)" << endl;
//		if (this != &aa)
//		{
//			_a1 = aa._a1;
//		}
//		return *this;
//	}
//
//	~A()
//	{
//		//delete _ptr;
//		cout << "~A()" << endl;
//	}
//
//	void Print()
//	{
//		cout << "A::Print->" << _a1 << endl;
//	}
//
//	A& operator++()
//	{
//		_a1 += 100;
//
//		return *this;
//	}
//private:
//	int _a1 = 1;
//	int _a2 = 1;
//};
//
//
//class A
//{
//public:
//	A(int a = 0)
//		:_a1(a)
//	{
//		cout << "A(int a)" << endl;
//	}
//	A(const A& aa)
//		:_a1(aa._a1)
//	{
//		cout << "A(const A& aa)" << endl;
//	}
//	A& operator=(const A& aa)
//	{
//		cout << "A& operator=(const A& aa)" << endl;
//		if (this != &aa)
//		{
//			_a1 = aa._a1;
//		}
//		return *this;
//	}
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//
//	void Print()
//	{
//		cout << "A::Print->" << _a1 << endl;
//	}
//
//private:
//	int _a1 = 1;
//	int _a2 = 1;
//};
//void f1(A aa)
//{}
//A f2()
//{
//	A aa;
//	return aa;
//}
//int main()
//{
//	// 传值传参
//	A aa1;
//	f1(aa1);
//	cout << endl;
//	// 隐式类型，连续构造+拷贝构造->优化为直接构造
//	f1(1);
//	// 一个表达式中，连续构造+拷贝构造->优化为一个构造
//	f1(A(2));
//	cout << endl;
//	cout << "***********************************************" << endl;
//	// 传值返回
//// 返回时一个表达式中，连续拷贝构造+拷贝构造->优化一个拷贝构造 （vs2019 debug）
//// 一些编译器会优化得更厉害，进行跨行合并优化，直接变为构造。（vs2022 debug）
//	f2();
//	cout << endl;
//	// 返回时一个表达式中，连续拷贝构造+拷贝构造->优化一个拷贝构造 （vs2019 debug）
//	// 一些编译器会优化得更厉害，进行跨行合并优化，直接变为构造。（vs2022 debug）
//	A aa2 = f2();
//	cout << endl;
//	// 一个表达式中，连续拷贝构造+赋值重载->无法优化
//	aa1 = f2();
//	cout << endl;
//	return 0;
//}


////class Date
////{
////public:
////	Date* operator&()
////	{
////		return this;
////		// return nullptr;
////	}
////	const Date* operator&()const
////	{
////		return this;
////		// return nullptr;
////	}
////private:
////	int _year; // 年
////	int _month; // 月
////	int _day; // 日
////};
//
//
//#include<iostream>
//using namespace std;
//class A
//{
//private:
//	static int _k;
//	int _h = 1;
//public:
//	class B // B默认就是A的友元，可以访问A私有或者保护的数据
//	{
//	public:
//		void foo(const A& a)
//		{
//			cout << _k << endl; //OK
//			cout << a._h << endl; //OK
//		}
//	};
//};
//int A::_k = 1;
//int main()
//{
//	cout << sizeof(A) << endl;
//	A::B b;
//	A aa;
//	b.foo(aa);
//	//A::C c;受到A访问限定符限制,C类无法从外部访问
//	return 0;
//}
//class A
//{
//public:
//	A()
//	{
//		++_scount;
//	}
//
//	A(const A& t)
//	{
//		++_scount;
//	}
//
//	~A()
//	{
//		--_scount;
//	}
//
//	static int GetACount()
//	{
//		//_a++;没有this指针，不能访问
//		return _scount;
//	}
//
//	void func()//非静态的成员函数，可以访问任意的静态成员变量和静态成员函数
//	{
//		cout << _scount << endl;
//		cout << GetACount() << endl;
//	}
//
//
//private:
//	// 类里面声明
//	static int _scount;
//
//	int _a = 1;
//};
//
//// 类外面初始化
//int A::_scount = 0;
//
//int main()
//{
//	//cout << A::_scount << endl;
//	//cout << sizeof(A) << endl;
//
//
//	//a1、a2、a3创建调用构造函数对静态成员++，验证静态_scount为整个类共有
//	cout << A::GetACount() << endl;
//	A a1, a2;
//
//	{//代码块构成局部域,a3出了作用域就销毁
//		A a3(a1);
//		cout << A::GetACount() << endl;
//	}
//
//	// 突破类域就可以访问静态成员，可以通过类名::静态成员 或者 对象.
//	// 静态成员 来访问静态成员变量和静态成员函数
//	cout << A::GetACount() << endl;
//	cout << a1.GetACount() << endl;
//
//	// 编译报错：error C2248: “A::_scount”: 无法访问 private 成员(在“A”类中声明)
////cout << A::_scount << endl;
//	return 0;
//}

//#include<iostream>
//using namespace std;
//class A
//{
//public:
//	A()
//	{
//		++_scount;
//	}
//	A(const A& t)
//	{
//		++_scount;
//	}
//	~A()
//	{
//		--_scount;
//	}
//	static int GetACount()
//	{
//		return _scount;
//	}
//private:
//	// 类里面声明
//	static int _scount;
//};
//// 类外面初始化
//int A::_scount = 0;
//int main()
//{
//	cout << A::GetACount() << endl;
//	A a1, a2;
//	A a3(a1);
//	cout << A::GetACount() << endl;
//	cout << a1.GetACount() << endl;
//	// 编译报错：error C2248: “A::_scount”: 无法访问 private 成员(在“A”类中声明)
//	//cout << A::_scount << endl;
//	return 0;
//}

//int main() {
//
//	int a;
//	a = 0;
//
//
//	return 0;
//}

//class Time
//{
//public:
//	Time(int hour)//需要传参，不是默认构造
//		:_hour(hour)
//	{
//		cout << "Time()" << endl;
//	}
//private:
//	int _hour;
//};
//
//class Date
//{
//public:
//	Date(int& xx, int year, int month, int day)
//		:_year(year)
//		,_month(month)
//		,_day(day)
//		,_n(1)
//		,_ref(xx)
//		,_t(1)
//		,_ptr((int*)malloc(12))
//	{
//		if (_ptr == nullptr)
//		{
//			perror("malloc fail");
//		}
//		else
//		{
//			memset(_ptr, 0, 12);
//		}
//	}
//
//	void Print() const
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//private:
//	// 声明
//	int _year;
//	int _month;
//	int _day;
//
//	// error C2512: “Time”: 没有合适的默认构造函数可用
//	// error C2530 : “Date::_ref” : 必须初始化引用
//	// error C2789 : “Date::_n” : 必须初始化常量限定类型的对象
//	const int _n;
//	int& _ref;
//	Time _t;
//
//	int* _ptr;
//};
//
//int main()
//{
//	int x = 0;
//	// 对象定义
//	Date d1(x, 2024, 7, 14);
//	d1.Print();
//
//	//const int x = 1;
//	// x = 1;
//
//	//int& rx;
//
//	return 0;
//}


//#include<iostream>
//using namespace std;
//class Time
//{
//public:
//	Time(int hour)//需要传参，不是默认构造
//		:_hour(hour)
//	{
//		cout << "Time()" << endl;
//	}
//private:
//	int _hour;
//};
//class Date
//{
//public:
//	Date(int& x, int year = 1, int month = 1, int day = 1)
//		:_year(year)
//		, _month(month + 1)
//		, _day(day)
//		, _t(12)
//		, _ref(x)
//		, _n(1)
//	{
//		// error C2512: “Time”: 没有合适的默认构造函数可用
//		// error C2530 : “Date::_ref” : 必须初始化引用
//		// error C2789 : “Date::_n” : 必须初始化常量限定类型的对象
//	}
//	void Print() const
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//	Time _t; // 没有默认构造
//	int& _ref; // 引用
//	const int _n; // const
//};
//int main()
//{
//	int i = 0;
//	Date d1(i);
//	d1.Print();
//	return 0;
//}



//#include<iostream>
//using namespace std;
//class A
//{
//public:
//	//// 构造函数加了explicit就不再支持隐式类型转换
//	// explicit A(int a = 0)
//	A(int a = 0)
//	{
//		_a1 = a;
//	}
//
//	A(const A& aa)
//	{
//		_a1 = aa._a1;
//	}
//
//	A(int a1, int a2)
//		:_a1(a1)
//		, _a2(a2)
//	{}
//
//	void Print() {
//		cout << _a1 << " " << _a2 << endl;
//	}
//private:
//	int _a1;
//	int _a2;
//};
//
//class Stack
//{
//public:
//	void Push(const A& aa)
//	{
//		//...
//	}
//private:
//	A _arr[10];
//	int _top;
//};
//
//int main()
//{
//	A aa1(1);
//	aa1.Print();
//
//	// 隐式类型转换
//	// 2构造一个A的临时对象，再用这个临时对象拷贝构造aa2
//	// 编译器遇到连续构造+拷贝构造->优化为直接构造
//	A aa2 = 2;
//	aa2.Print();
//
//	A& raa1 = aa2;
//	const A& raa2 = 2;
//
//	int i = 1;
//	double d = i;
//	const double& rd = i;
//
//	Stack st;
//
//	A aa3(3);
//	st.Push(aa3);
//
//	st.Push(3);
//
//	// C++11之后才支持多参数转化
//	A aa5 = { 1, 1 };
//	const A& raa6 = { 2,2 };
//	st.Push(aa5);
//	st.Push({ 2,2 });
//
//	return 0;
//}
//#include<iostream>
//using namespace std;
//class A
//{
//public:
//	// 构造函数explicit就不再支持隐式类型转换
//	// explicit A(int a1)
//	A(int a1)
//		:_a1(a1)
//	{}
//	//explicit A(int a1, int a2)
//	A(int a1, int a2)
//		:_a1(a1)
//		, _a2(a2)
//	{}
//	void Print()
//	{
//		cout << _a1 << " " << _a2 << endl;
//	}
//	int Get() const
//	{
//		return _a1 + _a2;
//	}
//private:
//	int _a1 = 1;
//	int _a2 = 2;
//};
//class B
//{
//public:
//	B(const A& a)
//		:_b(a.Get())
//	{}
//private:
//	int _b = 0;
//};
//int main()
//{
//	// 1构造一个A的临时对象，再用这个临时对象拷贝构造aa3
//	// 编译器遇到连续构造+拷贝构造->优化为直接构造
//	A aa1 = 1;
//	aa1.Print();
//	const A& aa2 = 1;
//	// C++11之后才支持多参数转化
//	A aa3 = { 2,2 };
//	// aa3隐式类型转换为b对象
//	// 原理跟上面类似
//	B b = aa3;
//	const B& rb = aa3;
//	return 0;
//}


//typedef int STDataType;
//class Stack
//{
//public:
//	Stack(int n = 4)
//	{
//		_a = (STDataType*)malloc(sizeof(STDataType) * n);
//		if (nullptr == _a)
//		{
//			perror("malloc申请空间失败");
//			return;
//		}
//		_capacity = n;
//		_top = 0;
//	}
//
//	// st2(st1)
//	Stack(const Stack& st)
//	{
//		cout << "Stack(const Stack& st)" << endl;
//
//		// 需要对_a指向资源创建同样大的资源再拷贝值
//		_a = (STDataType*)malloc(sizeof(STDataType) * st._capacity);
//		if (nullptr == _a)
//		{
//			perror("malloc申请空间失败!!!");
//			return;
//		}
//		memcpy(_a, st._a, sizeof(STDataType) * st._top);
//		_top = st._top;
//		_capacity = st._capacity;
//	}
//
//	void Push(STDataType x)
//	{
//		if (_top == _capacity)
//		{
//			int newcapacity = _capacity * 2;
//			STDataType* tmp = (STDataType*)realloc(_a, newcapacity *
//				sizeof(STDataType));
//			if (tmp == NULL)
//			{
//				perror("realloc fail");
//				return;
//			}
//			_a = tmp;
//			_capacity = newcapacity;
//		}
//		_a[_top++] = x;
//
//	}
//	~Stack()
//	{
//		cout << "~Stack()" << endl;
//		free(_a);
//		_a = nullptr;
//		_top = _capacity = 0;
//	}
//private:
//	STDataType* _a;
//	size_t _capacity;
//	size_t _top;
//};
//
//int main()
//{
//	Stack st1;
//	st1.Push(1);
//	st1.Push(2);
//
//	// Stack不显示实现拷贝构造，用自动生成的拷贝构造完成浅拷贝
//	// 会导致st1和st2里面的_a指针指向同一块资源，析构时会析构两次，程序崩溃
//	Stack st2(st1);
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//class Date
//{
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	// 编译报错：error C2652: “Date”: 非法的复制构造函数: 第一个参数不应是“Date”
//	//Date(Date d)
//	Date(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//	Date(Date* d)
//	{
//		_year = d->_year;
//		_month = d->_month;
//		_day = d->_day;
//	}
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//void Func1(Date d)
//{
//	cout << &d << endl;
//	d.Print();
//}
//// Date Func2()
//Date& Func2()
//{
//	Date tmp(2024, 7, 5);
//	tmp.Print();
//	return tmp;
//}
//int main()
//{
//	Date d1(2024, 7, 5);
//	// C++规定自定义类型对象进行拷贝行为必须调用拷贝构造，所以这里传值传参要调用拷贝
//	//构造
//		// 所以这里的d1传值传参给d要调用拷贝构造完成拷贝，传引用传参可以较少这里的拷贝
//	Func1(d1);
//	cout << &d1 << endl;
//
//	// 这里可以完成拷贝，但是不是拷贝构造，只是一个普通的构造
//	Date d2(&d1);
//	d1.Print();
//	d2.Print();
//
//	//这样写才是拷贝构造，通过同类型的对象初始化构造，而不是指针
//	Date d3(d1);
//	d2.Print();
//
//	// 也可以这样写，这里也是拷贝构造
//	Date d4 = d1;
//	d2.Print();
//
//	// Func2返回了一个局部对象tmp的引用作为返回值
//	// Func2函数结束，tmp对象就销毁了，相当于了一个野引用
//	Date ret = Func2();
//	ret.Print();
//	return 0;
//}

//#include<iostream>
//using namespace std;
//class Date
//{
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//	int Getyeat() {
//		return _year;
//	}
//
//	int Getmonth() {
//		return _month;
//	}	
//
//	int Getday() {
//		return _day;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//
//};
//// 重载为全局的面临对象访问私有成员变量的问题
//// 有几种方法可以解决：
//// 1、成员放公有
//// 2、Date提供getxxx函数
//// 3、友元函数
//// 4、重载为成员函数
//bool operator==(const Date& d1, const Date& d2)
//{
//	return d1._year == d2._year
//		&& d1._month == d2._month
//		&& d1._day == d2._day;
//}
//int main()
//{
//	Date d1(2024, 7, 5);
//	Date d2(2024, 7, 6);
//	// 运算符重载函数可以显示调用
//	operator==(d1, d2);
//	// 编译器会转换成 operator==(d1, d2);
//	d1 == d2;
//	return 0;
//}

//#include<iostream>
//using namespace std;
//class A
//{
//public:
//	void Print()
//	{
//		cout << "A::Print()" << endl;
//		cout << _a << endl;//实质上是this->_a
//	}
//private:
//	int _a;
//};
//int main()
//{
//	A* p = nullptr;
//	p->Print();
//	return 0;
//}

//#include<iostream>
//using namespace std;
//class Date
//{
//public:
//	// void Init(Date* const this, int year, int month, int day)
//	void Init(int year, int month, int day)
//	{
//		this->_year = year;
//		this->_month = month;
//		this->_day = day;
//	}
//
//	// void Print(Date* const this)
//	void Print()
//	{
//		cout << this->_year << "/" << this->_month << "/" << _day << endl;
//	}
//
//private:
//	// 这里只是声明，没有开空间
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	// Date类实例化出对象d1和d2
//	Date d1;
//	Date d2;
//
//	// d1.Init(&d1, 2024, 3, 31);
//	d1.Init(2024, 3, 31);
//	// d1.Print(&d1);
//	d1.Print();
//
//	// d2.Init(&d2, 2024, 7, 5);
//	d2.Init(2024, 7, 5);
//	// d2.Print(&d2);
//	d2.Print();
//
//	return 0;
//}



//#include<iostream>
//using namespace std;
//
//class Stack//类定义在全局位置
//{
//public://访问限定符可可以定义多个
//	void Push(int x)
//	{}
//
//private://访问限定符定义顺序不一定
//	int* a;
//	int top;
//	int capacity;
//
//public:
//	void Pop()
//	{}
//
//private:
//
//	int Top()
//	{
//		return 0;
//	}
//
//};
//
//int main()
//{
//	Stack st;
//	st.Pop();
//	st.Push(1);
//	//st.a;
//
//	return 0;
//}




//#include <iostream>
//using namespace std;
//
//int main() {
//    string str;
//    getline(cin, str);
//    int pos = str.rfind(' ');
//    cout << str.size() - pos - 1;
//    return 0;
//}
// 64 位输出请用 printf("%lld")


//class Solution {
//public:
//    int firstUniqChar(string s) {
//        int arr[256] = { 0 };
//        for (auto ch : s) {
//            arr[ch]++;
//        }
//        for (int i = 0; i < s.size(); i++) {
//            if (arr[s[i]] == 1)
//                return i;
//        }
//        return -1;
//    }
//};


//翻转字符串II：区间部分翻转


//class Solution {
//public:
//    string reverseStr(string s, int k) {
//        auto begin = s.begin();
//        auto end = s.end();
//        while (end - begin >= 2 * k) {
//            reverse(begin, begin + k);
//            begin += 2 * k;
//        }
//
//
//        if (end - begin < k) {
//            reverse(begin, end);
//        }
//        else if ((end - begin) >= k && (end - begin) < 2 * k) {
//            reverse(begin, begin + k);
//        }
//
//
//        return s;
//    }
//};
//class Solution {
//public:
//    string reverseStr(string s, int k) {
//        auto begin = s.begin();
//        auto end = s.end();
//        int ret = end - begin;
//        while (ret >= 2 * k) {
//            reverse(begin, begin + k - 1);
//            begin += 2 * k;
//            ret = end - begin;
//        }
//
//        if (ret < k) {
//            reverse(s.begin(), s.end() - 1);
//        }
//        else if (ret >= k && ret < 2 * k) {
//            reverse(s.begin(), s.begin() + k - 1);
//        }
//
//        return s;
//    }
//};
//
//int main() {
//
//    Solution().reverseStr("abcdefg",2);
//
//    return 0;
//}





//验证一个字符串是否是回文
//class Solution {
//public:
//    bool isPalindrome(string s) {
//        string tmp;
//        for (auto ch : s) {
//            if (ch >= 'A' && ch <= 'Z') {
//                tmp += ch + 32;
//            }
//            else if (ch >= 'a' && ch <= 'z') {
//                tmp += ch;
//            }
//            else if (ch >= '0' && ch <= '9') {
//                tmp += ch;
//            }
//            else {
//                continue;
//            }
//        }
//        int left = 0;
//        int right = tmp.size() - 1;
//        while (left < right) {
//            if (tmp[left++] != tmp[right--]) {
//                return false;
//            }
//        }
//        return true;
//    }
//};


//class Solution {
//public:
//    bool isPalindrome(string s) {
//        string tmp;
//        for (auto ch : s) {
//            if (ch >= 'A' && ch <= 'Z') {
//                tmp += ch + 32;
//            }
//            else if (ch >= 'a' && ch <= 'z') {
//                tmp += ch;
//            }
//            else {
//                continue;
//            }
//        }
//        int left = 0;
//        int right = tmp.size() - 1;
//        while (left < right) {
//            if (tmp[left] != tmp[right]) {
//                return false;
//            }
//        }
//        return true;
//    }
//};
//
//
//int main() {
//    Solution().isPalindrome("A man, a plan, a canal: Panama");
//
//
//    return 0;
//}






//
////字符串里面最后一个单词的长度
//#include <iostream>
//using namespace std;
//
//int main() {
//    string str;
//    getline(cin, str);
//    int i = str.size() - 1;
//    for (; i > 0; i--) {
//        if (str[i] == ' ')
//            break;
//    }
//    if (i) {
//        cout << str.substr(i).size();
//    }
//    else {
//        cout << str.size();
//    }
//    return 0;
//}


//
//#include <iostream>
//using namespace std;
//
//int main() {
//    string str;
//    while (cin >> str) { // 注意 while 处理多个 case
//        int i = str.size() - 1;
//        for (; i > 0; i--) {
//            if (str[i] == ' ')
//                break;
//        }
//        if (i) {
//            cout << str.substr(i).size();
//        }
//        else {
//            cout << str.size();
//        }
//        return 0;
//    }
//}
//// 64 位输出请用 printf("%lld")


//class string {
//private:
//	char _buff[16];
//	char* _str;
//
//	size_t _size;
//	size_t _capacity;
//
//};





//template<class T>
//T Add(const T& left, const T& right) {
//	return left + right;
//}



//int main() {
//	int i = 1, int j = 2;
//	double m = 1.1, n = 2.2;
//	Swap(i, j);
//
//}

//template<typename T1, typename T2 >
//void func(const T1& x, const T2& y) {
//
//}




//class A {
//public:
//	A(int a = 0)
//		:_a(a) {
//		cout << "A():" << this << endl;
//	}
//
//	~A() {
//		cout << "~A()" << this << endl;
//	}
//
//private :
//	int _a;
//};
//
//int main() {
//	A* p1 = new A(1);
//	delete p1;
//
//	A* p2 = (A*) operator new (sizeof(A));
//	new(p2)A(1);
//	p2->~A();
//	operator delete(p2);
//	return 0;
//
//
//
//}

//#include <iostream>
//using namespace std;
//
//int main() {
//    string str;
//    while (cin >> str) { // 注意 while 处理多个 case
//        int pos = str.find(' ') + 1;
//        //if (pos == -1) {
//            cout << str.size();
//        }
//
//        cout << str.substr(pos).size();
//    }
//}
//// 64 位输出请用 printf("%lld")


////字符串相加
//class Solution {
//public:
//    string addStrings(string num1, string num2) {
//        int end1 = num1.size() - 1;
//        int end2 = num2.size() - 1;
//        string tmp;
//        int next = 0;
//        while (end1 >= 0 || end2 >= 0) {
//            int n1 = end1 < 0 ? 0 : num1[end1--] - '0';
//            int n2 = end2 < 0 ? 0 : num2[end2--] - '0';
//            int ret = n2 + n1 + next;
//            next = ret / 10;
//            ret %= 10;
//            tmp += ret + '0';
//        }
//        if (next)
//            tmp += next + '0';
//
//        reverse(tmp.begin(), tmp.end());
//
//        return tmp;
//    }
//};
//
//int main() {
//    Solution().addStrings("1","9");
//
//    return 0;
//
//}

////class string {
////private:
////	char _buff[16];
////	char* _str;
////
////	size_t _size;
////	size_t _capacity;
////};
//void test_string1() {
//	string s1;
//	string s2("hello world");
//
//	cout << s1 << s2 << endl;
//
//	s2[0] = 'x';
//	cout << s1 << s2 << endl;
//
//	for (size_t i = 0; i < s2.size(); i++) {
//		cout << s2[i] << " ";
//	}
//	cout << endl;
//	auto it = s2.begin();
//	while (it != s2.end()) {
//		*it += 2;
//
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//
//	cout << s2 << endl;
//
//	map<string, string>dict;
//
//	auto mit = dict.begin();
//	for (auto& ch : s2) {
//		ch -= 2;
//		cout << ch << " ";
//	}
//	cout << endl;
//
//	cout << s2 << endl;
//
//}
//void test_string2() {
//	string s2("hello world");
//	string::iterator it = s2.begin();
//}



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