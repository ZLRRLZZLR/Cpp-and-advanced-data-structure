#include<iostream>
#include<vector>
#include<list>
#include<deque>
using namespace std;


//class Base1 { public: int _b1; };
//class Base2 { public: int _b2; };
//class Derive : public Base1, public Base2 { public: int _d; };
//int main()
//{
//	Derive d;
//	Base1* p1 = &d;
//	Base2* p2 = &d;
//	Derive* p3 = &d;
//	return 0;
//}


//class Person
//{
//public:
//	Person(const char* name = "xxx")
//		: _name(name)
//	{
//		cout << "Person()" << endl;
//	}
//
//	Person(const Person& p)
//		: _name(p._name)
//	{
//		cout << "Person(const Person& p)" << endl;
//	}
//
//	Person& operator=(const Person& p)
//	{
//		cout << "Person operator=(const Person& p)" << endl;
//		if (this != &p)
//			_name = p._name;
//		return *this;
//	}
//
//	~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//protected:
//	string _name; // ����
//};
//
//class Student : public Person
//{
//public:
//	Student(const char* name, int num, const char* addrss)
//		:Person(name)
//		, _num(num)
//		, _addrss(addrss)
//	{}
//
//	// �ϸ�˵Student��������Ĭ�����ɵľ͹�����
//	// �������Ҫ�������Դ������Ҫ�Լ�ʵ��
//	Student(const Student& s)
//		:Person(s)
//		, _num(s._num)
//		, _addrss(s._addrss)
//	{
//		// ���
//	}
//
//	// �ϸ�˵Student��ֵ����Ĭ�����ɵľ͹�����
//	// �������Ҫ�������Դ������Ҫ�Լ�ʵ��
//	Student& operator=(const Student& s)
//	{
//		if (this != &s)
//		{
//			// ����������operator=�������ع�ϵ
//			Person::operator=(s);
//
//			_num = s._num;
//			_addrss = s._addrss;
//		}
//
//		return *this;
//	}
//
//	// �ϸ�˵Student����Ĭ�����ɵľ͹�����
//	// �������Ҫ��ʾ�ͷŵ���Դ������Ҫ�Լ�ʵ��
//	// �����������ᱻ���⴦���destructor() 
//	~Student()
//	{
//		// ����������͸�����������Ҳ�������ع�ϵ
//		// �涨������Ҫ��ʾ���ã�������������֮�󣬻��Զ����ø�������
//		// ������֤����˳�����Ӻ󸸣���ʾ����ȡ����ʵ�ֵ��ˣ����ܱ�֤
//		// ���Ӻ�
//		//Person::~Person();
//		//delete _ptr;
//	}
//protected:
//	int _num = 1; //ѧ��
//	string _addrss = "�����и�����";
//
//	int* _ptr = new int[10];
//};
//
//int main()
//{
//	Student s1("����", 1, "������");
//	Student s2(s1);
//
//	Student s3("����", 2, "������");
//	s1 = s3;
//
//	/*Person* ptr = new Person;
//	delete ptr;*/
//
//	return 0;
//}



//class Person
//{
//public:
//	string _name; // ����
//	string _sex; // �Ա�
//	int _age; // ����
//};
//
//class Student : public Person
//{
//public:
//	int _No; // ѧ��
//};
//
//int main()
//{
//	Student sobj;
//	// �����������Ը�ֵ������Ķ�����ͨ�����ú���ὲ��Ļ���Ŀ���������ɵ�
//	Person pobj = sobj;
//	// 1.���������Ը�ֵ���������/ָ��/����,����������ת��
//	Person* pp = &sobj;
//	Person& rp = sobj;
//	rp._name = "����";
//
//	//int i = 1;
//	//double d = i;
//	//const double& rd = i;//����ת���������ʱ����
//
//	//2.��������ܸ�ֵ����������������뱨��
//	//sobj = (Student)pobj;
//
//	// ������˽�һ��
//	Student* ps1 = dynamic_cast<Student*>(pp);//
//	cout << ps1 << endl;
//
//	pp = &pobj;
//	Student* ps2 = dynamic_cast<Student*>(pp);
//	cout << ps2 << endl;
//
//	return 0;
//}


