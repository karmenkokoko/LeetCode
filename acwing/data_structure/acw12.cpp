#include <bits/stdc++.h>

using namespace std;
// 837. 连通块中点的数量
// 给定一个包含 n 个点（编号为 1∼n）的无向图，初始时图中没有边。

// 现在要进行 m 个操作，操作共有三种：

// C a b，在点 a 和点 b 之间连一条边，a 和 b 可能相等；
// Q1 a b，询问点 a 和点 b 是否在同一个连通块中，a 和 b 可能相等；
// Q2 a，询问点 a 所在连通块中点的数量
const int N = 100010;
int n, m;
int p[N];
int cnt[N];
// 维护count的一个数组
int find(int x)
{
    if(x != p[x])
        p[x] = find(p[x]);
    return p[x];
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        p[i] = i;
        cnt[i] = 1;
    }

    while(m--)
    {
        string op;
        cin >> op;
        if(op == "C")
        {
            int a, b;
            cin >> a >> b;
            a = find(a), b = find(b);
            if(a != b)
            {
                p[a] = b;
                cnt[b] += cnt[a];
            }
        }
        else if(op == "Q1")
        {
            int a, b;
            cin >> a >> b;
            if(find(a) == find(b))
                printf("Yes\n");
            else
                printf("No\n");
        }
        else{
            int a;
            cin >> a;
            printf("%d\n", cnt[a]);
        }
    }

    return 0;
}