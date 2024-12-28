#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int i = 0;
	static int j = 1;
	int* p1 = new int;
	const char* p2 = "xxxxxxxx";
	printf("栈:%p\n", &i);
	printf("静态区:%p\n", &j);
	printf("堆:%p\n", p1);
	printf("常量区:%p\n", p2);
	Base b;
	Derive d;
	Base* p3 = &b;
	Derive* p4 = &d;
	printf("Person虚表地址:%p\n", *(int*)p3);//强制转换成int*可以看虚表中存储函数前四个字节 
	printf("Student虚表地址:%p\n", *(int*)p4);//的地址进而观察到虚表存储地址
	printf("虚函数地址:%p\n", &Base::func1);
	printf("普通函数地址:%p\n", &Base::func5);
	return 0;
}
运行结果：
栈 : 010FF954
静态区 : 0071D000
堆 : 0126D740
常量区 : 0071ABA4
Person虚表地址 : 0071AB44
Student虚表地址 : 0071AB84
虚函数地址 : 00711488
普通函数地址 : 007114BF
//class Base {
//public:
//	virtual void func1() { cout << "Base::func1" << endl; }
//	virtual void func2() { cout << "Base::func2" << endl; }
//	void func5() { cout << "Base::func5" << endl; }
//protected:
//	int a = 1;
//};
//
//class Derive : public Base
//{
//public:
//	// 重写基类的func1
//	virtual void func1() { cout << "Derive::func1" << endl; }
//	virtual void func3() { cout << "Derive::func1" << endl; }
//	void func4() { cout << "Derive::func4" << endl; }
//
//protected:
//	int b = 2;
//};
//
//int main()
//{
//	Base b1;
//	Base b2;
//
//	Derive d;
//
//
//	return 0;
}
//class Person {
//public:
//	virtual void BuyTicket() { cout << "买票-全价" << endl; }
//};
//
//class Student : public Person {
//public:
//	void BuyTicket() { cout << "买票-打折" << endl; }
//};
//
//void Func(Person* ptr)
//{
//	ptr->BuyTicket();
//}
//int main()
//{
//	Person ps;
//	Student st;
//	Func(&ps);
//	Func(&st);
//	return 0;
//}

//int main() {
//	int a = 3;
//	int b = 4;
//
//	double c = 1.0;
//	double d = 2.0;
//
//	swap(a, b);//交换int
//	swap(c, d);//交换double
//
//	cout << a << endl;//输出int
//	cout << c << endl;//输出double
//
//	return 0;
//}
//int main()
//{
//	int i = 0;
//	static int j = 1;
//	int* p1 = new int;
//	const char* p2 = "xxxxxxxx";
//	printf();
//}



//class Derive : public Base
//{
//public:
//	virtual void func1() { cout << "Derive::func1" << endl; }
//
//};


//class Person{
//public:
//	void BuyTicket() { cout << "买票-全价" << endl; }
//protected:
//	string _name;
//};
//
//class student : public Person
//{
//public:
//	virtual void BuyTicket() { cout << "买票-打折" << endl; }
//
//protected:
//	int _id;
//};
//
//class Soldier : public Person
//{
//public:
//	virtual
//};

//class Car
//{
//public:
//	virtual void Drive() = 0;
//};
//
//class Benz : public Car
//{
//public:
//	virtual void Drive()
//	{
//		cout << "Benz-舒适" << endl;
//	}
//};
//
//class BMW : public Car
//{
//public:
//	virtual void Drive()
//	{
//		cout << "BMW-操控" << endl;
//	}
//};
//
//int main()
//{
//	Car* pBenz = new Benz;
//	pBenz->Drive();
//
//	return 0;
//}
//
//class Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Func1()" << endl;
//	}
//
//		virtual void Func2()
//	{
//		cout << "Func1()" << endl;
//	}
//
//	void Func3()
//	{
//		cout << "Func1()" << endl;
//	}
//
//protected:
//	int _b = 1;
//	char _ch = 'x';
//};
//
//int main()
//{
//	Base b;
//	cout << sizeof(b) << endl;
//	return 0;
//}

//class A
//{
//public:
//	virtual ~A()
//	{
//		cout << "~A()" << endl;
//	}
//};
//
//class B : public A
//{
//public:
//	~B()
//	{
//		cout << "~B()->delete:" << _p << endl;
//		delete _p;
//	}
//
//protected:
//	int* _p = new int[10];
//};
//
//class Car
//{
//public:
//	virtual void Drive()final;
//	{}
//};
//
//class Benz :public Car {
//public:
//	virtual void Drive() { cout << "Benz-舒适" << endl; }
//};
//
//int main()
//{
//	A* p1 = new A;
//	A* p2 = new B;
//
//	delete p1;
//	delete p2;
//
//	return 0;
//}



//class A {};
//class B : public A {};



