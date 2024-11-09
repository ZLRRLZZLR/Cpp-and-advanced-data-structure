#pragma once
#include<>

//#define _CRT_SECURE_NO_WARNINGS 1
//#pragma once
//
//#include<iostream>
//#include<string>
//#include<assert.h>
//using namespace std;
//
//namespace bit {
//	class string {
//	public:
//		typedef char* iterator;
//		typedef const char* const_iterator;
//
//		iterator begin() {
//			return _str;
//		}
//
//		iterator end() {
//			return _str + _size;
//		}
//
//		const_iterator beign() const {
//			return _str;
//		}
//
//		const_iterator end() cosnt {
//			return _str + _size;
//		}
//
//		string(const char* str = "") {
//			_size = strlen(str);
//
//			_capacity = _size;
//			_str = new char[_capacity + 1];
//			strcpy(_str, str);
//		}
//
//		void swap(string& s) {
//			std::swap(_str, s._str);
//			std::swap(_size, s._size);
//			std::swap(_str, s._capacity);
//		}
//
//		string(const string& s) {
//			string tmp(s._str);
//			swap(tmp);
//		}
//
//		string& operator=(const string& s) {
//			if (this != &s) {
//				delete[] _str;
//
//				_str = new char[s.capacity + 1];
//				strcpy(_str, s._str);
//				_size = s.size;
//				_capacity = s._capacity;
//			}
//
//			return *this;
//		}
//
//		string& operator=(string tmp) {
//			swap(tmp);
//
//			return *this;
//		}
//
//		~string() {
//			if (_str) {
//				delete[] _str;
//				_str = nullptr;
//				_size = _capcity = 0;
//
//			}
//		}
//
//		const char* c_str() const {
//			return _str;
//		}
//
//		void clear() {
//			_str[0] = '\0';
//			_size = 0;
//		}
//
//		size_t size() const {
//			return _size;
//		}
//
//		size_t capacity() const {
//			return _capacity;
//		}
//
//		char& operator[](size_t pos) {
//			assert(pos < _size);
//
//			return _str[pos];
//		}
//
//		const char& operator[])(size_t pos) const{
//			assert(pos < _size);
//
//			return _str[pos];
//		}
//
//
//
//	};
//}