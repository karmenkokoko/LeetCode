#include <bits/stdc++.h>

using namespace std;
// 分割回文串
// dp+回溯算法

// dp 存储从x开始i结束的字符串是否为回文串
class Solution{
public:
    vector<vector<string>> res;
    vector<string> cur_path;
    vector<vector<bool>> dp;
    int n;

    vector<vector<string>> partition(string s)
    {
        n = s.size();
        dp.assign(n, vector<bool>(n, true));
        for (int i = n - 1; i >= 0; --i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                dp[i][j] = dp[i + 1][j - 1] && (s[i] == s[j]);
            }
        }

        dfs(s, 0);
        return res;
    }

    void dfs(string& s, int begin)
    {
        if(begin == n)
        {
            res.push_back(cur_path);
            return;
        }
        for (int i = begin; i < n; i++)
        {
            if(dp[begin][i])
            {
                cur_path.push_back(s.substr(begin, i - begin + 1));
                dfs(s, i + 1);
                cur_path.pop_back();
            }
        }
    }
};