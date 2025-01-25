
//—’…´∑÷¿‡£®medium£©
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