#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

// ��������ǵ�ǰn��Ϊ��������nΪ5
void test2vector(size_t n)
{
	// ʹ��vector�����ά����vv��vv�е�ÿ��Ԫ�ض���vector<int>
	bit::vector<bit::vector<int>> vv(n);
	// ����ά����ÿһ���е�vecotr<int>�е�Ԫ��ȫ������Ϊ1
	for (size_t i = 0; i < n; ++i)
		vv[i].resize(i + 1, 1);
	// ��������ǳ���һ�кͶԽ��ߵ�����Ԫ�ظ�ֵ
	for (int i = 2; i < n; ++i)
	{
		for (int j = 1; j < i; ++j)
		{
			vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1];
		}
	}
}



//int main()
//{
//	bite::vector<bite::string> v;
//	v.push_back("1111");
//	v.push_back("2222");
//	v.push_back("3333");
//	return 0;
//}


//class Solution {
//public:
//	int singleNumber(vector<int>& nums) {
//		int value = 0;
//		for (auto e : nums)
//		{
//			value ^= e;
//		}
//		return value;
//	}
//};


//#include <string>
//void TestString()
//{
//	string s("hello");
//	auto it = s.begin();
//	// �ſ�֮�������������Ϊresize��20��string���������
//	// ����֮��itָ��֮ǰ�ɿռ��Ѿ����ͷ��ˣ��õ�������ʧЧ��
//	// �����ӡʱ���ٷ���itָ��Ŀռ����ͻ����
//	//s.resize(20, '!');
//	while (it != s.end())
//	{
//		cout << *it;
//		++it;
//	}
//	cout << endl;
//	it = s.begin();
//	while (it != s.end())
//	{
//		it = s.erase(it);
//		// �������淽ʽд������ʱ������������Ϊerase(it)֮��
//		// itλ�õĵ�������ʧЧ��
//		// s.erase(it);
//		++it;
//	}
//}



//// 1. ����֮�󣬵������Ѿ�ʧЧ�ˣ�������Ȼ�������У��������н���Ѿ�������
//int main()
//{
//	vector<int> v{ 1,2,3,4,5 };
//	for (size_t i = 0; i < v.size(); ++i)
//		cout << v[i] << " ";
//	cout << endl;
//	auto it = v.begin();
//	cout << "����֮ǰ��vector������Ϊ: " << v.capacity() << endl;
//	// ͨ��reserve���ײ�ռ�����Ϊ100��Ŀ����Ϊ����vector�ĵ�����ʧЧ
//	v.reserve(100);
//	cout << "����֮��vector������Ϊ: " << v.capacity() << endl;
//	// ��������reserve֮��it�������϶���ʧЧ����vs�³����ֱ�ӱ����ˣ�����linux
//	�²���
//		// ��Ȼ�������У���������Ľ���ǲ��Ե�
//		while (it != v.end())
//		{
//			cout << *it << " ";
//			++it;
//		}
//	cout << endl;
//	return 0;
//}
//���������
//1 2 3 4 5
//����֮ǰ��vector������Ϊ: 5
//����֮��vector������Ϊ : 100
//0 2 3 4 5 409 1 2 3 4 5
//// 2. eraseɾ������λ�ô����linux�µ�������û��ʧЧ
//// ��Ϊ�ռ仹��ԭ���Ŀռ䣬����Ԫ����ǰ�����ˣ�it��λ�û�����Ч��
//#include <vector>
//#include <algorithm>
//int main()
//{
//	vector<int> v{ 1,2,3,4,5 };
//	vector<int>::iterator it = find(v.begin(), v.end(), 3);
//	v.erase(it);
//	cout << *it << endl;
//	while (it != v.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//	return 0;
//}
//��������������У�����ӡ��
//4
//4 5
//// 3: eraseɾ���ĵ�������������һ��Ԫ�أ�ɾ��֮��it�Ѿ�����end
//// ��ʱ����������Ч�ģ�++it���³������
//int main()
//{
//	vector<int> v{ 1,2,3,4,5 };
//	// vector<int> v{1,2,3,4,5,6};
//	auto it = v.begin();
//	while (it != v.end())
//	{
//		if (*it % 2 == 0)
//			v.erase(it);
//		++it;
//	}
//	for (auto e : v)
//		cout << e << " ";
//	cout << endl;
//	return 0;
//}
//========================================================
//// ʹ�õ�һ������ʱ�������������
//[sly@VM - 0 - 3 - centos 20220114]$ g++ testVector.cpp - std = c++11
//[sly@VM - 0 - 3 - centos 20220114]$ . / a.out
//1 3 5
//======================================================== =
//// ʹ�õڶ�������ʱ���������ջ����
//[sly@VM - 0 - 3 - centos 20220114]$ vim testVector.cpp
//[sly@VM - 0 - 3 - centos 20220114]$ g++ testVector.cpp - std = c++11
//[sly@VM - 0 - 3 - centos 20220114]$ . / a.out
//Segmentation fault




