#include<iostream>
#include<vector>

using namespace std;

//∑÷÷Œ - πÈ≤¢≈≈–Ú
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