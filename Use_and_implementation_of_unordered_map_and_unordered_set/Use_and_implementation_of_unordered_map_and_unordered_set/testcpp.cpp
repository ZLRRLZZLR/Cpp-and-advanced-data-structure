
// MyUnorderedSet.h
namespace bit
{
	template<class K, class Hash = HashFunc<K>>
	class unordered_set
	{
		struct SetKeyOfT
		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};
	public:
		typedef typename hash_bucket::HashTable<K, const K, SetKeyOfT,
			Hash>::Iterator iterator;
		typedef typename hash_bucket::HashTable<K, const K, SetKeyOfT,
			Hash>::ConstIterator const_iterator;
		iterator begin()
		{
			return _ht.Begin();
		}
		iterator end()
		{
			return _ht.End();
		}
		const_iterator begin() const
		{
			return _ht.Begin();
		}
		const_iterator end() const
		{
			return _ht.End();
		}
		pair<iterator, bool> insert(const K& key)
		{
			return _ht.Insert(key);
		}
		iterator Find(const K& key)
		{
			return _ht.Find(key);
		}
		bool Erase(const K& key)
		{
			return _ht.Erase(key);
		}
	private:
		hash_bucket::HashTable<K, const K, SetKeyOfT, Hash> _ht;
	};
	void test_set()
	{
		unordered_set<int> s;
		int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14, 3,3,15 };
		for (auto e : a)
		{
			s.insert(e);
		}
		for (auto e : s)
		{
			cout << e << " ";
		}
		cout << endl;
		unordered_set<int>::iterator it = s.begin();
		while (it != s.end())
		{
			// 不支持修改
			//*it += 1;
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}
}
// MyUnorderedMap.h
namespace bit
{
	template<class K, class V, class Hash = HashFunc<K>>
	class unordered_map
	{
		struct MapKeyOfT
		{
			const K& operator()(const pair<K, V>& kv)
			{
				return kv.first;
			}
		};
	public:
		typedef typename hash_bucket::HashTable<K, pair<const K, V>,
			MapKeyOfT, Hash>::Iterator iterator;
		typedef typename hash_bucket::HashTable<K, pair<const K, V>,
			MapKeyOfT, Hash>::ConstIterator const_iterator;
		iterator begin()
		{
			return _ht.Begin();
		}
		iterator end()
		{
			return _ht.End();
		}
		const_iterator begin() const
		{
			return _ht.Begin();
		}
		const_iterator end() const
		{
			return _ht.End();
		}
		pair<iterator, bool> insert(const pair<K, V>& kv)
		{
			return _ht.Insert(kv);
		}
		V& operator[](const K& key)
		{
			pair<iterator, bool> ret = _ht.Insert(make_pair(key, V()));
			return ret.first->second;
		}
		iterator Find(const K& key)
		{
			return _ht.Find(key);
		}
		bool Erase(const K& key)
		{
			return _ht.Erase(key);
		}
	private:
		hash_bucket::HashTable<K, pair<const K, V>, MapKeyOfT, Hash> _ht;
	};
	void test_map()
	{
		unordered_map<string, string> dict;
		dict.insert({ "sort", "排序" });
		dict.insert({ "left", "左边" });
		dict.insert({ "right", "右边" });
		dict["left"] = "左边，剩余";
		dict["insert"] = "插入";
		dict["string"];
		unordered_map<string, string>::iterator it = dict.begin();
		while (it != dict.end())
		{
			// 不能修改first，可以修改second
			//it->first += 'x';
			it->second += 'x';
			cout << it->first << ":" << it->second << endl;
			++it;
		}
		cout << endl;
	}
}
// HashTable.h
template<class K>
struct HashFunc
{
	size_t operator()(const K& key)
	{
		return (size_t)key;
	}
};
// 特化
template<>
struct HashFunc<string>
{
	size_t operator()(const string& key)
	{
		size_t hash = 0;
		for (auto e : key)
		{
			hash *= 131;
			hash += e;
		}
		return hash;
	}
};
namespace hash_bucket
{
	template<class T>
	struct HashNode
	{
		T _data;
		HashNode<T>* _next;
		HashNode(const T& data)
			:_data(data)
			, _next(nullptr)
		{
		}
	};
	// 前置声明
	template<class K, class T, class KeyOfT, class Hash>
	class HashTable;
	template<class K, class T, class Ptr, class Ref, class KeyOfT, class Hash>
	struct HTIterator
	{
		typedef HashNode<T> Node;
		typedef HTIterator<K, T, Ptr, Ref, KeyOfT, Hash> Self;
		Node* _node;
		const HashTable<K, T, KeyOfT, Hash>* _pht;
		HTIterator(Node* node, const HashTable<K, T, KeyOfT, Hash>* pht)
			:_node(node)
			, _pht(pht)
		{
		}
		Ref operator*()
		{
			return _node->_data;
		}
		Ptr operator->()
		{
			return &_node->_data;
		}
		bool operator!=(const Self& s)
		{
			return _node != s._node;
		}
		Self& operator++()
		{
			if (_node->_next)
			{
				// 当前桶还有节点
				_node = _node->_next;
			}
			else
			{
				// 当前桶走完了，找下一个不为空的桶
				KeyOfT kot;
				Hash hs;
				size_t hashi = hs(kot(_node->_data)) % _pht -
> _tables.size();
++hashi;
while (hashi < _pht->_tables.size())
{
	if (_pht->_tables[hashi])
	{
		break;
	}
	++hashi;
}
if (hashi == _pht->_tables.size())
{
	_node = nullptr; // end()
}
else
{
	_node = _pht->_tables[hashi];
}
			}
			return *this;
		}
	};
	template<class K, class T, class KeyOfT, class Hash>
	class HashTable
	{
		// 友元声明
		template<class K, class T, class Ptr, class Ref, class KeyOfT, class
			Hash>
		friend struct HTIterator;
		typedef HashNode<T> Node;
	public:
		typedef HTIterator<K, T, T*, T&, KeyOfT, Hash> Iterator;
		typedef HTIterator<K, T, const T*, const T&, KeyOfT, Hash>
			ConstIterator;
		Iterator Begin()
		{
			if (_n == 0)
				return End();
			for (size_t i = 0; i < _tables.size(); i++)
			{
				Node* cur = _tables[i];
				if (cur)
				{
					return Iterator(cur, this);
				}
			}
			return End();
		}
		Iterator End()
		{
			return Iterator(nullptr, this);
		}
		ConstIterator Begin() const
		{
			if (_n == 0)
				return End();
			for (size_t i = 0; i < _tables.size(); i++)
			{
				Node* cur = _tables[i];
				if (cur)
				{
					return ConstIterator(cur, this);
				}
			}
			return End();
		}
		ConstIterator End() const
		{
			return ConstIterator(nullptr, this);
		}
		inline unsigned long __stl_next_prime(unsigned long n)
		{
			static const int __stl_num_primes = 28;
			static const unsigned long __stl_prime_list[__stl_num_primes] =
			{
				53, 97, 193, 389, 769,
				1543, 3079, 6151, 12289, 24593,
				49157, 98317, 196613, 393241, 786433,
				1572869, 3145739, 6291469, 12582917, 25165843,
				50331653, 100663319, 201326611, 402653189, 805306457,
				1610612741, 3221225473, 4294967291
			};
			const unsigned long* first = __stl_prime_list;
			const unsigned long* last = __stl_prime_list +
				__stl_num_primes;
			const unsigned long* pos = lower_bound(first, last, n);
			return pos == last ? *(last - 1) : *pos;
		}
		HashTable()
		{
			_tables.resize(__stl_next_prime(_tables.size()), nullptr);
		}
		~HashTable()
		{
			// 依次把每个桶释放
			for (size_t i = 0; i < _tables.size(); i++)
			{
				Node* cur = _tables[i];
				while (cur)
				{
					Node* next = cur->_next;
					delete cur;
					cur = next;
				}
				_tables[i] = nullptr;
			}
		}
		pair<Iterator, bool> Insert(const T& data)
		{
			KeyOfT kot;
			Iterator it = Find(kot(data));
			if (it != End())
				return make_pair(it, false);
			Hash hs;
			size_t hashi = hs(kot(data)) % _tables.size();
			// 负载因子==1扩容
			if (_n == _tables.size())
			{
				vector<Node*>
					newtables(__stl_next_prime(_tables.size() + 1), nullptr);
				for (size_t i = 0; i < _tables.size(); i++)
				{
					Node* cur = _tables[i];
					while (cur)
					{
						Node* next = cur->_next;
						// 旧表中节点，挪动新表重新映射的位置
						size_t hashi = hs(kot(cur->_data)) %
							newtables.size();
						// 头插到新表
						cur->_next = newtables[hashi];
						newtables[hashi] = cur;
						cur = next;
					}
					_tables[i] = nullptr;
				}
				_tables.swap(newtables);
			}
			// 头插
			Node* newnode = new Node(data);
			newnode->_next = _tables[hashi];
			_tables[hashi] = newnode;
			++_n;
			return make_pair(Iterator(newnode, this), true);
		}
		Iterator Find(const K& key)
		{
			KeyOfT kot;
			Hash hs;
			size_t hashi = hs(key) % _tables.size();
			Node* cur = _tables[hashi];
			while (cur)
			{
				if (kot(cur->_data) == key)
				{
					return Iterator(cur, this);
				}
				cur = cur->_next;
			}
			return End();
		}
		bool Erase(const K& key)
		{
			KeyOfT kot;
			Hash hs;
			size_t hashi = hs(key) % _tables.size();
			Node* prev = nullptr;
			Node* cur = _tables[hashi];
			while (cur)
			{
				if (kot(cur->_data) == key)
				{
					if (prev == nullptr)
					{
						_tables[hashi] = cur->_next;
					}
					else
					{
						prev->_next = cur->_next;
					}
					delete cur;
					--_n;
					return true;
				}
				prev = cur;
				cur = cur->_next;
			}
			return false;
		}
	private:
		vector<Node*> _tables; // 指针数组
		size_t _n = 0; // 表中存储数据个数
	};
}

