#include <bits/stdc++.h>

using namespace std;

// 组合总和2
// 数字可以用1次，有重复数字

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<bool> st; // 加入用过标记
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        st = vector<bool>(n, false);
        sort(candidates.begin(), candidates.end()); // 排序来判断两个是否是一样的
        dfs(candidates, 0, target);

        return res;
    }

    void dfs(vector<int>& candidates, int begin, int target)
    {
        if(target < 0)
        {
            return;
        }
        if(target == 0)
        {
            res.push_back(path);
            return ;
        }

        for(int i = begin; i < candidates.size(); i++)
        {
            if(i > 0 && candidates[i] == candidates[i-1] && st[i-1] == false)
            {
                continue;
            }
            if(!st[i])
            {
                path.push_back(candidates[i]);
                st[i] = true;
                dfs(candidates, i, target-candidates[i]);
                st[i] = false;
                path.pop_back();
            }
        }
    }
};