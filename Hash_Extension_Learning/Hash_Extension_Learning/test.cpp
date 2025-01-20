
//// 模拟位图找交集
//void test_bitset1()
//{
//	int a1[] = { 5,7,9,2,5,99,5,5,7,5,3,9,2,55,1,5,6 };
//	int a2[] = { 5,3,5,99,6,99,33,66 };
//	bitset<100> bs1;
//	bitset<100> bs2;
//	for (auto e : a1)
//	{
//		bs1.set(e);
//	}
//	for (auto e : a2)
//	{
//		bs2.set(e);
//	}
//	for (size_t i = 0; i < 100; i++)
//	{
//		if (bs1.test(i) && bs2.test(i))
//		{
//			cout << i << endl;
//		}
//	}
//}
//template<size_t N>
//class twobitset
//{
//public:
//	void set(size_t x)
//	{
//		bool bit1 = _bs1.test(x);
//		bool bit2 = _bs2.test(x);
//		if (!bit1 && !bit2) // 00->01
//		{
//			_bs2.set(x);
//		}
//		else if (!bit1 && bit2) // 01->10
//		{
//			_bs1.set(x);
//			_bs2.reset(x);
//		}
//		else if (bit1 && !bit2) // 10->11
//		{
//			_bs1.set(x);
//			_bs2.set(x);
//		}
//	}
//	// 返回0 出现0次数
//	// 返回1 出现1次数
//	// 返回2 出现2次数
//	// 返回3 出现2次及以上
//	int get_count(size_t x)
//	{
//		bool bit1 = _bs1.test(x);
//		bool bit2 = _bs2.test(x);
//		if (!bit1 && !bit2)
//		{
//			return 0;
//		}
//		else if (!bit1 && bit2)
//		{
//			return 1;
//		}
//		else if (bit1 && !bit2)
//		{
//			return 2;
//		}
//		else
//		{
//			return 3;
//		}
//	}
//private:
//	bitset<N> _bs1;
//	bitset<N> _bs2;
//};
//};
//void test_bitset2()
//{
//	bit::twobitset<100> tbs;
//	int a[] = { 5,7,9,2,5,99,5,5,7,5,3,9,2,55,1,5,6,6,6,6,7,9 };
//	for (auto e : a)
//	{
//		tbs.set(e);
//	}
//	for (size_t i = 0; i < 100; ++i)
//	{
//		//cout << i << "->" << tbs.get_count(i) << endl;
//		if (tbs.get_count(i) == 1 || tbs.get_count(i) == 2)
//		{
//			cout << i << endl;
//		}
//	}
//}

//namespace bit
//{
//	// N是需要多少比特位
//	template<size_t N>
//	class bitset
//	{
//	public:
//		bitset()
//		{
//			//_bits.resize(N/32+1, 0);
//			_bits.resize((N >> 5) + 1, 0);
//		}
//		// 把x映射的位标记成1
//		void set(size_t x)
//		{
//			size_t i = x / 32;
//			size_t j = x % 32;
//			_bits[i] |= (1 << j);
//		}
//		// 把x映射的位标记成0
//		void reset(size_t x)
//		{
//			size_t i = x / 32;
//			size_t j = x % 32;
//			_bits[i] &= ~(1 << j);
//		}
//		bool test(size_t x)
//		{
//			size_t i = x / 32;
//			size_t j = x % 32;
//			return _bits[i] & (1 << j);
//		}
//	private:
//		vector<int> _bits;
//	};
//}
//int main()
//{
//	bit::bitset<100> bs1;
//	bs1.set(50);
//	bs1.set(30);
//	bs1.set(90);
//	for (size_t i = 0; i < 100; i++)
//	{
//		if (bs1.test(i))
//		{
//			cout << i << "->" << "在" << endl;
//		}
//		else
//		{
//			cout << i << "->" << "不在" << endl;
//		}
//	}
//	bs1.reset(90);
//	bs1.set(91);
//	cout << endl << endl;
//	for (size_t i = 0; i < 100; i++)
//	{
//		if (bs1.test(i))
//		{
//			cout << i << "->" << "在" << endl;
//		}
//		else
//		{
//			cout << i << "->" << "不在" << endl;
//		}
//	}
//	// 开2^32个位的位图
//	//bit::bitset<-1> bs2;
//	//bit::bitset<UINT_MAX> bs3;
//	//bit::bitset<0xffffffff> bs4;
//	return 0;
//}