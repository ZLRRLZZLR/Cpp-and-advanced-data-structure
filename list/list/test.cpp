
// 迭代器支持比较
bool operator!=(const Self& l)const { return _it != l._it; }
bool operator==(const Self& l)const { return _it != l._it; }
Iterator _it;
};
//template<class Iterator>
//class ReverseListIterator
//{
//	// 注意：此处typename的作用是明确告诉编译器，Ref是Iterator类中的类型，而不是静态
//	成员变量
//		// 否则编译器编译时就不知道Ref是Iterator中的类型还是静态成员变量
//		// 因为静态成员变量也是按照 类名::静态成员变量名 的方式访问的
//public:
//	typedef typename Iterator::Ref Ref;
//	typedef typename Iterator::Ptr Ptr;
//	typedef ReverseListIterator<Iterator> Self;
//public:
//	//////////////////////////////////////////////
//	// 构造
//	ReverseListIterator(Iterator it) : _it(it) {}
//	//////////////////////////////////////////////
//	// 具有指针类似行为
//	Ref operator*() {
//		Iterator temp(_it);
//		--temp;
//		return *temp;
//	}
//	Ptr operator->() { return &(operator*()); }
//	//////////////////////////////////////////////
//	// 迭代器支持移动
//	Self& operator++() {
//		--_it;
//		return *this;
//	}
//	Self operator++(int) {
//		Self temp(*this);
//		--_it;
//		return temp;
//	}
//	Self& operator--() {
//		++_it;
//		return *this;
//	}
//	Self operator--(int)
//	{
//		Self temp(*this);
//		++_it;
//		return temp;
//	}
//	//////////////////////////////////////////////

//void TestListIterator1()
//{
//	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
//	list<int> l(array, array + sizeof(array) / sizeof(array[0]));
//	auto it = l.begin();
//	while (it != l.end())
//	{
//		// erase()函数执行后，it所指向的节点已被删除，因此it无效，在下一次使用it时，必须先给
//		其赋值
//			l.erase(it);
//		++it;
//	}
//}
//// 改正
//void TestListIterator()
//{
//	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
//	list<int> l(array, array + sizeof(array) / sizeof(array[0]));
//	auto it = l.begin();
//	while (it != l.end())
//	{
//		l.erase(it++); // it = l.erase(it);
//	}
//}