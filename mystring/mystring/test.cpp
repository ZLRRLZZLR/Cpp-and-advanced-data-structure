#include"mystring.h"

//        ostream& operator<<(ostream& _cout, const bit::string& s);
//
//        istream& operator>>(istream& _cin, bit::string& s);

//        //�ɰ�
//        //string(const string& s)

//        //string& operator=(const string& s)

//        string(const string& s)
// 
//        string& operator=(string s)

//        ~string()

//        iterator begin()
//
//        iterator end()
//
//        void push_back(char c);
//
//        string& operator+=(char c)

//        void append(const char* str);
// 
//        string& operator+=(const char* str);
//
//        void clear()

//        void swap(string& s)


//        size_t size()const

//        size_t capacity()const
//
//        bool empty()const

//        void resize(size_t n, char c = '\0');
//        void reserve(size_t n);

//        char& operator[](size_t index) 

//        const char& operator[](size_t index)const

//        bool operator<(const string& s) 

//        bool operator<=(const string& s) 

//        bool operator>(const string& s)

//        bool operator>=(const string& s) 

//        bool operator==(const string& s)

//        bool operator!=(const string& s)

//        size_t find(char c, size_t pos = 0) const;
//
//        size_t find(const char* s, size_t pos = 0) const

//        string& insert(size_t pos, char c);
//
//        string& insert(size_t pos, const char* str);

//        string& erase(size_t pos, size_t len);

namespace bit {
    void Test_mystring01() {
        ////// ʹ��Ĭ�Ϲ��캯��
        //string s1;
        //// ���Ĭ�Ϲ��캯���Ƿ���ȷ��ʼ�����ַ���
        //// ʹ�ô������Ĺ��캯��
        //string s2("Hello");
        //// ��鹹�캯���Ƿ���ȷ�����ַ������ݡ���С������
        //// 
        //// ����c_str����
        //const char* cstr = s2.c_str();
        //for (size_t i = 0; i < s2.size(); ++i) {
        //    if (s2[i] = cstr[i]) {
        //        int a = 0;
        //    }
        //}

        string s3("abc");

        string s4;
        string s5(s3);


        // ���Ը�ֵ����
        s4 = s3;
        assert(s4.size() == s3.size());
        for (size_t i = 0; i < s3.size(); ++i) {
            if (s4[i] == s3[i]) {
                int a = 0;
            }
        }

        // ����+= (char)����
        s4 += 'd';
        //const char* str = s4.c_str();
        if (s4.size() == s3.size() + 1) {
            int a = 0;
        }
        if (s4[s4.size() - 1] == 'd') {
            int a = 0;
        }

        // ����+= (const char*)����
        s4 += "efg";
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
    //void Tset_mystring02() {
//
//
//}void Tset_mystring03() {
//
//
//}void Tset_mystring03() {
//
//
//}void Tset_mystring04() {
//
//
//}void Tset_mystring05() {
//

}

int main() {
    bit::Test_mystring01();

    return 0;
}




