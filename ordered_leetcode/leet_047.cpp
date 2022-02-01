#include <bits/stdc++.h>

using namespace std;
// 全排列2 任意数字 
// 去重要对元素进行排序，从而判断连续的两个数字是否想等
// 给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        int n = nums.size();
        vector<bool> st(n, false);
        sort(nums.begin(), nums.end());
        dfs(nums, st);

        return res;
    }

    void dfs(vector<int> &nums, vector<bool> &st)
    {
        if(path.size() == nums.size())
        {
            res.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            // 判断两个连续的数字是否相同
            if(i > 0 && nums[i] == nums[i-1] && st[i-1] == false){
                continue;
            }
            if(st[i] == false)
            {
                st[i] = true;
                path.push_back(nums[i]);
                dfs(nums, st);
                path.pop_back();
                st[i] = false;
            }
        }
    }
};