
//根据二叉树创建字符串
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     TreeNode *left;
// *     TreeNode *right;
// *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
// *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// * };
// */
//class Solution {
//public:
//    string tree2str(TreeNode* root) {
//        string s;
//
//        if (root == nullptr)
//            return "";
//
//        s += to_string(root->val);
//        // 1、左右都为空，要省略括号
//        // 2、右为空，要省略括号
//        // 3、左为空，右不为空，不能省略括号
//        // 左边和右边有一个为空，左边必须有括号
//
//        if (root->left || root->right) {
//            s += '(';
//            s += tree2str(root->left);
//            s += ')';
//        }
//
//        if (root->right) {
//            s += '(';
//            s += tree2str(root->right);
//            s += ')';
//        }
//
//        return s;
//    }
//};