#include<iostream>
#include <functional>

using namespace std;

using placeholders::_1;
using placeholders::_2;
using placeholders::_3;

int Sub(int a, int b)
{
    return (a - b) * 10;
}

int SubX(int a, int b, int c)
{
    return (a - b - c) * 10;
}

class Plus
{
public:
    static int plusi(int a, int b)
    {
        return a + b;
    }
    double plusd(double a, double b)
    {
        return a + b;
    }
};

int main()
{
    auto sub1 = bind(Sub, _1, _2);
    cout << sub1(10, 5) << endl;

    // bind 本质返回的一个仿函数对象
    // 调整参数顺序（不常用）
    // _1代表第一个实参
    // _2代表第二个实参
    // ...
    auto sub2 = bind(Sub, _2, _1);
    cout << sub2(10, 5) << endl;

    // 调整参数个数 （常用）
    auto sub3 = bind(Sub, 100, _1);
    cout << sub3(5) << endl;
    auto sub4 = bind(Sub, _1, 100);
    cout << sub4(5) << endl;

    // 分别绑死第123个参数
    auto sub5 = bind(SubX, 100, _1, _2);
    cout << sub5(5, 1) << endl;
    auto sub6 = bind(SubX, _1, 100, _2);
    cout << sub6(5, 1) << endl;
    auto sub7 = bind(SubX, _1, _2, 100);
    cout << sub7(5, 1) << endl;

    // 成员函数对象进行绑死，就不需要每次都传递了
    function<double(Plus&&, double, double)> f6 = &Plus::plusd;
    Plus pd;
    cout << f6(move(pd), 1.1, 1.1) << endl;
    cout << f6(Plus(), 1.1, 1.1) << endl;

    // bind一般用于，绑死一些固定参数
    function<double(double, double)> f7 = bind(&Plus::plusd, Plus(), _1, _2);
    cout << f7(1.1, 1.1) << endl;
    // 计算复利的lambda
    auto func1 = [](double rate, double money, int year) -> double
        {
            double ret = money;
            for (int i = 0; i < year; i++)
            {
                ret += ret * rate;
            }
            return ret - money;
        };

    // 绑死一些参数，实现出支持不同年华利率，不同金额和不同年份计算出复利的结算利息
    function<double(double)> func3_1_5 = bind(func1, 0.015, _1, 3);
    function<double(double)> func5_1_5 = bind(func1, 0.015, _1, 5);
    function<double(double)> func10_2_5 = bind(func1, 0.025, _1, 10);
    function<double(double)> func20_3_5 = bind(func1, 0.035, _1, 30);
    cout << func3_1_5(1000000) << endl;
    cout << func5_1_5(1000000) << endl;
    cout << func10_2_5(1000000) << endl;
    cout << func20_3_5(1000000) << endl;


    return 0;
}

//struct Goods
//{
//    string _name;  // 名字
//    double _price; // 价格
//    int _evaluate; // 评价
//    // ...
//    Goods(const char* str, double price, int evaluate)
//        : _name(str), _price(price), _evaluate(evaluate)
//    {
//    }
//};
//struct ComparePriceLess
//{
//    bool operator()(const Goods& gl, const Goods& gr)
//    {
//        return gl._price < gr._price;
//    }
//};
//
//struct ComparePriceGreater
//{
//    bool operator()(const Goods& gl, const Goods& gr) { return gl._price > gr._price; }
//};
//
//int main()
//{
//    vector<Goods> v = { {"苹果", 2.1, 5}, {"香蕉", 3, 4}, {"橙子", 2.2, 3}, {"菠萝", 1.5, 4} };
//    // 类似这样的场景，我们实现仿函数对象或者函数指针支持商品中
//    // 不同项的比较，相对还是比较麻烦的，那么这里lambda就很好用了
//    sort(v.begin(), v.end(), ComparePriceLess());
//    sort(v.begin(), v.end(), ComparePriceGreater());
//    sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2)
//        { return g1._price < g2._price; });
//    sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2)
//        { return g1._price > g2._price; });
//    sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2)
//        { return g1._evaluate < g2._evaluate; });
//    sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2)
//        { return g1._evaluate > g2._evaluate; });
//    return 0;
//}


//#include<functional>
//using placeholders::_1;
//using placeholders::_2;
//using placeholders::_3;
//int Sub(int a, int b)
//{
//	return (a - b) * 10;
//}
//int SubX(int a, int b, int c)
//{
//	return (a - b - c) * 10;
//}
//class Plus
//{
//public:
//	static int plusi(int a, int b)
//	{
//		return a + b;
//	}
//	double plusd(double a, double b)
//	{
//		return a + b;
//	}
//};
//int main()
//{
//	auto sub1 = bind(Sub, _1, _2);
//	cout << sub1(10, 5) << endl;
//	// bind 本质返回的一个仿函数对象
//	// 调整参数顺序（不常用）
//	// _1代表第一个实参
//	// _2代表第二个实参
//	// ...
//	auto sub2 = bind(Sub, _2, _1);
//	out << sub2(10, 5) << endl;
//	// 调整参数个数 （常用）
//	auto sub3 = bind(Sub, 100, _1);
//	cout << sub3(5) << endl;
//	auto sub4 = bind(Sub, _1, 100);
//	cout << sub4(5) << endl;
//	// 分别绑死第123个参数
//	auto sub5 = bind(SubX, 100, _1, _2);
//	cout << sub5(5, 1) << endl;
//	auto sub6 = bind(SubX, _1, 100, _2);
//	cout << sub6(5, 1) << endl;
//	auto sub7 = bind(SubX, _1, _2, 100);
//	cout << sub7(5, 1) << endl;
//	// 成员函数对象进行绑死，就不需要每次都传递了
//	function<double(Plus&&, double, double)> f6 = &Plus::plusd;
//	Plus pd;
//	cout << f6(move(pd), 1.1, 1.1) << endl;
//	cout << f6(Plus(), 1.1, 1.1) << endl;
//	// bind一般用于，绑死一些固定参数
//	function<double(double, double)> f7 = bind(&Plus::plusd, Plus(), _1, _2);
//	cout << f7(1.1, 1.1) << endl;
//	// 计算复利的lambda
//	auto func1 = [](double rate, double money, int year)->double {
//		double ret = money;
//		for (int i = 0; i < year; i++)
//		{
//			ret += ret * rate;
//		}
//		return ret - money;
//		};
//	// 绑死一些参数，实现出支持不同年华利率，不同金额和不同年份计算出复利的结算利息
//	function<double(double)> func3_1_5 = bind(func1, 0.015, _1, 3);
//	function<double(double)> func5_1_5 = bind(func1, 0.015, _1, 5);
//	function<double(double)> func10_2_5 = bind(func1, 0.025, _1, 10);
//	function<double(double)> func20_3_5 = bind(func1, 0.035, _1, 30);
//	cout << func3_1_5(1000000) << endl;
//	cout << func5_1_5(1000000) << endl;
//	cout << func10_2_5(1000000) << endl;
//	cout << func20_3_5(1000000) << endl;
//	return 0;
//}

