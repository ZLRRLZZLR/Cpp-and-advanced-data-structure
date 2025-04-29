#pragma
#include<iostream>
#include<vector>

using namespace std;

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
		~HashTable()
		{
			int n = _tables.size();
			for (int i = 0; i < n; i++)
			{
				Node* next = nullptr;
				Node* cur = _tables[i];
				while (cur)
				{
					next = cur->_next;
					delete cur;
					cur = next;
				}
				_tables[i] = nullptr;
			}
		}

		// 插入值为data的元素，如果data存在则不插入
		bool Insert(const T& data)
		{
			if (Find(data)) return false;
			else
			{
				if (_n / _tables.size() >= 1)
				{
					HashTable newHashtable.resize(_tables.size() * 2 + 1);
					int n = _tables.size();
					for (int i = 0; i < n; i++)
					{
						Node* cur = _tables[i];
						while (cur)
						{
							newHashtable.Insert(cur->_data);
							cur = cur->_next;
						}
					}
					_tables.swap(newHashtable._tables);
				}
				KeyOfT kt;
				Hash hash;
				int hash0 = hash(kt(data)) % _tables.size();
				Node* newnode = new Node(data);
				newnode->_next = _tables[hash0];
				_tables[hash0] = newnode;
				_n++;
				return true;
			}
		}

		// 在哈希桶中查找值为key的元素，存在返回true否则返回false﻿
		bool Find(const K& key)
		{
			Hash hash;
			int hash0 = hash(key) % _tables.size();
			Node* cur = _tables[hash0];
			while (cur)
			{
				if (kt(cur->_data) == key) return true;
				cur = cur->_next;
			}
			return false;
		}

		// 哈希桶中删除key的元素，删除成功返回true，否则返回false
		bool Erase(const K& key)
		{
			if (!Find(key)) return false;
			else
			{
				Hash hash;
				int hash0 = hash(key) % _tables.size();
				Node* prev = nullptr;
				Node* cur = _tables[hash0];
				while (cur)
				{
					if (kt(cur->_data) == key) break;
					prev = cur;
					cur = cur->next;
				}
				if (prev == nullptr)
				{
					_tables[hash0] = cur->_next;
				}
				else
				{
					prev->_next = cur->_next;
				}
				delete cur;
				--_n;
				return true;
			}
		}

	private:
		vector<Node*> _tables;  // 指针数组
		size_t _n = 0;			// 表中存储数据个数
	};
}