//class Base1 { public: int _b1 = 1; };
//class Base1 { public: int _b1 = 2; };
//class Derive : public Base2,pubic Base1
//{
//public: 
//	int _d = 3;
//	int _e = 4;
//
//};
//
//int main()
//{
//	Derive d;
//	Base1* p1 = &d;
//	Base1* p2 = &d;
//	Base1* p3 = &d;
//
//	int i = 0;
//	cout << i << endl;
//	return 0;
//}




//class Student : virtual public Person
//{
//public:
//	Student(const char* name,int num = 0)
//		:person(name)
//		,_num(num)
//	{}
//protected:
//	int _num;
//};
//class Teacher : virtual public Person
//{
//
//};
//
//class Assitant : public Student,public Teacher
//{
//public:
//	Assistant(const char* name1,const char* name2,const char* name3)
//		:Student(name1)
//		,Tercher(name2)
//		,Person(name3)
//	{}
//protected:
//	string _mahjorCourse;
//};
//
//int main()
//{
//	Assintant a;
//	a._name = "perter";
//
//	a.student::_name = "С��";
//	a.Teacher::_name = "����";
//
//	cout << sizeof(a) << endl;
//
//	Assistant a("����"��"����"��"����");
//
//	return 0;
//}



//class Person
//{
//public:
//	Person(const char* name)
//		:_name(name)
//	{}
//	string _name;
//};


//class Person
//{
//public:
//	string _name;
//	static int _cout;
//};
//int Person::_cout = 0;
//
//class Student : public Person
//{
//protected:
//	int _stuNum;
//};
//
//int main()
//{
//	Person p;
//	Student s;
//
//	cout << &p._name << endl;
//	cout << &s._name << endl;
//
//	cout << Person::_count << endl;
//
//}





//class student;

//class Person
//{
//public:
//	friend void Display(const Person& p, const Student& s);
//protected:
//	string _name;
//};
//
//class Student : public Person
//{
//	friend void Display(const Person& p, const Student& s);
//protected:
//	int _stuNum;
//};
//
//void Display(const Person& p,const Student& s)
//{
//	cout << p._name << endl;
//	cout << s.stuNNum << endl;
//}
//
//int main()
//{
//	Person p;
//	Student s;
//
//	Display(p, s);
//
//	return 0;
//}



//class Base final
//{
//public:
//	void func5()
//	{
//		cout << "Base::func5" << endl;
//	}
//protected:
//	int a = 1;
//private:
//	Base()
//	{}
//};


//class Person
//{
//public:
//	Person(const char* name = "xxxx")
//		:_name(name)
//	{
//		cout << "Person()" << endl;
//	}
//
//	Person(const Person& p)
//		:_name(p._name)
//	{
//		cout << "Person(const Person& p)" << endl;
//	}
//
//	Person& operator=(const Person& p)
//	{
//		cout << "Person operator=(const Person& p)" << endl;
//		if (this != &p)
//			_name = p._name;
//
//		return *this;
//	}
//
//	~Person()
//	{
//		cout << "~Person" <<endl;
//	}
//	protected:
//		string _name;
//};
//
//class Student : public Person
//{
//public :
//	Student(const char* name,int num ,const char* addrss)
//		:Person(name)
//		,_num(num)
//		,_address(address)
//	{}
//	Student(const Student& s)
//		:Person(s)
//		,_num(s._num)
//		,_address(s._addrss)
//	{}
//
//	Student& operator=(const Student& s)
//	{
//		if(this != &s)
//		{
//			Person::operator=(s);
//
//			_num = s._num;
//			_adress = s.adress;
//		}
//
//		return *this;
//	}
//Protected:
//	int _num = 1;
//	string _adress = "����������";
//
//	int* _ptr = new int[10];
//};




