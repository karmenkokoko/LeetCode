#include <bits/stdc++.h>

using namespace std;
const int N = 510;
// 给定一个二分图，其中左半部包含 n1 个点（编号 1∼n1），右半部包含 n2 个点（编号 1∼n2），二分图共包含 m 条边。

// 数据保证任意一条边的两个端点都不可能在同一部分中。

// 请你求出二分图的最大匹配数。
vector<int> g[N];
bool st[N]; // 已有匹配
int match[N]; // 

bool find(int x)
{
    for(auto j:g[x])
    {
        if(st[j])
            continue;
        st[j] = true;
        if(match[j] == 0 || find(match[j]))
        {
            match[j] = x;
            return true;
        }
    }
    return false;
}

int main()
{
    int n1, n2, m;
    cin >> n1 >> n2 >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    int res = 0;
    for (int i = 1; i <= n1; i++)
    {
        memset(st, false, sizeof st);
        if(find(i))
            res++;
    }

    cout << res << endl;
    return 0;
}