//class Person{
//public :
//	virtual A* BuyTicket()
//	{
//		cout << "买票-全价" << endl;
//		return nullptr;
//	}
//};
//
//class Student : public Person
//{
//public:
//	virtual B* BuyTicket()
//	{
//		cout << "买票-打折" << endl;
//		return nullptr;
//	}
//};
//
//void Func(Person* ptr)
//{
//	ptr->BuyTicket();
//}
//
//int main()
//{
//	Person ps;
//	Student st;
//
//	Func(&ps);
//	Func(&st);
//
//	return 0;
//}


//class A
//{
//public:
//	virtual void func(int val = 1) { std::cout << "A->" << val << std::endl; }
//	virtual void test() { func(); }
//
//};
//
//class B : public A
//{
//public:
//	void func(int val = 0) { std::cout << "B->" << val << std::endl; }
//};
//
//int main(int argc,char* argv)
//{
//	B* p = new B;
//	p->func();
//	p->test();
//
//	return 0;
//}



//class Person
//{
//public:
//	virtual void BuyTicket() { cout << "买票—全价" << endl; }
//};
//
//class Student : public Person{
//public:
//	void BuyTicket() { cout << "买票-打折" << endl; }
//};
//
//void Func(Person& ptr)
//{
//	ptr.BuyTicket();
//}
//
//class Animal
//{
//public:
//	virtual void talk() const
//	{}
//};
//
//class Dog : public Animal
//{
//public:
//	virtual void talk() const
//	{
//		std::cout << "汪汪" << std::endl;
//	}
//};
//
//class Cat : public Animal
//{
//public:
//	virtual void talk() const
//	{
//		std::cout << "喵" << std::endl;
//	}
//};
//
//void letsHear(const Animal& animal)
//{
//	animal.talk();
//}
//
//int main()
//{
//	Person ps;
//	Student st;
//	Func(ps);//对于普通人买票全价
//	Func(st);//对于学生买票半价
//
//	Cat cat;
//	Dog dog;
//	letsHear(cat);//狗的叫声是汪汪
//	letsHear(dog);//猫的叫声是喵
//
//
//	return 0;
//}


//int main()
//{
//	int i = 0;
//	static int j = 1;
//	int* p1 = new int;
//	const char* p2 = "xxxxxxxx";
//	printf("栈:%p\n", &i);
//	printf("静态区:%p\n", &j);
//	printf("堆:%p\n", p1);
//	printf("常量区:%p\n", p2);
//	Base b;
//	Derive d;
//	Base* p3 = &b;
//	Derive* p4 = &d;
//	printf("Person虚表地址:%p\n", *(int*)p3);
//	printf("Student虚表地址:%p\n", *(int*)p4);
//	printf("虚函数地址:%p\n", &Base::func1);
//	printf("普通函数地址:%p\n", &Base::func5);
//	return 0;
//}
//运行结果：
//栈 : 010FF954
//静态区 : 0071D000
//堆 : 0126D740
//常量区 : 0071ABA4
//Person虚表地址 : 0071AB44
//Student虚表地址 : 0071AB84
//虚函数地址 : 00711488
//普通函数地址 : 007114BF


//class Base {
//public:
//	virtual void func1() { cout << "Base::func1" << endl; }
//	virtual void func2() { cout << "Base::func2" << endl; }
//	void func5() { cout << "Base::func5" << endl; }
//protected:
//	int a = 1;
//};
//class Derive : public Base
//{
//public:
//	// 重写基类的func1
//	virtual void func1() { cout << "Derive::func1" << endl; }
//	virtual void func3() { cout << "Derive::func1" << endl; }
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



//// ptr是指针+BuyTicket是虚函数满足多态条件。
//// 这里就是动态绑定，编译在运行时到ptr指向对象的虚函数表中确定调用函数地址
//ptr->BuyTicket();
//00EF2001 mov eax, dword ptr[ptr]
//00EF2004 mov edx, dword ptr[eax]
//00EF2006 mov esi, esp
//00EF2008 mov ecx, dword ptr[ptr]
//00EF200B mov eax, dword ptr[edx]
//00EF200D call eax
//// BuyTicket不是虚函数，不满足多态条件。
//// 这里就是静态绑定，编译器直接确定调用函数地址
//ptr->BuyTicket();
//00EA2C91 mov ecx, dword ptr[ptr]
//00EA2C94 call Student::Student(0EA153Ch)