//#include <iostream>
//using namespace std;
//#include <vector>
//int main()
//{
//	vector<int> v{ 1, 2, 3, 4 };
//	auto it = v.begin();
//	while (it != v.end())
//	{
//		if (*it % 2 == 0)
//			v.erase(it);
//		++it;
//	}
//	return 0;
//}
//int main()
//{
//	vector<int> v{ 1, 2, 3, 4 };
//	auto it = v.begin();
//	while (it != v.end())
//	{
//		if (*it % 2 == 0)
//			it = v.erase(it);
//		else
//			++it;
//	}
//	return 0;
//}

//#include <iostream>
//using namespace std;
//#include <vector>
//int main()
//{
//	vector<int> v{ 1,2,3,4,5,6 };
//	auto it = v.begin();
//	// ����ЧԪ�ظ������ӵ�100���������λ��ʹ��8��䣬�����ڼ�ײ������
//	// v.resize(100, 8);
//	// reserve�����þ��Ǹı����ݴ�С�����ı���ЧԪ�ظ����������ڼ���ܻ�����ײ���
//	���ı�
//		// v.reserve(100);
//		// ����Ԫ���ڼ䣬���ܻ��������ݣ�������ԭ�ռ䱻�ͷ�
//		// v.insert(v.begin(), 0);
//		// v.push_back(8);
//		// ��vector���¸�ֵ�����ܻ�����ײ������ı�
//		v.assign(100, 8);
//	/*
//	����ԭ�����ϲ��������п��ܻᵼ��vector���ݣ�Ҳ����˵vector�ײ�ԭ��ɿռ䱻��
//	�ŵ������ڴ�ӡʱ��it��ʹ�õ����ͷ�֮��ľɿռ䣬�ڶ�it����������ʱ��ʵ�ʲ�������һ��
//	�Ѿ����ͷŵĿռ䣬�������������ʱ������
//	�����ʽ�������ϲ������֮�������Ҫ����ͨ������������vector�е�Ԫ�أ�ֻ���
//	it���¸�ֵ���ɡ�
//	*/
//	while (it != v.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//	return 0;
//}
//2. ָ��λ��Ԫ�ص�ɾ������--erase
//#include <iostream>
//using namespace std;
//#include <vector>
//int main()
//{
//	int a[] = { 1, 2, 3, 4 };
//	vector<int> v(a, a + sizeof(a) / sizeof(int));
//	// ʹ��find����3����λ�õ�iterator
//	vector<int>::iterator pos = find(v.begin(), v.end(), 3);
//	// ɾ��posλ�õ����ݣ�����pos������ʧЧ��
//	v.erase(pos);
//	cout << *pos << endl; // �˴��ᵼ�·Ƿ�����
//	return 0;
//}