//class A
//{
//public:
//	void func()
//	{
//		cout << "func()" << endl;
//	}
//};
//
//class B : public A
//{
//public:
//	void func(int i)
//	{
//		cout << "func(int i)" << i << endl;
//	}
//};
//
//int main()
//{
//	B b;
//	b.A::func();
//	b.func(1);
//
//	return 0;
//}


//class Person
//{
//protected:
//	string _name = "С����";
//	int _num = 111;
//
//};
//
//class Student : public Person
//{
//public:
//	void Print()
//	{
//		cout << _num << endl;
//		cout << Person::_num << endl;
//	}
//Proteted:
//	int _num = 999;
//};
//
//int main()
//{
//	Student s;
//	s.Print();
//
//	return 0;
//}



//class Person
//{
//protected:
//	virtual void func()
//	{}
//public:
//	string _name;
//	string _sex;
//	int _age;
//};
//class Student : public Person
//{
//	public��
//		int _No;
//};
//
//int main()
//{
//	Student sobj;
//
//	Person pobj = sobj;
//	Person* pp = &sobj;
//	Person pobj = sobj;
//	Person pobj = sobj;
//	rp._name = "����";
//
//	int i = 1;
//	double d = i;
//	const double& rd = i;
//
//	sobj = (Student)pobj;
//
//	Student* ps1 = dynamic_cast<Student*>(pp);
//	cout << ps1 << endl;
//
//	pp = &pobj;
//	Student* ps2 = dynamic_cast<Student*>(pp);
//	cout << ps1 << endl;
//
//	pp = &pobj;
//	Student* ps2 = dynamic_cast<Student*>(pp);
//	cout << ps2 << endl;
//
//	return 0;
//}

////#define CONTAINER std::vector
////#define CONTAINER std::list
//#define CONTAINER std::deque
//
//namespace bit
//{
//	template<class T>
//	class vector
//	{};
//
//	template<class T>
//	class stack : public CONTAINER<T>
//	{
//		void push(const T& x)
//		{
//			CONTAINER<T>::push_back(x);
//		}
//
//		void pop()
//		{
//			CONTAINER<T>::pop_back();
//		}
//
//		const T& top()
//		{
//			return CONTAINER<T>::back();
//		}
//
//		bool empty()
//		{
//			return CONTAINER<T>::empty();
//		}
//	};
//
//	template<class T>
//	class A
//	{
//	public:
//		A()
//		{
//			func();
//		}
//
//		void push(const T& x)
//		{
//			x.func();
//		}
//	};
//}
//
//int main()
//{
//	bit::stack<int> st;
//	st.push(1);
//	st.push(2);
//	st.push(3);
//	while(!st.empty())
//	{
//		cout << st.top() << "";
//		st.pop_back();
//	}
//
//	bit::A<int> aa;
//	aa.push(1);
//
//	return 0;
//}



//class Person
//{
//public:
//	void identity()
//	{
//		cout << "void itidentity()" << _name() << endl;
//		cout << _age << endl;
//	}
//protected:
//	string _name = "����";
//	string _address;
//	string _tel;
//private:
//	int _age = 18;
//};
//
//class Studet :public Person
//{
//public:
//	void study()
//	{
//		identity();
//
//		cout << _tal << endl;
//	}
//protected:
//	int _stuid;
//};
//
//class Teacher : public Person
//{
//public:
//	void teachering()
//	{};
//protected:
//	string title;
//};
//int main()
//{
//	Student s;
//	Teacher t;
//
//	s.identity();
//	t.identity();
//
//	return 0;
//}


