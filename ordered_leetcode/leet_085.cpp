#include <bits/stdc++.h>

using namespace std;

// 给定一个仅包含 0 和 1 、大小为 rows x cols 的二维二进制矩阵，找出只包含 1 的最大矩形，并返回其面积。
// 084的扩展，对每一行使用084单调栈做法.
// 首先第一步预处理高度，用dp的思考，求取第i行往上还有多少行


class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> heights(n, vector<int>(m, 0));
        // 求取每一行的高度
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(matrix[i][j] == '1')
                {
                    if(i) heights[i][j] = heights[i-1][j] + 1;
                    else heights[i][j] = 1;
                }
            }
        }
        int res = 0;
        for(int i = 0; i < n; i++)
        {
            res = max(res, get_largest_rectangle(heights[i]));
        }
        return res;
    }
    // 084
    int get_largest_rectangle(vector<int>& heights)
    {
        int n = heights.size();
        vector<int> left(n), right(n);

        stack<int> stk;
        for(int i = 0; i < n; i++)
        {
            while(stk.size() && heights[stk.top()] >= heights[i]) stk.pop();
            if(stk.empty()) left[i] = -1;
            else left[i] = stk.top();
            stk.push(i);
        }

        stk = stack<int>();
        for(int i = n-1; i >= 0; i--)
        {
            while(stk.size() && heights[stk.top()] >= heights[i]) stk.pop();
            if(stk.empty()) right[i] = n;
            else right[i] = stk.top();
            stk.push(i);
        }

        int res = 0;
        for(int i = 0; i < n; i++)
        {
            res = max(res, (right[i] - left[i] - 1) * heights[i]);
        }
        return res;
    }
};