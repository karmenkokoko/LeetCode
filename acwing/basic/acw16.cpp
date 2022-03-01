#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
// 数组元素的目标和
// 经典双指针
int a[N], b[N];

int n, m, x;

int main()
{
    cin >> n >> m >> x;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];

    int l = 0, r = m - 1;
    while(l < n && r >= 0)
    {
        if(a[l] + b[r] > x)
        {
            r--;
        }
        else if(a[l] + b[r] < x)
        {
            l++;
        }
        else
        {
            cout << l << " " << r << endl;
            break;
        }
    }

    return 0;
}