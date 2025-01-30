
// ReverseIterator.h
// 所有容器的反向迭代器
// 迭代器适配器
namespace bit
{
	template<class Iterator, class Ref, class Ptr>
	struct ReverseIterator
	{
		typedef ReverseIterator<Iterator, Ref, Ptr> Self;
		// 正向迭代器
		Iterator _it;
		ReverseIterator(Iterator it)
			:_it(it)
		{
		}
		Ref operator*()
		{
			Iterator tmp = _it;
			return *(--tmp);
		}
		Ptr operator->()
		{
			return &(operator*());
		}
		Self& operator++()
		{
			--_it;
			return *this;
		}
		Self& operator--()
		{
			++_it;
			return *this;
		}
		Self operator++(int)
		{
			Self tmp(*this);
			--_it;
			return tmp;
		}
		Self operator--(int)
		{
			Self tmp(*this);
			--_it;
			return tmp;
		}
		bool operator!=(const Self& s) const
		{
			return _it != s._it;
		}
		bool operator==(const Self& s) const
		{
			return _it != s._it;
		}
	};
}
// vector.h
#include"ReverseIterator.h"
namespace bit
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
		typedef ReverseIterator<iterator, T&, T*> reverse_iterator;
		typedef ReverseIterator<const_iterator, const T&, const T*>
			const_reverse_iterator;
		reverse_iterator rbegin()
		{
			return reverse_iterator(end());
		}
		reverse_iterator rend()
		{
			return reverse_iterator(begin());
		}
		const_reverse_iterator rbegin() const
		{
			return const_reverse_iterator(end());
		}
		const_reverse_iterator rend() const
		{
			return const_reverse_iterator(begin());
		}
		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}
		const_iterator begin() const
		{
			return _start;
		}
		const_iterator end() const
		{
			return _finish;
		}
		// ....
	private:
		iterator _start = nullptr;
		iterator _finish = nullptr;
		iterator _endofstorage = nullptr;
	};
}
// list.h
#include"ReverseIterator.h"
namespace bit
{
	template<class T>
	class list
	{
		typedef ListNode<T> Node;
	public:
		typedef ListIterator<T, T&, T*> iterator;
		typedef ListIterator<T, const T&, const T*> const_iterator;
		typedef ReverseIterator<iterator, T&, T*> reverse_iterator;
		typedef ReverseIterator<const_iterator, const T&, const T*>
			const_reverse_iterator;
		reverse_iterator rbegin()
		{
			return reverse_iterator(end());
		}
		reverse_iterator rend()
		{
			return reverse_iterator(begin());
		}
		const_reverse_iterator rbegin() const
		{
			return const_reverse_iterator(end());
		}
		const_reverse_iterator rend() const
		{
			return const_reverse_iterator(begin());
		}
		iterator begin()
		{
			return _head->_next;
		}
		iterator end()
		{
			return _head;
		}
		const_iterator begin() const
		{
			return _head->_next;
		}
		const_iterator end() const
		{
			return _head;
		}
		// ...
	private:
		Node* _head;
		size_t _size;
	};
}
// test.cpp
#include"list.h"
#include"vector.h"
int main()
{
	bit::list<int> lt = { 1,2,3,4 };
	bit::list<int>::reverse_iterator rit = lt.rbegin();
	while (rit != lt.rend())
	{
		//*rit = 1;
		cout << *rit << " ";
		++rit;
	}
	cout << endl;
	return 0;
}
//int main()
//{
// bit::vector<int> v = { 1,2,3,4 };
// bit::vector<int>::reverse_iterator rit = v.rbegin();
// while (rit != v.rend())
// {
// //*rit = 1;
// cout << *rit << " ";
// ++rit;
// }
// cout << endl;
//
// return 0;
//}

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
//		: current(x) {
//	}
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
//				//前运算符入栈
//					// 2、如果栈不为为空且比栈顶运算符优先级低或相等，说明栈顶的运算符
//					//可以运算了，
//					// 输出栈顶运算符，当前运算符继续走前面遇到运算符的逻辑
//				if (st.empty() || operatorPrecedence(s[i]) >
//					operatorPrecedence(st.top()))
//				{
//					st.push(s[i]);
//					++i;
//				}
//				else
//				{
//					v.push_back(string(1, st.top()));
//					st.pop();
//				}
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
//	//}, { '/', 2 } };
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
//				//前运算符入栈
//					// 2、如果栈不为为空且比栈顶运算符优先级低或相等，说明栈顶的运算符
//					//可以运算了，
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