//// ����vector��Ĭ�����ݻ���
//void TestVectorExpand()
//{
//	size_t sz;
//	vector<int> v;
//	sz = v.capacity();
//	cout << "making v grow:\n";
//	for (int i = 0; i < 100; ++i)
//	{
//		v.push_back(i);
//		if (sz != v.capacity())
//		{
//			sz = v.capacity();
//			cout << "capacity changed: " << sz << '\n';
//		}
//	}
//}
//vs�����н����vs��ʹ�õ�STL�����ǰ���1.5����ʽ����
//making foo grow :
//capacity changed : 1
//capacity changed : 2
//capacity changed : 3
//capacity changed : 4
//capacity changed : 6
//capacity changed : 9
//capacity changed : 13
//capacity changed : 19
//capacity changed : 28
//capacity changed : 42
//capacity changed : 63
//capacity changed : 94
//capacity changed : 141
//g++���н����linux��ʹ�õ�STL�����ǰ���2����ʽ����
//making foo grow :
//capacity changed : 1
//capacity changed : 2
//capacity changed : 4
//capacity changed : 8
//capacity changed : 16
//capacity changed : 32
//capacity changed : 64
//capacity changed : 128
//// ����Ѿ�ȷ��vector��Ҫ�洢Ԫ�ش�Ÿ�����������ǰ���ռ������㹻
//// �Ϳ��Ա���߲�������ݵ���Ч�ʵ��µ�������
//void TestVectorExpandOP()
//{
//	vector<int> v;
//	size_t sz = v.capacity();
//	v.reserve(100); // ��ǰ���������úã����Ա���һ�����һ������
//	cout << "making bar grow:\n";
//	for (int i = 0; i < 100; ++i)
//	{
//		v.push_back(i);
//		if (sz != v.capacity())
//		{
//			sz = v.capacity();
//			cout << "capacity changed: " << sz << '\n';
//		}
//	}
//}




//void test_string5()
//{
//	string s("hello world");
//
//	s.insert(0, "hello bit ");
//	cout << s << endl;
//
//	s.insert(10, "zzzz");
//	cout << s << endl;
//
//	s.insert(0, "p");
//	cout << s << endl;
//
//	char ch = 't';
//	s.insert(0, 1, ch);
//	s.insert(s.begin(), ch);
//
//	cout << s << endl;
//}
//
//void test_string6()
//{
//	string s("hello world");
//	s.erase(6, 1);
//	cout << s << endl;
//
//	// ͷɾ
//	s.erase(0, 1);
//	cout << s << endl;
//
//	s.erase(s.begin());
//	cout << s << endl;
//
//	// βɾ
//	s.erase(--s.end());
//	cout << s << endl;
//
//	s.erase(s.size() - 1, 1);
//	cout << s << endl;
//
//	string ss("hello world");
//	ss.erase(6);
//	cout << ss << endl;
//
//	string sss("hello                 world hello bit");
//	/*size_t pos = sss.find(' ');
//	while (pos != string::npos)
//	{
//		sss.replace(pos, 1, "%%");
//		cout << sss << endl;
//
//		pos = sss.find(' ', pos+2);
//	}
//	cout << sss << endl;*/
//
//	//sss.replace(5, 1, "%%");
//	//cout << sss << endl;
//
//	string tmp;
//	tmp.reserve(sss.size());
//	for (auto ch : sss)
//	{
//		if (ch == ' ')
//			tmp += "%%";
//		else
//			tmp += ch;
//	}
//	cout << tmp << endl;
//	//sss = tmp;
//	sss.swap(tmp);
//	cout << sss << endl;
//
//	string file;
//	cin >> file;
//	FILE* fout = fopen(file.c_str(), "r");
//	char ch = fgetc(fout);
//	while (ch != EOF)
//	{
//		cout << ch;
//		ch = fgetc(fout);
//	}
//	fclose(fout);
//}
//
//void SplitFilename(const std::string& str)
//{
//	std::cout << "Splitting: " << str << '\n';
//	std::size_t found = str.find_last_of("/\\");
//
//	std::cout << " path: " << str.substr(0, found) << '\n';
//	std::cout << " file: " << str.substr(found + 1) << '\n';
//}
//// 16��10
//void test_string7()
//{
//	string s("test.cpp.zip");
//	size_t pos = s.rfind('.');
//	string suffix = s.substr(pos);
//	cout << suffix << endl;
//
//	std::string str("Please, replace the vowels in this sentence by asterisks.");
//	std::cout << str << '\n';
//
//	std::size_t found = str.find_first_not_of("abcdef");
//	while (found != std::string::npos)
//	{
//		str[found] = '*';
//		found = str.find_first_not_of("abcdef", found + 1);
//	}
//
//	std::cout << str << '\n';
//
//	std::string str1("/usr/bin/man");
//
//	SplitFilename(str1);
//
//}



