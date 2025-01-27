#include<iostream>
#include<vector>

using namespace std;

//快速选择算法（medium）
//class Solution {
//public:
//	int findKthLargest(vector<int>& nums, int k) {
//		srand(time(NULL)); // 种下一个随机数种子
//		return qsort(nums, 0, nums.size() - 1, k);
//	}
//	// 快排
//	int qsort(vector<int>& nums, int l, int r, int k)
//	{
//		if (l == r)
//			return nums[l];
//		// 数组分三块
//		int key = getRandom(nums, l, r);
//		int i = l, left = l - 1, right = r + 1;
//		while (i < right)
//		{
//			if (nums[i] < key) swap(nums[++left], nums[i++]);
//			else if (nums[i] == key) i++;
//			else swap(nums[--right], nums[i]);
//		}
//		int c = r - right + 1, b = right - left - 1;
//		if (c >= k) return qsort(nums, right, r, k);
//		else if (c + b >= k) return key;
//		else return qsort(nums, l, left, k - b - c);
//	}
//	int getRandom(vector<int>& nums, int left, int right)
//	{
//		int r = rand();
//		return nums[r % (right - left + 1) + left];
//	}
//};

//class Solution {
//public:
//	int findKthLargest(vector<int>& nums, int k) {
//		srand(time(NULL)); // 种下一个随机数种子
//		return qsort(nums, 0, nums.size() - 1, k);
//	}
//	// 快排
//	int qsort(vector<int>& nums, int l, int r, int k)
//	{
//		// 数组分三块
//		int key = getRandom(nums, l, r);
//		int i = l, left = l - 1, right = r + 1;
//		while (i < right)
//		{
//			if (nums[i] < key) swap(nums[++left], nums[i++]);
//			else if (nums[i] == key) i++;
//			else swap(nums[--right], nums[i]);
//		}
//		if (r - right >= k) {
//			for (int i = nums.size() - 1; k >= 0; k--, i--)
//				return nums[i];
//		}
//		else if (r - left >= k) {
//			return key;
//		}
//		else {
//			for (int i = nums.size() - 1, k = r - k; k >= 0; k--, i--)
//				return nums[i];
//		}
//	}
//	int getRandom(vector<int>& nums, int left, int right)
//	{
//		int r = rand();
//		return nums[r % (right - left + 1) + left];
//	}
//};

//class Solution
//{
//public:
//	vector<int> sortArray(vector<int>& nums)
//	{
//		srand(time(NULL)); // 种下一个随机数种子
//		qsort(nums, 0, nums.size() - 1);
//		return nums;
//	}
//	// 快排
//	void qsort(vector<int>& nums, int l, int r)
//	{
//		if (l >= r) return;
//		// 数组分三块
//		int key = getRandom(nums, l, r);
//		int i = l, left = l - 1, right = r + 1;
//		while (i < right)
//		{
//			if (nums[i] < key) swap(nums[++left], nums[i++]);
//			else if (nums[i] == key) i++;
//			else swap(nums[--right], nums[i]);
//		}
//		// [l, left] [left + 1, right - 1] [right, r]
//		qsort(nums, l, left);
//		qsort(nums, right, r);
//	}
//	int getRandom(vector<int>& nums, int left, int right)
//	{
//		int r = rand();
//		return nums[r % (right - left + 1) + left];
//	}
//};

//快速排序（medium）
//class Solution {
//public:
//    vector<int> sortArray(vector<int>& nums) {
//        srand(time(NULL));
//        qsort(nums, 0, nums.size() - 1);
//        return nums;
//    }
//
//    void qsort(vector<int>& nums, int l, int r) {
//        if (l >= r) return;
//
//        int cur = l, left = l - 1, right = r + 1;
//        int key = getRandom(nums, l, r);
//
//        while (cur < right) {
//            if (nums[cur] < key) {
//                swap(nums[++left], nums[cur++]);
//            }
//            else if (nums[cur] > key) {
//                swap(nums[--right], nums[cur]);
//            }
//            else {
//                cur++;
//            }
//        }
//        qsort(nums, l, left);
//        qsort(nums, right, r);
//
//    }
//    int getRandom(vector<int>& nums, int left, int right)
//    {
//        int k = nums[rand() % (right - left + 1) + left];
//        return k;
//    }
//};

//int main() {
//
//    vector<int> nums = { 5,2,3,1};
//    Solution().sortArray(nums);
//    return 0;
//}
//颜色分类（medium）
//class Solution {
//public:
//    void sortColors(vector<int>& nums) {
//        int n = nums.size();
//        int cur = 0, left = -1, right = n;
//        while (cur < right) {
//            if (nums[cur] == 0) {
//                swap(nums[++left], nums[cur++]);
//            }
//            else if (nums[cur] == 2) {
//                swap(nums[--right], nums[cur]);
//            }
//            else {
//                cur++;
//            }
//        }
//    }
//};