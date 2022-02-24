#include <bits/stdc++.h>

using namespace std;

// 35. 搜索插入位置
// 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

// 请必须使用时间复杂度为 O(log n) 的算法。

// 二分
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n-1;
        while(l < r)
        {
            int mid = (l + r) >> 1;
            if(nums[mid] >= target) r = mid;
            else l = mid+1;

        }
        if(target > nums[l]) return l+1;
        return l;
    }
};