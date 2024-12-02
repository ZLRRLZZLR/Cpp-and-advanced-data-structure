
class Solution
{
public:
	int numDecodings(string s)
	{
		// 优化
		int n = s.size();
		vector<int> dp(n + 1);
		dp[0] = 1; // 保证后续填表是正确的
		dp[1] = s[0] != '0';
		// 填表
		for (int i = 2; i <= n; i++)
		{
			// 处理单独编码
			if (s[i - 1] != '0') dp[i] += dp[i - 1];
			// 如果和前面的一个数联合起来编码
			int t = (s[i - 2] - '0') * 10 + s[i - 1] - '0';
			if (t >= 10 && t <= 26) dp[i] += dp[i - 2];
		}
		return dp[n];
	}
};


//class Solution
//{
//public:
//	int maxArea(vector<int>& height)
//	{
//		int left = 0, right = height.size() - 1, ret = 0;
//		while (left < right)
//		{
//			int v = min(height[left], height[right]) * (right - left);
//			ret = max(ret, v);
//			// 移动指针
//			if (height[left] < height[right]) left++;
//			else right--;
//		}
//		return ret;
//	}
//};


////#define N 10
//
////template<size_t N>//可以不给缺省值
////class Stack
////{
////private:
////	int _a[N];
////	int _top;
////};
//
//template<size_t N = 10>
//class Stack
//{
//private:
//	int _a[N];
//	int _top;
//};
//
//int main()
//{
//	Stack<> s0;
//	Stack<5> s1;
//	Stack<10> s2;
//
//	return 0;
//}
//
//template<size_t N = 10, bool flag = false>
//class Stack
//{
//private:
//	int _a[N];
//	int _top;
//};
////
////template<size_t N = 10, bool flag = false>
////class Stack
////{
////private:
////	int _a[N];
////	int _top;
////};
////
////template<size_t N = 10, bool flag = false>
////class Stack
////{
////private:
////	int _a[N];
////	int _top;
////};
//
//
//// C++20
////template<double D>
////class A
////{
////private:
////
////};
//
//
//
////template<class T, size_t N = 10>
////class array
////{
////public:
////	T& operator[](size_t index) { 
////		assert(index < N);
////		return _array[index];
////	}
////private:
////	T _array[N];
////	size_t _size;
////};
//
////int main()
////{
////	// 栈
////	array<int, 10> a1;
////	array<int, 100> a2;
////
////	int a3[10];
////	// 越界检查的问题
////	// 静态数组，抽查
////	// 越界读不检查，越界写抽查
////	cout << a3[10] << endl;
////	//a3[10] = 10;
////	//a3[11] = 10;
////	a3[12] = 10;
////	a3[20] = 10;
////
////	// array越界读写都可以检查
////	//a1[10];
////	//a1[12] = 10;
////
////	// 堆
////	vector<int> v(100, 1);
////	cout << sizeof(a2) << endl;
////	cout << sizeof(v) << endl;
////
////	return 0;
////}
////
//
////void func()
////{
////	int a = 1;
////	cout << &a << endl;
////}
////
////int main()
////{
////	int a = 0;
////	cout << &a << endl;
////
////	func();
////
////	return 0;
////}
//
//// 函数模板 -- 参数匹配
//template<class T>
////bool LessFunc(T const & left, T const & right)
//bool LessFunc(const T& left, const T& right)
//{
//	return left < right;
//}
//
// //特化
//template<>
//bool LessFunc<const Date*>(const Date* const& left, const Date* const& right)
//{
//	return *left < *right;
//}
////
//template<>
//bool LessFunc<Date*>(Date* const& left, Date* const& right)
//{
//	return *left < *right;
//}
//
//// 推荐
//bool LessFunc(const Date* left, const Date* right)
//{
//	return *left < *right;
//}
//
//bool LessFunc(Date* left, Date* right)
//{
//	return *left < *right;
//}
//
////int main()
////{
////	cout << LessFunc(1, 2) << endl; // 可以比较，结果正确
////
////	Date d1(2022, 7, 7);
////	Date d2(2022, 7, 8);
////	cout << LessFunc(d1, d2) << endl; // 可以比较，结果正确
////
////	Date* p1 = &d1;
////	Date* p2 = &d2;
////	cout << LessFunc(p1, p2) << endl; // 可以比较，结果错误
////
////	const Date* p3 = &d1;
////	const Date* p4 = &d2;
////	cout << LessFunc(p3, p4) << endl; // 可以比较，结果错误
////
////	const int i = 0;
////	int const j = 0;
////	const int& rx = i;
////	int const& ry = i;
////
////	return 0;
////}
//
//template<class T1, class T2>
//class Data
//{
//public:
//	Data() { cout << "Data<T1, T2>" << endl; }
//private:
//	T1 _d1;
//	T2 _d2;
//};
//
//// 全特化
//template<>
//class Data<int, char>
//{
//public:
//	Data() { cout << "Data<int, char>" << endl; }
//};
//
//// 偏特化/半特化
//template<class T1>
//class Data<T1, double>
//{
//public:
//	Data() { cout << "Data<T1, double>" << endl; }
//};
//
//template<class T1>
//class Data<T1, char>
//{
//public:
//	Data() { cout << "Data<T1, char>" << endl; }
//};
//
//// 偏特化，传的类型是指针
//template <typename T1, typename T2>
//class Data <T1*, T2*>
//{
//public:
//	Data()
//	{
//		cout << "Data<T1*, T2*>" << endl;
//	}
//};
//
//template <typename T1, typename T2>
//class Data <T1&, T2&>
//{
//public:
//	Data()
//	{
//		cout << "Data<T1&, T2&>" << endl;
//	}
//};
//
//template <typename T1, typename T2>
//class Data <T1&, T2*>
//{
//public:
//	Data()
//	{
//		cout << "Data<T1&, T2*>" << endl;
//
//		int a = 0;
//		T1& x = a;
//		T2* y = &a;
//		T1 z = a;
//
//		cout << typeid(x).name() << endl;
//		cout << typeid(y).name() << endl;
//	}
//
//	void Push(const T1& x)
//	{}
//};

