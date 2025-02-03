#include"mystring.h"


namespace bit {
    bool operator<(const string& s1, const string& s2) {
        return strcmp(s1._str, s2._str) < 0;
    }

    bool operator>(const string& s1, const string& s2) {
        return strcmp(s1._str, s2._str) > 0;
    }

    bool operator<=(const string& s1, const string& s2) {
        return !(s1 > s2);
    }

    bool operator>=(const string& s1, const string& s2) {
        return !(s1 < s2);
    }

    bool operator==(const string& s1, const string& s2) {
        return !(s1 < s2) && !(s1 > s2);
    }

    bool operator!=(const string& s1, const string& s2) {
        return !(s1 == s2);
    }


    void string::reserve(size_t n) {
        if (n >= _capacity) {
            size_t new_capacity = n > 2 * _capacity ? n + 1 : 2 * _capacity + 1;
            char* str = new char[new_capacity];
            _capacity = new_capacity - 1;
            strcpy(str, _str);
            std::swap(_str, str);
            delete[] str;
        }
    }

    void string::resize(size_t n, char c) {
        reserve(n);

        if (n <= _size) {
            _str[n] = '\0';
            _size = n;
        }

        int i = _size;
        for (; i < n; i++) {
            _str[i] = c;
        }

        _size = n;
        _str[_size] = '\0';
    }

    size_t string::find(char c, size_t pos) const {
        assert(pos < _size);

        for (int i = pos; i < _size; i++) {
            if (_str[i] == c) {
                return i;
            }
        }

        return npos;
    }


    void string::push_back(char c) {
        reserve(_size + 1);
        _str[_size++] = c;
        _str[_size] = '\0';

    }

    string& string::operator+=(const char* str) {
        int lenth = strlen(str);
        reserve(_size + lenth);
        strcpy(_str + _size, str);
        _size += lenth;

        return *this;
    }

    void string::append(const char* str) {
        size_t ch = strlen(str);
        reserve(ch + _capacity);
        strcpy(_str + _size, str);
        _size += ch;

    }

    string& string::insert(size_t pos, char c) {
        assert(pos < _size);

        reserve(_size + 1);
        size_t end = _size;
        while (end > pos) {
            _str[end] = _str[end - 1];
            end--;
        }

        _str[pos] = c;
        _size++;
        _str[_size] = '\0';

        return *this;
    }

    string& string::insert(size_t pos, const char* str) {
        assert(pos < _size);

        size_t len = strlen(str);
        reserve(len + _capacity);

        size_t end = _size + len;
        while (end >= pos + len) {
            _str[end] = _str[end - len];
            end--;
        }

        memcpy(_str + pos, str, len);
        _size += len;

        _str[_size] = '\0';


        return *this;
    }

    string& string::erase(size_t pos, size_t len) {
        assert(pos < _size);

        if(len != npos) {
            while(pos + len < _size){
                _str[pos] = _str[pos + len];
                pos++;
            }

        }

        _size = pos;
        _str[pos] = '\0';

        return *this;
    }


    ostream& operator<<(ostream& _cout, const bit::string& s) {
        _cout << s.c_str();
        return  _cout;
    }

    istream& operator>>(istream& _cin, bit::string& s) {
        s.clear();

        char ch = _cin.get();

        while (ch != '\n') {
            s += ch;

            ch = _cin.get();
        }

        const char* str = s.c_str();
          cout << str;

        return _cin;
    }

}



#pragma once
#include<iostream>
#include<assert.h>
#include<string.h>

#define _CRT_SECURE_NO_WARNINGS 1

using namespace std;

namespace bit

{

    class string

    {

        friend ostream& operator<<(ostream& _cout, const bit::string& s);

        friend istream& operator>>(istream& _cin, bit::string& s);

    public:

        typedef char* iterator;
        typedef const char* const_iterator;

    public:

        string(const char* str = "") {
            _size = _capacity = strlen(str);
            _str = new char[_capacity + 1];
            strcpy(_str, str);
        }

        //旧版
        string(const string& s) {
            _size = s._size;
            _capacity = s._capacity;
            _str = new char[_capacity + 1];
            strcpy(_str, s._str);
        }

        string& operator=(const string& s) {
            _size = s._size;
            _capacity = s._capacity;
            delete[] _str;
            _str = new char[_capacity + 1];
            strcpy(_str, s._str);
            return *this;
        }

