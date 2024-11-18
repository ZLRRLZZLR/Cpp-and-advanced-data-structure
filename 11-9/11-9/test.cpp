#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

// 以杨慧三角的前n行为例：假设n为5
void test2vector(size_t n)
{
	// 使用vector定义二维数组vv，vv中的每个元素都是vector<int>
	bit::vector<bit::vector<int>> vv(n);
	// 将二维数组每一行中的vecotr<int>中的元素全部设置为1
	for (size_t i = 0; i < n; ++i)
		vv[i].resize(i + 1, 1);
	// 给杨慧三角出第一列和对角线的所有元素赋值
	for (int i = 2; i < n; ++i)
	{
		for (int j = 1; j < i; ++j)
		{
			vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1];
		}
	}
}



//int main()
//{
//	bite::vector<bite::string> v;
//	v.push_back("1111");
//	v.push_back("2222");
//	v.push_back("3333");
//	return 0;
//}


//class Solution {
//public:
//	int singleNumber(vector<int>& nums) {
//		int value = 0;
//		for (auto e : nums)
//		{
//			value ^= e;
//		}
//		return value;
//	}
//};


//#include <string>
//void TestString()
//{
//	string s("hello");
//	auto it = s.begin();
//	// 放开之后代码会崩溃，因为resize到20会string会进行扩容
//	// 扩容之后，it指向之前旧空间已经被释放了，该迭代器就失效了
//	// 后序打印时，再访问it指向的空间程序就会崩溃
//	//s.resize(20, '!');
//	while (it != s.end())
//	{
//		cout << *it;
//		++it;
//	}
//	cout << endl;
//	it = s.begin();
//	while (it != s.end())
//	{
//		it = s.erase(it);
//		// 按照下面方式写，运行时程序会崩溃，因为erase(it)之后
//		// it位置的迭代器就失效了
//		// s.erase(it);
//		++it;
//	}
//}



//// 1. 扩容之后，迭代器已经失效了，程序虽然可以运行，但是运行结果已经不对了
//int main()
//{
//	vector<int> v{ 1,2,3,4,5 };
//	for (size_t i = 0; i < v.size(); ++i)
//		cout << v[i] << " ";
//	cout << endl;
//	auto it = v.begin();
//	cout << "扩容之前，vector的容量为: " << v.capacity() << endl;
//	// 通过reserve将底层空间设置为100，目的是为了让vector的迭代器失效
//	v.reserve(100);
//	cout << "扩容之后，vector的容量为: " << v.capacity() << endl;
//	// 经过上述reserve之后，it迭代器肯定会失效，在vs下程序就直接崩溃了，但是linux
//	下不会
//		// 虽然可能运行，但是输出的结果是不对的
//		while (it != v.end())
//		{
//			cout << *it << " ";
//			++it;
//		}
//	cout << endl;
//	return 0;
//}
//程序输出：
//1 2 3 4 5
//扩容之前，vector的容量为: 5
//扩容之后，vector的容量为 : 100
//0 2 3 4 5 409 1 2 3 4 5
//// 2. erase删除任意位置代码后，linux下迭代器并没有失效
//// 因为空间还是原来的空间，后序元素往前搬移了，it的位置还是有效的
//#include <vector>
//#include <algorithm>
//int main()
//{
//	vector<int> v{ 1,2,3,4,5 };
//	vector<int>::iterator it = find(v.begin(), v.end(), 3);
//	v.erase(it);
//	cout << *it << endl;
//	while (it != v.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//	return 0;
//}
//程序可以正常运行，并打印：
//4
//4 5
//// 3: erase删除的迭代器如果是最后一个元素，删除之后it已经超过end
//// 此时迭代器是无效的，++it导致程序崩溃
//int main()
//{
//	vector<int> v{ 1,2,3,4,5 };
//	// vector<int> v{1,2,3,4,5,6};
//	auto it = v.begin();
//	while (it != v.end())
//	{
//		if (*it % 2 == 0)
//			v.erase(it);
//		++it;
//	}
//	for (auto e : v)
//		cout << e << " ";
//	cout << endl;
//	return 0;
//}
//========================================================
//// 使用第一组数据时，程序可以运行
//[sly@VM - 0 - 3 - centos 20220114]$ g++ testVector.cpp - std = c++11
//[sly@VM - 0 - 3 - centos 20220114]$ . / a.out
//1 3 5
//======================================================== =
//// 使用第二组数据时，程序最终会崩溃
//[sly@VM - 0 - 3 - centos 20220114]$ vim testVector.cpp
//[sly@VM - 0 - 3 - centos 20220114]$ g++ testVector.cpp - std = c++11
//[sly@VM - 0 - 3 - centos 20220114]$ . / a.out
//Segmentation fault




