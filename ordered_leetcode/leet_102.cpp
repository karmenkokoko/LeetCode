#include <bits/stdc++.h>

using namespace std;
// 二叉树层次遍历

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
    vector<vector<int>> res;
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size())
        {
            int size = q.size();
            // 记录这层的数量，然后全部遍历
            vector<int> level;
            for(int i = 0; i < size; i++)
            {
                auto t = q.front();
                q.pop();
                level.push_back(t->val);
                if(t->left)
                {
                    q.push(t->left);
                }
                if(t->right)
                {
                    q.push(t->right);
                }
            }
            res.push_back(level);
        }
        return res;
    }
};