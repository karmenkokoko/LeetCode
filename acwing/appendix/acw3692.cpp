#include <bits/stdc++.h>

using namespace std;

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
