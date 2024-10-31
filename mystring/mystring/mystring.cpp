#include"mystring.h"


namespace bit {
    static const size_t npos = -1;

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
        append(str);
        return *this;
    }

    void string::append(const char* str) {
        size_t ch = strlen(str);
        reserve(ch + _capacity);
        strcpy(_str + _size, str);
        _size += ch;

    }

    string& string::insert(size_t pos, char c) {
        assert(pos <= _size);

        reserve(_size + 1);
        size_t end = _size + 1;
        while (end > pos) {
            _str[end] = _str[end - 1];
            end--;
        }

        _str[pos] = c;
        _size++;

        return *this;
    }

    string& string::insert(size_t pos, const char* str) {
        assert(pos <= _size);

        size_t len = strlen(str);
        reserve(len + _capacity);

        size_t end = _size + len;
        while (end > pos + len - 1) {
            _str[end] = _str[end - len];
            end--;
        }

        for (size_t i = 0; i < len; i++)
        {
            _str[pos + i] = str[i];
        }

        _size += len;

        return *this;
    }

    string& string::erase(size_t pos, size_t len) {
        assert(pos < _size);

        if (len != npos) {
            while (pos + len < _size) {
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

        const int N = 256;
        char buff[N];


        char ch = _cin.get();

        int i = 0;
        for (; ch != '\n';) {
            buff[i++] = ch;
            if (i == N - 1) {
                buff[i] = '\0';
                s += buff;
                i = 0;
            }

            ch = _cin.get();
        }
        if (i > 0) {
            buff[i] = '\0';

            s += buff;
        }

        //while (ch != '\n') {
        //    s += ch;

        //    ch = _cin.get();
        //}

        //const char* str = s.c_str();
        //cout << str;

        return _cin;
    }

}