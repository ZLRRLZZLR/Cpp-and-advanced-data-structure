#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
#include<math.h>
using namespace std;



#include <iostream>

// 函数模板定义
template <typename T>
void printValue(T value) {
    std::cout << "Value: " << value << std::endl;
}

// 类模板定义
template <typename T>
class MyClass {
public:
    MyClass(T value) : value_(value) {}

    void display() const {
        std::cout << "Class Value: " << value_ << std::endl;
    }

private:
    T value_;
};

// 显式实例化函数模板
template void printValue<int>(int);

// 显式实例化类模板
template class MyClass<double>;

int main() {
    // 隐式实例化函数模板
    printValue(42);              // 隐式地实例化 printValue<int>(int)
    printValue(3.14);            // 隐式地实例化 printValue<double>(double)

    // 隐式实例化类模板
    MyClass<int> obj1(100);      // 隐式地实例化 MyClass<int>
    obj1.display();

    // 使用显式实例化的类模板（注意：这里不需要再次实例化，只是展示如何使用）
    MyClass<double> obj2(200.5); // 理论上，这个实例化是隐式的，但因为我们之前已经显式实例化了MyClass<double>，所以这里只是使用它
    // 然而，需要注意的是，C++标准并不要求编译器因为之前的显式实例化而优化这里的隐式实例化。
    // 这里的隐式实例化是独立的，之前的显式实例化主要是为了解决链接问题或编译时间优化。
    obj2.display();

    // 显式实例化的函数模板调用（实际上，由于C++的ODR规则，显式实例化通常用于声明，而不是在main中调用）
    // 但为了演示，我们假设它在其他地方已经被实例化，并在这里调用
    // 注意：在真实代码中，你应该在头文件中声明显式实例化，在一个源文件中定义它，并在其他源文件中使用它。
    printValue<int>(42); // 调用显式实例化的函数模板（虽然这里看起来像是隐式调用，但假设它在其他地方已经被显式实例化）

    return 0;
}

// 注意：在真实项目中，显式实例化通常放在源文件中，而不是头文件中，
// 并且需要确保每个模板实例只在一个翻译单元中被显式实例化。
// 此外，对于函数模板的显式实例化，你通常会在头文件中声明一个extern模板实例化，
// 并在一个源文件中进行实际的模板实例化。
// 对于类模板，如果涉及到静态成员，你通常也需要在源文件中进行显式实例化。


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

// 定位new/replacement new
//int main()
//{
//	//// p2现在指向的只不过是与A对象相同大小的一段空间，还不能算是一个对象，因为构造函数没
//	////有执行
//	//A* p2 = (A*)operator new(sizeof(A));
//	//new(p2)A(10);// 注意：如果A类的构造函数有参数时，此处需要传参
//
//	//p2->~A();//显式调用析构
//	//operator delete(p2);
//	int a1 = 0;
//	char e1 = 0;
//		int a2 = 0;
//	char c2 = 0;
//
//
//	scanf("%d%c%d%c", &a1, &e1, &a2, &c2);
//
//	int i = 0;
//
//	return 0;
//
//}



//class A
//{
//	~A()
//	{
//		//delete _ptr;
//		cout << "~A()" << endl;
//	}
//
//private:
//	int _a1 = 1;
//	int _a2 = 1;
//};
//
//
//class B
//{
//private:
//	int _b1 = 2;
//	int _b2 = 2;
//};
//
//int main()
//{
//	int* p1 = new int[10]; // -> malloc
//	delete p1;             // -> free
//	free(p1);
//
//	B* p2 = new B[10];
//	delete p2;//B对象数组不会报错
//
//	A* p3 = new A[10];
//	delete[] p3;//A对象数组会报错
//
//	return 0;
//}


//int main()
//{
//	int* p1 = new int;//内置类型，没有指向什么资源
//	free(p1);//使用free，不会调用析构函数
//	//delete p1;
//
//	A* p2 = new A;//A匿名对象中有指针指向一块空间
//	free(p2);//free仅会释放匿名对象的空间，指针管理的空间丢失
//	//delete p2;
//
//	return 0;
//}

//int main()
//{
//	try
//	{
//		// throw try/catch 
//		void* p1 = new char[1024 * 1024 * 1024];
//		cout << p1 << endl;
//
//		void* p2 = new char[1024 * 1024 * 1024];
//		cout << p2 << endl;
//
//		void* p3 = new char[1024 * 1024 * 1024];
//		cout << p3 << endl;
//	}
//	catch (const exception& e)
//	{
//		cout << e.what() << endl;
//	}
//
//	return 0;
//}
//
//
//void func()
//{
//	// throw try/catch 
//	int n = 1;
//	while (1)
//	{
//		void* p1 = new char[1024 * 1024];
//		cout << p1 << "->"<< n<<endl;
//		++n;
//	}
//}
//
//int main()
//{
//	try
//	{
//		func();
//	}
//	catch (const exception& e)
//	{
//		cout << e.what() << endl;
//	}
//
//	return 0;
//}

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
//int main()
//{
//
//	A* p1 = new A(1);
//	A* p2 = new A(2, 2);
//
//	A aa1(1, 1);
//	A aa2(2, 2);
//	A aa3(3, 3);
//
//	return 0;
//}


