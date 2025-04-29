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

	// unordered_set中存储的是K类型，HF哈希函数类型
	// unordered_set在实现时，只需将hashbucket中的接口重新封装即可
	template<class K, class HF = DefHashF<K>>
	class unordered_set
	{
		typedef HashBucket<K, K, KeyOfValue, HF> HT;
		// 通过key获取value的操作
		struct KeyOfValue

	public:
		typename typedef HT::Iterator iterator;
	public:
		unordered_set() : _ht()
		{
		}
		////////////////////////////////////////////////////
		iterator begin() { return _ht.begin() };
		iterator end() { return _ht.end() };
		////////////////////////////////////////////////////////////
		// capacity
		size_t size()const { return _ht.size() };
		bool empty()const { return _ht.empty() };
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
