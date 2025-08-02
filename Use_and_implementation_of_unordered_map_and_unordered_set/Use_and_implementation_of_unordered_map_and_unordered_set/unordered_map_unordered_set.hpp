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
			hash *= 31;
			hash += e;
		}
		return hash;
	}
};

namespace open_address
{
	enum State
	{
		EXIST,
		EMPTY,
		DELETE
	};

	template<class K, class V>
	struct HashData
	{
		pair<K, V> _kv;
		State _state = EMPTY;
	};


	template<class K, class V, class Hash = HashFunc<K>>
	class HashTable
	{
	public:
		HashTable()
		{
			_tables.resize(10);
		}

		bool Insert(const pair<K, V>& kv)
		{
			if (Find(kv.first))
				return false;

			// 扩容
			if (_n * 10 / _tables.size() >= 7)
			{

				//vector<HashData<K, V>> newTables(_tables.size() * 2);

				//// 遍历旧表， 将所有数据映射到新表

				//// ...

				//_tables.swap(newTables);
				HashTable<K, V, Hash> newHT;
				newHT._tables.resize(_tables.size() * 2);
				for (size_t i = 0; i < _tables.size(); i++)
				{
					if (_tables[i]._state == EXIST)
					{
						newHT.Insert(_tables[i]._kv);
					}
				}

				_tables.swap(newHT._tables);
			}

			Hash hs;
			size_t hashi = hs(kv.first) % _tables.size();
			while (_tables[hashi]._state == EXIST)
			{
				++hashi;
				hashi %= _tables.size();
			}

			_tables[hashi]._kv = kv;
			_tables[hashi]._state = EXIST;
			++_n;
			return true;
		}

		HashData<K, V>* Find(const K& key)
		{
			Hash hs;
			size_t hashi = hs(key) % _tables.size();
			while (_tables[hashi]._state != EMPTY)
			{
				if (_tables[hashi]._state == EXIST
					&& _tables[hashi]._kv.first == key)
				{
					return &_tables[hashi];
				}

				++hashi;
				hashi %= _tables.size();
			}

			return nullptr;
		}

		bool Erase(const K& key)
		{
			HashData<K, V>* ret = Find(key);
			if (ret == nullptr)
			{
				return false;
			}
			else
			{
				ret->_state = DELETE;
				return true;
			}
		}
	private:
		vector<HashData<K, V>> _tables;
		size_t _n = 0;  // 表中存储数据个数

	};


	// 对key为int的键值对测试
	void TestHT1()
	{
		HashTable<int, int> ht;
		int a[] = { 11,21,4,14,24,15,9 };
		for (auto e : a)
		{
			ht.Insert({ e,e });
		}

		ht.Insert({ 19,19 });
		ht.Insert({ 19,190 });
		ht.Insert({ 19,1900 });
		ht.Insert({ 39,1900 });

		cout << ht.Find(24) << endl;
		ht.Erase(4);
		cout << ht.Find(24) << endl;
		cout << ht.Find(4) << endl;
	}

	// 字符串转整形处理方式
	struct StringHashFunc
	{
		size_t operator()(const string& s)
		{
			size_t hash = 0;
			for (auto e : s)
			{
				hash *= 31;
				hash += e;
			}

			return hash;
		}
	};

	// 对key为string类型键值对进行测试
	void TestHT2()
	{
		HashTable<string, string> ht;
		ht.Insert({ "sort", "排序" });
		ht.Insert({ "left", "左边" });


		//string s1("sort");
		//string s2("sort");
		cout << StringHashFunc()("bacd") << endl;
		cout << StringHashFunc()("abcd") << endl;
		cout << StringHashFunc()("aadd") << endl;
	}
}