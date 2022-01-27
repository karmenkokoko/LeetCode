#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
// 代码有问题

// 严选的快递员每天需要送很多个包裹，在货物装车后，需要开着电动车先到0号用户家。
// 送完货后从0号出发，再送到1号用户。然后快递员可以从1号直接到2号用户家，完成送货。
// 但有时候由于路不通的原因，需要先折返回0号，再去2号，如此循环，完成送货。


// 由于路况复杂，每个用户家只有一条路通往附近的其他一户邻居家，假设每条通路都是1公里。
// 另外快递员的电动车的电是有限的，最多只能开有限的k公里。现在快递员已经在0号用户家送完快递，问快递员最多可以送多少个不重复的用户

// 输入描述:
// 输入包括两行,第一行包括两个正整数n(2 ≤ n ≤ 1000)和k(1 ≤ k ≤ 3000),表示用户家个数和快递员电动车剩余还能够行使的路程。
// 第二行包括n-1个整数，定义该数组为S，对于每个数组下标 i (0 ≤ i ≤ n - 2)，第i+1号用户跟S[i]号用户有一条道路连接。（参见下方样例和上图）

// 输出描述:
// 输出一个整数，表示快递员该次累计最多可以送几个用户

// 输入例子1:
// 6 3
// 0 0 2 3 3

// 输出例子1:
// 4


int n, k;
int g[N][N];
bool st[N];
 
int layer()
{
    int depth = 0;
    queue<int> q;
    q.push(0);
    st[0] = true;
    int layernodes = 1;
    int nextnodes = 0;
    while(q.size())
    {
        while(layernodes > 0)
        {
            layernodes--;
            int curnode = q.front();
            q.pop();
            for(int i = 1; i < n; i++)
            {
                if(g[curnode][i] == 1 && !st[i])
                {
                    nextnodes++;
                    st[i] = true;
                    q.push(i);
                }
            }
        }
        layernodes = nextnodes;
        nextnodes = 0;
        depth++;
    }
    return depth;
}
 
int main()
{
    cin >> n >> k;
    int idx = 0;
    memset(g, 0x3f, sizeof g);
    memset(st, false, sizeof st);
    while(1)
    {
        int v;
        cin >> v;
        g[v][idx+1] = 1;
        g[idx+1][v] = 1;
        if(cin.get() == '\n') break;
    }
    int depth = layer();
    // cout << "depth" << depth << endl;
    if(depth > k) cout << k+1 << endl;
    else
    {
        int res;
        res = min(n, depth + 1 + (k-depth)/2);
        cout << res << endl;
    }
    return 0;
}