#include <bits/stdc++.h>

using namespace std;
// 递增子序列
// 给你一个整数数组 nums ，找出并返回所有该数组中不同的递增子序列，递增子序列中 至少有两个元素 。你可以按 任意顺序 返回答案。
// 数组中可能含有重复元素，如出现两个整数相等，也可以视作递增序列的一种特殊情况。

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    
    vector<vector<int>> findSubsequences(vector<int> &nums)
    {
        dfs(nums, 0);
        return res;
    }

    void dfs(const vector<int>& nums, int begin)
    {
        if(path.size() > 1)
        {
            res.push_back(path);
            return;
        }
        unordered_set<int> st; // st指示本一层的重复使用情况 每一层都会有一个st
        for (int i = begin; i < nums.size(); i++)
        {
            if((!path.empty() && nums[i] < path.back()) || st.count(nums[i]) > 0)
            {
                continue;
            }
            st.insert(nums[i]);
            path.push_back(nums[i]);
            dfs(nums, i);
            path.pop_back();
            // st不需要erase
        }
    }
};