        //string(const string& s){
        //    string tmp(s);
        //    swap(tmp);
        //}

        //string& operator=(string s) {
        //    swap(s._str);
        //    return *this;
        //}

        ~string() {
            delete[] _str;
            _size = _capacity = 0;
            _str = nullptr;
        }



        //////////////////////////////////////////////////////////////

        // iterator

        iterator begin() {
            return _str;
        }

        iterator end() {
            return _str + _size;
        }

        const_iterator begin() const{
            return _str;
        }

        const_iterator end() const{
            return _str + _size;
        }



        /////////////////////////////////////////////////////////////

        // modify

        void push_back(char c);


        string& operator+=(char c) {
            push_back(c);
            return *this;
        }


        void append(const char* str);


        string& operator+=(const char* str);

        void clear() {
            _str[0] = '\0';
            _size = 0;
        }

        void swap(string& s) {
            std::swap(_str, s._str);
            std::swap(_capacity, s._capacity);
            std::swap(_size, s._size);
        }

        const char* c_str()const {
            return _str;
        }

        /////////////////////////////////////////////////////////////

        // capacity

        size_t size()const {
            return _size;
        }

        size_t capacity()const {
            return _capacity;
        }

        bool empty()const {
            return _size == 0;
        }

        void resize(size_t n, char c = '\0');


        void reserve(size_t n);

        /////////////////////////////////////////////////////////////

        // access

        char& operator[](size_t index) {
            assert(index < _size);

            return _str[index];
        }

        const char& operator[](size_t index)const {
            assert(index < _size);

            return _str[index];
        }


        /////////////////////////////////////////////////////////////

        //relational operators


        // 返回c在string中第一次出现的位置

        size_t find(char c, size_t pos = 0) const;

        // 返回子串s在string中第一次出现的位置

        size_t find(const char* s, size_t pos = 0) const {
            return strstr(_str + pos, s) - _str;
        }

        // 在pos位置上插入字符c/字符串str，并返回该字符的位置

        string& insert(size_t pos, char c);

        string& insert(size_t pos, const char* str);


        // 删除pos位置上的元素，并返回该元素的下一个位置

        string& erase(size_t pos, size_t len = npos);

        //private:

        char* _str = nullptr;

        size_t _capacity = 0;

        size_t _size = 0;

        static const size_t npos = -1;

    };

    bool operator<(const string& s1, const string& s2);

    bool operator>(const string& s1, const string& s2);


    bool operator<=(const string& s1, const string& s2);


    bool operator>=(const string& s1, const string& s2);


    bool operator==(const string& s1, const string& s2);

    bool operator!=(const string& s1, const string& s2);

}



#include"mystring.h"
//
//        istream& operator>>(istream& _cin, bit::string& s);

namespace bit {
    void Test_mystring01() {
        ////// 使用默认构造函数
        string s1("abc");
        //// 检查默认构造函数是否正确初始化空字符串
        //// 使用带参数的构造函数
        //string s2("Helloabc");
        //string s3;

        cin >> s1;
        ////s2.erase(3,3);
        ////s2.erase(3);
        ////s2.erase(0);

        //s3.resize(10, 'b');

        //s2.insert(7, s1.c_str());

        //s2.insert(0, s1.c_str());


        //s2.insert(7, 'b');

        //s2.insert(5,'b');
        //s2.insert(0, 'b');

        //char ret3 = s2[5];

         //int ret1 = s2.find(s1.c_str());
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

        //string s3("abc");

        //string s4;
        //string s5(s3);


        //// 测试赋值操作
        //s4 = s3;
        //assert(s4.size() == s3.size());
        //for (size_t i = 0; i < s3.size(); ++i) {
        //    if (s4[i] == s3[i]) {
        //        int a = 0;
        //    }
        //}

        //// 测试+= (char)操作
        //s4 += 'd';
        ////const char* str = s4.c_str();
        //if (s4.size() == s3.size() + 1) {
        //    int a = 0;
        //}
        //if (s4[s4.size() - 1] == 'd') {
        //    int a = 0;
        //}

        // 测试+= (const char*)操作
        //s4 += "efg";
        //const char* str = s4.c_str();
        //if (s4.size() == s3.size() + 1 + 3){
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





