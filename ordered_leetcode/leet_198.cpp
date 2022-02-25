#include <bits/stdc++.h>

using namespace std;
// 198. 打家劫舍
// 你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，
// 影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

// 给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。

// dp 存到这个点为止选择的最大值
// k 表示用从i开始前k个的dp
class Solution{
public:
    int rob(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> dp(n + 1, 0);
        dp[1] = nums[0];

        for (int i = 2; i <= n; i++)
        {
            for (int k = 2; k <= i; k++)
            {
                // 记得比较前一个状态的dp[i] 
                // 因为dp[i]一直在被更新
                // 比较dp[i-1] 是因为dp[i]和dp[i-1]只能有一个
                dp[i] = max(dp[i], max(dp[i - 1], dp[i - k] + nums[i - 1]));
            }
        }
        return dp[n];
    }
};