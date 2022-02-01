#include <bits/stdc++.h>

using namespace std;
// 组合
// 给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。
// 你可以按 任何顺序 返回答案。

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> combine(int n, int k)
    {

        dfs(n, k, 1);
        return res;
    }
    void dfs(int n, int k, int index)
    {
        // 这里必须是path.size， 不能是index。
        // index算是避免使用前面的数字，这里index直接返回了就没了

        if(path.size() == k)
        {
            res.push_back(path);
            return;
        }

        for (int i = index; i < n; i++)
        {
            path.push_back(i + 1);
            dfs(n, k, i + 1);
            path.pop_back();
        }
    }
};