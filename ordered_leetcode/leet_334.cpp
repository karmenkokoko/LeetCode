#include <bits/stdc++.h>

using namespace std;
// 334. 递增的三元子序列
// 给你一个整数数组 nums ，判断这个数组中是否存在长度为 3 的递增子序列。

// 如果存在这样的三元组下标 (i, j, k) 且满足 i < j < k ，使得 nums[i] < nums[j] < nums[k] ，返回 true ；否则，返回 false 。


class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        vector<int> left_min(n, INT_MAX);
        vector<int> right_max(n, INT_MIN);
        // 记录左右的最小值和最大值
        for(int i = 1; i < n; i++)
        {
            left_min[i] = min(left_min[i-1], nums[i-1]);
        }

        for(int i = n-2; i >= 0; i--)
        {
            right_max[i] = max(right_max[i+1], nums[i+1]);
        }

        for(int i = 0; i < n; i++)
        {
            if(left_min[i] < nums[i] && nums[i] < right_max[i])
            {
                return true;
            }
        }
        return false;
    }
};