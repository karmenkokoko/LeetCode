#include <bits/stdc++.h>

using namespace std;
// 128. 最长连续序列
// 给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。

// 请你设计并实现时间复杂度为 O(n) 的算法解决此问题。


class Solution{
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> map;
        for(int num:nums)
        {
            map.insert(num);
        }
        int res = 0;
        for(const int& num:nums)
        {
            // num-1不在set中， 那么这个就是序列的第一个数
            if(!map.count(num-1))
            {
                int cur = 1;
                int temp = num;
                while(map.count(temp+1))
                {
                    temp++;
                    cur++;
                }
                res = max(res, cur);
            }
        }
        return res;
    }
};