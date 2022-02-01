#include <bits/stdc++.h>

using namespace std;
// 子集2
// 有重复数字
// 先排序，然后加入标记

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<bool> st;
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        int n = nums.size();
        st = vector<bool>(n, false);
        sort(nums.begin(), nums.end());
        dfs(nums, 0);
        return res;
    }

    void dfs(vector<int>& nums, int begin)
    {
        res.push_back(path);
        for (int i = begin; i < nums.size(); i++)
        {
            if(i > 0 && nums[i] == nums[i-1] && st[i-1] == false)
            {
                continue;
            }
            if(!st[i])
            {
                st[i] = true;
                path.push_back(nums[i]);
                dfs(nums, i + 1);
                path.pop_back();
                st[i] = false;
            }
        }
    }
};