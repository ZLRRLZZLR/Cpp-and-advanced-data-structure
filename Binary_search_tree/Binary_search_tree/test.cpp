#include<iostream>
#include<string>
#define _CRT_SECURE_NO_WARNINGS 1
#include"BinarySearch.h"
using namespace std;

//int main()
//{
//	key::BSTree<int> t;
//	int a[] = { 8,3,1,10,1,6,4,7,14,13 };
//	for (auto e : a) {
//		t.Insert(e);
//	}
//	t.InOrder();
//	t.Insert(16);
//	t.Insert(3);
//
//	t.Erase(3);
//	t.InOrder();
//
//	for (auto e : a) {
//		t.Erase(e);
//		t.InOrder();
//	}
//	return 0;
//}
//
//int main() {
//	key_valude::BSTree<string, string> dict;
//	BSTree<string, string> copy = dict;
//	dict.Insert("left", "左边");
//	dict.Insert("right", "右边");
//	dict.Insert("insert", "插入");
//	dict.Insert("string", "字符串");
//
//	string str;
//	while (cin >> str) {
//		auto ret = dict.Find(str);
//		if (ret) {
//			cout << "->" << ret->_value << endl;
//		}
//		else {
//			cout << "无此单词，请重新输入" << endl;
//		}
//	}
//		return 0;
//}

//int main() {
//	string arr[] = { "苹果", "西瓜", "苹果", "西瓜", "苹果", "苹果", "西瓜",
//	"苹果", "香蕉", "苹果", "香蕉" };
//	key_valude::BSTree<string, int> countTree;
//
//	for (const auto& str : arr) {
//		auto ret = countTree.Find(str);
//		if (ret = nullptr)
//		{
//			conTree.Insert(str, 1);
//		}
//		else {
//			ret->_value++;
//		}
//		countTree.InOrder();
//	}
//
//	key_valude::BSTree<string, int>  copy = countTree;
//	copy.InOrder();
//
//	return 0;
//}