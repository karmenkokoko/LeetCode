#include <bits/stdc++.h>
using namespace std;
// 840. 模拟散列表
// 维护一个集合，支持如下几种操作：
// I x，插入一个数 x；
// Q x，询问数 x 是否在集合中出现过；
// 现在要进行 N 次操作，对于每个询问操作输出对应的结果。

const int N = 200010, null = 0x3f3f3f3f;
// memset只能赋值每8位都相同的int
int n;
int h[N];

int find(int x)
{
    // 找哈希索引值
    int t = (x % N + N) % N;
    while(h[t] != null && h[t] != x)
    {
        t++;
        if(t == N)
            t = 0;
    }
    return t;
}

int main()
{
    cin >> n;
    memset(h, 0x3f, sizeof h);
    while(n--)
    {
        string op;
        int x;
        cin >> op >> x;
        if(op == "I")
        {
            h[find(x)] = x;
        }
        else
        {
            if(h[find(x)] == null)
                printf("No\n");
            else
                printf("Yes\n");
        }
    }

    return 0;
}