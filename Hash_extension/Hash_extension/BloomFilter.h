#pragma once
#include<string>
#include"BitSet.h"

struct HashFuncBKDR
{
	// @detail 本 算法由于在Brian Kernighan与Dennis Ritchie的《The CProgramming Language》
	// 一书被展示而得 名，是一种简单快捷的hash算法，也是Java目前采用的字符串的Hash算法累乘因子为31。
	size_t operator()(const std::string& s)
	{
		size_t hash = 0;
		for (auto ch : s)
		{
			hash *= 31;
			hash += ch;
		}
		return hash;
	}
};


struct HashFuncAP
{
	// 由Arash Partow发明的一种hash算法。  
	size_t operator()(const std::string& s)
	{
		size_t hash = 0;
		for (size_t i = 0; i < s.size(); i++)
		{
			if ((i & 1) == 0) // 偶数位字符
			{
				hash ^= ((hash << 7) ^ (s[i]) ^ (hash >> 3));
			}
			else              // 奇数位字符
			{
				hash ^= (~((hash << 11) ^ (s[i]) ^ (hash >> 5)));
			}
		}

		return hash;
	}
};

struct HashFuncDJB
{
	// 由Daniel J. Bernstein教授发明的一种hash算法。 
	size_t operator()(const std::string& s)
	{
		size_t hash = 5381;
		for (auto ch : s)
		{
			hash = hash * 33 ^ ch;
		}

		return hash;
	}
};

template<size_t N,size_t X = 5,class K = std::string, 
	class Hash1 = HashFuncBKDR,
	class Hash2 = HashFuncAP,
	class Hash3 = HashFuncDJB>
class BloomFilter
{
public:
	void Set(const K& key)
	{
		size_t hash1 = Hash1()(key) % M;
		size_t hash2 = Hash2()(key) % M;
		size_t hash3 = Hash3()(key) % M;

		_bs.set(hash1);
		_bs.set(hash2);
		_bs.set(hash3);
	}

	bool Test(const K& key)
	{
		size_t hash1 = Hash1()(key) % M;
		if(!_ba.test(hash1))
		{
			return false;
		}
		
		size_t hash2 = Hash2()(key) % M;
		if(!_bs.test(hash2))
		{
			return false;
		}

		size_t hash3 = Hash3()(key) % M;
		if(!_bs.test(hash3))
		{
			return false;
		}

		return true;
	}

	double getFalseProbaility()
	{
		double p = pow(1.0 - pow(2.7, -3.0 / X), 3.0);

		return p;
	}
private:
	static const size_t M = N * X;
	bit::bitset<M> _bs;
};