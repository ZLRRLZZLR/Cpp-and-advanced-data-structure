#pragma once
#include<iostream>
using namespace std;


//模拟实现vector类，并完成测试

namespace bit
{
    template<class T>
    class vector
    {
    public:

        // Vector的迭代器是一个原生指针

        typedef T* iterator；

        typedef const T* const_iterator；

            iterator begin() 
        {
            return _start;
        }

            iterator end()
            {
                return _finish;
            }

            const_iterator cbegin() const
            {
                return _start
            }

            const_iterator cend() const
            {
                return _finish;
            }

            // construct and destroy

            vector() = default;

            vector(int n, const T& value = T())
            {
                reserve(n);

                for(int i = 0;i < n;i++)
                {
                    push_back(value);
                }

            }

            template<class InputIterator>
            vector(InputIterator first, InputIterator last)
            {
                while(first != last)
                {
                    push_back(*first);
                    ++_finish;
                }
            }

            vector(const vector<T>& v)
            {
                reserve(v.size());

                for (int i = 0; i < v.size(); i++)
                {
                    push_back(v[i]);
                }

            }

            vector<T>& operator= (vector<T> v)
            {
                swap(v);

                return *this;
            }

            ~vector()
            {
                delete[] _start;

                _start = _finish = _end_of_storage;
            }

            // capacity

            size_t size() const
            {
                return _finish - _start;
            }

            size_t capacity() const 
            {
                return _end_of_storage - _start;
            }

            void reserve(size_t n)
            {
                if(n > capacity())
                {
                    size_t old_size = _finish - _start;
                    T* tmp = new T * [size() == 0 ? 4 : n * sizeof(T)];
                    for(int i = 0;i < old_size,i++)
                    {
                        tmp[i] = _start[i];
                    }

                    _start = tmp;
                    _finish = _start + old_size;
                    _end_of_storage = _start + n;
                }
            }

            void resize(size_t n, const T& value = T())
            {
                if(n > size())
                {
                    reserve(n);

                    for(int i = size() - 1; i < n;i++)
                    {
                        push_back(value);
                    }

                }
            }



            ///////////////access///////////////////////////////

                T& operator[](size_t pos) 
            {
                assert(pos >= 0 && pos < size())

                return _start[pos];
            }

            const T& operator[](size_t pos)const 
            {
                assert(pos >= 0 && pos < size())

                    return _start[pos];
            }



            ///////////////modify/////////////////////////////

            void push_back(const T& x)
            {
                if(_finish = _end_of_storage)
                {
                    reserve()
                }
            }

            void pop_back()
            {
                assert(size() != 0);

                _finish--;
            }

            void swap(vector<T>& v)
            {
                std::swap(_start, v._start);
                std::swap(_finish, v._finish);
                std::swap(_end_of_storage, v._end_of_storage);
            }

            iterator insert(iterator pos, const T& x)
            {
                if(_end_of_stage)
            }

            iterator erase(Iterator pos)；

    private:

        iterator _start = nullptr; // 指向数据块的开始

        iterator _finish = nullptr; // 指向有效数据的尾

        iterator _end_of_storage = nullptr; // 指向存储容量的尾

    };

}
