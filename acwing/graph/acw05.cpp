#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;

int h[N], e[N], ne[N], idx;
int n;
bool st[N];
int ans = N;

void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

// 以这个点为分割点的子树 数量
int dfs(int u)
{
    st[u] = true; // 访问过了就不需要再访问
    int sum = 1, res = 0;
    for (int i = h[u]; i != -1; i = ne[i])
    {
        auto j = e[i];
        if(st[j])
            continue;
        int s = dfs(j);
        // 求其中最大的一个子树
        res = max(res, s);
        sum += s;
    }
    // 最大子树和父节点以上节点数量的比较
    res = max(res, n - sum);
    ans = min(ans, res);

    return sum;
}

int main()
{
    memset(h, -1, sizeof h);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }

    dfs(1);

    cout << ans << endl;
    return 0;
}