//template <class Value, class Key, class HashFcn,
//	class ExtractKey, class EqualKey, class Alloc>
//struct __hashtable_iterator {
//	typedef hashtable<Value, Key, HashFcn, ExtractKey, EqualKey, Alloc>
//		hashtable;
//	typedef __hashtable_iterator<Value, Key, HashFcn,
//		ExtractKey, EqualKey, Alloc>
//		iterator;
//	typedef __hashtable_const_iterator<Value, Key, HashFcn,
//		ExtractKey, EqualKey, Alloc>
//		const_iterator;
//	typedef __hashtable_node<Value> node;
//	typedef forward_iterator_tag iterator_category;
//	typedef Value value_type;
//	node* cur;
//	hashtable* ht;
//	__hashtable_iterator(node* n, hashtable* tab) : cur(n), ht(tab) {}
//	__hashtable_iterator() {}
//	reference operator*() const { return cur->val; }
//#ifndef __SGI_STL_NO_ARROW_OPERATOR
//	pointer operator->() const { return &(operator*()); }
//#endif /* __SGI_STL_NO_ARROW_OPERATOR */
//	iterator& operator++();
//	iterator operator++(int);
//	bool operator==(const iterator& it) const { return cur == it.cur; }
//	bool operator!=(const iterator& it) const { return cur != it.cur; }
//};
//template <class V, class K, class HF, class ExK, class EqK, class A>
//__hashtable_iterator<V, K, HF, ExK, EqK, A>&
//__hashtable_iterator<V, K, HF, ExK, EqK, A>::operator++()
//{
//	const node* old = cur;
//	cur = cur->next;
//	if (!cur) {
//		size_type bucket = ht->bkt_num(old->val);
//		while (!cur && ++bucket < ht->buckets.size())
//			cur = ht->buckets[bucket];
//	}
//	return *this;
//}

