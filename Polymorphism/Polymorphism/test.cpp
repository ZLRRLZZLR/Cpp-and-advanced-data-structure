
//int main()
//{
//	int i = 0;
//	static int j = 1;
//	int* p1 = new int;
//	const char* p2 = "xxxxxxxx";
//	printf("ջ:%p\n", &i);
//	printf("��̬��:%p\n", &j);
//	printf("��:%p\n", p1);
//	printf("������:%p\n", p2);
//	Base b;
//	Derive d;
//	Base* p3 = &b;
//	Derive* p4 = &d;
//	printf("Person����ַ:%p\n", *(int*)p3);
//	printf("Student����ַ:%p\n", *(int*)p4);
//	printf("�麯����ַ:%p\n", &Base::func1);
//	printf("��ͨ������ַ:%p\n", &Base::func5);
//	return 0;
//}
//���н����
//ջ : 010FF954
//��̬�� : 0071D000
//�� : 0126D740
//������ : 0071ABA4
//Person����ַ : 0071AB44
//Student����ַ : 0071AB84
//�麯����ַ : 00711488
//��ͨ������ַ : 007114BF


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
//	// ��д�����func1
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



//// ptr��ָ��+BuyTicket���麯�������̬������
//// ������Ƕ�̬�󶨣�����������ʱ��ptrָ�������麯������ȷ�����ú�����ַ
//ptr->BuyTicket();
//00EF2001 mov eax, dword ptr[ptr]
//00EF2004 mov edx, dword ptr[eax]
//00EF2006 mov esi, esp
//00EF2008 mov ecx, dword ptr[ptr]
//00EF200B mov eax, dword ptr[edx]
//00EF200D call eax
//// BuyTicket�����麯�����������̬������
//// ������Ǿ�̬�󶨣�������ֱ��ȷ�����ú�����ַ
//ptr->BuyTicket();
//00EA2C91 mov ecx, dword ptr[ptr]
//00EA2C94 call Student::Student(0EA153Ch)

//class Person {
//public:
//	virtual void BuyTicket() { cout << "��Ʊ-ȫ��" << endl; }
//};
//class Student : public Person {
//public:
//	virtual void BuyTicket() { cout << "��Ʊ-����" << endl; }
//};
//class Soldier : public Person {
//public:
//	virtual void BuyTicket() { cout << "��Ʊ-����" << endl; }
//};
//void Func(Person* ptr)
//{
//	// ������Կ�����Ȼ����Personָ��Ptr�ڵ���BuyTicket
//	// ���Ǹ�ptrû��ϵ��������ptrָ��Ķ�������ġ�
//	ptr->BuyTicket();
//}
//int main()
//{
//	// ��ζ�̬���������������������֮�䣬���������̳л��࣬��д�麯����
//	// ��̬Ҳ�ᷢ���ڶ��������֮�䡣
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
//		cout << "Benz-����" << endl;
//	}
//};
//class BMW :public Car
//{
//public:
//	virtual void Drive()
//	{
//		cout << "BMW-�ٿ�" << endl;
//	}
//};
//int main()
//{
//	// ���뱨��error C2259: ��Car��: �޷�ʵ����������
//	Car car;
//	Car* pBenz = new Benz;
//	pBenz->Drive();
//	Car* pBMW = new BMW;
//	pBMW->Drive();
//	return 0;
//}


//// error C3668: ��Benz::Drive��: ������д˵������override���ķ���û����д�κλ��෽��
//class Car {
//public:
//	virtual void Dirve()
//	{}
//};
//class Benz :public Car {
//public:
//	virtual void Drive() override { cout << "Benz-����" << endl; }
//};
//int main()
//{
//	return 0;
//}
//// error C3248: ��Car::Drive��: ����Ϊ��final���ĺ����޷�����Benz::Drive����д
//class Car
//{
//public:
//	virtual void Drive() final {}
//};
//class Benz :public Car
//{
//public:
//	virtual void Drive() { cout << "Benz-����" << endl; }
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
//// ֻ��������Student������������д��Person�����������������delete���������������������
////���ɶ�̬�����ܱ�֤p1��p2ָ��Ķ�����ȷ�ĵ�������������
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
//		cout << "��Ʊ-ȫ��" << endl;
//		return nullptr;
//	}
//};
//class Student : public Person {
//public:
//	virtual B* BuyTicket()
//	{
//		cout << "��Ʊ-����" << endl;
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
//		std::cout << "����" << std::endl;
//	}
//};
//class Cat : public Animal
//{
//public:
//	virtual void talk() const
//	{
//		std::cout << "(>^��^<)��" << std::endl;
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
//	virtual void BuyTicket() { cout << "��Ʊ-ȫ��" << endl; }
//};
//class Student : public Person {
//public:
//	virtual void BuyTicket() { cout << "��Ʊ-����" << endl; }
//};
//void Func(Person* ptr)
//{
//	// ������Կ�����Ȼ����Personָ��Ptr�ڵ���BuyTicket
//	// ���Ǹ�ptrû��ϵ��������ptrָ��Ķ�������ġ�
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
//	virtual void BuyTicket() { cout << "��Ʊ-ȫ��" << endl; }
//};