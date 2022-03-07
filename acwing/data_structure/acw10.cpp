#include <bits/stdc++.h>
// 143. 最大异或对

// 在给定的 N 个整数 A1，A2……AN 中选出两个进行 xor（异或）运算，得到的结果最大是多少？

// 输入格式
// 第一行输入一个整数 N。

// 第二行输入 N 个整数 A1～AN。

// 输出格式
// 输出一个整数表示答案。

using namespace std;
const int N = 1000010, M = 2 * N;
int son[M][2], idx, a[N];

void insert(int x)
{
    int p = 0;
    for (int i = 30; i >= 0; i--)
    {
        int u = x >> i & 1;
        if(!son[p][u])
            son[p][u] = ++idx;
        p = son[p][u];
    }

}

int eval(int x)
{
    int p = 0;
    int res = 0;
    for (int i = 30; i >= 0; i--)
    {
        int s = x >> i & 1;
        // 树有两个分叉
        if(son[p][!s])
        {
            res = res + (1 << i);
            p = son[p][!s];
        }
        else
            p = son[p][s];
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        insert(a[i]);
    }

    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res = max(res, eval(a[i]));
    }
    cout << res << endl;

    return 0;
}