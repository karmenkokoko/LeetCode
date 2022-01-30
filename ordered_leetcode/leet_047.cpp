#include <bits/stdc++.h>

using namespace std;
// 全排列 任意数字 有重复数字

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