#include"Stack.h"
#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
using namespace std;
int main()
{
	int a = 10;
	// 编译报错：“ra”: 必须初始化引用
	//int& ra;
	int& b = a;
	int c = 20;
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	// 这里并非让b引用c，因为C++引用不能改变指向，
	// 这里是一个赋值
	b = c;

	cout << &a << endl;
	cout << &b << endl;
	cout << &c << endl;
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
}

//#include<iostream>
//using namespace std;
//int main()
//{
//	int a = 0;
//	// 引用：b和c是a的别名
//	int& b = a;
//	int& c = a;
//	// 也可以给别名b取别名，d相当于还是a的别名
//	int& d = b;
//	++d;
//	// 这里取地址我们看到是一样的
//	cout << &a << endl;
//	cout << &b << endl;
//	cout << &c << endl;
//	cout << &d << endl;
//	return 0;
//}

//// 下面两个函数构成重载
//// f()但是调用时，会报错，存在歧义，编译器不知道调用谁
//
//void f1()
//{
//	cout << "f()" << endl;
//}
//
//void f1(int a = 10)
//{
//	cout << "f(int a)" << endl;
//}

//#include<iostream>
//using namespace std;
//
//// 1、参数类型不同
//int Add(int left, int right)
//{
//	cout << "int Add(int left, int right)" << endl;
//	return left + right;
//}
//
//double Add(double left, double right)
//{
//	cout << "double Add(double left, double right)" << endl;
//	return left + right;
//}
//
//void Swap(int* px, int* py)
//{}
//
//void Swap(double* px, double* py)
//{}
//
//// 2、参数个数不同
//void f()
//{
//	cout << "f()" << endl;
//}
//void f(int a)
//{
//	cout << "f(int a)" << endl;
//}
//
//// 3、参数类型顺序不同
//void f(int a, char b)
//{
//	cout << "f(int a,char b)" << endl;
//}
//
//void f(char b, int a)
//{
//	cout << "f(char b, int a)" << endl;
//}

// 下面两个函数构成重载
// f()但是调用时，会报错，存在歧义，编译器不知道调用谁

//namespace bit1
//{
//	void f1()
//	{
//		cout << "f()" << endl;
//	}
//}

//#include<iostream>
//using namespace std;
//
//#include"Stack.h"
//
//int main()
//{
//	zlr::ST s1;
//	zlr::STInit(&s1);
//
//	// 确定知道要插入1000个数据，初始化时一把开好，避免扩容
//	zlr::ST s2;
//	zlr::STInit(&s2, 1000);
//
//	for (size_t i = 0; i < 1000; i++)
//	{
//		zlr::STPush(&s2, i);
//	}
//
//	return 0;
//}

//#include <iostream>
//using namespace std;
//// 全缺省
//void Func1(int a = 10, int b = 20, int c = 30)//全缺省
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl << endl;
//}
//// 半缺省
//void Func2(int a, int b = 10, int c = 20)//半缺省
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl << endl;
//}
//int main()
//{
//	Func1();//使用缺省参数设置的默认值
//	Func1(1);
//	Func1(1, 2);//依次赋值
//	Func1(1, 2, 3);
//	Func2(100);
//	Func2(100, 200);
//	Func2(, 200, );//无法跳跃传值
//	return 0;
//}
//#include<iostream>
//using namespace std;
//
//int main()
//{
//
//	int a = 0;
//	double b = 0.1;
//	char c = 'x';
//
//	cout << a << "             " << b << " " << c << "\n" << '\n' << endl;//输出多个空格
//	std::cout << a << " " << b << " " << c << std::endl;//输出单个空格
//	//cout输出不需要指定输出格式，自动识别类型
//
//	//scanf("%d%lf", &a, &b);
//	//printf("%d %lf\n", a, b);
//
//	double d = 2.22222222;
//	printf("%.2lf\n", d);
//	cout << d << endl;
//	cout << &d << endl;
//
//	// cin可以自动识别输入变量的类型
//	//cin >> a;
//	//cin >> b >> c;
//	cin >>a>> b >> c;
//	cout << a << endl;
//	cout << b << " " << c << endl;
//
//	return 0;
//}

// //展开头文件
//#include <stdio.h>
//namespace zlr
//{
//	int a = 0;
//	int b = 1;
//}
//
//using namespace zlr;
//
//
//int main()
//{
//
//	printf("%d\n", a);
//	printf("%d\n", b);
//
//
//	return 0;
//}

//#include <stdio.h>
//namespace zlr
//{
//	int a = 0;
//	int b = 1;
//}
//
//using zlr::a;
//
//int main()
//{
//
//	printf("%d\n", a);
//	printf("%d\n", zlr::b);
//
//
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//// 域
//namespace zlr
//{
//	namespace z1
//	{
//		int rand = 1;
//		int Add(int left, int right)
//		{
//		return left + right;
//		}
//	}
//
//	namespace z2
//	{
//		int rand = 2;
//		int Add(int left, int right)
//		{
//			return (left + right) * 10;
//		}
//	}
//}
//
//int main()
//{
//	printf("%d\n", zlr::z1::rand);
//	printf("%d\n", zlr::z2::rand);
//
//
//	return 0;
//}
//// 域
//namespace bit
//{
//	int rand = 10;
//
//	int Add(int left, int right)
//	{
//		return left + right;
//	}
//
//	struct Node
//	{
//		struct Node* next;
//		int val;
//	};
//}
//
//int main()
//{
//	printf("%d\n", bit::Add(1, 1));
//
//	struct bit::Node p1;
//
//	return 0;
//}

//namespace zlr
//{
//	int rand = 10;
//}
//
//int a = 0;
//
//int main()
//{
//	printf("%p\n", rand);
//	printf("%d\n", zlr::rand);
//
//	int a = 1;
//	printf("%d\n", a);
//
//	// ::域作用限定符
//	printf("%d\n",::a);
//
//	return 0;
//}
//#include<iostream>
//using namespace std;
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
//private:
//	int _a1 = 1;
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





//class A
//{
//public:
//	A(int a = 0)
//		:_a(a)
//	{
//		cout << "A(int a)" << endl;
//	}
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//private:
//	int _a;
//};
//class Solution {
//public:
//	int Sum_Solution(int n) {
//		//...
//		return n;
//	}
//};
//int main()
//{
//	A aa1;
//	// 不能这么定义对象，因为编译器无法识别下面是一个函数声明，还是对象定义
//	//A aa1();
//	// 但是我们可以这么定义匿名对象，匿名对象的特点不用取名字，
//	// 但是他的生命周期只有这一行，我们可以看到下一行他就会自动调用析构函数
//	A();
//	A(1);
//	A aa2(2);
//	// 匿名对象在这样场景下就很好用，当然还有一些其他使用场景，这个我们以后遇到了再说
//	Solution().Sum_Solution(10);
//	return 0;
//}





//class Solution {
//	// 内部类
//	class Sum
//	{
//	public:
//		Sum()
//		{
//			_ret += _i;
//			++_i;
//		}
//	};
//	static int _i;
//	static int _ret;
//public:
//	int Sum_Solution(int n) {
//		// 变长数组
//		Sum arr[n];
//		return _ret;
//	}
//};
//int Solution::_i = 1;
//int Solution::_ret = 0;






//#include<iostream>
//using namespace std;
//class A
//{
//private:
//	static int _k;
//	int _h = 1;
//public:
//	class B // B默认就是A的友元
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
//	return 0;
//}






//#include<iostream>
//using namespace std;
//class A
//{
//	// 友元声明
//	friend class B;
//private:
//	int _a1 = 1;
//	int _a2 = 2;
//};
//class B
//{
//public:
//	void func1(const A& aa)
//	{
//		cout << aa._a1 << endl;
//		cout << _b1 << endl;
//	}
//	void func2(const A& aa)
//	{
//		cout << aa._a2 << endl;
//		cout << _b2 << endl;
//	}
//private:
//	int _b1 = 3;
//	int _b2 = 4;
//};
//int main()
//{
//	A aa;
//	B bb;
//	bb.func1(aa);
//	bb.func1(aa);
//	return 0;
//}




