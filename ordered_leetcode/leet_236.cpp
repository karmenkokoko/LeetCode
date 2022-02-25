#include <bits/stdc++.h>
#include "basic.h"
using namespace std;

// 236. 二叉树的最近公共祖先
// 给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。

// 百度百科中最近公共祖先的定义为：“对于有根树 T 的两个节点 p、q，
// 最近公共祖先表示为一个节点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return nullptr; // 找不到返回nullptr 作为一个标记
        
        if(root->val == p->val || root->val == q->val)
            return root;
        // 若有一个是根，那么返回这个点

        // 如果找不到， 那么从左右子树找
        // 返回查找的结果
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        // 如果left 和 right有一个为nullptr 返回另一个子树
        if(left == nullptr)
            return right;

        if(right == nullptr)
            return left;

        // 若左右子树都有 那么最近祖先就是root
        return root;
    }
};