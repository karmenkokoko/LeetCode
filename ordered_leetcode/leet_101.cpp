#include <bits/stdc++.h>

using namespace std;
// 对称二叉树的判断

class Solution {
private:
    struct TreeNode{
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };
public:
    bool isSymmetric(TreeNode* root) {
        // 创建左右子树的两个指针，分别判断
        if(!root) return true;
        return dfs(root->left, root->right);
    }

    bool dfs(TreeNode* p, TreeNode* q)
    {
        if(!p && !q) return true;
        if(!p || !q) return false;
        return p->val == q->val && dfs(p->left, q->right) && dfs(p->right, q->left);
    }
};