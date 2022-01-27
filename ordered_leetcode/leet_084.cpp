// 数组中的最大矩形
#include <bits/stdc++.h>

using namespace std;

class Solution{

public:
    int largestRectangleArea(vector<int>& heights) {
        // 单调栈
        int n = heights.size();
        vector<int> left(n), right(n);
        stack<int> stk;

        // 找左右两边第一个小于当前值的index, 存到数组中
        // left
        for (int i = 0; i < n; i++)
        {
            while(stk.size() && heights[stk.top()] >= heights[i])
                stk.pop();
            if(stk.empty())
                left[i] = -1; // 边界情况记为-1
            else{
                left[i] = stk.top();
            }
            stk.push(i);
        }

        stk = stack<int>();
        // right
        for (int i = n - 1; i >= 0; i--)
        {
            while(stk.size() && heights[stk.top()] >= heights[i])
                stk.pop();
            if(stk.empty())
                right[i] = n;
            else{
                right[i] = stk.top();
            }
            stk.push(i);
        }

        int res = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            res = max(res, (right[i] - left[i] - 1) * heights[i]);
        }
        return res;
    }
};