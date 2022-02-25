#include <bits/stdc++.h>

using namespace std;

// 139. 单词拆分
// 给你一个字符串 s 和一个字符串列表 wordDict 作为字典。请你判断是否可以利用字典中出现的单词拼接出 s 。

// 注意：不要求字典中出现的单词全部都使用，并且字典中的单词可以重复使用。

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // dp指前i个字母是否能够用字典字母组合
        int n = s.size();
        vector<bool> dp(n + 1, false);

        dp[0] = true;
        for (int i = 1; i <= n; i++)
        {
            if(dp[i-1])
            {
                for (int j = 0; j < wordDict.size(); j++)
                {
                    int len = wordDict[j].length();
                    string sub = s.substr(i - 1, len);
                    if(sub == wordDict[j])
                    {
                        dp[i + len - 1] = true;
                    }
                }
            }
        }
        return dp[n];
    }
};