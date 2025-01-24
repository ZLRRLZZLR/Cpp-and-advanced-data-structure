

//二叉树的最近公共祖先
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     TreeNode *left;
// *     TreeNode *right;
// *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// * };
// */
//class Solution {
//public:
//    bool Getpath(TreeNode* root, TreeNode* node, stack<TreeNode*>& path) {
//
//        if (root == nullptr)
//            return false;
//
//        path.push(root);
//
//        if (root == node)
//            return true;
//
//
//        if (Getpath(root->left, node, path)) {
//            return true;
//        }
//        if (Getpath(root->right, node, path)) {
//            return true;
//        }
//
//        path.pop();
//        return false;
//    }
//    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//        stack<TreeNode*> qpath, ppath;
//        Getpath(root, q, qpath);
//        Getpath(root, p, ppath);
//
//        while (qpath.size() != ppath.size()) {
//            if (qpath.size() > ppath.size()) {
//                qpath.pop();
//            }
//            else {
//                ppath.pop();
//            }
//        }
//
//        while (qpath.top() != ppath.top()) {
//            qpath.pop();
//            ppath.pop();
//        }
//
//        return qpath.top();
//    }
//
//};

//二叉树的最近公共祖先
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     TreeNode *left;
// *     TreeNode *right;
// *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// * };
// */
//class Solution {
//public:
//    bool IsInTree(TreeNode* root, TreeNode* node) {
//        if (root == nullptr)
//            return false;
//
//        return root == node || IsInTree(root->left, node) || IsInTree(root->right, node);
//    }
//    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//        if (root == nullptr)
//            return nullptr;
//
//        if (root == p || root == q)
//            return root;
//
//        bool pInLeftTree = IsInTree(root->left, p);
//        bool pInRightTree = !pInLeftTree;
//
//        bool qInLeftTree = IsInTree(root->left, q);
//        bool qInRightTree = !qInLeftTree;
//
//        if (pInLeftTree && qInLeftTree) {
//            return lowestCommonAncestor(root->left, p, q);
//        }
//        else if (pInRightTree && qInRightTree) {
//            return lowestCommonAncestor(root->right, p, q);
//        }
//        else {
//            return root;
//        }
//    }
//};
///**二叉树的层序遍历II
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
//    vector<vector<int>> levelOrderBottom(TreeNode* root) {
//        vector<vector<int>> vv;
//        queue<TreeNode*> q;
//        int levelsize = 0;
//
//        if (root)
//        {
//            q.push(root);
//            levelsize = 1;
//        }
//
//        while (!q.empty())
//        {
//            vector<int> v;
//            while (levelsize--)
//            {
//                TreeNode* front = q.front();
//                q.pop();
//                v.push_back(front->val);
//
//                if (front->left)
//                {
//                    q.push(front->left);
//                }
//
//                if (front->right)
//                {
//                    q.push(front->right);
//                }
//
//            }
//
//            vv.push_back(v);
//            levelsize = q.size();
//
//        }
//
//        reverse(vv.begin(), vv.end());
//        return vv;
//    }
//};

//二叉树的层序遍历
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
//    vector<vector<int>> levelOrder(TreeNode* root) {
//        vector<vector<int>> vv;
//        queue<TreeNode*> q;
//        int levelsize = 0;
//
//        if (root)
//        {
//            q.push(root);
//            levelsize = 1;
//        }
//
//        while (!q.empty())
//        {
//            vector<int> v;
//            while (levelsize--)
//            {
//                TreeNode* front = q.front();
//                q.pop();
//                v.push_back(front->val);
//
//                if (front->left)
//                {
//                    q.push(front->left);
//                }
//
//                if (front->right)
//                {
//                    q.push(front->right);
//                }
//
//            }
//
//            vv.push_back(v);
//            levelsize = q.size();
//
//        }
//
//        return vv;
//    }
//};
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
//    vector<vector<int>> levelOrderBottom(TreeNode* root) {
//        vector<vector<int>> vv;
//        queue<TreeNode*> q;
//        int levelsize = 0;
//
//        if (root)
//        {
//            q.push(root);
//            levelsize = 1;
//        }
//
//        while (!q.empty())
//        {
//            vector<int> v;
//            while (levelsize--)
//            {
//                TreeNode* front = q.front();
//                q.pop();
//                v.push_back(front->val);
//
//                if (front->left)
//                {
//                    q.push(front->left);
//                }
//
//                if (front->right)
//                {
//                    q.push(front->right);
//                }
//
//            }
//
//            vv.push_back(v);
//            levelsize = q.size();
//
//        }
//
//        reverse(vv.begin(), vv.end());
//        return vv;
//    }
//};

