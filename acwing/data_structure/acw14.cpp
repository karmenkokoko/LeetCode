#include <bits/stdc++.h>

using namespace std;
const int N = 100010;
// 堆排序
// 去数组中前m小的数

int n, m;
int h[N], cnt;

void down(int x)
{
    int k = x;
    if(2 * x <= cnt && h[k] > h[2*x]) k = 2 * x;
    if(2 * x + 1 <= cnt && h[k] > h[2*x+1]) k = 2 * x + 1;
    if(k != x)
    {
        swap(h[k], h[x]);
        down(k);
    }
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> h[i];
    cnt = n;
    
    for(int i = cnt/2; i > 0; i--) down(i);
    
    while(m--)
    {
        int t = h[1];
        printf("%d ", t);
        h[1] = h[cnt--];
        down(1);
    }
    return 0;
}