// 113. 路径总和 II
// 给你二叉树的根节点 root 和一个整数目标和 targetSum ，找出所有 从根节点到叶子节点 路径总和等于给定目标和的路径。

// 叶子节点 是指没有子节点的节点。

#include <bits/stdc++.h>
#include "basic.h"

using namespace std;
// 经典的dfs
class Solution{
public:
    vector<vector<int>> res;
    vector<int> cur;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root, targetSum);
        return res;
    }

    void dfs(TreeNode* root, int target)
    {
        if(!root)
            return;

        cur.push_back(root->val);
        target -= root->val;
        if (target == 0 && !root->left && !root->right)
        {
            res.push_back(cur);
            // 这里不需要return， 因为会造成cur里面还剩东西
        }
        dfs(root->left, target);
        dfs(root->right, target);

        cur.pop_back();
    }
};