//int main()
//{
//	Data<int, int> d1;
//	Data<int, char> d2;
//	Data<int, double> d3;
//	Data<char, double> d4;
//	Data<char, char> d5;
//	Data<char*, char*> d6;
//	Data<int*, char*> d7;
//	Data<int&, char&> d8;
//	Data<int&, double&> d9;
//	Data<int&, int*> d10;
//
//	return 0;
//}

int main()
{


	return 0;
}

//template<class T1,class T2>
//class Date
//{
//public:
//	Date() { cout << "Data<T1，T2>" << endl }
//private :
//	T1 _d1;
//	T2 _d2;
//
//};
//
//template<>
//class Date<int, char>
//{
//public:
//	Data() {cout << ""
//};

//bool LessFunc(const Date* left,const Date* right)
//{
//	return *left < *right;
//}
//
//template<class T1,class T2>
//class Date
//{
//public:
//	Date(){cout << }
//};

//template<class T>
//bool LessFunc(const T& left,const T& right)
//{
//	return left < right;
//}
//
//template<>
//bool LessFunc<const Date*>(const Date* left, const Date* const& right)
//{
//	return *left < *right;
//}
//
//template<>
//bool LessFunc<Date*>(const& left,Date* const& right)
//{
//	return *left < *right;
//}


//template<class T,size_t N = 10>
//class array
//{
//public:
//	T& operator[](size_t index){
//		assert(index < n)
//			return _array[index];
//	}
//
//private:
//	T _array[N];
//	size_t _size;
//};
//
//int main()
//{
//	array<int, 10> a1;
//	array<int,100> a2;
//
//	int a3[10];
//	cout << a3[10] << endl;
//	a3[10] = 10;
//	a3[20] = 10;
//
//	vector<int> v(100, 1);
//	cout << sizeof(a2) << ednl;
//	cout << sizeof(v) << ednl;
//
//	return 0;
//
//}

//template<size_t N = 10, bool flag = false>
//class stack
//{
//private:
//	int _a[N];
//	int _top;
//};
//
//int main()
//{
//	stack<> s0;
//	stack<5> s1;
//	stack<10> s2;
//
//	return 0;
//}

//template<double b>
//{
//}


//template<size_t N = 10,bool flag = false>
//class Stack
//{
//private：
//	int _a[N];
//	int _top;
//};

//// a.h
//template<class T>
//T Add(const T& left, const T& right);
//// a.cpp
//template<class T>
//T Add(const T& left, const T& right)
//{
//	return left + right;
//}
//// main.cpp
//#include"a.h"
//int main()
//{
//	Add(1, 2);
//	Add(1.0, 2.0);
//	return 0;
//}


//// 对Less类模板按照指针方式特化
//template<>
//struct Less<Date*>
//{
//	bool operator()(Date* x, Date* y) const
//	{
//		return *x < *y;
//	}
//};

