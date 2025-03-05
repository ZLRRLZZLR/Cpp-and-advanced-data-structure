#include <iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
using namespace std;

//#include<map>
//using namespace std;
//
//int main() {
//
//	//默认构造
//	map<string, string> dict1;
//
//	//使用列表初始化构造
//	map<string,string> dict2 = { {"left", "左边"}, {"right", "右边"}, {"insert", "插入"},{ "string", "字符串" } };
//
//	//拷贝构造
//	map<string, string> dict3(dict2);
//
//	//迭代器区间构造
//	map<string, string> dict4(dict2.begin(), dict2.end());
//
//	return 0;
//}




// insert插入一个pair<key, T>对象
// 1、如果key已经在map中，插入失败，则返回一个pair<iterator,bool>对象，返回pair对象
//first是key所在结点的迭代器，second是false
// 2、如果key不在在map中，插入成功，则返回一个pair<iterator,bool>对象，返回pair对象
//first是新插入key所在结点的迭代器，second是true
// 也就是说无论插入成功还是失败，返回pair<iterator,bool>对象的first都会指向key所在的迭
//代器
// 那么也就意味着insert插入失败时充当了查找的功能，正是因为这一点，insert可以用来实现
//operator[]
// 需要注意的是这里有两个pair，不要混淆了，一个是map底层红黑树节点中存的pair<key, T>，另
//一个是insert返回值pair<iterator, bool>
//pair<iterator, bool> insert(const value_type& val);








//#include<map>
//
//int main()
//{
//	map<string, string> dict1;//使用缺省值构造
//
//	//{"left", "左边"}等用{}括起来的数据先隐式构造一个pair对象，然后这些数据在通过列表初始化构造map对象
//	map<string, string> dict2 = { {"left", "左边"}, {"right", "右边"}, {"insert", "插入"},{ "string", "字符串" } };
//
//	//通过初始化列表构造
//	pair<string, string> kv1("first", "第一个");
//	map<string, string> dict3 = {kv1, pair<string, string>("second", "第二个")};
//
//
//	pair<string, string> kv1("first", "第一个");
//	dict1.insert(kv1);
//
//	dict1.insert(pair<string, string>("second", "第二个"));
//
//	//C++11出来之前受欢迎的写法
//	dict1.insert(make_pair("sort", "排序"));
//
//	// C++11的写法，通过{}构造pair对象，再通过列表初始化构造，最方便
//	dict1.insert({ "auto", "自动的" });
//
//	// 插入时只看key，value不相等不会更新
//	dict1.insert({ "auto", "自动的xxxx" });
//
//	//出现
//	map<string, string>::iterator it = dict1.begin();
//	//auto it = dict1.begin();
//	while (it != dict1.end())
//	{
//		// 可以修改value，不支持修改key
//		//it->first += 'x';
//		it->second += 'x';
//
//		//cout << (*it).first <<":"<< (*it).second<< endl;
//		cout << it->first << ":" << it->second << endl;
//		//cout << it.operator->()->first << ":" << it.operator->()->second << endl;
//		++it;
//	}
//	cout << endl;
//
//	return 0;
//}

//int main() {
//	map<string, string> dict1 = { {"left", "左边"}, {"right", "右边"}, {"insert", "插入"},{ "string", "字符串" } };//初始化列表初始化
//	//map<string, string> dict2({ "left", "左边" });
//
//	//map<string, string> dict3("right", "右边");
//	return 0;
//}

//int main() {
//
//
//
//	pair<int, int> example(3, 2025);
//
//	cout << example.first << endl;//.first取出第一个元素
//	cout << example.second << endl;//.second取出第二个元素
//
//	return 0;
//}

