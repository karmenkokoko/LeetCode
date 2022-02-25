#include <bits/stdc++.h>

using namespace std;
// 152. 乘积最大子数组
// 给你一个整数数组 nums ，请你找出数组中乘积最大的非空连续子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。

// 测试用例的答案是一个 32-位 整数。

// 子数组 是数组的连续子序列。


// 光记录最大还不行，要记录前i个的最小值

class Solution{
public:
    int maxProduct(vector<int>& nums)
    {
        int n = nums.size();

        // 直接把nums赋给dp
        vector<int> dp_min(nums), dp_max(nums);

        for (int i = 1; i < n; i++)
        {
            dp_min[i] = min(min(dp_min[i - 1] * nums[i], nums[i]), dp_max[i-1] * nums[i]);
            dp_max[i] = max(max(dp_max[i - 1] * nums[i], nums[i]), dp_min[i-1] * nums[i]);
        }

        int res = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            res = max(res, dp_max[i]);
        }
        return res;
    }
};