#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<set>
using namespace std;


///*随机链表的复制
//// Definition for a Node.
//class Node {
//public:
//    int val;
//    Node* next;
//    Node* random;
//
//    Node(int _val) {
//        val = _val;
//        next = NULL;
//        random = NULL;
//    }
//};
//*/
//
//class Solution {
//public:
//    Node* copyRandomList(Node* head) {
//        map<Node*, Node*> nodetable;
//        Node* copyhead = nullptr, * copytail = nullptr;
//        Node* cur = head;
//        while (cur) {
//            if (copytail == nullptr) {
//                copyhead = copytail = new Node(cur->val);
//            }
//            else {
//                copytail->next = new Node(cur->val);
//                copytail = copytail->next;
//            }
//            nodetable[cur] = copytail;
//            cur = cur->next;
//        }
//
//        cur = head;
//        Node* copy = copyhead;
//        while (cur) {
//            if (cur->random == nullptr) {
//                copy->random = nullptr;
//            }
//            else {
//                copy->random = nodetable[cur->random];
//            }
//            cur = cur->next;
//            copy = copy->next;
//        }
//        return copyhead;
//    }
//};
//int main() {
//	set<int> s;
//	set<int, greater<int>> s;
//	s.insert(5);
//
//	set<int>::iterator it = s.begin();
//	auto it = s.begin();
//	while (it != s.end()) {
//		cout << *it << " ";
//	}
//	cout << endl;
//	s.insert({ 2,8,3,9,2 });
//	for (auto e : s) {
//		cout << e << " ";
//	}
//	cout << endl;
//	void insert(initializer_list<value_type> il);
//	set<string> strset = {"sort","insert","add"};
//	set<string> strset({ "sort","insert","add" });
//
//	for (auto& e : strset) {
//		cout << e << "";
//	}
//	cout << endl;
//
//	return 0;
//}
//int main() {
//	set<int> s = { 4,2,7,2,8,5,9 };
//	for (auto e : s) {
//		cout << e << " ";
//	}
//	cout << endl;
//
//	s.erase(s.begin());
//	for (auto e : s) {
//		cout << e << " ";
//	}
//	cout << endl;
//
//	int x;
//	cin >> x;
//	int num = s.erase(x);
//	if (num == 0) {
//		cout << x << "不存在！" << endl;
//	}
//	else {
//		cout << x << "删除成功!" << endl;
//	}
//	cin >> x;
//	auto pos = s.find(x);
//	if(pos != s.end()){
//		s.erase(pos);
//	}
//	else {
//		cout << x << "不存在" << endl;
//	}
//
//	for (auto e : s) {
//		cout << e << "";
//	}
//	cout << endl;
//
//	auto pos1 = find(s.begin(), s.end(),x);
//
//	auto pos2 = s.find(x);
//
//	cin >> x;
//	if (s.count(x)) {
//		cout << x << "在" << endl;
//	}
//	return 0;
//}
//
//int main() {
//	std::set<int> myset;
//	for (int i = 1; i < 10; i++) {
//		myset.insert(i * 10);
//	}
//	for (auto e : myset) {
//		cout << e << "";
//	}
//	cout << endl;
//
//	auto itlow = myset.lower_bound(30);
//	auto itlow = myset.upper_bound(50);
//
//	myset.erase(itlow, itup);
//	for (auto e : myset) {
//		cout << e << "";
//	}
//
//	cout << endl;
//
//}
//int main() {
//	multiset<int> s = { 4,2,7,2,8,4,5,4,9 };
//	auto it = s.begin();
//	while (it != s.end()) {
//		cout << *it << "";
//		++it;
//	}
//	cout << endl;
//
//	int x;
//	cin >> x;
//	auto pos = s.find(x);
//	while (pos != s.end() && *pos == x) {
//		cout << *pos << "";
//		++pos;
//	}
//	cout << endl;
//	s.erase(x);
//
//	it = s.begin();
//	while (it != s.end()) {
//		cout << *it << "";
//		++it;
//	}
//	cout << endl;
//	return;
//}
//#include<map>
//
//int main() {
//	map<string，string> dict = { {""} };
//	pair<string, string>kv1();
//
//	dict.insert(kv1);
//	dict.insert(pair<string, string>());
//	dict.insert()
//		map<string, string>::iterator it = dict.begin();
//	while (it != dict.end()) {
//		it->second += 'x';
//
//		cout << it->first << it->second
//	}
//}

///**环形链表II
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     ListNode *next;
// *     ListNode(int x) : val(x), next(NULL) {}
// * };
// */
//class Solution {
//public:
//    ListNode* detectCycle(ListNode* head) {
//        set<ListNode*> s;
//        ListNode* cur = head;
//        while (cur) {
//            if (s.count(cur))
//                return cur;
//            else
//                s.insert(cur);
//            cur = cur->next;
//        }
//        return nullptr;
//    }
//};
//两个数组的交集
//class Solution {
//public:
//    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
//        set<int> s1(nums1.begin(), nums1.end());
//        set<int> s2(nums2.begin(), nums2.end());
//        auto it1 = s1.begin();
//        auto it2 = s2.begin();
//        vector<int> ret;
//        while (it1 != s1.end() && it2 != s2.end()) {
//            if (*it1 > *it2)
//                it2++;
//            if (*it1 < *it2)
//                it1++;
//            if (*it1 == *it2) {
//                ret.push_back(*it1);
//                it1++;
//                it2++;
//            }
//        }
//        return ret;
//    }
//};