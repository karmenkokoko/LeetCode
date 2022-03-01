#include <bits/stdc++.h>

using namespace std;
// 判断子序列
// 一个数组是否是另一个数组的子序列
const int N = 100010;
int n, m;
int a[N], b[N];

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];

    int ptra = 0, ptrb = 0;
    while(ptra < n && ptrb < m)
    {
        if(a[ptra] == b[ptrb])
        {
            ptra++;
            ptrb++;
        }
        else if(a[ptra] != b[ptrb]){
            ptrb++;
        }
        
        
    }

    if(ptra != n)
        cout << "No" << endl;
    else
        cout << "Yes" << endl;
    return 0;
}