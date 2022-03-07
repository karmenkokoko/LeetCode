#include <bits/stdc++.h>

using namespace std;
// 给定一个长度为 N 的整数数列，输出每个数左边第一个比它小的数，如果不存在则输出 −1。

const int N = 100010;
int top = 0;
int stk[N];
int a[N];

// 维护一个单调递增的栈
int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++)
    {
        // 保持单调递增的属性
        while(top && stk[top] >= a[i])
            top--;
        if(!top)
            printf("-1 ");
        else
            printf("%d ", stk[top]);
        stk[++top] = a[i];
    }
    return 0;
}