//#include<iostream>
//using namespace std;
//// 前置声明，都则A的友元函数声明编译器不认识B
//class B;
//class A
//{
//	// 友元声明
//	friend void func(const A& aa, const B& bb);
//private:
//	int _a1 = 1;
//	int _a2 = 2;
//};
//class B
//{
//	// 友元声明
//	friend void func(const A& aa, const B& bb);
//private:
//	int _b1 = 3;
//	int _b2 = 4;
//};
//void func(const A& aa, const B& bb)
//{
//	cout << aa._a1 << endl;
//	cout << bb._b1 << endl;
//}
//int main()
//{
//	A aa;
//	B bb;
//	func(aa, bb);
//	return 0;
//}





//A：D B A C
//B：B A D C
//C：C D B A
//D：A B D C
//E：C A B D
//F：C D A B
//C c;
//int main()
//{
//	A a;
//	B b;
//	static D d;
//	return 0；
//}

//class Sum
//{
//public:
//	Sum()
//	{
//		_ret += _i;
//		++_i;
//	}
//	static int GetRet()
//	{
//		return _ret;
//	}
//private:
//	static int _i;
//	static int _ret;
//};
//int Sum::_i = 1;
//int Sum::_ret = 0;
//class Solution {
//public:
//	int Sum_Solution(int n) {
//		// 变长数组
//		Sum arr[n];
//		return Sum::GetRet();
//	}
//};
//// 实现一个类，计算程序中创建出了多少个类对象？
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


//#include<iostream>
//using namespace std;
//class A
//{
//public:
//	A(int a)
//		:_a1(a)
//		, _a2(_a1)
//	{}
//	void Print() {
//		cout << _a1 << " " << _a2 << endl;
//	}
//private:
//	int _a2 = 2;
//	int _a1 = 2;
//};
//int main()
//{
//	A aa(1);
//	aa.Print();
//}


//#include<iostream>
//using namespace std;
//class Time
//{
//public:
//	Time(int hour)
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
//	Date()
//		:_month(2)
//	{
//		cout << "Date()" << endl;
//	}
//	void Print() const
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	// 注意这里不是初始化，这里给的是缺省值，这个缺省值是给初始化列表的
//	// 如果初始化列表没有显示初始化，默认就会用这个缺省值初始化
//	int _year = 1;
//	int _month = 1;
//	int _day;
//	Time _t = 1;
//	const int _n = 1;
//	int* _ptr = (int*)malloc(12);
//};
//int main()
//{
//	Date d1;
//	d1.Print();
//	return 0;
//}




//#include<iostream>
//using namespace std;
//class Time
//{
//public:
//	Time(int hour)
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
//		, _month(month)
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
//class Date
//{
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	// void Print(const Date* const this) const
//	void Print() const
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	// 这里非const对象也可以调用const成员函数是一种权限的缩小
//	Date d1(2024, 7, 5);
//	d1.Print();
//	const Date d2(2024, 8, 5);
//	d2.Print();
//	return 0;
//}


//#pragma once
//#include<iostream>
//using namespace std;
//#include<assert.h>
//class Date
//{
//	// 友元函数声明
//	friend ostream& operator<<(ostream& out, const Date& d);
//	friend istream& operator>>(istream& in, Date& d);
//public:
//	Date(int year = 1900, int month = 1, int day = 1);
//	void Print() const;
//	// 直接定义类里面，他默认是inline
//	// 频繁调用
//	int GetMonthDay(int year, int month)
//	{
//		assert(month > 0 && month < 13);
//		static int monthDayArray[13] = { -1, 31, 28, 31, 30, 31, 30,
//		31, 31, 30, 31, 30, 31 };
//		// 365天 5h +
//		if (month == 2 && (year % 4 == 0 && year % 100 != 0) || (year
//			% 400 == 0))
//		{
//			return 29;
//		}
//		else
//		{
//			return monthDayArray[month];
//		}
//	}
//	bool CheckDate();
//	bool operator<(const Date& d) const;
//	bool operator<=(const Date& d) const;
//	bool operator>(const Date& d) const;
//	bool operator>=(const Date& d) const;
//	bool operator==(const Date& d) const;
//	bool operator!=(const Date& d) const;
//	// d1 += 天数
//	Date& operator+=(int day);
//	Date operator+(int day) const;
//	// d1 -= 天数
//	Date& operator-=(int day);
//	Date operator-(int day) const;
//	// d1 - d2
//	int operator-(const Date& d) const;
//	// ++d1 -> d1.operator++()
//	Date& operator++();
//	// d1++ -> d1.operator++(0)
//	// 为了区分，构成重载，给后置++，强行增加了一个int形参
//	// 这里不需要写形参名，因为接收值是多少不重要，也不需要用
//	// 这个参数仅仅是为了跟前置++构成重载区分
//	Date operator++(int);
//	Date& operator--();
//	Date operator--(int);
//	// 流插入
//	// 不建议，因为Date* this占据了一个参数位置，使用d<<cout不符合习惯
//	//void operator<<(ostream& out);
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//// 重载
//ostream& operator<<(ostream& out, const Date& d);
//istream& operator>>(istream& in, Date& d);
//// Date.cpp
//#include"Date.h"
//bool Date::CheckDate()
//{
//	if (_month < 1 || _month > 12
//		|| _day < 1 || _day > GetMonthDay(_year, _month))
//	{
//		return false;
//	}
//	else
//	{
//		return true;
//	}
//}
//Date::Date(int year, int month, int day)
//{
//	_year = year;
//	_month = month;
//	_day = day;
//	if (!CheckDate())
//	{
//		cout << "日期非法" << endl;
//	}
//}
//void Date::Print() const
//{
//	cout << _year << "-" << _month << "-" << _day << endl;
//}
//// d1 < d2
//bool Date::operator<(const Date& d) const
//{
//	if (_year < d._year)
//	{
//		return true;
//	}
//	else if (_year == d._year)
//	{
//		if (_month < d._month)
//		{
//			return true;
//		}
//		else if (_month == d._month)
//		{
//			return _day < d._day;
//		}
//	}
//	return false;
//}
//// d1 <= d2
//bool Date::operator<=(const Date& d) const
//{
//	return *this < d || *this == d;
//}
//bool Date::operator>(const Date& d) const
//{
//	return !(*this <= d);
//}
//bool Date::operator>=(const Date& d) const
//{
//	return !(*this < d);
//}
//bool Date::operator==(const Date& d) const
//{
//	return _year == d._year
//		&& _month == d._month
//		&& _day == d._day;
//}
//bool Date::operator!=(const Date& d) const
//{
//	return !(*this == d);
//}
//// d1 += 50
//// d1 += -50
//Date& Date::operator+=(int day)
//{
//	if (day < 0)
//	{
//		return *this -= -day;
//	}
//	_day += day;
//	while (_day > GetMonthDay(_year, _month))
//	{
//		_day -= GetMonthDay(_year, _month);
//		++_month;
//		if (_month == 13)
//		{
//			++_year;
//			_month = 1;
//		}
//	}
//	return *this;
//}
//Date Date::operator+(int day) const
//{
//	Date tmp = *this;
//	tmp += day;
//	return tmp;
//}
//// d1 -= 100
//Date& Date::operator-=(int day)
//{
//	if (day < 0)
//	{
//		return *this += -day;
//	}
//	_day -= day;
//	while (_day <= 0)
//	{
//		--_month;
//		if (_month == 0)
//		{
//			_month = 12;
//			_year--;
//		}
//		// 借上一个月的天数
//		_day += GetMonthDay(_year, _month);
//	}
//	return *this;
//}
//Date Date::operator-(int day) const
//{
//	Date tmp = *this;
//	tmp -= day;
//	return tmp;
//}
////++d1
//Date& Date::operator++()
//{
//	*this += 1;
//	return *this;
//}
//// d1++
//Date Date::operator++(int)
//{
//	Date tmp(*this);
//	*this += 1;
//	return tmp;
//}
//Date& Date::operator--()
//{
//	*this -= 1;
//	return *this;
//}
//Date Date::operator--(int)
//{
//	Date tmp = *this;
//	*this -= 1;
//	return tmp;
//}
//// d1 - d2
//int Date::operator-(const Date& d) const
//{
//	Date max = *this;
//	Date min = d;
//	int flag = 1;
//	if (*this < d)
//	{
//		max = d;
//		min = *this;
//		flag = -1;
//	}
//	int n = 0;
//	while (min != max)
//	{
//		++min;
//		++n;
//	}
//	return n * flag;
//}
//ostream& operator<<(ostream& out, const Date& d)
//{
//	out << d._year << "年" << d._month << "月" << d._day << "日" << endl;
//	return out;
//}
//istream& operator>>(istream& in, Date& d)
//{
//	cout << "请依次输入年月日:>";
//	in >> d._year >> d._month >> d._day;
//	if (!d.CheckDate())
//	{
//		cout << "日期非法" << endl;
//	}
//	return in;
//}
//// Test.cpp
//#include"Date.h"
//void TestDate1()
//{
//	// 这里需要测试一下大的数据+和-
//	Date d1(2024, 4, 14);
//	Date d2 = d1 + 30000;
//	d1.Print();
//	d2.Print();
//	Date d3(2024, 4, 14);
//	Date d4 = d3 - 5000;
//	d3.Print();
//	d4.Print();
//	Date d5(2024, 4, 14);
//	d5 += -5000;
//	d5.Print();
//}
//void TestDate2()
//{
//	Date d1(2024, 4, 14);
//	Date d2 = ++d1;
//	d1.Print();
//	d2.Print();
//	Date d3 = d1++;
//	d1.Print();
//	d3.Print();
//	/*d1.operator++(1);
//	d1.operator++(100);
//	d1.operator++(0);
//	d1.Print();*/
//}
//void TestDate3()
//{
//	Date d1(2024, 4, 14);
//	Date d2(2034, 4, 14);
//	int n = d1 - d2;
//	cout << n << endl;
//	n = d2 - d1;
//}
//void TestDate4()
//{
//	Date d1(2024, 4, 14);
//	Date d2 = d1 + 30000;
//	// operator<<(cout, d1)
//	cout << d1;
//	cout << d2;
//	cin >> d1 >> d2;
//	cout << d1 << d2;
//}
//void TestDate5()
//{
//	const Date d1(2024, 4, 14);
//	d1.Print();
//	//d1 += 100;
//	d1 + 100;
//	Date d2(2024, 4, 25);
//	d2.Print();
//	d2 += 100;
//	d1 < d2;
//	d2 < d1;
//}
//int main()
//{
//	return 0;
//}

