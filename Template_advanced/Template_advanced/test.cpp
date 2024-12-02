
class Solution
{
public:
	int numDecodings(string s)
	{
		// �Ż�
		int n = s.size();
		vector<int> dp(n + 1);
		dp[0] = 1; // ��֤�����������ȷ��
		dp[1] = s[0] != '0';
		// ���
		for (int i = 2; i <= n; i++)
		{
			// ����������
			if (s[i - 1] != '0') dp[i] += dp[i - 1];
			// �����ǰ���һ����������������
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
//			// �ƶ�ָ��
//			if (height[left] < height[right]) left++;
//			else right--;
//		}
//		return ret;
//	}
//};


////#define N 10
//
////template<size_t N>//���Բ���ȱʡֵ
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
////	// ջ
////	array<int, 10> a1;
////	array<int, 100> a2;
////
////	int a3[10];
////	// Խ���������
////	// ��̬���飬���
////	// Խ�������飬Խ��д���
////	cout << a3[10] << endl;
////	//a3[10] = 10;
////	//a3[11] = 10;
////	a3[12] = 10;
////	a3[20] = 10;
////
////	// arrayԽ���д�����Լ��
////	//a1[10];
////	//a1[12] = 10;
////
////	// ��
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
//// ����ģ�� -- ����ƥ��
//template<class T>
////bool LessFunc(T const & left, T const & right)
//bool LessFunc(const T& left, const T& right)
//{
//	return left < right;
//}
//
// //�ػ�
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
//// �Ƽ�
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
////	cout << LessFunc(1, 2) << endl; // ���ԱȽϣ������ȷ
////
////	Date d1(2022, 7, 7);
////	Date d2(2022, 7, 8);
////	cout << LessFunc(d1, d2) << endl; // ���ԱȽϣ������ȷ
////
////	Date* p1 = &d1;
////	Date* p2 = &d2;
////	cout << LessFunc(p1, p2) << endl; // ���ԱȽϣ��������
////
////	const Date* p3 = &d1;
////	const Date* p4 = &d2;
////	cout << LessFunc(p3, p4) << endl; // ���ԱȽϣ��������
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
//// ȫ�ػ�
//template<>
//class Data<int, char>
//{
//public:
//	Data() { cout << "Data<int, char>" << endl; }
//};
//
//// ƫ�ػ�/���ػ�
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
//// ƫ�ػ�������������ָ��
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
//	Date() { cout << "Data<T1��T2>" << endl }
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
//private��
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


//// ��Less��ģ�尴��ָ�뷽ʽ�ػ�
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
//	// ����ֱ�����򣬽������������
//	sort(v1.begin(), v1.end(), Less<Date>());
//	vector<Date*> v2;
//	v2.push_back(&d1);
//	v2.push_back(&d2);
//	v2.push_back(&d3);
//	// ����ֱ�����򣬽���������ڻ��������򣬶�v2�зŵĵ�ַ������
//	// �˴���Ҫ����������У���sort�Ƚ�v2�д�ŵ�ַָ������ڶ���
//	// ������Lessģ�壬sort������ʱʵ�ʱȽϵ���v2��ָ��ĵ�ַ������޷��ﵽԤ��
//	sort(v2.begin(), v2.end(), Less<Date*>());
//	return 0;
//}

////��������ƫ�ػ�Ϊָ������
//template <typename T1, typename T2>
//class Data <T1*, T2*>
//{
//public:
//	Data() { cout << "Data<T1*, T2*>" << endl; }
//private:
//	T1 _d1;
//	T2 _d2;
//};
////��������ƫ�ػ�Ϊ��������
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
//	Data<double, int> d1; // �����ػ���int�汾
//	Data<int, double> d2; // ���û�����ģ��
//	Data<int*, int*> d3; // �����ػ���ָ��汾
//	Data<int&, int&> d4(1, 2); // �����ػ���ָ��汾
//}

//// ���ڶ��������ػ�Ϊint
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

//// ����ģ�� -- ����ƥ��
//template<class T>
//bool Less(T left, T right)
//{
//	return left < right;
//}
//// ��Less����ģ������ػ�
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
//	cout << Less(p1, p2) << endl; // �����ػ�֮��İ汾��������ģ��������
//	return 0;
//}





//// ����ģ�� -- ����ƥ��
//template<class T>
//bool Less(T left, T right)
//{
//	return left < right;
//}
//int main()
//{
//	cout << Less(1, 2) << endl; // ���ԱȽϣ������ȷ
//	Date d1(2022, 7, 7);
//	Date d2(2022, 7, 8);
//	cout << Less(d1, d2) << endl; // ���ԱȽϣ������ȷ
//	Date* p1 = &d1;
//	Date* p2 = &d2;
//	cout << Less(p1, p2) << endl; // ���ԱȽϣ��������
//	return 0;
//}


//namespace bite
//{
//	// ����һ��ģ�����͵ľ�̬����
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