//class Solution {
//public:
//	vector<int> preorderTraversal(TreeNode* root) {
//		stack<TreeNode*> s;
//		vector<int> v;
//		TreeNode* cur = root;
//		while (cur || !s.empty())
//		{
//			// 访问一颗树的开始
//			// 1、访问左路结点，左路结点入栈
//			while (cur)
//			{
//				v.push_back(cur->val);
//				s.push(cur);
//				cur = cur->left;
//			}
//			// 2、从栈中依次访问左路结点的右子树
//			TreeNode* top = s.top();
//			s.pop();
//			// 循环子问题方式访问左路结点的右子树 --
//			cur = top->right;
//		}
//		return v;
//	}
//};
//class Solution {
//public:
//	vector<int> inorderTraversal(TreeNode* root) {
//		stack<TreeNode*> st;
//		TreeNode* cur = root;
//		vector<int> v;
//		while (cur || !st.empty())
//		{
//			// 访问一颗树的开始
//			// 1、左路结点入栈
//			while (cur)
//			{
//				st.push(cur);
//				cur = cur->left;
//			}
//			// 访问问左路结点 和 左路结点的右子树
//			TreeNode* top = st.top();
//			st.pop();
//			v.push_back(top->val);
//			// 循环子问题方式访问右子树
//			cur = top->right;
//		}
//		return v;
//	}
//};
//class Solution {
//public:
//	vector<int> postorderTraversal(TreeNode* root) {
//		TreeNode* cur = root;
//		stack<TreeNode*> s;
//		vector<int> v;
//		TreeNode* prev = nullptr;
//		while (cur || !s.empty())
//		{
//			// 1、访问一颗树的开始
//			while (cur)
//			{
//				s.push(cur);
//				cur = cur->left;
//			}
//			TreeNode* top = s.top();
//			// top结点的右为空 或者 上一个访问结点等于他的右孩子
//			// 那么说明(空)不用访问 或者 (不为空)右子树已经访问过了
//			// 那么说明当前结点左右子树都访问过了，可以访问当前结点了
//			if (top->right == nullptr || top->right == prev)
//			{
//				s.pop();
//				v.push_back(top->val);
//				prev = top;
//			}
//			else
//			{
//				// 右子树不为空，且没有访问，循环子问题方式右子树
//				cur = top->right;
//			}
//		}
//		return v;
//	}
//};

//class Solution {
//public:
//	TreeNode* _buildTree(vector<int>& preorder, vector<int>& inorder, int&
//		prei, int inbegin, int inend) {
//		if (inbegin > inend)
//			return nullptr;
//		// 前序确定根
//		TreeNode* root = new TreeNode(preorder[prei++]);
//		// 根分割中序左右子区间
//		int rooti = inbegin;
//		while (rooti <= inend)
//		{
//			if (inorder[rooti] == root->val)
//				break;
//			else
//				rooti++;
//		}
//		// 递归左右子区间，递归构建左右子树
//		// [inbegin, rooti-1] rooti [rooti+1, inend]
//		root->left = _buildTree(preorder, inorder, prei, inbegin, rooti - 1);
//		root->right = _buildTree(preorder, inorder, prei, rooti + 1, inend);
//		return root;
//	}
//	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//		int i = 0;
//		TreeNode* root = _buildTree(preorder, inorder, i, 0, inorder.size() - 1);
//		return root;
//	}
//};

//class Solution {
//public:
//	void InOrderConvert(Node* cur, Node*& prev)
//	{
//		if (cur == nullptr)
//			return;
//		// 中序遍历
//		InOrderConvert(cur->left, prev);
//		// 当前结点的左，指向前一个结点
//		cur->left = prev;
//		// 前一个结点的右，指向当前结点
//		if (prev)
//			prev->right = cur;
//		prev = cur;
//		InOrderConvert(cur->right, prev);
//	}
//	Node* treeToDoublyList(Node* root) {
//		if (root == nullptr)
//			return nullptr;
//		Node* prev = nullptr;
//		InOrderConvert(root, prev);
//		// 从根开始往左走，找到第一个结点
//		Node* head = root;
//		while (head->left)
//		{
//			head = head->left;
//		}
//		// head为第一个结点，prev是最后一个结点
//		// 题目要求为循环链表，进行一些链接
//		head->left = prev;
//		prev->right = head;
//		return head;
//	}
//};

