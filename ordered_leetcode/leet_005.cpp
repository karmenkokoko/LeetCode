#include <bits/stdc++.h>
#include <iostream>

using namespace std;
// 最长回文子串

// 中心扩展
// dp


class Solution {
public:
    pair<int, int> parsesubstring(const string& s, int l, int r)
    {
        while(l >= 0 && r < s.size() && s[l] == s[r])
        {
            --l;
            ++r;
        }
        return {l+1, r-1};
    }


    string longestPalindrome(string s) {
        int n = s.size();

        int left = 0;
        int right = 0;

        pair<int, int> p1, p2;
        for (int i = 0; i < n; i++)
        {
            p1 = parsesubstring(s, i, i+1);
            p2 = parsesubstring(s, i, i);
            int left1 = p1.first, right1 = p1.second;
            int left2 = p2.first, right2 = p2.second;
            if (right1 - left1 > right - left)
            {
                left = left1;
                right = right1;

            }
            if(right2 - left2 > right - left)
            {
                left = left2;
                right = right2;
            }

        }

        return s.substr(left, right-left+1);
    }
};

class Solution2 {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n < 2) {
            return s;
        }

        int maxLen = 1;
        int begin = 0;
        // dp[i][j] 表示 s[i..j] 是否是回文串
        vector<vector<int>> dp(n, vector<int>(n));
        // 初始化：所有长度为 1 的子串都是回文串
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }
        // 递推开始
        // 先枚举子串长度
        for (int L = 2; L <= n; L++) {
            // 枚举左边界，左边界的上限设置可以宽松一些
            for (int i = 0; i < n; i++) {
                // 由 L 和 i 可以确定右边界，即 j - i + 1 = L 得
                int j = L + i - 1;
                // 如果右边界越界，就可以退出当前循环
                if (j >= n) {
                    break;
                }

                if (s[i] != s[j]) {
                    dp[i][j] = false;
                } else {
                    // 相等的情况
                    if (j - i < 3) {
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }

                // 只要 dp[i][L] == true 成立，就表示子串 s[i..L] 是回文，此时记录回文长度和起始位置
                if (dp[i][j] && j - i + 1 > maxLen) {
                    maxLen = j - i + 1;
                    begin = i;
                }
            }
        }
        return s.substr(begin, maxLen);
    }
};