//int main() {
//	set<int> s;
//	set<int, greater<int>> s;
//	s.insert(5);
//
//
//	set<int>::iterator it = s.begin();
//	auto it = s.begin();
//	while (it != s.end()) {
//		cout << *it << " ";
//		++it;
//	}
//
//	s.insert({ 2,8,3,9,2 });
//	for (auto e : s) {
//		cout << e << " ";
//	}
//	set<string> strset = { "sort","insert","add" };
//
//	for (auto& e : strset) {
//		cout << e << "";
//	}
//	cout << endl;
//	s.erase(s.begin());
//	for (auto e : s) {
//		cout << e << "";
//	}
//
//	int num = s.erase(x);
//	auto pos1 = find(s.begin(), s.end(), x);
//
//	auto pos2 = s.find(x);
//
//	cin >> x;
//
//	auto itlow = myset.lower_bound(30);
//	auto itlow = myset.lower_bound(50);
//
//	multiset<int> s = { 4,2,7,2,4,8,4,5,4,9 };
//	auto it = s.begin();
//	while (it != s.end()) {
//		cout << *it << "";
//		++it;
//	}
//	cout << endl;
//
//	int x;
//	cin > .x;
//	auto pos = s.find(s);
//
//	while (pos != s.end() && *pos == x) {
//		cout << *pos << "";
//		++pos;
//	}
//	cout << endl;
//
//
//
//	map<string, string> dict = ({ "left","左边" });
//	pair<string, string> kvl("first", "第一个");
//	dict.insert(kv1);
//
//	dict.insert(pair<string, string>("second", "第二个"));
//	dict.insert(make_pair("sort", "排序"));
//
//	dict.insert({ "auto","自动的" });
//	
//	cout << (*it).first << ;
//	cout->first;
//	it.operator->()->first;
//	return 0;
//}


//class Solution {
//public:
//	struct Compare
//	{
//		bool operator()(const pair<string, int>& x, const pair<string, int>& y)
//			const
//		{
//			// 要注意优先级队列底层是反的，大堆要实现小于比较，所以这里次数相等，想要字典
//			序小的在前面要比较字典序大的为真
//				return x.second < y.second || (x.second == y.second && x.first >
//					y.first);
//		}
//	};
//	vector<string> topKFrequent(vector<string>& words, int k) {
//		map<string, int> countMap;
//		for (auto& e : words)
//		{
//			countMap[e]++;
//		}
//		// 将map中的<单词，次数>放到priority_queue中，仿函数控制大堆，次数相同按照字典
//		序规则排序
//			priority_queue<pair<string, int>, vector<pair<string, int>>, Compare>
//			p(countMap.begin(), countMap.end());
//		vector<string> strV;
//		for (int i = 0; i < k; ++i)
//		{
//			strV.push_back(p.top().first);
//			p.pop();
//		}
//		return strV;
//	}
//};

//class Solution {
//public:
//	struct Compare
//	{
//		bool operator()(const pair<string, int>& x, const pair<string, int>& y)
//			const
//		{
//			return x.second > y.second || (x.second == y.second && x.first <
//				y.first);;
//		}
//	};
//	vector<string> topKFrequent(vector<string>& words, int k) {
//		map<string, int> countMap;
//		for (auto& e : words)
//		{
//			countMap[e]++;
//		}
//		vector<pair<string, int>> v(countMap.begin(), countMap.end());
//		// 仿函数控制降序,仿函数控制次数相等，字典序小的在前面
//		sort(v.begin(), v.end(), Compare());
//		// 取前k个
//		vector<string> strV;
//		for (int i = 0; i < k; ++i)
//		{
//			strV.push_back(v[i].first);
//		}
//		return strV;
//	}
//};

//class Solution {
//public:
//	struct Compare
//	{
//		bool operator()(const pair<string, int>& x, const pair<string, int>& y)
//			const
//		{
//			return x.second > y.second;
//		}
//	};
//	vector<string> topKFrequent(vector<string>& words, int k) {
//		map<string, int> countMap;
//		for (auto& e : words)
//		{
//			countMap[e]++;
//		}
//		vector<pair<string, int>> v(countMap.begin(), countMap.end());
//		// 仿函数控制降序
//		stable_sort(v.begin(), v.end(), Compare());
//		//sort(v.begin(), v.end(), Compare());
//		// 取前k个
//		vector<string> strV;
//		for (int i = 0; i < k; ++i)
//		{
//			strV.push_back(v[i].first);
//		}
//		return strV;
//	}
//};

//class Solution {
//public:
//	Node* copyRandomList(Node* head) {
//		map<Node*, Node*> nodeMap;
//		Node* copyhead = nullptr, * copytail = nullptr;
//		Node* cur = head;
//		while (cur)
//		{
//			if (copytail == nullptr)
//			{
//				copyhead = copytail = new Node(cur->val);
//			}
//			else
//			{
//				copytail->next = new Node(cur->val);
//				copytail = copytail->next;
//			}
//			// 原节点和拷贝节点map kv存储
//			nodeMap[cur] = copytail;
//			cur = cur->next;
//		}
//		// 处理random
//		cur = head;
//		Node* copy = copyhead;
//		while (cur)
//		{
//			if (cur->random == nullptr)
//			{
//				copy->random = nullptr;
//			}
//			else
//			{
//				copy->random = nodeMap[cur->random];
//			}
//			cur = cur->next;
//			copy = copy->next;
//		}
//		return copyhead;
//	}
//};

