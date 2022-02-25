// 239. 滑动窗口最大值
// 给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。
// 你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。

// 返回 滑动窗口中的最大值 。

#include <bits/stdc++.h>

using namespace std;

// 单调队列
class Solution {
public:
    vector<int> res;
    
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        // 单调队列加入nums的index
        int q[2 * n];
        int hh = 0, tt = -1;
        for (int i = 0; i < n; i++)
        {
            if(hh <= tt && i > q[hh]+k-1)
                hh++;
            while(hh <= tt && nums[q[tt]] <= nums[i])
                tt--;
            q[++tt] = i;
            if(i >= k-1)
                res.push_back(nums[q[hh]]);
        }
        return res;
    }
};