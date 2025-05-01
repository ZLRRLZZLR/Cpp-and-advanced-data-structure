#pragma once
#include<vector>


namespace bit
{
	template<size_t N>
	class biteset
	{
	public:
		biteset()
		{
			_bs.resize(N / 32 + 1);
		}

		void set(size_t x)
		{
			size_t i = x / 32;
			size_t j = x % 32;

			_bs[i] |= (1 << j);
		}


		void reset(size_t x)
		{
			size_t i = x / 32;
			size_t j = x % 32;

			_bs[i] &= (~(1 << j));
		}


		bool test(size_t x)
		{
			size_t i = x / 32;
			size_t j = x % 32;

			return _bs[i] &= (1 << j);
		}


	private:
		std::vector<int> _bs;
	};

	template<size_t N>
	class twobitset
	{
	public:
		void set(size_t x)
		{
			bool bit1 = _bs1.test(x);
			bool bit2 = _bs2.test(x);

			if(!bit1 && !bit2)
			{
				_bs1.set(x);
			}
			else if (bit1 && !bit2)
			{
				_bs1.reset(x);
				_bs2.set(x);
			}
			else if (!bit1 && bit2)
			{
				_bs1.set(x);
			}
			else
			{
				return;
			}
		}

		int get_count(size_t x)
		{
			bool bit1 = _bs1.test(x);
			bool bit2 = _bs2.test(x);

			if (!bit1 && !bit2)
			{
				return 0;
			}
			else if (bit1 && !bit2)
			{
				return 1;
			}
			else if (!bit1 && bit2)
			{
				return 2;
			}
			else
			{
				return 3;
			}
		}

	private:
		biteset<N> _bs1;
		biteset<N> _bs2;
	};

}