//#include<iostream>
//#include<map>
//#include<string>
//using namespace std;
//int main()
//{
//	map<string, string> dict;
//	dict.insert(make_pair("sort", "排序"));
//	// key不存在->插入 {"insert", string()}
//	dict["insert"];
//	// 插入+修改
//	dict["left"] = "左边";
//	// 修改
//	dict["left"] = "左边、剩余";
//	// key存在->查找
//	cout << dict["left"] << endl;
//	return 0;
//}

//#include<iostream>
//#include<map>
//#include<string>
//using namespace std;
//int main()
//{
//	// 利用find和iterator修改功能，统计水果出现的次数
//	string arr[] = { "苹果", "西瓜", "苹果", "西瓜", "苹果", "苹果", "西瓜",
//	"苹果", "香蕉", "苹果", "香蕉" };
//	map<string, int> countMap;
//	for (const auto& str : arr)
//	{
//		// 先查找水果在不在map中
//		// 1、不在，说明水果第一次出现，则插入{水果, 1}
//		// 2、在，则查找到的节点中水果对应的次数++
//		auto ret = countMap.find(str);
//		if (ret == countMap.end())
//		{
//			countMap.insert({ str, 1 });
//		}
//		else
//		{
//			ret->second++;
//		}
//	}
//	for (const auto& e : countMap)
//	{
//		cout << e.first << ":" << e.second << endl;
//	}
//	cout << endl;
//	return 0;
//}
//#include<iostream>
//#include<map>
//#include<string>
//using namespace std;
//int main()
//{
//	// 利用[]插入+修改功能，巧妙实现统计水果出现的次数
//	string arr[] = { "苹果", "西瓜", "苹果", "西瓜", "苹果", "苹果", "西瓜",
//	"苹果", "香蕉", "苹果", "香蕉" };
//	map<string, int> countMap;
//	for (const auto& str : arr)
//	{
//		// []先查找水果在不在map中
//		// 1、不在，说明水果第一次出现，则插入{水果, 0}，同时返回次数的引用，
//		++一下就变成1次了
//			// 2、在，则返回水果对应的次数++
//			countMap[str]++;
//	}
//	for (const auto& e : countMap)
//	{
//		cout << e.first << ":" << e.second << endl;
//	}
//	cout << endl;
//	return 0;
//}


//#include<iostream>
//#include<map>
//using namespace std;
//int main()
//{
//	// initializer_list构造及迭代遍历
//	map<string, string> dict = { {"left", "左边"}, {"right", "右边"},
//	{"insert", "插入"},{ "string", "字符串" } };
//	//map<string, string>::iterator it = dict.begin();
//	auto it = dict.begin();
//	while (it != dict.end())
//	{
//		//cout << (*it).first <<":"<<(*it).second << endl;
//		// map的迭代基本都使用operator->,这里省略了一个->
//		// 第一个->是迭代器运算符重载，返回pair*，第二个箭头是结构指针解引用取
//		pair数据
//			//cout << it.operator->()->first << ":" << it.operator->()-
//> second << endl;
//cout << it->first << ":" << it->second << endl;
//++it;
//	}
//	cout << endl;
//	// insert插入pair对象的4种方式，对比之下，最后一种最方便
//	pair<string, string> kv1("first", "第一个");
//	dict.insert(kv1);
//	dict.insert(pair<string, string>("second", "第二个"));
//	dict.insert(make_pair("sort", "排序"));
//	dict.insert({ "auto", "自动的" });
//	// "left"已经存在，插入失败
//	dict.insert({ "left", "左边，剩余" });
//	// 范围for遍历
//	for (const auto& e : dict)
//	{
//		cout << e.first << ":" << e.second << endl;
//	}
//	cout << endl;
//	string str;
//	while (cin >> str)
//	{
//		auto ret = dict.find(str);
//		if (ret != dict.end())
//		{
//			cout << "->" << ret->second << endl;
//		}
//		else
//		{
//			cout << "无此单词，请重新输入" << endl;
//		}
//	}
//	// erase等接口跟set完全类似，这里就不演示讲解了
//	return 0;
//}