//class Date
//{
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	Date(const Date& d)
//	{
//		cout << " Date(const Date& d)" << endl;
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//	// 传引用返回减少拷贝
//	// d1 = d2;
//	Date& operator=(const Date& d)
//	{
//		// 不要检查自己给自己赋值的情况
//		if (this != &d)
//		{
//			_year = d._year;
//			_month = d._month;
//			_day = d._day;
//		}
//		// d1 = d2表达式的返回对象应该为d1，也就是*this
//		return *this;
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
//int main()
//{
//	Date d1(2024, 7, 5);
//	Date d2(d1);
//	Date d3(2024, 7, 6);
//	d1 = d3;
//	// 需要注意这里是拷贝构造，不是赋值重载
//	// 请牢牢记住赋值重载完成两个已经存在的对象直接的拷贝赋值
//	// 而拷贝构造用于一个对象拷贝初始化给另一个要创建的对象
//	Date d4 = d1;
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
//	bool operator==(const Date& d)
//	{
//		return _year == d._year
//			&& _month == d._month
//			&& _day == d._day;
//	}
//	Date& operator++()
//	{
//		cout << "前置++" << endl;
//		//...
//		return *this;
//	}
//	Date operator++(int)
//	{
//		Date tmp;
//		cout << "后置++" << endl;
//		//...
//		return tmp;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d1(2024, 7, 5);
//	Date d2(2024, 7, 6);
//	// 运算符重载函数可以显示调用
//	d1.operator==(d2);
//	// 编译器会转换成 d1.operator==(d2);
//	d1 == d2;
//	// 编译器会转换成 d1.operator++();
//	++d1;
//	// 编译器会转换成 d1.operator++(0);
//	d1++;
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
//	//private:
//	int _year;
//	int _month;
//	int _day;
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
//// 编译报错：“operator +”必须至少有一个类类型的形参
//int operator+(int x, int y)
//{
//	return x - y;
//}
//class A
//{
//public:
//	void func()
//	{
//		cout << "A::func()" << endl;
//	}
//};
//typedef void(A::* PF)(); //成员函数指针类型
//int main()
//{
//	// C++规定成员函数要加&才能取到函数指针
//	PF pf = &A::func;
//	A obj;//定义ob类对象temp
//	// 对象调用成员函数指针时，使用.*运算符
//	(obj.*pf)();
//	return 0;
//}





//#include<iostream>
//using namespace std;
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
//	Stack(const Stack& st)
//	{
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
//// 两个Stack实现队列
//class MyQueue
//{
//public:
//private:
//	Stack pushst;
//	Stack popst;
//};
//int main()
//{
//	Stack st1;
//	st1.Push(1);
//	st1.Push(2);
//	// Stack不显示实现拷贝构造，用自动生成的拷贝构造完成浅拷贝
//	// 会导致st1和st2里面的_a指针指向同一块资源，析构时会析构两次，程序崩溃
//	Stack st2 = st1;
//	MyQueue mq1;
//	// MyQueue自动生成的拷贝构造，会自动调用Stack拷贝构造完成pushst/popst
//	// 的拷贝，只要Stack拷贝构造自己实现了深拷贝，他就没问题
//	MyQueue mq2 = mq1;
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
//	Date(Date * d)
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
//	构造
//		// 所以这里的d1传值传参给d要调用拷贝构造完成拷贝，传引用传参可以较少这里的拷贝
//		Func1(d1);
//	cout << &d1 << endl;
//	// 这里可以完成拷贝，但是不是拷贝构造，只是一个普通的构造
//	Date d2(&d1);
//	d1.Print();
//	d2.Print();
//	//这样写才是拷贝构造，通过同类型的对象初始化构造，而不是指针
//	Date d3(d1);
//	d2.Print();
//	// 也可以这样写，这里也是拷贝构造
//	Date d4 = d1;
//	d2.Print();
//	// Func2返回了一个局部对象tmp的引用作为返回值
//	// Func2函数结束，tmp对象就销毁了，相当于了一个野引用
//	Date ret = Func2();
//	ret.Print();
//	return 0;
//}





//#include<iostream>
//using namespace std;
//// 用最新加了构造和析构的C++版本Stack实现
//bool isValid(const char* s) {
//	Stack st;
//	while (*s)
//	{
//		if (*s == '[' || *s == '(' || *s == '{')
//		{
//			st.Push(*s);
//		}
//		else
//		{
//			// 右括号比左括号多，数量匹配问题
//			if (st.Empty())
//			{
//				return false;
//			}
//			// 栈里面取左括号
//			char top = st.Top();
//			st.Pop();
//			// 顺序不匹配
//			if ((*s == ']' && top != '[')
//				|| (*s == '}' && top != '{')
//				|| (*s == ')' && top != '('))
//			{
//				return false;
//			}
//		}
//		++s;
//	}
//	// 栈为空，返回真，说明数量都匹配 左括号多，右括号少匹配问题
//	return st.Empty();
//}
//// 用之前C版本Stack实现
//bool isValid(const char* s) {
//	ST st;
//	STInit(&st);
//	while (*s)
//	{
//		// 左括号入栈
//		if (*s == '(' || *s == '[' || *s == '{')
//		{
//			STPush(&st, *s);
//		}
//		else // 右括号取栈顶左括号尝试匹配
//		{
//			if (STEmpty(&st))
//			{
//				STDestroy(&st);
//				return false;
//			}
//			char top = STTop(&st);
//			STPop(&st);
//			// 不匹配
//			if ((top == '(' && *s != ')')
//				|| (top == '{' && *s != '}')
//				|| (top == '[' && *s != ']'))
//			{
//				STDestroy(&st);
//				return false;
//			}
//		}
//		++s;
//	}
//	// 栈不为空，说明左括号比右括号多，数量不匹配
//	bool ret = STEmpty(&st);
//	STDestroy(&st);
//	return ret;
//}
//int main()
//{
//	cout << isValid("[()][]") << endl;
//	cout << isValid("[(])[]") << endl;
//	return 0;
//}
//#include<iostream>
//using namespace std;
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
//// 两个Stack实现队列
//class MyQueue
//{
//public:
//	//编译器默认生成MyQueue的析构函数调用了Stack的析构，释放的Stack内部的资源
//	// 显示写析构，也会自动调用Stack的析构
///*~MyQueue()
//{}*/
//private:
//	Stack pushst;
//	Stack popst;
//};
//int main()
//{
//	Stack st;
//	MyQueue mq;
//	return 0;
//}