//#include<vector>
//#include<algorithm>
//template<class T>
//struct Less
//{
//	bool operator()(const T& x, const T& y) const
//	{
//		return x < y;
//	}
//};
//int main()
//{
//	Date d1(2022, 7, 7);
//	Date d2(2022, 7, 6);
//	Date d3(2022, 7, 8);
//	vector<Date> v1;
//	v1.push_back(d1);
//	v1.push_back(d2);
//	v1.push_back(d3);
//	// 可以直接排序，结果是日期升序
//	sort(v1.begin(), v1.end(), Less<Date>());
//	vector<Date*> v2;
//	v2.push_back(&d1);
//	v2.push_back(&d2);
//	v2.push_back(&d3);
//	// 可以直接排序，结果错误日期还不是升序，而v2中放的地址是升序
//	// 此处需要在排序过程中，让sort比较v2中存放地址指向的日期对象
//	// 但是走Less模板，sort在排序时实际比较的是v2中指针的地址，因此无法达到预期
//	sort(v2.begin(), v2.end(), Less<Date*>());
//	return 0;
//}

////两个参数偏特化为指针类型
//template <typename T1, typename T2>
//class Data <T1*, T2*>
//{
//public:
//	Data() { cout << "Data<T1*, T2*>" << endl; }
//private:
//	T1 _d1;
//	T2 _d2;
//};
////两个参数偏特化为引用类型
//template <typename T1, typename T2>
//class Data <T1&, T2&>
//{
//public:
//	Data(const T1& d1, const T2& d2)
//		: _d1(d1)
//		, _d2(d2)
//	{
//		cout << "Data<T1&, T2&>" << endl;
//	}
//private:
//	const T1& _d1;
//	const T2& _d2;
//};
//void test2()
//{
//	Data<double, int> d1; // 调用特化的int版本
//	Data<int, double> d2; // 调用基础的模板
//	Data<int*, int*> d3; // 调用特化的指针版本
//	Data<int&, int&> d4(1, 2); // 调用特化的指针版本
//}

//// 将第二个参数特化为int
//template <class T1>
//class Data<T1, int>
//{
//public:
//	Data() { cout << "Data<T1, int>" << endl; }
//private:
//	T1 _d1;
//	int _d2;
//};

//template<class T1, class T2>
//class Data
//{
//public:
//	Data() { cout << "Data<T1, T2>" << endl; }
//private:
//	T1 _d1;
//	T2 _d2;
//};

//template<class T1, class T2>
//class Data
//{
//public:
//	Data() { cout << "Data<T1, T2>" << endl; }
//private:
//	T1 _d1;
//	T2 _d2;
//};
//template<>
//class Data<int, char>
//{
//public:
//	Data() { cout << "Data<int, char>" << endl; }
//private:
//	int _d1;
//	char _d2;
//};
//void TestVector()
//{
//	Data<int, int> d1;
//	Data<int, char> d2;
//}

//// 函数模板 -- 参数匹配
//template<class T>
//bool Less(T left, T right)
//{
//	return left < right;
//}
//// 对Less函数模板进行特化
//template<>
//bool Less<Date*>(Date* left, Date* right)
//{
//	return *left < *right;
//}
//int main()
//{
//	cout << Less(1, 2) << endl;
//	Date d1(2022, 7, 7);
//	Date d2(2022, 7, 8);
//	cout << Less(d1, d2) << endl;
//	Date* p1 = &d1;
//	Date* p2 = &d2;
//	cout << Less(p1, p2) << endl; // 调用特化之后的版本，而不走模板生成了
//	return 0;
//}





//// 函数模板 -- 参数匹配
//template<class T>
//bool Less(T left, T right)
//{
//	return left < right;
//}
//int main()
//{
//	cout << Less(1, 2) << endl; // 可以比较，结果正确
//	Date d1(2022, 7, 7);
//	Date d2(2022, 7, 8);
//	cout << Less(d1, d2) << endl; // 可以比较，结果正确
//	Date* p1 = &d1;
//	Date* p2 = &d2;
//	cout << Less(p1, p2) << endl; // 可以比较，结果错误
//	return 0;
//}


//namespace bite
//{
//	// 定义一个模板类型的静态数组
//	template<class T, size_t N = 10>
//	class array
//	{
//	public:
//		T& operator[](size_t index) { return _array[index]; }
//		const T& operator[](size_t index)const { return _array[index]; }
//		size_t size()const { return _size; }
//		bool empty()const { return 0 == _size; }
//	private:
//		T _array[N];
//		size_t _size;
//	};
//}