#include <iostream>
// 完全背包
using namespace std;

const int N = 100010;

int vol[N], weight[N];
int V, M;
int f[N];

int main()
{
    cin >> M >> V;
    for(int i = 1; i <= M; i++)
    {
        cin >> vol[i] >> weight[i];
    }

    for(int i = 1; i <= M; i++)
    {
        for(int j = vol[i]; j <= V; j++)
        {
            f[j] = max(f[j], f[j-vol[i]]+weight[i]);
        }
    }

    cout << f[V] << endl;

    return 0;
}