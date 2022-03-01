#include <bits/stdc++.h>

using namespace std;
const int N = 1000010;

int a[N], S[N];
int n, m;
// 前缀和

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        S[i] = S[i - 1] + a[i];
    }

    while(m--)
    {
        int l, r;
        cin >> l >> r;
        cout << S[r] - S[l-1] << endl;
    }
    return 0;
}