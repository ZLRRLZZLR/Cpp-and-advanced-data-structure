//#include"stack_queue.h"
#include"priority_queue.h"

namespace bit
{
	// 默认是大堆
	template<class T, class Container = vector<T>, class Compare = Less<T>>
	class priority_queue
	{
	public:
		void AdjustUp(int child)//向上调整算法
		{
			Compare com;
			int parent = (child - 1) / 2;
			while (child > 0)
			{
				//if (_con[parent] < _con[child])
				if (com(_con[parent], _con[child]))
				{
					swap(_con[child], _con[parent]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else
				{
					break;
				}
			}
		}

		void push(const T& x)
		{
			_con.push_back(x);

			AdjustUp(_con.size() - 1);
		}

		void AdjustDown(int parent)//向下调整算法
		{
			// 先假设左孩子小
			size_t child = parent * 2 + 1;

			Compare com;
			while (child < _con.size())  // child >= n说明孩子不存在，调整到叶子了
			{
				// 找出小的那个孩子
				//if (child + 1 < _con.size() && _con[child] < _con[child + 1])
				if (child + 1 < _con.size() && com(_con[child], _con[child + 1]))
				{
					++child;
				}

				//if (_con[parent] < _con[child])
				if (com(_con[parent], _con[child]))
				{
					swap(_con[child], _con[parent]);
					parent = child;
					child = parent * 2 + 1;
				}
				else
				{
					break;
				}
			}
		}

		void pop()
		{
			swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();
			AdjustDown(0);
		}

		const T& top()
		{
			return _con[0];
		}

		size_t size() const
		{
			return _con.size();
		}

		bool empty() const
		{
			return _con.empty();
		}

	private:
		Container _con;
	};
}

// //仿函数：本质是一个类，这个类重载operator(),他的对象可以像函数一样使用
//template<class T>
//class Less
//{
//public:
//	bool operator()(const T& x, const T& y)
//	{
//		return x < y;
//	}
//};
//
//template<class T>
//class Greater
//{
//public:
//	bool operator()(const T& x, const T& y)
//	{
//		return x > y;
//	}
//};
//
// //< 升序
// //> 降序
//template<class Compare>
//void BubbleSort(int* a, int n, Compare com)
//{
//	for (int j = 0; j < n; j++)
//	{
//		// 单趟
//		int flag = 0;
//		for (int i = 1; i < n - j; i++)
//		{
//			//if (a[i] < a[i - 1])
//			if (com(a[i], a[i - 1]))//通过仿函数，这里的比较逻辑
//			{	                    //我们就可以通过传比较器（仿函数）控制
//				swap(a[i - 1], a[i]);
//				flag = 1;
//			}
//		}
//
//		if (flag == 0)
//		{
//			break;
//		}
//	}
//}
//
//int main()
//{
//	Less<int> LessFunc;
//	Greater<int> GreaterFunc;
//	// 函数对象
//	cout << LessFunc(1, 2) << endl;
//	cout << LessFunc.operator()(1, 2) << endl;
//
//	int a[] = { 9,1,2,5,7,4,6,3 };
//	BubbleSort(a, 8, LessFunc);//传入比较器（仿函数）控制内部的比较逻辑
//	BubbleSort(a, 8, GreaterFunc);
//
//	BubbleSort(a, 8, Less<int>());
//	BubbleSort(a, 8, Greater<int>());
//
//	return 0;
//}

//template<class T, class Container = deque<T>>
//class queue
//{
//public:
//	void push(const T& x)
//	{
//		_con.push_back(x);
//	}
//
//	void pop()
//	{
//		_con.pop_front();
//	}
//
//	const T& front() const
//	{
//		return _con.front();
//	}
//
//	const T& back() const
//	{
//		return _con.back();
//	}
//
//	size_t size() const
//	{
//		return _con.size();
//	}
//
//	bool empty() const
//	{
//		return _con.empty();
//	}
//
//private:
//	Container _con;
//};


//template<class T, class Container = deque<T>>
//class stack
//{
//public:
//	void push(const T& x)
//	{
//		_con.push_back(x);
//	}
//
//	void pop()
//	{
//		_con.pop_back();
//	}
//
//	const T& top() const
//	{
//		return _con.back();
//	}
//
//	size_t size() const
//	{
//		return _con.size();
//	}
//
//	bool empty() const
//	{
//		return _con.empty();
//	}
//
//private:
//	Container _con;//自定义对象调用自己的析构和构造函数，我们不需要写
//};



//int main()
//{
//	//zlr::TestStack();
//	//cout << endl;
//	//zlr::TestQueue();
//	zlr::TestPriority_queue();
//	
//	return 0;
//}

//int main()
//{
//	bit::priority_queue<int, vector<int>, Greater<int >> pq;
//
//
//}

//template<class T>
//class Less
//{
//public:
//	bool operator()(const T& x,const T& y)
//	{
//		return x < y;
//	}
//};
//
//template<class T>
//class Greater
//{
//public:
//	bool operator()(const T& x,const T& y)
//	{
//		return x > y;
//	}
//};
//
//namespace bit
//{
//	template<class T,class Container = vector<T>,class Compare = Less<T>>
//	class priority_queue
//	{
//	public:
//		void AdjustUp(int child)
//		{
//			Compare com;
//			int parent = (child - 1) / 2;
//			while (child > 0)
//			{
//				if(com(_con[parent],_con[child]))
//				{
//					swap(_con[child], _con[parent]);
//					child = parent;
//					parent = (child - 1) / 2;
//				}
//				else
//				{
//					break;
//				}
//			}
//		}
//
//		void push(const T& x)
//		{
//			_con.push_back(x);
//
//			Adjustup(_con.size() - 1);
//		}
//
//		void AdjustDown(int parent)
//		{
//			size_t child = parent * 2 + 1;
//
//			Compare com;
//			while(child < _con.size())
//			{
//				if(child + 1 < _con.size() && com(_con[child],_con[child + 1]))
//				{
//					++child;
//				}
//
//				if (com(_con[child], _con[parent]))
//				{
//					swap(_con[child], _con[parent]);
//					parent = child;
//					child = parent * 2 + 1；
//				}
//				else
//				{
//					break;
//				}
//
//			}
//		}
//	};
//}
//
//
//namespace bit
//{
//
//
//	//template<class T,class Container = deque<T>>
//	//class stack
//	//{
//	//public:
//	//	void push(const T& x)
//	//	{
//	//		_con.push_back(x);
//	//	}
//
//	//	void pop()
//	//	{
//	//		_con.pop_back();
//	//	}
//	//	const T& top() const
//	//	{
//	//		return _con.back();
//	//	}
//
//	//	size_t size() const
//	//	{
//	//		return _con.size();
//	//	}
//
//	//	bool empty() const
//	//	{
//	//		return _con.empty();
//	//	}
//
//	//private :
//	//	Container _con;
//	//};
//}



//namespace bite
//{
//	template<class T, class Con = deque<T>>
//	//template<class T, class Con = list<T>>
//	class queue
//	{
//	public:
//		queue() {}
//		void push(const T& x) { _c.push_back(x); }
//		void pop() { _c.pop_front(); }
//		T& back() { return _c.back(); }
//		const T& back()const { return _c.back(); }
//		T& front() { return _c.front(); }
//		const T& front()const { return _c.front(); }
//		size_t size()const { return _c.size(); }
//		bool empty()const { return _c.empty(); }
//	private:
//		Con _c;
//	};
//}

//#include<deque>
//namespace bite
//{
//	template<class T, class Con = deque<T>>
//	//template<class T, class Con = vector<T>>
//	//template<class T, class Con = list<T>>
//	class stack
//	{
//	public:
//		stack() {}
//		void push(const T& x) { _c.push_back(x); }
//		void pop() { _c.pop_back(); }
//		T& top() { return _c.back(); }
//		const T& top()const { return _c.back(); }
//		size_t size()const { return _c.size(); }
//		bool empty()const { return _c.empty(); }
//	private:
//		Con _c;
//	};
//}


//class Solution {
//public:
//	int findKthLargest(vector<int>& nums, int k) {
//		// 将数组中的元素先放入优先级队列中
//		priority_queue<int> p(nums.begin(), nums.end());
//		// 将优先级队列中前k-1个元素删除掉
//		for (int i = 0; i < k - 1; ++i)
//		{
//			p.pop();
//		}
//		return p.top();
//	}
//};

//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{}
//	bool operator<(const Date& d)const
//	{
//		return (_year < d._year) ||
//			(_year == d._year && _month < d._month) ||
//			(_year == d._year && _month == d._month && _day < d._day);
//	}
//	bool operator>(const Date& d)const
//	{
//		return (_year > d._year) ||
//			(_year == d._year && _month > d._month) ||
//			(_year == d._year && _month == d._month && _day > d._day);
//	}
//	friend ostream& operator<<(ostream& _cout, const Date& d)
//	{
//		_cout << d._year << "-" << d._month << "-" << d._day;
//		return _cout;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//void TestPriorityQueue()
//{
//	// 大堆，需要用户在自定义类型中提供<的重载
//	priority_queue<Date> q1;
//	q1.push(Date(2018, 10, 29));
//	q1.push(Date(2018, 10, 28));
//	q1.push(Date(2018, 10, 30));
//	cout << q1.top() << endl;
//	// 如果要创建小堆，需要用户提供>的重载
//	priority_queue<Date, vector<Date>, greater<Date>> q2;
//	q2.push(Date(2018, 10, 29));
//	q2.push(Date(2018, 10, 28));
//	q2.push(Date(2018, 10, 30));
//	cout << q2.top() << endl;
//}


//#include <vector>
//#include <queue>
//#include <functional> // greater算法的头文件
//void TestPriorityQueue()
//{
//	// 默认情况下，创建的是大堆，其底层按照小于号比较
//	vector<int> v{ 3,2,7,6,0,4,1,9,8,5 };
//	priority_queue<int> q1;
//	for (auto& e : v)
//		q1.push(e);
//	cout << q1.top() << endl;
//	// 如果要创建小堆，将第三个模板参数换成greater比较方式
//	priority_queue<int, vector<int>, greater<int>> q2(v.begin(), v.end());
//	cout << q2.top() << endl;
//}



//#include <list>
//namespace bite
//{
//	template<class T>
//	class queue
//	{
//	public:
//		queue() {}
//		void push(const T& x) { _c.push_back(x); }
//		void pop() { _c.pop_front(); }
//		T& back() { return _c.back(); }
//		const T& back()const { return _c.back(); }
//		T& front() { return _c.front(); }
//		const T& front()const { return _c.front(); }
//		size_t size()const { return _c.size(); }
//		bool empty()const { return _c.empty(); }
//	private:
//		std::list<T> _c;
//	};
//}

//#include<vector>
//namespace bite
//{
//	template<class T>
//	class stack
//	{
//	public:
//		stack() {}
//		void push(const T& x) { _c.push_back(x); }
//		void pop() { _c.pop_back(); }
//		T& top() { return _c.back(); }
//		const T& top()const { return _c.back(); }
//		size_t size()const { return _c.size(); }
//		bool empty()const { return _c.empty(); }
//	private:
//		std::vector<T> _c;
//	};
//}


//
//// ReverseIterator.h
//// 所有容器的反向迭代器
//// 迭代器适配器
//namespace bit
//{
//	template<class Iterator, class Ref, class Ptr>
//	struct ReverseIterator
//	{
//		typedef ReverseIterator<Iterator, Ref, Ptr> Self;
//		// 正向迭代器
//		Iterator _it;
//		ReverseIterator(Iterator it)
//			:_it(it)
//		{}
//		Ref operator*()
//		{
//			Iterator tmp = _it;
//			return *(--tmp);
//		}
//		Ptr operator->()
//		{
//			return &(operator*());
//		}
//		Self& operator++()
//		{
//			--_it;
//			return *this;
//		}
//		Self& operator--()
//		{
//			++_it;
//			return *this;
//		}
//		Self operator++(int)
//		{
//			Self tmp(*this);
//			--_it;
//			return tmp;
//		}
//		Self operator--(int)
//		{
//			Self tmp(*this);
//			--_it;
//			return tmp;
//		}
//		bool operator!=(const Self& s) const
//		{
//			return _it != s._it;
//		}
//		bool operator==(const Self& s) const
//		{
//			return _it != s._it;
//		}
//	};
//}
//// vector.h
//#include"ReverseIterator.h"
//namespace bit
//{
//	template<class T>
//	class vector
//	{
//	public:
//		typedef T* iterator;
//		typedef const T* const_iterator;
//		typedef ReverseIterator<iterator, T&, T*> reverse_iterator;
//		typedef ReverseIterator<const_iterator, const T&, const T*>
//			const_reverse_iterator;
//		reverse_iterator rbegin()
//		{
//			return reverse_iterator(end());
//		}
//		reverse_iterator rend()
//		{
//			return reverse_iterator(begin());
//		}
//		const_reverse_iterator rbegin() const
//		{
//			return const_reverse_iterator(end());
//		}
//		const_reverse_iterator rend() const
//		{
//			return const_reverse_iterator(begin());
//		}
//		iterator begin()
//		{
//			return _start;
//		}
//		iterator end()
//		{
//			return _finish;
//		}
//		const_iterator begin() const
//		{
//			return _start;
//		}
//		const_iterator end() const
//		{
//			return _finish;
//		}
//		// ....
//	private:
//		iterator _start = nullptr;
//		iterator _finish = nullptr;
//		iterator _endofstorage = nullptr;
//	};
//}
//// list.h
//#include"ReverseIterator.h"
//namespace bit
//{
//	template<class T>
//	class list
//	{
//		typedef ListNode<T> Node;
//	public:
//		typedef ListIterator<T, T&, T*> iterator;
//		typedef ListIterator<T, const T&, const T*> const_iterator;
//		typedef ReverseIterator<iterator, T&, T*> reverse_iterator;
//		typedef ReverseIterator<const_iterator, const T&, const T*>
//			const_reverse_iterator;
//		reverse_iterator rbegin()
//		{
//			return reverse_iterator(end());
//		}
//		reverse_iterator rend()
//		{
//			return reverse_iterator(begin());
//		}
//		const_reverse_iterator rbegin() const
//		{
//			return const_reverse_iterator(end());
//		}
//		const_reverse_iterator rend() const
//		{
//			return const_reverse_iterator(begin());
//		}
//		iterator begin()
//		{
//			return _head->_next;
//		}
//		iterator end()
//		{
//			return _head;
//		}
//		const_iterator begin() const
//		{
//			return _head->_next;
//		}
//		const_iterator end() const
//		{
//			return _head;
//		}
//		// ...
//	private:
//		Node* _head;
//		size_t _size;
//	};
//}
//// test.cpp
//#include"list.h"
//#include"vector.h"
//int main()
//{
//	bit::list<int> lt = { 1,2,3,4 };
//	bit::list<int>::reverse_iterator rit = lt.rbegin();
//	while (rit != lt.rend())
//	{
//		//*rit = 1;
//		cout << *rit << " ";
//		++rit;
//	}
//	cout << endl;
//	return 0;
//}
////int main()
////{
//// bit::vector<int> v = { 1,2,3,4 };
//// bit::vector<int>::reverse_iterator rit = v.rbegin();
//// while (rit != v.rend())
//// {
//// //*rit = 1;
//// cout << *rit << " ";
//// ++rit;
//// }
//// cout << endl;
////
//// return 0;
////}


//// stl_list.h
//template <class T, class Alloc = alloc>
//class list {
//public:
//	typedef __list_iterator<T, T&, T*> iterator;
//	typedef __list_iterator<T, const T&, const T*> const_iterator;
//#ifdef __STL_CLASS_PARTIAL_SPECIALIZATION
//	typedef reverse_iterator<const_iterator> const_reverse_iterator;
//	typedef reverse_iterator<iterator> reverse_iterator;
//#else /* __STL_CLASS_PARTIAL_SPECIALIZATION */
//	typedef reverse_bidirectional_iterator<const_iterator, value_type,
//		const_reference, difference_type> const_reverse_iterator;
//	typedef reverse_bidirectional_iterator<iterator, value_type, reference,
//		difference_type> reverse_iterator;
//#endif /* __STL_CLASS_PARTIAL_SPECIALIZATION */
//	iterator begin() { return (link_type)((*node).next); }
//	const_iterator begin() const { return (link_type)((*node).next); }
//	iterator end() { return node; }
//	const_iterator end() const { return node; }
//	reverse_iterator rbegin() { return reverse_iterator(end()); }
//	const_reverse_iterator rbegin() const {
//		return
//			const_reverse_iterator(end());
//	}
//	reverse_iterator rend() { return reverse_iterator(begin()); }
//	const_reverse_iterator rend() const {
//		return
//			const_reverse_iterator(begin());
//	}
//};
//// stl_vector.h
//template <class T, class Alloc = alloc>
//class vector {
//public:
//	typedef T value_type;
//	typedef value_type* iterator;
//#ifdef __STL_CLASS_PARTIAL_SPECIALIZATION
//	typedef reverse_iterator<const_iterator> const_reverse_iterator;
//	typedef reverse_iterator<iterator> reverse_iterator;
//#else /* __STL_CLASS_PARTIAL_SPECIALIZATION */
//	typedef reverse_iterator<const_iterator, value_type, const_reference,
//		difference_type> const_reverse_iterator;
//	typedef reverse_iterator<iterator, value_type, reference, difference_type>
//		reverse_iterator;
//#endif /* __STL_CLASS_PARTIAL_SPECIALIZATION */
//	iterator begin() { return start; }
//	const_iterator begin() const { return start; }
//	iterator end() { return finish; }
//	const_iterator end() const { return finish; }
//	reverse_iterator rbegin() { return reverse_iterator(end()); }
//	const_reverse_iterator rbegin() const {
//		return
//			const_reverse_iterator(end());
//	}
//	reverse_iterator rend() { return reverse_iterator(begin()); }
//	const_reverse_iterator rend() const {
//		return
//			const_reverse_iterator(begin());
//	}
//};
//// stl_iterator.h
//#ifdef __STL_CLASS_PARTIAL_SPECIALIZATION
//// This is the new version of reverse_iterator, as defined in the
//// draft C++ standard. It relies on the iterator_traits template,
//// which in turn relies on partial specialization. The class
//// reverse_bidirectional_iterator is no longer part of the draft
//// standard, but it is retained for backward compatibility.
//template <class Iterator>
//class reverse_iterator
//{
//protected:
//	Iterator current;
//public:
//	typedef typename iterator_traits<Iterator>::iterator_category
//		iterator_category;
//	typedef typename iterator_traits<Iterator>::value_type
//		value_type;
//	typedef typename iterator_traits<Iterator>::difference_type
//		difference_type;
//	typedef typename iterator_traits<Iterator>::pointer
//		pointer;
//	typedef typename iterator_traits<Iterator>::reference
//		reference;
//	typedef Iterator iterator_type;
//	typedef reverse_iterator<Iterator> self;
//public:
//	reverse_iterator() {}
//	explicit reverse_iterator(iterator_type x) : current(x) {}
//	reverse_iterator(const self& x) : current(x.current) {}
//#ifdef __STL_MEMBER_TEMPLATES
//	template <class Iter>
//	reverse_iterator(const reverse_iterator<Iter>& x) : current(x.current) {}
//#endif /* __STL_MEMBER_TEMPLATES */
//	iterator_type base() const { return current; }
//	reference operator*() const {
//		Iterator tmp = current;
//		return *--tmp;
//	}
//#ifndef __SGI_STL_NO_ARROW_OPERATOR
//	pointer operator->() const { return &(operator*()); }
//#endif /* __SGI_STL_NO_ARROW_OPERATOR */
//	self& operator++() {
//		--current;
//		return *this;
//	}
//	self operator++(int) {
//		self tmp = *this;
//		--current;
//		return tmp;
//	}
//	self& operator--() {
//		++current;
//		return *this;
//	}
//	self operator--(int) {
//		self tmp = *this;
//		++current;
//		return tmp;
//	}
//	self operator+(difference_type n) const {
//		return self(current - n);
//	}
//	self& operator+=(difference_type n) {
//		current -= n;
//		return *this;
//	}
//	self operator-(difference_type n) const {
//		return self(current + n);
//	}
//	self& operator-=(difference_type n) {
//		current += n;
//		return *this;
//	}
//	reference operator[](difference_type n) const { return *(*this + n); }
//};
//template <class Iterator>
//inline bool operator==(const reverse_iterator<Iterator>& x,
//	const reverse_iterator<Iterator>& y) {
//	return x.base() == y.base();
//}
//template <class Iterator>
//inline bool operator<(const reverse_iterator<Iterator>& x,
//	const reverse_iterator<Iterator>& y) {
//	return y.base() < x.base();
//}
//template <class Iterator>
//inline typename reverse_iterator<Iterator>::difference_type
//operator-(const reverse_iterator<Iterator>& x,
//	const reverse_iterator<Iterator>& y) {
//	return y.base() - x.base();
//}
//template <class Iterator>
//inline reverse_iterator<Iterator>
//operator+(reverse_iterator<Iterator>::difference_type n,
//	const reverse_iterator<Iterator>& x) {
//	return reverse_iterator<Iterator>(x.base() - n);
//}
//#else /* __STL_CLASS_PARTIAL_SPECIALIZATION */
//// This is the old version of reverse_iterator, as found in the original
//// HP STL. It does not use partial specialization.
//template <class BidirectionalIterator, class T, class Reference = T&,
//	class Distance = ptrdiff_t>
//class reverse_bidirectional_iterator {
//	typedef reverse_bidirectional_iterator<BidirectionalIterator, T, Reference,
//		Distance> self;
//protected:
//	BidirectionalIterator current;
//public:
//	typedef bidirectional_iterator_tag iterator_category;
//	typedef T value_type;
//	typedef Distance difference_type;
//	typedef T* pointer;
//	typedef Reference reference;
//	reverse_bidirectional_iterator() {}
//	explicit reverse_bidirectional_iterator(BidirectionalIterator x)
//		: current(x) {}
//	BidirectionalIterator base() const { return current; }
//	Reference operator*() const {
//		BidirectionalIterator tmp = current;
//		return *--tmp;
//	}
//#ifndef __SGI_STL_NO_ARROW_OPERATOR
//	pointer operator->() const { return &(operator*()); }
//#endif /* __SGI_STL_NO_ARROW_OPERATOR */
//	self& operator++() {
//		--current;
//		return *this;
//	}
//	self operator++(int) {
//		self tmp = *this;
//		--current;
//		return tmp;
//	}
//	self& operator--() {
//		++current;
//		return *this;
//	}
//	self operator--(int) {
//		self tmp = *this;
//		++current;
//		return tmp;
//	}
//};
//template <class RandomAccessIterator, class T, class Reference = T&,
//	class Distance = ptrdiff_t>
//class reverse_iterator {
//	typedef reverse_iterator<RandomAccessIterator, T, Reference, Distance>
//		self;
//protected:
//	RandomAccessIterator current;
//public:
//	typedef random_access_iterator_tag iterator_category;
//	typedef T value_type;
//	typedef Distance difference_type;
//	typedef T* pointer;
//	typedef Reference reference;
//	reverse_iterator() {}
//	explicit reverse_iterator(RandomAccessIterator x) : current(x) {}
//	RandomAccessIterator base() const { return current; }
//	Reference operator*() const { return *(current - 1); }
//#ifndef __SGI_STL_NO_ARROW_OPERATOR
//	pointer operator->() const { return &(operator*()); }
//#endif /* __SGI_STL_NO_ARROW_OPERATOR */
//	self& operator++() {
//		--current;
//		return *this;
//	}
//	self operator++(int) {
//		self tmp = *this;
//		--current;
//		return tmp;
//	}
//	self& operator--() {
//		++current;
//		return *this;
//	}
//	self operator--(int) {
//		self tmp = *this;
//		++current;
//		return tmp;
//	}
//	self operator+(Distance n) const {
//		return self(current - n);
//	}
//	self& operator+=(Distance n) {
//		current -= n;
//		return *this;
//	}
//	self operator-(Distance n) const {
//		return self(current + n);
//	}
//	self& operator-=(Distance n) {
//		current += n;
//		return *this;
//	}
//	Reference operator[](Distance n) const { return *(*this + n); }
//};
//#endif //__STL_CLASS_PARTIAL_SPECIALIZATION

//class Solution {
//public:
//	//map<char, int> _operatorPrecedence = { { '+', 1 }, { '-', 1 }, { '*', 2
//}, { '/', 2 } };
//int operatorPrecedence(char ch)
//{
//	struct opPD
//	{
//		char _op;
//		int _pd;
//	};
//	static opPD arr[] = { {'+', 1},{'-', 1},{'*', 2},{'/', 2} };
//	for (auto& e : arr)
//	{
//		if (e._op == ch)
//		{
//			return e._pd;
//		}
//	}
//	assert(false);
//	return -1;
//}
//void toRPN(const string& s, size_t& i, vector<string>& v)
//{
//	stack<char> st;
//	while (i < s.size())
//	{
//		if (isdigit(s[i]))
//		{
//			// 运算数输出
//			string num;
//			while (i < s.size() && isdigit(s[i]))
//			{
//				num += s[i];
//				++i;
//			}
//			v.push_back(num);
//		}
//		else
//		{
//			if (s[i] == '(')
//			{
//				// 递归方式处理括号中的子表达式
//				++i;
//				toRPN(s, i, v);
//			}
//			else if (s[i] == ')')
//			{
//				++i;
//				// 栈中的运算符全部输出
//				while (!st.empty())
//				{
//					v.push_back(string(1, st.top()));
//					st.pop();
//				}
//				// 结束递归
//				return;
//			}
//			else
//			{
//				// 运算符
//				// 1、如果栈为空或者栈不为空且当前运算符比栈顶运算符优先级高，则当
//				前运算符入栈
//					// 2、如果栈不为为空且比栈顶运算符优先级低或相等，说明栈顶的运算符
//					可以运算了，
//					// 输出栈顶运算符，当前运算符继续走前面遇到运算符的逻辑
//					if (st.empty() || operatorPrecedence(s[i]) >
//						operatorPrecedence(st.top()))
//					{
//						st.push(s[i]);
//						++i;
//					}
//					else
//					{
//						v.push_back(string(1, st.top()));
//						st.pop();
//					}
//			}
//		}
//	}
//	// 栈中的运算符全部输出
//	while (!st.empty())
//	{
//		v.push_back(string(1, st.top()));
//		st.pop();
//	}
//}
//int evalRPN(const vector<string>& tokens) {
//	stack<int> s;
//	for (size_t i = 0; i < tokens.size(); ++i)
//	{
//		const string& str = tokens[i];
//		// str为数字
//		if (!("+" == str || "-" == str || "*" == str || "/" == str))
//		{
//			s.push(stoi(str));
//		}
//		else
//		{
//			// str为操作符
//			int right = s.top();
//			s.pop();
//			int left = s.top();
//			s.pop();
//			switch (str[0])
//			{
//			case '+':
//				s.push(left + right);
//				break;
//			case '-':
//				s.push(left - right);
//				break;
//			case '*':
//				s.push(left * right);
//				break;
//			case '/':
//				s.push(left / right);
//				break;
//			}
//		}
//	}
//	return s.top();
//}
//int calculate(string s)
//{
//	// 1、去除所有空格，否则下面的一些逻辑没办法处理
//	std::string news;
//	news.reserve(s.size());
//	for (auto ch : s)
//	{
//		if (ch != ' ')
//			news += ch;
//	}
//	s.swap(news);
//	news.clear();
//	// 2、将所有的负数-x转换为0-x
//	for (size_t i = 0; i < s.size(); ++i)
//	{
//		if (s[i] == '-' && (i == 0 || (!isdigit(s[i - 1]) && s[i - 1] !=
//			')')))
//			news += "0-";
//		else
//			news += s[i];
//	}
//	// 中缀表达式转成后缀表达式
//	size_t i = 0;
//	vector<string> v;
//	toRPN(news, i, v);
//	// 后缀表达式进行运算
//	return evalRPN(v);
//}
//};

//class Solution {
//public:
//	//map<char, int> _operatorPrecedence = { { '+', 1 }, { '-', 1 }, { '*', 2
//}, { '/', 2 } };
//int operatorPrecedence(char ch)
//{
//	struct opPD
//	{
//		char _op;
//		int _pd;
//	};
//	static opPD arr[] = { {'+', 1},{'-', 1},{'*', 2},{'/', 2} };
//	for (auto& e : arr)
//	{
//		if (e._op == ch)
//		{
//			return e._pd;
//		}
//	}
//	assert(false);
//	return -1;
//}
//void toRPN(const string& s, size_t& i, vector<string>& v)
//{
//	stack<char> st;
//	while (i < s.size())
//	{
//		if (isdigit(s[i]))
//		{
//			// 操作数输出
//			string num;
//			while (i < s.size() && isdigit(s[i]))
//			{
//				num += s[i];
//				++i;
//			}
//			v.push_back(num);
//		}
//		else
//		{
//			if (s[i] == '(')
//			{
//				// 递归方式处理括号中的子表达式
//				++i;
//				toRPN(s, i, v);
//			}
//			else if (s[i] == ')')
//			{
//				++i;
//				// 栈中的运算符全部输出
//				while (!st.empty())
//				{
//					v.push_back(string(1, st.top()));
//					st.pop();
//				}
//				// 结束递归
//				return;
//			}
//			else
//			{
//				// 运算符
//				// 1、如果栈为空或者栈不为空且当前运算符比栈顶运算符优先级高，则当
//				前运算符入栈
//					// 2、如果栈不为为空且比栈顶运算符优先级低或相等，说明栈顶的运算符
//					可以运算了，
//					// 输出栈顶运算符，当前运算符继续走前面遇到运算符的逻辑
//					if (st.empty() || operatorPrecedence(s[i]) >
//						operatorPrecedence(st.top()))
//					{
//						st.push(s[i]);
//						++i;
//					}
//					else
//					{
//						v.push_back(string(1, st.top()));
//						st.pop();
//					}
//			}
//		}
//	}
//	// 栈中的运算符全部输出
//	while (!st.empty())
//	{
//		v.push_back(string(1, st.top()));
//		st.pop();
//	}
//}
//};
//int main()
//{
//	size_t i = 0;
//	vector<string> v;
//	//string str = "1+2-3";
//	string str = "1+2-(3*4+5)-7";
//	Solution().toRPN(str, i, v);
//	for (auto& e : v)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	return 0;
//}

//class Solution {
//public:
//	int evalRPN(const vector<string>& tokens) {
//		stack<int> s;
//		for (size_t i = 0; i < tokens.size(); ++i)
//		{
//			const string& str = tokens[i];
//			// str为运算数
//			if (!("+" == str || "-" == str || "*" == str || "/" == str))
//			{
//				s.push(stoi(str));
//			}
//			else
//			{
//				// str为运算符
//				int right = s.top();
//				s.pop();
//				int left = s.top();
//				s.pop();
//				switch (str[0])
//				{
//				case '+':
//					s.push(left + right);
//					break;
//				case '-':
//					s.push(left - right);
//					break;
//				case '*':
//					s.push(left * right);
//					break;
//				case '/':
//					s.push(left / right);
//					break;
//				}
//			}
//		}
//		return s.top();
//	}
//};

//class MinStack
//{
//public:
//	void push(int x)
//	{
//		// 只要是压栈，先将元素保存到_elem中
//		_elem.push(x);
//		// 如果x小于_min中栈顶的元素，将x再压入_min中
//		if (_min.empty() || x <= _min.top())
//			_min.push(x);
//	}
//	void pop()
//	{
//		// 如果_min栈顶的元素等于出栈的元素，_min顶的元素要移除
//		if (_min.top() == _elem.top())
//			_min.pop();
//		_elem.pop();
//	}
//	int top() { return _elem.top(); }
//	int getMin() { return _min.top(); }
//private:
//	// 保存栈中的元素
//	std::stack<int> _elem;
//	// 保存栈的最小值
//	std::stack<int> _min;
//};
//
//class Solution {
//public:
//	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
//		//入栈和出栈的元素个数必须相同
//		if (pushV.size() != popV.size())
//			return false;
//		// 用s来模拟入栈与出栈的过程
//		int outIdx = 0;
//		int inIdx = 0;
//		stack<int> s;
//		while (outIdx < popV.size())
//		{
//			// 如果s是空，或者栈顶元素与出栈的元素不相等，就入栈
//			while (s.empty() || s.top() != popV[outIdx])
//			{
//				if (inIdx < pushV.size())
//					s.push(pushV[inIdx++]);
//				else
//					return false;
//			}
//			// 栈顶元素与出栈的元素相等，出栈
//			s.pop();
//			outIdx++;
//		}
//		return true;
//	}
//};
//
//class Solution {
//public:
//	int evalRPN(vector<string>& tokens) {
//		stack<int> s;
//		for (size_t i = 0; i < tokens.size(); ++i)
//			string& str = tokens[i];
//		// str为数字
//		if (!("+" == str || "-" == str || "*" == str || "/" == str))
//		{
//			s.push(atoi(str.c_str()));
//		}
//		else
//		{
//			// str为操作符
//			int right = s.top();
//			s.pop();
//			int left = s.top();
//			s.pop();
//			switch (str[0])
//			{
//			case '+':
//				s.push(left + right);
//				break;
//			case '-':
//				s.push(left - right);
//				break;
//			case '*':
//				s.push(left * right);
//				break;
//			case '/':
//				// 题目说明了不存在除数为0的情况
//				s.push(left / right);
//				break;
//			}
//		}
//	}
//	return s.top();
//}
//};

