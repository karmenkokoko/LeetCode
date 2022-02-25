// 283. 移动零
// 给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

// 请注意 ，必须在不复制数组的情况下原地对数组进行操作。

#include <bits/stdc++.h>

using namespace std;

// 双指针， r不为零则交换， 保持l和r之间全是0
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 0;
        while(r < n)
        {
            if(nums[r])
            {
                swap(nums[l], nums[r]);
                l++;
            }
            r++;
        }
    }
};