#include<iostream>
//#include<string>
#include<vector>
using namespace std;

#include"3.h";

void test_vector1() {
	vector<int> v1;
	vector<int> v2(10,1);

	vector<int> v3(++v2.begin(), --v2.end());

	for (size_t i = 0; i < v3.size(); i++) {
		cout << v3[i] << " ";
	}
	cout << endl;

	vector<int>::iterator it = v3.begin();
	while (it != v3.end() ) {
		cout << *it << " ";
		++it;
	}
	cout << endl;

	for (auto e : v3) {
		cout << e << " ";
	}
	cout << endl;

}

void TestVectorExpand() {
	size_t sz;
	vector<int> v;
	v.reserve(100);

	sz = v.capacity();
	cout << "capacity changed:" << sz << '\n';

	cout << "making v grow:\n";
	for (int i = 0; i < 100; ++i) {
		v.push_back(i);
		if (sz != v.capacity()) {
			sz = v.capacity();
			cout << "capacity changed:" << sz << '\n';
		}
	}
}

void test_vector2() {
	vector<int> v(10, 1);
	v.reserve(20);
	cout << v.capacity() << endl;

	v.reserve(15);
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	v.reserve(5);
	cout << v.size() << endl;
	cout << v.capacity() << endl;

}

void test_vector3() {
	vector<int> v(10, 1);
	v.reserve(20);
	cout << v.size() << endl;
	cout << v.capacity() << endl;

}

void test_vector4() {
	vector<int> v(10, 1);
	v.push_back(2);
	v.insert(v.begin(), 0);

	for (auto e : v) {
		cout << e << "";
	}
	cout << endl;

	v.insert(v.begin() + 3, 10);

	for (auto e : v) {
		cout << e << "";
	}

	cout << endl;

	vector<int> v1(5, 0);
	for (size_t i = 0; i < 5; i++) {
		cin >> v1[i];
	}

	for (auto e : v1) {
		cout << endl;
	}

	vector<char> v2;
	string s2;

	vector<int> v2;
}

void test_vector5() {
	vector<string> v1;
	string s1("xxxx");
	v1.push_back(s1);

	v1.push_back("yyyyy");
	for (const auto& e : v1)
	{
		cout << e << " ";
	}
	cout << endl;

	vector<int> v(5, 1);
	vector<vector<int>> vv(10, v);
	vv[2][1] = 2;

	for (size_t i = 0; i < vv.size(); ++i) {
		for (size_t j = 0; j < vv[i].size(); ++j) {
			cout << vv[i][j] << " ";

		}
		cout << endl;
	}
	cout << endl;
}




//vector<int>
//class vector {
//	int& operator[](int i) {
//		assert(i < _size);
//
//		return _a[i];
//	}
//};

//
//template<class T>
//class vector {
//	T& operator[](int i) {
//		assert(i < _size);
//
//		return _a[i];
//	}
//private:
//	T* _a;
//	size_t _size;
//	size_t _capacity;
//};



//class string {
//	private：
//		char _buff[16];
//	char* _str;
//
//	size_t _size;
//	size_t _capacity;
//};

//void test_string() {
//	string s1;
//	string s2("hello world");
//	cout << s1 << s2 << endl;
//
//	s2[0] = 'x';
//	cout << s1 << s2 << endl;
//
//	for (int i = 0; i < s2.size(); i++) {
//		cout << s2[i] << " ";
//	}
//
//	cout << endl;
//
//
//}




//class string {
//private:
//	char _buff[16];
//	char* _str;
//
//	size_t _size;
//	size_t _capaccity;
//
//};

//void test_string1() {
//	string s1;
//	string s2("hello world");
//
//	cout << s1 << s2 << endl;
//	s2[0] = 'x';
//	cout << s1 << s2 << endl;
//
//	for (size_t i = 0; i < s2.size(); i++) {
//		cout << s2[i] << "";
//	}
//	cout << endl;
//
//	string::iterator it = s2.begin();
//	auto it = s2.begin();
//	while(it != s2.end()) {
//		*it += 2;
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//	cout << s2 << endl;
//
//	map<string>
//}

//using namespace std;
//
//
//int main() {
//
//	char arr[] = "hello world";
//	cout << arr;
//
//	return 0;
//}

//翻转字符串III：翻转字符串中的单词
//class Solution {
//public:
//    string reverseWords(string s) {
//        string tmp;
//        int prev = 0;
//        int cur = s.find(' ', prev);
//        if (cur < 0) {
//            reverse(s.begin(), s.end());
//        }
//        while (cur >= 0) {
//            reverse(s.begin() + prev, s.begin() + cur);
//            prev = cur + 1;
//            cur = s.find(' ', prev);
//        }
//        reverse(s.begin() + prev, s.end());
//        return s;
//    }
//};
//
//
//int main() {
//    Solution().reverseWords("Let's take LeetCode contest");
//	return 0;
//}

//字符串转整形数字
//class Solution {
//public:
//    int myAtoi(string str) {
//        int flge = 1;
//        int i = 0;
//        int broder = INT_MAX / 10;
//        int sum = 0;
//        while (str[i] == ' ') {
//            i++;
//        }
//
//        if (str[i] == '+') {
//            i++;
//        }
//        else if (str[i] == '-') {
//            flge = -1;
//            i++;
//        }
//
//        while (str[i] != '\0') {
//
//            if (str[i] < '0' || str[i] > '9')
//                break;
//
//            if ((sum > broder) || (sum == broder && str[i] > '7')) {
//                if (flge > 0)
//                    return INT_MAX;
//                else
//                    return INT_MIN;
//            }
//
//            sum = sum * 10 + (str[i++] - '0');
//        }
//        return sum * flge;
//
//    }
//};
//
//int main() {
//    Solution().myAtoi("2147483646");
//
//    return 0;
//}