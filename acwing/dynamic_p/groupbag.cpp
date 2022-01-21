#include <iostream>
// 分组背包
using namespace std;

const int N = 1010;

int vol[N][N], weight[N][N], s[N]; 
int V, M;
int f[N];

int main()
{
    cin >> M >> V;
    for(int i = 1; i <= M; i++)
    {
        cin >> s[i];
        for(int j = 1; j <= s[i]; j++)
        {
            cin >> vol[i][j] >> weight[i][j];
        }
    }

    for(int i = 1; i <= M; i++)
    {
        for(int j = V; j >= 0; j--)
        {
            for(int k = 1; k <= s[i]; k++)
            {
                if(vol[i][k] <= j)
                {
                    f[j] = max(f[j], f[j-vol[i][k]]+weight[i][k]);
                }
            }
        }
    }

    cout << f[V] << endl;
    return 0;
}