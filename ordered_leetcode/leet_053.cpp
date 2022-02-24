#include <bits/stdc++.h>

using namespace std;

// 53. 最大子数组和
// 给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

// 子数组 是数组中的一个连续部分。

// 同时输出开始坐标和结束坐标

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int start=0, end=0;
        int res = INT_MIN;
        // 拿start和end记录一下就好，sum > 0 那加，  小于0可以判断为从这个点重新开始
        for(int i = 0; i < n; i++)
        {
            if(sum > 0)
            {
                sum += nums[i];
            }
            else{
                start = i;
                end = i+1;
                sum = nums[i];
            }
            if(sum > res)
            {
                res = sum;
                end = i;
            }
        }
        printf("%d %d", start, end);
        return res;
    }
};