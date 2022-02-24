#include <bits/stdc++.h>
// 剑指 Offer 32 - II. 从上到下打印二叉树 II
// 从上到下按层打印二叉树，同一层的节点按从左到右的顺序打印，每一层打印到一行。
using namespace std;

class Solution {
private:
     struct TreeNode {
        int val;
         TreeNode *left;
         TreeNode *right;
         TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };
public:
    vector<vector<int>> res;
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size())
        {
            vector<int> cur;
            int n = q.size();
            for(int i = 0; i < n; i++)
            {
                auto t = q.front();
                q.pop();
                cur.push_back(t->val);
                if(t->left)
                {
                    q.push(t->left);
                }
                if(t->right)
                {
                    q.push(t->right);
                }
            }
            res.push_back(cur);
        }
        return res;
    }
};