//simple(1)
//template <class Fn, class... Args>
///* unspecified */ bind(Fn&& fn, Args&&... args);
//with return type(2)
//template <class Ret, class Fn, class... Args>
///* unspecified */ bind(Fn && fn, Args&&... args);
//// 传统方式的实现
//class Solution {
//public:
//	int evalRPN(vector<string>& tokens) {
//		stack<int> st;
//		for (auto& str : tokens)
//		{
//			if (str == "+" || str == "-" || str == "*" || str == "/")
//			{
//				int right = st.top();
//				st.pop();
//				int left = st.top();
//				st.pop();
//				switch (str[0])
//				{
//				case '+':
//					st.push(left + right);
//					break;
//				case '-':
//					st.push(left - right);
//					break;
//				case '*':
//					st.push(left * right);
//					break;
//				case '/':
//					st.push(left / right);
//					break;
//				}
//			}
//			else
//			{
//				st.push(stoi(str));
//			}
//		}
//		return st.top();
//	}
//};
//// 使用map映射string和function的方式实现
//// 这种方式的最大优势之一是方便扩展，假设还有其他运算，我们增加map中的映射即可
//class Solution {
//public:
//	int evalRPN(vector<string>& tokens) {
//		stack<int> st;
//		// function作为map的映射可调用对象的类型
//		map<string, function<int(int, int)>> opFuncMap = {
//		{"+", [](int x, int y) {return x + y; }},
//		{"-", [](int x, int y) {return x - y; }},
//		{"*", [](int x, int y) {return x * y; }},
//		{"/", [](int x, int y) {return x / y; }}
//		};
//		for (auto& str : tokens)
//		{
//			if (opFuncMap.count(str)) // 操作符
//			{
//				int right = st.top();
//				st.pop();
//				int left = st.top();
//				st.pop();
//				int ret = opFuncMap[str](left, right);
//				st.push(ret);
//			}
//			else
//			{
//				st.push(stoi(str));
//			}
//		}
//		return st.top();
//	}
//};

//#include<functional>
//int f(int a, int b)
//{
//	return a + b;
//}
//struct Functor
//{
//public:
//	int operator() (int a, int b)
//	{
//		return a + b;
//	}
//};
//class Plus
//{
//public:
//	Plus(int n = 10)
//		:_n(n)
//	{
//	}
//	static int plusi(int a, int b)
//	{
//		return a + b;
//	}
//	double plusd(double a, double b)
//	{
//		return (a + b) * _n;
//	}
//private:
//	int _n;
//};
//int main()
//{
//	// 包装各种可调用对象
//	function<int(int, int)> f1 = f;
//	function<int(int, int)> f2 = Functor();
//	function<int(int, int)> f3 = [](int a, int b) {return a + b; };
//	cout << f1(1, 1) << endl;
//	cout << f2(1, 1) << endl;
//	cout << f3(1, 1) << endl;
//	// 包装静态成员函数
//	// 成员函数要指定类域并且前面加&才能获取地址
//	function<int(int, int)> f4 = &Plus::plusi;
//	cout << f4(1, 1) << endl;
//	// 包装普通成员函数
//	// 普通成员函数还有一个隐含的this指针参数，所以绑定时传对象或者对象的指针过去都可以
//	function<double(Plus*, double, double)> f5 = &Plus::plusd;
//	Plus pd;
//	cout << f5(&pd, 1.1, 1.1) << endl;
//	function<double(Plus, double, double)> f6 = &Plus::plusd;
//	cout << f6(pd, 1.1, 1.1) << endl;
//	cout << f6(pd, 1.1, 1.1) << endl;
//	function<double(Plus&&, double, double)> f7 = &Plus::plusd;
//	cout << f7(move(pd), 1.1, 1.1) << endl;
//	cout << f7(Plus(), 1.1, 1.1) << endl;
//	return 0;
//}

//template <class T>
//class function; // undefined
//template <class Ret, class... Args>
//class function<Ret(Args...)>;


//// lambda
//auto r2 = [rate](double money, int year) {
//	return money * rate * year;
//	};
//// 捕捉列表的rate，可以看到作为lambda_1类构造函数的参数传递了，这样要拿去初始化成员变量
//// 下面operator()中才能使用
//00D8295C lea eax, [rate]
//00D8295F push eax
//00D82960 lea ecx, [r2]
//00D82963 call `main'::`2': : <lambda_1>::<lambda_1> (0D81F80h)
//// 函数对象
//Rate r1(rate);
//00D82968 sub esp, 8
//00D8296B movsd xmm0, mmword ptr[rate]
//00D82970 movsd mmword ptr[esp], xmm0
//00D82975 lea ecx, [r1]
//00D82978 call Rate::Rate(0D81438h)
//r1(10000, 2);
//00D8297D push 2
//00D8297F sub esp, 8
//00D82982 movsd xmm0, mmword ptr[__real@40c3880000000000(0D89B50h)]
//00D8298A movsd mmword ptr[esp], xmm0
//00D8298F lea ecx, [r1]
//00D82992 call Rate::operator() (0D81212h)
//// 汇编层可以看到r2 lambda对象调用本质还是调用operator()，类型是lambda_1,这个类型名
//// 的规则是编译器自己定制的，保证不同的lambda不冲突
//r2(10000, 2);
//00D82999 push 2
//00D8299B sub esp, 8
//00D8299E movsd xmm0, mmword ptr[__real@40c3880000000000(0D89B50h)]
//00D829A6 movsd mmword ptr[esp], xmm0
//00D829AB lea ecx, [r2]
//00D829AE call `main'::`2': : <lambda_1>::operator() (0D824C0h)

//class Rate
//{
//public:
//	Rate(double rate)
//		: _rate(rate)
//	{
//	}
//	double operator()(double money, int year)
//	{
//		return money * _rate * year;
//	}
//private:
//	double _rate;
//};
//int main()
//{
//	double rate = 0.49;
//	// lambda
//	auto r2 = [rate](double money, int year) {
//		return money * rate * year;
//		};
//	// 函数对象
//	Rate r1(rate);
//	r1(10000, 2);
//	r2(10000, 2);
//	auto func1 = [] {
//		cout << "hello world" << endl;
//		};
//	func1();
//	return 0;
//}