//// MyUnorderedSet.h
//namespace bit
//{
//	template<class K, class Hash = HashFunc<K>>
//	class unordered_set
//	{
//		struct SetKeyOfT
//		{
//			const K& operator()(const K& key)
//			{
//				return key;
//			}
//		};
//	public:
//		bool insert(const K& key)
//		{
//			return _ht.Insert(key);
//		}
//	private:
//		hash_bucket::HashTable<K, K, SetKeyOfT, Hash> _ht;
//	};
//}
//// MyUnorderedMap.h
//namespace bit
//{
//	template<class K, class V, class Hash = HashFunc<K>>
//	class unordered_map
//	{
//		struct MapKeyOfT
//		{
//			const K& operator()(const pair<K, V>& kv)
//			{
//				return kv.first;
//			}
//		};
//	public:
//		bool insert(const pair<K, V>& kv)
//		{
//			return _ht.Insert(kv);
//		}
//	private:
//		hash_bucket::HashTable<K, pair<K, V>, MapKeyOfT, Hash> _ht;
//	};
//}
//// HashTable.h
//template<class K>
//struct HashFunc
//{
//	size_t operator()(const K& key)
//	{
//		return (size_t)key;
//	}
//};
//namespace hash_bucket
//{
//	template<class T>
//	struct HashNode
//	{
//		T _data;
//		HashNode<T>* _next;
//		HashNode(const T& data)
//			:_data(data)
//			, _next(nullptr)
//		{
//		}
//	};
//	// 实现步骤：
//	// 1、实现哈希表
//	// 2、封装unordered_map和unordered_set的框架 解决KeyOfT
//	// 3、iterator
//	// 4、const_iterator
//	// 5、key不支持修改的问题
//	// 6、operator[]
//	template<class K, class T, class KeyOfT, class Hash>
//	class HashTable
//	{
//		typedef HashNode<T> Node;
//		inline unsigned long __stl_next_prime(unsigned long n)
//		{
//			static const int __stl_num_primes = 28;
//			static const unsigned long __stl_prime_list[__stl_num_primes] =
//			{
//				53, 97, 193, 389, 769,
//				1543, 3079, 6151, 12289, 24593,
//				49157, 98317, 196613, 393241, 786433,
//				1572869, 3145739, 6291469, 12582917, 25165843,
//				50331653, 100663319, 201326611, 402653189, 805306457,
//				1610612741, 3221225473, 4294967291
//			};
//			const unsigned long* first = __stl_prime_list;
//			const unsigned long* last = __stl_prime_list + __stl_num_primes;
//			const unsigned long* pos = lower_bound(first, last, n);
//			return pos == last ? *(last - 1) : *pos;
//		}
//	public:
//		HashTable()
//		{
//			_tables.resize(__stl_next_prime(_tables.size()), nullptr);
//		}
//		~HashTable()
//		{
//			// 依次把每个桶释放
//			for (size_t i = 0; i < _tables.size(); i++)
//			{
//				Node* cur = _tables[i];
//				while (cur)
//				{
//					Node* next = cur->_next;
//					delete cur;
//					cur = next;
//				}
//				_tables[i] = nullptr;
//			}
//		}
//		bool Insert(const T& data)
//		{
//			KeyOfT kot;
//			if (Find(kot(data)))
//				return false;
//			Hash hs;
//			size_t hashi = hs(kot(data)) % _tables.size();
//			// 负载因子==1扩容
//			if (_n == _tables.size())
//			{
//				vector<Node*> newtables(__stl_next_prime(_tables.size()),
//					nullptr);
//				for (size_t i = 0; i < _tables.size(); i++)
//				{
//					Node* cur = _tables[i];
//					while (cur)
//					{
//						Node* next = cur->_next;
//						// 旧表中结点，挪动新表重新映射的位置
//						size_t hashi = hs(kot(cur->_data)) % newtables.size();
//						// 头插到新表
//						cur->_next = newtables[hashi];
//						newtables[hashi] = cur;
//						cur = next;
//					}
//					_tables[i] = nullptr;
//				}
//				_tables.swap(newtables);
//			}
//			// 头插
//			Node* newnode = new Node(data);
//			newnode->_next = _tables[hashi];
//			_tables[hashi] = newnode;
//			++_n;
//			return true;
//		}
//	private:
//		vector<Node*> _tables; // 指针数组
//		size_t _n = 0; // 表中存储数据个数
//	};
//}