//#include<iostream>
//using namespace std;
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
//	// ...
//private:
//	STDataType* _a;
//	size_t _capacity;
//	size_t _top;
//};
//// 两个Stack实现队列
//class MyQueue
//{
//public:
//	//编译器默认生成MyQueue的构造函数调用了Stack的构造，完成了两个成员的初始化
//private:
//	Stack pushst;
//	Stack popst;
//};
//int main()
//{
//	MyQueue mq;
//	return 0;
//}


//#include<iostream>
//using namespace std;
//class Date
//{
//public:
//	// 1.无参构造函数
//	Date()
//	{
//		_year = 1;
//		_month = 1;
//		_day = 1;
//	}
//	// 2.带参构造函数
//	Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	// 3.全缺省构造函数
//	/*Date(int year = 1, int month = 1, int day = 1)
//	{
//	_year = year;
//	_month = month;
//	_day = day;
//	}*/
//	void Print()
//	{
//		cout << _year << "/" << _month << "/" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	// 如果留下三个构造中的第二个带参构造，第一个和第三个注释掉
//	// 编译报错：error C2512: “Date”: 没有合适的默认构造函数可用
//	Date d1; // 调用默认构造函数
//	Date d2(2025, 1, 1); // 调用带参的构造函数
//	// 注意：如果通过无参构造函数创建对象时，对象后面不用跟括号，否则编译器无法
//	// 区分这里是函数声明还是实例化对象
//	// warning C4930: “Date d3(void)”: 未调用原型函数(是否是有意用变量定义的?)
//	Date d3();
//	d1.Print();
//	d2.Print();
//	return 0;
//}



//#include<iostream>
//using namespace std;
//typedef int STDataType;
//class Stack
//{
//public:
//	// 成员函数
//	void Init(int n = 4)
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
//	}
//	void Pop()
//	{
//		assert(_top > 0);
//		--_top;
//	}
//	bool Empty()
//	{
//		return _top == 0;
//	}
//	int Top()
//	{
//		assert(_top > 0);
//		return _a[_top - 1];
//	}
//	void Destroy()
//	{
//		free(_a);
//		_a = nullptr;
//		_top = _capacity = 0;
//	}
//private:
//	// 成员变量
//	STDataType* _a;
//	size_t _capacity;
//	size_t _top;
//};
//int main()
//{
//	Stack s;
//	s.Init();
//	s.Push(1);
//	s.Push(2);
//	s.Push(3);
//	s.Push(4);
//	while (!s.Empty())
//	{
//		printf("%d\n", s.Top());
//		s.Pop();
//	}
//	s.Destroy();
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//#include<stdbool.h>
//#include<assert.h>
//typedef int STDataType;
//typedef struct Stack
//{
//	STDataType* a;
//	int top;
//	int capacity;
//}ST;
//void STInit(ST* ps)
//{
//	assert(ps);
//	ps->a = NULL;
//	ps->top = 0;
//	ps->capacity = 0;
//}
//void STDestroy(ST* ps)
//{
//	assert(ps);
//	free(ps->a);
//	ps->a = NULL;
//	ps->top = ps->capacity = 0;
//}
//void STPush(ST* ps, STDataType x)
//{
//	assert(ps);
//	// 满了， 扩容
//	if (ps->top == ps->capacity)
//	{
//		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
//		STDataType* tmp = (STDataType*)realloc(ps->a, newcapacity *
//			sizeof(STDataType));
//		if (tmp == NULL)
//		{
//			perror("realloc fail");
//			return;
//		}
//		ps->a = tmp;
//		ps->capacity = newcapacity;
//	}
//	ps->a[ps->top] = x;
//	ps->top++;
//}
//bool STEmpty(ST* ps)
//{
//	assert(ps);
//	return ps->top == 0;
//}
//void STPop(ST* ps)
//{
//	assert(ps);
//	assert(!STEmpty(ps));
//	ps->top--;
//}
//STDataType STTop(ST* ps)
//{
//	assert(ps);
//	assert(!STEmpty(ps));
//	ps->top--;
//}
//STDataType STTop(ST* ps)
//{
//	assert(ps);
//	assert(!STEmpty(ps));
//	return ps->a[ps->top - 1];
//}
//int STSize(ST* ps)
//{
//	assert(ps);
//	return ps->top;
//}
//int main()
//{
//	ST s;
//	STInit(&s);
//	STPush(&s, 1);
//	STPush(&s, 2);
//	STPush(&s, 3);
//	STPush(&s, 4);
//	while (!STEmpty(&s))
//	{
//		printf("%d\n", STTop(&s));
//		STPop(&s);
//	}
//	STDestroy(&s);
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
//		// 编译报错：error C2106: “=”: 左操作数必须为左值
//		// this = nullptr;
//		// this->_year = year;
//		_year = year;
//		this->_month = month;
//		this->_day = day;
//	}
//	void Print()
//	{
//		cout << _year << "/" << _month << "/" << _day << endl;
//	}
//private:
//	// 这里只是声明，没有开空间
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	// Date类实例化出对象d1和d2
//	Date d1;
//	Date d2;
//	// d1.Init(&d1, 2024, 3, 31);
//	d1.Init(2024, 3, 31);
//	d1.Print();
//	d2.Init(2024, 7, 5);
//	d2.Print();
//	return 0;
//}

//#include<iostream>
//using namespace std;
//// 计算一下A/B/C实例化的对象是多大？
//class A
//{
//public:
//	void Print()
//	{
//		cout << _ch << endl;
//	}
//private:
//	char _ch;
//	int _i;
//};
//class B
//{
//public:
//	void Print()
//	{
//		//...
//	}
//};
//class C
//{};
//int main()
//{
//	A a;
//	B b;
//	C c;
//	cout << sizeof(a) << endl;
//	cout << sizeof(b) << endl;
//	cout << sizeof(c) << endl;
//	return 0;
//}

//#include<iostream>
//using namespace std;
//class Date
//{
//public:
//	void Init(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void Print()
//	{
//		cout << _year << "/" << _month << "/" << _day << endl;
//	}
//private:
//	// 这里只是声明，没有开空间
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	// Date类实例化出对象d1和d2
//	Date d1;
//	Date d2;
//	d1.Init(2024, 3, 31);
//	d1.Print();
//	d2.Init(2024, 7, 5);
//	d2.Print();
//	return 0;
//}
//#include<iostream>
//using namespace std;
//class Stack
//{
//public:
//	// 成员函数
//	void Init(int n = 4);
//private:
//	// 成员变量
//	int* array;
//	size_t capacity;
//	size_t top;
//};
//// 声明和定义分离，需要指定类域
//void Stack::Init(int n)
//{
//	array = (int*)malloc(sizeof(int) * n);
//	if (nullptr == array)
//	{
//		perror("malloc申请空间失败");
//		return;
//	}
//	capacity = n;
//	top = 0;
//}
//int main()
//{
//	Stack st;
//	st.Init();
//	return 0;
//}


