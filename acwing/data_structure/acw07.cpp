// 滑动窗口
#include <bits/stdc++.h>
using namespace std;
const int N = 1000010;
// 输入格式
// 输入包含两行。
// 第一行包含两个整数 n 和 k，分别代表数组长度和滑动窗口的长度。
// 第二行有 n 个整数，代表数组的具体数值。
// 同行数据之间用空格隔开。
// 输出格式
// 输出包含两个。
// 第一行输出，从左至右，每个位置滑动窗口中的最小值。
// 第二行输出，从左至右，每个位置滑动窗口中的最大值。

int n, k;
int a[N];
int q[N];

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int hh = 0, tt = -1;
    for (int i = 0; i < n; i++)
    {
        if(hh <= tt && q[hh] < i - k + 1)
            hh++;
        while(hh <= tt && a[q[tt]] >= a[i])
            tt--;
        q[++tt] = i;
        if (i > k - 2)
            printf("%d ", a[q[hh]]);
    }

    hh = 0, tt = -1;
    for (int i = 0; i < n; i++)
    {
        if(hh <= tt && q[hh] < i - k + 1)
            hh++;
        while(hh <= tt && a[q[tt]] <= a[i])
            tt--;
        q[++tt] = i;
        if (i > k - 2)
            printf("%d ", a[q[hh]]);
    }
    return 0;
}