#include <bits/stdc++.h>
// n皇后问题
// dfs每一行
using namespace std;
const int N = 20;
bool col[N], diag[2 * N], udiag[2 * N];
char g[N][N];
int n;

void dfs(int row)
{
    if(row >= n)
    {
        for (int i = 0; i < n; i++)
            puts(g[i]);
        cout << endl;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if(!col[i] && !diag[i+row] && !udiag[n - row + i])
        {
            col[i] = diag[i + row] = udiag[n - row + i] = true;
            g[row][i] = 'Q';
            dfs(row + 1);
            g[row][i] = '.';
            col[i] = diag[i + row] = udiag[n - row + i] = false;
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            g[i][j] = '.';
        }
    }

    dfs(0);

    return 0;
}