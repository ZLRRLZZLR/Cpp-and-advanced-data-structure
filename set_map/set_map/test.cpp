
///**环形链表II
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     ListNode *next;
// *     ListNode(int x) : val(x), next(NULL) {}
// * };
// */
//class Solution {
//public:
//    ListNode* detectCycle(ListNode* head) {
//        set<ListNode*> s;
//        ListNode* cur = head;
//        while (cur) {
//            if (s.count(cur))
//                return cur;
//            else
//                s.insert(cur);
//            cur = cur->next;
//        }
//        return nullptr;
//    }
//};
//两个数组的交集
//class Solution {
//public:
//    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
//        set<int> s1(nums1.begin(), nums1.end());
//        set<int> s2(nums2.begin(), nums2.end());
//        auto it1 = s1.begin();
//        auto it2 = s2.begin();
//        vector<int> ret;
//        while (it1 != s1.end() && it2 != s2.end()) {
//            if (*it1 > *it2)
//                it2++;
//            if (*it1 < *it2)
//                it1++;
//            if (*it1 == *it2) {
//                ret.push_back(*it1);
//                it1++;
//                it2++;
//            }
//        }
//        return ret;
//    }
//};