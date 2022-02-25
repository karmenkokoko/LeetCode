#include <bits/stdc++.h>

using namespace std;

// 221. 最大正方形
// 在一个由 '0' 和 '1' 组成的二维矩阵内，找到只包含 '1' 的最大正方形，并返回其面积。

// 重要的思想是用单调栈返回每一个高度左右第一个比他小的值
// 也可以用dp
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {

        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> height(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if(matrix[i][j] == '1')
                {
                    if(!i)
                        height[i][j]++;
                    else
                        height[i][j] = height[i - 1][j] + 1;
                }
            }
        }

        int res = 0;
        for (int i = 0; i < n; i++)
        {
            res = max(res, find_max_matrix(height[i]));
        }
        return res;
    }

    int find_max_matrix(vector<int>& height)
    {
        int m = height.size();
        vector<int> left(m), right(m);

        stack<int> stk_l, stk_r;

        for (int i = 0; i < m; i++)
        {
            while(stk_l.size() && height[stk_l.top()] >= height[i])
                stk_l.pop();
            if(stk_l.empty())
                left[i] = -1;
            else
                left[i] = stk_l.top();
            stk_l.push(i);
        }

        for (int i = m; i >= 0; i--)
        {
            while(stk_r.size() && height[stk_r.top()] >= height[i])
                stk_r.pop();
            if(stk_r.empty())
                right[i] = m;
            else
                right[i] = stk_r.top();
            stk_r.push(i);
        }

        int size = 0;
        for (int i = 0; i < m; i++)
        {
            int side = min((right[i] - left[i] - 1), height[i]);
            size = max(size, side * side);
        }
        return size;
    }
};