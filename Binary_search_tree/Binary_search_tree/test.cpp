#include<iostream>
#include<string>
#define _CRT_SECURE_NO_WARNINGS 1
#include"BinarySearch.h"
using namespace std;

int main()
{
	key::BSTree<int> t;
	int a[] = { 8,3,1,10,1,6,4,7,14,13 };
	for (auto e : a) {
		t.Insert(e);
	}
	t.InOrder();
	t.Insert(16);
	t.Insert(3);

	t.Erase(3);
	t.InO
	return 0;
}