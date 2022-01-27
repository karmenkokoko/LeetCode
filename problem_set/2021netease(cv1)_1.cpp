#include <bits/stdc++.h>
// 摘樱桃
// 判断纯净的父母， 左右孩子结构
// 输入描述:
// 第一行两个正整数m, n，空格分开，分别代表总共有树上有多少个节点，和树上有多少条边，2<=m<=100,  1<=n<=100
// 下面有n行，每行为3个部分，用空格分割，第一个数字为某非叶子节点的id, 第二个为该边为left还是right，第三个为子节点的id
// 注意：节点id彼此不会重复，id 1为根节点 

// 输出描述:
// 一个整数，标示符合要求的子结构的数量
using namespace std;

// 建树
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};

const int N = 110;
int m, n;
TreeNode* a[N];

int dfs(TreeNode* root)
{
    if(!root) return 0;
    // 如果左子树或者右子树为空，那么这个node必定不是子结构
    if(!root->left) return dfs(root->right);
    if(!root->right) return dfs(root->left);
    if(!root->left->right && !root->left->left && !root->right->right && !root->right->left) return 1;
    return dfs(root->right) + dfs(root->left);
}

int main()
{
    cin >> m >> n;
    int cnt = 0;
    for(int i = 1; i <= m; i++)
    {
        a[i] = new TreeNode(i);
    }
    while(n--)
    {
        int x, y;
        string str;
        cin >> x >> str >> y;
        if(str == "left")
        {
            a[x]->left = a[y];
        }
        else{
            a[x]->right = a[y];
        }
    }
    cnt = dfs(a[1]);
    cout << cnt << endl;
    return 0;
}