//class Person {
//public:
//	virtual void BuyTicket() { cout << "买票-全价" << endl; }
//};
//class Student : public Person {
//public:
//	virtual void BuyTicket() { cout << "买票-打折" << endl; }
//};
//class Soldier : public Person {
//public:
//	virtual void BuyTicket() { cout << "买票-优先" << endl; }
//};
//void Func(Person* ptr)
//{
//	// 这里可以看到虽然都是Person指针Ptr在调用BuyTicket
//	// 但是跟ptr没关系，而是由ptr指向的对象决定的。
//	ptr->BuyTicket();
//}
//int main()
//{
//	// 其次多态不仅仅发生在派生类对象之间，多个派生类继承基类，重写虚函数后
//	// 多态也会发生在多个派生类之间。
//	Person ps;
//	Student st;
//	Soldier sr;
//	Func(&ps);
//	Func(&st);
//	Func(&sr);
//	return 0;
//}
//class Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Func1()" << endl;
//	}
//protected:
//	int _b = 1;
//	char _ch = 'x';
//};
//int main()
//{
//	Base b;
//	cout << sizeof(b) << endl;
//	return 0;
//}

//class Car
//{
//public:
//	virtual void Drive() = 0;
//};
//class Benz :public Car
//{
//public:
//	virtual void Drive()
//	{
//		cout << "Benz-舒适" << endl;
//	}
//};
//class BMW :public Car
//{
//public:
//	virtual void Drive()
//	{
//		cout << "BMW-操控" << endl;
//	}
//};
//int main()
//{
//	// 编译报错：error C2259: “Car”: 无法实例化抽象类
//	Car car;
//	Car* pBenz = new Benz;
//	pBenz->Drive();
//	Car* pBMW = new BMW;
//	pBMW->Drive();
//	return 0;
//}


//// error C3668: “Benz::Drive”: 包含重写说明符“override”的方法没有重写任何基类方法
//class Car {
//public:
//	virtual void Dirve()
//	{}
//};
//class Benz :public Car {
//public:
//	virtual void Drive() override { cout << "Benz-舒适" << endl; }
//};
//int main()
//{
//	return 0;
//}
//// error C3248: “Car::Drive”: 声明为“final”的函数无法被“Benz::Drive”重写
//class Car
//{
//public:
//	virtual void Drive() final {}
//};
//class Benz :public Car
//{
//public:
//	virtual void Drive() { cout << "Benz-舒适" << endl; }
//};
//int main()
//{
//	return 0;
//}


//class A
//{
//public:
//	virtual ~A()
//	{
//		cout << "~A()" << endl;
//	}
//};
//class B : public A {
//public:
//	~B()
//	{
//		cout << "~B()->delete:" << _p << endl;
//		delete _p;
//	}
//protected:
//	int* _p = new int[10];
//};
//// 只有派生类Student的析构函数重写了Person的析构函数，下面的delete对象调用析构函数，才能
////构成多态，才能保证p1和p2指向的对象正确的调用析构函数。
//int main()
//{
//	A* p1 = new A;
//	A* p2 = new B;
//	delete p1;
//	delete p2;
//	return 0;
//}



//class A {};
//class B : public A {};
//class Person {
//public:
//	virtual A* BuyTicket()
//	{
//		cout << "买票-全价" << endl;
//		return nullptr;
//	}
//};
//class Student : public Person {
//public:
//	virtual B* BuyTicket()
//	{
//		cout << "买票-打折" << endl;
//		return nullptr;
//	}
//};
//void Func(Person* ptr)
//{
//	ptr->BuyTicket();
//}
//int main()
//{
//	Person ps;
//	Student st;
//	Func(&ps);
//	Func(&st);
//	return 0;
//}

//class A
//{
//public:
//	virtual void func(int val = 1) { std::cout << "A->" << val << std::endl; }
//	virtual void test() { func(); }
//};
//class B : public A
//{
//public:
//	void func(int val = 0) { std::cout << "B->" << val << std::endl; }
//};
//int main(int argc, char* argv[])
//{
//	B* p = new B;
//	p->test();
//	return 0;
//}
//class Animal
//{
//public:
//	virtual void talk() const
//	{}
//};
//class Dog : public Animal
//{
//public:
//	virtual void talk() const
//	{
//		std::cout << "汪汪" << std::endl;
//	}
//};
//class Cat : public Animal
//{
//public:
//	virtual void talk() const
//	{
//		std::cout << "(>^ω^<)喵" << std::endl;
//	}
//};
//void letsHear(const Animal& animal)
//{
//	animal.talk();
//}
//int main()
//{
//	Cat cat;
//	Dog dog;
//	letsHear(cat);
//	letsHear(dog);
//	return 0;
//}

//class Person {
//public:
//	virtual void BuyTicket() { cout << "买票-全价" << endl; }
//};
//class Student : public Person {
//public:
//	virtual void BuyTicket() { cout << "买票-打折" << endl; }
//};
//void Func(Person* ptr)
//{
//	// 这里可以看到虽然都是Person指针Ptr在调用BuyTicket
//	// 但是跟ptr没关系，而是由ptr指向的对象决定的。
//	ptr->BuyTicket();
//}
//int main()
//{
//	Person ps;
//	Student st;
//	Func(&ps);
//	Func(&st);
//	return 0;
//}
//class Person
//{
//public:
//	virtual void BuyTicket() { cout << "买票-全价" << endl; }
//};