//#include<iostream>
//using namespace std;
//// C++升级struct升级成了类
//// 1、类里面可以定义函数
//// 2、struct名称就可以代表类型
//// C++兼容C中struct的用法
//typedef struct ListNodeC
//{
//	struct ListNodeC* next;
//	int val;
//}LTNode;
//// 不再需要typedef，ListNodeCPP就可以代表类型
//struct ListNodeCPP
//{
//	void Init(int x)
//	{
//		next = nullptr;
//		val = x;
//	}
//	ListNodeCPP* next;
//	int val;
//};
//int main()
//{
//	return 0;
//}


//class Date
//{
//public:
//	void Init(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//private:
//	// 为了区分成员变量，一般习惯上成员变量
//	// 会加一个特殊标识，如_ 或者 m开头
//	int _year; // year_ m_year
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d;
//	d.Init(2024, 3, 31);
//	return 0;
//}

//#include<iostream>
//using namespace std;
//class Stack
//{
//public:
//	// 成员函数
//	void Init(int n = 4)
//	{
//		array = (int*)malloc(sizeof(int) * n);
//		if (nullptr == array)
//		{
//			perror("malloc申请空间失败");
//			return;
//		}
//		capacity = n;
//		top = 0;
//	}
//	void Push(int x)
//	{
//		// ...扩容
//		array[top++] = x;
//	}
//	int Top()
//	{
//		assert(top > 0);
//		return array[top - 1];
//	}
//	void Destroy()
//	{
//		free(array);
//		array = nullptr;
//		top = capacity = 0;
//	}
//private:
//	// 成员变量
//	int* array;
//	size_t capacity;
//	size_t top;
//}; // 分号不能省略
//int main()
//{
//	Stack st;
//	st.Init();
//	st.Push(1);
//	st.Push(2);
//	cout << st.Top() << endl;
//	st.Destroy();
//	return 0;
//}

//#include<iostream>
//using namespace std;
//void f(int x)
//{
//	cout << "f(int x)" << endl;
//}
//void f(int* ptr)
//{
//	cout << "f(int* ptr)" << endl;
//}
//int main()
//{
//	f(0);
//	// 本想通过f(NULL)调用指针版本的f(int*)函数，但是由于NULL被定义成0，调用了f(int
//	//x)，因此与程序的初衷相悖。
//	f(NULL);
//	f((int*)NULL);
//	// 编译报错：error C2665: “f”: 2 个重载中没有一个可以转换所有参数类型
//	// f((void*)NULL);
//	f(nullptr);
//	return 0;
//}
//#ifndef NULL
//    #ifdef __cplusplus
//        #define NULL 0
//    #else
//        #define NULL ((void *)0)
//    #endif
//#endif
//// F.h
//#include <iostream>
//using namespace std;
//inline void f(int i);
//// F.cpp
//#include "F.h"
//void f(int i)
//{
//	cout << i << endl;
//}
//// main.cpp
//#include "F.h"
//int main()
//{
//	// 链接错误：无法解析的外部符号 "void __cdecl f(int)" (?f@@YAXH@Z)
//	f(10);
//	return 0;
//}

//#include<iostream>
//using namespace std;
//inline int Add(int x, int y)
//{
//	int ret = x + y;
//	ret += 1;
//	ret += 1;
//	ret += 1;
//	return ret;
//}
//int main()
//{
//	// 可以通过汇编观察程序是否展开
//	// 有call Add语句就是没有展开，没有就是展开了
//	int ret = Add(1, 2);
//	cout << Add(1, 2) * 5 << endl;
//	return 0;
//}
//#include<iostream>
//using namespace std;
//// 实现一个ADD宏函数的常见问题
////#define ADD(int a, int b) return a + b;
////#define ADD(a, b) a + b;
////#define ADD(a, b) (a + b)
//// 正确的宏实现
//#define ADD(a, b) ((a) + (b))
//// 为什么不能加分号?
//// 为什么要加外面的括号?
//// 为什么要加里面的括号?
//int main()
//{
//	int ret = ADD(1, 2);
//	cout << ADD(1, 2) << endl;
//	cout << ADD(1, 2) * 5 << endl;
//	int x = 1, y = 2;
//	ADD(x & y, x | y); // -> (x&y+x|y)
//	return 0;
//}

