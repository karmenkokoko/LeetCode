#include <iostream>
#include <cstring>

using namespace std;

// 可能有负值， 需要定义-INF
const int N = 510, INF = 0x3f3f3f3f;

int n;
int a[N][N];
int f[N][N];


int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            cin >> a[i][j];
        }
    }
    memset(f, -INF, sizeof(f));
    f[1][1] = a[1][1];

    for(int i = 2; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            f[i][j] = max(f[i-1][j-1]+a[i][j], f[i-1][j]+a[i][j]);
            // printf("f : %d, i: %d, j: %d \n", f[i][j], i, j);
        }
    }

    int res = -INF;
    for(int i = 1; i <= n; i++)
    {
        res = max(res, f[n][i]);
    }
    cout << res << endl;
    return 0;

}
