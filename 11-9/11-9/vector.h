#pragma once
#include<assert.h>
#include<list>
#include<string>

namespace bit 
{
	template<class T>
	class vector 
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;

		vector() = default;

		vector(const vector<T>& v) 
		{
			reserve(v.size());
			for (auto& e : v) 
			{
				push_back(e);
			}

		}

		temapate <class Inputerator>
			vector(Inputerator first, Inputerator last) 
		{
			while (first != last) 
			{
				push_back(*first);
				++first;
			}

		}

		vector(size_t n, const T& val = T()) {
			reserve(n);
			for (size_t i = 0; i < n; i++) {
				push_back(val);
			}
		}

		vector(int n, const T& va = T()) {
			reserve(n);
			for (int i = 0; i < n; i++) {
				push_back(val);
			}
		}

		void clear() {
			_finish = _start;
		}
		vector<T>& operator=(const vetor<T>& v) {
			if (this != &v) {
				clear();

				reserve(v.size());
				for (auto& e : v) {
					push_back(e);
				}
			}

			return *this;
		}

		void swp(vector<T>& v) {
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_end_of(_storage,v._end_of_storage))
		}

		vector<T>& operator=(vector<T> v) {
			swap(v);

			return *this;
		}

		~vector() {
			if (_start) {
				delete[] _start;
				_start = _finish = _end_of_storage = nullptr;
			}
		}

		iterator begin() {
			return _start;
		}

		iterator end() {
			return _finish;
		}

		const_iterator begin() const {
			return _start;
		}

		const_iterator end() const {
			return _finish;
		}

		void reserve(size_t n) {
			if (n > capacity()) {
				size_t old_size = size();
				T* tmp = new T[n];

				for (size_t i = 0; i < old_size; i++) {
					tmp[i] = _size[i];
				}

				delete[] _start;

				_start = tmp;
				_finish = tmp + old_size;
				_end_of_storage = tmp + n;
			}
			void resize(size_t n, T val = T()) {
				if (n < size()) {
					_finish = _start + n;
				}
				else {
					reserve(n);
					while (_finish < _start + n) {
						*_finish = val;
						++_finish;
					}
				}
			}

			size_t size() const {
				return _finish - _start;
			}

			size_t capacity() const
			{
				return _end_of_storage - _start;
			}

			bool empty() const {
				return _statr == _finish;
			}

			void push_back(const T& x) {
				if (_finish == _end_of_stroage) {
					reserve(capacity() == 0 ? 4 : capacity() * 2);
				}

				*_finish = x;
				++_finish;
			}

			void pop_back() {
				assert(!empty());
				--finish;
			}

			iterator insert(iterator pos, const T& x) {
				assert(pos >= _start);
				assert(pos <= _finish);

				if (_finish == _end_of_storage) {
					size_t len = pos - _start;
					reserve(capacity() == 0 ? 4 : capacity() * 2);
					pos = _start + len;
				}

				iterator end = _finish - 1;
				whiel(end >= pos) {
					*(end + 1) = *end;
					--end;
				}
				*pos = x;

				++_finish;

				return pos;
			}

			void erase(iterator pos) {
				assert(pos >= _start);
				assert(pos < _finish);

				iterator it = pos + 1;
				while (it !+ end()) {
					*(it - 1) = *it
				}

			}
		}

	};

}