//Member types
//key_type->The first template parameter(Key)
//mapped_type->The second template parameter(T)
//value_type->pair<const key_type, mapped_type>
//// 查找k，返回k所在的迭代器，没有找到返回end()，如果找到了通过iterator可以修改key对应的
////mapped_type值
//iterator find(const key_type& k);
//// 文档中对insert返回值的说明
//// The single element versions (1) return a pair, with its member pair::first
////set to an iterator pointing to either the newly inserted element or to the
////element with an equivalent key in the map.The pair::second element in the pair
////is set to true if a new element was inserted or false if an equivalent key
////already existed.
//// insert插入一个pair<key, T>对象
//// 1、如果key已经在map中，插入失败，则返回一个pair<iterator,bool>对象，返回pair对象
////first是key所在结点的迭代器，second是false
//// 2、如果key不在在map中，插入成功，则返回一个pair<iterator,bool>对象，返回pair对象
////first是新插入key所在结点的迭代器，second是true
//// 也就是说无论插入成功还是失败，返回pair<iterator,bool>对象的first都会指向key所在的迭
////代器
//// 那么也就意味着insert插入失败时充当了查找的功能，正是因为这一点，insert可以用来实现
////operator[]
//// 需要注意的是这里有两个pair，不要混淆了，一个是map底层红黑树节点中存的pair<key, T>，另
////一个是insert返回值pair<iterator, bool>
//pair<iterator, bool> insert(const value_type& val);
//mapped_type& operator[] (const key_type& k);
//// operator的内部实现
//mapped_type& operator[] (const key_type& k)
//{
//	// 1、如果k不在map中，insert会插入k和mapped_type默认值，同时[]返回结点中存储
//	//mapped_type值的引用，那么我们可以通过引用修改返映射值。所以[]具备了插入 + 修改功能
//		// 2、如果k在map中，insert会插入失败，但是insert返回pair对象的first是指向key结点的
//		//迭代器，返回值同时[]返回结点中存储mapped_type值的引用，所以[]具备了查找 + 修改的功能
//	pair<iterator, bool> ret = insert({ k, mapped_type() });
//	iterator it = ret.first;
//	return it->second;
//}

//Member types
//key_type->The first template parameter(Key)
//mapped_type->The second template parameter(T)
//value_type->pair<const key_type, mapped_type>
//// 单个数据插入，如果已经key存在则插入失败,key存在相等value不相等也会插入失败
//pair<iterator, bool> insert(const value_type& val);
//// 列表插入，已经在容器中存在的值不会插入
//void insert(initializer_list<value_type> il);
//// 迭代器区间插入，已经在容器中存在的值不会插入
//template <class InputIterator>
//void insert(InputIterator first, InputIterator last);
//// 查找k，返回k所在的迭代器，没有找到返回end()
//iterator find(const key_type& k);
//// 查找k，返回k的个数
//size_type count(const key_type& k) const;
//// 删除一个迭代器位置的值
//iterator erase(const_iterator position);
//// 删除k，k存在返回0，存在返回1
//size_type erase(const key_type& k);
//// 删除一段迭代器区间的值
//iterator erase(const_iterator first, const_iterator last);
//// 返回大于等k位置的迭代器
//iterator lower_bound(const key_type& k);
//// 返回大于k位置的迭代器
//const_iterator lower_bound(const key_type& k) const;

//// empty (1) 无参默认构造
//explicit map(const key_compare& comp = key_compare(),
//	const allocator_type& alloc = allocator_type());
//// range (2) 迭代器区间构造
//template <class InputIterator>
//map(InputIterator first, InputIterator last,
//	const key_compare& comp = key_compare(),
//	const allocator_type & = allocator_type());
//// copy (3) 拷贝构造
//map(const map& x);
//// initializer list (5) initializer 列表构造
//map(initializer_list<value_type> il,
//	const key_compare& comp = key_compare(),
//	const allocator_type& alloc = allocator_type());
//// 迭代器是一个双向迭代器
//iterator->a bidirectional iterator to const value_type
//// 正向迭代器
//iterator begin();
//iterator end();
//// 反向迭代器
//reverse_iterator rbegin();
//reverse_iterator rend();

