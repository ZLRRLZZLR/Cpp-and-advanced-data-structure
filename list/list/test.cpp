
// ������֧�ֱȽ�
bool operator!=(const Self& l)const { return _it != l._it; }
bool operator==(const Self& l)const { return _it != l._it; }
Iterator _it;
};
//template<class Iterator>
//class ReverseListIterator
//{
//	// ע�⣺�˴�typename����������ȷ���߱�������Ref��Iterator���е����ͣ������Ǿ�̬
//	��Ա����
//		// �������������ʱ�Ͳ�֪��Ref��Iterator�е����ͻ��Ǿ�̬��Ա����
//		// ��Ϊ��̬��Ա����Ҳ�ǰ��� ����::��̬��Ա������ �ķ�ʽ���ʵ�
//public:
//	typedef typename Iterator::Ref Ref;
//	typedef typename Iterator::Ptr Ptr;
//	typedef ReverseListIterator<Iterator> Self;
//public:
//	//////////////////////////////////////////////
//	// ����
//	ReverseListIterator(Iterator it) : _it(it) {}
//	//////////////////////////////////////////////
//	// ����ָ��������Ϊ
//	Ref operator*() {
//		Iterator temp(_it);
//		--temp;
//		return *temp;
//	}
//	Ptr operator->() { return &(operator*()); }
//	//////////////////////////////////////////////
//	// ������֧���ƶ�
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
//		// erase()����ִ�к�it��ָ��Ľڵ��ѱ�ɾ�������it��Ч������һ��ʹ��itʱ�������ȸ�
//		�丳ֵ
//			l.erase(it);
//		++it;
//	}
//}
//// ����
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