//void test_string3()
//{
//	string s2("hello world");
//	cout << s2.length() << endl;
//	cout << s2.size() << endl;
//
//	cout << s2.max_size() << endl;
//
//	cout << s2.capacity() << endl;
//
//
//	string s3("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
//	//cout << sizeof(s2) << endl;
//	//cout << sizeof(s3) << endl;
//}

//class string
//{
//private:
//	char _buff[16];
//	char*  _str;
//
//	size_t _size;
//	size_t _capacity;
//};


//void test_string2()
//{
//	string s2("hello world");
//	string::iterator it = s2.begin();
//	while (it != s2.end())
//	{
//		*it += 2;
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//
//	string s3("hello world");
//	string::reverse_iterator rit = s3.rbegin();
//	while (rit != s3.rend())
//	{
//		cout << *rit << " ";
//		++rit;
//	}
//	cout << endl;
//
//	const string s4("hello world");
//	//string::const_iterator cit = s3.begin();
//	auto cit = s4.begin();
//	while (cit != s4.end())
//	{
//		//*cit += 2;
//		cout << *cit << " ";
//		++cit;
//	}
//	cout << endl;
//
//	const string s5("hello world");
//	//string::const_reverse_iterator rcit = s3.rbegin();
//	auto rcit = s5.rbegin();
//	while (rcit != s5.rend())
//	{
//		// *rcit += 2;
//		cout << *rcit << " ";
//		++rcit;
//	}
//	cout << endl;
//}
//int main() {
//	test_string2();
//	return 0;
//}

//#include<iostream>
//using namespace std;
//int func1()
//{
//	return 10;
//}
//
//// ����������
//void func2(auto a)
//{}
//
//// ����������ֵ�����ǽ������ʹ��
//auto func3()
//{
//	return 3;
//}
//
//
//
//int main()
//{
//	int a = 10;
//	auto b = a;//b��a��ֵ�õ��ģ�b������int
//	auto c = 'a';//c������char
//	auto d = func1();
//
//	// ���뱨��:rror C3531: ��e��: ���Ͱ�����auto���ķ��ű�����г�ʼֵ�趨��
//	auto e;
//
//	cout << typeid(b).name() << endl;//�鿴����������
//	cout << typeid(c).name() << endl;
//	cout << typeid(d).name() << endl;
//
//	int x = 10;
//	auto y = &x;//�����Ƶ�ָ������
//	auto* z = &x;
//	auto& m = x;
//
//	cout << typeid(x).name() << endl;//�鿴����������
//	cout << typeid(y).name() << endl;
//	cout << typeid(z).name() << endl;
//
//	auto aa = 1, bb = 2;
//	// ���뱨��error C3538: ���������б��У���auto������ʼ���Ƶ�Ϊͬһ����
//	auto cc = 3, dd = 4.0;
//	// ���뱨��error C3318: ��auto []��: ���鲻�ܾ������а�����auto����Ԫ������
//	auto array[] = { 4, 5, 6 };
//
//	return 0;
//}
//
//#include<iostream>
//#include <string>
//#include <map>
//using namespace std;
//int main()
//{
//	std::map<std::string, std::string> dict = { { "apple", "ƻ��" },{ "orange",
//	"����" }, {"pear","��"} };
//	// auto������֮��
//	//std::map<std::string, std::string>::iterator it = dict.begin();
//	auto it = dict.begin();
//	while (it != dict.end())
//	{
//		cout << it->first << ":" << it->second << endl;
//		++it;
//	}
//	return 0;
//}