//// Tire(��̥)��Car(��)������has-a�Ĺ�ϵ
//class Tire {
//protected:
//	string _brand = "Michelin"; // Ʒ��
//	size_t _size = 17; // �ߴ�
//};
//class Car {
//protected:
//	string _colour = "��ɫ"; // ��ɫ
//	string _num = "��ABIT00"; // ���ƺ�
//	Tire _t1; // ��̥
//	Tire _t2; // ��̥
//	Tire _t3; // ��̥
//	Tire _t4; // ��̥
//};
//class BMW : public Car {
//public:
//	void Drive() { cout << "�ÿ�-�ٿ�" << endl; }
//};
//// Car��BMW/Benz������is-a�Ĺ�ϵ
//class Benz : public Car {
//public:
//	void Drive() { cout << "����-����" << endl; }
//};
//template<class T>
//class vector
//{};
//// stack��vector�Ĺ�ϵ���ȷ���is-a��Ҳ����has-a
//template<class T>
//class stack : public vector<T>
//{};
//template<class T>
//class stack
//{
//public:
//	vector<T> _v;
//};
//int main()
//{
//	return 0;
//}


//template<class CharT, class Traits = std::char_traits<CharT>>
//class basic_ostream : virtual public std::basic_ios<CharT, Traits>
//{};
//template<class CharT, class Traits = std::char_traits<CharT>>
//class basic_istream : virtual public std::basic_ios<CharT, Traits>
//{};

//class Base1 { public: int _b1; };
//class Base2 { public: int _b2; };
//					class Derive : public Base1, public Base2 { public: int _d; };
//					int main()
//					{
//						Derive d;
//						Base1* p1 = &d;
//						Base2* p2 = &d;
//						Derive* p3 = &d;
//						return 0;
//					}


//class Person
//{
//public:
//	Person(const char* name)
//		:_name(name)
//	{}
//	string _name; // ����
//};
//class Student : virtual public Person
//{
//public:
//	Student(const char* name, int num)
//		:Person(name)
//		, _num(num)
//	{}
//protected:
//	int _num; //ѧ��
//};
//class Teacher : virtual public Person
//{
//public:
//	Teacher(const char* name, int id)
//		:Person(name)
//		, _id(id)
//	{}
//protected:
//	int _id; // ְ�����
//};
//// ��Ҫȥ�����μ̳�
//class Assistant : public Student, public Teacher
//{
//public:
//	Assistant(const char* name1, const char* name2, const char* name3)
//		:Person(name3)
//		, Student(name1, 1)
//		, Teacher(name2, 2)
//	{}
//protected:
//	string _majorCourse; // ���޿γ�
//};
//int main()
//{
//	// ˼��һ������a������_name��"����", "����", "����"�е���һ����
//	Assistant a("����", "����", "����");
//	return 0;
//}

//class Person
//{
//public:
//	string _name; // ����
//	/*int _tel;
//	int _age;
//string _gender;
//string _address;*/
//// ...
//};
//// ʹ����̳�Person��
//class Student : virtual public Person
//{
//protected:
//	int _num; //ѧ��
//};
//// ʹ����̳�Person��
//class Teacher : virtual public Person
//{
//protected:
//	int _id; // ְ�����
//};
//// ��������
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse; // ���޿γ�
//};
//int main()
//{
//	// ʹ����̳У����Խ����������Ͷ�����
//	Assistant a;
//	a._name = "peter";
//	return 0;
//}




//class Person
//{
//public:
//	string _name; // ����
//};
//class Student : public Person
//{
//protected:
//	int _num; //ѧ��
//};
//class Teacher : public Person
//{
//protected:
//	int _id; // ְ�����
//};
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse; // ���޿γ�
//};
//int main()
//{
//	// ���뱨��error C2385: �ԡ�_name���ķ��ʲ���ȷ
//	Assistant a;
//	a._name = "peter";
//	// ��Ҫ��ʾָ�������ĸ�����ĳ�Ա���Խ�����������⣬�����������������޷����
//	a.Student::_name = "xxx";
//	a.Teacher::_name = "yyy";
//	return 0;
//}



//class Person
//{
//public:
//	string _name;
//	static int _count;
//};
//int Person::_count = 0;
//class Student : public Person
//{
//protected:
//	int _stuNum;
//};
//int main()
//{
//	Person p;
//	Student s;
//	// ��������н�����Կ����Ǿ�̬��Ա_name�ĵ�ַ�ǲ�һ����
//	// ˵��������̳������ˣ���������������һ��
//	cout << &p._name << endl;
//	cout << &s._name << endl;
//	// ��������н�����Կ�����̬��Ա_count�ĵ�ַ��һ����
//	// ˵��������ͻ��๲��ͬһ�ݾ�̬��Ա
//	cout << &p._count << endl;
//	cout << &s._count << endl;
//	// ���е�����£���������ָ�����򶼿��Է��ʾ�̬��Ա
//	cout << Person::_count << endl;
//	cout << Student::_count << endl;
//	return 0;
//}