//class A
//{
//public:
//	A(int a = 0)
//		: _a(a)
//	{
//		cout << "A():" << endl;
//	}
//	~A()
//	{
//		cout << "~A():" << endl;
//	}
//private:
//	int _a;
//};
//int main()
//{
//	// new/delete 和 malloc/free最大区别是 new/delete对于【自定义类型】除了开空间
//	//还会调用构造函数和析构函数
//	A* p1 = (A*)malloc(sizeof(A));
//	A* p2 = new A(1);
//	free(p1);
//	delete p2;
//
//	// 内置类型是几乎是一样的
//	int* p3 = (int*)malloc(sizeof(int)); // C
//	int* p4 = new int;
//	free(p3);
//	delete p4;
//
//	A* p5 = (A*)malloc(sizeof(A) * 10);
//	A* p6 = new A[10];
//	free(p5);
//	delete[] p6;
//	return 0;
//}


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
//int main()
//{
//
//	A* p1 = new A(1);
//	A* p2 = new A(2, 2);
//
//	A aa1(1, 1);
//	A aa2(2, 2);
//	A aa3(3, 3);
//	A* p3 = new A[3]{ aa1, aa2, aa3 };
//
//	A* p4 = new A[3]{ A(1,1), A(2,2), A(3,3) };
//
//	//A aa1 = { 1, 1 };
//	A* p5 = new A[3]{ {1,1}, {2,2}, {3,3} };
//
//	return 0;
//}


//int main()
//{
//	// 动态申请一个int类型的空间
//	int* p1 = new int;
//
//	// 动态申请10个int类型的空间
//	int* p2 = new int[10];
//
//	delete p1;
//	delete[] p2;
//
//	// 动态申请一个int类型的空间并初始化为0
//	int* p3 = new int(0);
//
//	//动态申请10个int类型的空间，10个空间初始化为0
//	int* p4 = new int[10]{ 0 };
//
//	//动态申请10个空间，前5个空间依次初始化为1,2,3,4,5,后5个空间默认初始化为0
//	int* p5 = new int[10]{1,2,3,4,5};
//
//	delete p3;
//	delete[] p4;
//	delete[] p5;
//
//	return 0;
//}

////删除排序数组中的重复项
//class Solution {
//public:
//    int removeDuplicates(vector<int>& nums) {
//        int max = nums[0];
//        int min = nums[0];
//        for (auto i : nums) {
//            if (max < i) {
//                max = i;
//            }
//            else if (min > i) {
//                min = i;
//            }
//        }
//        vector<int> v(max - min + 1, 0);
//        for (int i = 0; i < nums.size();) {
//            v[nums[i] - min]++;
//            if (v[nums[i] - min] > 1) {
//                v[nums[i] - min]--;
//                auto pos = nums.begin() + i;
//                nums.erase(pos);
//            }
//            else {
//                i++;
//            }
//        }
//        return nums.size();
//    }
//};
//
//int main() {
//    vector<int> vv = { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };
//    Solution().removeDuplicates(vv);
//
//    return 0;
//}

//只出现一次的数ii
//class Solution {
//public:
//    int singleNumber(vector<int>& nums) {
//        int ans = 0;
//        for (int i = 0; i < 32; i++) {
//            int total = 0;
//            for (int tmp : nums) {
//                total += (tmp >> i) & 1;
//            }
//
//
//            if (total % 3 != 0) {
//                ans |= (1 << i);
//            }
//
//
//        }
//        return ans;
//    }
//};

////只出现一次的数
//class Solution {
//public:
//    vector<int> singleNumber(vector<int>& nums) {
//        unsigned s = 0;
//        for (auto i : nums) {
//            s ^= i;
//        }
//
//        int lowbit = s & (~s);
//
//        int a = 0;
//        int b = 0;
//
//        for (auto i : nums) {
//            if (i & lowbit != lowbit) {
//                a ^= i;
//            }
//            else {
//                b ^= i;
//            }
//        }
//
//        return vector<int>{a, b};
//    }
//};
//
//int main() {
//    vector<int> nums = { 1, 2, 1, 3, 2, 5 };
//    
//    Solution().singleNumber(nums);
//
//    return 0;
//}

