#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n;
int a[N], st[N];
// 最长连续不重复子序列
// st可以当作一个set来存

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    memset(st, 0, sizeof st);
    int j = 0, maxlen = 0;
    for (int i = 0; i < n; i++)
    {
        st[a[i]]++;
        while (j < i && st[a[i]] > 1)
        {
            st[a[j]]--;
            j++;
        }
        
        maxlen = max(maxlen, i - j + 1);
    }
    cout << maxlen << endl;

    return 0;
}