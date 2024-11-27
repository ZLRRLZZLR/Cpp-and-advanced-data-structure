#pragma once

namespace zlr

{

#include<vector>

#include<functional>

    template <class T, class Container = vector<T>, class Compare = less<T> >

    class priority_queue

    {

    public:

        priority_queue();

        template <class InputIterator>

        priority_queue(InputIterator first, InputIterator last);

        bool empty() const;

        size_t size() const;

        T& top() const;

        void push(const T& x);

        void pop();

    private:

        Container c;

        Compare comp;

    };

};
