#include"Stack.h"
#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
using namespace std;
int main()
{
	int a = 10;
	// ���뱨����ra��: �����ʼ������
	//int& ra;
	int& b = a;
	int c = 20;
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	// ���ﲢ����b����c����ΪC++���ò��ܸı�ָ��
	// ������һ����ֵ
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
//	// ���ã�b��c��a�ı���
//	int& b = a;
//	int& c = a;
//	// Ҳ���Ը�����bȡ������d�൱�ڻ���a�ı���
//	int& d = b;
//	++d;
//	// ����ȡ��ַ���ǿ�����һ����
//	cout << &a << endl;
//	cout << &b << endl;
//	cout << &c << endl;
//	cout << &d << endl;
//	return 0;
//}

//// ��������������������
//// f()���ǵ���ʱ���ᱨ���������壬��������֪������˭
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
//// 1���������Ͳ�ͬ
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
//// 2������������ͬ
//void f()
//{
//	cout << "f()" << endl;
//}
//void f(int a)
//{
//	cout << "f(int a)" << endl;
//}
//
//// 3����������˳��ͬ
//void f(int a, char b)
//{
//	cout << "f(int a,char b)" << endl;
//}
//
//void f(char b, int a)
//{
//	cout << "f(char b, int a)" << endl;
//}

// ��������������������
// f()���ǵ���ʱ���ᱨ���������壬��������֪������˭

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
//	// ȷ��֪��Ҫ����1000�����ݣ���ʼ��ʱһ�ѿ��ã���������
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
//// ȫȱʡ
//void Func1(int a = 10, int b = 20, int c = 30)//ȫȱʡ
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl << endl;
//}
//// ��ȱʡ
//void Func2(int a, int b = 10, int c = 20)//��ȱʡ
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl << endl;
//}
//int main()
//{
//	Func1();//ʹ��ȱʡ�������õ�Ĭ��ֵ
//	Func1(1);
//	Func1(1, 2);//���θ�ֵ
//	Func1(1, 2, 3);
//	Func2(100);
//	Func2(100, 200);
//	Func2(, 200, );//�޷���Ծ��ֵ
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
//	cout << a << "             " << b << " " << c << "\n" << '\n' << endl;//�������ո�
//	std::cout << a << " " << b << " " << c << std::endl;//��������ո�
//	//cout�������Ҫָ�������ʽ���Զ�ʶ������
//
//	//scanf("%d%lf", &a, &b);
//	//printf("%d %lf\n", a, b);
//
//	double d = 2.22222222;
//	printf("%.2lf\n", d);
//	cout << d << endl;
//	cout << &d << endl;
//
//	// cin�����Զ�ʶ���������������
//	//cin >> a;
//	//cin >> b >> c;
//	cin >>a>> b >> c;
//	cout << a << endl;
//	cout << b << " " << c << endl;
//
//	return 0;
//}

// //չ��ͷ�ļ�
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
//// ��
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
//// ��
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
//	// ::�������޶���
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
//	// ��ֵ����
//	A aa1;
//	f1(aa1);
//	cout << endl;
//	// ��ʽ���ͣ���������+��������->�Ż�Ϊֱ�ӹ���
//	f1(1);
//	// һ�����ʽ�У���������+��������->�Ż�Ϊһ������
//	f1(A(2));
//	cout << endl;
//	cout << "***********************************************" << endl;
//	// ��ֵ����
//// ����ʱһ�����ʽ�У�������������+��������->�Ż�һ���������� ��vs2019 debug��
//// һЩ���������Ż��ø����������п��кϲ��Ż���ֱ�ӱ�Ϊ���졣��vs2022 debug��
//	f2();
//	cout << endl;
//	// ����ʱһ�����ʽ�У�������������+��������->�Ż�һ���������� ��vs2019 debug��
//	// һЩ���������Ż��ø����������п��кϲ��Ż���ֱ�ӱ�Ϊ���졣��vs2022 debug��
//	A aa2 = f2();
//	cout << endl;
//	// һ�����ʽ�У�������������+��ֵ����->�޷��Ż�
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
//	// ������ô���������Ϊ�������޷�ʶ��������һ���������������Ƕ�����
//	//A aa1();
//	// �������ǿ�����ô����������������������ص㲻��ȡ���֣�
//	// ����������������ֻ����һ�У����ǿ��Կ�����һ�����ͻ��Զ�������������
//	A();
//	A(1);
//	A aa2(2);
//	// �������������������¾ͺܺ��ã���Ȼ����һЩ����ʹ�ó�������������Ժ���������˵
//	Solution().Sum_Solution(10);
//	return 0;
//}





//class Solution {
//	// �ڲ���
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
//		// �䳤����
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
//	class B // BĬ�Ͼ���A����Ԫ
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
//	// ��Ԫ����
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
//// ǰ������������A����Ԫ������������������ʶB
//class B;
//class A
//{
//	// ��Ԫ����
//	friend void func(const A& aa, const B& bb);
//private:
//	int _a1 = 1;
//	int _a2 = 2;
//};
//class B
//{
//	// ��Ԫ����
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





//A��D B A C
//B��B A D C
//C��C D B A
//D��A B D C
//E��C A B D
//F��C D A B
//C c;
//int main()
//{
//	A a;
//	B b;
//	static D d;
//	return 0��
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
//		// �䳤����
//		Sum arr[n];
//		return Sum::GetRet();
//	}
//};
//// ʵ��һ���࣬��������д������˶��ٸ������
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
//	// ����������
//	static int _scount;
//};
//// �������ʼ��
//int A::_scount = 0;
//int main()
//{
//	cout << A::GetACount() << endl;
//	A a1, a2;
//	A a3(a1);
//	cout << A::GetACount() << endl;
//	cout << a1.GetACount() << endl;
//	// ���뱨��error C2248: ��A::_scount��: �޷����� private ��Ա(�ڡ�A����������)
//	//cout << A::_scount << endl;
//	return 0;
//}


//#include<iostream>
//using namespace std;
//class A
//{
//public:
//	// ���캯��explicit�Ͳ���֧����ʽ����ת��
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
//	// 1����һ��A����ʱ�������������ʱ���󿽱�����aa3
//	// ������������������+��������->�Ż�Ϊֱ�ӹ���
//	A aa1 = 1;
//	aa1.Print();
//	const A& aa2 = 1;
//	// C++11֮���֧�ֶ����ת��
//	A aa3 = { 2,2 };
//	// aa3��ʽ����ת��Ϊb����
//	// ԭ�����������
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
//	// ע�����ﲻ�ǳ�ʼ�������������ȱʡֵ�����ȱʡֵ�Ǹ���ʼ���б��
//	// �����ʼ���б�û����ʾ��ʼ����Ĭ�Ͼͻ������ȱʡֵ��ʼ��
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
//		// error C2512: ��Time��: û�к��ʵ�Ĭ�Ϲ��캯������
//		// error C2530 : ��Date::_ref�� : �����ʼ������
//		// error C2789 : ��Date::_n�� : �����ʼ�������޶����͵Ķ���
//	}
//	void Print() const
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//	Time _t; // û��Ĭ�Ϲ���
//	int& _ref; // ����
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
//	// �����const����Ҳ���Ե���const��Ա������һ��Ȩ�޵���С
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
//	// ��Ԫ��������
//	friend ostream& operator<<(ostream& out, const Date& d);
//	friend istream& operator>>(istream& in, Date& d);
//public:
//	Date(int year = 1900, int month = 1, int day = 1);
//	void Print() const;
//	// ֱ�Ӷ��������棬��Ĭ����inline
//	// Ƶ������
//	int GetMonthDay(int year, int month)
//	{
//		assert(month > 0 && month < 13);
//		static int monthDayArray[13] = { -1, 31, 28, 31, 30, 31, 30,
//		31, 31, 30, 31, 30, 31 };
//		// 365�� 5h +
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
//	// d1 += ����
//	Date& operator+=(int day);
//	Date operator+(int day) const;
//	// d1 -= ����
//	Date& operator-=(int day);
//	Date operator-(int day) const;
//	// d1 - d2
//	int operator-(const Date& d) const;
//	// ++d1 -> d1.operator++()
//	Date& operator++();
//	// d1++ -> d1.operator++(0)
//	// Ϊ�����֣��������أ�������++��ǿ��������һ��int�β�
//	// ���ﲻ��Ҫд�β�������Ϊ����ֵ�Ƕ��ٲ���Ҫ��Ҳ����Ҫ��
//	// �������������Ϊ�˸�ǰ��++������������
//	Date operator++(int);
//	Date& operator--();
//	Date operator--(int);
//	// ������
//	// �����飬��ΪDate* thisռ����һ������λ�ã�ʹ��d<<cout������ϰ��
//	//void operator<<(ostream& out);
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//// ����
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
//		cout << "���ڷǷ�" << endl;
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
//		// ����һ���µ�����
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
//	out << d._year << "��" << d._month << "��" << d._day << "��" << endl;
//	return out;
//}
//istream& operator>>(istream& in, Date& d)
//{
//	cout << "����������������:>";
//	in >> d._year >> d._month >> d._day;
//	if (!d.CheckDate())
//	{
//		cout << "���ڷǷ�" << endl;
//	}
//	return in;
//}
//// Test.cpp
//#include"Date.h"
//void TestDate1()
//{
//	// ������Ҫ����һ�´������+��-
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
//	// �����÷��ؼ��ٿ���
//	// d1 = d2;
//	Date& operator=(const Date& d)
//	{
//		// ��Ҫ����Լ����Լ���ֵ�����
//		if (this != &d)
//		{
//			_year = d._year;
//			_month = d._month;
//			_day = d._day;
//		}
//		// d1 = d2���ʽ�ķ��ض���Ӧ��Ϊd1��Ҳ����*this
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
//	// ��Ҫע�������ǿ������죬���Ǹ�ֵ����
//	// �����μ�ס��ֵ������������Ѿ����ڵĶ���ֱ�ӵĿ�����ֵ
//	// ��������������һ�����󿽱���ʼ������һ��Ҫ�����Ķ���
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
//		cout << "ǰ��++" << endl;
//		//...
//		return *this;
//	}
//	Date operator++(int)
//	{
//		Date tmp;
//		cout << "����++" << endl;
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
//	// ��������غ���������ʾ����
//	d1.operator==(d2);
//	// ��������ת���� d1.operator==(d2);
//	d1 == d2;
//	// ��������ת���� d1.operator++();
//	++d1;
//	// ��������ת���� d1.operator++(0);
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
//// ����Ϊȫ�ֵ����ٶ������˽�г�Ա����������
//// �м��ַ������Խ����
//// 1����Ա�Ź���
//// 2��Date�ṩgetxxx����
//// 3����Ԫ����
//// 4������Ϊ��Ա����
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
//	// ��������غ���������ʾ����
//	operator==(d1, d2);
//	// ��������ת���� operator==(d1, d2);
//	d1 == d2;
//	return 0;
//}



//#include<iostream>
//using namespace std;
//// ���뱨����operator +������������һ�������͵��β�
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
//typedef void(A::* PF)(); //��Ա����ָ������
//int main()
//{
//	// C++�涨��Ա����Ҫ��&����ȡ������ָ��
//	PF pf = &A::func;
//	A obj;//����ob�����temp
//	// ������ó�Ա����ָ��ʱ��ʹ��.*�����
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
//			perror("malloc����ռ�ʧ��");
//			return;
//		}
//		_capacity = n;
//		_top = 0;
//	}
//	Stack(const Stack& st)
//	{
//		// ��Ҫ��_aָ����Դ����ͬ�������Դ�ٿ���ֵ
//		_a = (STDataType*)malloc(sizeof(STDataType) * st._capacity);
//		if (nullptr == _a)
//		{
//			perror("malloc����ռ�ʧ��!!!");
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
//// ����Stackʵ�ֶ���
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
//	// Stack����ʾʵ�ֿ������죬���Զ����ɵĿ����������ǳ����
//	// �ᵼ��st1��st2�����_aָ��ָ��ͬһ����Դ������ʱ���������Σ��������
//	Stack st2 = st1;
//	MyQueue mq1;
//	// MyQueue�Զ����ɵĿ������죬���Զ�����Stack�����������pushst/popst
//	// �Ŀ�����ֻҪStack���������Լ�ʵ�������������û����
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
//	// ���뱨��error C2652: ��Date��: �Ƿ��ĸ��ƹ��캯��: ��һ��������Ӧ�ǡ�Date��
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
//	// C++�涨�Զ������Ͷ�����п�����Ϊ������ÿ������죬�������ﴫֵ����Ҫ���ÿ���
//	����
//		// ���������d1��ֵ���θ�dҪ���ÿ���������ɿ����������ô��ο��Խ�������Ŀ���
//		Func1(d1);
//	cout << &d1 << endl;
//	// ���������ɿ��������ǲ��ǿ������죬ֻ��һ����ͨ�Ĺ���
//	Date d2(&d1);
//	d1.Print();
//	d2.Print();
//	//����д���ǿ������죬ͨ��ͬ���͵Ķ����ʼ�����죬������ָ��
//	Date d3(d1);
//	d2.Print();
//	// Ҳ��������д������Ҳ�ǿ�������
//	Date d4 = d1;
//	d2.Print();
//	// Func2������һ���ֲ�����tmp��������Ϊ����ֵ
//	// Func2����������tmp����������ˣ��൱����һ��Ұ����
//	Date ret = Func2();
//	ret.Print();
//	return 0;
//}





//#include<iostream>
//using namespace std;
//// �����¼��˹����������C++�汾Stackʵ��
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
//			// �����ű������Ŷ࣬����ƥ������
//			if (st.Empty())
//			{
//				return false;
//			}
//			// ջ����ȡ������
//			char top = st.Top();
//			st.Pop();
//			// ˳��ƥ��
//			if ((*s == ']' && top != '[')
//				|| (*s == '}' && top != '{')
//				|| (*s == ')' && top != '('))
//			{
//				return false;
//			}
//		}
//		++s;
//	}
//	// ջΪ�գ������棬˵��������ƥ�� �����Ŷ࣬��������ƥ������
//	return st.Empty();
//}
//// ��֮ǰC�汾Stackʵ��
//bool isValid(const char* s) {
//	ST st;
//	STInit(&st);
//	while (*s)
//	{
//		// ��������ջ
//		if (*s == '(' || *s == '[' || *s == '{')
//		{
//			STPush(&st, *s);
//		}
//		else // ������ȡջ�������ų���ƥ��
//		{
//			if (STEmpty(&st))
//			{
//				STDestroy(&st);
//				return false;
//			}
//			char top = STTop(&st);
//			STPop(&st);
//			// ��ƥ��
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
//	// ջ��Ϊ�գ�˵�������ű������Ŷ࣬������ƥ��
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
//			perror("malloc����ռ�ʧ��");
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
//// ����Stackʵ�ֶ���
//class MyQueue
//{
//public:
//	//������Ĭ������MyQueue����������������Stack���������ͷŵ�Stack�ڲ�����Դ
//	// ��ʾд������Ҳ���Զ�����Stack������
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
//			perror("malloc����ռ�ʧ��");
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
//// ����Stackʵ�ֶ���
//class MyQueue
//{
//public:
//	//������Ĭ������MyQueue�Ĺ��캯��������Stack�Ĺ��죬�����������Ա�ĳ�ʼ��
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
//	// 1.�޲ι��캯��
//	Date()
//	{
//		_year = 1;
//		_month = 1;
//		_day = 1;
//	}
//	// 2.���ι��캯��
//	Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	// 3.ȫȱʡ���캯��
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
//	// ����������������еĵڶ������ι��죬��һ���͵�����ע�͵�
//	// ���뱨��error C2512: ��Date��: û�к��ʵ�Ĭ�Ϲ��캯������
//	Date d1; // ����Ĭ�Ϲ��캯��
//	Date d2(2025, 1, 1); // ���ô��εĹ��캯��
//	// ע�⣺���ͨ���޲ι��캯����������ʱ��������治�ø����ţ�����������޷�
//	// ���������Ǻ�����������ʵ��������
//	// warning C4930: ��Date d3(void)��: δ����ԭ�ͺ���(�Ƿ��������ñ��������?)
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
//	// ��Ա����
//	void Init(int n = 4)
//	{
//		_a = (STDataType*)malloc(sizeof(STDataType) * n);
//		if (nullptr == _a)
//		{
//			perror("malloc����ռ�ʧ��");
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
//	// ��Ա����
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
//	// ���ˣ� ����
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
//		// ���뱨��error C2106: ��=��: �����������Ϊ��ֵ
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
//	// ����ֻ��������û�п��ռ�
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	// Date��ʵ����������d1��d2
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
//// ����һ��A/B/Cʵ�����Ķ����Ƕ��
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
//	// ����ֻ��������û�п��ռ�
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	// Date��ʵ����������d1��d2
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
//	// ��Ա����
//	void Init(int n = 4);
//private:
//	// ��Ա����
//	int* array;
//	size_t capacity;
//	size_t top;
//};
//// �����Ͷ�����룬��Ҫָ������
//void Stack::Init(int n)
//{
//	array = (int*)malloc(sizeof(int) * n);
//	if (nullptr == array)
//	{
//		perror("malloc����ռ�ʧ��");
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
//// C++����struct����������
//// 1����������Զ��庯��
//// 2��struct���ƾͿ��Դ�������
//// C++����C��struct���÷�
//typedef struct ListNodeC
//{
//	struct ListNodeC* next;
//	int val;
//}LTNode;
//// ������Ҫtypedef��ListNodeCPP�Ϳ��Դ�������
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
//	// Ϊ�����ֳ�Ա������һ��ϰ���ϳ�Ա����
//	// ���һ�������ʶ����_ ���� m��ͷ
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
//	// ��Ա����
//	void Init(int n = 4)
//	{
//		array = (int*)malloc(sizeof(int) * n);
//		if (nullptr == array)
//		{
//			perror("malloc����ռ�ʧ��");
//			return;
//		}
//		capacity = n;
//		top = 0;
//	}
//	void Push(int x)
//	{
//		// ...����
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
//	// ��Ա����
//	int* array;
//	size_t capacity;
//	size_t top;
//}; // �ֺŲ���ʡ��
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
//	// ����ͨ��f(NULL)����ָ��汾��f(int*)��������������NULL�������0��������f(int
//	//x)����������ĳ�����㣡�
//	f(NULL);
//	f((int*)NULL);
//	// ���뱨��error C2665: ��f��: 2 ��������û��һ������ת�����в�������
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
//	// ���Ӵ����޷��������ⲿ���� "void __cdecl f(int)" (?f@@YAXH@Z)
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
//	// ����ͨ�����۲�����Ƿ�չ��
//	// ��call Add������û��չ����û�о���չ����
//	int ret = Add(1, 2);
//	cout << Add(1, 2) * 5 << endl;
//	return 0;
//}
//#include<iostream>
//using namespace std;
//// ʵ��һ��ADD�꺯���ĳ�������
////#define ADD(int a, int b) return a + b;
////#define ADD(a, b) a + b;
////#define ADD(a, b) (a + b)
//// ��ȷ�ĺ�ʵ��
//#define ADD(a, b) ((a) + (b))
//// Ϊʲô���ܼӷֺ�?
//// ΪʲôҪ�����������?
//// ΪʲôҪ�����������?
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
//	// ���뱨��error C2440: ����ʼ����: �޷��ӡ�const int��ת��Ϊ��int &��
//	// ����������Ƕ�a����Ȩ�޵ķŴ�
//	//int& ra = a;
//	// �����ſ���
//	const int& ra = a;
//	// ���뱨��error C3892: ��ra��: ���ܸ�������ֵ
//	//ra++;
//	// ����������Ƕ�b����Ȩ�޵���С
//	int b = 20;
//	const int& rb = b;
//	// ���뱨��error C3892: ��rb��: ���ܸ�������ֵ
//	//rb++;
//	return 0;
//}
//#include<iostream>
//using namespace std;
//int main()
//{
//	int a = 10;
//	const int& ra = 30;
//	// ���뱨��: ����ʼ����: �޷��ӡ�int��ת��Ϊ��int &��
//	// int& rb = a * 3;
//	const int& rb = a * 3;
//	double d = 12.34;
//	// ���뱨������ʼ����: �޷��ӡ�double��ת��Ϊ��int &��
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
//// һЩ��Ҫ��C����ʵ�ְ汾���ݽṹ�̲��У�ʹ��C++�������ָ�봫�Σ�Ŀ���Ǽ򻯳��򣬱ܿ���
////�ӵ�ָ�룬���Ǻܶ�ͬѧûѧ�����ã�����һͷ��ˮ��
//void SeqPushBack(SLT& sl, int x)
//{}
//typedef struct ListNode
//{
//	int val;
//	struct ListNode* next;
//}LTNode, * PNode;
//// ָ�����Ҳ����ȡ����������LTNode*& phead���Ǹ�ָ�����ȡ����
//// �����Ͳ���Ҫ�ö���ָ���ˣ���Զ��Լ��˳���
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
//// ջ��
//void STPush(ST& rs, STDataType x)
//{
//	assert(ps);
//	// ���ˣ� ����
//	if (rs.top == rs.capacity)
//	{
//		printf("����\n");
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
//	// ����ȫ�ֵ�
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
//	// ���뱨����ra��: �����ʼ������
//	//int& ra;
//	int& b = a;
//	int c = 20;
//	// ���ﲢ����b����c����ΪC++���ò��ܸı�ָ��
//	// ������һ����ֵ
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
//	// ���ã�b��c��a�ı���
//	int& b = a;
//	int& c = a;
//	// Ҳ���Ը�����bȡ������d�൱�ڻ���a�ı���
//	int& d = b;
//	++d;
//	// ����ȡ��ַ���ǿ�����һ����
//	cout << &a << endl;
//	cout << &b << endl;
//	cout << &c << endl;
//	cout << &d << endl;
//	return 0;
//}
//#include<iostream>
//using namespace std;
//// 1���������Ͳ�ͬ
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
//// 2������������ͬ
//void f()
//{
//	cout << "f()" << endl;
//}
//void f(int a)
//{
//	cout << "f(int a)" << endl;
//}
//// 3����������˳��ͬ
//void f(int a, char b)
//{
//	cout << "f(int a,char b)" << endl;
//}
//void f(char b, int a)
//{
//	cout << "f(char b, int a)" << endl;
//}
//// ����ֵ��ͬ������Ϊ������������Ϊ����ʱҲ�޷�����
////void fxx()
////{}
////
////int fxx()
////{
//// return 0;
////}
//// ��������������������
//// f()���ǵ���ʱ���ᱨ���������壬��������֪������˭
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
//// ȱʡ�������������Ͷ���ͬʱ��
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
//	// ȷ��֪��Ҫ����1000�����ݣ���ʼ��ʱһ�ѿ��ã���������
//	ST s2;
//	STInit(&s2, 1000);
//	return 0;
//}
//#include <iostream>
//using namespace std;
//// ȫȱʡ
//void Func1(int a = 10, int b = 20, int c = 30)
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl << endl;
//}
//// ��ȱʡ
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
//	Func(); // û�д���ʱ��ʹ�ò�����Ĭ��ֵ
//	Func(10); // ����ʱ��ʹ��ָ����ʵ��
//	return 0;
//}
//#include<iostream>
//using namespace std;
//int main()
//{
//	// ��io����Ƚϸߵĵط����粿�ִ�������ľ������У���������3�д���
//	// �������C++IOЧ��
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
//	// �����Զ�ʶ�����������
//	cin >> a;
//	cin >> b >> c;
//	cout << a << endl;
//	cout << b << " " << c << endl;
//	return 0;
//}
//// ָ�������ռ����
//int main()
//{
//	printf("%d\n", N::a);
//	return 0;
//}
//// using�������ռ���ĳ����Աչ��
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
//	// ���뱨��error C2065: ��a��: δ�����ı�ʶ��
//	printf("%d\n", a);
//	return 0;
//}
////2. �����ռ����Ƕ��
//namespace bit
//{
//	// ����
//	namespace pg
//	{
//		int rand = 1;
//		int Add(int left, int right)
//		{
//			return left + right;
//		}
//	}
//	// ����
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
//// ���ļ��п��Զ���ͬ��namespace�����ǻ�Ĭ�Ϻϲ���һ�𣬾���ͬһ��namespaceһ��
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
//	// ջ��
//	void STPush(ST* ps, STDataType x)
//	{
//		assert(ps);
//		// ���ˣ� ����
//		if (ps->top == ps->capacity)
//		{
//			printf("����\n");
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
//	// �����
//	void QueuePush(Queue* pq, QDataType x);
//	// ������
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
//// ȫ�ֶ�����һ�ݵ�����Stack
//typedef struct Stack
//{
//	int a[10];
//	int top;
//}ST;
//void STInit(ST* ps) {}
//void STPush(ST* ps, int x) {}
//int main()
//{
//	// ����ȫ�ֵ�
//	ST st1;
//	STInit(&st1);
//	STPush(&st1, 1);
//	STPush(&st1, 2);
//	printf("%d\n", sizeof(st1));
//	// ����bit namespace��
//	bit::ST st2;
//	printf("%d\n", sizeof(st2));
//	bit::STInit(&st2);
//	bit::STPush(&st2, 1);
//	bit::STPush(&st2, 2);
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//// 1. �����������ռ䶨��
//// bit�������ռ�����֣�һ�㿪����������Ŀ�����������ռ�����
//// �����Ͽ��õ���bit�������ȥ�Ժ��Լ���ϰ���Կ������Լ�������д����������zs
//namespace bit
//{
//	// �����ռ��п��Զ������/����/����
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
//	// ����Ĭ���Ƿ��ʵ���ȫ�ֵ�rand����ָ��
//	printf("%p\n", rand);
//	// ����ָ��bit�����ռ��е�rand
//	printf("%d\n", bit::rand);
//	return 0;
//}

//#include <stdio.h>
//#include <stdio.h>
//#include <stdlib.h>
//int rand = 10;
//int main()
//{
//	// ���뱨��error C2365: ��rand��: �ض��壻��ǰ�Ķ����ǡ�������
//	printf("%d\n", rand);
//	return 0;
//}
//// test.cpp
//// �����std cout�����Ƕ���������û��ϵ���������ǻ����ν���
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
//			perror("malloc����ռ�ʧ��");
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
//	//	// ��Ҫ��_aָ����Դ����ͬ�������Դ�ٿ���ֵ
//	//	_a = (STDataType*)malloc(sizeof(STDataType) * st._capacity);
//	//	if (nullptr == _a)
//	//	{
//	//		perror("malloc����ռ�ʧ��!!!");
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
//	// Stack����ʾʵ�ֿ������죬���Զ����ɵĿ����������ǳ����
//	// �ᵼ��st1��st2�����_aָ��ָ��ͬһ����Դ������ʱ���������Σ��������
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
//	// ����ͨ��f(NULL)����ָ��汾��f(int*)��������������NULL�������0��������f(int
//	//x)����������ĳ�����㣡�
//	f(NULL);
//	f((int*)NULL);
//	// ���뱨��error C2665: ��f��: 2 ��������û��һ������ת�����в�������
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
//// ʵ��һ��ADD�꺯���ĳ�������
////#define ADD(int a, int b) return a + b;
////#define ADD(a, b) a + b;
////#define ADD(a, b) (a + b)
//// ��ȷ�ĺ�ʵ��
//#define ADD(a, b) ((a) + (b))
//// Ϊʲô���ܼӷֺ�?
//// ΪʲôҪ�����������?
//// ΪʲôҪ�����������?
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
//{// ���Ӵ����޷��������ⲿ���� "void __cdecl f(int)" (?f@@YAXH@Z)
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
//	// ����ͨ�����۲�����Ƿ�չ��
//	// ��call Add������û��չ����û�о���չ����
//	int ret = Add(1, 2);
//	cout << Add(1, 2) * 5 << endl;
//	return 0;
//}
//int main()
//{
//	const int a = 10;
//	// ���뱨��error C2440: ����ʼ����: �޷��ӡ�const int��ת��Ϊ��int &��
//	// ����������Ƕ�a����Ȩ�޵ķŴ�
//	//int& ra = a;
//	// �����ſ���
//	const int& ra = a;
//	// ���뱨��error C3892: ��ra��: ���ܸ�������ֵ
//	//ra++;
//	// ����������Ƕ�b����Ȩ�޵���С
//	int b = 20;
//	const int& rb = b;
//	// ���뱨��error C3892: ��rb��: ���ܸ�������ֵ
//	//rb++;
//	return 0;
//}
//#include<iostream>
//using namespace std;
//int main()
//{
//	int a = 10;
//	const int& ra = 30;
//	// ���뱨��: ����ʼ����: �޷��ӡ�int��ת��Ϊ��int &��
//	// int& rb = a * 3;
//	const int& rb = a * 3;
//	double d = 12.34;
//	// ���뱨������ʼ����: �޷��ӡ�double��ת��Ϊ��int &��
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
//// ջ��
//void STPush(ST& rs, STDataType x)
//{
//	assert(ps);
//	// ���ˣ� ����
//	if (rs.top == rs.capacity)
//	{
//		printf("����\n");
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
//	// ����ȫ�ֵ�
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
//// һЩ��Ҫ��C����ʵ�ְ汾���ݽṹ�̲��У�ʹ��C++�������ָ�봫�Σ�Ŀ���Ǽ򻯳��򣬱ܿ���
//�ӵ�ָ�룬���Ǻܶ�ͬѧûѧ�����ã�����һͷ��ˮ��
//void SeqPushBack(SLT& sl, int x)
//{}
//typedef struct ListNode
//{
//	int val;
//	struct ListNode* next;
//}LTNode, * PNode;
//// ָ�����Ҳ����ȡ����������LTNode*& phead���Ǹ�ָ�����ȡ����
//// �����Ͳ���Ҫ�ö���ָ���ˣ���Զ��Լ��˳���
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
//	// ���뱨����ra��: �����ʼ������
//	//int& ra;
//	int& b = a;
//	int c = 20;
//	// ���ﲢ����b����c����ΪC++���ò��ܸı�ָ��
//	// ������һ����ֵ
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
//	// ���ã�b��c��a�ı���
//	int& b = a;
//	int& c = a;
//	// Ҳ���Ը�����bȡ������d�൱�ڻ���a�ı���
//	int& d = b;
//	++d;
//	// ����ȡ��ַ���ǿ�����һ����
//	cout << &a << endl;
//	cout << &b << endl;
//	cout << &c << endl;
//	cout << &d << endl;
//	return 0;
//}

//#include<iostream>
//using namespace std;
//// 1���������Ͳ�ͬ
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
//// 2������������ͬ
//void f()
//{
//	cout << "f()" << endl;
//}
//void f(int a)
//{
//	cout << "f(int a)" << endl;
//}
//// 3����������˳��ͬ
//void f(int a, char b)
//{
//	cout << "f(int a,char b)" << endl;
//}
//void f(char b, int a)
//{
//	cout << "f(char b, int a)" << endl;
//}
//// ����ֵ��ͬ������Ϊ������������Ϊ����ʱҲ�޷�����
////void fxx()
////{}
////
////int fxx()
////{
//// return 0;
////}
//// ��������������������
//// f()���ǵ���ʱ���ᱨ���������壬��������֪������˭
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
//	Func(); // û�д���ʱ��ʹ�ò�����Ĭ��ֵ
//	Func(10); // ����ʱ��ʹ��ָ����ʵ��
//	return 0;
//}
//#include <iostream>
//using namespace std;
//// ȫȱʡ
//void Func1(int a = 10, int b = 20, int c = 30)
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl << endl;
//}
//// ��ȱʡ
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
//// ȱʡ�������������Ͷ���ͬʱ��
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
//	// ȷ��֪��Ҫ����1000�����ݣ���ʼ��ʱһ�ѿ��ã���������
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
//	// �����Զ�ʶ�����������
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
//	// ��io����Ƚϸߵĵط����粿�ִ�������ľ������У���������3�д���
//	// �������C++IOЧ��
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





