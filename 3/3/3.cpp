#include<iostream>
#include<string>


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