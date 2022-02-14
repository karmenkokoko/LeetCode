// 剑指 Offer 21. 调整数组顺序使奇数位于偶数前面
// 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有奇数在数组的前半部分，所有偶数在数组的后半部分。

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int i = 0, j = nums.size() - 1;
        // while
        // do while的开始index有不同
        // do while不好处理空串
        while(i < j)
        {
            while(i < j && (nums[i] & 1) == 1)
                i++;
            while(i < j && (nums[j] & 1) == 0)
                j++;
            swap(nums[i], nums[j]);
        }

        return nums;
    }
};