//typedef pair<const Key, T> value_type;
//template <class T1, class T2>
//struct pair
//{
//	typedef T1 first_type;
//	typedef T2 second_type;
//	T1 first;
//	T2 second;
//	pair() : first(T1()), second(T2())
//	{}
//	pair(const T1& a, const T2& b) : first(a), second(b)
//	{}
//	template<class U, class V>
//	pair(const pair<U, V>& pr) : first(pr.first), second(pr.second)
//	{}
//};
//template <class T1, class T2>
//inline pair<T1, T2> make_pair(T1 x, T2 y)
//{
//	return (pair<T1, T2>(x, y));
//}

//template < class Key, // map::key_type
//	class T, // map::mapped_type
//	class Compare = less<Key>, // map::key_compare
//	class Alloc = allocator<pair<const Key, T> > //
////map::allocator_type
//    > class map;

//class Solution {
//public:
//	ListNode* detectCycle(ListNode* head) {
//		set<ListNode*> s;
//		ListNode* cur = head;
//		while (cur)
//		{
//			auto ret = s.insert(cur);
//			if (ret.second == false)
//				return cur;
//			cur = cur->next;
//		}
//		return nullptr;
//	}
//};

//class Solution {
//public:
//	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
//		set<int> s1(nums1.begin(), nums1.end());
//		set<int> s2(nums2.begin(), nums2.end());
//		// 因为set遍历是有序的，有序值，依次比较
//		// 小的++，相等的就是交集
//		vector<int> ret;
//		auto it1 = s1.begin();
//		auto it2 = s2.begin();
//		while (it1 != s1.end() && it2 != s2.end())
//		{
//			if (*it1 < *it2)
//			{
//				it1++;
//			}
//			else if (*it1 > *it2)
//			{
//				it2++;
//			}
//			else
//			{
//				ret.push_back(*it1);
//				it1++;
//				it2++;
//			}
//		}
//		return ret;
//	}
//};

//#include<iostream>
//#include<set>
//using namespace std;
//int main()
//{
//	// 相比set不同的是，multiset是排序，但是不去重
//	multiset<int> s = { 4,2,7,2,4,8,4,5,4,9 };
//	auto it = s.begin();
//	while (it != s.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//	// 相比set不同的是，x可能会存在多个，find查找中序的第一个
//	int x;
//	cin >> x;
//	auto pos = s.find(x);
//	while (pos != s.end() && *pos == x)
//	{
//		cout << *pos << " ";
//		++pos;
//	}
//	cout << endl;
//	// 相比set不同的是，count会返回x的实际个数
//	cout << s.count(x) << endl;
//	// 相比set不同的是，erase给值时会删除所有的x
//	s.erase(x);
//	for (auto e : s)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	return 0;
//}

//#include<iostream>
//#include<set>
//using namespace std;
//int main()
//{
//	set<int> s = { 4,2,7,2,8,5,9 };
//	for (auto e : s)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	// 删除最小值
//	s.erase(s.begin());
//	for (auto e : s)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	// 直接删除x
//	int x;
//	cin >> x;
//	int num = s.erase(x);
//	if (num == 0)
//	{
//		cout << x << "不存在！" << endl;
//	}
//	for (auto e : s)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	// 直接查找在利用迭代器删除x
//	cin >> x;
//	auto pos = s.find(x);
//	if (pos != s.end())
//	{
//		s.erase(pos);
//	}
//	else
//	{
//		cout << x << "不存在！" << endl;
//	}
//	for (auto e : s)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	// 算法库的查找 O(N)
//	auto pos1 = find(s.begin(), s.end(), x);
//	// set自身实现的查找 O(logN)
//	auto pos2 = s.find(x);
//	// 利用count间接实现快速查找
//	cin >> x;
//	if (s.count(x))
//	{
//		cout << x << "在！" << endl;
//	}
//	else
//	{
//		cout << x << "不存在！" << endl;
//	}
//	return 0;
//}
//#include<iostream>
//#include<set>
//using namespace std;
//int main()
//{
//	std::set<int> myset;
//	for (int i = 1; i < 10; i++)
//		myset.insert(i * 10); // 10 20 30 40 50 60 70 80 90
//	for (auto e : myset)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	// 实现查找到的[itlow,itup)包含[30, 60]区间
//	// 返回 >= 30
//	auto itlow = myset.lower_bound(30);
//	// 返回 > 60
//	auto itup = myset.upper_bound(60);
//	// 删除这段区间的值
//	myset.erase(itlow, itup);
//	for (auto e : myset)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	return 0;
//}

