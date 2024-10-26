#pragma once
#include<iostream>
#include<assert.h>
#include<string.h>

using namespace std;


namespace bit

{

    class string

    {

        friend ostream& operator<<(ostream& _cout, const bit::string& s);

        friend istream& operator>>(istream& _cin, bit::string& s);

    public:

        typedef char* iterator;

    public:

        string(const char* str = "") {
            _size = _capacity = strlen(str);
            _str = new char[_capacity + 1];
            strcpy(_str,str);
        }

        //�ɰ�
        //string(const string& s) {
        //    _size = s._size;
        //    _capacity = s._capacity;
        //    _str = new char[_capacity + 1];
        //    strcpy(_str, s._str);
        //}

        //string& operator=(const string& s) {
        //    _size = s._size;
        //    _capacity = s._capacity;
        //    delete[] _str;
        //    _str = new char[_capacity + 1];
        //    strcpy(_str, s._str);
        //}

        string(const string& s) {
            string tmp(s);
            swap(tmp);
        }

        string& operator=(string s) {

        }

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



            /////////////////////////////////////////////////////////////

            // modify

        void push_back(char c);

        string& operator+=(char c);

        void append(const char* str);

        string& operator+=(const char* str);

        void clear();

        void swap(string& s) {
            std::swap(_str,s._str);
            std::swap(_capacity, s._capacity);
            std::swap(_size, s._capacity);
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
            return 
        }

        void resize(size_t n, char c = '\0');

        void reserve(size_t n);

        /////////////////////////////////////////////////////////////

        // access

        char& operator[](size_t index);

        const char& operator[](size_t index)const;


        /////////////////////////////////////////////////////////////

        //relational operators

        bool operator<(const string& s) {
            return strcmp(_str,s._str) < 0;
        }

        bool operator<=(const string& s) {
            return strcmp(_str, s._str) <= 0;
        }

        bool operator>(const string& s) {
            return strcmp(_str, s._str) > 0;
        }

        bool operator>=(const string& s) {
            return strcmp(_str, s._str) >= 0;
        }

        bool operator==(const string& s) {
            return strcmp(_str, s._str) == 0;
        }

        bool operator!=(const string& s) {
            return strcmp(_str, s._str) != 0;
        }

        // ����c��string�е�һ�γ��ֵ�λ��

        size_t find(char c, size_t pos = 0) const;

        // �����Ӵ�s��string�е�һ�γ��ֵ�λ��

        size_t find(const char* s, size_t pos = 0) const;

        // ��posλ���ϲ����ַ�c/�ַ���str�������ظ��ַ���λ��

        string& insert(size_t pos, char c);

        string& insert(size_t pos, const char* str);


        // ɾ��posλ���ϵ�Ԫ�أ������ظ�Ԫ�ص���һ��λ��

        string& erase(size_t pos, size_t len);

    private:

        char* _str = nullptr;

        size_t _capacity = 0;

        size_t _size = 0;

        static const size_t npos = -1;

    };

}
