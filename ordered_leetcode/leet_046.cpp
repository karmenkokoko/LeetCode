#include <bits/stdc++.h>

using namespace std;
// 全排列1
// 给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    set<int> st;
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        int n = nums.size();
        path = vector<int>(n);
        dfs(0, nums);
        return res;
    }

    void dfs(int x, vector<int>& nums)
    {
        if(x == nums.size())
        {
            res.emplace_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if(!st.count(i))
            {
                path[i] = nums[i];
                st.insert(i);
                dfs(x + 1, nums);
                st.erase(i);
            }
        }
    }
};