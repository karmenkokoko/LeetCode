#include <bits/stdc++.h>

using namespace std;

// 组合总和
// 数字可以用多次，但不重复

class Solution{
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtrack(candidates, 0, target);
        return res;
    }
    void backtrack(vector<int>& candidates, int begin, int target)
    {
        if(target < 0)
        {
            return;
        }
        if(target == 0)
        {
            res.push_back(path);
            return;
        }

        for (int i = begin; i < candidates.size(); i++)
        {
            path.push_back(candidates[i]);
            // 递归从这个candidate开始的数字, 不能用前面已经用过的, 这样就能去除集合中的重复
            backtrack(candidates, i, target - candidates[i]);
            path.pop_back();
        }
    }
};