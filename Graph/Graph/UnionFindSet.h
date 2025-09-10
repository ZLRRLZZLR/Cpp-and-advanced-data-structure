#pragma once
#include<vector>




////将两个元素合并到一个集合中
//bool Union(int x1, int x2)
//{
//	int root1 = FindRoot(x1);
//	int root2 = FindRoot(x2);
//	// 根相同，x1已经与x2在同一个集合
//	if (root1 == root2)
//		return false;
//
//	//数据量小的合集往大合集合并
//	if (abs(root1) < abs(root2))
//		swap(root1, root2);
//
//	// 将两个集合中元素合并
//	_ufs[root1] += _ufs[root2];
//	// 将其中一个集合名称改变成另外一个（改变指向的根）
//	_ufs[root2] = root1;
//	return true;
//}



class UnionFindSet 
{
public:
	UnionFindSet(int size)
		:_set(size, -1)
	{}

	//查找当前数据集合的根
	size_t FindRoot(int x)
	{
		int root = x;
		while (_set[root] >= 0) {
			root = _set[root];
		}
		return root;
	}

	//将两个数合并集合
	void Union(int x1, int x2)
	{
		int root1 = FindRoot(x1);
		int root2 = FindRoot(x2);

		if (root1 == root2) return;

		else {
			_set[root1] += _set[root2];
			_set[root2] = root1;
		}
	}

	//判断并查集中有多少集合
	size_t SetCount()
	{
		int n = 0;
		for (auto& num : _set) {
			if (num < 0) n++;
		}
		return n;
	}

	//判断两个数据是否在同一个合集中
	bool InSet(int x1, int x2)
	{
		return FindRoot(x1) == FindRoot(x2);
	}

private:
	std::vector<int> _set;
};