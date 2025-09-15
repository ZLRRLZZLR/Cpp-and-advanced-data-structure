#pragma once
#include <iostream>
#include <vector>
#include <time.h>
#include <random>
#include <chrono>
using namespace std;

struct SkiplistNode
{
	int _val;
	vector<SkiplistNode*> _nextV;

	SkiplistNode(int val, int level)
		:_val(val)
		, _nextV(level, nullptr)
	{
	}
};

class Skiplist {
	typedef SkiplistNode Node;
public:
	Skiplist() {
		srand(time(0));

		// 头节点，层数是1
		_head = new SkiplistNode(-1, 1);
	}

	bool search(int target) {
		Node* cur = _head;
		int level = _head->_nextV.size() - 1;
		while (level >= 0)
		{
			// 目标值比下一个节点值要大，向右走
			// 下一个节点是空(尾)，目标值比下一个节点值要小，向下走
			if (cur->_nextV[level] && cur->_nextV[level]->_val < target)
			{
				// 向右走
				cur = cur->_nextV[level];
			}
			else if (cur->_nextV[level] == nullptr || cur->_nextV[level]->_val > target)
			{
				// 向下走
				--level;
			}
			else
			{
				return true;
			}
		}

		return false;
	}

	vector<Node*> FindPrevNode(int num)
	{
		Node* cur = _head;
		int level = _head->_nextV.size() - 1;

		// 插入位置每一层前一个节点指针
		vector<Node*> prevV(level + 1, _head);

		while (level >= 0)
		{
			// 目标值比下一个节点值要大，向右走
			// 下一个节点是空(尾)，目标值比下一个节点值要小，向下走
			if (cur->_nextV[level] && cur->_nextV[level]->_val < num)
			{
				// 向右走
				cur = cur->_nextV[level];
			}
			else if (cur->_nextV[level] == nullptr
				|| cur->_nextV[level]->_val >= num)
			{
				// 更新level层前一个
				prevV[level] = cur;

				// 向下走
				--level;
			}
		}

		return prevV;
	}

	void add(int num) {
		vector<Node*> prevV = FindPrevNode(num);

		int n = RandomLevel();
		Node* newnode = new Node(num, n);

		// 如果n超过当前最大的层数，那就升高一下_head的层数
		if (n > _head->_nextV.size())
		{
			_head->_nextV.resize(n, nullptr);
			prevV.resize(n, _head);
		}

		// 链接前后节点
		for (size_t i = 0; i < n; ++i)
		{
			newnode->_nextV[i] = prevV[i]->_nextV[i];
			prevV[i]->_nextV[i] = newnode;
		}
	}

	bool erase(int num) {
		vector<Node*> prevV = FindPrevNode(num);

		// 第一层下一个不是val，val不在表中
		if (prevV[0]->_nextV[0] == nullptr || prevV[0]->_nextV[0]->_val != num)
		{
			return false;
		}
		else
		{
			Node* del = prevV[0]->_nextV[0];
			// del节点每一层的前后指针链接起来
			for (size_t i = 0; i < del->_nextV.size(); i++)
			{
				prevV[i]->_nextV[i] = del->_nextV[i];
			}
			delete del;

			// 如果删除最高层节点，把头节点的层数也降一下
			int i = _head->_nextV.size() - 1;
			while (i >= 0)
			{
				if (_head->_nextV[i] == nullptr)
					--i;
				else
					break;
			}
			_head->_nextV.resize(i + 1);

			return true;
		}


	}

	int RandomLevel()
	{
		size_t level = 1;
		// rand() ->[0, RAND_MAX]之间
		while (rand() <= RAND_MAX*_p && level < _maxLevel)
		{
			++level;
		}

		return level;
	}


private:
	Node* _head;
	size_t _maxLevel = 32;
	double _p = 0.5;
};

/**
* Your Skiplist object will be instantiated and called as such:
* Skiplist* obj = new Skiplist();
* bool param_1 = obj->search(target);
* obj->add(num);
* bool param_3 = obj->erase(num);
*/


