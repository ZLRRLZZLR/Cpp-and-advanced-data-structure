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
//	string _name; // 姓名
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
//	// 严格说Student拷贝构造默认生成的就够用了
//	// 如果有需要深拷贝的资源，才需要自己实现
//	Student(const Student& s)
//		:Person(s)
//		, _num(s._num)
//		, _addrss(s._addrss)
//	{
//		// 深拷贝
//	}
//
//	// 严格说Student赋值重载默认生成的就够用了
//	// 如果有需要深拷贝的资源，才需要自己实现
//	Student& operator=(const Student& s)
//	{
//		if (this != &s)
//		{
//			// 父类和子类的operator=构成隐藏关系
//			Person::operator=(s);
//
//			_num = s._num;
//			_addrss = s._addrss;
//		}
//
//		return *this;
//	}
//
//	// 严格说Student析构默认生成的就够用了
//	// 如果有需要显示释放的资源，才需要自己实现
//	// 析构函数都会被特殊处理成destructor() 
//	~Student()
//	{
//		// 子类的析构和父类析构函数也构成隐藏关系
//		// 规定：不需要显示调用，子类析构函数之后，会自动调用父类析构
//		// 这样保证析构顺序，先子后父，显示调用取决于实现的人，不能保证
//		// 先子后父
//		//Person::~Person();
//		//delete _ptr;
//	}
//protected:
//	int _num = 1; //学号
//	string _addrss = "西安市高新区";
//
//	int* _ptr = new int[10];
//};
//
//int main()
//{
//	Student s1("张三", 1, "西安市");
//	Student s2(s1);
//
//	Student s3("李四", 2, "咸阳市");
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
//	string _name; // 姓名
//	string _sex; // 性别
//	int _age; // 年龄
//};
//
//class Student : public Person
//{
//public:
//	int _No; // 学号
//};
//
//int main()
//{
//	Student sobj;
//	// 派生类对象可以赋值给基类的对象是通过调用后面会讲解的基类的拷贝构造完成的
//	Person pobj = sobj;
//	// 1.子类对象可以赋值给父类对象/指针/引用,不属于类型转换
//	Person* pp = &sobj;
//	Person& rp = sobj;
//	rp._name = "张三";
//
//	//int i = 1;
//	//double d = i;
//	//const double& rd = i;//类型转换会产生临时对象
//
//	//2.父类对象不能赋值给子类对象，这里会编译报错
//	//sobj = (Student)pobj;
//
//	// 这里简单了解一下
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
//	a.student::_name = "小李";
//	a.Teacher::_name = "老李";
//
//	cout << sizeof(a) << endl;
//
//	Assistant a("张三"，"李四"，"王五");
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
//	string _adress = "西安高新区";
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
//	string _name = "小李子";
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
//	public：
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
//	rp._name = "张三";
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
//	string _name = "张三";
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


//// Tire(轮胎)和Car(车)更符合has-a的关系
//class Tire {
//protected:
//	string _brand = "Michelin"; // 品牌
//	size_t _size = 17; // 尺寸
//};
//class Car {
//protected:
//	string _colour = "白色"; // 颜色
//	string _num = "陕ABIT00"; // 车牌号
//	Tire _t1; // 轮胎
//	Tire _t2; // 轮胎
//	Tire _t3; // 轮胎
//	Tire _t4; // 轮胎
//};
//class BMW : public Car {
//public:
//	void Drive() { cout << "好开-操控" << endl; }
//};
//// Car和BMW/Benz更符合is-a的关系
//class Benz : public Car {
//public:
//	void Drive() { cout << "好坐-舒适" << endl; }
//};
//template<class T>
//class vector
//{};
//// stack和vector的关系，既符合is-a，也符合has-a
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
//	string _name; // 姓名
//};
//class Student : virtual public Person
//{
//public:
//	Student(const char* name, int num)
//		:Person(name)
//		, _num(num)
//	{}
//protected:
//	int _num; //学号
//};
//class Teacher : virtual public Person
//{
//public:
//	Teacher(const char* name, int id)
//		:Person(name)
//		, _id(id)
//	{}
//protected:
//	int _id; // 职工编号
//};
//// 不要去玩菱形继承
//class Assistant : public Student, public Teacher
//{
//public:
//	Assistant(const char* name1, const char* name2, const char* name3)
//		:Person(name3)
//		, Student(name1, 1)
//		, Teacher(name2, 2)
//	{}
//protected:
//	string _majorCourse; // 主修课程
//};
//int main()
//{
//	// 思考一下这里a对象中_name是"张三", "李四", "王五"中的哪一个？
//	Assistant a("张三", "李四", "王五");
//	return 0;
//}

//class Person
//{
//public:
//	string _name; // 姓名
//	/*int _tel;
//	int _age;
//string _gender;
//string _address;*/
//// ...
//};
//// 使用虚继承Person类
//class Student : virtual public Person
//{
//protected:
//	int _num; //学号
//};
//// 使用虚继承Person类
//class Teacher : virtual public Person
//{
//protected:
//	int _id; // 职工编号
//};
//// 教授助理
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse; // 主修课程
//};
//int main()
//{
//	// 使用虚继承，可以解决数据冗余和二义性
//	Assistant a;
//	a._name = "peter";
//	return 0;
//}




