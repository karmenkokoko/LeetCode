#include <bits/stdc++.h>

using namespace std;

// 数字的全排列

const int N = 10;

int n;
int path[N];
bool st[N];

void dfs(int x)
{
    if(x == n)
    {
        for (int i = 0; i < n; i++)
        {
            printf("%d ", path[i]);

        }
        cout << endl;
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if(!st[i])
        {
            st[i] = true;
            path[x] = i;
            dfs(x+1);
            path[x] = -1;
            st[i] = false;
        }
    }
}

int main()
{
    cin >> n;
    dfs(0);
    return 0;
}