////enum State
////{
////	EXIST,
////	EMPTY,
////	DELETE
////};
////
////template<class K,class V>
////struct HashData
////{
////	pair<K, V> _kv;
////	State _state = EMPTY;
////};
////
////template<class K, class V>
////class HashTable
////{
////public:
////	HashTable()
////		:_table(__stl_next_prime(0))
////		, _n(0)
////	{}
////	inline unsigned long __stl_next_prime(unsigned long n)
////	{
////		// Note: assumes long is at least 32 bits.
////		static const int __stl_num_primes = 28;
////		static const unsigned long __stl_prime_list[__stl_num_primes] = {
////			53, 97, 193, 389, 769,
////			1543, 3079, 6151, 12289, 24593,
////			49157, 98317, 196613, 393241, 786433,
////			1572869, 3145739, 6291469, 12582917, 25165843,
////			50331653, 100663319, 201326611, 402653189, 805306457,
////			1610612741, 3221225473, 4294967291
////		};
////		const unsigned long* first = __stl_prime_list;
////		const unsigned long* last = __stl_prime_list + __stl_num_primes;
////		const unsigned long* pos = lower_bound(first, last, n);
////		return pos == last ? *(last - 1) : *pos;
////	}
////
////	bool Insert(const pair<K,V>& kv)
////	{
////		if (Find(kv.first))
////			return false;
////		if(_n*10 / _tables.size() >= 7)
////		{
////			HashTable<K, V> newht;
////			newht._table.resize(__stl_next_prime(_table.size() + 1));
////
////			for(auto& data : _tables)
////			{
////				if(data._state == EXIST)
////				{
////					newht.Insert(data._kv);
////				}
////			}
////		}
////
////		size_t hash0 = kv.first % _tables.size();
////		size_t hashi = hash0;
////		size_t i = 1;
////		int flag = 1;
////		while(_tables[hashi]._state == EXIST)
////		{
////			hashi = (hash0 + i) % _tables.size();
////			++i;
////		}
////
////		_tables[hashi]._kv = kv;
////		_tables[hashi]._state = EXIST;
////		++_n;
////
////		return true;
////	}
////
////	HashData<K,V>* Find(const K& key)
////	{
////		size_t hash0 = key % _table.size();
////		size_t hashi = hash0;
////		size_t i = 1;
////		while(_tables[hashi]._state == EMPTY)
////		{
////			if(_tables[hashi]._state == EXIST
////				&& _tables[hashi]._kv.first == key)
////			{
////				return &_tables[hashi];
////			}
////
////			hashi = (hash0 + i) % _tables.size();
////			++i;
////		}
////
////		return nullptr;
////	}
////
////	bool Erase(const K& key)
////	{
////		HashData<K, V>* ret = Find(key);
////		if(ret)
////		{
////			ret->_state == DELETE;
////		}
////		else
////		{
////			return false;
////		}
////	}
////private:
////	vector<HashData<K, V>> _tables;
////	size_t _n;
////
////};
//
//
//
////namespace hash_bucket
////{
////	template<class K, class V>
////	struct HashNode
////	{
////		pair<K, V> _kv;
////		HashNode<K, V>* _next;
////		HashNode(const pair<K, V>& kv)
////			:_kv(kv)
////			, _next(nullptr)
////		{
////		}
////	};
////	template<class K, class V, class Hash = HashFunc<K>>
////	class HashTable
////	{1	·1	`1	`1	`1	`1	`1	`1	`1	`1	`1	`1	`1	`1	`1	`1	`
////		typedef HashNode<K, V> Node;
////		inline unsigned long __stl_next_prime(unsigned long n)
////		{
////			static const int __stl_num_primes = 28;
////			static const unsigned long __stl_prime_list[__stl_num_primes] =
////			{
////				53, 97, 193, 389, 769,
////				1543, 3079, 6151, 12289, 24593,
////				49157, 98317, 196613, 393241, 786433,
////				1572869, 3145739, 6291469, 12582917, 25165843,
////				50331653, 100663319, 201326611, 402653189, 805306457,
////				1610612741, 3221225473, 4294967291
////			};
////			const unsigned long* first = __stl_prime_list;
////			const unsigned long* last = __stl_prime_list +
////				__stl_num_primes;
////			const unsigned long* pos = lower_bound(first, last, n);
////			return pos == last ? *(last - 1) : *pos;
////		}
////	public:
////		HashTable()
////		{
////			_tables.resize(__stl_next_prime(0), nullptr);
////		}
////		// 拷贝构造和赋值拷贝需要实现深拷贝，有兴趣的同学可以自行实现
////		~HashTable()
////		{
////			// 依次把每个桶释放
////			for (size_t i = 0; i < _tables.size(); i++)
////			{
////				Node* cur = _tables[i];
////				while (cur)
////				{
////					Node* next = cur->_next;
////					delete cur;
////					cur = next;
////				}
////				_tables[i] = nullptr;
////			}
////		}
////		bool Insert(const pair<K, V>& kv)
////		{
////			Hash hs;
////			size_t hashi = hs(kv.first) % _tables.size();
////			// 负载因子==1扩容
////			if (_n == _tables.size())
////			{
////				/*HashTable<K, V> newHT;
////				newHT._tables.resize(__stl_next_prime(_tables.size()+1);
////				for (size_t i = 0; i < _tables.size(); i++)
////				{
////					Node* cur = _tables[i];
////					while(cur)
////					{
////						newHT.Insert(cur->_kv);
////						cur = cur->_next;
////					}
////				}
////					_tables.swap(newHT._tables);*/
////					// 这里如果使用上面的方法，扩容时创建新的结点，后面还要使用就结点，浪费了
////					// 下面的方法，直接移动旧表的结点到新表，效率更好
////				vector<Node*>
////					newtables(__stl_next_prime(_tables.size() + 1), nullptr);
////				for (size_t i = 0; i < _tables.size(); i++)
////				{
////					Node* cur = _tables[i];
////					while (cur)
////					{
////						Node* next = cur->_next;
////						// 旧表中节点，挪动新表重新映射的位置
////						size_t hashi = hs(cur->_kv.first) % newtables.size();
////						// 头插到新表
////						cur->_next = newtables[hashi];
////						newtables[hashi] = cur;
////						cur = next;
////					}
////					_tables[i] = nullptr;
////				}
////				_tables.swap(newtables);
////			}
////			// 头插
////			Node* newnode = new Node(kv);
////			newnode->_next = _tables[hashi];
////			_tables[hashi] = newnode;
////			++_n;
////			return true;
////		}
////		Node* Find(const K& key)
////		{
////			Hash hs;
////			size_t hashi = hs(key) % _tables.size();
////			Node* cur = _tables[hashi];
////			while (cur)
////			{
////				if (cur->_kv.first == key)
////				{
////					return cur;
////				}
////				cur = cur->_next;
////			}
////			return nullptr;
////		}
////		bool Erase(const K& key)
////		{
////			Hash hs;
////			size_t hashi = hs(key) % _tables.size();
////			Node* prev = nullptr;
////			Node* cur = _tables[hashi];
////			while (cur)
////			{
////				if (cur->_kv.first == key)
////				{
////					if (prev == nullptr)
////					{
////						_tables[hashi] = cur->_next;
////					}
////					else
////					{
////						prev->_next = cur->_next;
////					}
////					delete cur;
////					--_n;
////					return true;
////				}
////				prev = cur;
////				cur = cur->_next;
////			}
////			return false;
////		}
////	private:
////		vector<Node*> _tables; // 指针数组
////		size_t _n = 0; // 表中存储数据个数
////	};
////}
////
//////namespace open_address
//////{
//////	enum State
//////	{
//////		EXIST,
//////		EMPTY,
//////		DELETE
//////	};
//////	template<class K, class V>
//////	struct HashData
//////	{
//////		pair<K, V> _kv;
//////		State _state = EMPTY;
//////	};
//////	template<class K, class V, class Hash = HashFunc<K>>
//////	class HashTable
//////	{
//////	public:
//////		inline unsigned long __stl_next_prime(unsigned long n)
//////		{
//////			// Note: assumes long is at least 32 bits.
//////			static const int __stl_num_primes = 28;
//////			static const unsigned long __stl_prime_list[__stl_num_primes] =
//////			{
//////				53, 97, 193, 389, 769,
//////				1543, 3079, 6151, 12289, 24593,
//////				49157, 98317, 196613, 393241, 786433,
//////				1572869, 3145739, 6291469, 12582917, 25165843,
//////				50331653, 100663319, 201326611, 402653189, 805306457,
//////				1610612741, 3221225473, 4294967291
//////			};
//////			const unsigned long* first = __stl_prime_list;
//////			const unsigned long* last = __stl_prime_list +
//////				__stl_num_primes;
//////			const unsigned long* pos = lower_bound(first, last, n);
//////			return pos == last ? *(last - 1) : *pos;
//////		}
//////		HashTable()
//////		{
//////			_tables.resize(__stl_next_prime(0));
//////		}
//////		bool Insert(const pair<K, V>& kv)
//////		{
//////			if (Find(kv.first))
//////				return false;
//////			// 负载因子大于0.7就扩容
//////			if (_n * 10 / _tables.size() >= 7)
//////			{
//////				// 这里利用类似深拷贝现代写法的思想插入后交换解决
//////				HashTable<K, V, Hash> newHT;
//////				newHT._tables.resize(__stl_next_prime(_tables.size() + 1));
//////				for (size_t i = 0; i < _tables.size(); i++)
//////				{
//////					if (_tables[i]._state == EXIST)
//////					{
//////						newHT.Insert(_tables[i]._kv);
//////					}
//////				}
//////				_tables.swap(newHT._tables);
//////			}
//////			Hash hash;
//////			size_t hash0 = hash(kv.first) % _tables.size();
//////			size_t hashi = hash0;
//////			size_t i = 1;
//////			while (_tables[hashi]._state == EXIST)
//////			{
//////				// 线性探测
//////				hashi = (hash0 + i) % _tables.size();
//////				// 二次探测就变成 +- i^2
//////				++i;
//////			}
//////			_tables[hashi]._kv = kv;
//////			_tables[hashi]._state = EXIST;
//////			++_n;
//////			return true;
//////		}
//////		HashData<K, V>* Find(const K& key)
//////		{
//////			Hash hash;
//////			size_t hash0 = hash(key) % _tables.size();
//////			size_t hashi = hash0;
//////			size_t i = 1;
//////			while (_tables[hashi]._state != EMPTY)
//////			{
//////				if (_tables[hashi]._state == EXIST
//////					&& _tables[hashi]._kv.first == key)
//////				{
//////					return &_tables[hashi];
//////				}
//////				// 线性探测
//////				hashi = (hash0 + i) % _tables.size();
//////				++i;
//////			}
//////			return nullptr;
//////		}
//////		bool Erase(const K& key)
//////		{
//////			HashData<K, V>* ret = Find(key);
//////			if (ret == nullptr)
//////			{
//////				return false;
//////			}
//////			else
//////			{
//////				ret->_state = DELETE;
//////				--_n;
//////				return true;
//////			}
//////		}
//////	private:
//////		vector<HashData<K, V>> _tables;
//////		size_t _n = 0; // 表中存储数据个数
//////	};
//////}
////
//////template<class K>
//////struct HashFunc
//////{
//////	size_t operator()(const K& key)
//////	{
//////		return (size_t)key;
//////	}
//////};
//////// 特化
//////template<>
//////struct HashFunc<string>
//////{
//////	// 字符串转换成整形，可以把字符ascii码相加即可
//////	// 但是直接相加的话，类似"abcd"和"bcad"这样的字符串计算出是相同的
//////	// 这里我们使用BKDR哈希的思路，用上次的计算结果去乘以一个质数，这个质数一般去31, 131
//////	等效果会比较好
//////		size_t operator()(const string& key)
//////	{
//////		size_t hash = 0;
//////		for (auto e : key)
//////		{
//////			hash *= 131;
//////			hash += e;
//////		}
//////		return hash;
//////	}
//////};
//////template<class K, class V, class Hash = HashFunc<K>>
//////class HashTable
//////{
//////public:
//////private:
//////	vector<HashData<K, V>> _tables;
//////	size_t _n = 0; // 表中存储数据个数
//////};
////
////
//////inline unsigned long __stl_next_prime(unsigned long n)
//////{
//////	// Note: assumes long is at least 32 bits.
//////	static const int __stl_num_primes = 28;
//////	static const unsigned long __stl_prime_list[__stl_num_primes] =
//////	{
//////		53, 97, 193, 389, 769,
//////		1543, 3079, 6151, 12289, 24593,
//////		49157, 98317, 196613, 393241, 786433,
//////		1572869, 3145739, 6291469, 12582917, 25165843,
//////		50331653, 100663319, 201326611, 402653189, 805306457,
//////		1610612741, 3221225473, 4294967291
//////	};
//////	const unsigned long* first = __stl_prime_list;
//////	const unsigned long* last = __stl_prime_list + __stl_num_primes;
//////	const unsigned long* pos = lower_bound(first, last, n);
//////	return pos == last ? *(last - 1) : *pos;
//////}
////
////
////////enum State
////////{
////////	EXIST,
////////	EMPTY,
////////	DELETE
////////};
////////template<class K, class V>
////////struct HashData
////////{
////////	pair<K, V> _kv;
////////	State _state = EMPTY;
////////};
////////template<class K, class V>
////////class HashTable
////////{
////////private:
////////	vector<HashData<K, V>> _tables;
////////	size_t _n = 0; // 表中存储数据个数
////////};
////
//////class Solution {
//////public:
//////	int firstUniqChar(string s) {
//////		// 每个字母的ascii码-'a'的ascii码作为下标映射到count数组，数组中存储出现的次数
//////		int count[26] = { 0 };
//////		// 统计次数
//////		for (auto ch : s)
//////		{
//////			count[ch - 'a']++;
//////		}
//////		for (size_t i = 0; i < s.size(); ++i)
//////		{
//////			if (count[s[i] - 'a'] == 1)
//////				return i;
//////		}
//////		return -1;
//////	}
//////};