//int main()
//{
//	const int a = 10;
//	// 编译报错：error C2440: “初始化”: 无法从“const int”转换为“int &”
//	// 这里的引用是对a访问权限的放大
//	//int& ra = a;
//	// 这样才可以
//	const int& ra = a;
//	// 编译报错：error C3892: “ra”: 不能给常量赋值
//	//ra++;
//	// 这里的引用是对b访问权限的缩小
//	int b = 20;
//	const int& rb = b;
//	// 编译报错：error C3892: “rb”: 不能给常量赋值
//	//rb++;
//	return 0;
//}
//#include<iostream>
//using namespace std;
//int main()
//{
//	int a = 10;
//	const int& ra = 30;
//	// 编译报错: “初始化”: 无法从“int”转换为“int &”
//	// int& rb = a * 3;
//	const int& rb = a * 3;
//	double d = 12.34;
//	// 编译报错：“初始化”: 无法从“double”转换为“int &”
//	// int& rd = d;
//	const int& rd = d;
//	return 0;
//}
//#include<iostream>
//using namespace std;
//typedef struct SeqList
//{
//	int a[10];
//	int size;
//}SLT;
//// 一些主要用C代码实现版本数据结构教材中，使用C++引用替代指针传参，目的是简化程序，避开复
////杂的指针，但是很多同学没学过引用，导致一头雾水。
//void SeqPushBack(SLT& sl, int x)
//{}
//typedef struct ListNode
//{
//	int val;
//	struct ListNode* next;
//}LTNode, * PNode;
//// 指针变量也可以取别名，这里LTNode*& phead就是给指针变量取别名
//// 这样就不需要用二级指针了，相对而言简化了程序
////void ListPushBack(LTNode** phead, int x)
////void ListPushBack(LTNode*& phead, int x)
//void ListPushBack(PNode& phead, int x)
//{
//	PNode newnode = (PNode)malloc(sizeof(LTNode));
//	newnode->val = x;
//	newnode->next = NULL;
//	if (phead == NULL)
//	{
//		phead = newnode;
//	}
//	else
//	{
//		//...
//	}
//}
//int main()
//{
//	PNode plist = NULL;
//	ListPushBack(plist, 1);
//	return 0;
//}
//void Swap(int& rx, int& ry)
//{
//	int tmp = rx;
//	rx = ry;
//	ry = tmp;
//}
//int main()
//{
//	int x = 0, y = 1;
//	cout << x << " " << y << endl;
//	Swap(x, y);
//	cout << x << " " << y << endl;
//	return 0;
//}
//#include<iostream>
//using namespace std;
//typedef int STDataType;
//typedef struct Stack
//{
//	STDataType* a;
//	int top;
//	int capacity;
//}ST;
//void STInit(ST& rs, int n = 4)
//{
//	rs.a = (STDataType*)malloc(n * sizeof(STDataType));
//	rs.top = 0;
//	rs.capacity = n;
//}
//// 栈顶
//void STPush(ST& rs, STDataType x)
//{
//	assert(ps);
//	// 满了， 扩容
//	if (rs.top == rs.capacity)
//	{
//		printf("扩容\n");
//		int newcapacity = rs.capacity == 0 ? 4 : rs.capacity * 2;
//		STDataType* tmp = (STDataType*)realloc(rs.a, newcapacity *
//			sizeof(STDataType));
//		if (tmp == NULL)
//		{
//			perror("realloc fail");
//			return;
//		}
//		rs.a = tmp;
//		rs.capacity = newcapacity;
//	}
//	rs.a[rs.top] = x;
//	rs.top++;
//}
//// int STTop(ST& rs)
//int& STTop(ST& rs)
//{
//	assert(rs.top > 0);
//	return rs.a[rs.top];
//}
//int main()
//{
//	// 调用全局的
//	ST st1;
//	STInit(st1);
//	STPush(st1, 1);
//	STPush(st1, 2);
//	cout << STTop(st1) << endl;
//	STTop(st1) += 10;
//	cout << STTop(st1) << endl;
//	return 0;
//}
//#include<iostream>
//using namespace std;
//int main()
//{
//	int a = 10;
//	// 编译报错：“ra”: 必须初始化引用
//	//int& ra;
//	int& b = a;
//	int c = 20;
//	// 这里并非让b引用c，因为C++引用不能改变指向，
//	// 这里是一个赋值
//	b = c;
//	cout << &a << endl;
//	cout << &b << endl;
//	cout << &c << endl;
//	return 0;
//}
//#include<iostream>
//using namespace std;
//int main()
//{
//	int a = 0;
//	// 引用：b和c是a的别名
//	int& b = a;
//	int& c = a;
//	// 也可以给别名b取别名，d相当于还是a的别名
//	int& d = b;
//	++d;
//	// 这里取地址我们看到是一样的
//	cout << &a << endl;
//	cout << &b << endl;
//	cout << &c << endl;
//	cout << &d << endl;
//	return 0;
//}
//#include<iostream>
//using namespace std;
//// 1、参数类型不同
//int Add(int left, int right)
//{
//	cout << "int Add(int left, int right)" << endl;
//	return left + right;
//}
//double Add(double left, double right)
//{
//	cout << "double Add(double left, double right)" << endl;
//	return left + right;
//}
//// 2、参数个数不同
//void f()
//{
//	cout << "f()" << endl;
//}
//void f(int a)
//{
//	cout << "f(int a)" << endl;
//}
//// 3、参数类型顺序不同
//void f(int a, char b)
//{
//	cout << "f(int a,char b)" << endl;
//}
//void f(char b, int a)
//{
//	cout << "f(char b, int a)" << endl;
//}
//// 返回值不同不能作为重载条件，因为调用时也无法区分
////void fxx()
////{}
////
////int fxx()
////{
//// return 0;
////}
//// 下面两个函数构成重载
//// f()但是调用时，会报错，存在歧义，编译器不知道调用谁
//void f1()
//{
//	cout << "f()" << endl;
//}
//void f1(int a = 10)
//{
//	cout << "f(int a)" << endl;
//}
//int main()
//{
//	Add(10, 20);
//	Add(10.1, 20.2);
//	f();
//	f(10);
//	f(10, 'a');
//	f('a', 10);
//	return 0;
//}
//// Stack.h
//#include <iostream>
//#include <assert.h>
//using namespace std;
//typedef int STDataType;
//typedef struct Stack
//{
//	STDataType* a;
//	int top;
//	int capacity;
//}ST;
//void STInit(ST* ps, int n = 4);
//// Stack.cpp
//#include"Stack.h"
//// 缺省参数不能声明和定义同时给
//void STInit(ST* ps, int n)
//{
//	assert(ps && n > 0);
//	ps->a = (STDataType*)malloc(n * sizeof(STDataType));
//	ps->top = 0;
//	ps->capacity = n;
//}
//// test.cpp
//#include"Stack.h"
//int main()
//{
//	ST s1;
//	STInit(&s1);
//	// 确定知道要插入1000个数据，初始化时一把开好，避免扩容
//	ST s2;
//	STInit(&s2, 1000);
//	return 0;
//}
//#include <iostream>
//using namespace std;
//// 全缺省
//void Func1(int a = 10, int b = 20, int c = 30)
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl << endl;
//}
//// 半缺省
//void Func2(int a, int b = 10, int c = 20)
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl << endl;
//}
//int main()
//{
//	Func1();
//	Func1(1);
//	Func1(1, 2);
//	Func1(1, 2, 3);
//	Func2(100);
//	Func2(100, 200);
//	Func2(100, 200, 300);
//	return 0;
//}
//#include <iostream>
//#include <assert.h>
//using namespace std;
//void Func(int a = 0)
//{
//	cout << a << endl;
//}
//int main()
//{
//	Func(); // 没有传参时，使用参数的默认值
//	Func(10); // 传参时，使用指定的实参
//	return 0;
//}
//#include<iostream>
//using namespace std;
//int main()
//{
//	// 在io需求比较高的地方，如部分大量输入的竞赛题中，加上以下3行代码
//	// 可以提高C++IO效率
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//	return 0;
//}
//#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//using namespace std;
//int main()
//{
//	int a = 0;
//	double b = 0.1;
//	char c = 'x';
//	cout << a << " " << b << " " << c << endl;
//	std::cout << a << " " << b << " " << c << std::endl;
//	scanf("%d%lf", &a, &b);
//	printf("%d %lf\n", a, b);
//	// 可以自动识别变量的类型
//	cin >> a;
//	cin >> b >> c;
//	cout << a << endl;
//	cout << b << " " << c << endl;
//	return 0;
//}
//// 指定命名空间访问
//int main()
//{
//	printf("%d\n", N::a);
//	return 0;
//}
//// using将命名空间中某个成员展开
//using N::b;
//int main()
//{
//	printf("%d\n", N::a);
//	printf("%d\n", b);
//	return 0;
//}
//#include<stdio.h>
//namespace bit
//{
//	int a = 0;
//	int b = 1;
//}
//int main()
//{
//	// 编译报错：error C2065: “a”: 未声明的标识符
//	printf("%d\n", a);
//	return 0;
//}
////2. 命名空间可以嵌套
//namespace bit
//{
//	// 鹏哥
//	namespace pg
//	{
//		int rand = 1;
//		int Add(int left, int right)
//		{
//			return left + right;
//		}
//	}
//	// 杭哥
//	namespace hg
//	{
//		int rand = 2;
//		int Add(int left, int right)
//		{
//			return (left + right) * 10;
//		}
//	}
//}
//int main()
//{
//	printf("%d\n", bit::pg::rand);
//	printf("%d\n", bit::hg::rand);
//	printf("%d\n", bit::pg::Add(1, 2));
//	printf("%d\n", bit::hg::Add(1, 2));
//	return 0;
//}
//// 多文件中可以定义同名namespace，他们会默认合并到一起，就像同一个namespace一样
//// Stack.h
//#pragma once
//#include<stdio.h>
//#include<stdlib.h>
//#include<stdbool.h>
//#include<assert.h>
//namespace bit
//{
//	typedef int STDataType;
//	typedef struct Stack
//	{
//		int top;
//		int capacity;
//	}ST;
//	void STInit(ST* ps, int n);
//	void STDestroy(ST* ps);
//	void STPush(ST* ps, STDataType x);
//	void STPop(ST* ps);
//	STDataType STTop(ST* ps);
//	int STSize(ST* ps);
//	bool STEmpty(ST* ps);
//}
//// Stack.cpp
//#include"Stack.h"
//namespace bit
//{
//	void STInit(ST* ps, int n)
//	{
//		assert(ps);
//		ps->a = (STDataType*)malloc(n * sizeof(STDataType));
//		ps->top = 0;
//		ps->capacity = n;
//	}
//	// 栈顶
//	void STPush(ST* ps, STDataType x)
//	{
//		assert(ps);
//		// 满了， 扩容
//		if (ps->top == ps->capacity)
//		{
//			printf("扩容\n");
//			int newcapacity = ps->capacity == 0 ? 4 : ps->capacity
//				* 2;
//			STDataType* tmp = (STDataType*)realloc(ps->a,
//				newcapacity * sizeof(STDataType));
//			if (tmp == NULL)
//			{
//				perror("realloc fail");
//				return;
//			}
//			ps->a = tmp;
//			ps->capacity = newcapacity;
//		}
//		ps->a[ps->top] = x;
//		ps->top++;
//	}
//	//...
//}
//// Queue.h
//#pragma once
//#include<stdlib.h>
//#include<stdbool.h>
//#include<assert.h>
//namespace bit
//{
//	typedef int QDataType;
//	typedef struct QueueNode
//	{
//		int val;
//		struct QueueNode* next;
//	}QNode;
//	typedef struct Queue
//	{
//		QNode* phead;
//		QNode* ptail;
//		int size;
//	}Queue;
//	void QueueInit(Queue* pq);
//	void QueueDestroy(Queue* pq);
//	// 入队列
//	void QueuePush(Queue* pq, QDataType x);
//	// 出队列
//	void QueuePop(Queue* pq);
//	QDataType QueueFront(Queue* pq);
//	QDataType QueueBack(Queue* pq);
//	bool QueueEmpty(Queue* pq);
//	int QueueSize(Queue* pq);
//}
//// Queue.cpp
//#include"Queue.h"
//namespace bit
//{
//	void QueueInit(Queue* pq)
//	{
//		assert(pq);
//		pq->phead = NULL;
//		pq->ptail = NULL;
//		pq->size = 0;
//	}
//	// ...
//}
//// test.cpp
//#include"Queue.h"
//#include"Stack.h"
//// 全局定义了一份单独的Stack
//typedef struct Stack
//{
//	int a[10];
//	int top;
//}ST;
//void STInit(ST* ps) {}
//void STPush(ST* ps, int x) {}
//int main()
//{
//	// 调用全局的
//	ST st1;
//	STInit(&st1);
//	STPush(&st1, 1);
//	STPush(&st1, 2);
//	printf("%d\n", sizeof(st1));
//	// 调用bit namespace的
//	bit::ST st2;
//	printf("%d\n", sizeof(st2));
//	bit::STInit(&st2);
//	bit::STPush(&st2, 1);
//	bit::STPush(&st2, 2);
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//// 1. 正常的命名空间定义
//// bit是命名空间的名字，一般开发中是用项目名字做命名空间名。
//// 我们上课用的是bit，大家下去以后自己练习可以考虑用自己名字缩写，如张三：zs
//namespace bit
//{
//	// 命名空间中可以定义变量/函数/类型
//	int rand = 10;
//	int Add(int left, int right)
//	{
//		return left + right;
//	}
//	struct Node
//	{
//		struct Node* next;
//		int val;
//	};
//}
//int main()
//{
//	// 这里默认是访问的是全局的rand函数指针
//	printf("%p\n", rand);
//	// 这里指定bit命名空间中的rand
//	printf("%d\n", bit::rand);
//	return 0;
//}