//#include <iostream>
//using namespace std;
//#include <vector>
//int main()
//{
//	vector<int> v{ 1, 2, 3, 4 };
//	auto it = v.begin();
//	while (it != v.end())
//	{
//		if (*it % 2 == 0)
//			v.erase(it);
//		++it;
//	}
//	return 0;
//}
//int main()
//{
//	vector<int> v{ 1, 2, 3, 4 };
//	auto it = v.begin();
//	while (it != v.end())
//	{
//		if (*it % 2 == 0)
//			it = v.erase(it);
//		else
//			++it;
//	}
//	return 0;
//}

//#include <iostream>
//using namespace std;
//#include <vector>
//int main()
//{
//	vector<int> v{ 1,2,3,4,5,6 };
//	auto it = v.begin();
//	// 将有效元素个数增加到100个，多出的位置使用8填充，操作期间底层会扩容
//	// v.resize(100, 8);
//	// reserve的作用就是改变扩容大小但不改变有效元素个数，操作期间可能会引起底层容
//	量改变
//		// v.reserve(100);
//		// 插入元素期间，可能会引起扩容，而导致原空间被释放
//		// v.insert(v.begin(), 0);
//		// v.push_back(8);
//		// 给vector重新赋值，可能会引起底层容量改变
//		v.assign(100, 8);
//	/*
//	出错原因：以上操作，都有可能会导致vector扩容，也就是说vector底层原理旧空间被释
//	放掉，而在打印时，it还使用的是释放之间的旧空间，在对it迭代器操作时，实际操作的是一块
//	已经被释放的空间，而引起代码运行时崩溃。
//	解决方式：在以上操作完成之后，如果想要继续通过迭代器操作vector中的元素，只需给
//	it重新赋值即可。
//	*/
//	while (it != v.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//	return 0;
//}
//2. 指定位置元素的删除操作--erase
//#include <iostream>
//using namespace std;
//#include <vector>
//int main()
//{
//	int a[] = { 1, 2, 3, 4 };
//	vector<int> v(a, a + sizeof(a) / sizeof(int));
//	// 使用find查找3所在位置的iterator
//	vector<int>::iterator pos = find(v.begin(), v.end(), 3);
//	// 删除pos位置的数据，导致pos迭代器失效。
//	v.erase(pos);
//	cout << *pos << endl; // 此处会导致非法访问
//	return 0;
//}


//// 测试vector的默认扩容机制
//void TestVectorExpand()
//{
//	size_t sz;
//	vector<int> v;
//	sz = v.capacity();
//	cout << "making v grow:\n";
//	for (int i = 0; i < 100; ++i)
//	{
//		v.push_back(i);
//		if (sz != v.capacity())
//		{
//			sz = v.capacity();
//			cout << "capacity changed: " << sz << '\n';
//		}
//	}
//}
//vs：运行结果：vs下使用的STL基本是按照1.5倍方式扩容
//making foo grow :
//capacity changed : 1
//capacity changed : 2
//capacity changed : 3
//capacity changed : 4
//capacity changed : 6
//capacity changed : 9
//capacity changed : 13
//capacity changed : 19
//capacity changed : 28
//capacity changed : 42
//capacity changed : 63
//capacity changed : 94
//capacity changed : 141
//g++运行结果：linux下使用的STL基本是按照2倍方式扩容
//making foo grow :
//capacity changed : 1
//capacity changed : 2
//capacity changed : 4
//capacity changed : 8
//capacity changed : 16
//capacity changed : 32
//capacity changed : 64
//capacity changed : 128
//// 如果已经确定vector中要存储元素大概个数，可以提前将空间设置足够
//// 就可以避免边插入边扩容导致效率低下的问题了
//void TestVectorExpandOP()
//{
//	vector<int> v;
//	size_t sz = v.capacity();
//	v.reserve(100); // 提前将容量设置好，可以避免一遍插入一遍扩容
//	cout << "making bar grow:\n";
//	for (int i = 0; i < 100; ++i)
//	{
//		v.push_back(i);
//		if (sz != v.capacity())
//		{
//			sz = v.capacity();
//			cout << "capacity changed: " << sz << '\n';
//		}
//	}
//}




//void test_string5()
//{
//	string s("hello world");
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
//
//	SplitFilename(str1);
//
//}



//void test_string3()
//{
//	string s2("hello world");
//	cout << s2.length() << endl;
//	cout << s2.size() << endl;
//
//	cout << s2.max_size() << endl;
//
//	cout << s2.capacity() << endl;
//
//
//	string s3("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
//	//cout << sizeof(s2) << endl;
//	//cout << sizeof(s3) << endl;
//}

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