//class Solution {
//public:
//	// 查找x是否在树中
//	bool IsInTree(TreeNode* root, TreeNode* x)
//	{
//		if (root == nullptr)
//			return false;
//		return root == x
//			|| IsInTree(root->left, x)
//			|| IsInTree(root->right, x);
//	}
//	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//		if (root == NULL)
//			return NULL;
//		if (root == p || root == q)
//		{
//			return root;
//		}
//		// 这里要注意，这里的命名非常关键，命名好了，代码可读性大大增强
//		bool pInLeft, pInRight, qInLeft, qInRight;
//		// 题目中有说明p和q一定是树中的结点
//		// p不在左树就在右树
//		pInLeft = IsInTree(root->left, p);
//		pInRight = !pInLeft;
//		// q不在左树就在右树
//		qInLeft = IsInTree(root->left, q);
//		qInRight = !qInLeft;
//		// 一个在左，一个在右，那么root就是最近公共祖先
//		// 都在左，递归去左树查找
//		// 都在右，递归去右树查找
//		if ((pInLeft && qInRight) || (qInLeft && pInRight))
//		{
//			return root;
//		}
//		else if (pInLeft && qInLeft)
//		{
//			return lowestCommonAncestor(root->left, p, q);
//		}
//		else if (pInRight && qInRight)
//		{
//			return lowestCommonAncestor(root->right, p, q);
//		}
//		// 虽然执行逻辑不会走到这里，但是如果不写这个代码，语法逻辑过不去(相当于语法上走
//		到这没返回值)
//		// 编译器会报语法错误。
//		assert(false);
//		return NULL;
//	}
//};
//class Solution {
//public:
//	bool GetPath(TreeNode* root, TreeNode* x, stack<TreeNode*>& path)
//	{
//		if (root == nullptr)
//			return false;
//		// 前序遍历的思路，找x结点的路径
//		// 遇到root结点先push入栈，因为root就算不是x，但是root可能是根->x路径中一个分
//		支结点
//			path.push(root);
//		if (root == x)
//			return true;
//		if (GetPath(root->left, x, path))
//			return true;
//		if (GetPath(root->right, x, path))
//			return true;
//		// 如果左右子树都没有x，那么说明上面入栈的root不是根->x路径中一个分支结点
//		// 所以要pop出栈，回退，继续去其他分支路径进行查找
//		path.pop();
//		return false;
//	}
//	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//		stack<TreeNode*> pPath, qPath;
//		GetPath(root, p, pPath);
//		GetPath(root, q, qPath);
//		// 模拟链表相交，两个路径找交点
//		// 长的先走差距步，再一起走找交点
//		while (pPath.size() != qPath.size())
//		{
//			if (pPath.size() > qPath.size())
//				pPath.pop();
//			else
//				qPath.pop();
//		}
//		while (pPath.top() != qPath.top())
//		{
//			pPath.pop();
//			qPath.pop();
//		}
//		return pPath.top();
//	}
//};

//class Solution {
//public:
//	vector<vector<int>> levelOrder(TreeNode* root) {
//		vector<vector<int>> vv;
//		queue<TreeNode*> q;
//		int levelSize = 0;
//		if (root)
//		{
//			q.push(root);
//			levelSize = 1;
//		}
//		while (!q.empty())
//		{
//			vector<int> v;
//			// 控制一层出完
//			while (levelSize--)
//			{
//				TreeNode* front = q.front();
//				q.pop();
//				v.push_back(front->val);
//				if (front->left)
//					q.push(front->left);
//				if (front->right)
//					q.push(front->right);
//			}
//			// 当前层出完了，下一层都进队列了，队列size就是下一层数据个数
//			levelSize = q.size();
//			// 获取到每一层数据放到二维数组中
//			vv.push_back(v);
//		}
//		return vv;
//	}
//};

//class Solution {
//public:
//	// 走前序遍历二叉树转换
//	string tree2str(TreeNode* root) {
//		if (root == nullptr)
//			return "";
//		string ret = to_string(root->val);
//		// 1、左右都为空，要省略括号
//		// 2、右为空，要省略括号
//		// 3、左为空，右不为空，不能省略括号
//		// 左边和右边有一个为空，左边必须有括号
//		if (root->left || root->right)
//		{
//			ret += '(';
//			ret += tree2str(root->left);
//			ret += ')';
//		}
//		if (root->right)
//		{
//			ret += '(';
//			ret += tree2str(root->right);
//			ret += ')';
//		}
//		return ret;
//	}
//};

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