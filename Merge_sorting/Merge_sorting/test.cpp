#include<iostream>
#include<vector>

using namespace std;

//翻转对（hard）
//class Solution {
//	vector<int> tmp;
//	int ret = 0;
//public:
//	int reversePairs(vector<int>& nums) {
//		tmp.resize(nums.size());
//		mergeSort(nums, 0, nums.size() - 1);
//		return ret;
//	}
//	void mergeSort(vector<int>& nums, int left, int right)
//	{
//		if (left >= right) return;
//		// 1. 选择中间点划分区间
//		int mid = (left + right) >> 1;
//		// [left, mid] [mid + 1, right]
//		// 2. 把左右区间排序
//		mergeSort(nums, left, mid);
//		mergeSort(nums, mid + 1, right);
//
//		// 3. 合并两个有序数组
//		int cur1 = left, cur2 = mid + 1, i = 0;
//		int l1 = cur1, l2 = cur2;
//		while (l1 < cur2 && l2 <= right) {
//			if ((double)nums[l1] > (double)2 * nums[l2]) {
//				ret += right - l2 + 1;
//				l1++;
//			}
//			else {
//				l2++;
//			}
//		}
//
//		while (cur1 <= mid && cur2 <= right) {
//			tmp[i++] = nums[cur1] > nums[cur2] ? nums[cur1++] : nums[cur2++];
//		}
//		// 处理没有遍历完的数组
//		while (cur1 <= mid) tmp[i++] = nums[cur1++];
//		while (cur2 <= right) tmp[i++] = nums[cur2++];
//		// 4. 还原
//		for (int i = left; i <= right; i++)
//			nums[i] = tmp[i - left];
//	}
//};
//分治 - 归并排序
//class Solution {
//public:
//    vector<int> sortArray(vector<int>& nums) {
//        vector<int> tmp(nums.size());
//        mergesort(nums, 0, nums.size() - 1, tmp);
//        return nums;
//    }
//
//    void mergesort(vector<int>& nums, int left, int right, vector<int>& tmp) {
//        if (left >= right)
//            return;
//
//        int mid = (right + left) / 2;
//        int i = 0;
//        mergesort(nums, left, mid, tmp);
//        mergesort(nums, mid + 1, right, tmp);
//
//        int cur1 = left, cur2 = mid + 1;
//        while (cur1 <= mid && cur2 <= right)
//            tmp[i++] = nums[cur1] < nums[cur2] ? nums[cur1++] : nums[cur2++];
//        while (cur1 <= mid) {
//            tmp[i++] = nums[cur1++];
//        }
//        while (cur2 <= right) {
//            tmp[i++] = nums[cur2++];
//        }
//        for (int j = 0; j < i; j++) {
//            nums[left++] = tmp[j];
//        }
//    }
//};
//int main() {
//    vector<int> arr = { 5,2,3,1};
//
//    Solution().sortArray(arr);
//    return 0;
//}