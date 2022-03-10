#include <bits/stdc++.h>
// 给定一个 n 个点 m 条边的无向图，图中可能存在重边和自环。

// 请你判断这个图是否是二分图。

// 输入格式
// 第一行包含两个整数 n 和 m。

// 接下来 m 行，每行包含两个整数 u 和 v，表示点 u 和点 v 之间存在一条边。

// 输出格式
// 如果给定图是二分图，则输出 Yes，否则输出 No。
using namespace std;
const int N = 100010;

int n, m;
int color[N];
int h[N], e[2*N], ne[2*N], idx;

void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

bool dfs(int u, int c)
{
    color[u] = c;
    for(int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if(!color[j])
        {
            if(!dfs(j, 3-c)) return false;
        }
        else if(color[j] == c) return false;
    }
    return true;
}


int main()
{
    memset(h, -1, sizeof h);
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        add(u, v), add(v, u);
    }
    
    bool flag = true;
    for(int i = 1; i <= n; i++)
    {
        if(!color[i])
        {
            if(!dfs(i, 1))
            {
                flag = false;
                break;
            }
        }
    }
    
    if(flag) printf("Yes");
    else printf("No");
    
    return 0;
}