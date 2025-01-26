#include<iostream>
#include<vector>

using namespace std;

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