//// stl_hash_set
//template <class Value, class HashFcn = hash<Value>,
//	class EqualKey = equal_to<Value>,
//	class Alloc = alloc>
//class hash_set
//{
//private:
//	typedef hashtable<Value, Value, HashFcn, identity<Value>,
//		EqualKey, Alloc> ht;
//	ht rep;
//public:
//	typedef typename ht::key_type key_type;
//	typedef typename ht::value_type value_type;
//	typedef typename ht::hasher hasher;
//	typedef typename ht::key_equal key_equal;
//	typedef typename ht::const_iterator iterator;
//	typedef typename ht::const_iterator const_iterator;
//	hasher hash_funct() const { return rep.hash_funct(); }
//	key_equal key_eq() const { return rep.key_eq(); }
//};
//// stl_hash_map
//template <class Key, class T, class HashFcn = hash<Key>,
//	class EqualKey = equal_to<Key>,
//	class Alloc = alloc>
//class hash_map
//{
//private:
//	typedef hashtable<pair<const Key, T>, Key, HashFcn,
//		select1st<pair<const Key, T> >, EqualKey, Alloc> ht;
//	ht rep;
//public:
//	typedef typename ht::key_type key_type;
//	typedef T data_type;
//	typedef T mapped_type;
//	typedef typename ht::value_type value_type;
//	typedef typename ht::hasher hasher;
//	typedef typename ht::key_equal key_equal;
//	typedef typename ht::iterator iterator;
//	typedef typename ht::const_iterator const_iterator;
//};
//// stl_hashtable.h
//template <class Value, class Key, class HashFcn,
//	class ExtractKey, class EqualKey,
//	class Alloc>
//class hashtable {
//public:
//	typedef Key key_type;
//	typedef Value value_type;
//	typedef HashFcn hasher;
//	typedef EqualKey key_equal;
//private:
//	hasher hash;
//	key_equal equals;
//	ExtractKey get_key;
//	typedef __hashtable_node<Value> node;
//	vector<node*, Alloc> buckets;
//	size_type num_elements;
//public:
//	typedef __hashtable_iterator<Value, Key, HashFcn, ExtractKey, EqualKey,
//		Alloc> iterator;
//	pair<iterator, bool> insert_unique(const value_type& obj);
//	const_iterator find(const key_type& key) const;
//};
//template <class Value>
//struct __hashtable_node
//{
//	__hashtable_node* next;
//	Value val;
//};

