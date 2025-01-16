class Solution {
public:
	int firstUniqChar(string s) {
		// 每个字母的ascii码-'a'的ascii码作为下标映射到count数组，数组中存储出现的次数
		int count[26] = { 0 };
		// 统计次数
		for (auto ch : s)
		{
			count[ch - 'a']++;
		}
		for (size_t i = 0; i < s.size(); ++i)
		{
			if (count[s[i] - 'a'] == 1)
				return i;
		}
		return -1;
	}
};