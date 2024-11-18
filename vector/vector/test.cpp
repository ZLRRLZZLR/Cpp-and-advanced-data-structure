


//int a();
//int b(10);
//int* p();
//
//
//void test_vector5()
//{
//	vector<string> v1;//vector中也可以存储自定义类型
//	string s1("xxxx");
//	v1.push_back(s1);
//
//	v1.push_back("yyyyy");
//	for (const auto& e : v1)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//
//	vector<int> v(5, 1);
//	vector<vector<int>> vv(10, v);//这里就相当于数组中存储数组，达到二维数组的效果
//	vv[2][1] = 2;//重载的[]
//	// vv.operator[](2).operator[](1) = 2;//实际上是这样，为了美观可以像二维数组一样访问
//	                                      //编译器特殊处理vv[2][1]这样就行
//	for (size_t i = 0; i < vv.size(); i++)
//	{
//		for (size_t j = 0; j < vv[i].size(); ++j)
//		{
//			cout << vv[i][j] << " ";
//		}
//		cout << endl;
//	}
//	cout << endl;
//}
//
//
//////////////////////////////////////////////////////////////////////////
////  vector的迭代器
//////////////////////////////////////////////////////////////////////////
//void PrintVector(const vector<int>& v)
//{
//	// const对象使用const迭代器进行遍历打印
//	vector<int>::const_iterator it = v.begin();
//	while (it != v.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//}
//
//void TestVector2()
//{
//	// 使用push_back插入4个数据
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	v.push_back(4);
//
//	// 使用迭代器进行遍历打印
//	vector<int>::iterator it = v.begin();
//	while (it != v.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//
//	// 使用迭代器进行修改
//	it = v.begin();
//	while (it != v.end())
//	{
//		*it *= 2;
//		++it;
//	}
//
//	// 使用反向迭代器进行遍历再打印
//	// vector<int>::reverse_iterator rit = v.rbegin();
//	auto rit = v.rbegin();
//	while (rit != v.rend())
//	{
//		cout << *rit << " ";
//		++rit;
//	}
//	cout << endl;
//
//	PrintVector(v);
//}
//
//////////////////////////////////////////////////////////////////////////
////  vector的resize 和 reserve
//////////////////////////////////////////////////////////////////////////
//// reisze(size_t n, const T& data = T())
//// 将有效元素个数设置为n个，如果时增多时，增多的元素使用data进行填充
//// 注意：resize在增多元素个数时可能会扩容
//void TestVector3()
//{
//	vector<int> v;
//
//	// set some initial content:
//	for (int i = 1; i < 10; i++)
//		v.push_back(i);
//
//	v.resize(5);
//	v.resize(8, 100);
//	v.resize(12);
//
//	cout << "v contains:";
//	for (size_t i = 0; i < v.size(); i++)
//		cout << ' ' << v[i];
//	cout << '\n';
//}
//
//
//////////////////////////////////////////////////////////////////////////
////  vector的增删改查
//////////////////////////////////////////////////////////////////////////
//// 尾插和尾删：push_back/pop_back
//void TestVector4()
//{
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	v.push_back(4);
//
//	auto it = v.begin();
//	while (it != v.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//
//	v.pop_back();
//	v.pop_back();
//
//	it = v.begin();
//	while (it != v.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//}
//
//// 任意位置插入：insert和erase，以及查找find
//// 注意find不是vector自身提供的方法，是STL提供的算法
//void TestVector5()
//{
//	// 使用列表方式初始化，C++11新语法
//	vector<int> v{ 1, 2, 3, 4 };
//
//	// 在指定位置前插入值为val的元素，比如：3之前插入30,如果没有则不插入
//	// 1. 先使用find查找3所在位置
//	// 注意：vector没有提供find方法，如果要查找只能使用STL提供的全局find
//	auto pos = find(v.begin(), v.end(), 3);
//	if (pos != v.end())
//	{
//		// 2. 在pos位置之前插入30
//		v.insert(pos, 30);
//	}
//
//	vector<int>::iterator it = v.begin();
//	while (it != v.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//
//	pos = find(v.begin(), v.end(), 3);
//	// 删除pos位置的数据
//	v.erase(pos);
//
//	it = v.begin();
//	while (it != v.end()) {
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//}
//
//// operator[]+index 和 C++11中vector的新式for+auto的遍历
//// vector使用这两种遍历方式是比较便捷的。
//void TestVector6()
//{
//	vector<int> v{ 1, 2, 3, 4 };
//
//	// 通过[]读写第0个位置。
//	v[0] = 10;
//	cout << v[0] << endl;
//
//	// 1. 使用for+[]小标方式遍历
//	for (size_t i = 0; i < v.size(); ++i)
//		cout << v[i] << " ";
//	cout << endl;
//
//	vector<int> swapv;
//	swapv.swap(v);
//
//	cout << "v data:";
//	for (size_t i = 0; i < v.size(); ++i)
//		cout << v[i] << " ";
//	cout << endl;
//
//	// 2. 使用迭代器遍历
//	cout << "swapv data:";
//	auto it = swapv.begin();
//	while (it != swapv.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//
//	// 3. 使用范围for遍历
//	for (auto x : v)
//		cout << x << " ";
//	cout << endl;
//}