//#include <stdio.h>
//#include <stdio.h>
//#include <stdlib.h>
//int rand = 10;
//int main()
//{
//	// 编译报错：error C2365: “rand”: 重定义；以前的定义是“函数”
//	printf("%d\n", rand);
//	return 0;
//}
//// test.cpp
//// 这里的std cout等我们都看不懂，没关系，下面我们会依次讲解
//#include<iostream>
//using namespace std;
//
//int main()
//{
//	cout << "hello world\n" << endl;
//	return 0;
//}
//#include<iostream>
//using namespace std;
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
//	//Stack(const Stack& st)
//	//{
//	//	cout << "Stack(const Stack& st)" << endl;
//
//	//	// 需要对_a指向资源创建同样大的资源再拷贝值
//	//	_a = (STDataType*)malloc(sizeof(STDataType) * st._capacity);
//	//	if (nullptr == _a)
//	//	{
//	//		perror("malloc申请空间失败!!!");
//	//		return;
//	//	}
//	//	memcpy(_a, st._a, sizeof(STDataType) * st._top);
//	//	_top = st._top;
//	//	_capacity = st._capacity;
//	//}
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
//int main() {
//	int i = 1234;
//	int j = -1234;
//	std::cout << i << endl;
//	cout << i << endl;
//
//	int a = 0;
//	double b = 0.1;
//	char c = 'x';
//
//	cout << a << " " << b << endl;
//	cin >> a >> b >> c;
//
//}
////#include<iostream>
//using namespace std;
//void f(int x)
//{
//	cout << "f(int x)" << endl;
//}
//void f(int* ptr)
//{
//	cout << "f(int* ptr)" << endl;
//}
//int main()
//{
//	f(0);
//	// 本想通过f(NULL)调用指针版本的f(int*)函数，但是由于NULL被定义成0，调用了f(int
//	//x)，因此与程序的初衷相悖。
//	f(NULL);
//	f((int*)NULL);
//	// 编译报错：error C2665: “f”: 2 个重载中没有一个可以转换所有参数类型
//	// f((void*)NULL);
//	f(nullptr);
//	return 0;
//}
//#ifndef NULL
//  #ifdef __cplusplus
//    #define NULL 0
//  #else
//    #define NULL ((void *)0)
//  #endif
//#endif
//#ifndef NULL
//#ifdef __cplusplus
//#define NULL 0
//#else
//#define NULL ((void *)0)
//#endif
//#endif
//#include<iostream>
//using namespace std;
//// 实现一个ADD宏函数的常见问题
////#define ADD(int a, int b) return a + b;
////#define ADD(a, b) a + b;
////#define ADD(a, b) (a + b)
//// 正确的宏实现
//#define ADD(a, b) ((a) + (b))
//// 为什么不能加分号?
//// 为什么要加外面的括号?
//// 为什么要加里面的括号?
//int main()
//{
//	int ret = ADD(1, 2);
//	cout << ADD(1, 2) << endl;
//	cout << ADD(1, 2) * 5 << endl;
//	int x = 1, y = 2;
//	ADD(x & y, x | y); // -> (x&y+x|y)
//	return 0;
//}
//// F.h
//#include <iostream>
//using namespace std;
//inline void f(int i);
//// F.cpp
//#include "F.h"
//void f(int i)
//{
//	cout << i << endl;
//}
//// main.cpp
//#include "F.h"
//int main()
//{// 链接错误：无法解析的外部符号 "void __cdecl f(int)" (?f@@YAXH@Z)
//	f(10);
//	return 0;
//}
//#include<iostream>
//using namespace std;
//inline int Add(int x, int y)
//{
//	int ret = x + y;
//	ret += 1;
//	ret += 1;
//	ret += 1;
//	return ret;
//}
//int main()
//{
//	// 可以通过汇编观察程序是否展开
//	// 有call Add语句就是没有展开，没有就是展开了
//	int ret = Add(1, 2);
//	cout << Add(1, 2) * 5 << endl;
//	return 0;
//}
//int main()
//{
//	const int a = 10;
//	// 编译报错：error C2440: “初始化”: 无法从“const int”转换为“int &”
//	// 这里的引用是对a访问权限的放大
//	//int& ra = a;
//	// 这样才可以
//	const int& ra = a;
//	// 编译报错：error C3892: “ra”: 不能给常量赋值
//	//ra++;
//	// 这里的引用是对b访问权限的缩小
//	int b = 20;
//	const int& rb = b;
//	// 编译报错：error C3892: “rb”: 不能给常量赋值
//	//rb++;
//	return 0;
//}
//#include<iostream>
//using namespace std;
//int main()
//{
//	int a = 10;
//	const int& ra = 30;
//	// 编译报错: “初始化”: 无法从“int”转换为“int &”
//	// int& rb = a * 3;
//	const int& rb = a * 3;
//	double d = 12.34;
//	// 编译报错：“初始化”: 无法从“double”转换为“int &”
//	// int& rd = d;
//	const int& rd = d;
//	return 0;
//}
//void Swap(int& rx, int& ry)
//{
//	int tmp = rx;
//	rx = ry;
//	ry = tmp;
//}
//int main()
//{
//	int x = 0, y = 1;
//	cout << x << " " << y << endl;
//	Swap(x, y);
//	cout << x << " " << y << endl;
//	return 0;
//}
//#include<iostream>
//using namespace std;
//typedef int STDataType;
//typedef struct Stack
//{
//	STDataType* a;
//	int top;
//	int capacity;
//}ST;
//void STInit(ST& rs, int n = 4)
//{
//	rs.a = (STDataType*)malloc(n * sizeof(STDataType));
//	rs.top = 0;
//	rs.capacity = n;
//}
//// 栈顶
//void STPush(ST& rs, STDataType x)
//{
//	assert(ps);
//	// 满了， 扩容
//	if (rs.top == rs.capacity)
//	{
//		printf("扩容\n");
//		int newcapacity = rs.capacity == 0 ? 4 : rs.capacity * 2;
//		STDataType* tmp = (STDataType*)realloc(rs.a, newcapacity *
//			sizeof(STDataType));
//		if (tmp == NULL)
//		{
//			perror("realloc fail");
//			return;
//		}
//		rs.a = tmp;
//		rs.capacity = newcapacity;
//	}
//	rs.a[rs.top] = x;
//	rs.top++;
//}
//// int STTop(ST& rs)
//int& STTop(ST& rs)
//{
//	assert(rs.top > 0);
//	return rs.a[rs.top];
//}
//int main()
//{
//	// 调用全局的
//	ST st1;
//	STInit(st1);
//	STPush(st1, 1);
//	STPush(st1, 2);
//	cout << STTop(st1) << endl;
//	STTop(st1) += 10;
//	cout << STTop(st1) << endl;
//	return 0;
//}
//#include<iostream>
//using namespace std;
//typedef struct SeqList
//{
//	int a[10];
//	int size;
//}SLT;
//// 一些主要用C代码实现版本数据结构教材中，使用C++引用替代指针传参，目的是简化程序，避开复
//杂的指针，但是很多同学没学过引用，导致一头雾水。
//void SeqPushBack(SLT& sl, int x)
//{}
//typedef struct ListNode
//{
//	int val;
//	struct ListNode* next;
//}LTNode, * PNode;
//// 指针变量也可以取别名，这里LTNode*& phead就是给指针变量取别名
//// 这样就不需要用二级指针了，相对而言简化了程序
////void ListPushBack(LTNode** phead, int x)
////void ListPushBack(LTNode*& phead, int x)
//void ListPushBack(PNode& phead, int x)
//{
//	PNode newnode = (PNode)malloc(sizeof(LTNode));
//	newnode->val = x;
//	newnode->next = NULL;
//	if (phead == NULL)
//	{
//		phead = newnode;
//	}
//	else
//	{
//		//...
//	}
//}
//int main()
//{
//	PNode plist = NULL;
//	ListPushBack(plist, 1);
//	return 0;
//}
//#include<iostream>
//using namespace std;
//int main()
//{
//	int a = 10;
//	// 编译报错：“ra”: 必须初始化引用
//	//int& ra;
//	int& b = a;
//	int c = 20;
//	// 这里并非让b引用c，因为C++引用不能改变指向，
//	// 这里是一个赋值
//	b = c;
//	cout << &a << endl;
//	cout << &b << endl;
//	cout << &c << endl;
//	return 0;
//}

