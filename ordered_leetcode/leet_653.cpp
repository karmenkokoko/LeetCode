#include <bits/stdc++.h>

using namespace std;
// 653. 两数之和 IV - 输入 BST
// 给定一个二叉搜索树 root 和一个目标结果 k，如果 BST 中存在两个元素且它们的和等于给定的目标结果，则返回 true。

// dfs

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
    bool findTarget(TreeNode* root, int k) {
        set<int> st;
        return dfs(st, root, k);
    }

    bool dfs(set<int>& st, TreeNode* root, int target)
    {
        if(!root) return false;
        if(st.count(target-root->val)) return true;
        st.insert(root->val);

        return dfs(st, root->right, target) || dfs(st, root->left, target);
    }
};