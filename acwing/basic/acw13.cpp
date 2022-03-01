#include <bits/stdc++.h>

using namespace std;
// 一维差分
const int N = 1000010;
// b[i] = a[i] - a[i-1]
int a[N];
int b[N];

void insert(int l, int r, int c)
{
    b[l] += c;
    b[r + 1] -= c;
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i <= n; i++)
        insert(i, i, a[i]);

    while(m--)
    {
        int l, r, c;
        cin >> l >> r >> c;
        insert(l, r, c);
    }

    for (int i = 1; i <= n; i++)
    {
        // a[i] 是 b[i]的前缀和
        b[i] += b[i - 1];
        cout << b[i] << " ";
    }
    cout << endl;
    return 0;
}