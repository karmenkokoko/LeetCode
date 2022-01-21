#include <iostream>
// 01背包
using namespace std;
const int N = 100010;

int vol[N], W[N];
int f[N];
int V, M;

int main(){
    cin >> M >> V;
    for(int i = 1; i <= M; i++)
    {
        cin >> vol[i] >> W[i];
    }

    for(int i = 1; i <= M; i++)
    {
        for(int j = V; j >= vol[i]; j--)
        {
            f[j] = max(f[j], f[j-vol[i]]+W[i]);
        }
    }
    cout << f[V] << endl;
    return 0;

}