//class Person
//{
//public:
//	string _name; // 姓名
//};
//class Student : public Person
//{
//protected:
//	int _num; //学号
//};
//class Teacher : public Person
//{
//protected:
//	int _id; // 职工编号
//};
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse; // 主修课程
//};
//int main()
//{
//	// 编译报错：error C2385: 对“_name”的访问不明确
//	Assistant a;
//	a._name = "peter";
//	// 需要显示指定访问哪个基类的成员可以解决二义性问题，但是数据冗余问题无法解决
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
//	// 这里的运行结果可以看到非静态成员_name的地址是不一样的
//	// 说明派生类继承下来了，父派生类对象各有一份
//	cout << &p._name << endl;
//	cout << &s._name << endl;
//	// 这里的运行结果可以看到静态成员_count的地址是一样的
//	// 说明派生类和基类共用同一份静态成员
//	cout << &p._count << endl;
//	cout << &s._count << endl;
//	// 公有的情况下，父派生类指定类域都可以访问静态成员
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
//	string _name; // 姓名
//};
//class Student : public Person
//{
//protected:
//	int _stuNum; // 学号
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
//	// 编译报错：error C2248: “Student::_stuNum”: 无法访问 protected 成员
//	// 解决方案：Display也变成Student 的友元即可
//	Display(p, s);
//	return 0;
//}


//// C++11的方法
//class Base final
//{
//public:
//	void func5() { cout << "Base::func5" << endl; }
//protected:
//	int a = 1;
//private:
//	// C++98的方法
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
//	string _name; // 姓名
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
//			// 构成隐藏，所以需要显示调用
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
//	int _num; //学号
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

//// Student的_num和Person的_num构成隐藏关系，可以看出这样代码虽然能跑，但是非常容易混淆
//class Person
//{
//protected:
//	string _name = "小李子"; // 姓名
//	int _num = 111; // 身份证号
//};
//class Student : public Person
//{
//public:
//	void Print()
//	{
//		cout << " 姓名:" << _name << endl;
//		cout << " 身份证号:" << Person::_num << endl;
//		cout << " 学号:" << _num << endl;
//	}
//protected:
//	int _num = 999; // 学号
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
//	string _name; // 姓名
//	string _sex; // 性别
//	int _age; // 年龄
//};
//class Student : public Person
//{
//public:
//	int _No; // 学号
//};
//int main()
//{
//	Student sobj;
//	// 1.派生类对象可以赋值给基类的指针/引用
//	Person* pp = &sobj;
//	Person& rp = sobj;
//	// 生类对象可以赋值给基类的对象是通过调用后面会讲解的基类的拷贝构造完成的
//	Person pobj = sobj;
//	//2.基类对象不能赋值给派生类对象，这里会编译报错
//	sobj = pobj;
//	return 0;
//}


//namespace bit
//{
//	//template<class T>
//	//class vector
//	//{};
//	// stack和vector的关系，既符合is-a，也符合has-a
//	template<class T>
//	class stack : public std::vector<T>
//	{
//	public:
//		void push(const T& x)
//		{
//			// 基类是类模板时，需要指定一下类域，
//			// 否则编译报错:error C3861: “push_back”: 找不到标识符
//			// 因为stack<int>实例化时，也实例化vector<int>了
//// 但是模版是按需实例化，push_back等成员函数未实例化，所以找不到
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


//// 实例演示三种继承关系下基类成员的各类型成员访问关系的变化
//class Person
//{
//public:
//	void Print()
//	{
//		cout << _name << endl;
//	}
//protected:
//	string _name; // 姓名
//private:
//	int _age; // 年龄
//};
////class Student : protected Person
////class Student : private Person
//class Student : public Person
//{
//protected:
//	int _stunum; // 学号
//};


//class Person
//{
//public:
//	// 进入校园/图书馆/实验室刷二维码等身份认证
//	void identity()
//	{
//		cout << "void identity()" << _name << endl;
//	}
//protected:
//	string _name = "张三"; // 姓名
//	string _address; // 地址
//	string _tel; // 电话
//	int _age = 18; // 年龄
//};
//class Student : public Person
//{
//public:
//	// 学习
//	void study()
//	{
//		// ...
//	}
//protected:
//	int _stuid; // 学号
//};
//class Teacher : public Person
//{
//public:
//	// 授课
//	void teaching()
//	{
//		//...
//	}
//protected:
//	string title; // 职称
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
//	// 进入校园/图书馆/实验室刷二维码等身份认证
//	void identity()
//	{
//		// ...
//	}
//	// 学习
//	void study()
//	{
//		// ...
//	}
//protected:
//	string _name = "peter"; // 姓名
//	string _address; // 地址
//	string _tel; // 电话
//	int _age = 18; // 年龄
//	int _stuid; // 学号
//};
//class Teacher
//{
//public:
//	// 进入校园/图书馆/实验室刷二维码等身份认证
//	void identity()
//	{
//		// ...
//	}
//	// 授课
//	void teaching()
//	{
//		//...
//	}
//protected:
//	string _name = "张三"; // 姓名
//	int _age = 18; // 年龄
//	string _address; // 地址
//	string _tel; // 电话
//	string _title; // 职称
//};
//int main()
//{
//	return 0;
//}