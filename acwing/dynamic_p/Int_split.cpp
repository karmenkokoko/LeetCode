#include <iostream>
// 整数划分
using namespace std;

const int N = 100010, mod = 1e9+7;
int n;
int f[N];

int main()
{
    cin >> n;
    f[0] = 1;
    // 前i个数恰好拼成j的方案数
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            f[j] = (f[j] + f[j - i]) % mod;
        }
    }
    cout << f[n] << endl;
    return 0;
}