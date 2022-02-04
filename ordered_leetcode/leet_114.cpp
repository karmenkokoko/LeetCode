#include <bits/stdc++.h>

using namespace std;


class Solution{
private:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

public:
    // 找到先序遍历的前驱节点
    // 前驱节点的右子树为当前节点的右子树
    // 当前节点的右子树改为next节点，左子树置空
    /*
           o
        /     \
       o<-next o
      / \       \
     o   o<-pre  o
    */
    void flatten(TreeNode* root) {
        TreeNode *temp = root;
        while(temp)
        {
            if(temp->left)
            {
                auto next = temp->left;
                auto pre = next;
                while(pre->right)
                {
                    pre = pre->right;
                }
                pre->right = temp->right;
                temp->right = next;
                temp->left = nullptr;
            }
            temp = temp->right;
        }
    }
};