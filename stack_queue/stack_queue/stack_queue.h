#pragma once
#include<queue>
#include<assert.h>
#include<iostream>
using namespace std;



namespace zlr

{

    template<class T, class Con = deque<T>>
    class stack

    {

    public:

        //stack() = default;//不报错
        //stack() = default//报错
        stack() {};
        //stack() {}//不报错
        //stack()报错
        //stack()报错


        void push(const T& x)
        {
            _c.push_back(x);
        }

        void pop()
        {
            _c.pop_back();
        }

        T& top()
        {
            return _c.back();
        }

        const T& top()const
        {
            return _c.back();
        }

        size_t size()const
        {
            return _c.size();
        }

        bool empty()const
        {
            return _c.empty();
        }

    private:

        Con _c;

    };



    template<class T, class Con = deque<T>>

    class queue

    {

    public:

        void push(const T& x)
        {
            _c.push_back(x);
        }

        void pop()
        {
            _c.pop_front();
        }

        T& back()
        {
            return _c.back();
        }

        const T& back()const
        {
            return _c.back();
        }

        T& front()
        {
            return _c.front();
        }

        const T& front()const
        {
            return _c.front();
        }

        size_t size()const
        {
            return _c.size();
        }

        bool empty()const
        {
            return _c.empty();
        }

    private:

        Con _c;

    };


    void TestStack()
    {
        stack<int> s;

        cout << s.empty();

        s.push(1);
        s.push(2);
        s.push(3);
        s.push(4);
        s.push(5);

        cout << s.top();

        cout << s.size();

        s.pop();
        s.pop();
        s.pop();
        cout << s.size();


    }

    void TestQueue()
    {
        queue<int> s;

        cout << s.empty();

        s.push(1);
        s.push(2);
        s.push(3);
        s.push(4);
        s.push(5);

        cout << s.front();
        cout << s.back();


        cout << s.size();

        s.pop();
        s.pop();
        s.pop();
        cout << s.size();


    }


};