//class Student;
//class Person
//{
//public:
//	friend void Display(const Person& p, const Student& s);
//protected:
//	string _name; // ����
//};
//class Student : public Person
//{
//protected:
//	int _stuNum; // ѧ��
//};
//void Display(const Person& p, const Student& s)
//{
//	cout << p._name << endl;
//	cout << s._stuNum << endl;
//}
//int main()
//{
//	Person p;
//	Student s;
//	// ���뱨��error C2248: ��Student::_stuNum��: �޷����� protected ��Ա
//	// ���������DisplayҲ���Student ����Ԫ����
//	Display(p, s);
//	return 0;
//}


//// C++11�ķ���
//class Base final
//{
//public:
//	void func5() { cout << "Base::func5" << endl; }
//protected:
//	int a = 1;
//private:
//	// C++98�ķ���
//	/*Base()
//	{}*/
//};
//class Derive :public Base
//{
//	void func4() { cout << "Derive::func4" << endl; }
//protected:
//	int b = 2;
//};
//int main()
//{
//	Base b;
//	Derive d;
//	return 0;
//}


//class Person
//{
//public:
//	Person(const char* name = "peter")
//		: _name(name)
//	{
//		cout << "Person()" << endl;
//	}
//	Person(const Person& p)
//		: _name(p._name)
//	{
//		cout << "Person(const Person& p)" << endl;
//	}
//	Person& operator=(const Person& p)
//	{
//		cout << "Person operator=(const Person& p)" << endl;
//		if (this != &p)
//			_name = p._name;
//		return *this;
//	}
//	~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//protected:
//	string _name; // ����
//};
//class Student : public Person
//{
//public:
//	Student(const char* name, int num)
//		: Person(name)
//		, _num(num)
//	{
//		cout << "Student()" << endl;
//	}
//	Student(const Student& s)
//		: Person(s)
//		, _num(s._num)
//	{
//		cout << "Student(const Student& s)" << endl;
//	}
//	Student& operator = (const Student& s)
//	{
//		cout << "Student& operator= (const Student& s)" << endl;
//		if (this != &s)
//		{
//			// �������أ�������Ҫ��ʾ����
//			Person::operator =(s);
//			_num = s._num;
//		}
//		return *this;
//	}
//	~Student()
//	{
//		cout << "~Student()" << endl;
//	}
//protected:
//	int _num; //ѧ��
//};
//int main()
//{
//	Student s1("jack", 18);
//	Student s2(s1);
//	Student s3("rose", 17);
//	s1 = s3;
//	return 0;
//}

//class A
//{
//public:
//	void fun()
//	{
//		cout << "func()" << endl;
//	}
//};
//class B : public A
//{
//public:
//	void fun(int i)
//	{
//		cout << "func(int i)" << i << endl;
//	}
//};
//int main()
//{
//	B b;
//	b.fun(10);
//	b.fun();
//	return 0;
//};

//// Student��_num��Person��_num�������ع�ϵ�����Կ�������������Ȼ���ܣ����Ƿǳ����׻���
//class Person
//{
//protected:
//	string _name = "С����"; // ����
//	int _num = 111; // ���֤��
//};
//class Student : public Person
//{
//public:
//	void Print()
//	{
//		cout << " ����:" << _name << endl;
//		cout << " ���֤��:" << Person::_num << endl;
//		cout << " ѧ��:" << _num << endl;
//	}
//protected:
//	int _num = 999; // ѧ��
//};
//int main()
//{
//	Student s1;
//	s1.Print();
//	return 0;
//};



