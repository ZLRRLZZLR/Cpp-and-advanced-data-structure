#pragma once
#include<iostream>
using namespace std;


namespace zlr
{
    // List的节点类
    template<class T>
    struct ListNode
    {
        ListNode(const T& val = T())
            :_pPre(nullptr)
             ,_pNext(nullptr)
             ,_val(val)
        {}

        ListNode<T>* _pPre;
        ListNode<T>* _pNext;
        T _val;
    };


    //List的迭代器类
    template<class T, class Ref, class Ptr>
    struct ListIterator
    {
        typedef ListNode<T>* PNode;
        typedef ListIterator<T, Ref, Ptr> Self;
    public:

        ListIterator(PNode pNode = nullptr)
            : _pNode(pNode)
        {}

        ListIterator(const Self& l)
            :_pNode(l._pNode)
        {}

        T& operator*()
        {
            return _pNode->_val;
        }

        T* operator->()
        {
            return &_pNode->_val;
        }

        Self& operator++()
        {
            _pNode = _pNode->_pNext;
            return *this;
        }

        Self operator++(int)
        {
            PNode* tmp(_pNode);
            _pNode = _pNode->_pNext;
            return *this;
        }

        Self& operator--()
        {
            _pNode = _pNode->_pPre;
            return *this;
        }

        Self& operator--(int)
        {
            PNode* tmp(_pNode);
            _pNode = _pNode->_pPre;
            return *this;
        }

        bool operator!=(const Self& l)
        {
            return _pNode->_val != l._pNode->_val;
        }

        bool operator==(const Self& l)
        {
            return _pNode->_val == l._pNode->_val;
        }

        PNode _pNode;
    };


    //list类
    template<class T>
    class list
    {
        typedef ListNode<T> Node;
        typedef Node* PNode;

    public:

        typedef ListIterator<T, T&, T*> iterator;
        typedef ListIterator<T, const T&, const T&> const_iterator;

    public:
        ///////////////////////////////////////////////////////////////
        // List的构造

        list()
        {
            CreateHead();
        }

        list(int n, const T& value = T())
        {
            for(int i = 0;i < n;i++)
            {
                push_back(value);
            }
        }

        template <class Iterator>
        list(Iterator first, Iterator last)
        {
            while(*first != *last)
            {
                push_back(*first);
                ++first;
            }
        }

        list(const list<T>& l)
        {
            *this(l.begin(), l.end());
        }

        list<T>& operator=(const list<T> l)
        {
            swap(l);
        }

        ~list()
        {
            clear();

            delete _pHead;
            _pHead = nullptr;
        }


        ///////////////////////////////////////////////////////////////
        // List Iterator
        iterator begin()
        {
            return _pHead->_pNext;
        }
        iterator end()
        {
            return _pHead;
        }
        const_iterator begin() const
        {
            return _pHead->_pNext;
        }
        const_iterator end() const
        {
            return _pHead;
        }


        ///////////////////////////////////////////////////////////////
        // List Capacity
        size_t size()const
        {
            return _size;
        }
        bool empty()const
        {
            return _size == 0;
        }


        ////////////////////////////////////////////////////////////
        // List Access
        T& front()
        {
            return _pHead->_pNext;
        }
        const T& front()const
        {
            return _pHead->_pNext;
        }

        T& back()
        {
            return _pHead->_pPre;
        }
        const T& back()const
        {
            return _pHead->_pPre;
        }


        ////////////////////////////////////////////////////////////
        // List Modify
        void push_back(const T& val)
        {
            insert(end(), val);
        }

        void pop_back()
        {
            erase(--end());
        }

        void push_front(const T& val)
        {
            push_front(begin(), val);
        }

        void pop_front()
        {
            erase(begin());

        }
        // 在pos位置前插入值为val的节点
        iterator insert(iterator pos, const T& val)
        {
            CreateHead();
            PNode newnode = new Node;
            PNode prev = pos._pNode->_pPre;

            prev->_pNext = newnode;
            newnode->_pPre = prev;
            newnode->_pNext = pos._pNode;
            pos._pNode->_pPre = newnode;

            _size++;
            return newnode;
        }

        // 删除pos位置的节点，返回该节点的下一个位置
        iterator erase(iterator pos)
        {
            PNode prev = pos._pNode->_pPre;
            PNode next = pos._pNode->_pNext;

            prev->_pNext = next;
            next->_pPre = prev;

            delete pos._pNode;

            _size--;

            return next;
        }

        void clear()
        {
            while (_size > 0)
            {
                pop_back();
            }
        }

        void swap(list<T>& l)
        {
            std::swap(_pHead,l._pHead);
            std::swap(_size, l._size);

        }

    private:
        void CreateHead() 
        {   
            _pHead = new Node;
            _pHead->_pNext = _pHead;
            _pHead->_pPre = _pHead;

            _size = 0;
        }

        PNode _pHead;
        size_t _size;
    };

    void Test_01()
    {
        list<int> l1(10);
    }






};
