#include"HashTable.h"
using namespace hash_bucket;

namespace bit
{
	template<class K>
	struct DefHashF
	{
		size_t operator()(K data)
		{
			return (size_t)data;
		}
	};
	// unordered_map中存储的是pair<K, V>的键值对，K为key的类型，V为value的类型，HF哈希函数类型
	// unordered_map在实现时，只需将hashbucket中的接口重新封装即可
	template<class K, class V, class HF = DefHashF<K>>
	class unordered_map
	{
		// 通过key获取value的操作
		struct KeyOfValue
		{
			const K& operator()(const pair<K,V>& kv)
			{
				return kv.first;
			}
		};

		typedef HashBucket<K, pair<const K, V>, KeyOfValue, HF> HT;
	public:
		typedef typename HT::HTIterator iterator;
		typedef typename HT::ConstHTIterator iterator;

	public:
		unordered_map() : _ht()
		{
		}
		////////////////////////////////////////////////////
		iterator begin() { return _ht.begin() };
		iterator end() { return _ht.end() };
		////////////////////////////////////////////////////////////
		// capacity
		size_t size()const { return _ht.size() };
		bool empty()const { return _ht.empty() };
		///////////////////////////////////////////////////////////
		// Acess
		V& operator[](const K& key)
		{
			pair<iterator，bool> ret = insert({ key,V() });
			return ret.first->second;
		}

		const V& operator[](const K& key)const
		{
			pair<iterator，bool> ret = insert({ key,V() });
			return (const)ret.first->second;
		}
		//////////////////////////////////////////////////////////
		// lookup
		iterator find(const K& key) { return _ht.Find(key) };
		/////////////////////////////////////////////////
		// modify
		pair<iterator, bool> insert(const pair<K, V>& valye)
		{
			return _ht.insert(valye);
		}


		iterator erase(const K& key)
		{
			return _ht.Erase(key);
		}

	private:
		HT _ht;
	};
}
