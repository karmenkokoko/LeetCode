#include <bits/stdc++.h>

using namespace std;
// 组合总和3
// k表示一个集合的大小，n表示target
// 从1-9  9个数字中挑k个=n的组合
// 不能选多次

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<bool> st;
    vector<vector<int>> combinationSum3(int k, int n) {
        st = vector<bool>(10, false);
        dfs(1, 0, k, n);
        return res;
    }

    void dfs(int begin_num, int idx, int k, int target)
    {
        if(target < 0)
        {
            return;
        }
        if(target == 0)
        {
            if(idx == k)
            {
                res.push_back(path);
                return;
            }
            else{
                return;
            }
        }

        for(int i = begin_num; i <= 9; i++)
        {
            if(!st[i])
            {
                st[i] = true;
                path.push_back(i);
                dfs(i, idx+1, k, target-i);
                path.pop_back();
                st[i] = false;
            }
        }
    }
};