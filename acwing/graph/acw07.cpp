// 有向图的拓扑序列

#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
int n, m;
// idx 表示第几个插入的数的index， 它的element value存在e[N]里面，ne[N]表示这个element value的下一个节点的值. 
// h[a]存idx的原因是idx的e已经有了, 到时候取就Ok
// 这样我们把第几个数index也存下来了
int h[N], e[N], ne[N], idx;
// 队列用数组模拟可以真正的存储遍历过程
int q[N], d[N]; // 队列和入度

// 这里传入的其实是点的序号,
void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool topsort()
{
    // 维护队列
    int hh = 0, tt = -1;
    // 找开头
    for (int i = 1; i <= n; i++)
    {
        if(!d[i])
            q[++tt] = i;
    }

    while(hh <= tt)
    {
        int t = q[hh++];
        // 遍历head为t的邻接表, 链表
        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            // 这个点入度 -1
            d[j]--;
            if(!d[j])
                q[++tt] = j;
        }
    }
    // 最后判断tt是否遍历了n个数
    return tt == n - 1;
}

int main()
{
    cin >> n >> m;
    memset(h, -1, sizeof h);
    while (m--)
    {
        // 指示点的序号
        int a, b;

        cin >> a >> b;
        add(a, b);
        d[b]++;
    }

    if(topsort())
    {
        for (int i = 0; i < n; i++)
        {
            printf("%d ", q[i]);
        }
        cout << endl;
    }
    else
        puts("-1");
    return 0;
}