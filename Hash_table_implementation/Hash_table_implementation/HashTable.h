
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


	// K 为 T 中key的类型
	// T 可能是键值对，也可能是K
	// KeyOfT: 从T中提取key
	// Hash将key转化为整形，因为哈市函数使用除留余数法
	template<class K, class T, class KeyOfT, class Hash>
	class HashTable
	{

		typedef HashNode<T> Node;
	public:
		HashTable()
		{
			_tables.resize(10, nullptr);
		}

		// 哈希桶的销毁
		~HashTable();

		// 插入值为data的元素，如果data存在则不插入
		bool Insert(const T& data);

		// 在哈希桶中查找值为key的元素，存在返回true否则返回false﻿
		bool Find(const K& key);

		// 哈希桶中删除key的元素，删除成功返回true，否则返回false
		bool Erase(const K& key);

	private:
		vector<Node*> _tables;  // 指针数组
		size_t _n = 0;			// 表中存储数据个数
	};
}


//#include<iostream>
//#include<vector>
//#include<string>
//
//using namespace std;
//
//// 请完成哈希表的如下操作
//// 哈希函数采用除留余数法﻿
//template<class K>
//struct HashFunc
//{
//	size_t operator()(const K& key)
//	{
//		return (size_t)key;
//	}
//};
//
//// 哈希表中支持字符串的操作
//template<>
//struct HashFunc<string>
//{
//	size_t operator()(const string& key)
//	{
//		size_t hash = 0;
//		for (auto e : key)
//		{
//			hash *= 31;
//			hash += e;
//		}
//
//		return hash;
//	}
//};
//
//// 以下采用开放定址法，即线性探测解决冲突
//namespace open_address
//{
//	enum State
//	{
//		EXIST,
//		EMPTY,
//		DELETE
//
//	};
//
//	template<class K, class V>
//	struct HashData
//	{
//		pair<K, V> _kv;
//		State _state = EMPTY;
//	};
//
//	template<class K, class V, class Hash = HashFunc<K>>
//	class HashTable
//	{
//	public:
//		HashTable()
//		{
//			_tables.resize(10);
//		}
//
//		bool Insert(const pair<K, V>& kv)
//		{
//			if (Find(kv.first) == nullptr)
//			{
//				int factor = _n * 10 / _tables.size();
//				if (factor >= 7)
//				{
//					HashTable<K, V, Hash> newtHash;//现代写法
//					newtHash._tables.resize(_tables.size() * 2 + 1);
//					for (auto ch : _tables)
//					{
//						if (ch._state == EXIST)
//							newtHash.Insert(ch._kv);
//					}
//					_tables.swap(newtHash._tables);
//				}
//				//因子达标，直接插入
//				Hash hash;
//				int hash0 = hash(kv.first) % _tables.size();
//				int i = 1;
//				int hash1 = hash0;
//				while (_tables[hash1]._state == EXIST)//找到空位置
//				{
//					hash1 = (hash0 + i) % _tables.size();
//					i++;
//				}
//				_tables[hash1]._kv = kv;
//				_tables[hash1]._state = EXIST;
//				_n++;
//				return true;
//			}
//			else
//			{
//				return false;
//			}
//		}
//
//		HashData<K, V>* Find(const K& key)
//		{
//			Hash hash;
//			int hash0 = hash(key) % _tables.size();
//			int i = 1;
//			int hash1 = hash0;
//			while (_tables[hash1]._state == EXIST)//找到
//			{
//				if (_tables[hash1]._state == EXIST
//					&& _tables[hash1]._kv.first == key)
//				{
//					return &_tables[hash1];
//				}
//				hash1 = (hash0 + i) % _tables.size();
//				i++;
//			}
//			return nullptr;
//		}
//
//		bool Erase(const K& key)
//		{
//			HashData<K, V>* act = Find(key);
//			if (act != nullptr)
//			{
//				act._state = DELETE;
//				--_n;
//				return true;
//			}
//			else
//			{
//				return false;
//			}
//		}
//
//	private:
//		vector<HashData<K, V>> _tables;
//		size_t _n = 0;  // 表中存储数据个数
//	};
//}
//
//using namespace open_address;
//
//// 实现完成后，请对整形 和 字符串完成测试
//int main()
//{
//	// 测试使用字符串作为键的哈希表
//	HashTable<std::string, int> stringHashTable;
//	stringHashTable.Insert({ "apple", 1 });
//	stringHashTable.Insert({ "banana", 2 });
//	stringHashTable.Insert({"cherry", 3});
//
//	int stringValue;
//	if (stringHashTable.Find("banana"))
//	{
//		std::cout << "Found key 'banana', value: " << std::endl;
//	}
//	else 
//	{
//		std::cout << "Key 'banana' not found." << std::endl;
//	}
//
//	// 测试使用整数作为键的哈希表
//	HashTable<int, int> intHashTable;
//	intHashTable.Insert({ 1, 100 });
//	intHashTable.Insert({ 2, 200 });
//	intHashTable.Insert({ 3, 300 });
//
//	int intValue;
//	if (intHashTable.Find(2))
//	{
//		std::cout << "Found key 2, value: " << std::endl;
//	}
//	else 
//	{
//		std::cout << "Key 2 not found." << std::endl;
//	}
//
//	return 0;
//}