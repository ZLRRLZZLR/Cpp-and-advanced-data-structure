
#include<iostream>
#include<sstream>
#include<string>
using namespace std;
class Date
{
	friend ostream& operator << (ostream& out, const Date& d);
	friend istream& operator >> (istream& in, Date& d);
public:
	Date(int year = 1, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
	{
	}
private:
	int _year;
	int _month;
	int _day;
};
istream& operator >> (istream& in, Date& d)
{
	in >> d._year >> d._month >> d._day;
	return in;
}
ostream& operator << (ostream& out, const Date& d)
{
	out << d._year << " " << d._month << " " << d._day << endl;
	return out;
}
struct ChatInfo
{
	string _name; // 名字
	int _id; // id
	Date _date; // 时间
	string _msg; // 聊天信息
};
int main()
{
	// 结构信息序列化为字符串
	ChatInfo winfo = { "张三", 135246, { 2022, 4, 10 }, "晚上一起看电影吧" };
	ostringstream oss;
	oss << winfo._name << " " << winfo._id << " " << winfo._date << " " <<
		winfo._msg;
	string str = oss.str();
	cout << str << endl << endl;
	// 我们通过网络这个字符串发送给对象，实际开发中，信息相对更复杂，
	// 一般会选用Json、xml等方式进行更好的支持
	// 字符串解析成结构信息
	ChatInfo rInfo;
	istringstream iss(str);
	iss >> rInfo._name >> rInfo._id >> rInfo._date >> rInfo._msg;
	cout << "-------------------------------------------------------" << endl;
	cout << "姓名：" << rInfo._name << "(" << rInfo._id << ") ";
	cout << rInfo._date << endl;
	cout << rInfo._name << ":>" << rInfo._msg << endl;
	cout << "-------------------------------------------------------" << endl;
	return 0;
}

//#include<iostream>
//#include<sstream>
//#include<string>
//using namespace std;
//int main()
//{
//	int i = 123;
//	Date d = { 2025, 4, 10 };
//	ostringstream oss;
//	oss << i << endl;
//	oss << d << endl;
//	string s = oss.str();
//	cout << s << endl;
//	//stringstream iss(s);
//	//stringstream iss;
//	//iss.str("100 2025 9 9");
//	istringstream iss("100 2025 9 9");
//	int j;
//	Date x;
//	iss >> j >> x;
//	cout << j << endl;
//	cout << x << endl;
//	int a = 1234;
//	int b = 5678;
//	string str;
//	// 将一个整形变量转化为字符串，存储到string类对象中
//	stringstream ss;
//	ss << a << " " << b;
//	ss >> str;
//	cout << str << endl;
//	cout << ss.fail() << endl;
//	cout << ss.bad() << endl;
//	// 注意多次转换时，必须使用clear将上次转换状态清空掉
//	// stringstreams在转换结尾时(即最后一个转换后),会将其内部状态设置为badbit和failbit
//	// 因此下一次转换是必须调用clear()将状态重置为goodbit才可以转换
//	// 但是clear()不会将stringstreams底层字符串清空掉,str给一个空串可以清掉底层的字符
//	//串
//	ss.clear();
//	ss.str("");
//	double dd = 12.34;
//	ss << dd;
//	ss >> str;
//	cout << str << endl;
//	return 0;
//}

//#include<iostream>
//#include<fstream>
//#include<string>
//using namespace std;
//class Date
//{
//	friend ostream& operator << (ostream& out, const Date& d);
//	friend istream& operator >> (istream& in, Date& d);
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//	{
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//istream& operator >> (istream& in, Date& d)
//{
//	in >> d._year >> d._month >> d._day;
//	return in;
//}
//ostream& operator << (ostream& out, const Date& d)
//{
//	out << d._year << " " << d._month << " " << d._day << endl;
//	return out;
//}
//struct ServerInfo
//{
//	// 二进制读写时，这里不能用string，否则写到文件中的是string中指向字符数组的指针
//	// 若string对象析构后再去文件中读取string对象，string中读到是一个野指针。
//	char _address[32];
//	//string _address;
//	int _port;
//	Date _date;
//};
//struct ConfigManager
//{
//public:
//	ConfigManager(const char* filename)
//		:_filename(filename)
//	{
//	}
//	// 二进制写
//	// 内存中怎么存，囫囵吞枣，就怎么直接写出去
//	void WriteBin(const ServerInfo& info)
//	{
//		ofstream ofs(_filename, ios_base::out | ios_base::binary);
//		ofs.write((const char*)&info, sizeof(info));
//	}
//	// 二进制读
//	// 将文件中的内容直接囫囵吞枣，直接读到内存中
//	void ReadBin(ServerInfo& info)
//	{
//		ifstream ifs(_filename, ios_base::in | ios_base::binary);
//		ifs.read((char*)&info, sizeof(info));
//	}
//	void WriteText(const ServerInfo& info)
//	{
//		ofstream ofs(_filename);
//		ofs << info._address << " " << info._port << " " << info._date;
//	}
//	void ReadText(ServerInfo& info)
//	{
//		ifstream ifs(_filename);
//		ifs >> info._address >> info._port >> info._date;
//	}
//private:
//	string _filename; // 配置文件
//};
//void WriteBin()
//{
//	ServerInfo winfo = { "192.0.0.1111111111111111111111", 80, { 2025, 1, 10 }
//	};
//	// 二进制读写
//	ConfigManager cf_bin("test.bin");
//	cf_bin.WriteBin(winfo);
//}
//void ReadBin()
//{
//	// 二进制读写
//	ConfigManager cf_bin("test.bin");
//	ServerInfo rbinfo;
//	cf_bin.ReadBin(rbinfo);
//	cout << rbinfo._address << " " << rbinfo._port << " " << rbinfo._date <<
//		endl;
//}
//void WriteText()
//{
//	ServerInfo winfo = { "192.0.0.1", 80, { 2025, 1, 10 } };
//	// 文本读写
//	ConfigManager cf_text("test.txt");
//	cf_text.WriteText(winfo);
//}
//void ReadText()
//{
//	ConfigManager cf_text("test.txt");
//	ServerInfo rtinfo;
//	cf_text.ReadText(rtinfo);
//	cout << rtinfo._address << " " << rtinfo._port << " " << rtinfo._date <<
//		endl;
//}
//int main()
//{
//	WriteBin();
//	ReadBin();
//	WriteText();
//	ReadText();
//	return 0;
//}

//#include<iostream>
//#include<fstream>
//#include<string>
//using namespace std;
//int main()
//{
//	ofstream ofs("test.txt");
//	// 字符和字符串的写
//	ofs.put('x');
//	ofs.write("hello\nworld", 11);
//	// 使用<<进行写
//	ofs << "22222222" << endl;
//	int x = 111;
//	double y = 1.11;
//	ofs << x << endl;
//	ofs << y << endl;
//	ofs.close();
//	// app和ate都是尾部追加，不同的是app不能移动文件指针，永远是在文件尾写
//	// ate可以移动文件指针，写到其他位置
//	ofs.open("test.txt", ios_base::out | ios_base::app);
//	ofs << "1111111" << endl;
//	ofs.seekp(0, ios_base::beg);
//	ofs << x << " " << y << endl;
//	ofs.close();
//	ofs.open("test.txt", ios_base::out | ios_base::ate);
//	ofs << "1111111" << endl;
//	ofs.seekp(0, ios_base::beg);
//	ofs << x << " " << y << endl;
//	ofs.close();
//	// out和 out|trunc都会先把数据清掉，再写数据（官方文档也明确是这样写的）
//	// https://en.cppreference.com/w/cpp/io/basic_filebuf/open
//	// 那么trunc存在的意义是什么呢？out|trunc更明确的表达了文件中有内容时要清除掉内
//	//容
//	// 对于代码维护者和阅读者来说能清晰地理解这个行为，在一些复杂的文件系统环境或不同
//	//的
//	// C++文件流实现库中,out行为不完全等同于截断内容的情况(虽然当前主流实现基本一
//	//致),
//	// out|trunc更明确的表要清除内容的行为
//	ofs.open("test.txt", ios_base::out);
//	//ofs.open("test.txt", ios_base::out | ios_base::trunc);
//	ofs << "xxxx";
//	ofs.close();
//	return 0;
//}
//int main()
//{
//	// 实现一个图片文件的复制，需要用二进制方式打开读写，第一个参数可以给文件的绝对路径
//	ifstream ifs("D:\\360MoveData\\Users\\xjh\\Desktop\\11-29.png",
//		ios_base::in | ios_base::binary);
//	ofstream ofs("D:\\360MoveData\\Users\\xjh\\Desktop\\11-29-copy.png",
//		ios_base::out | ios_base::binary);
//	int n = 0;
//	while (ifs && ofs)
//	{
//		char ch = ifs.get();
//		ofs << ch;
//		++n;
//	}
//	cout << n << endl;
//	return 0;
//}


//#include<iostream>
//#include<fstream>
//#include<string>
//using namespace std;
//int main()
//{
//	int i = 0, j = 1;
//	// 持续的输入，要结束需要输入Ctrl+Z换行，Ctrl+Z用于告诉程序输入已经完成，类似于在文
//	//件末尾添加一个标记。
//	// istream& operator>>(int i),>>运算符重载的返回值是istream对象，istream对象可以
//	//调用operator bool转换为bool值
//	// 本质在底层是将cin的eofbit和failbit标志位设置了，cin调用operator bool函数语法逻
//	//辑上实现转换为bool值
//		while (cin >> i >> j)
//		{
//			cout << i << ":" << j << endl;
//		}
//	cout << cin.good() << endl;
//	cout << cin.eof() << endl;
//	cout << cin.bad() << endl;
//	cout << cin.fail() << endl << endl;
//	// 流一旦发生错误就不能再用了，清理重置一下再能使用
//	cin.clear();
//	string s;
//	while (cin >> s)
//	{
//		cout << s << endl;
//	}
//}

//#include<iostream>
//using namespace std;
//int main()
//{
//	// 在io需求比较高的地方，如部分大量输入的竞赛题中，加上以下几行代码可以提高C++IO效率
//	// 并且建议用'\n'替代endl，因为endl会刷新缓冲区
//	// 关闭标准 C++ 流是否与标准 C 流在每次输入/输出操作后同步。
//	ios_base::sync_with_stdio(false);
//	// 关闭同步后，以下程序可能顺序为b a c
//	// std::cout << "a\n";
//	// std::printf("b\n");
//	// std::cout << "c\n";
//	// 解绑cin和cout关联绑定的其他流
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//	return 0;
//}


//#include<iostream>
//#include<fstream>
//using namespace std;
//void func(ostream& os)
//{
//	os << "hello world";
//	os << "hello bit";
//	// "hello world"和"hello bit"是否输出不确定
//	system("pause");
//	// 遇到endl，"hello world"和"hello bit"一定刷新缓冲区输出了
//	//os << endl;
//	//os << flush;
//	//int i;
//	//cin >> i;
//	os << "hello cat";
//	// "hello cat"是否输出不确定
//	system("pause");
//}
//int main()
//{
//	ofstream ofs("test.txt");
//	//func(cout);
//	// unitbuf设置后，ofs每次写都直接刷新
//	// ofs << unitbuf;
//	// cin绑定到ofs，cin进行读时，会刷新ofs的缓冲区
//	// cin.tie(&ofs);
//	func(ofs);
//	return 0;
//}


//#include<iostream>
//using namespace std;
//int main()
//{
//	cout << cin.good() << endl;
//	cout << cin.eof() << endl;
//	cout << cin.bad() << endl;
//	cout << cin.fail() << endl << endl;
//	int i = 0;
//	// 输入一个字符或多个字符，cin读取失败，流状态被标记为failbit
//	cin >> i;
//	cout << i << endl;
//	cout << cin.good() << endl;
//	cout << cin.eof() << endl;
//	cout << cin.bad() << endl;
//	cout << cin.fail() << endl << endl;
//	if (cin.fail())
//	{
//		// clear可以恢复流状态位goodbit
//		cin.clear();
//		// 我们还要把缓冲区中的多个字符都读出来，读到数字停下来，否则再去cin>>i还是
//		会失败
//			char ch = cin.peek();
//		while (!(ch >= '0' && ch <= '9'))
//		{
//			ch = cin.get();
//			cout << ch;
//			ch = cin.peek();
//		}
//		cout << endl;
//	}
//	cout << cin.good() << endl;
//	cout << cin.eof() << endl;
//	cout << cin.bad() << endl;
//	cout << cin.fail() << endl << endl;
//	cin >> i;
//	cout << i << endl;
//	return 0;
//}