//class Person
//{
//protected:
//	string _name; // ����
//	string _sex; // �Ա�
//	int _age; // ����
//};
//class Student : public Person
//{
//public:
//	int _No; // ѧ��
//};
//int main()
//{
//	Student sobj;
//	// 1.�����������Ը�ֵ�������ָ��/����
//	Person* pp = &sobj;
//	Person& rp = sobj;
//	// ���������Ը�ֵ������Ķ�����ͨ�����ú���ὲ��Ļ���Ŀ���������ɵ�
//	Person pobj = sobj;
//	//2.��������ܸ�ֵ������������������뱨��
//	sobj = pobj;
//	return 0;
//}


//namespace bit
//{
//	//template<class T>
//	//class vector
//	//{};
//	// stack��vector�Ĺ�ϵ���ȷ���is-a��Ҳ����has-a
//	template<class T>
//	class stack : public std::vector<T>
//	{
//	public:
//		void push(const T& x)
//		{
//			// ��������ģ��ʱ����Ҫָ��һ������
//			// ������뱨��:error C3861: ��push_back��: �Ҳ�����ʶ��
//			// ��Ϊstack<int>ʵ����ʱ��Ҳʵ����vector<int>��
//// ����ģ���ǰ���ʵ������push_back�ȳ�Ա����δʵ�����������Ҳ���
//			vector<T>::push_back(x);
//			//push_back(x);
//		}
//		void pop()
//		{
//			vector<T>::pop_back();
//		}
//		const T& top()
//		{
//			return vector<T>::back();
//		}
//		bool empty()
//		{
//			return vector<T>::empty();
//		}
//	};
//}
//int main()
//{
//	bit::stack<int> st;
//	st.push(1);
//	st.push(2);
//	st.push(3);
//	while (!st.empty())
//	{
//		cout << st.top() << " ";
//		st.pop();
//	}
//	return 0;
//}


//// ʵ����ʾ���ּ̳й�ϵ�»����Ա�ĸ����ͳ�Ա���ʹ�ϵ�ı仯
//class Person
//{
//public:
//	void Print()
//	{
//		cout << _name << endl;
//	}
//protected:
//	string _name; // ����
//private:
//	int _age; // ����
//};
////class Student : protected Person
////class Student : private Person
//class Student : public Person
//{
//protected:
//	int _stunum; // ѧ��
//};


//class Person
//{
//public:
//	// ����У԰/ͼ���/ʵ����ˢ��ά��������֤
//	void identity()
//	{
//		cout << "void identity()" << _name << endl;
//	}
//protected:
//	string _name = "����"; // ����
//	string _address; // ��ַ
//	string _tel; // �绰
//	int _age = 18; // ����
//};
//class Student : public Person
//{
//public:
//	// ѧϰ
//	void study()
//	{
//		// ...
//	}
//protected:
//	int _stuid; // ѧ��
//};
//class Teacher : public Person
//{
//public:
//	// �ڿ�
//	void teaching()
//	{
//		//...
//	}
//protected:
//	string title; // ְ��
//};
//int main()
//{
//	Student s;
//	Teacher t;
//	s.identity();
//	t.identity();
//	return 0;
//}

//class Student
//{
//public:
//	// ����У԰/ͼ���/ʵ����ˢ��ά��������֤
//	void identity()
//	{
//		// ...
//	}
//	// ѧϰ
//	void study()
//	{
//		// ...
//	}
//protected:
//	string _name = "peter"; // ����
//	string _address; // ��ַ
//	string _tel; // �绰
//	int _age = 18; // ����
//	int _stuid; // ѧ��
//};
//class Teacher
//{
//public:
//	// ����У԰/ͼ���/ʵ����ˢ��ά��������֤
//	void identity()
//	{
//		// ...
//	}
//	// �ڿ�
//	void teaching()
//	{
//		//...
//	}
//protected:
//	string _name = "����"; // ����
//	int _age = 18; // ����
//	string _address; // ��ַ
//	string _tel; // �绰
//	string _title; // ְ��
//};
//int main()
//{
//	return 0;
//}