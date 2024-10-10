#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;





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