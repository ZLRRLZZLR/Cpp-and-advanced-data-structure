#include"mystring.h"
//
//        istream& operator>>(istream& _cin, bit::string& s);
// 
//        void push_back(char c);
//
//        void append(const char* str);
// 

//        void resize(size_t n, char c = '\0');
// 
//        void reserve(size_t n);

//        char& operator[](size_t index) 

//        const char& operator[](size_t index)const


//        size_t find(char c, size_t pos = 0) const;
//
// 
//        size_t find(const char* s, size_t pos = 0) const


//        string& insert(size_t pos, char c);
//
// 
//        string& insert(size_t pos, const char* str);


//        string& erase(size_t pos, size_t len);

namespace bit {
    void Test_mystring01() {
        ////// ʹ��Ĭ�Ϲ��캯��
        string s1("abc");
        // ���Ĭ�Ϲ��캯���Ƿ���ȷ��ʼ�����ַ���
        // ʹ�ô������Ĺ��캯��
        string s2("Hello");

        s2[1] = 'g';

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

        //// ��鹹�캯���Ƿ���ȷ�����ַ������ݡ���С������
        //// 
        //// ����c_str����
        //const char* cstr = s2.c_str();
        //for (size_t i = 0; i < s2.size(); ++i) {
        //    if (s2[i] = cstr[i]) {
        //        int a = 0;
        //    }
        //}

        //string s3("abc");

        //string s4;
        //string s5(s3);


        //// ���Ը�ֵ����
        //s4 = s3;
        //assert(s4.size() == s3.size());
        //for (size_t i = 0; i < s3.size(); ++i) {
        //    if (s4[i] == s3[i]) {
        //        int a = 0;
        //    }
        //}

        //// ����+= (char)����
        //s4 += 'd';
        ////const char* str = s4.c_str();
        //if (s4.size() == s3.size() + 1) {
        //    int a = 0;
        //}
        //if (s4[s4.size() - 1] == 'd') {
        //    int a = 0;
        //}

        // ����+= (const char*)����
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




