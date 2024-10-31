#include"mystring.h"
//
//        istream& operator>>(istream& _cin, bit::string& s);

namespace bit {
    void Test_mystring01() {
        //// 使用默认构造函数
        string s1("abc");
        // 检查默认构造函数是否正确初始化空字符串
        // 使用带参数的构造函数
        string s2("Helloabc");
        string s3;

        //cin >> s1;
        //s2.erase(3,3);
        //s2.erase(3);
        //s2.erase(0);

        //s3.resize(10, 'b');

        //s2.insert(7, s1.c_str());

        //s2.insert(0, s1.c_str());


        //s2.insert(7, 'b');

        //s2.insert(5,'b');
        //s2.insert(0, 'b');

        //char ret3 = s2[5];

        // int ret1 = s2.find(s1.c_str());
        //int ret2 = s2.find(' ');

        //s2[1] = 'g';
        //s2.push_back(' ');
        //s2.append(s1.c_str());
        //cout << s2.capacity() << " ";
        //cout << s2.empty() << " ";
        //cout << s2.size() << " ";

        //s2.clear();
        //cout << s1;
        //cout << s2;
        //for (auto ch : s1) {
        //    cout << ch << " ";
        //}

        //cout << (s1 < s2) << " ";
        //cout << (s1 > s2) << " ";
        //cout << (s1 == s2) << " ";
        //cout << (s1 <= s2) << " ";
        //cout << (s1 >= s2) << " ";
        //cout << (s1 != s2) << " ";

        //// 检查构造函数是否正确设置字符串内容、大小和容量
        //// 
        //// 测试c_str函数
        //const char* cstr = s2.c_str();
        //for (size_t i = 0; i < s2.size(); ++i) {
        //    if (s2[i] = cstr[i]) {
        //        int a = 0;
        //    }
        //}

        //string s7("abc");

        //string s4;
        //string s5(s7);


        //// 测试赋值操作
        //s4 = s7;
        //assert(s4.size() == s7.size());
        //for (size_t i = 0; i < s7.size(); ++i) {
        //    if (s4[i] == s7[i]) {
        //        int a = 0;
        //    }
        //}

        //// 测试+= (char)操作
        //s4 += 'd';
        ////const char* str = s4.c_str();
        //if (s4.size() == s7.size() + 1) {
        //    int a = 0;
        //}
        //if (s4[s4.size() - 1] == 'd') {
        //    int a = 0;
        //}

        //// 测试+= (const char*)操作
        //s4 += "efg";
        //const char* str = s4.c_str();
        //if (s4.size() == s7.size() + 1 + 3){
        //    int a = 0;
        //}
        //if (s4[s4.size() - 3] == 'e'){
        //    int a = 0;
        //}
        //if (s4[s4.size() - 2] == 'f') {
        //    int a = 0;
        //}
        //if (s4[s4.size() - 1] == 'g') {
        //    int a = 0;
        //}



    }
}

int main() {
    bit::Test_mystring01();

    return 0;
}