//struct Goods
//{
//	string _name; // 名字
//	double _price; // 价格
//	int _evaluate; // 评价
//	// ...
//	Goods(const char* str, double price, int evaluate)
//		:_name(str)
//		, _price(price)
//		, _evaluate(evaluate)
//	{
//	}
//};
//struct ComparePriceLess
//{
//	bool operator()(const Goods& gl, const Goods& gr)
//	{
//		return gl._price < gr._price;
//	}
//};
//struct ComparePriceGreater
//{
//	bool operator()(const Goods& gl, const Goods& gr)
//	{
//		return gl._price > gr._price;
//	}
//};
//int main()
//{
//	vector<Goods> v = { { "苹果", 2.1, 5 }, { "香蕉", 3, 4 }, { "橙子", 2.2, 3
//	}, { "菠萝", 1.5, 4 } };
//	// 类似这样的场景，我们实现仿函数对象或者函数指针支持商品中
//	// 不同项的比较，相对还是比较麻烦的，那么这里lambda就很好用了
//	sort(v.begin(), v.end(), ComparePriceLess());
//	sort(v.begin(), v.end(), ComparePriceGreater());
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2) {
//		return g1._price < g2._price;
//		});
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2) {
//		return g1._price > g2._price;
//		});
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2) {
//		return g1._evaluate < g2._evaluate;
//		});
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2) {
//		return g1._evaluate > g2._evaluate;
//		});
//	return 0;
//}

//int x = 0;
//// 捕捉列表必须为空，因为全局变量不用捕捉就可以用，没有可被捕捉的变量
//auto func1 = []()
//	{
//		x++;
//	};
//int main()
//{
//	// 只能用当前lambda局部域和捕捉的对象和全局对象
//	int a = 0, b = 1, c = 2, d = 3;
//	auto func1 = [a, &b]
//		{
//			// 值捕捉的变量不能修改，引用捕捉的变量可以修改
//			//a++;
//			b++;
//			int ret = a + b;
//			return ret;
//		};
//	cout << func1() << endl;
//	// 隐式值捕捉
//	// 用了哪些变量就捕捉哪些变量
//	auto func2 = [=]
//		{
//			int ret = a + b + c;
//			return ret;
//		};
//	cout << func2() << endl;
//	// 隐式引用捕捉
//	// 用了哪些变量就捕捉哪些变量
//	auto func3 = [&]
//		{
//			a++;
//			c++;
//			d++;
//		};
//	func3();
//	cout << a << " " << b << " " << c << " " << d << endl;
//	// 混合捕捉1
//	auto func4 = [&, a, b]
//		{
//			//a++;
//			//b++;
//			c++;
//			d++;
//			return a + b + c + d;
//		};
//	func4();
//	cout << a << " " << b << " " << c << " " << d << endl;
//	// 混合捕捉1
//	auto func5 = [=, &a, &b]
//		{
//			a++;
//			b++;
//			/*c++;
//			d++;*/
//			return a + b + c + d;
//		};
//	func5();
//	cout << a << " " << b << " " << c << " " << d << endl;
//	// 局部的静态和全局变量不能捕捉，也不需要捕捉
//	static int m = 0;
//	auto func6 = []
//		{
//			int ret = x + m;
//			return ret;
//		};
//	// 传值捕捉本质是一种拷贝,并且被const修饰了
//	// mutable相当于去掉const属性，可以修改了
//	// 但是修改了不会影响外面被捕捉的值，因为是一种拷贝
//	auto func7 = [=]()mutable
//		{
//			a++;
//			b++;
//			c++;
//			d++;
//			return a + b + c + d;
//		};
//	cout << func7() << endl;
//	cout << a << " " << b << " " << c << " " << d << endl;
//	return 0;
//}

//int main()
//{
//	// 一个简单的lambda表达式
//	auto add1 = [](int x, int y)->int {return x + y; };
//	cout << add1(1, 2) << endl;
//	// 1、捕捉为空也不能省略
//	// 2、参数为空可以省略
//	// 3、返回值可以省略，可以通过返回对象自动推导
//	// 4、函数题不能省略
//	auto func1 = []
//		{
//			cout << "hello bit" << endl;
//			return 0;
//		};
//	func1();
//	int a = 0, b = 1;
//	auto swap1 = [](int& x, int& y)
//		{
//			int tmp = x;
//			x = y;
//			y = tmp;
//		};
//	swap1(a, b);
//	cout << a << ":" << b << endl;
//	return 0;
//}


//class Person
//{
//public:
//	Person(const char* name = "", int age = 0)
//		:_name(name)
//		, _age(age)
//	{
//	}
//	Person(const Person& p)
//		:_name(p._name)
//		, _age(p._age)
//	{
//	}
//	Person(Person&& p) = default;
//	//Person(const Person& p) = delete;
//private:
//	bit::string _name;
//	int _age;
//};
//int main()
//{
//	Person s1;
//	Person s2 = s1;
//	Person s3 = std::move(s1);
//	return 0;
//}

//class Person
//{
//public:
//	Person(const char* name = "", int age = 0)
//		:_name(name)
//		, _age(age)
//	{
//	}
//	/*Person(const Person& p)
//	:_name(p._name)
//	,_age(p._age)
//	{}*/
//	/*Person& operator=(const Person& p)
//	{
//	if(this != &p)
//	{
//	_name = p._name;
//	_age = p._age;
//	}
//	return *this;
//	}*/
//	/*~Person()
//{}*/
//private:
//	bit::string _name;
//	int _age;
//};
//int main()
//{
//	Person s1;
//	Person s2 = s1;
//	Person s3 = std::move(s1);
//	Person s4;
//	s4 = std::move(s2);
//	return 0;
//}

//#include<list>
//// emplace_back总体而言是更高效，推荐以后使用emplace系列替代insert和push系列
//int main()
//{
//	list<bit::string> lt;
//	// 传左值，跟push_back一样，走拷贝构造
//	bit::string s1("111111111111");
//	lt.emplace_back(s1);
//	cout << "*********************************" << endl;
//	// 右值，跟push_back一样，走移动构造
//	lt.emplace_back(move(s1));
//	cout << "*********************************" << endl;
//	// 直接把构造string参数包往下传，直接用string参数包构造string
//	// 这里达到的效果是push_back做不到的
//	lt.emplace_back("111111111111");
//	cout << "*********************************" << endl;
//	list<pair<bit::string, int>> lt1;
//	// 跟push_back一样
//	// 构造pair + 拷贝/移动构造pair到list的节点中data上
//	pair<bit::string, int> kv("苹果", 1);
//	lt1.emplace_back(kv);
//	cout << "*********************************" << endl;
//	// 跟push_back一样
//	lt1.emplace_back(move(kv));
//	cout << "*********************************" << endl;
//	////////////////////////////////////////////////////////////////////
//	// 直接把构造pair参数包往下传，直接用pair参数包构造pair
//	// 这里达到的效果是push_back做不到的
//	lt1.emplace_back("苹果", 1);
//	cout << "*********************************" << endl;
//	return 0;
//}
//// List.h
//namespace bit
//{
//	template<class T>
//	struct ListNode
//	{
//		ListNode<T>* _next;
//		ListNode<T>* _prev;
//		T _data;
//		ListNode(T&& data)
//			:_next(nullptr)
//			, _prev(nullptr)
//			, _data(move(data))
//		{
//		}
//		template <class... Args>
//		ListNode(Args&&... args)
//			: _next(nullptr)
//			, _prev(nullptr)
//			, _data(std::forward<Args>(args)...)
//		{
//		}
//	};
//	template<class T, class Ref, class Ptr>
//	struct ListIterator
//	{
//		typedef ListNode<T> Node;
//		typedef ListIterator<T, Ref, Ptr> Self;
//		Node* _node;
//		ListIterator(Node* node)
//			:_node(node)
//		{
//		}
//		// ++it;
//		Self& operator++()
//		{
//			_node = _node->_next;
//			return *this;
//		}
//		Self& operator--()
//		{
//			_node = _node->_prev;
//			return *this;
//		}
//		Ref operator*()
//		{
//			return _node->_data;
//		}
//		bool operator!=(const Self& it)
//		{
//			return _node != it._node;
//		}
//	};
//	template<class T>
//	class list
//	{
//		typedef ListNode<T> Node;
//	public:
//		typedef ListIterator<T, T&, T*> iterator;
//		typedef ListIterator<T, const T&, const T*> const_iterator;
//		iterator begin()
//		{
//			return iterator(_head->_next);
//		}
//		iterator end()
//		{
//			return iterator(_head);
//		}
//		void empty_init()
//		{
//			_head = new Node();
//			_head->_next = _head;
//			_head->_prev = _head;
//		}
//		list()
//		{
//			empty_init();
//		}
//		void push_back(const T& x)
//		{
//			insert(end(), x);
//		}
//		void push_back(T&& x)
//		{
//			insert(end(), move(x));
//		}
//		iterator insert(iterator pos, const T& x)
//		{
//			Node* cur = pos._node;
//			Node* newnode = new Node(x);
//			Node* prev = cur->_prev;
//			// prev newnode cur
//			prev->_next = newnode;
//			newnode->_prev = prev;
//			newnode->_next = cur;
//			cur->_prev = newnode;
//			return iterator(newnode);
//		}
//		iterator insert(iterator pos, T&& x)
//		{
//			Node* cur = pos._node;
//			Node* newnode = new Node(move(x));
//			Node* prev = cur->_prev;
//			// prev newnode cur
//			prev->_next = newnode;
//			newnode->_prev = prev;
//			newnode->_next = cur;
//			cur->_prev = newnode;
//			return iterator(newnode);
//		}
//		template <class... Args>
//		void emplace_back(Args&&... args)
//		{
//			insert(end(), std::forward<Args>(args)...);
//		}
//		// 原理：本质编译器根据可变参数模板生成对应参数的函数
//		/*void emplace_back(string& s)
//		{
//		insert(end(), std::forward<string>(s));
//		}
//		void emplace_back(string&& s)
//		{
//		insert(end(), std::forward<string>(s));
//		}
//		void emplace_back(const char* s)
//		{
//		insert(end(), std::forward<const char*>(s));
//		}
//		*/
//		template <class... Args>
//		iterator insert(iterator pos, Args&&... args)
//		{
//			Node* cur = pos._node;
//			Node* newnode = new Node(std::forward<Args>(args)...);
//			Node* prev = cur->_prev;
//			// prev newnode cur
//			prev->_next = newnode;
//			newnode->_prev = prev;
//			newnode->_next = cur;
//			cur->_prev = newnode;
//			return iterator(newnode);
//		}
//	private:
//		Node* _head;
//	};
//}
//// Test.cpp
//#include"List.h"
//// emplace_back总体而言是更高效，推荐以后使用emplace系列替代insert和push系列
//int main()
//{
//	bit::list<bit::string> lt;
//	// 传左值，跟push_back一样，走拷贝构造
//	bit::string s1("111111111111");
//	lt.emplace_back(s1);
//	cout << "*********************************" << endl;
//	// 右值，跟push_back一样，走移动构造
//	lt.emplace_back(move(s1));
//	cout << "*********************************" << endl;
//	// 直接把构造string参数包往下传，直接用string参数包构造string
//	// 这里达到的效果是push_back做不到的
//	lt.emplace_back("111111111111");
//	cout << "*********************************" << endl;
//	bit::list<pair<bit::string, int>> lt1;
//	// 跟push_back一样
//	// 构造pair + 拷贝/移动构造pair到list的节点中data上
//	pair<bit::string, int> kv("苹果", 1);
//	lt1.emplace_back(kv);
//	cout << "*********************************" << endl;
//	// 跟push_back一样
//	lt1.emplace_back(move(kv));
//	cout << "*********************************" << endl;
//	////////////////////////////////////////////////////////////////////
//	// 直接把构造pair参数包往下传，直接用pair参数包构造pair
//	// 这里达到的效果是push_back做不到的
//	lt1.emplace_back("苹果", 1);
//	cout << "*********************************" << endl;
//	return 0;
//}

//// 可变模板参数
//// 参数类型可变
//// 参数个数可变
//// 打印参数包内容
////template <class ...Args>
////void Print(Args... args)
////{
//// // 可变参数模板编译时解析
//// // 下面是运行获取和解析，所以不支持这样用
//// cout << sizeof...(args) << endl;
//// for (size_t i = 0; i < sizeof...(args); i++)
//// {
//// cout << args[i] << " ";
//// }
//// cout << endl;
////}
//void ShowList()
//{
//	// 编译器时递归的终止条件，参数包是0个时，直接匹配这个函数
//	cout << endl;
//}
//template <class T, class ...Args>
//void ShowList(T x, Args... args)
//{
//	cout << x << " ";
//	// args是N个参数的参数包
//	// 调用ShowList，参数包的第一个传给x，剩下N-1传给第二个参数包
//	ShowList(args...);
//}
//// 编译时递归推导解析参数
//template <class ...Args>
//void Print(Args... args)
//{
//	ShowList(args...);
//}
//int main()
//{
//	Print();
//	Print(1);
//	Print(1, string("xxxxx"));
//	Print(1, string("xxxxx"), 2.2);
//	return 0;
//}
////template <class T, class ...Args>
////void ShowList(T x, Args... args)
////{
//// cout << x << " ";
//// Print(args...);
////}
//// Print(1, string("xxxxx"), 2.2);调用时
//// 本质编译器将可变参数模板通过模式的包扩展，编译器推导的以下三个重载函数函数
////void ShowList(double x)
////{
//// cout << x << " ";
//// ShowList();
////}
////
////void ShowList(string x, double z)
////{
//// cout << x << " ";
//// ShowList(z);
////}
////
////void ShowList(int x, string y, double z)
////{
//// cout << x << " ";
//// ShowList(y, z);
////}
////void Print(int x, string y, double z)
////{
//// ShowList(x, y, z);
////}
//template <class T>
//const T& GetArg(const T& x)
//{
//	cout << x << " ";
//	return x;
//}
//template <class ...Args>
//void Arguments(Args... args)
//{
//}
//template <class ...Args>
//void Print(Args... args)
//{
//	// 注意GetArg必须返回或者到的对象，这样才能组成参数包给Arguments
//	Arguments(GetArg(args)...);
//}
//// 本质可以理解为编译器编译时，包的扩展模式
//// 将上面的函数模板扩展实例化为下面的函数
//// 是不是很抽象，C++11以后，只能说委员会的大佬设计语法思维跳跃得太厉害
////void Print(int x, string y, double z)
////{
//// Arguments(GetArg(x), GetArg(y), GetArg(z));
////}
//int main()
//{
//	Print(1, string("xxxxx"), 2.2);
//	return 0;
//}


//template <class ...Args>
//void Print(Args&&... args)
//{
//	cout << sizeof...(args) << endl;
//}
//int main()
//{
//	double x = 2.2;
//	Print(); // 包里有0个参数
//	Print(1); // 包里有1个参数
//	Print(1, string("xxxxx")); // 包里有2个参数
//	Print(1.1, string("xxxxx"), x); // 包里有3个参数
//	return 0;
//}
//// 原理1：编译本质这里会结合引用折叠规则实例化出以下四个函数
//void Print();
//void Print(int&& arg1);
//void Print(int&& arg1, string&& arg2);
//void Print(double&& arg1, string&& arg2, double& arg3);
//// 原理2：更本质去看没有可变参数模板，我们实现出这样的多个函数模板才能支持
//// 这里的功能，有了可变参数模板，我们进一步被解放，他是类型泛化基础
//// 上叠加数量变化，让我们泛型编程更灵活。
//void Print();
//template <class T1>
//void Print(T1&& arg1);
//template <class T1, class T2>
//void Print(T1&& arg1, T2&& arg2);
//template <class T1, class T2, class T3>
//void Print(T1&& arg1, T2&& arg2, T3&& arg3);

//template <class _Ty>
//_Ty&& forward(remove_reference_t<_Ty>& _Arg) noexcept
//{ // forward an lvalue as either an lvalue or an rvalue
//	return static_cast<_Ty&&>(_Arg);
//}
//void Fun(int& x) { cout << "左值引用" << endl; }
//void Fun(const int& x) { cout << "const 左值引用" << endl; }
//void Fun(int&& x) { cout << "右值引用" << endl; }
//void Fun(const int&& x) { cout << "const 右值引用" << endl; }
//template<class T>
//void Function(T&& t)
//{
//	Fun(t);
//	//Fun(forward<T>(t));
//}
//int main()
//{
//	// 10是右值，推导出T为int，模板实例化为void Function(int&& t)
//	Function(10); // 右值
//	int a;
//	// a是左值，推导出T为int&，引用折叠，模板实例化为void Function(int& t)
//	Function(a); // 左值
//	// std::move(a)是右值，推导出T为int，模板实例化为void Function(int&& t)
//	Function(std::move(a)); // 右值
//	const int b = 8;
//	// a是左值，推导出T为const int&，引用折叠，模板实例化为void Function(const int&
//	//t)
//	Function(b); // const 左值
//	// std::move(b)右值，推导出T为const int，模板实例化为void Function(const int&&
//	t)
//	Function(std::move(b)); // const 右值
//	return 0;
//}

//template<class T>
//void Function(T&& t)
//{
//	int a = 0;
//	T x = a;
//	//x++;
//	cout << &a << endl;
//	cout << &x << endl << endl;
//}
//int main()
//{
//	// 10是右值，推导出T为int，模板实例化为void Function(int&& t)
//	Function(10); // 右值
//	int a;
//	// a是左值，推导出T为int&，引用折叠，模板实例化为void Function(int& t)
//	Function(a); // 左值
//	// std::move(a)是右值，推导出T为int，模板实例化为void Function(int&& t)
//	Function(std::move(a)); // 右值
//	const int b = 8;
//	// a是左值，推导出T为const int&，引用折叠，模板实例化为void Function(const int&
//	//t)
//	// 所以Function内部会编译报错，x不能++
//	Function(b); // const 左值
//	// std::move(b)右值，推导出T为const int，模板实例化为void Function(const int&&
//	//t)
//	// 所以Function内部会编译报错，x不能++
//	Function(std::move(b)); // const 右值
//	return 0;
//}



//// 由于引用折叠限定，f1实例化以后总是一个左值引用
//template<class T>
//void f1(T& x)
//{
//}
//// 由于引用折叠限定，f2实例化后可以是左值引用，也可以是右值引用
//template<class T>
//void f2(T&& x)
//{
//}
//int main()
//{
//	typedef int& lref;
//	typedef int&& rref;
//	int n = 0;
//	lref& r1 = n; // r1 的类型是 int&
//	lref&& r2 = n; // r2 的类型是 int&
//	rref& r3 = n; // r3 的类型是 int&
//	rref&& r4 = 1; // r4 的类型是 int&&
//	// 没有折叠->实例化为void f1(int& x)
//	f1<int>(n);
//	f1<int>(0); // 报错
//	// 折叠->实例化为void f1(int& x)
//	f1<int&>(n);
//	f1<int&>(0); // 报错
//	// 折叠->实例化为void f1(int& x)
//	f1<int&&>(n);
//	f1<int&&>(0); // 报错
//	// 折叠->实例化为void f1(const int& x)
//	f1<const int&>(n);
//	f1<const int&>(0);
//	// 折叠->实例化为void f1(const int& x)
//	f1<const int&&>(n);
//	f1<const int&&>(0);
//	// 没有折叠->实例化为void f2(int&& x)
//	f2<int>(n); // 报错
//	f2<int>(0);
//	// 折叠->实例化为void f2(int& x)
//	f2<int&>(n);
//	f2<int&>(0); // 报错
//	// 折叠->实例化为void f2(int&& x)
//	f2<int&&>(n); // 报错
//	f2<int&&>(0);
//	return 0;
//}

//// void push_back (const value_type& val);
//// void push_back (value_type&& val);
//// iterator insert (const_iterator position, value_type&& val);
//// iterator insert (const_iterator position, const value_type& val);
//int main()
//{
//	std::list<bit::string> lt;
//	bit::string s1("111111111111111111111");
//	lt.push_back(s1);
//	cout << "*************************" << endl;
//	lt.push_back(bit::string("22222222222222222222222222222"));
//	cout << "*************************" << endl;
//	lt.push_back("3333333333333333333333333333");
//	cout << "*************************" << endl;
//	lt.push_back(move(s1));
//	cout << "*************************" << endl;
//	return 0;
//}
//运行结果：
//string(char* str)
//string(const string& s) --拷贝构造
//* ************************
//string(char* str)
//string(string && s) --移动构造
//~string() --析构
//* ************************
//string(char* str)
//string(string && s) --移动构造
//~string() --析构
//* ************************
//string(string && s) --移动构造
//* ************************
//~string() --析构
//~string() --析构
//~string() --析构
//~string() --析构
//~string() --析构
//// List.h
//// 以下代码为了控制课件篇幅，把跟这里无关的接口都删除了
//namespace bit
//{
//	template<class T>
//	struct ListNode
//	{
//		ListNode<T>* _next;
//		ListNode<T>* _prev;
//		T _data;
//		ListNode(const T& data = T())
//			:_next(nullptr)
//			, _prev(nullptr)
//			, _data(data)
//		{
//		}
//		ListNode(T&& data)
//			:_next(nullptr)
//			, _prev(nullptr)
//			, _data(move(data))
//		{
//		}
//	};
//	template<class T, class Ref, class Ptr>
//	struct ListIterator
//	{
//		typedef ListNode<T> Node;
//		typedef ListIterator<T, Ref, Ptr> Self;
//		Node* _node;
//		ListIterator(Node* node)
//			:_node(node)
//		{
//		}
//		Self& operator++()
//		{
//			_node = _node->_next;
//			return *this;
//		}
//		Ref operator*()
//		{
//			return _node->_data;
//		}
//		bool operator!=(const Self& it)
//		{
//			return _node != it._node;
//		}
//	};
//	template<class T>
//	class list
//	{
//		typedef ListNode<T> Node;
//	public:
//		typedef ListIterator<T, T&, T*> iterator;
//		typedef ListIterator<T, const T&, const T*> const_iterator;
//		iterator begin()
//		{
//			return iterator(_head->_next);
//		}
//		iterator end()
//		{
//			return iterator(_head);
//		}
//		void empty_init()
//		{
//			_head = new Node();
//			_head->_next = _head;
//			_head->_prev = _head;
//		}
//		list()
//		{
//			empty_init();
//		}
//		void push_back(const T& x)
//		{
//			insert(end(), x);
//		}
//		void push_back(T&& x)
//		{
//			insert(end(), move(x));
//		}
//		iterator insert(iterator pos, const T& x)
//		{
//			Node* cur = pos._node;
//			Node* newnode = new Node(x);
//			Node* prev = cur->_prev;
//			// prev newnode cur
//			prev->_next = newnode;
//			newnode->_prev = prev;
//			newnode->_next = cur;
//			cur->_prev = newnode;
//			return iterator(newnode);
//		}
//		iterator insert(iterator pos, T && x)
//		{
//			Node* cur = pos._node;
//			Node* newnode = new Node(move(x));
//			Node* prev = cur->_prev;
//			// prev newnode cur
//			prev->_next = newnode;
//			newnode->_prev = prev;
//			newnode->_next = cur;
//			cur->_prev = newnode;
//			return iterator(newnode);
//		}
//	private:
//		Node* _head;
//	};
//}
//// Test.cpp
//#include"List.h"
//int main()
//{
//	bit::list<bit::string> lt;
//	cout << "*************************" << endl;
//	bit::string s1("111111111111111111111");
//	lt.push_back(s1);
//	cout << "*************************" << endl;
//	lt.push_back(bit::string("22222222222222222222222222222"));
//	cout << "*************************" << endl;
//	lt.push_back("3333333333333333333333333333");
//	cout << "*************************" << endl;
//	lt.push_back(move(s1));
//	cout << "*************************" << endl;
//	return 0;
//}

//#include<iostream>
//
//using namespace std;
//
//template <class T>
//const T& GetArg(const T& x)
//{
//	cout << x << " ";
//	return x;
//}
//template <class ...Args>
//void Arguments(Args... args)
//{
//}
//template <class ...Args>
//void Print(Args... args)
//{
//	// 注意GetArg必须返回或者到的对象，这样才能组成参数包给Arguments
//	GetArg(args)...;
//}
//
//// 本质可以理解为编译器编译时，包的扩展模式
//// 将上面的函数模板扩展实例化为下面的函数
//// 是不是很抽象，C++11以后，只能说委员会的大佬设计语法思维跳跃得太厉害
////void Print(int x, string y, double z)
////{
//// Arguments(GetArg(x), GetArg(y), GetArg(z));
////}
//int main()
//{
//	Print(1, string("xxxxx"), 2.2);
//	return 0;
//}
//
////namespace bit
////{
////	string addStrings(string num1, string num2)
////	{
////		string str;
////		int end1 = num1.size() - 1, end2 = num2.size() - 1;
////		int next = 0;
////		while (end1 >= 0 || end2 >= 0)
////		{
////			int val1 = end1 >= 0 ? num1[end1--] - '0' : 0;
////			int val2 = end2 >= 0 ? num2[end2--] - '0' : 0;
////			int ret = val1 + val2 + next;
////			next = ret / 10;
////			ret = ret % 10;
////			str += ('0' + ret);
////		}
////		if (next == 1)
////			str += '1';
////		reverse(str.begin(), str.end());
////		cout << "******************************" << endl;
////		return str;
////	}
////}
////// 场景1
////int main()
////{
////	bit::string ret = bit::addStrings("11111", "2222");
////	cout << ret.c_str() << endl;
////	return 0;
////}
////// 场景2
////int main()
////{
////	bit::string ret;
////	ret = bit::addStrings("11111", "2222");
////	cout << ret.c_str() << endl;
////	return 0;
////}
//
////#define _CRT_SECURE_NO_WARNINGS 1
////#include<iostream>
////#include<assert.h>
////#include<string.h>
////#include<algorithm>
////using namespace std;
////namespace bit
////{
////	class string
////	{
////	public:
////		typedef char* iterator;
////		typedef const char* const_iterator;
////		iterator begin()
////		{
////			return _str;
////		}
////		iterator end()
////		{
////			return _str + _size;
////		}
////		const_iterator begin() const
////		{
////			return _str;
////		}
////		const_iterator end() const
////		{
////			return _str + _size;
////		}
////		string(const char* str = "")
////			:_size(strlen(str))
////			, _capacity(_size)
////		{
////			cout << "string(char* str)-构造" << endl;
////			_str = new char[_capacity + 1];
////			strcpy(_str, str);
////		}
////		void swap(string& s)
////		{
////			::swap(_str, s._str);
////			::swap(_size, s._size);
////			::swap(_capacity, s._capacity);
////		}
////		string(const string& s)
////			:_str(nullptr)
////		{
////			cout << "string(const string& s) -- 拷贝构造" << endl;
////			reserve(s._capacity);
////			for (auto ch : s)
////			{
////				push_back(ch);
////			}
////		}
////		// 移动构造
////		string(string&& s)
////		{
////			cout << "string(string&& s) -- 移动构造" << endl;
////			swap(s);
////		}
////		string& operator=(const string& s)
////		{
////			cout << "string& operator=(const string& s) -- 拷贝赋值" <<
////				endl;
////			if (this != &s)
////			{
////				_str[0] = '\0';
////				_size = 0;
////				reserve(s._capacity);
////				for (auto ch : s)
////				{
////					push_back(ch);
////				}
////			}
////			return *this;
////		}
////		// 移动赋值
////		string& operator=(string&& s)
////		{
////			cout << "string& operator=(string&& s) -- 移动赋值" << endl;
////			swap(s);
////			return *this;
////		}
////		~string()
////		{
////			cout << "~string() -- 析构" << endl;
////			delete[] _str;
////			_str = nullptr;
////		}
////		char& operator[](size_t pos)
////		{
////			assert(pos < _size);
////			return _str[pos];
////		}
////		void reserve(size_t n)
////		{
////			if (n > _capacity)
////			{
////				char* tmp = new char[n + 1];
////				if (_str)
////				{
////					strcpy(tmp, _str);
////					delete[] _str;
////				}
////				_str = tmp;
////				_capacity = n;
////			}
////		}
////		void push_back(char ch)
////		{
////			if (_size >= _capacity)
////			{
////				size_t newcapacity = _capacity == 0 ? 4 : _capacity *
////					2;
////				reserve(newcapacity);
////			}
////			_str[_size] = ch;
////			++_size;
////			_str[_size] = '\0';
////		}
////		string& operator+=(char ch)
////		{
////			push_back(ch);
////			return *this;
////		}
////		const char* c_str() const
////		{
////			return _str;
////		}
////		size_t size() const
////		{
////			return _size;
////		}
////private:
////	char* _str = nullptr;
////	size_t _size = 0;
////	size_t _capacity = 0;
////};
////}
////int main()
////{
////	bit::string s1("xxxxx");
////	// 拷贝构造
////	bit::string s2 = s1;
////	// 构造+移动构造，优化后直接构造
////	bit::string s3 = bit::string("yyyyy");
////	// 移动构造
////	bit::string s4 = move(s1);
////	cout << "******************************" << endl;
////	return 0;
////}
//
////class Solution {
////public:
////	// 传值返回需要拷贝
////	string addStrings(string num1, string num2) {
////		string str;
////		int end1 = num1.size() - 1, end2 = num2.size() - 1;
////		// 进位
////		int next = 0;
////		while (end1 >= 0 || end2 >= 0)
////		{
////			int val1 = end1 >= 0 ? num1[end1--] - '0' : 0;
////			int val2 = end2 >= 0 ? num2[end2--] - '0' : 0;
////			int ret = val1 + val2 + next;
////			next = ret / 10;
////			ret = ret % 10;
////			str += ('0' + ret);
////		}
////		if (next == 1)
////			str += '1';
////		reverse(str.begin(), str.end());
////		return str;
////	}
////};
////class Solution {
////public:
////	// 这里的传值返回拷贝代价就太大了
////	vector<vector<int>> generate(int numRows) {
////		vector<vector<int>> vv(numRows);
////		for (int i = 0; i < numRows; ++i)
////		{
////			vv[i].resize(i + 1, 1);
////		}
////		for (int i = 2; i < numRows; ++i)
////		{
////			for (int j = 1; j < i; ++j)
////			{
////				vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1];
////			}
////		}
////		return vv;
////	}
////};
//
//
////#include<iostream>
////using namespace std;
////void f(int& x)
////{
////	std::cout << "左值引用重载 f(" << x << ")\n";
////}
////void f(const int& x)
////{
////	std::cout << "到 const 的左值引用重载 f(" << x << ")\n";
////}
////void f(int&& x)
////{
////	std::cout << "右值引用重载 f(" << x << ")\n";
////}
////int main()
////{
////	int i = 1;
////	const int ci = 2;
////	f(i); // 调用 f(int&)
////	f(ci); // 调用 f(const int&)
////	f(3); // 调用 f(int&&)，如果没有 f(int&&) 重载则会调用 f(const int&)
////	f(std::move(i)); // 调用 f(int&&)
////	// 右值引用变量在用于表达式时是左值
////	int&& x = 1;
////	f(x); // 调用 f(int& x)
////	f(std::move(x)); // 调用 f(int&& x)
////	return 0;
////}
//
////int main()
////{
////	std::string s1 = "Test";
////	// std::string&& r1 = s1; // 错误：不能绑定到左值
////	const std::string& r2 = s1 + s1; // OK：到 const 的左值引用延长生存期
////	// r2 += "Test"; // 错误：不能通过到 const 的引用修改
////	std::string&& r3 = s1 + s1; // OK：右值引用延长生存期
////	r3 += "Test"; // OK：能通过到非 const 的引用修改
////	std::cout << r3 << '\n';
////	return 0;
////}
//
////template <class _Ty>
////remove_reference_t<_Ty>&& move(_Ty&& _Arg)
////{ // forward _Arg as movable
////	return static_cast<remove_reference_t<_Ty>&&>(_Arg);
////}
////#include<iostream>
////using namespace std;
////int main()
////{
////	// 左值：可以取地址
////	// 以下的p、b、c、*p、s、s[0]就是常见的左值
////	int* p = new int(0);
////	int b = 1;
////	const int c = b;
////	*p = 10;
////	string s("111111");
////	s[0] = 'x';
////	double x = 1.1, y = 2.2;
////	// 左值引用给左值取别名
////	int& r1 = b;
////	int*& r2 = p;
////	int& r3 = *p;
////	string& r4 = s;
////	char& r5 = s[0];
////	// 右值引用给右值取别名
////	int&& rr1 = 10;
////	double&& rr2 = x + y;
////	double&& rr3 = fmin(x, y);
////	string&& rr4 = string("11111");
////	// 左值引用不能直接引用右值，但是const左值引用可以引用右值
////	const int& rx1 = 10;
////	const double& rx2 = x + y;
////	const double& rx3 = fmin(x, y);
////	const string& rx4 = string("11111");
////	// 右值引用不能直接引用左值，但是右值引用可以引用move(左值)
////	int&& rrx1 = move(b);
////	int*&& rrx2 = move(p);
////	int&& rrx3 = move(*p);
////	string&& rrx4 = move(s);
////	string&& rrx5 = (string&&)s;
////	// b、r1、rr1都是变量表达式，都是左值
////	cout << &b << endl;
////	cout << &r1 << endl;
////	cout << &rr1 << endl;
////	// 这里要注意的是，rr1的属性是左值，所以不能再被右值引用绑定，除非move一下
////	int& r6 = r1;
////	// int&& rrx6 = rr1;
////	int&& rrx6 = move(rr1);
////	return 0;
////}
//
//
////#include<iostream>
////using namespace std;
////int main()
////{
////	// 左值：可以取地址
////	// 以下的p、b、c、*p、s、s[0]就是常见的左值
////	int* p = new int(0);
////	int b = 1;
////	const int c = b;
////	*p = 10;
////	string s("111111");
////	s[0] = 'x';
////	cout << &c << endl;
////	cout << (void*)&s[0] << endl;
////	// 右值：不能取地址
////	double x = 1.1, y = 2.2;
////	// 以下几个10、x + y、fmin(x, y)、string("11111")都是常见的右值
////	10;
////	x + y;
////	fmin(x, y);
////	string("11111");
////	//cout << &10 << endl;
////	//cout << &(x+y) << endl;
////	//cout << &(fmin(x, y)) << endl;
////	//cout << &string("11111") << endl;
////	return 0;
////}
//
////#include<vector>
////#include<string>
////#include<map>
////using namespace std;
////int main()
////{
////	std::initializer_list<int> mylist;
////	mylist = { 10, 20, 30 };
////	cout << sizeof(mylist) << endl;
////	// 这里begin和end返回的值initializer_list对象中存的两个指针
////	// 这两个指针的值跟i的地址跟接近，说明数组存在栈上
////	int i = 0;
////	cout << mylist.begin() << endl;
////	cout << mylist.end() << endl;
////	cout << &i << endl;
////	// {}列表中可以有任意多个值
////	// 这两个写法语义上还是有差别的，第一个v1是直接构造，
////	// 第二个v2是构造临时对象+临时对象拷贝v2+优化为直接构造
////	vector<int> v1({ 1,2,3,4,5 });
////	vector<int> v2 = { 1,2,3,4,5 };
////	const vector<int>& v3 = { 1,2,3,4,5 };
////	// 这里是pair对象的{}初始化和map的initializer_list构造结合到一起用了
////	map<string, string> dict = { {"sort", "排序"}, {"string", "字符串"} };
////	// initializer_list版本的赋值支持
////	v1 = { 10,20,30,40,50 };
////	return 0;
////}
//
////// STL中的容器都增加了一个initializer_list的构造
////vector(initializer_list<value_type> il, const allocator_type& alloc =
////	allocator_type());
////list(initializer_list<value_type> il, const allocator_type& alloc =
////	allocator_type());
////map(initializer_list<value_type> il, const key_compare& comp =
////	key_compare(), const allocator_type& alloc = allocator_type());
////// ...
////template<class T>
////class vector {
////public:
////	typedef T* iterator;
////	vector(initializer_list<T> l)
////	{
////		for (auto e : l)
////			push_back(e)
////	}
////private:
////	iterator _start = nullptr;
////	iterator _finish = nullptr;
////	iterator _endofstorage = nullptr;
////};
////// 另外，容器的赋值也支持initializer_list的版本
////vector& operator= (initializer_list<value_type> il);
////map& operator= (initializer_list<value_type> il);
//
//
//
////#include<iostream>
////#include<vector>
////using namespace std;
////struct Point
////{
////	int _x;
////	int _y;
////};
////class Date
////{
////public:
////	Date(int year = 1, int month = 1, int day = 1)
////		:_year(year)
////		, _month(month)
////		, _day(day)
////	{
////		cout << "Date(int year, int month, int day)" << endl;
////	}
////	Date(const Date& d)
////		:_year(d._year)
////		, _month(d._month)
////		, _day(d._day)
////	{
////		cout << "Date(const Date& d)" << endl;
////	}
////private:
////	int _year;
////	int _month;
////	int _day;
////};
////// 一切皆可用列表初始化，且可以不加=
////int main()
////{
////	// C++98支持的
////	int a1[] = { 1, 2, 3, 4, 5 };
////	int a2[5] = { 0 };
////	Point p = { 1, 2 };
////	// C++11支持的
////	// 内置类型支持
////	int x1 = { 2 };
////	// 自定义类型支持
////	// 这里本质是用{ 2025, 1, 1}构造一个Date临时对象
////	// 临时对象再去拷贝构造d1，编译器优化后合二为一变成{ 2025, 1, 1}直接构造初始化
////	d1
////		// 运行一下，我们可以验证上面的理论，发现是没调用拷贝构造的
////		Date d1 = { 2025, 1, 1 };
////	// 这里d2引用的是{ 2024, 7, 25 }构造的临时对象
////	const Date& d2 = { 2024, 7, 25 };
////	// 需要注意的是C++98支持单参数时类型转换，也可以不用{}
////	Date d3 = { 2025 };
////	Date d4 = 2025;
////	// 可以省略掉=
////	Point p1{ 1, 2 };
////	int x2{ 2 };
////	Date d6{ 2024, 7, 25 };
////	const Date& d7{ 2024, 7, 25 };
////	// 不支持，只有{}初始化，才能省略=
////	// Date d8 2025;
////	vector<Date> v;
////	v.push_back(d1);
////	v.push_back(Date(2025, 1, 1));
////	// 比起有名对象和匿名对象传参，这里{}更有性价比
////	v.push_back({ 2025, 1, 1 });
////	return 0;
////}
//
////struct Point
////{
////	int _x;
////	int _y;
////};
////int main()
////{
////	int array1[] = { 1, 2, 3, 4, 5 };
////	int array2[5] = { 0 };
////	Point p = { 1, 2 };
////	return 0;
////}