//void Teststring3()
//{
//	// 2��������
//	//string::iterator it = s2.begin();
//	auto it = s2.begin();
//	while (it != s2.end())
//	{
//		*it += 2;
//
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//
//	cout << s2 << endl;
//
//	map<string, string> dict;
//	//map<string, string>::iterator mit = dict.begin();
//	auto mit = dict.begin();
//
//	/*list<int> lt = { 1,2,3,4,5,6,7 };
//	list<int>::iterator lit = lt.begin();
//	while (lit != lt.end())
//	{
//		cout << *lit << " ";
//		++lit;
//	}
//	cout << endl;*/
//}

//int main()
//{
//	string s1;// ����յ�string�����s1
//	string s2("hello world");// ��C��ʽ�ַ�������string�����s2
//	string s3(s2);// ��������s3
//
//	cout << s1 << endl;
//	cout << s2 << endl;
//	cout << s3 << endl;
//
//	string s4(s2, 6, 15);//��s2��6���ַ���ʼ����5���ַ����й���
//	cout << s4 << endl;
//
//	string s5(s2, 6);//�ӵ�6���ַ�һֱ���������
//	cout << s5 << endl;
//
//	string s6("hello world", 5);//���ַ�����5���ַ���ʼ����
//	cout << s6 << endl;
//
//	string s7(10, 'X');//��10��X����
//	cout << s7 << endl;
//
//	return 0;
//}
//namespace zlr
//{
//	template<class T, class Container = vector<T>>
//	class stack
//	{
//	public:
//		void push(const T& x)
//		{
//			_con.push_back(x);
//		}
//
//		void pop()
//		{
//			_con.pop_back();
//		}
//
//		const T& top() const
//		{
//			X++;
//			return _con.func();//û�б���
//		}
//
//		size_t size() const
//		{
//			return _con.size();
//		}
//
//		bool empty() const
//		{
//			return _con.empty();
//		}
//
//	private:
//		Container _con;
//	};
//
//}
//
//int main()
//{
//	bit::stack<int, vector<int>> st;
//	bit::stack<int, list<int>> st;
//	zlr::stack<int, vector<int>> st;
//
//	 ��ģ��ʵ����ʱ������ʵ������ʹ����Щ��Ա������ʵ������Щ������ȫʵ����
//	st.push(1);//push�����ʵ����
//	st.push(2);
//	st.push(3);
//	st.push(4);
//
//	cout << st.top() << endl;//�����ˣ����top�ڲ�ϸ�ڣ����򱨴�
//	st.pop();
//
//	return 0;
//}

//template<typename T>
//class Stack
//{
//public:
//	Stack(int n = 4)
//		:_array(new T[n])
//		,_size(0)
//		,_capacity(n)
//	{}
//
//	~Stack()
//	{
//		delete[] _array;
//		_array = nullptr;
//		_size = _capacity = 0;
//	}
//
//	void Push(const T& x);
//
//private:
//	T* _array;
//	size_t _capacity;
//	size_t _size;
//};

//template<class X>//���Ʋ���Ҫ���滻ΪXҲ��
//void Stack<X>::Push(const X& x)
//{
//	if (_size == _capacity)
//	{
//		X* tmp = new X[_capacity * 2];
//		memcpy(tmp, _array, sizeof(X) * _size);
//		delete[] _array;
//
//		_array = tmp;
//		_capacity *= 2;
//	}
//
//	_array[_size++] = x;
//}



//int main()
//{
//	// ��ģ�嶼����ʾʵ����
//	Stack<int> st1; // int
//	st1.Push(1);
//	st1.Push(2);
//	st1.Push(3);
//
//	Stack<double> st2; // double
//	st2.Push(1.1);
//	st2.Push(1.1);
//	st2.Push(1.1);
//
//	Stack<double>* pst = new Stack<double>;
//	//...
//	delete pst;
//
//	return 0;
//}



