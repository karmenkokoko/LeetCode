#include <bits/stdc++.h>
using namespace std;

// 数字的全排列

const int N = 10;

int n;
int path[N];
bool st[N];

void dfs(int x)
{
    if(x > n)
    {
        for (int i = 1; i <= n; i++)
        {
            cout << path[i] << endl;
        }
        cout << endl;
    }

    for (int i = 1; i <= n; i++)
    {
        if(!st[i])
        {
            path[x] = i;
            st[i] = true;
            dfs(x + 1);
            st[i] = false;
        }
    }
}

int main(){
    cin >> n;
    memset(st, false, sizeof st);
    dfs(1);
    return 0;
}
