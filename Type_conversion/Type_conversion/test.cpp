#include<iostream>
using namespace std;
class A
{
public:
	virtual void func()
	{
	}
protected:
	int _a1 = 1;
};
class B : public A
{
protected:
	int _b1 = 2;
};
int main()
{
	try
	{
		B* pb = new B;
		A* pa = (A*)pb;
		if (typeid(*pb) == typeid(B))
		{
			cout << "typeid(*pb) == typeid(B)" << endl;
		}
		// 如果A和B不是继承关系，则会抛bad_typeid异常
		if (typeid(*pa) == typeid(B))
		{
			cout << "typeid(*pa) == typeid(B)" << endl;
		}
		// 这里pa和pb是A*和B*，不是类类型对象，他会被当做编译是求值的静态类型运
		//算
			// 所以这里始终是不相等的
			if (typeid(pa) == typeid(pb))
			{
				cout << "typeid(pa) == typeid(B)" << endl;
			}
	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;
	}
	return 0;
}