// �ú���ģ�����ɶ�Ӧ�ĺ��� -> ģ���ʵ����
//template<class t>
//t Add(const t& left, const t& right)
//{
//	return left + right;
//}
//
//template<class T>
//T* func1(int n)
//{
//	return new T[n];
//}
//
//int main()
//{
//	int a1 = 10, a2 = 20;
//	double d1 = 10.1, d2 = 20.2;
//
//	 �Ƶ�ʵ����
//	cout << Add(a1, (int)d1) << endl;
//	cout << Add((double)a1, d1) << endl;
//
//	 ��ʾʵ����
//	cout << Add<int>(a1, d1) << endl;
//	cout << Add<double>(a1, d1) << endl;
//
//	double* p1 = func1<double>(10);
//
//	return 0;
//}


// //�ú���ģ�����ɶ�Ӧ�ĺ��� -> ģ���ʵ����
//template<class T>
//T Add(const T& left, const T& right)
//{
//	return left + right;
//}
//
//
//
//
//int main()
//{
//	int a1 = 10, a2 = 20;
//	double d1 = 10.1, d2 = 20.2;
//	Add(a1, a2);
//	Add(d1, d2);
//
//
//
//	return 0;
//}
//
//
//
//template<class T>
//T Add(const T& left, const T& right)
//{
//	return left + right;
//}
//int main()
//{
//	int a1 = 10, a2 = 20;
//	double d1 = 10.0, d2 = 20.0;
//	Add(a1, a2);
//	Add(d1, d2);
//	/*
//	����䲻��ͨ�����룬��Ϊ�ڱ����ڼ䣬��������������ʵ����ʱ����Ҫ������ʵ������
//	ͨ��ʵ��a1��T����Ϊint��ͨ��ʵ��d1��T����Ϊdouble���ͣ���ģ������б���ֻ��
//	һ��T��
//	�������޷�ȷ���˴����׸ý�Tȷ��Ϊint ���� double���Ͷ�����
//	ע�⣺���ڰ�ȫ���ɶ��Եȿ�������ģ���У�������һ�㲻���������ת��������
//*/
//// ��ʱ�����ִ���ʽ��1. �û��Լ���ǿ��ת�� 2. ʹ����ʽʵ����(���Ľ���)
//	Add(a1, (int)d2);
//	return 0;
//}
//
//template<class T1, class T2>
//T1 Add(const T1& left, const T2& right)
//{
//	return left + right;
//}
//
//int main()
//{
//	int a1 = 10, a2 = 20;
//	double d1 = 10.1, d2 = 20.2;
//	Add(a1, a2);//�������ģ������֮��,�����ȿ�����ͬһ���͵�Ҳ�����ǲ�ͬ���͵�
//	Add(d1, d2);
//
//	return 0;
//}
//
//
//
//
//template<class T>
//T* func1(int n)
//{
//	return new T[n];
//}
//
//// �Ƶ�ʵ����
//cout << Add(a1, (int)d1) << endl;
//cout << Add((double)a1, d1) << endl;
//
//// ��ʾʵ����
//cout << Add<int>(a1, d1) << endl;
//cout << Add<double>(a1, d1) << endl;
//
//cout << Add(a1, d1) << endl;
//
//double* p1 = func1<double>(10);

////ģ������
//template<class T>
//void Swap(T& x, T& y)
//{
//	T tmp = x;
//	x = y;
//	y = tmp;
//}
//
//template<typename T>
//void Swap(T& x, T& y)
//{
//	T tmp = x;
//	x = y;
//	y = tmp;
//}
//
//template<class T1, typename T2>
//void func(const T1& x, const T2& y)
//{
//	//������������
//}
//
//template<class A, class B>
//void func(const A& x, const B& y)
//{
//	//������������
//}

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