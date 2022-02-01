#include <bits/stdc++.h>

using namespace std;

// 列出所有子集

class Solution{
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> subsets(vector<int> &nums)
    {
        dfs(nums, 0);
        return res;
    }
    void dfs(vector<int>& nums, int begin)
    {
        // 和组合不同的是直接加入res， 不用判断条件
        res.push_back(path);
        for (int i = begin; i < nums.size(); i++)
        {
            path.push_back(nums[i]);
            dfs(nums, i + 1);
            path.pop_back();
        }
    }
};