//class Solution {
//public:
//
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
//    string multiply(string num1, string num2) {
//
//        string sum;
//        for (int i = num2.size(); i >= 0; i--) {
//            string s = to_string((num2[i] - '0') * stoi(num1) * pow(10, num2.size() - i));
//            sum = addStrings(s, sum);
//        }
//        return sum;
//    }
//};

//class Solution {
//public:
//    void Mulitem(string& tmp, string& num1, char ch) {
//        int sign = 0;
//        for (int i = num1.size() - 1; i >= 0; i--) {
//            int ret = (num1[i] - '0') * (ch - '0') + sign;
//            sign = ret / 10;
//            if (sign) {
//                ret %= 10;
//            }
//
//            tmp.push_back(ret + '0');
//        }
//        if (sign) {
//            tmp.push_back(sign + '0');
//        }
//
//        reverse(tmp.begin(), tmp.end());
//    }
//
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
//
//        reverse(tmp.begin(), tmp.end());
//
//
//        return tmp;
//    }
//
//    string multiply(string num1, string num2) {
//        string tmp;
//        string result;
//
//        if (strcmp(num1.c_str(),"0") == 0 || strcmp(num2.c_str(),"0") == 0) {
//            result += "0";
//        }
//        else {
//            for (int i = num2.size() - 1; i >= 0; i--) {
//                Mulitem(tmp, num1, num2[i]);
//                for (int j = 0; j < num2.size() - i - 1; j++) {
//                    tmp.push_back('0');
//                }
//                result = addStrings(result, tmp);
//
//                tmp.clear();
//            }
//        }
//        return result;
//    }
//};
//
//int main() {
//
//    char p1[] = "2";
//    char p2[] = "3";
//
//    Solution().multiply(p1,p2);
//    //vector<vector<int>> vv(5);
//
//    return 0;
//}

//namespace bit {
//	class string
//
//	{
//
//	public:
//
//		string(const char* str = "")
//		{
//			int len = strlen(str);
//			if (len) {
//				_str = new char[len];
//				strcpy(_str, str);
//			}
//			else {
//				_str = new char[len + 1];
//				_str[0] = '\0';
//			}
//
//		}
//
//		string(const string& s) {
//			string tmp(s);
//			std::swap(_str, tmp._str);
//		}
//
//		string& operator=(const string& s) {
//			string tmp(s);
//			std::swap(_str, tmp._str);
//		}
//
//		~string() {
//			delete[] _str;
//			_str = nullptr;
//		}
//
//	private:
//
//		char* _str;
//
//	};
//}
//
//
//
//int main() {
//	string s1("abc");
//	string s2(s1);
//	string s3("acd");
//	//s3 = s2;
//
//	return 0;
//}
//void test_vector() {
//	vector<int> v1;
//	vector<int> v2(10, 1);
//
//	vector<int> v3(++v2.begin(), --v2.end());
//
//	for (size_t i = 0; i < v3.size(); i++) {
//		cout << v3[i] << "";
//	}
//	cout << endl;
//
//	vector<>
//}


