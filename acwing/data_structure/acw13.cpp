#include <bits/stdc++.h>

using namespace std;
const int N = 1000010;
int n, k;
int p[N], dist[N];

int find(int x)
{
    if(p[x] != x)
    {
        // 维护的是到父节点的距离, 多次递归以后就是到根节点距离
        int pa = find(p[x]);
        dist[x] += dist[p[x]];
        p[x] = pa;
    }
    return p[x];
}


int main()
{
    cin >> n >> k;

    int res = 0;
    for (int i = 0; i <= n; i++)
        p[i] = i;
    
    while(k--)
    {
        int a, b;
        int w;
        cin >> w >> a >> b;
        if(a > n || b > n)
            res += 1;
        else{
            int px = find(a), py = find(b);
            if(w == 1)
            {
                if(px == py && (dist[a] - dist[b]) % 3)
                    res++;
                else if(px != py)
                {
                    p[px] = py;
                    // a的祖先的祖先 = b的祖先
                    // d[x] + d[px] = d[y]        mod 3
                    dist[px] = dist[b] - dist[a];
                }
            }
            else{
                if(px == py && ((dist[a] - 1 - dist[b])%3))
                    res++;
                else if(px != py)
                {
                    p[px] = py;
                    dist[px] = dist[b] + 1 - dist[a];
                }
            }
        }
    }
    cout << res << endl;

    return 0;
}