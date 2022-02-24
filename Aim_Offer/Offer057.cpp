// 剑指 Offer 57. 和为s的两个数字
// 输入一个递增排序的数组和一个数字s，在数组中查找两个数，使得它们的和正好是s。
// 如果有多对数字的和等于s，则输出任意一对即可。

#include <bits/stdc++.h>

using namespace std;

// 双指针
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        vector<int> res;
        for(int i = 0; i < n; i++)
        {
            int j = n-1;
            int target_temp = target-nums[i];
            while(target_temp < nums[j])
            {
                j--;
            }
            if(target_temp == nums[j])
            {
                res = vector<int> {nums[i], nums[j]};
                return res;
            }
            if(target_temp != nums[j]) continue;
        }
        return res;
    }
};