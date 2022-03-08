#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ULL;
const int N = 100010;
int n, m;
char s[N];
// 0 : 48, A : 65, a : 97
int p = 131;
ULL h[N], q[N];
// h表示到i为止的字符串代表的数

ULL get_num(int l, int r)
{
    return h[r] - h[l - 1] * q[r - l + 1];
}

int main()
{
    // 把一段字母看成一个p进制的数， p=131 > ascii(z)
    cin >> n >> m;
    cin >> s + 1;
    q[0] = 1;

    // 直接求大小， 加ascii码
    // 求一下进位的和
    for (int i = 1; i <= n; i++)
    {
        h[i] = h[i - 1] * p + s[i];
        q[i] = q[i - 1] * p;
    }
    while (m--)
    {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        ULL n1 = get_num(l1, r1);
        ULL n2 = get_num(l2, r2);
        if(n1 == n2)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}