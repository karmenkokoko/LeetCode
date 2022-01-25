#include <iostream>
#include <cstring>
// 蒙德里安的梦想
using namespace std;

const int N = 12, M = 1 << N;

typedef long long LL;
int n, m;
LL f[N][M]; // 第i列状态为j时方案的最大值
// 状态j 00101010 其中1表示这一列有横向的方块
bool st[M];

int main()
{
    while(cin >> n >> m, n || m)
    {
        // 排除每一列中不可能的状态
        for (int i = 0; i < 1 << n; i++)
        {
            st[i] = true;
            int cnt = 0; // 对0行计数，不应该存在奇数个零行
            for (int j = 0; j < n; j++)
            {
                if((i >> j & 1) == 1)
                {
                    // 存在奇数个零
                    if(cnt & 1)
                        st[i] = false;
                    cnt = 0;
                }
                else
                    cnt++;
            }
            // 到最后的0判断一下
            if(cnt & 1)
                st[i] = false;
        }

        memset(f, 0, sizeof f);
        f[0][0] = 1;
        // 列举每一列
        for (int i = 1; i <= m; i++)
        {
            // j 表示i列的状态， k表示i-1列的状态
            for (int j = 0; j < 1 << n; j++)
            {
                for (int k = 0; k < 1 << n; k++)
                {
                    // st[j|k] i-1列插过来的和第i列插出去的或，反映第i列的状态
                    // j k 不能同时有1
                    if((j & k) == 0 && st[j|k])
                    {
                        f[i][j] += f[i - 1][k];
                    }
                }
            }
        }

        cout << f[m][0] << endl;

    }
    return 0;
}