//////void test_vector1() {
////	vector<int> v1;
////	vector<int> v2(10,1);
////
////	vector<int> v3(++v2.begin(), --v2.end());
////
////	for (size_t i = 0; i < v3.size(); i++) {
////		cout << v3[i] << " ";
////	}
////	cout << endl;
////
////	vector<int>::iterator it = v3.begin();
////	while (it != v3.end() ) {
////		cout << *it << " ";
////		++it;
////	}
////	cout << endl;
////
////	for (auto e : v3) {
////		cout << e << " ";
////	}
////	cout << endl;
////
////}
////
////void TestVectorExpand() {
////	size_t sz;
////	vector<int> v;
////	v.reserve(100);
////
////	sz = v.capacity();
////	cout << "capacity changed:" << sz << '\n';
////
////	cout << "making v grow:\n";
////	for (int i = 0; i < 100; ++i) {
////		v.push_back(i);
////		if (sz != v.capacity()) {
////			sz = v.capacity();
////			cout << "capacity changed:" << sz << '\n';
////		}
////	}
////}
////
////void test_vector2() {
////	vector<int> v(10, 1);
////	v.reserve(20);
////	cout << v.capacity() << endl;
////
////	v.reserve(15);
////	cout << v.size() << endl;
////	cout << v.capacity() << endl;
////
////	v.reserve(5);
////	cout << v.size() << endl;
////	cout << v.capacity() << endl;
////
////}
////
////void test_vector3() {
////	vector<int> v(10, 1);
////	v.reserve(20);
////	cout << v.size() << endl;
////	cout << v.capacity() << endl;
////
////}
////
////void test_vector4() {
////	vector<int> v(10, 1);
////	v.push_back(2);
////	v.insert(v.begin(), 0);
////
////	for (auto e : v) {
////		cout << e << "";
////	}
////	cout << endl;
////
////	v.insert(v.begin() + 3, 10);
////
////	for (auto e : v) {
////		cout << e << "";
////	}
////
////	cout << endl;
////
////	vector<int> v1(5, 0);
////	for (size_t i = 0; i < 5; i++) {
////		cin >> v1[i];
////	}
////
////	for (auto e : v1) {
////		cout << endl;
////	}
////
////	vector<char> v2;
////	string s2;
////
////	vector<int> v2;
////}
////
////void test_vector5() {
////	vector<string> v1;
////	string s1("xxxx");
////	v1.push_back(s1);
////
////	v1.push_back("yyyyy");
////	for (const auto& e : v1)
////	{
////		cout << e << " ";
////	}
////	cout << endl;
////
////	vector<int> v(5, 1);
////	vector<vector<int>> vv(10, v);
////	vv[2][1] = 2;
////
////	for (size_t i = 0; i < vv.size(); ++i) {
////		for (size_t j = 0; j < vv[i].size(); ++j) {
////			cout << vv[i][j] << " ";
////
////		}
////		cout << endl;
////	}
////	cout << endl;
////}
//
//
//
//
////vector<int>
////class vector {
////	int& operator[](int i) {
////		assert(i < _size);
////
////		return _a[i];
////	}
////};
//
////
////template<class T>
////class vector {
////	T& operator[](int i) {
////		assert(i < _size);
////
////		return _a[i];
////	}
////private:
////	T* _a;
////	size_t _size;
////	size_t _capacity;
////};
//
//
//
////class string {
////	private：
////		char _buff[16];
////	char* _str;
////
////	size_t _size;
////	size_t _capacity;
////};
//
////void test_string() {
////	string s1;
////	string s2("hello world");
////	cout << s1 << s2 << endl;
////
////	s2[0] = 'x';
////	cout << s1 << s2 << endl;
////
////	for (int i = 0; i < s2.size(); i++) {
////		cout << s2[i] << " ";
////	}
////
////	cout << endl;
////
////
////}
//
//
//
//
////class string {
////private:
////	char _buff[16];
////	char* _str;
////
////	size_t _size;
////	size_t _capaccity;
////
////};
//
////void test_string1() {
////	string s1;
////	string s2("hello world");
////
////	cout << s1 << s2 << endl;
////	s2[0] = 'x';
////	cout << s1 << s2 << endl;
////
////	for (size_t i = 0; i < s2.size(); i++) {
////		cout << s2[i] << "";
////	}
////	cout << endl;
////
////	string::iterator it = s2.begin();
////	auto it = s2.begin();
////	while(it != s2.end()) {
////		*it += 2;
////		cout << *it << " ";
////		++it;
////	}
////	cout << endl;
////	cout << s2 << endl;
////
////	map<string>
////}
//
////using namespace std;
////
////
////int main() {
////
////	char arr[] = "hello world";
////	cout << arr;
////
////	return 0;
////}
//
////翻转字符串III：翻转字符串中的单词
////class Solution {
////public:
////    string reverseWords(string s) {
////        string tmp;
////        int prev = 0;
////        int cur = s.find(' ', prev);
////        if (cur < 0) {
////            reverse(s.begin(), s.end());
////        }
////        while (cur >= 0) {
////            reverse(s.begin() + prev, s.begin() + cur);
////            prev = cur + 1;
////            cur = s.find(' ', prev);
////        }
////        reverse(s.begin() + prev, s.end());
////        return s;
////    }
////};
////
////
////int main() {
////    Solution().reverseWords("Let's take LeetCode contest");
////	return 0;
////}
//
////字符串转整形数字
////class Solution {
////public:
////    int myAtoi(string str) {
////        int flge = 1;
////        int i = 0;
////        int broder = INT_MAX / 10;
////        int sum = 0;
////        while (str[i] == ' ') {
////            i++;
////        }
////
////        if (str[i] == '+') {
////            i++;
////        }
////        else if (str[i] == '-') {
////            flge = -1;
////            i++;
////        }
////
////        while (str[i] != '\0') {
////
////            if (str[i] < '0' || str[i] > '9')
////                break;
////
////            if ((sum > broder) || (sum == broder && str[i] > '7')) {
////                if (flge > 0)
////                    return INT_MAX;
////                else
////                    return INT_MIN;
////            }
////
////            sum = sum * 10 + (str[i++] - '0');
////        }
////        return sum * flge;
////
////    }
////};
////
////int main() {
////    Solution().myAtoi("2147483646");
////
////    return 0;
////}