//#include<iostream>
//using namespace std;
//int main()
//{
//	int a = 0;
//	// 引用：b和c是a的别名
//	int& b = a;
//	int& c = a;
//	// 也可以给别名b取别名，d相当于还是a的别名
//	int& d = b;
//	++d;
//	// 这里取地址我们看到是一样的
//	cout << &a << endl;
//	cout << &b << endl;
//	cout << &c << endl;
//	cout << &d << endl;
//	return 0;
//}

//#include<iostream>
//using namespace std;
//// 1、参数类型不同
//int Add(int left, int right)
//{
//	cout << "int Add(int left, int right)" << endl;
//	return left + right;
//}
//double Add(double left, double right)
//{
//	cout << "double Add(double left, double right)" << endl;
//	return left + right;
//}
//// 2、参数个数不同
//void f()
//{
//	cout << "f()" << endl;
//}
//void f(int a)
//{
//	cout << "f(int a)" << endl;
//}
//// 3、参数类型顺序不同
//void f(int a, char b)
//{
//	cout << "f(int a,char b)" << endl;
//}
//void f(char b, int a)
//{
//	cout << "f(char b, int a)" << endl;
//}
//// 返回值不同不能作为重载条件，因为调用时也无法区分
////void fxx()
////{}
////
////int fxx()
////{
//// return 0;
////}
//// 下面两个函数构成重载
//// f()但是调用时，会报错，存在歧义，编译器不知道调用谁
//void f1()
//{
//	cout << "f()" << endl;
//}
//void f1(int a = 10)
//{
//	cout << "f(int a)" << endl;
//}
//int main() 
//{
//	Add(10, 20);
//	Add(10.1, 20.2);
//	f();
//	f(10);
//	f(10, 'a');
//	f('a', 10);
//	return 0;
//}
//#include <iostream>
//#include <assert.h>
//using namespace std;
//void Func(int a = 0)
//{
//	cout << a << endl;
//}
//int main()
//{
//	Func(); // 没有传参时，使用参数的默认值
//	Func(10); // 传参时，使用指定的实参
//	return 0;
//}
//#include <iostream>
//using namespace std;
//// 全缺省
//void Func1(int a = 10, int b = 20, int c = 30)
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl << endl;
//}
//// 半缺省
//void Func2(int a, int b = 10, int c = 20)
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl << endl;
//}
//int main()
//{
//	Func1();
//	Func1(1);
//	Func1(1, 2);
//	Func1(1, 2, 3);
//	Func2(100);
//	Func2(100, 200);
//	Func2(100, 200, 300);
//	return 0;
//}
//// Stack.h
//#include <iostream>
//#include <assert.h>
//using namespace std;
//typedef int STDataType;
//typedef struct Stack
//{
//	STDataType* a;
//	int top;
//	int capacity;
//}ST;
//void STInit(ST* ps, int n = 4);
//// Stack.cpp
//#include"Stack.h"
//// 缺省参数不能声明和定义同时给
//void STInit(ST* ps, int n)
//{
//	assert(ps && n > 0);
//	ps->a = (STDataType*)malloc(n * sizeof(STDataType));
//	ps->top = 0;
//	ps->capacity = n;
//}
//// test.cpp
//#include"Stack.h"
//int main()
//{
//	ST s1;
//	STInit(&s1);
//	// 确定知道要插入1000个数据，初始化时一把开好，避免扩容
//	ST s2;
//	STInit(&s2, 1000);
//	return 0;
//}
//#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//using namespace std;
//int main()
//{
//	int a = 0;
//	double b = 0.1;
//	char c = 'x';
//	cout << a << " " << b << " " << c << endl;
//	std::cout << a << " " << b << " " << c << std::endl;
//	scanf("%d%lf", &a, &b);
//	printf("%d %lf\n", a, b);
//	// 可以自动识别变量的类型
//	cin >> a;
//	cin >> b >> c;
//	cout << a << endl;
//	cout << b << " " << c << endl;
//	return 0;
//}
//#include<iostream>
//using namespace std;
//int main()
//{
//	// 在io需求比较高的地方，如部分大量输入的竞赛题中，加上以下3行代码
//	// 可以提高C++IO效率
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//	return 0;
//}
////test.cpp
//#include<stdio.h>
//
//int main() {
//	printf("hello world\n");
//	return 0;
//}

//test.cpp
//#include<iostream>
//using namespace std;

//int main() {
//	//int i = 1;
//	//i << 10;
//
//	cout << "hello world\n" << endl;
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//namespace blog {
//	int rand = 10;
//}
//
//int a = 0;
//int main() {
//	printf("%p\n",rand);
//	printf("%d\n",blog::rand);
//
//	int a = 1;
//	printf("%d\n",a);
//
//	printf("%d\n",::a);
//
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//
//namespace blog
//{
//	int rand = 20;
//
//	int Add(int left, int right) {
//		return left + right;
//	}
//
//	struct Node {
//		struct Node* next;
//		int val;
//	};
//}
//
//int main() {
//	printf("%d\n",blog::Add(1,1));
//
//	struct blog::Node p1;
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//
//namespace blog {
//
//	namespace b1 {
//		int rand = 1;
//		int Add(int left, int right) {
//			return left + right;
//		}
//	}
//
//	namespace b2 {
//		int rand = 2;
//		int Add(int left, int right) {
//			return (left + right) * 10;
//		}
//	}
//}
//
//int main() {
//	printf("%d\n",blog::b1::rand);
//	printf("%d\n", blog::b2::rand);
//
//}