//pair<iterator, bool> insert(const value_type& val);
//size_type erase(const key_type& k);
//iterator find(const key_type& k);
//mapped_type& operator[] (const key_type& k);
//pair<iterator, bool> insert(const value_type& val);
//size_type erase(const key_type& k);
//iterator find(const key_type& k);
//#include<unordered_set>
//#include<unordered_map>
//#include<set>
//#include<iostream>
//using namespace std;
//int test_set2()
//{
//	const size_t N = 1000000;
//	unordered_set<int> us;
//	set<int> s;
//	vector<int> v;
//	v.reserve(N);
//	srand(time(0));
//	for (size_t i = 0; i < N; ++i)
//	{
//		//v.push_back(rand()); // N比较大时，重复值比较多
//		v.push_back(rand() + i); // 重复值相对少
//		//v.push_back(i); // 没有重复，有序
//	}
//	// 21:15
//	size_t begin1 = clock();
//	for (auto e : v)
//	{
//		s.insert(e);
//	}
//	size_t end1 = clock();
//	cout << "set insert:" << end1 - begin1 << endl;
//	size_t begin2 = clock();
//	us.reserve(N);
//	for (auto e : v)
//	{
//		us.insert(e);
//	}
//	size_t end2 = clock();
//	cout << "unordered_set insert:" << end2 - begin2 << endl;
//	int m1 = 0;
//	size_t begin3 = clock();
//	for (auto e : v)
//	{
//		auto ret = s.find(e);
//		if (ret != s.end())
//		{
//			++m1;
//		}
//	}
//	size_t end3 = clock();
//	cout << "set find:" << end3 - begin3 << "->" << m1 << endl;
//	int m2 = 0;
//	size_t begin4 = clock();
//	for (auto e : v)
//	{
//		auto ret = us.find(e);
//		if (ret != us.end())
//		{
//			++m2;
//		}
//	}
//	size_t end4 = clock();
//	cout << "unorered_set find:" << end4 - begin4 << "->" << m2 << endl;
//	cout << "插入数据个数：" << s.size() << endl;
//	cout << "插入数据个数：" << us.size() << endl << endl;
//	size_t begin5 = clock();
//	for (auto e : v)
//	{
//		s.erase(e);
//	}
//	size_t end5 = clock();
//	cout << "set erase:" << end5 - begin5 << endl;
//	size_t begin6 = clock();
//	for (auto e : v)
//	{
//		us.erase(e);
//	}
//	size_t end6 = clock();
//	cout << "unordered_set erase:" << end6 - begin6 << endl << endl;
//	return 0;
//}
//int main()
//{
//	test_set2();
//	return 0;
//}

//template < class Key, //
//	unordered_set::key_type / value_type
//	class Hash = hash<Key>, // unordered_set::hasher
//	class Pred = equal_to<Key>, // unordered_set::key_equal
//	class Alloc = allocator<Key> // unordered_set::allocator_type
//	> class unordered_set;