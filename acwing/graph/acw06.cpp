#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
// 给定一个 n 个点 m 条边的有向图，图中可能存在重边和自环。

// 所有边的长度都是 1，点的编号为 1∼n。

// 请你求出 1 号点到 n 号点的最短距离，如果从 1 号点无法走到 n 号点，输出 −1。

// 输入格式
// 第一行包含两个整数 n 和 m。

// 接下来 m 行，每行包含两个整数 a 和 b，表示存在一条从 a 走到 b 的长度为 1 的边。

// 输出格式
// 输出一个整数，表示 1 号点到 n 号点的最短距离。


int h[N], e[2*N], ne[2*N], idx;
int d[N];
int n, m;

void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

int bfs()
{
    // 广搜d表示了是否访问过了， 已访问就更新d， 以后不再更新
    memset(d, -1, sizeof d);
    queue<int> q;
    d[1] = 0;
    q.push(1);

    while(q.size())
    {
        auto t = q.front();
        q.pop();
        for (int j = h[t]; j != -1; j = ne[j])
        {
            if(d[j] == -1)
            {
                d[j] = d[t] + 1;
                q.push(j);
            }
        }
    }
    return d[n];
}

int main()
{
    cin >> n >> m;
    memset(h, -1, sizeof h);
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        add(a, b);
    }
    cout << bfs() << endl;
    return 0;
}