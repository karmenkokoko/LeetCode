// 41. 缺失的第一个正数
// 给你一个未排序的整数数组 nums ，请你找出其中没有出现的最小的正整数。

// 请你实现时间复杂度为 O(n) 并且只使用常数级别额外空间的解决方案。
#include <bits/stdc++.h>
using namespace std;
// 原地哈希， 给他进行标记
class Solution
{
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if(nums[i] <= 0)
                nums[i] = n + 1;
        }

        for (int i = 0; i < n; i++)
        {
            int num = abs(nums[i]);
            // 重复数字
            if(num >= 1 && num <= n && nums[num-1] > 0)
                nums[num - 1] = -nums[num - 1];
        }

        for (int i = 0; i < n; i++)
        {
            if(nums[i] > 0)
                return i + 1;
        }

        return n + 1;
    }
};