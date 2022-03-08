#include <bits/stdc++.h>
// 动物王国中有三类动物 A,B,C，这三类动物的食物链构成了有趣的环形。

// A 吃 B，B 吃 C，C 吃 A。

// 现有 N 个动物，以 1∼N 编号。

// 每个动物都是 A,B,C 中的一种，但是我们并不知道它到底是哪一种。

// 有人用两种说法对这 N 个动物所构成的食物链关系进行描述：

// 第一种说法是 1 X Y，表示 X 和 Y 是同类。

// 第二种说法是 2 X Y，表示 X 吃 Y。

// 此人对 N 个动物，用上述两种说法，一句接一句地说出 K 句话，这 K 句话有的是真的，有的是假的。

// 当一句话满足下列三条之一时，这句话就是假话，否则就是真话。

// 当前的话与前面的某些真的话冲突，就是假话；
// 当前的话中 X 或 Y 比 N 大，就是假话；
// 当前的话表示 X 吃 X，就是假话。
// 你的任务是根据给定的 N 和 K 句话，输出假话的总数。


// 首先把所有的关系都放到并查集上去
// 通过模3 也就是一个环来判断这个点在这个集合上对于根节点的关系
// dist 维护了一个到父节点的距离 通过dist[p[x]]这样的递归，来表示到根节点的距离
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
                    // a的祖先的祖先 = b的祖先 保持这个吃的关系
                    // d[x] + d[px] = d[y] + 1        mod 3
                    dist[px] = dist[b] + 1 - dist[a];
                }
            }
        }
    }
    cout << res << endl;

    return 0;
}