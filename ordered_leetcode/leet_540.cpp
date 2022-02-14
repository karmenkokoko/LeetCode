#include <bits/stdc++.h>

using namespace std;

// 540. 有序数组中的单一元素
// 给你一个仅由整数组成的有序数组，其中每个元素都会出现两次，唯有一个数只会出现一次。

// 请你找出并返回只出现一次的那个数。

// 你设计的解决方案必须满足 O(log n) 时间复杂度和 O(1) 空间复杂度。


// 由于是排序的， 可以用二分
// 异或的话是遍历一遍，O(n)时间
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while(l < r)
        {
            int mid = (l + r) >> 1;
            if(check(nums, mid))
                l = mid + 1;
            else
                r = mid;
        }
        return nums[r];
    }

    bool check(vector<int>& nums, int mid)
    {
        // mid为奇数时
        if(mid & 1)
        {
            if (mid + 1 < nums.size() && nums[mid] == nums[mid+1])
                return false;
            else
                return true;
        }
        // mid为偶数时
        else{
            if (mid + 1 < nums.size() && nums[mid] == nums[mid+1])
                return true;
            else
                return false;
        }
    }
};