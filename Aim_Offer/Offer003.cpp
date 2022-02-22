// 剑指 Offer 03. 数组中重复的数字
// 找出数组中重复的数字。


// 在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。
// 数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int n = nums.size();
        int st[n];
        memset(st, 0, sizeof st);
        int res;
        for(int i = 0; i < n; i++)
        {
            st[nums[i]]++;
            if(st[nums[i]] > 1)
            {
                res = nums[i];
                break;
            }
        }
        return res;
    }
};