#include"mystring.h"


namespace bit {

    void string::reserve(size_t n) {
        if (n > _capacity) {
            size_t new_capacity = n > 2 * _capacity ? n + 1 : 2 * _capacity + 1;
            char* str = new char[new_capacity];
            _capacity = new_capacity;
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
        for (int i = _size; i < n - _size; i++) {
            _str[i] = c;
        }

        _size = n;

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

        return *this;
    }

    string& string::erase(size_t pos, size_t len) {
        assert(pos < _size);

        _str[pos] = '\0';
        _size = pos;

        return *this;
    }


    ostream& operator<<(ostream& _cout, const bit::string& s) {
        _cout << s.c_str();
        return  _cout;
    }

    istream& operator>>(istream& _cin, bit::string& s) {

        char ch = getchar();
        while (ch != '\0') {
            s += ch;
            ch = getchar();
        }
        return _cin;
    }

}