//#include<iostream>
//#include<set>
//using namespace std;
//int main()
//{
//	// 去重+升序排序
//	set<int> s;
//	// 去重+降序排序（给一个大于的仿函数）
//	//set<int, greater<int>> s;
//	s.insert(5);
//	s.insert(2);
//	s.insert(7);
//	s.insert(5);
//	//set<int>::iterator it = s.begin();
//	auto it = s.begin();
//	while (it != s.end())
//	{
//		// error C3892: “it”: 不能给常量赋值
//// *it = 1;
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//	// 插入一段initializer_list列表值，已经存在的值插入失败
//	s.insert({ 2,8,3,9 });
//	for (auto e : s)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	set<string> strset = { "sort", "insert", "add" };
//	// 遍历string比较ascll码大小顺序遍历的
//	for (auto& e : strset)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//}

//Member types
//key_type->The first template parameter(T)
//value_type->The first template parameter(T)
//// 单个数据插入，如果已经存在则插入失败
//pair<iterator, bool> insert(const value_type& val);
//// 列表插入，已经在容器中存在的值不会插入
//void insert(initializer_list<value_type> il);
//// 迭代器区间插入，已经在容器中存在的值不会插入
//template <class InputIterator>
//void insert(InputIterator first, InputIterator last);
//// 查找val，返回val所在的迭代器，没有找到返回end()
//iterator find(const value_type& val);
//// 查找val，返回Val的个数
//size_type count(const value_type& val) const;
//// 删除一个迭代器位置的值
//iterator erase(const_iterator position);
//// 删除val，val不存在返回0，存在返回1
//size_type erase(const value_type& val);
//// 删除一段迭代器区间的值
//iterator erase(const_iterator first, const_iterator last);
//// 返回大于等val位置的迭代器
//iterator lower_bound(const value_type& val) const;
//// 返回大于val位置的迭代器
//iterator upper_bound(const value_type& val) const;

//// empty (1) 无参默认构造
//explicit set(const key_compare& comp = key_compare(),
//	const allocator_type& alloc = allocator_type());
//// range (2) 迭代器区间构造
//template <class InputIterator>
//set(InputIterator first, InputIterator last,
//	const key_compare& comp = key_compare(),
//	const allocator_type & = allocator_type());
//// copy (3) 拷贝构造
//set(const set& x);
//// initializer list (5) initializer 列表构造
//set(initializer_list<value_type> il,
//	const key_compare& comp = key_compare(),
//	const allocator_type& alloc = allocator_type());
//// 迭代器是一个双向迭代器
//iterator->a bidirectional iterator to const value_type
//// 正向迭代器
//iterator begin();
//iterator end();
//// 反向迭代器
//reverse_iterator rbegin();
//reverse_iterator rend();


//template < class T, // set::key_type/value_type
//	class Compare = less<T>, // set::key_compare/value_compare
//	class Alloc = allocator<T> // set::allocator_type
//> class set;

//单词识别
//struct Compare {
//    bool operator()(const pair<string, int>& a, const pair<string, int>& b) {
//        return a.second > b.second;
//    }
//};
//
//int main() {
//    string s;
//    while (getline(cin, s)) { // 注意 while 处理多个 case
//        s[0] += 32;
//        s[s.size() - 1] = ' ';
//        size_t pos = s.find(' ', 0), prev = 0;
//        map<string, int> wordtable;
//        while (pos != -1) {
//            wordtable[s.substr(prev, pos - prev)]++;
//            prev = pos + 1;
//            pos = s.find(' ', prev);
//        }
//        vector<pair<string, int>> tmp({ wordtable.begin(),wordtable.end() });
//        stable_sort(tmp.begin(), tmp.end(), Compare());
//        for (auto i : tmp) {
//            cout << i.first << ':' << i.second << endl;
//        }
//    }
//    return 0;
//}
//// 64 位输出请用 printf("%lld")



//class Solution {
//public:
//    struct Compare {
//        bool operator()(const pair<string, int>& a, const pair<string, int>& b) {
//            return a.second > b.second;
//        }
//    };
//    vector<string> topKFrequent(vector<string>& words, int k) {
//        map<string, int> wordtable;
//        for (auto i : words) {
//            wordtable[i]++;
//        }
//        vector<pair<string, int>> tmp(wordtable.begin(), wordtable.end());
//        stable_sort(tmp.begin(), tmp.end(), Compare());
//        vector<string> ret;
//        for (int i = 0; i < k; i++) {
//            ret.push_back(tmp[i].first);
//        }
//        return ret;
//    }
//};
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