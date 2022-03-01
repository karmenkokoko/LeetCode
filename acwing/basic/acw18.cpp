#include <bits/stdc++.h>

using namespace std;

// 二进制中1的个数
// 统计每个数中1的个数


int count(int x)
{
    int cnt = 0;
    while(x)
    {
        if(x&1)
            cnt++;
        x >>= 1;
    }
    return cnt;
}

int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        int x;
        cin >> x;
        cout << count(x) << " ";
    }
    cout << endl;

    return 0;
}