#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
#include<math.h>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int s = 0;
        for (auto i : nums) {
            s ^= i;
        }

        int lowbit = s & (~s);

        int a = 0;
        int b = 0;

        for (auto i : nums) {
            if (i & lowbit != lowbit) {
                a ^= i;
            }
            else {
                b ^= i;
            }
        }

        return vector<int>{a, b};
    }
};

int main() {
    vector<int> nums = { 1, 2, 1, 3, 2, 5 };
    
    Solution().singleNumber(nums);

    return 0;
}

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