#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<set>
#include<map>
#include<string>
#include<vector>
#include<stack>
#include<assert.h>

using namespace std;

class Solution {
public:
	struct opPD
	{
		char _op;
		int _pd;
	};
	static opPD arr[] = { {'+', 1},{'-', 1},{'*', 2},{'/', 2} };
	for (auto& e : arr)
	{
		if (e._op == ch)
		{
			return e._pd;
		}
	}
	assert(false);
	return -1;
}
void toRPN(const string& s, size_t& i, vector<string>& v){
	stcak<char> st;

	while (i < s.szie()) {
		if (isdigit(s[i])) {
			string num;
			while (i < size() && isdigit(s[i])) {
				num += s[i];
				++i;
			}
			v.push_back(num);
		}
		else if (s[i] == '(') {
			++i;
			toRPN(s, i, v);
		}
		else if (s[i] == ')') {
			while (!st.empty())
			{
				v.push_back(string(1, st.top()));
				st.pop();
			}
			++i;
			return;
		}
		else {
			if (st.empty() || operatorPrecedence(s[i]) > operatorPrecedence(st.top()))
			{
				st.push(s[i]);
				++i;
			}
			else {
				char op = st.top();
				st.pop();

				v.push_back(string(1, op));
			}
			while (!st.empty()) {
				v.push_back(string(1, st.top());
				st.pop();
			}
		}
	}
};

int main()
{
	size_t i = 0;
	vector<string> v;
	//string str = "1+2-3";
	string str = "1+2-(3*4+5)-7";
	Solution().toRPN(str, i, v);
	for (auto& e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	return 0;
}