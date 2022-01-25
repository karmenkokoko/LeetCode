#include <iostream>
#include <cstring>

using namespace std;
// 最短汉密尔顿距离
const int N = 20, M = 1 << N;
int n;
int f[M][N], a[N][N];
// f[i][j] i表示经过点，j表示结束index


int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    memset(f, 0x3f, sizeof f);
    f[1][0] = 0;

    for (int i = 0; i < 1 << n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(i >> j & 1)
            {
                // 举例中间状态 和区间dp有点像
                for (int k = 0; k < n; k++)
                {
                    if(i >> k & 1)
                    {
                        f[i][j] = min(f[i][j], f[i - (1 << j)][k] + a[k][j]);
                    }
                }
            }
        }
    }
    
    cout << f[(1 << n)  - 1][n - 1] << endl;

    return 0;
}
