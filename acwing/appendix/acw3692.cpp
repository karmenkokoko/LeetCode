#include <bits/stdc++.h>

using namespace std;
// 3692. 最长连续公共子序列

// 输入两个字符串 s1,s2。

// 输出最长连续公共子串长度和最长连续公共子串。

// 输入格式
// 一行，两个字符串 s1,s2，用空格隔开。

// 输出格式
// 第一行输出最长连续公共子串的长度

// 第二行输出最长连续公共子串。如果不唯一，则输出最后一个。
const int N = 110;

string a, b;
int dp[N][N];

int main()
{
    cin >> a >> b;
    string r;
    int res = 0;
    int end = 0;
    for (int i = 1; i <= a.size(); i++)
    {
        for (int j = 1; j <= b.size(); j++)
        {
            if(a[i-1] == b[j-1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            if(dp[i][j] >= res)
            {
                res = dp[i][j];
                end = i;
            }
        }
    }

    cout << res << endl;
    for (int i = end - res; i < end; i++)
    {
        r += a[i];
    }

    cout << r << endl;
    return 0;
}
