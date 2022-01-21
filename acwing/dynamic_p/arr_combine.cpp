#include <iostream>
#include <cstring>
// 合并石子
// 区间问题还是得循环区间长度len
using namespace std;

const int N = 310, INF = 0x3f3f3f3f;
int n;
int a[N];
int S[N];
int f[N][N];

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        S[i] += S[i-1] + a[i];
    }
    
    for(int len = 2; len <= n; len++)
    {
        for(int i = 1; i+len-1 <=n; i++)
        {
            int l = i, r = i+len-1;
            f[l][r] = INF;
            for(int k = l; k < r; k++)
            {
                f[l][r] = min(f[l][r], f[l][k]+f[k+1][r] +S[r] - S[l-1]);
                // printf("f : %d, l: %d, r:%d \n", f[l][r], l, r);
            }
        }
    }
    
    cout << f[1][n] << endl;
    return 0;
}