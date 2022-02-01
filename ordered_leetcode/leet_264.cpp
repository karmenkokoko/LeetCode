#include <bits/stdc++.h>

using namespace std;
// 丑数
// 只包含为2, 3, 5质因子的数
class leet_264
{
public:
    int nthUglyNumber(int n)
    {
        vector<int> dp(n + 1);
        dp[0] = 1;
        // a, b, c记录是2， 3， 5的第几个倍数  有点像线性筛
        int a = 0, b = 0, c = 0;
        // dp表示第i+1个丑数的值
        for (int i = 1; i < n + 1; i++)
        {
            int pow_2 = dp[a] * 2;
            int pow_3 = dp[b] * 3;
            int pow_5 = dp[c] * 5;
            dp[i] = min(pow_2, min(pow_3, pow_5));
            if(dp[i] == pow_2)
                a++;
            if(dp[i] == pow_3)
                b++;
            if(dp[i] == pow_5)
                c++;
            
        }
        return dp[n - 1];
    }
};

