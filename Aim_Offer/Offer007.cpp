#include <bits/stdc++.h>
// 105. 从前序与中序遍历序列构造二叉树
// 给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历， 
// inorder 是同一棵树的中序遍历，请构造二叉树并返回其根节点。
using namespace std;

class Solution {
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
public:
    unordered_map<int, int> map;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        for(int i = 0; i < n; i++)
        {
            map.insert({inorder[i], i});
        }
        return dfs_build(preorder, 0, n-1, 0, n-1);
    }

    TreeNode* dfs_build(vector<int>& preorder, int left, int right, int inorder_left, int inorder_right)
    {
        if(left > right)
            return nullptr;
        int root_val = preorder[left];
        int inorder_index = map[root_val];
        int left_size = inorder_index - inorder_left;

        TreeNode* root = new TreeNode(root_val);
        root->left = dfs_build(preorder, left+1, left+left_size, inorder_left, inorder_index-1);
        root->right = dfs_build(preorder, left+1+left_size, right, inorder_index+1, inorder_right);
        return root;
    }
};