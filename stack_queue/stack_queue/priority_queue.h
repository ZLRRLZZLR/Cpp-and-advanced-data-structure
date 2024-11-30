#pragma once
#include<vector>
#include<iostream>

using namespace std;


namespace zlr

{


    template <class T, class Container = vector<T>, class Compare = less<T> >
    class priority_queue
    {
        void AdjustUp(int child)
        {
            int parent = (child - 1) / 2;
            while (child > 0)
            {
                if (_comp(_c[parent], _c[child]))
                {
                    swap(_c[parent], _c[child]);
                    child = parent;
                    parent = (child - 1) / 2;
                }
                else
                {
                    break;
                }
            }

        }

        void AdjustDown(int parent)
        {
            int child = parent * 2 + 1;

            while (child< _c.size())
            {
                if (child + 1 < _c.size() && _comp(_c[child], _c[child + 1]))
                {
                    ++child;
                }

                if (_comp(_c[parent], _c[child]))
                {
                    swap(_c[parent], _c[child]);
                    parent = child;
                    child = parent * 2 + 1;
                }

                else
                {
                    break;
                }
            }
        }

    public:



        priority_queue() = default;

        template <class InputIterator>
        priority_queue(InputIterator first, InputIterator last)
        {
            while(first != last)
            {
                push(*first);
                first++;
            }
        }

        bool empty() const
        {
            return _c.empty();
        }

        size_t size() const
        {
            return _c.size();
        }

        const T& top() const
        {
            return _c[0];
        }

        void push(const T& x)
        {
            _c.push_back(x);

            AdjustUp((int)_c.size() - 1);
        }

        void pop()
        {
            swap(_c[0], _c[_c.size() - 1]);
            _c.pop_back();

            AdjustDown(0);
        }

    private:

        Container _c;

        Compare _comp;

    };

    void TestPriority_queue()
    {
        priority_queue<int> p;

        cout << p.size();
        cout << p.empty();

        p.push(2);
        p.push(1);
        p.push(4);
        p.push(5);
        p.push(3);

        cout << p.size() << endl;
        int n = p.size();

        for(int i = 0;i < n;i++)
        {
            cout << p.top();
            p.pop();
        }

    }

};
