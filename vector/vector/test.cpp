


//int a();
//int b(10);
//int* p();
//
//
//void test_vector5()
//{
//	vector<string> v1;//vector��Ҳ���Դ洢�Զ�������
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
//	vector<vector<int>> vv(10, v);//������൱�������д洢���飬�ﵽ��ά�����Ч��
//	vv[2][1] = 2;//���ص�[]
//	// vv.operator[](2).operator[](1) = 2;//ʵ������������Ϊ�����ۿ������ά����һ������
//	                                      //���������⴦��vv[2][1]��������
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
////  vector�ĵ�����
//////////////////////////////////////////////////////////////////////////
//void PrintVector(const vector<int>& v)
//{
//	// const����ʹ��const���������б�����ӡ
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
//	// ʹ��push_back����4������
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	v.push_back(4);
//
//	// ʹ�õ��������б�����ӡ
//	vector<int>::iterator it = v.begin();
//	while (it != v.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//
//	// ʹ�õ����������޸�
//	it = v.begin();
//	while (it != v.end())
//	{
//		*it *= 2;
//		++it;
//	}
//
//	// ʹ�÷�����������б����ٴ�ӡ
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
////  vector��resize �� reserve
//////////////////////////////////////////////////////////////////////////
//// reisze(size_t n, const T& data = T())
//// ����ЧԪ�ظ�������Ϊn�������ʱ����ʱ�������Ԫ��ʹ��data�������
//// ע�⣺resize������Ԫ�ظ���ʱ���ܻ�����
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
////  vector����ɾ�Ĳ�
//////////////////////////////////////////////////////////////////////////
//// β���βɾ��push_back/pop_back
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
//// ����λ�ò��룺insert��erase���Լ�����find
//// ע��find����vector�����ṩ�ķ�������STL�ṩ���㷨
//void TestVector5()
//{
//	// ʹ���б�ʽ��ʼ����C++11���﷨
//	vector<int> v{ 1, 2, 3, 4 };
//
//	// ��ָ��λ��ǰ����ֵΪval��Ԫ�أ����磺3֮ǰ����30,���û���򲻲���
//	// 1. ��ʹ��find����3����λ��
//	// ע�⣺vectorû���ṩfind���������Ҫ����ֻ��ʹ��STL�ṩ��ȫ��find
//	auto pos = find(v.begin(), v.end(), 3);
//	if (pos != v.end())
//	{
//		// 2. ��posλ��֮ǰ����30
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
//	// ɾ��posλ�õ�����
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
//// operator[]+index �� C++11��vector����ʽfor+auto�ı���
//// vectorʹ�������ֱ�����ʽ�ǱȽϱ�ݵġ�
//void TestVector6()
//{
//	vector<int> v{ 1, 2, 3, 4 };
//
//	// ͨ��[]��д��0��λ�á�
//	v[0] = 10;
//	cout << v[0] << endl;
//
//	// 1. ʹ��for+[]С�귽ʽ����
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
//	// 2. ʹ�õ���������
//	cout << "swapv data:";
//	auto it = swapv.begin();
//	while (it != swapv.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//
//	// 3. ʹ�÷�Χfor����
//	for (auto x : v)
//		cout << x << " ";
//	cout << endl;
//}