#include <iostream>
// 多重背包
using namespace std;

const int N = 100010;

int vol[N], weight[N], S[N];
int V, W;
int f[N];


int main()
{
    cin >> W >> V;
    int cnt = 0;
    for(int i = 1; i <= W; i++)
    {
        // 二进制优化
        int a, b, s;
        cin >> a >> b >> s;
        int k = 1;

        while(k <= s)
        {
            cnt++;
            vol[cnt] = a * k;
            weight[cnt] = b * k;
            s -= k;
            k *= 2;
        }
        if(s > 0)
        {
            cnt++;
            vol[cnt] = a * s;
            weight[cnt] = b * s;
        }
    }
    W = cnt;

    for(int i = 1; i <= W; i++)
    {
        for(int j = V; j >= vol[i]; j--)
        {
            f[j] = max(f[j], f[j-vol[i]]+weight[i]);
        }
    }

    cout << f[V] << endl;
    return 0;
}
